#include <iostream>
using namespace std;

// YOU WILL NEED TO CALL THIS FUNCTION
// Function for taking a string and creating a "checksum" in ASCII
// Reminder: The input string should be more than just the "command"
//           Review problem description for more info
unsigned char checksum(string input) {
  unsigned char accumulated = 0;
  for(char& c : input) {
    accumulated += c;
  }
  return (accumulated % 26) + 'A';
}

// Required output format
const string MSG_HEADER = "ZOOX";

const string MSG_LEFT = "LEFT";
const string MSG_RIGHT = "RIGHT";
const string MSG_FORWARD = "FORWARD";
const string MSG_BEEP = "BEEP";

const string OUTPUT_LEFT = "L";
const string OUTPUT_RIGHT = "R";
const string OUTPUT_FORWARD = "F";
const string OUTPUT_BEEP = "!";

// You should not need to call this function
// Util used by execute_packet_command(...)
void execute_command(string cmd, int repeat) {
  for (int i = 0; i < repeat; i++) {
    cout << cmd;
  }
}

// YOU WILL NEED TO CALL THIS FUNCTION
// Provide the content of the command packet as inputs.
// cmd should be the command string from the packet
// repeat should be the repeat byte from the packet
void execute_packet_command(string cmd, int repeat) {
  if (cmd.compare(MSG_LEFT) == 0) {
    execute_command(OUTPUT_LEFT, repeat);
  }
  if (cmd.compare(MSG_RIGHT) == 0) {
    execute_command(OUTPUT_RIGHT, repeat);
  }
  if (cmd.compare(MSG_FORWARD) == 0) {
    execute_command(OUTPUT_FORWARD, repeat);
  }
  if (cmd.compare(MSG_BEEP) == 0) {
    execute_command(OUTPUT_BEEP, repeat);
  }
}

// Required prototype and main
void parse(char c);
int main() {
  string input;
  cin >> input;
  cout << "Cmd: ";
  for(char& c : input) {
    parse(c);
  }
  return 0;
}

// ------ Do not modify above this line ----------
// ----------- Add your code below ---------------

/// ---- Trie ------------------------------------

#define LETTERS_IN_ALPHABET 26

typedef struct trie_t trie_t;
struct trie_t
{
  bool end_of_word = false;
  trie_t * character[LETTERS_IN_ALPHABET];
};

trie_t * trie_get_node()
{
  trie_t * node = (trie_t *)malloc(sizeof(trie_t));
  node->end_of_word = false;

  for (int i = 0; i < LETTERS_IN_ALPHABET; i++)
    node->character[i] = NULL;
  return node;
}

void trie_insert(trie_t * head, const char * str)
{
  if (!head || !str)
    return;

  trie_t * node = head;
  while (*str)
  {
    int c = *str - 'A';
    if (node->character[c] == NULL)
      node->character[c] = trie_get_node();

    node = node->character[c];
    str++;
  }
  node->end_of_word = true;
}

/// ---- Ends Trie -------------------------------

enum
{
  STATE_INIT = 0,
  STATE_IDLE,
  STATE_HEADER,
  STATE_LENGTH,
  STATE_COMMAND,
  STATE_REPEAT,
  STATE_CHECKSUM,
}states_e;

const char * COMMANDS[] = {MSG_LEFT.c_str(), MSG_RIGHT.c_str(), MSG_FORWARD.c_str(), MSG_BEEP.c_str()};

struct parser_impl_t
{
  trie_t * trie_head; ///< Head of commands trie
  trie_t * trie_ptr; ///< Pointer to last read letter in the trie
  
  int state = STATE_INIT; ///< FSM state  
  const char * header_ptr; ///< Pointer to next letter to read of header  
  int length; ///< Length of command to read  
  int repeat; ///< Times to repeat command  
  string buffer; ///< Packet buffer  
  string cmd; ///< Command  
};
typedef struct parser_impl_t parser_impl_t;

// Global object of parser implementation
parser_impl_t parser_impl;

void init_parser_impl(parser_impl_t * p)
{
  p->trie_head = trie_get_node();
  for (int i = 0; i < sizeof(COMMANDS) / sizeof(COMMANDS[0]); i++)
    trie_insert(p->trie_head, COMMANDS[i]);
}

void parse(char c)
{
  parser_impl_t * p = &parser_impl;
  
  p->buffer += c;
  switch(p->state)
  {
    // Initialize variables
    case STATE_INIT:
      init_parser_impl(p);
      p->state = STATE_IDLE;
      // Don't break. Continue to idle. 
    
    // New packet
    case STATE_IDLE:
      p->buffer = "";
      p->buffer += c;
      if (c == MSG_HEADER.c_str()[0])
      {
        p->state = STATE_HEADER;
        p->header_ptr = MSG_HEADER.c_str() + 1;        
        p->trie_ptr = p->trie_head;
        p->repeat = 0;
        p->cmd = "";
      }     
      else
        p->state = STATE_IDLE;      
      break;
      
    // Reading header
    case STATE_HEADER:
      if (c == *p->header_ptr)
      {
        p->header_ptr++;
        if (*p->header_ptr == '\0')
          p->state = STATE_LENGTH;
      }
      else
      {
        p->state = STATE_IDLE;
        parse(c);
      }
      break;
      
    // Read length
    case STATE_LENGTH:
      if (c >= '1' && c <= '9')
      {
        p->length = c - '0' - 1;   
        p->state = STATE_COMMAND;        
      }
      else
      {
        p->state = STATE_IDLE;
        parse(c);
      }
      break;
      
    // Reading command
    case STATE_COMMAND:
      if (c >= 'A' && c <= 'Z' && p->trie_ptr->character[c - 'A'])
      {
        p->cmd += c;
        p->trie_ptr = p->trie_ptr->character[c - 'A'];
        if (--p->length <= 0)
        {
          if (p->trie_ptr->end_of_word)
          {            
            p->state = STATE_REPEAT;
          }            
          else
          {
            p->state = STATE_IDLE;
            parse(c);
          }            
        }
      }
      else
      {
        p->state = STATE_IDLE;
        parse(c);
      }        
      break;
      
    // Read repeat
    case STATE_REPEAT:
      if (c >= '0' && c <= '9')
      {
        p->repeat = c - '0';
        p->state = STATE_CHECKSUM;
      }
      else
      {
        p->state = STATE_IDLE;
        parse(c);
      }
      break;
      
    // Read checksum
    case STATE_CHECKSUM:
      string s = p->buffer.substr(0,p->buffer.size()-1);
      if (c >= 'A' && c <= 'Z' && checksum(s) == c)
      {
        execute_packet_command(p->cmd, p->repeat);
        p->state = STATE_IDLE;
      }
      else
      {
        p->state = STATE_IDLE;
        parse(c);
      }
      break;      
  }
}

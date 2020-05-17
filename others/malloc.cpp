#include <iostream>

using namespace std;

typedef struct free_block free_block;
struct free_block
{
	size_t size;
	free_block * next;
};

static free_block free_block_list_head = {0,nullptr};

void malloc(size_t size)
{
	size = (size + sizeof(size) + alignment - 1) & ~(alignment - 1);
	free_block *block = free_block_list_head.next;
	free_block ** head = &(free_block_list_head.next);
	while (block != nullptr)
	{
		if (block->size >= size)
		{
			*head = block->next;
			return ((char*)block) + sizeof(size_t);
		}
		head = &(block->next);
		block = block->next;
	}
	block = (free_block *)sbrk(size);
	block->size = size;

	return ((char*)block) + sizeof(size_t);
}

int main()
{




	return 0;
}
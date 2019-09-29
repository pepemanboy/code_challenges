# Rectangle Mania

## Problem

I started following [Clément Mihailescu](https://www.youtube.com/channel/UCaO6VoaYJv4kS-TQO_M-N_g) a while ago in YouTube, and yesterday he uploaded a [video](https://www.youtube.com/watch?v=EuPSibuIKIg) about a code interview to [Errichto](https://www.youtube.com/channel/UCBr_Fu6q9iHYQCh13jmpbrg).

I really liked the video and recommend it a lot. It talks about a sample google interview, and how it's answered by a competitive programmer.

The problem was very interesting, along the lines of:

"Given a list of n points in 2D, determine how many unique rectangles can be formed"

At the end, they explore the case of tilted rectangles, and hint about a O(n^2) time solution. 

Here I propose a simpler solution for O(n^2) time. (Actually O(n^2 log(n)) for map in C++, but changing to unordered_map can make it O(n^2)).

## Solution

We define an Edge data structure of the form Edge{vector v, double orthogonal_y_intercept}. This image describes how to calculate the vector and the orthogonal_y_intercept values.

![Algorithm for rectangle mania](https://github.com/pepemanboy/code_challenges/blob/master/rectangle_mania/img/algorithm.PNG)

Every pair of points whose vector and orthogonal_y_intercept is equal to an existing one, will form a new rectangle...

So... 

We have a map m with Edge keys, and int values.

We initialize answer to 0.

For every pair of points (p1,p2) that satisfy  (p2.x >= p1.x && p2.y > p1.y):
- calculate their Edge e.
- answer += m[e]
- m[e]++

See implementation in [rectangle_mania.cpp](https://github.com/pepemanboy/code_challenges/blob/master/rectangle_mania/rectangle_mania.cpp)


# Rectangle Mania

## Problem

I started following [Clément Mihailescu](https://www.youtube.com/channel/UCaO6VoaYJv4kS-TQO_M-N_g) a while ago in YouTube, and yesterday he uploaded a [video](https://www.youtube.com/watch?v=EuPSibuIKIg) about a code interview to [Errichto](https://www.youtube.com/channel/UCBr_Fu6q9iHYQCh13jmpbrg).

I really liked the video and recommend it a lot. It talks about a sample google interview, and how it's answered by a competitive programmer.

The problem was very interesting, along the lines of:

"Given a list of n points in 2D, determine how many unique rectangles can be formed"

At the end, they explore the case of tilted rectangles, and hint about a O(n^2) time solution. 

Here I propose a simpler solution for O(n^2) time. (Actually O(n^2 log(n)) for map in C++, but changing to unordered_map can make it O(n^2)).

## Solution

For every pair of points (p1,p2) that satisfies that (p2.x >= p1.x && p2.y > p1.y), calculate the following:

![Algorithm for rectangle mania](https://github.com/pepemanboy/code_challenges/rectangle_mania/img/algorithm.png)

Every pair of points whose vector and orthogonal_y_intercept is equal to an existing one, will form a new rectangle...

See implementation in [rectangle_mania.cpp](https://github.com/pepemanboy/code_challenges/rectangle_mania/rectangle_mania.cpp)


#include <iostream>
#include<cmath>
#include <stdbool.h>
#include<cstdio>
#include<fstream>
using namespace std;
struct point3D{
 bool allume;
} ;

//int lookUpTable[256][13] = {
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 8, 3, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 1, 0, 9, 6, 7, 11, -1, -1, -1, -1, -1, -1, -1 },
//    { 3, 1, 8, 1, 8, 9, 11, 6, 7, -1, -1, -1, -1 },
//    { 2, 10, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 10, 2, 1, 3, 8, 0, -1, -1, -1, -1, -1, -1, -1 },
//    { 9, 5, 0, 5, 0, 6, 6, 0, 2, -1, -1, -1, -1 },
//    { 7, 6, 8, 6, 8, 10, 10, 8, 9, 2, 1, 10, -1 },
//    { 11, 2, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 11, 7, 2, 7, 2, 4, 4, 2, 0, -1, -1, -1, -1 },
//    { 11, 3, 2, 0, 9, 1, -1, -1, -1, -1, -1, -1, -1 },
//    { 6, 5, 11, 5, 11, 9, 9, 11, 8, 1, 0, 9, -1 },
//    { 10, 6, 1, 6, 1, 7, 7, 1, 3, -1, -1, -1, -1 },
//    { 5, 4, 10, 4, 10, 8, 8, 10, 11, 0, 3, 8, -1 },
//    { 0, 9, 10, 0, 10, 7, 7, 6, 10, 3, 0, 7, -1 },
//    { 10, 9, 11, 9, 8, 11, -1, -1, -1, -1, -1, -1, -1 },
//    { 8, 4, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 4, 9, 7, 9, 7, 1, 1, 7, 3, -1, -1, -1, -1 },
//    { 7, 4, 8, 9, 1, 0, -1, -1, -1, -1, -1, -1, -1 },
//    { 10, 6, 1, 6, 1, 7, 7, 1, 3, 4, 8, 7, -1 },
//    { 10, 2, 1, 4, 8, 7, -1, -1, -1, -1, -1, -1, -1 },
//    { 0, 4, 3, 4, 3, 7, 1, 10, 2, -1, -1, -1, -1 },
//    { 0, 2, 9, 2, 9, 10, 8, 7, 4, -1, -1, -1, -1 },
//    { 7, 9, 2, 10, 2, 9, 4, 9, 7, 7, 2, 6, -1 },
//    { 4, 8, 7, 3, 2, 11, -1, -1, -1, -1, -1, -1, -1 },
//    { 5, 10, 4, 10, 4, 2, 2, 4, 0, 11, 3, 2, -1 },
//    { 4, 7, 8, 11, 3, 2, 1, 0, 9, -1, -1, -1, -1 },
//    { 1, 2, 11, 1, 11, 7, 1, 7, 9, 9, 4, 7, -1 },
//    { 11, 10, 3, 10, 3, 1, 7, 4, 8, -1, -1, -1, -1 },
//    { 7, 11, 10, 7, 10, 0, 0, 1, 10, 4, 7, 0, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 3, 0, 11, 0, 11, 9, 9, 11, 10, 4, 5, 9, -1 },
//    { 5, 4, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 3, 8, 0, 4, 5, 9, -1, -1, -1, -1, -1, -1, -1 },
//    { 5, 10, 4, 10, 4, 2, 2, 4, 0, -1, -1, -1, -1 },
//    { 6, 11, 5, 11, 5, 3, 3, 5, 1, 8, 0, 3, -1 },
//    { 4, 5, 9, 10, 2, 1, -1, -1, -1, -1, -1, -1, -1 },
//    { 8, 3, 0, 2, 1, 10, 5, 9, 4, -1, -1, -1, -1 },
//    { 11, 7, 2, 7, 2, 4, 4, 2, 0, 5, 9, 4, -1 },
//    { 2, 10, 5, 2, 5, 4, 2, 4, 3, 3, 8, 4, -1 },
//    { 4, 5, 9, 3, 2, 11, -1, -1, -1, -1, -1, -1, -1 },
//    { 8, 11, 0, 11, 0, 2, 4, 5, 9, -1, -1, -1, -1 },
//    { 1, 5, 0, 5, 0, 4, 2, 11, 3, -1, -1, -1, -1 },
//    { 2, 1, 5, 2, 5, 8, 8, 4, 5, 11, 2, 8, -1 },
//    { 1, 3, 10, 3, 10, 11, 9, 4, 5, -1, -1, -1, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 11, 0, 5, 4, 5, 0, 3, 0, 11, 11, 5, 7, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 7, 6, 8, 6, 8, 10, 10, 8, 9, -1, -1, -1, -1 },
//    { 2, 10, 3, 10, 3, 5, 5, 3, 7, 9, 4, 5, -1 },
//    { 11, 2, 7, 2, 7, 1, 1, 7, 5, 0, 9, 1, -1 },
//    { 5, 7, 1, 7, 3, 1, -1, -1, -1, -1, -1, -1, -1 },
//    { 5, 7, 9, 7, 9, 8, 10, 2, 1, -1, -1, -1, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 8, 0, 2, 8, 2, 5, 5, 10, 2, 7, 8, 5, -1 },
//    { 9, 0, 5, 0, 5, 3, 3, 5, 7, 2, 11, 3, -1 },
//    { 8, 9, 7, 9, 7, 5, 3, 2, 11, -1, -1, -1, -1 },
//    { 2, 7, 9, 5, 9, 7, 11, 7, 2, 2, 9, 10, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 0, 8, 1, 8, 1, 7, 7, 1, 5, 11, 6, 7, -1 },
//    { 8, 3, 9, 3, 1, 9, 7, 11, 5, 11, 10, 5, -1 },
//    { 10, 11, 5, 11, 5, 7, 1, 0, 9, -1, -1, -1, -1 },
//    { 7, 5, 11, 5, 11, 10, 8, 0, 3, -1, -1, -1, -1 },
//    { 5, 4, 10, 4, 10, 8, 8, 10, 11, -1, -1, -1, -1 },
//    { 5, 10, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 3, 8, 0, 10, 5, 6, -1, -1, -1, -1, -1, -1, -1 },
//    { 0, 9, 1, 5, 6, 10, -1, -1, -1, -1, -1, -1, -1 },
//    { 9, 8, 1, 8, 1, 3, 5, 6, 10, -1, -1, -1, -1 },
//    { 1, 9, 2, 9, 2, 4, 4, 2, 6, -1, -1, -1, -1 },
//    { 2, 6, 1, 6, 1, 5, 3, 8, 0, -1, -1, -1, -1 },
//    { 7, 8, 6, 8, 6, 0, 0, 6, 2, 9, 1, 0, -1 },
//    { 5, 9, 8, 5, 8, 2, 2, 3, 8, 6, 5, 2, -1 },
//    { 5, 6, 10, 11, 3, 2, -1, -1, -1, -1, -1, -1, -1 },
//    { 2, 0, 11, 0, 11, 8, 10, 5, 6, -1, -1, -1, -1 },
//    { 6, 5, 10, 9, 1, 0, 3, 2, 11, -1, -1, -1, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 8, 4, 3, 4, 3, 5, 5, 3, 1, 6, 10, 5, -1 },
//    { 8, 1, 6, 5, 6, 1, 0, 1, 8, 8, 6, 4, -1 },
//    { 3, 0, 9, 3, 9, 5, 3, 5, 11, 11, 6, 5, -1 },
//    { 1, 2, 9, 2, 9, 11, 11, 9, 8, 6, 7, 11, -1 },
//    { 0, 1, 8, 1, 8, 10, 10, 8, 11, 5, 6, 10, -1 },
//    { 7, 3, 4, 3, 4, 0, 6, 10, 5, -1, -1, -1, -1 },
//    { 7, 8, 4, 0, 9, 1, 10, 5, 6, -1, -1, -1, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 5, 1, 6, 1, 6, 2, 4, 8, 7, -1, -1, -1, -1 },
//    { 7, 6, 3, 6, 2, 3, 4, 5, 0, 5, 1, 0, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 6, 2, 7, 2, 7, 3, 5, 9, 4, -1, -1, -1, -1 },
//    { 8, 4, 7, 5, 6, 10, 2, 11, 3, -1, -1, -1, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 7, 6, 11, 2, 1, 10, 0, 3, 8, 4, 5, 9, -1 },
//    { 11, 7, 6, 4, 5, 9, 1, 10, 2, -1, -1, -1, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 4, 0, 5, 0, 5, 1, 7, 11, 6, -1, -1, -1, -1 },
//    { 9, 5, 4, 6, 7, 11, 3, 8, 0, -1, -1, -1, -1 },
//    { 9, 4, 5, 7, 11, 6, -1, -1, -1, -1, -1, -1, -1 },
//    { 10, 1, 6, 1, 6, 0, 0, 6, 4, -1, -1, -1, -1 },
//    { 9, 10, 4, 10, 4, 6, 0, 3, 8, -1, -1, -1, -1 },
//    { 3, 11, 0, 11, 0, 6, 6, 0, 4, 10, 5, 6, -1 },
//    { 6, 1, 8, 3, 8, 1, 10, 1, 6, 6, 8, 11, -1 },
//    { 8, 3, 4, 3, 4, 2, 2, 4, 6, 1, 10, 2, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 2, 6, 0, 6, 4, 0, -1, -1, -1, -1, -1, -1, -1 },
//    { 1, 9, 2, 9, 2, 4, 4, 2, 6, 8, 7, 4, -1 },
//    { 6, 4, 10, 4, 10, 9, 11, 3, 2, -1, -1, -1, -1 },
//    { 2, 10, 0, 10, 9, 0, 11, 6, 8, 6, 4, 8, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 11, 8, 6, 8, 6, 4, 2, 1, 10, -1, -1, -1, -1 },
//    { 9, 4, 6, 9, 6, 3, 3, 11, 6, 1, 9, 3, -1 },
//    { 4, 6, 8, 6, 8, 11, 9, 1, 0, -1, -1, -1, -1 },
//    { 10, 1, 6, 1, 6, 0, 0, 6, 4, 3, 8, 0, -1 },
//    { 8, 3, 4, 3, 4, 2, 2, 4, 6, -1, -1, -1, -1 },
//    { 2, 3, 10, 3, 10, 8, 8, 10, 9, 7, 4, 8, -1 },
//    { 6, 10, 9, 6, 9, 3, 3, 0, 9, 7, 6, 3, -1 },
//    { 10, 1, 0, 10, 0, 8, 10, 8, 6, 6, 7, 8, -1 },
//    { 4, 9, 7, 9, 7, 1, 1, 7, 3, 10, 2, 1, -1 },
//    { 9, 2, 7, 6, 7, 2, 1, 2, 9, 9, 7, 5, -1 },
//    { 3, 7, 2, 7, 2, 6, 0, 9, 1, -1, -1, -1, -1 },
//    { 9, 5, 0, 5, 0, 6, 6, 0, 2, 7, 11, 6, -1 },
//    { 2, 10, 3, 10, 3, 5, 5, 3, 7, -1, -1, -1, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 10, 9, 2, 9, 2, 0, 6, 7, 11, -1, -1, -1, -1 },
//    { 0, 8, 3, 7, 11, 6, 10, 2, 1, -1, -1, -1, -1 },
//    { 1, 10, 2, 6, 7, 11, -1, -1, -1, -1, -1, -1, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 6, 7, 11, 1, 0, 9, -1, -1, -1, -1, -1, -1, -1 },
//    { 6, 7, 11, 8, 0, 3, -1, -1, -1, -1, -1, -1, -1 },
//    { 7, 6, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 7, 6, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 6, 7, 11, 8, 0, 3, -1, -1, -1, -1, -1, -1, -1 },
//    { 6, 7, 11, 1, 0, 9, -1, -1, -1, -1, -1, -1, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 1, 10, 2, 6, 7, 11, -1, -1, -1, -1, -1, -1, -1 },
//    { 0, 8, 3, 7, 11, 6, 10, 2, 1, -1, -1, -1, -1 },
//    { 10, 9, 2, 9, 2, 0, 6, 7, 11, -1, -1, -1, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 2, 10, 3, 10, 3, 5, 5, 3, 7, -1, -1, -1, -1 },
//    { 9, 5, 0, 5, 0, 6, 6, 0, 2, 7, 11, 6, -1 },
//    { 3, 7, 2, 7, 2, 6, 0, 9, 1, -1, -1, -1, -1 },
//    { 9, 2, 7, 6, 7, 2, 1, 2, 9, 9, 7, 5, -1 },
//    { 4, 9, 7, 9, 7, 1, 1, 7, 3, 10, 2, 1, -1 },
//    { 10, 1, 0, 10, 0, 8, 10, 8, 6, 6, 7, 8, -1 },
//    { 6, 10, 9, 6, 9, 3, 3, 0, 9, 7, 6, 3, -1 },
//    { 2, 3, 10, 3, 10, 8, 8, 10, 9, 7, 4, 8, -1 },
//    { 8, 3, 4, 3, 4, 2, 2, 4, 6, -1, -1, -1, -1 },
//    { 10, 1, 6, 1, 6, 0, 0, 6, 4, 3, 8, 0, -1 },
//    { 4, 6, 8, 6, 8, 11, 9, 1, 0, -1, -1, -1, -1 },
//    { 9, 4, 6, 9, 6, 3, 3, 11, 6, 1, 9, 3, -1 },
//    { 11, 8, 6, 8, 6, 4, 2, 1, 10, -1, -1, -1, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 2, 10, 0, 10, 9, 0, 11, 6, 8, 6, 4, 8, -1 },
//    { 6, 4, 10, 4, 10, 9, 11, 3, 2, -1, -1, -1, -1 },
//    { 1, 9, 2, 9, 2, 4, 4, 2, 6, 8, 7, 4, -1 },
//    { 2, 6, 0, 6, 4, 0, -1, -1, -1, -1, -1, -1, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 8, 3, 4, 3, 4, 2, 2, 4, 6, 1, 10, 2, -1 },
//    { 6, 1, 8, 3, 8, 1, 10, 1, 6, 6, 8, 11, -1 },
//    { 3, 11, 0, 11, 0, 6, 6, 0, 4, 10, 5, 6, -1 },
//    { 9, 10, 4, 10, 4, 6, 0, 3, 8, -1, -1, -1, -1 },
//    { 10, 1, 6, 1, 6, 0, 0, 6, 4, -1, -1, -1, -1 },
//    { 9, 4, 5, 7, 11, 6, -1, -1, -1, -1, -1, -1, -1 },
//    { 9, 5, 4, 6, 7, 11, 3, 8, 0, -1, -1, -1, -1 },
//    { 4, 0, 5, 0, 5, 1, 7, 11, 6, -1, -1, -1, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 11, 7, 6, 4, 5, 9, 1, 10, 2, -1, -1, -1, -1 },
//    { 7, 6, 11, 2, 1, 10, 0, 3, 8, 4, 5, 9, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 8, 4, 7, 5, 6, 10, 2, 11, 3, -1, -1, -1, -1 },
//    { 6, 2, 7, 2, 7, 3, 5, 9, 4, -1, -1, -1, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 7, 6, 3, 6, 2, 3, 4, 5, 0, 5, 1, 0, -1 },
//    { 5, 1, 6, 1, 6, 2, 4, 8, 7, -1, -1, -1, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 7, 8, 4, 0, 9, 1, 10, 5, 6, -1, -1, -1, -1 },
//    { 7, 3, 4, 3, 4, 0, 6, 10, 5, -1, -1, -1, -1 },
//    { 0, 1, 8, 1, 8, 10, 10, 8, 11, 5, 6, 10, -1 },
//    { 1, 2, 9, 2, 9, 11, 11, 9, 8, 6, 7, 11, -1 },
//    { 3, 0, 9, 3, 9, 5, 3, 5, 11, 11, 6, 5, -1 },
//    { 8, 1, 6, 5, 6, 1, 0, 1, 8, 8, 6, 4, -1 },
//    { 8, 4, 3, 4, 3, 5, 5, 3, 1, 6, 10, 5, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 6, 5, 10, 9, 1, 0, 3, 2, 11, -1, -1, -1, -1 },
//    { 2, 0, 11, 0, 11, 8, 10, 5, 6, -1, -1, -1, -1 },
//    { 5, 6, 10, 11, 3, 2, -1, -1, -1, -1, -1, -1, -1 },
//    { 5, 9, 8, 5, 8, 2, 2, 3, 8, 6, 5, 2, -1 },
//    { 7, 8, 6, 8, 6, 0, 0, 6, 2, 9, 1, 0, -1 },
//    { 2, 6, 1, 6, 1, 5, 3, 8, 0, -1, -1, -1, -1 },
//    { 1, 9, 2, 9, 2, 4, 4, 2, 6, -1, -1, -1, -1 },
//    { 9, 8, 1, 8, 1, 3, 5, 6, 10, -1, -1, -1, -1 },
//    { 0, 9, 1, 5, 6, 10, -1, -1, -1, -1, -1, -1, -1 },
//    { 3, 8, 0, 10, 5, 6, -1, -1, -1, -1, -1, -1, -1 },
//    { 5, 10, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 5, 4, 10, 4, 10, 8, 8, 10, 11, -1, -1, -1, -1 },
//    { 7, 5, 11, 5, 11, 10, 8, 0, 3, -1, -1, -1, -1 },
//    { 10, 11, 5, 11, 5, 7, 1, 0, 9, -1, -1, -1, -1 },
//    { 8, 3, 9, 3, 1, 9, 7, 11, 5, 11, 10, 5, -1 },
//    { 0, 8, 1, 8, 1, 7, 7, 1, 5, 11, 6, 7, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 2, 7, 9, 5, 9, 7, 11, 7, 2, 2, 9, 10, -1 },
//    { 8, 9, 7, 9, 7, 5, 3, 2, 11, -1, -1, -1, -1 },
//    { 9, 0, 5, 0, 5, 3, 3, 5, 7, 2, 11, 3, -1 },
//    { 8, 0, 2, 8, 2, 5, 5, 10, 2, 7, 8, 5, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 5, 7, 9, 7, 9, 8, 10, 2, 1, -1, -1, -1, -1 },
//    { 5, 7, 1, 7, 3, 1, -1, -1, -1, -1, -1, -1, -1 },
//    { 11, 2, 7, 2, 7, 1, 1, 7, 5, 0, 9, 1, -1 },
//    { 2, 10, 3, 10, 3, 5, 5, 3, 7, 9, 4, 5, -1 },
//    { 7, 6, 8, 6, 8, 10, 10, 8, 9, -1, -1, -1, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 11, 0, 5, 4, 5, 0, 3, 0, 11, 11, 5, 7, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 1, 3, 10, 3, 10, 11, 9, 4, 5, -1, -1, -1, -1 },
//    { 2, 1, 5, 2, 5, 8, 8, 4, 5, 11, 2, 8, -1 },
//    { 1, 5, 0, 5, 0, 4, 2, 11, 3, -1, -1, -1, -1 },
//    { 8, 11, 0, 11, 0, 2, 4, 5, 9, -1, -1, -1, -1 },
//    { 4, 5, 9, 3, 2, 11, -1, -1, -1, -1, -1, -1, -1 },
//    { 2, 10, 5, 2, 5, 4, 2, 4, 3, 3, 8, 4, -1 },
//    { 11, 7, 2, 7, 2, 4, 4, 2, 0, 5, 9, 4, -1 },
//    { 8, 3, 0, 2, 1, 10, 5, 9, 4, -1, -1, -1, -1 },
//    { 4, 5, 9, 10, 2, 1, -1, -1, -1, -1, -1, -1, -1 },
//    { 6, 11, 5, 11, 5, 3, 3, 5, 1, 8, 0, 3, -1 },
//    { 5, 10, 4, 10, 4, 2, 2, 4, 0, -1, -1, -1, -1 },
//    { 3, 8, 0, 4, 5, 9, -1, -1, -1, -1, -1, -1, -1 },
//    { 5, 4, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 3, 0, 11, 0, 11, 9, 9, 11, 10, 4, 5, 9, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 7, 11, 10, 7, 10, 0, 0, 1, 10, 4, 7, 0, -1 },
//    { 11, 10, 3, 10, 3, 1, 7, 4, 8, -1, -1, -1, -1 },
//    { 1, 2, 11, 1, 11, 7, 1, 7, 9, 9, 4, 7, -1 },
//    { 4, 7, 8, 11, 3, 2, 1, 0, 9, -1, -1, -1, -1 },
//    { 5, 10, 4, 10, 4, 2, 2, 4, 0, 11, 3, 2, -1 },
//    { 4, 8, 7, 3, 2, 11, -1, -1, -1, -1, -1, -1, -1 },
//    { 7, 9, 2, 10, 2, 9, 4, 9, 7, 7, 2, 6, -1 },
//    { 0, 2, 9, 2, 9, 10, 8, 7, 4, -1, -1, -1, -1 },
//    { 0, 4, 3, 4, 3, 7, 1, 10, 2, -1, -1, -1, -1 },
//    { 10, 2, 1, 4, 8, 7, -1, -1, -1, -1, -1, -1, -1 },
//    { 10, 6, 1, 6, 1, 7, 7, 1, 3, 4, 8, 7, -1 },
//    { 7, 4, 8, 9, 1, 0, -1, -1, -1, -1, -1, -1, -1 },
//    { 4, 9, 7, 9, 7, 1, 1, 7, 3, -1, -1, -1, -1 },
//    { 8, 4, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 10, 9, 11, 9, 8, 11, -1, -1, -1, -1, -1, -1, -1 },
//    { 0, 9, 10, 0, 10, 7, 7, 6, 10, 3, 0, 7, -1 },
//    { 5, 4, 10, 4, 10, 8, 8, 10, 11, 0, 3, 8, -1 },
//    { 10, 6, 1, 6, 1, 7, 7, 1, 3, -1, -1, -1, -1 },
//    { 6, 5, 11, 5, 11, 9, 9, 11, 8, 1, 0, 9, -1 },
//    { 11, 3, 2, 0, 9, 1, -1, -1, -1, -1, -1, -1, -1 },
//    { 11, 7, 2, 7, 2, 4, 4, 2, 0, -1, -1, -1, -1 },
//    { 11, 2, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 7, 6, 8, 6, 8, 10, 10, 8, 9, 2, 1, 10, -1 },
//    { 9, 5, 0, 5, 0, 6, 6, 0, 2, -1, -1, -1, -1 },
//    { 10, 2, 1, 3, 8, 0, -1, -1, -1, -1, -1, -1, -1 },
//    { 2, 10, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { 3, 1, 8, 1, 8, 9, 11, 6, 7, -1, -1, -1, -1 },
//    { 1, 0, 9, 6, 7, 11, -1, -1, -1, -1, -1, -1, -1 },
//    { 8, 3, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 },
//    { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 }
//};
int lookUpTable[256][13] =
{
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{3,8,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{0,9,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{3,8,9,3,9,1,-1,-1,-1,-1,-1,-1,-1},
	{10,2,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{10,2,1,8,0,3,-1,-1,-1,-1,-1,-1,-1},
	{0,9,10,0,10,2,-1,-1,-1,-1,-1,-1,-1},
	{2,3,10,10,3,8,8,9,10,-1,-1,-1,-1},
	{2,11,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{2,11,8,2,8,0,-1,-1,-1,-1,-1,-1,-1},
	{11,3,2,9,1,0,-1,-1,-1,-1,-1,-1,-1},
	{1,2,9,9,2,11,11,8,9,-1,-1,-1,-1},
	{1,10,11,1,11,3,-1,-1,-1,-1,-1,-1,-1},
	{0,1,8,8,1,10,10,11,8,-1,-1,-1,-1},
	{3,0,11,11,0,9,9,10,11,-1,-1,-1,-1},
	{9,8,11,11,10,9,-1,-1,-1,-1,-1,-1,-1},
	{4,8,7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{0,3,7,0,7,4,-1,-1,-1,-1,-1,-1,-1},
	{7,4,8,1,0,9,-1,-1,-1,-1,-1,-1,-1},
	{4,9,7,7,9,1,1,3,7,-1,-1,-1,-1},
	{7,4,8,2,1,10,-1,-1,-1,-1,-1,-1,-1},
	{10,2,1,0,3,7,7,4,0,-1,-1,-1,-1},
	{7,4,8,0,9,10,10,2,0,-1,-1,-1,-1},
	{7,4,9,7,2,3,7,2,9,2,10,9,-1},
	{4,8,7,2,11,3,-1,-1,-1,-1,-1,-1,-1},
	{11,7,2,2,7,4,4,0,2,-1,-1,-1,-1},
	{2,3,11,1,0,9,7,8,4,-1,-1,-1,-1},
	{4,7,11,4,11,2,4,9,2,2,1,9,-1},
	{4,8,7,11,3,1,1,10,11,-1,-1,-1,-1},
	{7,4,11,4,0,1,4,11,1,11,10,1,-1},
	{7,4,8,11,10,9,3,0,11,0,9,11,-1},
	{4,7,9,9,7,11,11,10,9,-1,-1,-1,-1},
	{4,5,9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{5,9,4,3,8,0,-1,-1,-1,-1,-1,-1,-1},
	{4,5,1,4,1,0,-1,-1,-1,-1,-1,-1,-1},
	{8,4,3,3,4,5,5,1,3,-1,-1,-1,-1},
	{4,5,9,2,1,10,-1,-1,-1,-1,-1,-1,-1},
	{10,1,2,5,9,4,3,0,8,-1,-1,-1,-1},
	{5,10,4,4,10,2,2,0,4,-1,-1,-1,-1},
	{2,3,10,10,5,3,3,8,5,8,4,5,-1},
	{2,3,11,4,5,9,-1,-1,-1,-1,-1,-1,-1},
	{5,9,4,8,0,2,2,11,8,-1,-1,-1,-1},
	{11,3,2,1,0,4,4,5,1,-1,-1,-1,-1},
	{2,1,5,5,4,8,8,5,2,2,11,8,-1},
	{4,5,9,1,10,11,11,3,1,-1,-1,-1,-1},
	{10,11,8,1,0,10,1,0,8,5,4,9,-1},
	{4,3,0,3,10,4,4,5,10,3,10,11,-1},
	{5,4,10,10,4,8,8,11,10,-1,-1,-1,-1},
	{5,9,8,5,8,7,-1,-1,-1,-1,-1,-1,-1},
	{9,0,5,5,0,3,3,7,5,-1,-1,-1,-1},
	{0,8,1,1,8,7,7,5,1,-1,-1,-1,-1},
	{3,7,5,5,1,3,-1,-1,-1,-1,-1,-1,-1},
	{2,1,10,5,9,8,8,7,5,-1,-1,-1,-1},
	{2,1,10,0,9,5,3,5,0,3,7,5,-1},
	{0,2,10,10,0,7,7,5,10,8,0,7,-1},
	{2,10,3,3,10,5,5,7,3,-1,-1,-1,-1},
	{2,11,3,8,7,5,5,9,8,-1,-1,-1,-1},
	{5,11,7,2,11,0,5,11,0,5,9,0,-1},
	{2,3,11,1,5,7,1,0,8,0,8,7,-1},
	{11,2,7,7,2,1,1,5,7,-1,-1,-1,-1},
	{1,11,10,1,11,3,7,8,9,7,5,9,-1},
	{0,9,1,10,5,7,7,11,10,-1,-1,-1,-1},
	{0,3,8,7,11,10,10,5,7,-1,-1,-1,-1},
	{10,5,7,10,7,11,-1,-1,-1,-1,-1,-1,-1},
	{10,5,6,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{5,6,10,0,3,8,-1,-1,-1,-1,-1,-1,-1},
	{0,9,1,6,10,5,-1,-1,-1,-1,-1,-1,-1},
	{6,10,5,9,1,3,3,8,9,-1,-1,-1,-1},
	{5,6,2,5,2,1,-1,-1,-1,-1,-1,-1,-1},
	{8,0,3,2,1,5,5,6,2,-1,-1,-1,-1},
	{9,5,0,0,5,6,6,2,0,-1,-1,-1,-1},
	{3,8,6,3,8,9,3,2,6,6,5,9,-1},
	{5,6,10,3,2,11,-1,-1,-1,-1,-1,-1,-1},
	{5,6,10,2,11,8,8,0,2,-1,-1,-1,-1},
	{0,1,9,3,2,11,5,10,6,-1,-1,-1,-1},
	{1,2,9,9,2,11,11,8,9,6,5,10,-1},
	{6,11,5,5,11,3,3,1,5,-1,-1,-1,-1},
	{0,1,5,5,6,11,5,11,0,8,0,11,-1},
	{9,6,5,6,9,0,6,11,0,0,3,11,-1},
	{6,5,11,11,5,9,9,8,11,-1,-1,-1,-1},
	{10,5,6,8,7,4,-1,-1,-1,-1,-1,-1,-1},
	{10,5,6,7,4,0,0,3,7,-1,-1,-1,-1},
	{1,9,0,10,5,6,8,4,7,-1,-1,-1,-1},
	{10,6,5,1,9,7,7,4,9,1,7,3,-1},
	{8,7,4,5,6,2,2,1,5,-1,-1,-1,-1},
	{5,6,2,2,1,5,7,4,0,0,3,7,-1},
	{7,8,4,6,5,0,0,9,5,6,0,2,-1},
	{9,4,5,6,7,3,3,2,6,-1,-1,-1,-1},
	{10,6,5,2,11,3,4,7,8,-1,-1,-1,-1},
	{11,7,2,2,7,4,4,0,2,6,5,10,-1},
	{7,4,8,6,5,10,0,1,9,3,2,11,-1},
	{9,5,4,1,10,2,7,6,11,-1,-1,-1,-1},
	{6,11,5,5,11,3,3,1,5,7,4,8,-1},
	{11,6,7,4,5,1,1,0,4,-1,-1,-1,-1},
	{11,7,6,3,8,0,5,4,9,-1,-1,-1,-1},
	{9,4,5,11,6,7,-1,-1,-1,-1,-1,-1,-1},
	{9,4,6,9,6,10,-1,-1,-1,-1,-1,-1,-1},
	{3,8,0,9,4,6,6,10,9,-1,-1,-1,-1},
	{10,1,6,6,1,0,0,4,6,-1,-1,-1,-1},
	{6,4,10,10,4,3,3,4,8,10,1,3,-1},
	{1,9,2,2,9,4,4,6,2,-1,-1,-1,-1},
	{1,9,2,2,9,4,4,6,2,0,3,8,-1},
	{2,0,4,4,6,2,-1,-1,-1,-1,-1,-1,-1},
	{8,3,4,4,3,2,2,6,4,-1,-1,-1,-1},
	{3,2,11,6,10,9,9,4,6,-1,-1,-1,-1},
	{8,2,0,8,2,11,10,6,4,10,9,4,-1},
	{10,1,6,6,1,0,0,4,6,3,2,11,-1},
	{1,10,2,11,6,4,4,8,11,-1,-1,-1,-1},
	{11,3,6,3,9,6,9,6,4,3,9,1,-1},
	{1,0,9,4,8,11,11,6,4,-1,-1,-1,-1},
	{3,11,0,0,11,6,6,4,0,-1,-1,-1,-1},
	{11,6,4,11,4,8,-1,-1,-1,-1,-1,-1,-1},
	{7,6,8,8,6,10,10,9,8,-1,-1,-1,-1},
	{0,3,9,3,6,9,6,9,10,3,6,7,-1},
	{0,1,10,0,10,6,0,8,6,6,7,8,-1},
	{10,6,1,1,6,7,7,3,1,-1,-1,-1,-1},
	{6,7,2,7,2,9,2,9,1,7,9,8,-1},
	{9,1,0,3,2,6,6,7,3,-1,-1,-1,-1},
	{7,8,6,6,8,0,0,2,6,-1,-1,-1,-1},
	{3,2,6,3,6,7,-1,-1,-1,-1,-1,-1,-1},
	{7,6,8,8,6,10,10,9,8,3,2,11,-1},
	{7,11,6,10,2,0,0,9,10,-1,-1,-1,-1},
	{6,11,7,10,2,1,8,3,0,-1,-1,-1,-1},
	{7,11,6,1,10,2,-1,-1,-1,-1,-1,-1,-1},
	{6,7,11,3,8,9,9,1,3,-1,-1,-1,-1},
	{7,6,11,1,0,9,-1,-1,-1,-1,-1,-1,-1},
	{6,7,11,0,3,8,-1,-1,-1,-1,-1,-1,-1},
	{6,7,11,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{6,7,11,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{6,7,11,0,3,8,-1,-1,-1,-1,-1,-1,-1},
	{7,6,11,1,0,9,-1,-1,-1,-1,-1,-1,-1},
	{6,7,11,3,8,9,9,1,3,-1,-1,-1,-1},
	{7,11,6,1,10,2,-1,-1,-1,-1,-1,-1,-1},
	{6,11,7,10,2,1,8,3,0,-1,-1,-1,-1},
	{7,11,6,10,2,0,0,9,10,-1,-1,-1,-1},
	{8,9,10,2,3,8,2,3,10,11,7,6,-1},
	{3,2,6,3,6,7,-1,-1,-1,-1,-1,-1,-1},
	{7,8,6,6,8,0,0,2,6,-1,-1,-1,-1},
	{9,1,0,3,2,6,6,7,3,-1,-1,-1,-1},
	{6,7,2,7,2,9,2,9,1,7,9,8,-1},
	{10,6,1,1,6,7,7,3,1,-1,-1,-1,-1},
	{0,1,10,0,10,6,0,8,6,6,7,8,-1},
	{0,3,9,3,6,9,6,9,10,3,6,7,-1},
	{7,6,8,8,6,10,10,9,8,-1,-1,-1,-1},
	{11,6,4,11,4,8,-1,-1,-1,-1,-1,-1,-1},
	{3,11,0,0,11,6,6,4,0,-1,-1,-1,-1},
	{1,0,9,4,8,11,11,6,4,-1,-1,-1,-1},
	{11,3,6,3,9,6,9,6,4,3,9,1,-1},
	{1,10,2,11,6,4,4,8,11,-1,-1,-1,-1},
	{1,2,10,0,4,6,0,3,11,0,6,11,-1},
	{0,2,9,2,9,10,8,11,4,11,4,6,-1},
	{3,2,11,6,10,9,9,4,6,-1,-1,-1,-1},
	{8,3,4,4,3,2,2,6,4,-1,-1,-1,-1},
	{2,0,4,4,6,2,-1,-1,-1,-1,-1,-1,-1},
	{2,4,6,4,8,3,3,8,2,1,9,0,-1},
	{1,9,2,2,9,4,4,6,2,-1,-1,-1,-1},
	{1,3,8,1,8,6,1,10,6,8,4,6,-1},
	{10,1,6,6,1,0,0,4,6,-1,-1,-1,-1},
	{3,8,0,9,4,6,6,10,9,-1,-1,-1,-1},
	{9,4,6,9,6,10,-1,-1,-1,-1,-1,-1,-1},
	{9,4,5,11,6,7,-1,-1,-1,-1,-1,-1,-1},
	{11,7,6,3,8,0,5,4,9,-1,-1,-1,-1},
	{11,6,7,4,5,1,1,0,4,-1,-1,-1,-1},
	{7,11,6,1,5,3,8,4,5,8,4,3,-1},
	{9,5,4,1,10,2,7,6,11,-1,-1,-1,-1},
	{0,3,8,9,5,4,11,7,6,1,2,10,-1},
	{2,0,4,4,5,10,2,5,10,7,11,6,-1},
	{10,6,5,2,11,3,4,7,8,-1,-1,-1,-1},
	{9,4,5,6,7,3,3,2,6,-1,-1,-1,-1},
	{0,2,6,8,7,0,8,7,6,9,5,4,-1},
	{1,0,5,0,5,4,3,2,6,3,6,7,-1},
	{8,7,4,5,6,2,2,1,5,-1,-1,-1,-1},
	{1,3,7,10,6,7,10,6,1,5,9,4,-1},
	{1,9,0,10,5,6,8,4,7,-1,-1,-1,-1},
	{10,5,6,7,4,0,0,3,7,-1,-1,-1,-1},
	{10,5,6,8,7,4,-1,-1,-1,-1,-1,-1,-1},
	{6,5,11,11,5,9,9,8,11,-1,-1,-1,-1},
	{9,6,5,6,9,0,6,11,0,0,3,11,-1},
	{5,6,11,5,0,1,0,5,11,0,8,11,-1},
	{6,11,5,5,11,3,3,1,5,-1,-1,-1,-1},
	{11,9,8,5,6,9,5,6,11,1,10,2,-1},
	{0,1,9,3,2,11,5,10,6,-1,-1,-1,-1},
	{5,6,10,2,11,8,8,0,2,-1,-1,-1,-1},
	{5,6,10,3,2,11,-1,-1,-1,-1,-1,-1,-1},
	{9,8,3,3,9,6,6,2,3,5,9,6,-1},
	{9,5,0,0,5,6,6,2,0,-1,-1,-1,-1},
	{8,0,3,2,1,5,5,6,2,-1,-1,-1,-1},
	{5,6,2,5,2,1,-1,-1,-1,-1,-1,-1,-1},
	{6,10,5,9,1,3,3,8,9,-1,-1,-1,-1},
	{0,9,1,6,10,5,-1,-1,-1,-1,-1,-1,-1},
	{5,6,10,0,3,8,-1,-1,-1,-1,-1,-1,-1},
	{10,5,6,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{10,5,7,10,7,11,-1,-1,-1,-1,-1,-1,-1},
	{0,3,8,7,11,10,10,5,7,-1,-1,-1,-1},
	{0,9,1,10,5,7,7,11,10,-1,-1,-1,-1},
	{1,9,8,1,8,3,10,5,7,10,7,11,-1},
	{11,2,7,7,2,1,1,5,7,-1,-1,-1,-1},
	{1,5,7,2,11,1,2,11,7,0,3,8,-1},
	{9,5,7,9,7,2,7,2,11,9,0,2,-1},
	{2,11,3,8,7,5,5,9,8,-1,-1,-1,-1},
	{2,10,3,3,10,5,5,7,3,-1,-1,-1,-1},
	{5,7,8,8,2,5,2,0,8,10,5,2,-1},
	{3,7,5,2,10,3,2,10,5,1,0,9,-1},
	{2,1,10,5,9,8,8,7,5,-1,-1,-1,-1},
	{3,7,5,5,1,3,-1,-1,-1,-1,-1,-1,-1},
	{0,8,1,1,8,7,7,5,1,-1,-1,-1,-1},
	{9,0,5,5,0,3,3,7,5,-1,-1,-1,-1},
	{5,9,8,5,8,7,-1,-1,-1,-1,-1,-1,-1},
	{5,4,10,10,4,8,8,11,10,-1,-1,-1,-1},
	{4,3,0,3,10,4,4,5,10,3,10,11,-1},
	{8,11,10,4,5,10,4,5,8,1,9,0,-1},
	{4,5,9,1,10,11,11,3,1,-1,-1,-1,-1},
	{2,1,5,5,4,8,8,5,2,2,11,8,-1},
	{11,3,2,1,0,4,4,5,1,-1,-1,-1,-1},
	{5,9,4,8,0,2,2,11,8,-1,-1,-1,-1},
	{2,3,11,4,5,9,-1,-1,-1,-1,-1,-1,-1},
	{2,3,10,10,5,3,3,8,5,8,4,5,-1},
	{5,10,4,4,10,2,2,0,4,-1,-1,-1,-1},
	{10,1,2,5,9,4,3,0,8,-1,-1,-1,-1},
	{4,5,9,2,1,10,-1,-1,-1,-1,-1,-1,-1},
	{8,4,3,3,4,5,5,1,3,-1,-1,-1,-1},
	{4,5,1,4,1,0,-1,-1,-1,-1,-1,-1,-1},
	{5,9,4,3,8,0,-1,-1,-1,-1,-1,-1,-1},
	{4,5,9,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{4,7,9,9,7,11,11,10,9,-1,-1,-1,-1},
	{9,10,11,4,7,9,4,7,11,0,3,8,-1},
	{7,4,11,4,0,1,4,11,1,11,10,1,-1},
	{4,8,7,11,3,1,1,10,11,-1,-1,-1,-1},
	{4,7,11,4,11,2,4,9,2,2,1,9,-1},
	{2,3,11,1,0,9,7,8,4,-1,-1,-1,-1},
	{11,7,2,2,7,4,4,0,2,-1,-1,-1,-1},
	{4,8,7,2,11,3,-1,-1,-1,-1,-1,-1,-1},
	{3,7,4,3,4,10,4,9,10,2,3,10,-1},
	{7,4,8,0,9,10,10,2,0,-1,-1,-1,-1},
	{10,2,1,0,3,7,7,4,0,-1,-1,-1,-1},
	{7,4,8,2,1,10,-1,-1,-1,-1,-1,-1,-1},
	{4,9,7,7,9,1,1,3,7,-1,-1,-1,-1},
	{7,4,8,1,0,9,-1,-1,-1,-1,-1,-1,-1},
	{0,3,7,0,7,4,-1,-1,-1,-1,-1,-1,-1},
	{4,8,7,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{9,8,11,11,10,9,-1,-1,-1,-1,-1,-1,-1},
	{3,0,11,11,0,9,9,10,11,-1,-1,-1,-1},
	{0,1,8,8,1,10,10,11,8,-1,-1,-1,-1},
	{1,10,11,1,11,3,-1,-1,-1,-1,-1,-1,-1},
	{1,2,9,9,2,11,11,8,9,-1,-1,-1,-1},
	{11,3,2,9,1,0,-1,-1,-1,-1,-1,-1,-1},
	{2,11,8,2,8,0,-1,-1,-1,-1,-1,-1,-1},
	{2,11,3,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{2,3,10,10,3,8,8,9,10,-1,-1,-1,-1},
	{0,9,10,0,10,2,-1,-1,-1,-1,-1,-1,-1},
	{10,2,1,8,0,3,-1,-1,-1,-1,-1,-1,-1},
	{10,2,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{3,8,9,3,9,1,-1,-1,-1,-1,-1,-1,-1},
	{0,9,1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{3,8,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
	{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
};
float arete[12][3]={
    {0.0,0.5,0.0},
    {0.5,1.0,0.0},
    {1.0,0.5,0.0},
    {0.5,0.0,0.0},
    {0.0,0.5,1.0},
    {0.5,1.0,1.0},
    {1.0,0.5,1.0},
    {0.5,0.0,1.0},
    {0.0,0.0,0.5},
    {0.0,1.0,0.5},
    {1.0,1.0,0.5},
    {1.0,0.0,0.5},
};

point3D*** allocGrille(int size_x,int size_y, int size_z){
    point3D*** allocTable = new point3D**[size_x];
    for(int i=0; i < size_x; i ++){
        allocTable[i] = new point3D*[size_y];
    }
    for(int i=0; i < size_x; i ++){
        for(int j=0; j < size_y; j ++){
            allocTable[i][j] = new point3D[size_z];
            }
    }
    return allocTable;
};



void deleteGrille(point3D***Grille,int size_y,int size_x){
    for(int i = 0; i<size_x; i++){
        for(int j=0; j<size_y; j++){
            delete[] Grille[i][j];
        }
        delete[] Grille[i];
    }
    delete[] Grille;
};

bool distance(float pX,float pY,float pZ,float cX, float cY,float cZ,float r){
    float dist=sqrt(pow((pX-cX),2)+pow((pY-cY),2)+pow((pZ-cZ),2));
    if(dist<=r){
        return true;
    }
    else{
        return false;
    }
};

void initGrille(point3D ***Grille,int size_x,int size_y, int size_z,float cX, float cY,float cZ,float r){
    for(int i=0 ;i<size_x ;i++){
        for(int j=0;j<size_y ;j++){
            for(int k=0;k<size_z;k++){
                float pX = float(i);
                float pY = float(j);
                float pZ = float(k);
                if(distance(pX,pY,pZ,cX,cY,cZ,r)==true){
                    Grille[i][j][k].allume=true ;
               }
               else{
                    Grille[i][j][k].allume=false;
                }
            }
        }
    }

}

int calIndex(bool tab[8]){
    int index = 0;
    for(int i=0; i<8; i++){
        if(tab[i]==true){
            index += int(pow(2,i));
        }
    }
    return index;
}


void genFichier(point3D ***Grille,int size_x,int size_y, int size_z){
    ofstream f;
    int cpt=0;
    f.open("projetTableTest2.obj",ios::out | ios::app);
    f<<"g Object001"<<endl;
    for(int i=0 ;i<size_x -1;i++){
        for(int j=0;j<size_y-1 ;j++){
            for(int k=0;k<size_z-1;k++){
                    bool voisin[8] = {
                        Grille[i][j][k].allume,
                        Grille[i][j+1][k].allume,
                        Grille[i+1][j+1][k].allume,
                        Grille[i+1][j][k].allume,
                        Grille[i][j][k+1].allume,
                        Grille[i][j+1][k+1].allume,
                        Grille[i+1][j+1][k+1].allume,
                        Grille[i+1][j][k+1].allume
                    };
                    int index = calIndex(voisin);
                    int l=0;
                    int numero;
                    float aretI;
                    float areteJ;
                    float areteK;
                    while(lookUpTable[index][l]!=-1){
                        numero = lookUpTable[index][l];
                        aretI =i+arete[numero][0];
                        areteJ =j+arete[numero][1];
                        areteK=k+arete[numero][2];
                        f<<"v"<<" "<<aretI;
                        f<<" "<<areteJ;
                        f<<" "<<areteK<<endl;
                        cpt++;
                        l++;
                    }
            }
        }
    }
    for(int m=1;m<cpt;m=m+3){
        f<<"f"<<" "<<m<<" "<<m+1<<" "<<m+2<<endl;
    }
    f.close();
}

int main()
{
    point3D***Grille = allocGrille(10,10,10);
    initGrille(Grille,10,10,10,5,5,5,3);
    genFichier(Grille,10,10,10);
    cout << "Hello world!" << endl;
    deleteGrille(Grille, 10,10);
    return 0;
}

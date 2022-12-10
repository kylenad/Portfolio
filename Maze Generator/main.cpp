//Libraries -----------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include "maze.h"
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <utility>
//---------------------------------------------------------------------------------------------------------------------

//main ----------------------------------------------------------------------------------------------------------------
int main (int argc, char *agrv[]) {
    //arguments -------------------------------------------------------------------------------------------------------
//number for random seed
    int seed = std::stoi(agrv[1]);
//number of rows in the grid N > 0
    int N = std::stoi(agrv[2]);
//number of columns in the grid M > 0
    int M = std::stoi(agrv[3]);
//file output name
    std::string outPutFile = agrv[4];
//---------------------------------------------------------------------------------------------------------------------


    maze rand_maze = maze();

    rand_maze.random_maze(N, M, seed, outPutFile);


    return 0;
}
//---------------------------------------------------------------------------------------------------------------------
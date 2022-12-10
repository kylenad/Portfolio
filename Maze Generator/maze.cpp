//Libraries -----------------------------------------------------------------------------------------------------------
#include "maze.h"
//---------------------------------------------------------------------------------------------------------------------


//make function that was initialized in the .h file and called in the main.cpp
void maze::random_maze(int N, int M, int seed, std::string outPutFile) {

//process of declaring base dynamic array size and standard grid values ----------------------------------------------
//empty dynamic array starting point
    std::vector<std::vector<int> > start_arr;
//random number picker seed value
    std::srand(seed);
//set values/bounds of dynamic array
    for (int i = 0; i < N; i++) {
        std::vector<int> temp;
        for (int j = 0; j < M; j++) {
            temp.push_back(15);
        }
        start_arr.push_back(temp);
    }
//---------------------------------------------------------------------------------------------------------------------









//checking random neighborhoods and deleting --------------------------------------------------------------------------
//declare A and neighbors dynamic arrays
    std::vector<std::pair<int, int> > A;
//array that stores possible neighbor values
    std::vector<std::pair<int, int> > neighbors;
//save current val here
    std::pair<int, int> current;
//added for neighbors index rand value
    std::pair<int, int> neigh;
    //true false check vector
    std::vector<std::vector<int> > tf_check;
    for (int i = 0; i < N; i++) {
        std::vector<int> temp_2;
        for (int j = 0; j < M; j++) {
            temp_2.push_back(false);
        }
        tf_check.push_back(temp_2);
    }
    std::vector<std::pair<int, int> > tf;
//push A[0][0] into the array
    A.push_back(std::make_pair(0,0));
    
    while (A.size() != 0) {
//erase last element of A
//find last/current element
//position of last
        current = A[A.size() - 1];
        A.erase(A.begin() + A.size() -1);

//next, find the neighbors not visited
//clear neighbors
neighbors.clear();

//make directions (use pairs) //LOOK UP PAIRS TUTORIAL
//north
        std::pair<int, int> north;
        north.first = current.first - 1;
        north.second = current.second;
//south
        std::pair<int, int> south;
        south.first = current.first + 1;
        south.second = current.second;
//east
        std::pair<int, int> east;
        east.first = current.first;
        east.second = current.second + 1;
//west
        std::pair<int, int> west;
        west.first = current.first;
        west.second = current.second - 1;

        //bounds check
        if (current.first - 1 >= 0 ) {
            if (tf_check[current.first - 1][current.second] == false) {
                //north possibility check
                neighbors.push_back(north);
            }
        }
        //bounds check
        if (current.first + 1 <= N - 1) {
            if (tf_check[current.first + 1][current.second] == false) {
                //south possibility check
                neighbors.push_back(south);
            }
        }
        //bounds check
        if (current.second + 1 <= M- 1) {
            if (tf_check[current.first][current.second + 1] == false) {
                //east possibility check
                neighbors.push_back(east);
            }
        }
        //bounds check
        if (current.second - 1 >= 0) {
            if (tf_check[current.first][current.second - 1] == false) {
                //west possibility check
                neighbors.push_back(west);
            }
        }


        //pick rand use index code
        //checks if there were any neighbors
        if (neighbors.size() != 0) {
            A.push_back(current);


            //index code from github
           int idx = std::rand() / ((RAND_MAX + 1u) / neighbors.size());
           //neighbor to change
            neigh = neighbors[idx];

            //start changing cell values for walls to erase (note, play around with maze visualizer)
            //use the pair values
            //for north neighbor
            if (current.first - 1 == neigh.first) {
                start_arr[current.first][current.second] = start_arr[current.first][current.second] - 8;
                start_arr[neigh.first][neigh.second] = start_arr[neigh.first][neigh.second] - 4;

            }
                //for south neighbor
            else if (current.first + 1 == neigh.first) {
                start_arr[current.first][current.second] = start_arr[current.first][current.second] - 4;
                start_arr[neigh.first][neigh.second] = start_arr[neigh.first][neigh.second] - 8;
            }
                //for east neighbor
            else if (current.second + 1 == neigh.second) {
                start_arr[current.first][current.second] = start_arr[current.first][current.second] - 2;
                start_arr[neigh.first][neigh.second] = start_arr[neigh.first][neigh.second] - 1;
            }
                //for west neighbor
            else if (current.second - 1 == neigh.second) {
                start_arr[current.first][current.second] = start_arr[current.first][current.second] - 1;
                start_arr[neigh.first][neigh.second] = start_arr[neigh.first][neigh.second] - 2;
            }
            A.push_back(neigh);
            if (current.first - 1 == neigh.first) {
                tf_check[current.first][current.second] = start_arr[current.first][current.second] + 1;
                tf_check[neigh.first][neigh.second] = start_arr[neigh.first][neigh.second] + 1;

            }
                //for south neighbor
            else if (current.first + 1 == neigh.first) {
                tf_check[current.first][current.second] = start_arr[current.first][current.second] + 1;
                tf_check[neigh.first][neigh.second] = start_arr[neigh.first][neigh.second] + 1;
            }
                //for east neighbor
            else if (current.second + 1 == neigh.second) {
                tf_check[current.first][current.second] = start_arr[current.first][current.second] + 1;
                tf_check[neigh.first][neigh.second] = start_arr[neigh.first][neigh.second] + 1;
            }
                //for west neighbor
            else if (current.second - 1 == neigh.second) {
                tf_check[current.first][current.second] = start_arr[current.first][current.second] + 1;
                tf_check[neigh.first][neigh.second] = start_arr[neigh.first][neigh.second] + 1;
            }
        }
    }
//make start and end values open
    start_arr[0][0] = start_arr[0][0] - 8;
    start_arr[N-1][M-1] = start_arr[N-1][M-1] - 4;


//---------------------------------------------------------------------------------------------------------------------











//write file ----------------------------------------------------------------------------------------------------------

//std::fstream output_file;
    std::ofstream output_file(outPutFile);

    for(int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            output_file << start_arr[i][j] << " ";
        }
        output_file << "\n";
    }
    
//---------------------------------------------------------------------------------------------------------------------
}



# Portfolio:




## PAC-MAN Replica
### Group Members:
  Alex Estrada, Kyle Nadeau, Wes Hardesky
  
### Implementation
In this project we created the base game of PacMan where each ghost has been coded to move randomly around the map. The game was then modified so that one of the ghosts behaves independently from the others using the A* search algorithm. This provides the ghost with the ability to find the shortest path to the last known location of PacMan and follow him until he is captured.  This project was made using C++.

### How does A* Search work?
The functionality of A* is to find the shortest path between a starting coordinate and an end goal. This is done by using a heuristic value *h*, which estimates the distance between a point on the graph and the endpoint. In addition to the heuristic values, it uses the distance measured between each point to the next, *g*. After evaluating each path, the shortest path is recorded. The image below shows the process of how the algorithm is calculated.

<img src="https://raw.githubusercontent.com/aestrada30/Term-Project/main/AStar.png" height="500" width="700" >

### How to run on Windows Visual Studio 
In order to be able to run the base game begin by following the instructions on either the [64-bit](https://github.com/djperrone/glew_glut_64) or [32-bit](https://github.com/djperrone/opengl_glew_glut_starter) link.  Once the *csc406setup* project is setup, replace the code in the main file with the game code and run the program.

### How to run on Mac OS
1. First, make sure you have *Xcode* installed on your Mac with the necessary packages to run it.  You can install *Xcode* through the app store.
2. Create a directory in *Xcode* 
3. In the main project window, add *GLUT.framework* and *OpenGL.framework* to the Frameworks and Libraries in order to utilize *GLUT* and *OpenGL* in this directory.
4. Download each of the **.cpp** and **.h** files for Mac-OS and add them to your directory
5. Click on the Product tab at the top of the screen and select **Run** to launch the program






















## Image Binarization 
Binarization, otherwise known as thresholding, is the process of taking a grayscale image and converting it into images that are black and white. Grayscale images contain pixels ranging from 0 to 255 in intensity, while black and white images have pixels that are either 0 or 255 in intensity.  There are two different approaches to performing binarization, being global and local binarization.  For global, you need to calculate the median value of all pixels in the image.  If a pixel is less than this threshold value, it is converted to 0 intensity.  If the pixel value is greater than the threshold, it is converted to 255 intensity.  Local binarization focuses on changing pixels based on the pixel intensity values located in smaller "neighborhoods” within the picture. This project was made using C++.

<details>
  <summary>Binarization Code</summary>
  
  ### Binarization Code
  ```C++
  //Libraries --------------------------------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <iterator>
//-------------------------------------------------------------------------------------------------------------



//read file function ------------------------------------------------------------------------------------------
 void readFile(std::vector<std::vector<double> > &image2DSpace, std::string &fileName, std::vector<std::vector<double> > &copy_1)
  {

    std::ifstream inFile(fileName);
    std::string line;

    while (std::getline(inFile, line)) {
        std::vector <double> temp;
        std::istringstream stream(line);
        double val;
        while(stream >> val) {
            temp.push_back(val);
        }
        image2DSpace.push_back(temp);
        copy_1.push_back(temp);
      
    }
}
//-------------------------------------------------------------------------------------------------------------





//write file function -----------------------------------------------------------------------------------------
void writeFile(std::string &outPutFile, std::vector<std::vector<double> > &processImage) {

    std::ofstream output_file(outPutFile);

    for (std::vector<std::vector<double> >::const_iterator i = (processImage).begin(); i != (processImage).end(); ++i) {
        for (std::vector<double>::const_iterator j = i->begin(); j != i->end(); ++j) {
            output_file << *j << " ";
        }
        output_file << "\n";
    }
}
//-------------------------------------------------------------------------------------------------------------








//Global-------------------------------------------------------------------------------------------------------
void funcGlobal(std::vector<std::vector<double> > &image2DSpace, std::vector<std::vector<double> > copy_1, std::string &outPutFile) {
  //global start--------------------------------------------------------------------------------------------------------
  double Thresh;
  //sort through array
  std::vector<double> new1D;
  double size = double (image2DSpace.size());
  for (int i = 0; i < size; i++){
    for (int j = 0; j < double (image2DSpace[i].size()); j++) {
      new1D.push_back(image2DSpace[i][j]);
    }
  }
  
  std::sort(new1D.begin(), new1D.end());
  
  //find median value
  if (new1D.size() % 2 == 0) {
    double middle = new1D.size()/2;
    Thresh = (new1D[middle] + new1D[middle - 1]) / 2;
  }
  else {
    Thresh = new1D[new1D.size()/2];
  }
  
  //iterate through 2d vector after it is read
  for (int i = 0; i < image2DSpace.size(); i++)
    {
      for (int j = 0; j < image2DSpace[i].size(); j++)
        {
          if (image2DSpace[i][j] < Thresh) {
            copy_1[i][j] = 0;
          }
          else {
            copy_1[i][j] = 255;
          }
        }
    }
  //write file (global)
  writeFile(outPutFile, copy_1);
}
//-------------------------------------------------------------------------------------------------------------









//Local--------------------------------------------------------------------------------------------------------
void funcLocal(std::vector<std::vector<double> > &image2DSpace, std::vector<std::vector<double> > copy_1, std::string &outPutFile, int &hood) {
  //make a 1d vector to find min and max values of 2d
  std::vector<double> new1D_2;
  int size_2 = int (image2DSpace.size());
  for (int i = 0; i < size_2; i++){
    for (int j = 0; j < int (image2DSpace[i].size()); j++) {
      new1D_2.push_back(image2DSpace[i][j]);
    }
  }
  
  //get the max and min vals through algo's to get r for thresh local value
  double max_val =   *max_element(new1D_2.begin(), new1D_2.end());
  double min_val =  *min_element(new1D_2.begin(), new1D_2.end());
  double R = 0.5 * (max_val - min_val);
  
  double size = double (image2DSpace.size());
  for (int i = 0; i < size; i++ ){
    for(int j = 0; j < double (image2DSpace[i].size()); j++) {
      std::vector<double> vectfunct;
      for (int k = i - hood; k <= i + hood; k++){
        for (int l = j - hood; l <= j + hood; l++) {
          if (k >= 0 && k < image2DSpace.size() && l >= 0 && l < image2DSpace[k].size()) {
            vectfunct.push_back(image2DSpace[k][l]);
          }
        }
      }
      //find the mean/average-------------------------------------------------------------------------------------------------------
      double sum = 0;
      for(int i = 0; i < vectfunct.size();i++) {
        sum = sum + vectfunct[i];
      }
      
      double me = sum/vectfunct.size();
      //--------------------------------------------------------------------------------------------------------------------
      //find the standard deviation ----------------------------------------------------------------------------------------
      double sd = 0;
      
      for(int i = 0; i < vectfunct.size(); i++) {
        
        sd += pow(vectfunct[i] - me, 2);
      }
      sd = sqrt(sd/vectfunct.size());
      //--------------------------------------------------------------------------------------------------------------------
      // calculate thresh for local
      double Thresh_2 =  me * (1 + 0.2 * ( (sd / R) - 1));
      
      // if then to replace 0's and 255's for the pixel values
      if (image2DSpace[i][j] < Thresh_2) {
        copy_1[i][j] = 0;
      }
      else {
        copy_1[i][j] = 255;
      }
    }
  }
}
//--------------------------------------------------------------------------------------------------------------------------











//Main----------------------------------------------------------------------------------------------------------------------
int main (int argc, char * agrv[]) {
//string to store type (global/local)
std::string type = agrv[1];
// string to store file in name
std::string fileName = agrv[2];
//string to store file out name
std::string outPutFile = agrv[3];

//makes double vector for file (2D space)
std::vector<std::vector<double> > image2DSpace;
//vector copies
std::vector<std::vector<double> > copy_1;



//call read file function
readFile(image2DSpace, fileName, copy_1);



//determine if using global or local function
if (type == "global") {

  funcGlobal(image2DSpace, copy_1, outPutFile);
  }
    
else if (type == "local") {       
  //size of neighborhood
        int neighbor_size = std::stoi(agrv[4]);
        int hood = neighbor_size/2;
        
        funcLocal(image2DSpace, copy_1, outPutFile, hood);
}


    return 0;
}
//-------------------------------------------------------------------------------------------------------------

  ```
</details>

To run this code, you must first select an image in the format .img in order to view the pixels in a text editor.  If your image is not already in .img form (such as png or jpg), you can convert it using any2img.py python script.
 ```
 python3 any2img.py ./imgs/file_Name.png ./imgs/file_Name.img
 ```
 
 Once you are able to view the pixel values in a text file, you can run the code by typing this into the terminal. (This is only one example using global as a parameter)
```
 ./Binarization global file_Name.img file_Name_Output.img
```


## Maze Generator
The goal of this project was to make a program that would generate a random maze out of any size grid you desire.  This program uses dynamic arrays in order to acomplish this.  The input dynamic array defines the size of the grid and is the array which will change in value to generate the maze.  Another dynamic array tracks if points in the array have been visited already using true and false values (false if not visited, true if visited).  Classes were also used in this code.  This project was made using C++. 
  
  <details>
  <summary>Maze Main File</summary>
  
  ### main.cpp
 ```C++
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
    
```
</details>
    
    
    
<details>
  <summary>Maze Function File</summary>
  
  ### maze.cpp
  ```C++
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



  
```
</details>
  
  
 <details>
  <summary>Maze Header File</summary>
  
  ### maze.h
 ```C++
   #ifndef MAZE_H
#define MAZE_H
//Libraries -----------------------------------------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <utility>
//---------------------------------------------------------------------------------------------------------------------

//maze class ----------------------------------------------------------------------------------------------------------
class maze {
public:
    //define functions (they go in maze.cpp)
    void random_maze(int N, int M, int seed, std::string outPutFile);

    
//private:


};
//---------------------------------------------------------------------------------------------------------------------
#endif //MAZE_H

   
  ```
</details>
 
You can compile this program using the following line:
   ```
   g++ main.cpp maze.cpp -o generator
   ```


## MATLAB Signal Analysis
Analysis of signals and their behaviors when applying fourier transforms, as well as filters.  This assignment tasked us with splitting a 44,100Hz signal into 5 different frequency bands.  The code will ask for the user to input a number 1 through 5, each number cooresponding to a frequency band.  The output will play a part of Beethoven's symphony number 9 at a frequency dependent on the frequency band selected.  The output will also display a graphical representation of the signal being played.
### How to run this code
- Use the file from MATLAB Signal Analysis and open it in MATLAB.  Also download the data set included in the same folder and add it the the same directory as the previous file.  Simply select the green "Run" icon at the top of the screen.
<img src="https://raw.githubusercontent.com/aestrada30/Term-Project/main/AStar.png" height="500" width="700" >






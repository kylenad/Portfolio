# Portfolio:

This is code and various other projects that I completed in college

## C++ Projects
### Image Binarization --
Binarization, otherwise known as thresholding, is the process of taking a grayscale image and converting it into images that are black and white. Grayscale images contain pixels ranging from 0 to 255 in intensity, while black and white images have pixels that are either 0 or 255 in intensity.  There are two different approaches to performing binarization, being global and local binarization.  For global, you need to calculate the median value of all pixels in the image.  If a pixel is less than this threshold value, it is converted to 0 intensity.  If the pixel value is greater than the threshold, it is converted to 255 intensity.  Local binarization focuses on changing pixels based on the pixel intensity values located in smaller "neighborhoods” within the picture.  This assignment was completed using C++.

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


### Maze Generator --









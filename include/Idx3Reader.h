#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#define MAGIC_IDX3_NUMBER 2051

using namespace std;
using namespace cv;

class Idx3Reader{
private:
  int magic;
  int number;
  int rows;
  int cols;
  vector<Mat> data;
public:
  Idx3Reader(string);
  Mat getImage(int);
  int getRows();
  int getCols();
  int getNumber();
};

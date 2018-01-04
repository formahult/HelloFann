#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#define MAGIC_IDX1_NUMBER 2049

using namespace std;

class Idx1Reader{
private:
  int magic;
  int number;
  vector<u_char> data;
public:
  Idx1Reader(string);
  int getLabel(int);
};

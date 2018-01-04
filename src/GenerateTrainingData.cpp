#include "GenerateTrainingData.h"

#define REQUIRED_ARGUMENTS 4
#define BUFSIZE 512

#define MEAN 127
#define RANGE 255

using namespace std;
using namespace cv;

int main(int argc, char const *argv[]) {
  if(argc < REQUIRED_ARGUMENTS){
    printf("Required usage: GenerateTrainingData [label idx1] [image idx3] [output name]\n");
    return -1;
  }

  Idx1Reader labels(argv[1]);
  Idx3Reader images(argv[2]);
  ofstream ofs;
  ofs.open(argv[3], ofstream::out);
  if(!ofs.good()){
    throw runtime_error("Couldn't Open output file\n");
  }

  //header
  ofs << dec << images.getNumber() << " ";
  ofs << (images.getRows()*images.getCols()) << " ";
  ofs << 10 << endl;
  //data
  for(int i = 0; i < images.getNumber(); i++){
    uchar* data = images.getImage(i).data;
    int length = images.getRows()*images.getCols();
    for(int j = 0; j < length; j++){
      ofs << fixed << (double)data[j]/(double)RANGE << " ";
    }
    ofs << endl;
    for(int j = 0; j < 10; j++){
      if(labels.getLabel(i) == j){
        ofs << "1 ";
      } else {
        ofs << "0 ";
      }
    }
    ofs << endl;
  }

  ofs.close();
  return 0;
}

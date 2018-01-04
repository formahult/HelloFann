#include <cstdlib>
#include <stdexcept>
#include <fstream>
#include <stdint.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "Idx1Reader.h"
#include "Idx3Reader.h"
#include <fann.h>

#define REQUIRED_ARGUMENTS 4

#define RANGE 255

using namespace std;
using namespace cv;

int main(int argc, char const *argv[]) {
  if(argc < REQUIRED_ARGUMENTS){
    printf("Required usage: GenerateTrainingData [label idx1] [image idx3] [output name]\n");
    return -1;
  }

  //openCV
  Idx1Reader labels(argv[1]);
  Idx3Reader images(argv[2]);

  //fann
  struct fann *ann = fann_create_from_file(argv[3]);
  //fann_set_activation_function_output(ann, FANN_THRESHOLD);

  int fail = 0;
  int success = 0;

  for(int i = 0; i < 100; i++){

    uchar* data = images.getImage(i).data;


    //uint8_t* datau = (uint8_t*)data;
    int length = images.getRows()*images.getCols();
    float datai[784];
    for(int j = 0; j < length; j++){
      datai[j] = (float)data[j];
      if(datai[j] < 0){
        datai[j]+=1185677396;
      }
      datai[j]/=RANGE;
    }

    // for(int j = 0; j < length; j++){
    //   printf("%f ", datai[j]);
    // }

    fann_type* out = fann_run(ann, datai);


    float best = 0;
    float index = 0;
    for(int j = 0; j < 10; j++){
      // printf("%f ", out[j]);
      if(out[j] > best){
        index = j;
        best = out[j];
      }
    }

    if(labels.getLabel(i) == index){
      success++;
    } else {
      cout << "Output:" << index << endl;
      imshow("Display window", images.getImage(i));
      waitKey(0);
      fail++;
    }
  }
  cout << endl;
  printf("Sucesses: %i\n", success);
  printf("Fails: %i\n", fail);
  fann_destroy(ann);
  return 0;
}

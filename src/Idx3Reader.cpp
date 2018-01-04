#include "Idx3Reader.h"

Idx3Reader::Idx3Reader(string filename){
  ifstream ifs;
  ifs.open(filename, ifstream::in|ifstream::binary);

  if(!ifs.good()){
    throw invalid_argument("Couldn't open file");
  }

  magic = (ifs.get()<<24) + (ifs.get()<<16) + (ifs.get()<<8) + ifs.get();
  if(MAGIC_IDX3_NUMBER!=magic){
    throw runtime_error("Magic number not correct\n");
  }

    number = (ifs.get()<<24) + (ifs.get()<<16) + (ifs.get()<<8) + ifs.get();
    rows = (ifs.get()<<24) + (ifs.get()<<16) + (ifs.get()<<8) + ifs.get();
    cols = (ifs.get()<<24) + (ifs.get()<<16) + (ifs.get()<<8) + ifs.get();

    data.resize(number);
    char* buffer;
    buffer = (char*)malloc(rows*cols);
    for(int i = 0; i < number; i++){
      ifs.read(buffer, rows*cols);
      Mat m(rows, cols, CV_8UC1, buffer);
      data[i] = m.clone();
    }
    ifs.close();
}

Mat Idx3Reader::getImage(int index){
  return data[index];
}
int Idx3Reader::getRows(){
  return rows;
}
int Idx3Reader::getCols(){
  return cols;
}
int Idx3Reader::getNumber(){
  return number;
}

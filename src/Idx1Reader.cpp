#include "Idx1Reader.h"

Idx1Reader::Idx1Reader(string filename){
  ifstream ifs;
  ifs.open(filename, ifstream::in|ifstream::binary);

  if(!ifs.good()){
    throw invalid_argument("Couldn't open file");
  }

  //reverse byte order..
  magic = (ifs.get()<<24) + (ifs.get()<<16) + (ifs.get()<<8) + ifs.get();
  if(MAGIC_IDX1_NUMBER != magic){
    throw runtime_error("Magic number not correct\n");
  }
  number = (ifs.get()<<24) + (ifs.get()<<16) + (ifs.get()<<8) + ifs.get();
  for(int i = 0; i < number; i++){
    data.push_back(ifs.get());
  }
  ifs.close();
}

int Idx1Reader::getLabel(int index){
  return (int)data[index];
}

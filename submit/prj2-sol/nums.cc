#include <iostream>
#include <fstream>
#include <cstring>
#include "seq.hh"
#include "arrayseq.hh"
using TestType = int;

void readInts(std::string fileName, Seq<TestType>& rawPointer){
  TestType i;
  std::ifstream in(fileName);
  if(!in){
    //ERROR
  }
  while(in >> i){
    std::cout << i << std::endl;
    rawPointer.push(i);
  }
  if(!in.eof()){
    //ERROR
  }
}

int main(int argc, char **argv){
  //If not enough arguments
  if(argc < 2){
    std::cout << "usage: ./nums [-a] INTS_FILE_PATH" << std::endl;
    return 0;
  }
  std::string fileName;
  //If the user is using a special command
  if(*argv[1] == '-'){
    //If the special command is not "-a"
    if(strcmp(argv[1], "-a")!=0){
      std::cout << "usage: ./nums [-a] INTS_FILE_PATH" << std::endl;
      return 0;
    }
    fileName = argv[2];
  }else{
    fileName = argv[1];
  }
  Seq<TestType>* rawPointer = ArraySeq<TestType>::make().get();  
  readInts(fileName, *rawPointer);
}

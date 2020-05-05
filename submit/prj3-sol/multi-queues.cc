#include <memory>
#include <string>
#include <istream>
#include <iostream>
#include <vector>
#include <cstdlib>

#include "command.hh"
#include "command-stream.hh"

class PriorityQueue{
private:
  //Vector to Store Heap Elements
  std::vector<Job> A;

  //Return parent of A[i]
  int PARENT(int i){return (i-1)/2;}
  //Return left child of A[i]
  int LEFT(int i){return (2*i+1);}
  //Return right child of A[i]
  int RIGHT(int i){return (2*i+2);}

  void heapify_down(int i){
    int left = LEFT(i);
    int right = RIGHT(i);

    int largest = i;

    if(left < size() && A[left] > A[i])
      largest = left;
    if(right < size() && A[right] > A[largest])
      largest = right;

    if(largest != i) {
      std::swap(A[i], A[largest]);
      heapify_down(largest);
    }
  }

  void heapify_up(int i){
    if(i && A[PARENT(i)] < A[i]){
      std::swap(A[i], A[PARENT(i)]);
      heapify_up(PARENT(i));
    }
  }

public:
  int size(){
    return (int)A.size();
  }
  bool empty(){
    return size() == 0;
  }
  void push(Job key){
    A.push_back(key);
    int index = size() - 1;
    heapify_up(index);
  }
  void pop(){
    try{
      if(size()!=0){
	A[0] = A.back();
	A.pop_back();

	heapify_down(0);
      }
    }catch(const std::out_of_range& oor){
      std::cout << "\n" << oor.what();
    }
  }
  Job top(){
    if(size()!=0)
      return A.at(0);
    else{
      return Job("NULL JOB", -1, -1);
    }
  }
};

int
main(int argc, char* argv[])
{
  if (argc != 2) {
    std::cerr << "usage: " << argv[0] << " FILE_PATH" << std::endl;
    std::exit(1);
  }

  PriorityQueue pq0;
  PriorityQueue pq1;
  
  CommandStream commandIn(argv[1]); //create command stream
  for (std::unique_ptr<Command> commandP = commandIn.next();
       commandP != nullptr;
       commandP = commandIn.next()) {
    Command cmd = *commandP.get();
    if(cmd.toString() == "enter"){
      EnterCommand* enterP = dynamic_cast<EnterCommand*>(commandP.get());
      Job job = enterP->job;
      pq0.push(job);
      std::cout << *commandP << std::endl;
    }else if(cmd.toString() == "move"){
      Job job = pq0.top();
      if(job.id != "NULL JOB"){
        pq0.pop();
        job.inOne = false;
        pq1.push(job);
	std::cout << *commandP << " " << job << std::endl;
      }
    }else if(cmd.toString() == "leave"){
      Job job = pq1.top();
      if(job.id != "NULL JOB"){
        pq1.pop();
	std::cout << *commandP << " " << job << std::endl;
      }
    }
  }
}

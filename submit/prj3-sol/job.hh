#ifndef JOB_HH_
#define JOB_HH_

#include <memory>
#include <string>
#include <iostream>

class Job {
public:
  std::string id;
  int priority0; //higher numbers have priority
  int priority1; //lower numbers have priority
  bool inOne = true;
  Job(std::string id, int priority0, int priority1);
  std::string toString() const;

  /** Return next job read from in.  Returns nullptr on EOF */
  static std::unique_ptr<Job> read(std::istream& in);

  friend std::ostream& operator<<(std::ostream& out, const Job& job);
};
bool operator<(const Job& j1, const Job& j2);
bool operator>(const Job& j1, const Job& j2);
std::ostream& operator<<(std::ostream& out, const Job& job);

#endif //ifndef JOB_HH_

#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>
#include <unordered_map>
#include <algorithm>

typedef int Count;
typedef std::pair<std::string, Count> WordCount;

bool wordCountCompare(WordCount a, WordCount b){
  if(a.second == b.second){
    char aCharArray[a.first.length()+1];
    strcpy(aCharArray,a.first.c_str());
    char bCharArray[b.first.length()+1];
    strcpy(bCharArray,b.first.c_str());

    for(int i = 0; i < (int)a.first.size(); i++){
      if(aCharArray[i] != bCharArray[i])
	return aCharArray[i] < bCharArray[i];
    }
    return true;
  }
  return a.second > b.second;
}

int main(int argc, char *argv[]) {
  auto args = std::vector<std::string>(&argv[0], &argv[argc]);

  if((int) args.size() < 5){
    std::cout << "usage: ./wordcounts MAX_N_OUT MIN_WORD_LEN MAX_WORD_LEN FILE..."
	      << std::endl;
    return 0;
  }

  char cA[args[1].size()+1];
  strcpy(cA,args[1].c_str());
  for(int i = 0; i < (int)args[1].size(); i++){
    if(!isdigit(cA[i])){
      std::cout << "Bad Integer Value '" << args[1] <<"' for MAX_N_OUT" << std::endl;
      return 0;
    }
  }
  char cB[args[2].size()+1];
  strcpy(cB,args[2].c_str());
  for(int i = 0; i < (int)args[2].size(); i++){
    if(!isdigit(cB[i])){
      std::cout << "Bad Integer Value '" << args[2] <<"' for MIN_WORD_LEN" << std::endl;
      return 0;
    }
  }
  char cC[args[3].size()+1];
  strcpy(cC,args[3].c_str());
  for(int i = 0; i < (int)args[3].size(); i++){
    if(!isdigit(cC[i])){
      std::cout << "Bad Integer Value '" << args[3] <<"' for MAX_WORD_LEN" << std::endl;
      return 0;
    }
  }
  
  const int MAX_N_OUT = std::stoi(args[1]);
  const int MIN_WORD_LEN = std::stoi(args[2]);
  const int MAX_WORD_LEN = std::stoi(args[3]);

  std::unordered_map<std::string, Count> map;
  
  if(MAX_WORD_LEN < MIN_WORD_LEN){
    std::cout << "Max Word Length Is Less Than Minimum Word Length!" << std::endl;
    return 0;
  }else if(MAX_N_OUT < 0){
    std::cout << "Max Words Out Is Less Than 0!" << std::endl;
    return 0;
  }

  for(int i = 4; i < (int)args.size();i++){
    std::ifstream in(args[i],std::ifstream::in);
    while(in.good()){
      std::string w;
      in >> w;
      if(w != ""){
	int wordLength = w.length();
	char charArray[wordLength + 1];
	strcpy(charArray, w.c_str());
	std::vector<char> wordChars;
	for(int j = 0; j < wordLength; j++){
	  char c = charArray[j];
	  if(c > 64 && c < 91)
	    c = tolower(c);

	  if(c > 96 && c < 123)
	    wordChars.push_back(c);
	}
	std::string word(wordChars.begin(), wordChars.end());

	if((int)word.length() >=  MIN_WORD_LEN && (int)word.length() <= MAX_WORD_LEN){
	  Count& count = map[word];
	  count += 1;
	}
      }
    }
    if(!in.eof()){
      std::cout << "Cannot read " << args[4] <<": No such file exists!" <<  std::endl;
    }
    in.close();
  }
  auto wordCounts = std::vector<WordCount>(map.begin(),map.end());
  std::sort(wordCounts.begin(), wordCounts.end(), wordCountCompare);

  for(int i = 0; i < MAX_N_OUT; i++){
    if(i > (int) wordCounts.size()-1){
      return 0;
    }
    std::cout << wordCounts[i].first  << ": " << wordCounts[i].second << std::endl;
  }
  
  return 0;
}

#include <iostream>
#include <vector>
#include <fstream>
#include <cstring>

int main(int argc, char *argv[]) {
   auto args = std::vector<std::string>(&argv[0], &argv[argc]);

  const int MAX_N_OUT = std::stoi(args[1]);
  const int MIN_WORD_LEN = std::stoi(args[2]);
  const int MAX_WORD_LEN = std::stoi(args[3]);
  
  if(MAX_WORD_LEN < MIN_WORD_LEN){
    std::cout << "Max Word Length Is Less Than Minimum Word Length!" << std::endl;
    return 0;
  }else if(MAX_N_OUT < 0){
    std::cout << "Max Words Out Is Less Than 0!" << std::endl;
    return 0;
  }

  std::ifstream in(args[4],std::ifstream::in);
  while(in.good()){
    std::string w;
    in >> w;
    int wordLength = w.length();
    char charArray[wordLength + 1];
    strcpy(charArray, w.c_str());
    std::vector<char> wordChars;
    for(int i = 0; i < wordLength; i++){
      char c = charArray[i];
      if(c > 64 && c < 91)
	c = tolower(c);

      if(c > 96 && c < 123)
	wordChars.push_back(c);
    }
    std::string word(wordChars.begin(), wordChars.end());
    std::cout << word << std::endl;
  }
  if(!in.eof()){
    std::cout << "Error Reading File!" << std::endl;
  }
  in.close();

  return 0;
}

#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#include "LLRBBST.h"

//This function writes the tree to a DOT file for visualization, and deletes the tree to prevent data leakage.
void readFile(string inFile) {
  tree Txt;
  ifstream file(inFile);
  string txtFile, word;

  while(getline(file,txtFile)) {
    istringstream ss(txtFile);

    while(ss >> word) {
      for(int i = 0; i < word.length(); i++){
        if(word[i] < 0x5b and word[i] > 0x40){
          word[i] += 0x20;
        }
      }
      cout << word;
      Txt.insertFunc(word);
    }
  }
  Txt.printDOT();
  Txt.~tree();
}

//Main for Input of Txt file
int main(int argc, char** argv) {
  string inFile = argv[2], outFile = argv[3];
  readFile("somebody.txt");

  return 0;
}
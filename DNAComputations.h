//implementation for DNAComputations.h
#include <iostream>

using namespace std;
//header file DNAComputations.h
class DNAComputations{
public:
  DNAComputations(string txt); //constructor
  ~DNAComputations(); //destructor

  int len(); //outputs number of letters
  double mean(); //outputs mean number of letters per line
  double variance(); //outputs the variance
  double deviation(); //outputs the standard deviation
  void singleProbability(); //prints out single letter probability
  void doubleProbability(); //prints out double letter probability
  void kLines(); //prints out 1000 lines
  void printAll(); //is the call that prints out the rest of the methods

  string filetxt;
  string text;
  int lines;
private:
  bool goodFile;

  double AAp;
  double ACp;
  double ATp;
  double AGp;
  double CAp;
  double CCp;
  double CTp;
  double CGp;
  double TAp;
  double TCp;
  double TTp;
  double TGp;
  double GAp;
  double GCp;
  double GTp;
  double GGp;

};

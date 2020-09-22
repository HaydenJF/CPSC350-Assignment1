//implementation for main.cpp
#include "DNAComputations.h"
//main method
//Takes in user input and creates a version of DNAComputations
int main(int argc, char** argv) {
  bool running = true;
  cout << "Hayden Fargo" << endl;
  cout << "ID: 2367276" << endl;
  cout << "C++ Review" << endl;
  string textFile;
  while (running) {
    cout << "Please enter your text file: ";
    cin >> textFile;
    cout << "The file you want us to use is: " << textFile << endl;
    DNAComputations *comps = new DNAComputations(textFile);
    comps->printAll();
    delete comps;


    bool ans = false;
    string answer;
    while (!ans) {
      cout << "Would you like to run again?(Y/N) ";
      cin >> answer;
      if (answer.compare("Y") == 0) {
        ans = true;
        cout << "Ok. Have fun!" << endl;
      } else if (answer.compare("N") == 0) {
        ans = true;
        running = false;
        cout << "Understandable." << endl;
      } else {
        cout << "Please enter either Y or N." << endl;
      }
    }

}
  return 0;
}

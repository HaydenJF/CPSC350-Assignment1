//implementation for DNAComputations.cpp
#include <fstream>
#include <cmath>
#include <time.h>
#include "DNAComputations.h"

#define _USE_MATH_DEFINES

//Constructor needs a string input
DNAComputations::DNAComputations(string txt){
  ifstream file(txt);
  filetxt = txt;
  if (file.is_open()) {
    string tempLine;
    lines = 0;
    while (getline(file, tempLine)) {
      int testA = tempLine.find("A");
      int testC = tempLine.find("C");
      int testT = tempLine.find("T");
      int testG = tempLine.find("G");

      if (testA != string::npos && testC != string::npos && testT != string::npos && testG != string::npos) {
        text += tempLine;
        lines++;
      }
    }
    goodFile = true;
  } else {
    goodFile = false;
  }
  file.close();
}

//Destructor
DNAComputations::~DNAComputations(){

}

//returns the amount of letters
int DNAComputations::len(){
  return (text.length());
}

//returns the mean of the letters per line.
double DNAComputations::mean(){
  return (double(len()) / (double)(lines));
}

//Calculates and returns the variance.
double DNAComputations::variance(){
  double variance = 0;
  ifstream file(filetxt);
  if (file.is_open()) {
    string tempLine;
    while (getline(file, tempLine)) {
      int testA = tempLine.find("A");
      int testC = tempLine.find("C");
      int testT = tempLine.find("T");
      int testG = tempLine.find("G");

      if (testA != string::npos && testC != string::npos && testT != string::npos && testG != string::npos) {
        variance += pow(tempLine.length()-mean(),2.0);
      }
    }
    variance /= lines;
  }
  file.close();


  return variance;
}

//Calculates the power (square root of variance)
double DNAComputations::deviation(){
  return pow(variance(), 0.5);
}

//Prints out the proability of each letter.
void DNAComputations::singleProbability(){
  int A = 0;
  int C = 0;
  int T = 0;
  int G = 0;
  for (int i = 0; i <= text.length(); ++i) {
    string letter = "";
    letter = text[i];
    if (letter.compare("A") == 0) {
      A++;
    } else if (letter.compare("C") == 0) {
      C++;
    } else if (letter.compare("T") == 0) {
      T++;
    } else if (letter.compare("G") == 0) {
      G++;
    }
    letter.clear();
  }
  double Ap = ((double)(A))/((double)(len()));
  cout << "A:           " << Ap << endl;
  double Cp = ((double)(C))/((double)(len()));
  cout << "C:           " << Cp << endl;
  double Tp = ((double)(T))/((double)(len()));
  cout << "T:           " << Tp << endl;
  double Gp = ((double)(G))/((double)(len()));
  cout << "G:           " << Gp << endl;
}

//Prints out the probability of each biogram
void DNAComputations::doubleProbability(){
  int AA = 0;
  int AC = 0;
  int AT = 0;
  int AG = 0;
  int CA = 0;
  int CC = 0;
  int CT = 0;
  int CG = 0;
  int TA = 0;
  int TC = 0;
  int TT = 0;
  int TG = 0;
  int GA = 0;
  int GC = 0;
  int GT = 0;
  int GG = 0;

  for (int i = 0; i <= text.length()-2; i+=2) {
    string letter = "";
    string first(1,text[i]);
    string second(1,text[i+1]);
    letter = first+second;
    if (letter.compare("AA") == 0) {
      AA++;
    } else if (letter.compare("AC") == 0) {
      AC++;
    } else if (letter.compare("AT") == 0) {
      AT++;
    } else if (letter.compare("AG") == 0) {
      AG++;
    } else if (letter.compare("CA") == 0) {
      CA++;
    } else if (letter.compare("CC") == 0) {
      CC++;
    } else if (letter.compare("CT") == 0) {
      CT++;
    } else if (letter.compare("CG") == 0) {
      CG++;
    } else if (letter.compare("TA") == 0) {
      TA++;
    } else if (letter.compare("TC") == 0) {
      TC++;
    } else if (letter.compare("TT") == 0) {
      TT++;
    } else if (letter.compare("TG") == 0) {
      TG++;
    } else if (letter.compare("GA") == 0) {
      GA++;
    } else if (letter.compare("GC") == 0) {
      GC++;
    } else if (letter.compare("GT") == 0) {
      GT++;
    } else if (letter.compare("GG") == 0) {
      GG++;
    }
  }

  AAp = ((double)(AA))/((double)(len()/2));
  cout << "AA:          " << AAp << endl;
  ACp = ((double)(AC))/((double)(len()/2));
  cout << "AC:          " << ACp << endl;
  ATp = ((double)(AT))/((double)(len()/2));
  cout << "AT:          " << ATp << endl;
  AGp = ((double)(AG))/((double)(len()/2));
  cout << "AG:          " << AGp << endl;

  CAp = ((double)(CA))/((double)(len()/2));
  cout << "CA:          " << CAp << endl;
  CCp = ((double)(CC))/((double)(len()/2));
  cout << "CC:          " << CCp << endl;
  CTp = ((double)(CT))/((double)(len()/2));
  cout << "CT:          " << CTp << endl;
  CGp = ((double)(CG))/((double)(len()/2));
  cout << "CG:          " << CGp << endl;

  TAp = ((double)(TA))/((double)(len()/2));
  cout << "TA:          " << TAp << endl;
  TCp = ((double)(TC))/((double)(len()/2));
  cout << "TC:          " << TCp << endl;
  TTp = ((double)(TT))/((double)(len()/2));
  cout << "TT:          " << TTp << endl;
  TGp = ((double)(TG))/((double)(len()/2));
  cout << "TG:          " << TGp << endl;

  GAp = ((double)(GA))/((double)(len()/2));
  cout << "GA:          " << GAp << endl;
  GCp = ((double)(GC))/((double)(len()/2));
  cout << "GC:          " << GCp << endl;
  GTp = ((double)(GT))/((double)(len()/2));
  cout << "GT:          " << GTp << endl;
  GGp = ((double)(GG))/((double)(len()/2));
  cout << "GG:          " << GGp << endl;
}

//Prints out 1000 lines that are similar in mean, probability and standard deviation
void DNAComputations::kLines(){
  srand(time(NULL));

  for (int i = 0; i < 1000; ++i) {
    double a = (double)rand()/RAND_MAX;
    double b = (double)rand()/RAND_MAX;
    double c = pow(-2*log(a), 0.5) * cos(2*M_PI*b);
    double d = deviation()*c + mean();
    int roundD = (int)round(d);

    if (roundD % 2 != 0) {
      if ((double)roundD > d) {
        roundD--;
      } else {
        roundD++;
      }
    }
    for (int i = 0; i < roundD; i+=2) {
      double random = (double)rand()/RAND_MAX;
      if (random < AAp){
        cout << "AA";
      } else if((random < AAp + ACp)) {
        cout << "AC";
      } else if((random < AAp + ACp + ATp)) {
        cout << "AT";
      } else if((random < AAp + ACp + ATp + AGp)) {
        cout << "AG";
      } else if((random < AAp + ACp + ATp + AGp + CAp)) {
        cout << "CA";
      } else if((random < AAp + ACp + ATp + AGp + CAp + CCp)) {
        cout << "CC";
      } else if((random < AAp + ACp + ATp + AGp + CAp + CCp + CTp)) {
        cout << "CT";
      } else if((random < AAp + ACp + ATp + AGp + CAp + CCp + CTp + CGp)) {
        cout << "CG";
      } else if((random < AAp + ACp + ATp + AGp + CAp + CCp + CTp + CGp + TAp)) {
        cout << "TA";
      } else if((random < AAp + ACp + ATp + AGp + CAp + CCp + CTp + CGp + TAp + TCp)) {
        cout << "TC";
      } else if((random < AAp + ACp + ATp + AGp + CAp + CCp + CTp + CGp + TAp + TCp + TTp)) {
        cout << "TT";
      } else if((random < AAp + ACp + ATp + AGp + CAp + CCp + CTp + CGp + TAp + TCp + TTp + TGp)) {
        cout << "TG";
      } else if((random < AAp + ACp + ATp + AGp + CAp + CCp + CTp + CGp + TAp + TCp + TTp + TGp + GAp)) {
        cout << "GA";
      } else if((random < AAp + ACp + ATp + AGp + CAp + CCp + CTp + CGp + TAp + TCp + TTp + TGp + GAp + GCp)) {
        cout << "GC";
      } else if((random < AAp + ACp + ATp + AGp + CAp + CCp + CTp + CGp + TAp + TCp + TTp + TGp + GAp + GCp + GTp)) {
        cout << "GT";
      } else {
        cout << "GG";
      }
    }
    cout << endl;
  }


}

//Calls all of the above methods
void DNAComputations::printAll(){
  if (goodFile) {
    cout << "The Sum of the length of the DNA strings is: " << len() << endl;
    cout << "The Mean of the length of the DNA strings is " << mean() << endl;
    cout << "The variance of the length of the DNA strings is: " << variance() << endl;
    cout << "The Standard Deviation of the length of the DNA stings is: "  << deviation() << endl;
    cout << "Here is the relative probability of each nucleotide:" << endl;
    singleProbability();
    cout << "Here is the relative probability of each nucleotide bigram:" << endl;
    doubleProbability();
    bool ans = false;
    string answer;
    while (!ans) {
      cout << "Do you want 1000 lines of DNA strings similar to the file?(Y/N) ";
      cin >> answer;
      if (answer.compare("Y") == 0) {
        ans = true;
        cout << "Here are 1000 lines of DNA strings similar to the file:" << endl;
        kLines();
      } else if (answer.compare("N") == 0) {
        ans = true;
        cout << "Understandable." << endl;
      } else {
        cout << "Please enter either Y or N." << endl;
      }
    }
  } else {
    cout <<  "Sorry. You did not enter a proper file." << endl;
  }



}

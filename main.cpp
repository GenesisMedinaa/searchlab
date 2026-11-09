#include <iostream>
using namespace std;

#include "src/CountWords.hpp"

int main() {
  CountWords test;
   string filename;

  cout << "Enter the filename: ";
  cin >> filename;

  if (test.fileinside(filename)) {
    cout << "File processed successfully." << endl;
  } else {
    cout << "Failed to open the file." << endl;
  }

  test.diskprint("output.txt");
  

 
    return 0;
}

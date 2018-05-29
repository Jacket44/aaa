#include <iostream>
#include <string>

#include "RzymArab.h"

using namespace std;

int main (int argc, char* argv[]) {
  int n = 0; 

  for (int i=1; i<argc; i++) {
    try {
      n = stoi(argv[i]);
      cout << RzymArab::arab2rzym(n) << endl;
    }
    catch (invalid_argument ia) {
      try {
        cout << RzymArab::rzym2arab(argv[i]) << endl;
      }
      catch (string s) {
        cout << s << endl;
      }
    }
    catch (string s) {
      cout << s << endl;
    }
  }

  return 0;
}

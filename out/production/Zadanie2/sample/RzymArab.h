#include <iostream>
#include <string>

using namespace std;

class RzymArab {
  private:
    static string liczbyrzym[];

    static int liczbyarab[];

    static const int wielkosctablic = 12;//długość obu tablic

  public:
    static string arab2rzym (int arab);
    static int rzym2arab (string string);
};

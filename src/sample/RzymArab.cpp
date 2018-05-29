#include "RzymArab.h"

string RzymArab::liczbyrzym[] = {
  "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"
};

int RzymArab::liczbyarab[] = {
  1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000
};

string RzymArab::arab2rzym (int arab) {

  if (arab > 3999 || arab <= 0) {
    throw (string) "liczba nie moze zostac przekonwertowana";
  }


  string wynik = "";

  for (int i=wielkosctablic; i>=0;) {
    if (arab >= liczbyarab[i]) {
      wynik += liczbyrzym[i];
      arab -= liczbyarab[i];
    }
    else {
      i--;
    }
  }

  return wynik;
}

int RzymArab::rzym2arab (string rzym) {
  int wynik = 0; // initalize the wynik
  string rzymkopia = rzym;

  for (int i=wielkosctablic; i>=0;) {
    if (rzym.find(liczbyrzym[i]) == 0) {
      wynik += liczbyarab[i];
      rzym = rzym.substr(liczbyrzym[i].length(), rzym.length());
    }
    else {
      i--;
    }
  }

  try {
    if (!rzym.empty() || rzymkopia != arab2rzym(wynik)) {
      throw (string) "niepoprawny format";
    }
  }
  catch (string s) {
    throw (string) "niepoprawny format";
  }

  return wynik;
}

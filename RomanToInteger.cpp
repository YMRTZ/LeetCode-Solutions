#include <iostream>


std::string removeOne(std::string s) {
  return s.substr(1, s.size() - 1);
  
}

std::string removeTwo(std::string s) {
  if(s.size() == 2) {
    return "";
  }
  return s.substr(2, s.size() - 1);
}


int main() {
  std::string s = "III";




  int value = 0;
  while(s.size() > 1) {
    switch(s[0]) {
      case 'I':
        switch(s[1]) {
          case 'V':
            value += 4;
            s = removeTwo(s);
            break;
          case 'X':
            value += 9;
            s = removeTwo(s);
            break;
          default:
            value += 1;
            s = removeOne(s);
            break;
        }
        break;
      case 'V':
        value += 5;
        s = removeOne(s);
        break;
      case 'X':
        switch(s[1]) {
          case 'L':
            value += 40;
            s = removeTwo(s);
            break;
          case 'C':
            value += 90;
            s = removeTwo(s);
            break;
          default:
            value += 10;
            s = removeOne(s);
            break;
        }
        break;
      case 'L':
        value += 50;
        s = removeOne(s);
        break;
      case 'C':
        switch(s[1]) {
          case 'D':
            value += 400;
            s = removeTwo(s);
            break;
          case 'M':
            value += 900;
            s = removeTwo(s);
            break;
          default:
            value += 100;
            s = removeOne(s);
            break;
        }
        break;
      case 'D':
        value += 500;
        s = removeOne(s);
        break;
      case 'M':
        value += 1000;
        s = removeOne(s);
        break;
    }
  }
  if(s.size() > 0) {
    switch(s[0]) {
      case 'I':
        value += 1;
        break;
      case 'V':
        value += 5;
        break;
      case 'X':
        value += 10;
        break;
      case 'L':
        value += 50;
        break;
      case 'C':
        value += 100;
        break;
      case 'D':
        value += 500;
        break;
      case 'M':
        value += 1000;
        break;
    }
  }

  return 0;
}
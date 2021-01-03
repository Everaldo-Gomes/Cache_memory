#include <bits/stdc++.h>
#include <bitset>
#include "function.h"
using namespace std;

int main() {
  
  int choice = 0;
  bool exit = false;
  Function obj; 

  while(!exit) {
    
    cin >> choice;

    switch (choice) {	
    case 1:
      obj.read_content_main_memory();
      break;
	
    case 2:
      obj.write_content_main_memory();
      break;
	
    case 3:
      obj.statistic();
      break;
	
    case 4:
      exit = true;
      break;

    default:
      obj.menu();
    }
  }
  
  return 0;
}

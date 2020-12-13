#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <bits/stdc++.h>
using namespace std;

// just declarations

class Function {

 private:
  
 public:
  
  //instances
  const int main_memory_cell = 128;
  const int cache_memory_row = 8;

  int hit_read = 0;
  int miss_read = 0;
  double average_read = 0.0;

  int hit_write = 0;
  int miss_write = 0;
  double average_write = 0.0;

  
  
  vector<vector<pair<bitset<8>, bitset<8>>>> main_memory;
  //vector<bitset<8>> main_memory;

  //methods
  Function(); // constructor
  void info_students();
  void clean_screen();
  void menu();

  void main_memory_initializer();
  void cache_memory_initializer();
};


#endif

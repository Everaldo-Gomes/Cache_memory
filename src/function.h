#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <bits/stdc++.h>
using namespace std;

// just declarations

class Function {

 private:
  //instances
  
  const int main_memory_cell = 128;
  const int cache_memory_row = 8;
  const int cache_memory_column = 8;
  const int tag_column = 1;

  int hit_read = 0;
  int miss_read = 0;
  double average_read = 0.0;

  int hit_write = 0;
  int miss_write = 0;
  double average_write = 0.0;
  
  int hit_miss_read = 0;
  int hit_miiss_write = 0;
  double average_hit_miss_write = 0.0;

  int cache_memory_lfu = 0;
  
  vector<vector<pair<bitset<8>, bitset<8>>>> main_memory;
  vector<vector<bitset<8>>> cache_memory;
  
  //methods
  bool search_tag_cache_memory(bitset<8>);
  
 public:
  
  //instances
  
  
  //methods
  Function(); // constructor
  void info_students();
  void clean_screen();
  void menu();

  void main_memory_initializer();
  void cache_memory_initializer();
  void read_content_main_memory();
  
};


#endif

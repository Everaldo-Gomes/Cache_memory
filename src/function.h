#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <bits/stdc++.h>
using namespace std;

// just declarations

#define bit_qnt 7
#define bit_identify_block 5

class Function {

 private:
  //instances
  
  const int main_memory_cell = 128;
  const int cache_memory_row = 8;
  const int cache_memory_column = 8;
  const int valid_bit_column = 0;
  const int tag_column = 1;
  const int dirty_bit_column = 2;
  const int data1_column = 3;
  const int data2_column = 4;
  const int data3_column = 5;
  const int data4_column = 6;
  const int count_column = 7;

  int hit_read = 0;
  int miss_read = 0;
  double average_read = 0.0;

  int hit_write = 0;
  int miss_write = 0;
  double average_write = 0.0;
  
  int hit_miss_read = 0;
  int hit_miiss_write = 0;
  double average_hit_miss_write = 0.0;

  vector<vector<pair<bitset<7>, bitset<7>>>> main_memory;
  vector<vector<bitset<7>>> cache_memory;
  
  //methods
  bool cache_memory_search_tag(bitset<7>);
  bool cache_memory_check_valid_bit_0();
  void update_info();
  
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

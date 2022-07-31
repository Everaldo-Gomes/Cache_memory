#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <bits/stdc++.h>
using namespace std;

#define bit_identify_block 5

class Function {


  
  const int valid_bit_column = 0;
  const int tag_column = 1;
  const int dirty_bit_column = 2;
  const int data_column = 3; // 3 - 6
  const int count_column = 7;
  
  double hit_read = 0;
  double miss_read = 0;
  double average_read = 0.0;

  double hit_write = 0;
  double miss_write = 0;
  double average_write = 0.0;
  
  int hit_miss_read = 0;
  int hit_miss_write = 0;
  double average_hit_miss_write = 0.0;

  int cache_memory_tag_line = -1;
  
  
  
  //methods
  
  bool cache_memory_search_tag(bitset<bit_qnt>);
  int  cache_memory_check_valid_bit_0();
  bool cache_memory_check_dirty_bit_0(int);
  void cache_memory_find_tag_0();
  int  get_displacement(bitset<bit_qnt>);
  void cache_memory_increment_lfu(int);
  int  cache_memory_get_minimum_counter();
  bitset<bit_qnt> main_memory_get_value(bitset<bit_qnt>);
  void main_memory_set_value(bitset<bit_qnt>, bitset<bit_qnt>);
  int  get_block_number(bitset<bit_qnt>);
  int  find_beginning_block(bitset<bit_qnt>, int);
  void copy_block_to_cache(int, int);
  void show_info(bitset<bit_qnt>, int, int, int, bool);
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
  void write_content_main_memory();
  void statistic();
};


#endif

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <bits/stdc++.h>
using namespace std;


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
  const int data_column = 3; // 3 - 6
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

  int cache_memory_tag_line = -1;
  
  vector<vector<pair<bitset<bit_qnt>, bitset<bit_qnt>>>> main_memory;
  vector<vector<bitset<bit_qnt>>> cache_memory;
  
  
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
  
};


#endif




/* trash:


   
   
   //set value in the specific memory address
  
   for(int i = 0; i < main_memory.size(); i++) {
   for(auto [data, address] : main_memory[i]) {
   if(address == typed_address) {
   main_memory[i].back().first = typed_data;
   main_memory[i].back().second = address; //overwrite address 
   }
   }
   }


      //check if the displacement is avaiable, just put the data
    //    bitset<bit_qnt> zero(0);
 
    //if(cache_memory[cache_memory_tag_line][data_column+displacement] == zero) {

   //}
    /*
    //there is some data in the same displacement, need to write-back
    else {

      // write without saving in the main memory
      if(cache_memory[cache_memory_tag_line][dirty_bit_column] == zero) {
	cache_memory[cache_memory_tag_line][data_column+displacement] = typed_data;
	      
	show_info(typed_data, cache_memory_tag_line+1, displacement, current_block, false);
      }

      //save all lines in the main memory [write back]
      else {
	
	//get block number/beginning
	int beginning = find_beginning_block(typed_address);
	
	//coopy all data to there
	
	//save new data in cache
	//set lfu 1
      }
     
    } 

*/

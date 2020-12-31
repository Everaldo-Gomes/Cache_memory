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

  int cache_memory_tag_line = 0;
  
  vector<vector<pair<bitset<bit_qnt>, bitset<bit_qnt>>>> main_memory;
  vector<vector<bitset<bit_qnt>>> cache_memory;
  
  
  //methods
  
  bool cache_memory_search_tag(bitset<bit_qnt>);
  int  cache_memory_check_valid_bit_0();
  bool cache_memory_check_dirty_bit_0(int);
  int  get_displacement(bitset<bit_qnt>);
  void cache_memory_increment_lfu(int);
  int  cache_memory_get_maximum_counter();
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


   cout << "\n\n\t Valor: " << value << "\n"
   << "\t Valor nao estava na cache\n"
   << "\t Nº do bloco: " << current_block << "\n\n"
   << "\t Pressione [-Enter-] para continuar\n\n";


   //set dirty-bit
   //cannot change to 1 when read 
   //cache_memory[free_row_index][dirty_bit_column] = set_bit;
      

      //show some info
      // cout << "\n\n\t Valor: " << value << "\n"
      // 	   << "\t Valor não estava na cache\n"
      // 	   << "\t Nº do quadro: " << cache_memory_tag_line << "\n"
      // 	   << "\t Deslocamento: " << displacement << "\n"
      // 	   << "\t Nº do bloco: " << current_block << "\n\n"
      // 	   << "\t Pressione [-Enter-] para continuar.\n\n";

*/

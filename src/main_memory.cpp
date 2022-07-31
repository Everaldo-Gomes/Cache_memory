#include <bits/stdc++.h>
#include <bitset>
#include "function.h"
using namespace std;


int Function :: get_block_number(bitset<bit_qnt> address) {

	
  bitset<bit_identify_block> ab;
      
  for(int i = bit_qnt; i >= 2; i--) {
    ab[i] = address[i];
  }

  ab >>= 2;  //fix the first number that wasnt caugth"
   
  return (int)(ab.to_ulong());  //convert binary to int
}


int Function :: find_beginning_block(bitset<bit_qnt>, int current_block) {

  unsigned int i = 0;
  bool stop = false;
  
  for(; i < main_memory.size(); i++) {
    for(auto [data, address] : main_memory[i]) {
      if(current_block == get_block_number(address)) {
	stop = true;
	break;
      } 
    }
    if(stop) { break; }
  }
  return i;
}


bitset<bit_qnt> Function :: main_memory_get_value(bitset<bit_qnt> typed_address) {

  bitset<bit_qnt> value;
  bool stop = false;
  
  for(unsigned int i = 0; i < main_memory.size(); i++) {
    for(auto [data, address] : main_memory[i]) {
      if(address == typed_address) {
	value = data;
	stop = true;
	break;
      }
    }
    if(stop) { break; }
  }
  return value;
}






void Function :: write_content_main_memory() { //option 2

  bitset<bit_qnt> typed_address, typed_data, set_bit(1);
  
  cout << "\n\t Enter the address: ";
  cin >> typed_address;

  cout << "\t Enter the value:   ";
  cin >> typed_data;

  
  bool tag_found = cache_memory_search_tag(typed_address);
  int free_row_index = cache_memory_check_valid_bit_0();
  int displacement = get_displacement(typed_address);
  int current_block = get_block_number(typed_address);

    
  //there is not data in the cache, and valid bit is 0
  if((cache_memory_tag_line == -1 && free_row_index >= 0)) {

    miss_write++;
    
    //set valid bit
    cache_memory[free_row_index][valid_bit_column] = set_bit;

    //set tag
    cache_memory[free_row_index][tag_column] = typed_address;

    //set dirty-bit
    cache_memory[free_row_index][dirty_bit_column] = set_bit;

    //set value
    cache_memory[free_row_index][data_column+displacement] = typed_data;

    //increment count LFU
    cache_memory_increment_lfu(free_row_index);
    
    show_info(typed_data, cache_memory_tag_line+1, displacement, current_block, false);
  }

  //put new data in another place
  else if(!tag_found) {
    
    cache_memory_find_tag_0(); //search for an available tag

    miss_write++;

    //set valid bit
    cache_memory[free_row_index][valid_bit_column] = set_bit;

    //set tag
    cache_memory[free_row_index][tag_column] = typed_address;

    //set dirty-bit
    cache_memory[free_row_index][dirty_bit_column] = set_bit;
    
    //set value
    cache_memory[free_row_index][data_column+displacement] = typed_data;

    //increment count LFU
    cache_memory_increment_lfu(free_row_index);

    show_info(typed_data, cache_memory_tag_line+1, displacement, current_block, false);
  }

  //if foundtag and displacement is the same or different
  else if(tag_found) {

    hit_write++;
     
    cache_memory[cache_memory_tag_line][data_column+displacement] = typed_data;

    //increment count LFU
    cache_memory_increment_lfu(cache_memory_tag_line);
    
    show_info(typed_data, cache_memory_tag_line+1, displacement, current_block, false);
  }
  
  update_info();      
}

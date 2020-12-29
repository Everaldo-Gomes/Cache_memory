#include <bits/stdc++.h>
#include <bitset>
#include "function.h"
using namespace std;

void Function :: main_memory_initializer() {

  cout <<"\t\t\t Main Memory\n\n"
       <<"\t\t   Value \t Address\n\n";

  main_memory.resize(main_memory_cell);
  int block_counter = 0, block_qnt = 0;
  
  for(int i = 0; i < main_memory_cell; i++) {
    
    if(block_counter == 2) {   
      cout << "\033[1;36mBlock " << block_qnt << "\033[0m\b\b\b\b\b";
    }

    int aux_rand = rand() % 10000000;      // random values int
    int aux_address = i;                   // memory address int
    bitset<bit_qnt> binary_value(aux_rand);      // randon values binary
    bitset<bit_qnt> binary_address(aux_address); // memory address binary
    
    main_memory[i].push_back({binary_value, binary_address}); // save values

    cout << "\t\t\033[1;32m|---------|\n" << "\t\t|\033[0m " ;
    
    cout << binary_value << "\033[1;32m |\033[0m\t" << binary_address; // show the values
    
    if(block_counter == 3) {
      cout << "\n\t\t\033[1;32m|---------|\033[0m\n\n";
      block_counter = 0;
      block_qnt++;
    }
    else {
      cout << "\n";
      block_counter++;
    }
  } 
}



int Function :: get_block_number(bitset<bit_qnt> address) {
  
  bitset<bit_identify_block> ab;
      
  for(int i = bit_qnt; i >= 2; i--) {
    ab[i] = address[i];
  }

  ab >>= 2;  //fix the first number that wasnt caugth"
   
  return (int)(ab.to_ulong());  //convert binary to int
}


int Function :: find_beginning_block(bitset<bit_qnt>, int current_block) {

  int i = 0;
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


void Function :: read_content_main_memory() { //option 1

  cout << "\t Enter the address ";

  bitset<bit_qnt> typed_address;
  cin >> typed_address;
  
  //first, search for it in the cache memory
  bool tag_found = cache_memory_search_tag(typed_address);

  if(tag_found) { //the block is in the cache, read value...
      
  }
  else { //copy all block to the cache memory
  
    int free_row_index = cache_memory_check_valid_bit_0();
    
    //if cache is full
    if(free_row_index == -1) {
      // i dont know how to do yet...
      
    }
    else { //there is at least one free row in the cache

      //set valid bit
      int set_bit_int = 1;
      bitset<bit_qnt> set_bit(set_bit_int);
      cache_memory[free_row_index][valid_bit_column] = set_bit;
      
      //set tag
      cache_memory[free_row_index][tag_column] = typed_address;

      //set dirty-bit
      cache_memory[free_row_index][dirty_bit_column] = set_bit;


      //copying values to cache memory
      int current_block = get_block_number(typed_address);
      int index = find_beginning_block(typed_address, current_block);
      copy_block_to_cache(free_row_index, index);
      
      //increment count LFU
      int aux_int;
      aux_int = (int)(cache_memory[free_row_index][count_column].to_ulong()); //convert binary to int
      aux_int += 1; 
      bitset<bit_qnt> aux(aux_int);  //convert the new value to binary
      cache_memory[free_row_index][count_column] = aux; //save the value

      update_info();
    }   
  }
}

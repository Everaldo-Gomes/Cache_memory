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


void Function :: read_content_main_memory() { //option 1

  cout << "\t Enter the address ";
  
  bitset<bit_qnt> typed_address;
  cin >> typed_address;
  
  bool tag_found = cache_memory_search_tag(typed_address);
  int current_block = get_block_number(typed_address);
  int index = find_beginning_block(typed_address, current_block);

  
  //first, search for it in the cache memory
  
  if(tag_found) { //the block is in the cache, read value...
    
    int displacement = cache_memory_get_displacement(typed_address);
      
    hit_read += 1; 

    //get the value in the cache memrory
    bitset<bit_qnt> value(cache_memory[cache_memory_tag_line][data_column+displacement]);

    //increment counter LFU
    cache_memory_increment_lfu(cache_memory_tag_line); 

    //show some info
    cout << "\n\n\t Valor: " << value << "\n"
	 << "\t Está na cache\n"
	 << "\t Nº do quadro: " << cache_memory_tag_line << "\n"
	 << "\t Deslocamento: " << displacement << "\n"
     	 << "\t Nº do bloco: " << current_block << "\n\n"
     	 << "\t Pressione [-Enter-] para continuar.\n\n";
    
      getchar();getchar();
      update_info();
  }
  else { //copy all block to the cache memory
  
    int free_row_index = cache_memory_check_valid_bit_0();
    
    
    //if cache is full
    
    if(free_row_index == -1) {
      
      //DOING...
      // need to replace some data in the cache
      
      cout << "Cache is full \n\n";
      
    }
    else { //there is at least one free row in the cache

      miss_read++;

      //set valid bit
      int set_bit_int = 1;
      bitset<bit_qnt> set_bit(set_bit_int);
      cache_memory[free_row_index][valid_bit_column] = set_bit;
      
      //set tag
      cache_memory[free_row_index][tag_column] = typed_address;

      //set dirty-bit
      cache_memory[free_row_index][dirty_bit_column] = set_bit;

      //copying values to cache memory
      copy_block_to_cache(free_row_index, index);
      
      //increment count LFU
      cache_memory_increment_lfu(free_row_index); 

      //getting the value
      bitset<bit_qnt> value = main_memory_get_value(typed_address);
      
      //show some info
      cout << "\n\n\t Valor: " << value << "\n"
	   << "\t Valor nao esta na cache\n"
	   << "\t Nº do bloco: " << current_block << "\n\n"
	   << "\t Pressione [-Enter-] para continuar\n\n";
      
      getchar();getchar();
      update_info();      
    }   
  }
}

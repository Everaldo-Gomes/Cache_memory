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


void Function :: main_memory_set_value(bitset<bit_qnt> new_address, bitset<bit_qnt> new_value) {
  
  bool stop = false;
  
  for(unsigned int i = 0; i < main_memory.size(); i++) {
    for(auto [data, address] : main_memory[i]) {
      if(address == new_address) {
	data = new_value;
	stop = true;
	break;
      }
    }
    if(stop) { break; }
  }
}


void Function :: read_content_main_memory() { //option 1

  cout << "\t Enter the address ";
  
  bitset<bit_qnt> typed_address;
  cin >> typed_address;
  
  bool tag_found = cache_memory_search_tag(typed_address);
  int current_block = get_block_number(typed_address);
  int index = find_beginning_block(typed_address, current_block);
  int displacement = get_displacement(typed_address);
  bitset<bit_qnt> set_bit(1);

  
  //first, search for it in the cache memory
  
  if(tag_found) { //the block is in the cache, read value...
          
    hit_read += 1; 

    //get the value in the cache memrory
    bitset<bit_qnt> value(cache_memory[cache_memory_tag_line][data_column+displacement]);

    //increment counter LFU
    cache_memory_increment_lfu(cache_memory_tag_line); 

    show_info(value, cache_memory_tag_line, displacement, current_block, true);
    update_info();
  }

  //copy all block in the cache memory
  else { 

    miss_read++;
    int free_row_index = cache_memory_check_valid_bit_0();


    
    if(free_row_index == -1) {  //if cache is full,  replace data using LFU policy


      //get maximum counter's line
      int line = cache_memory_get_maximum_counter();
      
      //get value
      bitset<bit_qnt> value(cache_memory[line][data_column+displacement]);
      
      //check dirty bit
      bool dirty_bit = cache_memory_check_dirty_bit_0(line);

      //overrite all data without saving ( dirty bit = 0 )
      if(dirty_bit) { 

	//set tag
	cache_memory[line][tag_column] = typed_address;

	//copy the new block
	copy_block_to_cache(line, index);

	//set count LFU = 1
	cache_memory[line][count_column] = set_bit;   

	show_info(value, cache_memory_tag_line, displacement, current_block, true);	
      }

      
      /*
	+++++++++++  IMPORTANT ++++++++++

	the else below needs to be tested when finish the option 2
      */
      
      //save the data in the main memory before change it ( dirty bit = 1)
      else {
	
	//get some random place in the main memory 0 - 127
	bitset<bit_qnt> place(rand() % 127);

	//save the value
	main_memory_set_value(place, value);
	cout << place << " <- " << endl;

	//do the same thing as the if above
      }
      
      update_info();
    }

    //there is at least one free row in the cache
    else {

      miss_read++;

      //set valid bit
      cache_memory[free_row_index][valid_bit_column] = set_bit;
      
      //set tag
      cache_memory[free_row_index][tag_column] = typed_address;

      //copying values to cache memory
      copy_block_to_cache(free_row_index, index);
      
      //increment count LFU
      cache_memory_increment_lfu(free_row_index); 

      //getting the value
      bitset<bit_qnt> value = main_memory_get_value(typed_address);
      
      show_info(value, cache_memory_tag_line, displacement, current_block, false);
      update_info();
    }   
  }
}

//DOING...
void Function :: write_content_main_memory() { //option 2

  bitset<bit_qnt> typed_address, typed_data;
  
  
  cout << "\t Enter the address ";
  cin >> typed_address;

  cout << "\t Enter the value ";
  cin >> typed_data;

  //nned to write in the cache first 
  get_block_number(typed_address) << endl;
  get_displacement(typed_address) << endl;


  //set value in the specific memory address
  for(int i = 0; i < main_memory.size(); i++) {
    for(auto [data, address] : main_memory[i]) {
      if(address == typed_address) {
	data = typed_data;
      }
    }
  }
  
  getchar();  getchar();
  update_info();      
}

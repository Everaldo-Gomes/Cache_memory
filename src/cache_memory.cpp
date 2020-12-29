#include <bits/stdc++.h>
#include <bitset>
#include "function.h"
using namespace std;


void Function :: cache_memory_initializer() {
  
  cout <<"\t\t\t\t\t\t  Cache Memory\n\n"
       << "   Valid-bit \t   Tag  \t\b\b\bDirty-bit \t Data1  \t Data2  \t Data3  \t Data4 \t\t\bCount [LFU]\n\n";
 
  cache_memory.resize(cache_memory_row, vector<bitset<bit_qnt>>(cache_memory_column,0));

  cout << "\033[1;32m   |--------------------------------------------------------------------------------------------------------------|\033[0m\n";
  
  for(int i = 0; i < cache_memory_row; i++) {
    cout << "   \033[1;32m|\b\b\b\033[0m";
    
    for(int j = 0; j < cache_memory_column; j++) {
      bitset<bit_qnt> aa(0);
      cache_memory[i][j] = aa;
	
      if(j == 0 || j == 2) { //valid, dirty bit
	bitset<1> bb(0);
	cout << "\t" << bb;
      }
      else { // tag, data, counter (LFU)
	cout << "\t " << aa;
      }      
    }
    cout << "\033[1;32m  |\n\033[1;32m   |--------------------------------------------------------------------------------------------------------------|\033[0m\n";
  }
  cout << "\n\n\n";
}



bool Function :: cache_memory_search_tag(bitset<bit_qnt> typed_address) {
  
  bool found = false;
  int count_bit_hit = 0;

  //fetch a tag to compare
  for(int i = 0; i < cache_memory_row; i++) {

    if(cache_memory[i][valid_bit_column] == 1) { //exist some data in this row
    
      bitset<bit_qnt> fetched_tag(cache_memory[i][tag_column]);

      //compare the fethed tag
      for(int j = 0; i < 6; i++) {	
	if(fetched_tag[j] != typed_address[j]) {
	  count_bit_hit = 0;
	  break;
	}
	else { count_bit_hit++; }
      }

      if(count_bit_hit == 6) { //all bits matches, so the block is in the cache
	found = true;
	break;
      }
    }
  }
  return found;
}


bool Function :: cache_memory_check_valid_bit_0() {

  int found_valid_bit_0_index = -1;

  for(int i = 0; i < cache_memory_row; i++) {
    if(cache_memory[i][valid_bit_column] == 0) {
      found_valid_bit_0_index = i;
      break;
    }
  }

  return found_valid_bit_0_index;
}


void Function :: copy_block_to_cache(int free_row_index, int index) {

  //index + 3, because need to run through 4 cells
  int data_index = data_column;
  
  for(int i = index; i <= index+3; i++, data_index++) {
    for(auto [data, address] : main_memory[i]) {
      cache_memory[free_row_index][data_index] = data;
    }
  } 
}

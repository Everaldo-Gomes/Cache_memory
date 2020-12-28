#include <bits/stdc++.h>
#include <bitset>
#include "function.h"
using namespace std;

// just implementations


// constructor
Function :: Function() {
  
  clean_screen();
  info_students();
  cache_memory_initializer();
  main_memory_initializer();
  menu();  
}

void Function :: clean_screen() {
  system("clear");
}

void Function :: info_students() {
  
  cout << " Everaldo Gomes\n"
       << " Felipe Boschetti\n\n\n\n\n";
}


void Function :: menu() {
  
  cout << "\t 1- Ler conteúdo de um endereco de memoria\n"
       << "\t 2- Escreve conteúdo em um endereco de memoria\n"
       << "\t 3- Estatisticas de acertos e erros\n"
       << "\t 4- Encerrar programa\n\n\n"

       << "\t Digite a opção: ";
}


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
    bitset<7> binary_value(aux_rand);      // randon values binary
    bitset<7> binary_address(aux_address); // memory address binary
    
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


void Function :: cache_memory_initializer() {
  
  cout <<"\t\t\t\t\t\t  Cache Memory\n\n"
       << "   Valid-bit \t   Tag  \t\b\b\bDirty-bit \t Data1  \t Data2  \t Data3  \t Data4 \t\t\bCount [LFU]\n\n";
 
  cache_memory.resize(cache_memory_row, vector<bitset<7>>(cache_memory_column,0));

  cout << "\033[1;32m   |--------------------------------------------------------------------------------------------------------------|\033[0m\n";
  
  for(int i = 0; i < cache_memory_row; i++) {
    cout << "   \033[1;32m|\b\b\b\033[0m";
    
    for(int j = 0; j < cache_memory_column; j++) {
      bitset<7> aa(0);
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


void Function :: update_info() {
  
  clean_screen();
  info_students();

  //cache memory
  cout <<"\t\t\t\t\t\t  Cache Memory\n\n"
       << "   Valid-bit \t   Tag  \t\b\b\bDirty-bit \t Data1  \t Data2  \t Data3  \t Data4 \t\t\bCount [LFU]\n\n";

  cout << "\033[1;32m   |--------------------------------------------------------------------------------------------------------------|\033[0m\n";
  
  for(int i = 0; i < cache_memory_row; i++) {
    cout << "   \033[1;32m|\b\b\b\033[0m";
    
    for(int j = 0; j < cache_memory_column; j++) {	

      if(j == 0 || j == 2) { //valid, dirty bit
	bitset<7> aux(cache_memory[i][j]);
	cout << "\t" << aux[0];
      }
      else { // tag, data, counter (LFU)
	cout << "\t " << cache_memory[i][j];
      }      
    }
    cout << "\033[1;32m  |\n\033[1;32m   |--------------------------------------------------------------------------------------------------------------|\033[0m\n";
  }
  cout << "\n\n\n";


  //main memory
  cout <<"\t\t\t Main Memory\n\n"
       <<"\t\t   Value \t Address\n\n";

  int block_counter = 0, block_qnt = 0;
  
  for(int i = 0; i < main_memory_cell; i++) {
    
    if(block_counter == 2) {   
      cout << "\033[1;36mBlock " << block_qnt << "\033[0m\b\b\b\b\b";
    }
    
    cout << "\t\t\033[1;32m|---------|\n" << "\t\t|\033[0m ";

    for(auto [data, address] : main_memory[i]) {
      cout << data << "\033[1;32m |\033[0m\t" << address; // show the values
    }
    
    
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

  menu();
}

bool Function :: cache_memory_search_tag(bitset<7> typed_address) {
  
  bool found = false;
  int count_bit_hit = 0;

  //fetch a tag to compare
  for(int i = 0; i < cache_memory_row; i++) {

    if(cache_memory[i][valid_bit_column] == 1) { //exist some data in this row
    
      bitset<7> fetched_tag(cache_memory[i][tag_column]);

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


void Function :: read_content_main_memory() { //option 1

  cout << "\t Enter the address ";

  bitset<7> typed_address;
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
      bitset<7> set_bit(set_bit_int);
      cache_memory[free_row_index][valid_bit_column] = set_bit;
      
      //set tag
      cache_memory[free_row_index][tag_column] = typed_address;

      //set dirty-bit
      cache_memory[free_row_index][dirty_bit_column] = set_bit;
      
      
      //set data1
      //      std::stoi()
      
      //set data2
      //set data3
      //set data4
      
      //increment count LFU
      //cache_memory[free_row_index][count_column] += set_bit;
      // bitset<7> a(1);
      // bitset<7> b(2);
      // bitset<7> c(a+b);
      // cout << c << endl;
      
      update_info();
    }   
  }
}

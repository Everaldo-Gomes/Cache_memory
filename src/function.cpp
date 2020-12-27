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
    bitset<8> binary_value(aux_rand);      // randon values binary
    bitset<8> binary_address(aux_address); // memory address binary
    
    main_memory[i].push_back({binary_value, binary_address}); // save values

    cout << "\t\t\033[1;32m|----------|\n" << "\t\t|\033[0m " ;
    
    cout << binary_value << "\033[1;32m |\033[0m\t" << binary_address; // show the values
    
    if(block_counter == 3) {
      cout << "\n\t\t\033[1;32m|----------|\033[0m\n\n";
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
       << "   Valid-bit \t   Tag \t\t\b\b\bDirty-bit \t Data1  \t Data2  \t Data3  \t Data4 \t\t\bCount [LFU]\n\n";
 
  cache_memory.resize(cache_memory_row, vector<bitset<8>>(cache_memory_column,0));

  cout << "\033[1;32m   |--------------------------------------------------------------------------------------------------------------|\033[0m\n";
  
  for(int i = 0; i < cache_memory_row; i++) {
    cout << "   \033[1;32m|\b\b\b\033[0m";
    
    for(int j = 0; j < cache_memory_column; j++) {
      bitset<8> aa(0);
      cache_memory[i][j] = aa;
	
      if(j == 0 || j == 2) { //valid, dirty bit
	bitset<1> bb(0);
	cout << "\t" << bb;
      }
      else if(j == 1) { //tag
	bitset<5> bb(0);
	cout << "\t   " << bb << "\t\b\b\b";
      }
      else { //data, counter (LFU)
	cout << "\t" << aa;
      }      
    }
    cout << "\033[1;32m  |\n\033[1;32m   |--------------------------------------------------------------------------------------------------------------|\033[0m\n";
  }
  cout << "\n\n\n";
}


bool Function :: search_tag_cache_memory(bitset<8> tag) {
  
  bool found = false;

  for(int i = 0; i < cache_memory_row; i++) {    
    
  }
  
  return found;
}

void Function :: read_content_main_memory() { //option 1
  
    cout << "\t Enter the address ";
    
    bitset<8> typed_address;
    cin >> typed_address;

    //first, search for it in the cache memory
    search_tag_cache_memory(typed_address);
    
    

    
    //search for the data using the typed address in the main memory
    // for(int i = 0; i < main_memory.size(); i++) {
    //   for(auto [data, address] : main_memory[i]) {
    // 	if(address == typed_address) {
    // 	  cout << data << "<--";
    // 	}
    //   }
    // }

}

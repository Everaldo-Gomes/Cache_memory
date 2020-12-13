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

  cout <<"\t\t\t  MAIN MEMORY\n\n"
       <<"\t\t Cell \t\t\b\b\b\bValue \tAddress\n\n";

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

    cout << "\t\t\033[1;32m|------------------|\n"
	 << "\t\t|\033[0m " << i << " --- ";
    
    if(i < 10) { cout << "  "; }                 //just some black spaces
    else if(i >= 10 && i < 100) { cout << " "; } //just some black spaces
    
    cout << binary_value << "\033[1;32m |\033[0m\t" << binary_address; // show the values
    
    if(block_counter == 3) {
      cout << "\n\t\t\033[1;32m|------------------|\033[0m\n\n";
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

  cout <<"\t\t\t  CACHE MEMORY\n\n";
  

  
}


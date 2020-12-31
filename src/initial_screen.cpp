#include <bits/stdc++.h>
#include <bitset>
#include "function.h"
using namespace std;

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
	bitset<bit_qnt> aux(cache_memory[i][j]);
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


void Function :: show_info(bitset<bit_qnt> value, int tag_line, int d, int block, bool in_cache) {

  bitset<bit_qnt> cache_memory_tag_line(tag_line);
  bitset<bit_qnt> displacement(d);
  bitset<bit_qnt> current_block(block);

  string cache_no  = " Valor não estava na cache\n";
  string cache_yes = " Valor estava na cache\n";
  string result;

  if(in_cache) { result = cache_yes; }
  else { result = cache_no; }

  
  //show some info
      cout << "\n\n\t Valor: " << value << "\n"
	   << "\t" << result
	   << "\t Nº do quadro: " << cache_memory_tag_line << " [ " << tag_line << " ]\n"
	   << "\t Deslocamento: " << displacement << " [ " << d << " ]\n"
	   << "\t Nº do bloco:  " << current_block << " [ " << block << " ]\n\n"
	   << "\t Pressione [-Enter-] para continuar.\n\n";

      getchar(); getchar();
}

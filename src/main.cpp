#include <bitset>
//#include <stdlib.h>
//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//#include <sys/types.h>
#include <bits/stdc++.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ 27

int main ()
{
	const short int bit_qnt = 7;

	int shmid, *chosen_option;
	std::bitset<bit_qnt> *typed_info;
	key_t key = 0001; // identifier of the shared memory segment

	// create the segment.     
	if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0)
	{
		std::cout << "Error creating the segment shmget" << std::endl;
		return -1;
	}

	// attach the segment to the data space.
	if ((typed_info = (std::bitset<bit_qnt>*)shmat(shmid, NULL, 0)) == (std::bitset<bit_qnt>*) -1 ||
		(chosen_option = (int*)shmat(shmid, NULL, 0)) == (int*) -1)
	{
		std::cout << "Error attaching the segment shmat" << std::endl;
		return -1;
	}	

	int choice = 0;
	bool exit = false;
	std::bitset<bit_qnt> typed_address;
	
	while(!exit)
	{
		system("clear");
		
		std::cout << "Everaldo Gomes \t\t\t"
				  << "RAM & Cache Memory\n\n\n\n"
				  << "\t 1- Read from a memory address\n"
				  << "\t 2- Write in a memory address\n"
				  << "\t 3- Estatistics\n"
				  << "\t 4- Quit\n\n\n"
				  << "\t Your choice: ";
		
		std::cin >> choice;
		
		switch (choice)
		{
		case 1:
			std::cout << "\t Enter the address (" << bit_qnt << " digits): ";
			std::cin >> typed_address;
		    *typed_info = typed_address;
			*chosen_option = 1;
			break;

		case 2:			
			*chosen_option = 2;
			break;
	 /*			
		case 3:
			//obj.statistic();
			break;
	
		case 4:
			exit = true;
			shmctl(shmid, IPC_RMID, NULL); // remove shared segment
			shmdt(typed_info);             // detach shared memory from the program
			break;

		default:
			std::cout << "\n";
			//obj.menu(); */
		} 
	}
  
	return 0;
}



/*


#define bit_identify_block 5

  double hit_read = 0;
  double miss_read = 0;
  double average_read = 0.0;

  double hit_write = 0;
  double miss_write = 0;
  double average_write = 0.0;
  
  int hit_miss_read = 0;
  int hit_miss_write = 0;
  double average_hit_miss_write = 0.0;





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


void Function :: statistic() {

  double hit_read_ratio = hit_read / (hit_read + miss_read);
  double miss_read_ratio = miss_read / (hit_read + miss_read);
  average_read = hit_read_ratio / miss_read_ratio * 100;

  double hit_write_ratio = hit_write / (hit_write + miss_write);
  double miss_write_ratio = miss_write / (hit_write + miss_write);
  average_write = hit_write_ratio / miss_write_ratio * 100;

  hit_miss_read = hit_read + hit_write;
  hit_miss_write = miss_read + miss_write;
  average_hit_miss_write = ((average_write + average_read) / 2) / 100;
  
  //read
  cout << "\n\tRead: \n"
       << "\t\tHit: " << hit_read << "\n"
       << "\t\tMiss: " << miss_read << "\n"
       << fixed << setprecision(2)
       << "\t\tAverage: " << average_read << "%\n\n"
  
  //write
       << "\tWrite: \n"
       << fixed << setprecision(0)
       << "\t\tHit: " << hit_write << "\n"
       << "\t\tMiss: " << miss_write << "\n"
       << fixed << setprecision(2)
       << "\t\tAverage: " << average_write << "%\n\n"

  //general
       << "\tGeneral: \n"
       << fixed << setprecision(0)
       << "\t\tHit: " << hit_miss_read << "\n"
       << "\t\tMiss: " <<  hit_miss_write << "\n"
       << fixed << setprecision(2)
       << "\t\tAverage: " << average_hit_miss_write << "%\n\n";

  cout << "\t Pressione [-Enter-] para continuar.\n\n";

  getchar();getchar();
  update_info();
}


*/

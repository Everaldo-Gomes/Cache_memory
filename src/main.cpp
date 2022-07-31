//#include <bits/stdc++.h>
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

	int shmid;
	key_t key = 5678; // identifier of the shared memory segment
	std::bitset<bit_qnt> *typed_info;

	// create the segment.     
	if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0)
	{
		std::cout << "Error creating the segment shmget" << std::endl;
		return -1;
	}

	// attach the segment to the data space.
	if ((typed_info = (std::bitset<bit_qnt>*)shmat(shmid, NULL, 0)) == (std::bitset<bit_qnt>*) -1)
	{
		std::cout << "Error attaching the segment shmat" << std::endl;
		return -1;
	}

	int choice = 0;
	bool exit = false;
	
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
			std::bitset<bit_qnt> typed_address;
			std::cin >> typed_address;
		    *typed_info = typed_address;
				
			//obj.read_content_main_memory();
			break; /*
		case 2:
			//obj.write_content_main_memory();
			break;
	
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

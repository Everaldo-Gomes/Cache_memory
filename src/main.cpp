#include <bits/stdc++.h>
#include <bitset>

//#include <stdlib.h>
//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMSZ 27

int main ()
{
	std::cout << "Everaldo Gomes \t\t\t"
			  << "RAM & Cache Memory\n\n\n\n"
	
			  << "\t 1- Read from a memory address\n"
			  << "\t 2- Write in a memory address\n"
			  << "\t 3- Estatistics\n"
			  << "\t 4- Quit\n\n\n"

			  << "\t Your choice: ";

	int choice = 0;
	bool exit = false; 

	while(!exit)
	{   
		std::cin >> choice;

		switch (choice)
		{	
		case 1:

			char c;
			int shmid;
			char *shm, *s;

			//We'll name our shared memory segment "5678"
			key_t key = 5678;
    
			//Create the segment.     
			if ((shmid = shmget(key, SHMSZ, IPC_CREAT | 0666)) < 0) {
				perror("shmget");
			}

			//Now we attach the segment to our data space.
			if ((shm = (char*)shmat(shmid, NULL, 0)) == (char *) -1) {
				perror("shmat");
			}

			//Now put some things into the memory for the other process to read.
			s = shm;

			for (c = 'a'; c <= 'z'; c++) {
				*s++ = 'A';
			}
			*s = 'A';

			//*s = NULL;
			//obj.read_content_main_memory();
			
			break;
			/*
		case 2:
			//obj.write_content_main_memory();
			break;
	
		case 3:
			//obj.statistic();
			break;
	
		case 4:
			exit = true;
			break;

		default:
			std::cout << "\n";
			//obj.menu(); */
		} 
	}
  
	return 0;
}

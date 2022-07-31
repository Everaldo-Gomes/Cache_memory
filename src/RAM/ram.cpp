#include <bits/stdc++.h>
#include <bitset>

//#include <stdlib.h>
//#include <stdio.h>
//#include <stdbool.h>
//#include <string.h>
//#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "ram_func.h"

#define SHMSZ 27

int main ()
{
	const short int bit_qnt = 7;
	int shmid;
	key_t key = 5678;
	std::bitset<bit_qnt> *typed_info;

	if ((shmid = shmget(key, SHMSZ, 0666)) < 0)
	{
		std::cout << "Error creating the segment shmget" << std::endl;
		return -1;
	}

	if ((typed_info = (std::bitset<bit_qnt>*)shmat(shmid, NULL, 0)) == (std::bitset<bit_qnt>*) -1)
	{
		std::cout << "Error attaching the segment shmat" << std::endl;
		return -1;
	}

	RAM ram_memory;	
	ram_memory.init();
	
	while (1)
	{
		
		
	}
  
	return 0;
}

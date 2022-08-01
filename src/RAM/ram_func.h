#pragma once

#include <sys/ipc.h>
#include <sys/shm.h>
#include <bits/stdc++.h>
#include <bitset>

#define SHMSZ 27

class RAM
{

private:
  
	static const short int bit_qnt = 7;
	const short int ram_cell = 128;

	int shmid;
	key_t key = 0001;
	std::bitset<bit_qnt> *typed_info;
	bool *cache_tag_found;
	

public:

	int *chosen_option;
	std::vector<std::vector<std::pair<std::bitset<bit_qnt>, std::bitset<bit_qnt>>>> ram;
	
	RAM();
	void info_header();
	void update_info();
	void init();
	void read_content_ram();
	void set_value(std::bitset<bit_qnt> new_address, std::bitset<bit_qnt> new_value);
};

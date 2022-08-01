#pragma once

#include <bits/stdc++.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <bitset>

#define SHMSZ 27

class Cache
{

private:
	
	static const short int bit_qnt = 7;
	const short int row_qnt = 8;
	const short int column_qnt = 8;
	const short int valid_bit_column = 0;
	const short int tag_column = 1;
	const short int dirty_bit_column = 2;
	const short int data_column = 3; // start from the forth column
	const short int count_column = 7;
	short int tag_line = -1;

	
public:

	std::vector<std::vector<std::bitset<bit_qnt>>> cache_memory;
	
	Cache();
	void info_header();
	void init();
	void search_tag(std::bitset<bit_qnt> typed_address);
};

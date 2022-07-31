#pragma once

#include <iostream>
#include <bits/stdc++.h>
#include <bitset>


class RAM
{

private:
  
	static const short int bit_qnt = 7;
	const short int ram_memory_cell = 128;
	

public:

	std::vector<std::vector<std::pair<std::bitset<bit_qnt>, std::bitset<bit_qnt>>>> ram_memory;
	
	RAM();
	void info_header();
	void update_info();
	void init();
	void set_value(std::bitset<bit_qnt> new_address, std::bitset<bit_qnt> new_value);
};



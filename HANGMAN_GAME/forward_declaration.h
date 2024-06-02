#pragma once
#include "random.h"
#include "game_storage.h"
#include "random_words.h"

//namespace Random
namespace Random
{
	inline std::mt19937 generate();
}

class Storage;
void clearfunction();
char get_input();
std::string_view print_random_word(const Word::List& word);
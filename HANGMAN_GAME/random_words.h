#pragma once
#include <iostream>
#include <cassert>
#include <string>
#include <string_view>
#include <string.h>
#include <random>
#include <vector>
#include <array>
#include <limits>
#include "random.h"
#include "forward_declaration.h"
#include "game_storage.h"


namespace Word
{
	enum List
	{
		mystery,
		brocolli,
		account,
		almost,
		spaghetti,
		opinion,
		beautiful,
		distance,
		luggage,
	};

	
}
std::string_view print_random_word(const Word::List& word)
{
	switch (word)
	{
	case 0:
		return "mystery";
	case 1:
		return "brocolli";
	case 2:
		return "account";
	case 3:
		return "almost";
	case 4:
		return "spaghetti";
	case 5:
		return "opinion";
	case 6:
		return "beautiful";
	case 7:
		return "distance";
	case 8:
		return "luggage";
	default:
		return "????";
	}
}


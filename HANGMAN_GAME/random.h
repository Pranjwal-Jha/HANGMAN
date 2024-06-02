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
#include "forward_declaration.h"
#include "game_storage.h"
#include "random_words.h"


namespace Random
{
	inline std::mt19937 generate()
	{
		std::random_device rd{};
		std::seed_seq ss{ rd(),rd(), rd(), rd(), rd(), rd(), rd(), rd() };
		return std::mt19937{ ss };
	}

	inline std::mt19937 mt{ generate() };

}
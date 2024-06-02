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
#include "random_words.h"

class Storage
{
private:
	std::string_view m_random_word{};
	std::vector<char> m_user_input{};
	int m_user_lives{};
public:

	std::vector<char> m_user_guesses{};

	void print() const
	{
		std::cout << "Random word : " << m_random_word << " User Input " << m_user_input[m_user_input.size()-1] << " User lives " << m_user_lives << '\n';
	}

	void set_random_word(const std::string_view& random_word)
	{
		m_random_word = random_word;
	}

	std::string_view get_random_word() const
	{
		return m_random_word;
	}

	void set_user_input(char userinput) 
	{
		m_user_input.push_back(userinput);
	}

	char get_user_input() const
	{
		return m_user_input[m_user_input.size()-1];
	}

	void set_user_lives(int user_lives)
	{
		m_user_lives = user_lives;
	}
	
	int get_user_lives() const
	{
		return m_user_lives;
	}

	void set_user_guess(char guess)
	{
		m_user_guesses.push_back(guess);
	}

	char get_user_guess() const
	{
		return m_user_guesses[m_user_guesses.size() - 1];
	}
};
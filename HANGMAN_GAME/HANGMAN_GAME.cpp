#include <iostream>
#include <cassert>
#include <string>
#include <string_view>
#include <string.h>
#include <random>
#include <vector>
#include <array>
#include <limits>
#include <cctype>
#include "forward_declaration.h"
#include "random.h"
#include "game_storage.h"
#include "random_words.h"

void clearfunction()
{
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	
}

char get_input()
{
	char user_input{};
	do {
		std::cout << "Enter your next letter: ";
		std::cin >> user_input;
		if (std::cin.fail())
		{
			std::cin.clear();
			clearfunction();
		}
		else
			clearfunction();
		if (std::isalpha(user_input))
			break;
		else
			std::cout << "That wasn't a valid input.  Try again." << '\n';
	} while (!std::isalpha(user_input));
	return user_input;
}

void draw(const std::string_view& s, const std::vector<char> user_guess)
{
	std::cout << '\n';

	std::cout << "The word: ";
	for ([[maybe_unused]] auto c : s)
	{
		bool or_not{ false };
		for (char guess : user_guess)
		{
			if (c == guess)
			{
				std::cout << c;
				or_not = true;
			}
		}
		if (!or_not) {
			std::cout << '_';
		}
	}

	std::cout << '\t';

}

int main()
{
	Storage user{};
	std::cout << "Welcome to C++man (a variant of Hangman)" << '\n' << "To win : guess the word.To lose : run out of pluses." << '\n';

	std::uniform_int_distribution word_count{ 0,8 };
	int random_integer{ word_count(Random::mt) };
	std::string_view random_word{ print_random_word(static_cast<Word::List>(random_integer)) };
	user.set_random_word(random_word);
	//std::string_view random_word{ print_random_word(random_integer) };
	//user.set_random_word(random_word);


	//draw(random_word);
	user.set_user_lives(6);

	while (user.get_user_lives() > 0)
	{
		bool bool1{ false };
		for (char c : user.get_random_word())
		{
			for (char b : user.m_user_guesses)
			{
				if (c == b)
					bool1 = true;
				else
					bool1 = false;
			}
			
		}
		if (bool1) {
			std::cout << "Congratulations ! You have successfully guessed the word" << '\n' << '\n';
			std::exit(0);
		}
		draw(random_word,user.m_user_guesses);
	tryagain:
		for (int i{ 1 }; i <= user.get_user_lives()-1; i++) {
			std::cout << "+";
		}
		std::cout << '\n';


		char user_input{ get_input() };
		for (char c : user.m_user_guesses)
		{
			if (c == user_input) {
				std::cout << "You already guessed that.  Try again." << '\n';
				goto tryagain;
			}
		}
		//std::cout << "you've entered : " << user_input << '\n';
		user.set_user_input(user_input);
		user.set_user_guess(user_input);


		bool found{ false };
		for (char c : user.get_random_word())
		{
			//found = false;
			if (c == user.get_user_input())
			{
				found = true;
				break;
			}
			
		}
		if (!found) {
			user.set_user_lives(user.get_user_lives() - 1);
			std::cout << "No, " << "'" << user.get_user_input() << "'" << " is not in the word!" << '\n';
		   // user.print();      //checking statement 
			continue;
		}
		std::cout << "Yes " << "'" << user.get_user_input() << "'" << " is in the word!" << '\n';
		//user.print();          // checking statement
	}

	return 0;

}
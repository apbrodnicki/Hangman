/* This C++ program is a demonstration of the classic game Hangman!
   Follow the prompts on screen and continue 
   playing for as long as you'd like.
   
   -Alex Brodnicki*/  

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

//declaring function
int fillWord (char, string, string&);

int main()
{
  //variables for the answer to the game, the user's guess, and the number of guesses attempted
  const int ATTEMPTS = 6;
  int guesses = 0;
	string word, unknown = "";
	char letter;
	
  //a string array of the potential answers to the game
	string cities[] =
    {
      "chicago",
      "pasadena",
      "washington",
      "springfield",
      "seattle",
      "boston",
      "miami",
      "austin",
      "houston",
      "syracuse"
    };

	//taking one word from the cities array and copying it to word variable as the answer to the game
	srand(time(NULL));
	int n = rand()% 10;
	word = cities[n];
    
	//initialize the answer with the * character
	for (int i = 0; i < word.length(); i++)
  {
    unknown.append("*");
  }

	//explaining the game
	cout << "\nWelcome to Hangman! Here are the rules:";
	cout << "\n\n\tEach letter is represented by a star.";
	cout << "\n\n\tYou guess the word one letter at a time.";
	cout << "\n\n\tYou have " << ATTEMPTS << " attempts to try and guess the word until you lost.";
  cout << "\n\n\tThe word you will be guessing is an American city.";
  cout << "\n\n\tBuff up on your topical geography!";
  cout << "\n\n\t(everything will be in lowercase)";
	cout << "\n\n------------------------------------------------------------------";
    
	//looping until the user runs out of guesses
	while (guesses < ATTEMPTS)
	{
		cout << "\n\nWord: " << unknown;
		cout << "\n\nGuess a letter: "; 
		cin >> letter;

		//fill the answer word with a letter if the guess is correct,
		//otherwise increment the number of wrong guesses
		if (fillWord(letter, word, unknown) == 0)
		{
			cout << "\nUnfortunately for you, that letter isn't in this word.\n";
			guesses++;
		}
		else
		{
			cout << "\nYou got one!\n";
		}

		//tell user how many guesses are left
		cout << "You have " << ATTEMPTS - guesses << " guesses left.\n";

		//check if user guessed the word correctly
		if (word == unknown)
		{
			cout << word;
			cout << "\n\nWell done! If you would like to play again simply rerun the program.";
			break;
		}
	}

  //losing message
	if (guesses == ATTEMPTS)
	{
		cout << "\nNot everyone can be a geographical genius, maybe next time!\n";
		cout << "The word was: " << word << endl;
	}

	cin.ignore();
	cin.get();
	return 0;
}

/*take guess and word and fill in the unfinished astWord
  returns number of characters matched
  returns zero if the character is already guessed*/

int fillWord (char guess, string word, string &astWord)
{
	int matches = 0;

	for (int i = 0; i < word.length(); i++)
	{
		//if the letter has already been guessed
		if (guess == astWord[i])
			return 0;
		//if the letter was guessed correctly
		if (guess == word[i])
		{
			astWord[i] = guess;
			matches++;  
		}
	}
	return matches;
}
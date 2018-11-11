#include "pch.h"
#include "FBullCowGame.h"
#include <string>
#include <iostream>
#include <map>
#define TMap std::map


void FBullCowGame::Reset()
{
	constexpr int MAX_TRIES = 8;
	MyCurrentTries = 1;
	MyMaxTries = MAX_TRIES;
	const FString MyHiddenWord = "grade";
	HiddenWord = MyHiddenWord;
	bgamewon = false;
	return;
}

EWordStatus FBullCowGame::CheckGuessValid(std::string guess)
{
	if (guess.length() > HiddenWord.length())
	{
		return EWordStatus::TOO_LONG;
	}
	else if (guess.length() < HiddenWord.length())
	{
		return EWordStatus::TOO_SHORT;
	}
	else
	{
		// Correct length Now check

		// Check if isogram
		// If it isn't all lower case  --> make code that lowercases everything?
		int32 i = 0;
		for (i = 0; i < GetHiddenWordLength(); i++)
		{
			if (isupper(guess[i]))
			{
				// Means it is uppercase
				// TODO automatically convert to lower so it isnt case sensitive
				return EWordStatus::Not_Lowercase;
			}
			else
		if (!IsIsogram(guess))
		{
			return EWordStatus::NOT_ISOGRAM;
		}
		}
	}
	return EWordStatus::OK; // TODO Make Actual Error
}

// Receives a Valid Guess and Increments turn, and return count
FBullCowCount FBullCowGame::SubmitGuess(FString guess)
{
	int32 i = 0;
	int32 j = 0;
	int32 HiddenWord_Length;
	FBullCowCount bullcowcount;

	MyCurrentTries++;
	HiddenWord_Length = HiddenWord.length();

	for (i = 0; i < HiddenWord_Length; i++)
	{
		for (j = 0; j < HiddenWord_Length; j++)
		{
			if (guess[i] == HiddenWord[j])
			{
				if (i == j)
				{
					bullcowcount.Bulls++;
				}
				else
				{
					bullcowcount.Cows++;
				}
			}
		}
	}
	if (bullcowcount.Bulls == HiddenWord.length())
	{
		bgamewon = true;
	}
	else
	{
		bgamewon = false;
	}
	return bullcowcount;
}

void FBullCowGame::SummarizeGame(bool wantstoplayagain)
{
	FString changewords = "";
	if (bgamewon)
	{
		if (wantstoplayagain)
		{
			std::cout << "Do you want to change words(y/n)";
			std::getline(std::cin, changewords);
			// TODO Add function to change words
		}
		else
		{
			std::cout << "Goodbye" << std::endl;
		}
	}
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	TMap<char, bool> LetterSeen;
	
	if (HiddenWord.length() <= 1)
	{
		return true;
	}
	else
	{
		for (auto letter : Word) // for all letters of the word
		{
			letter = tolower(letter); // change to lowercase
			if (LetterSeen[letter])
			{
				return false;
			}
			else
			{
				LetterSeen[letter] = true;
			}
		}
	}
	return true;
}



FBullCowGame::FBullCowGame()
{
	Reset();
}


int32 FBullCowGame::GetHiddenWordLength() const
{
	return HiddenWord.length();
}
	
int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthtoTries{ {3,4} , {4,7} , {5,10} , {6,15},{7,20} };
	return WordLengthtoTries[HiddenWord.length()];
}

int32 FBullCowGame::GetCurrentTries() const
{
	return MyCurrentTries;
}

bool FBullCowGame::isGameWon() const
{
	return bgamewon;
}




/*
std::size_t pos = HiddenWord.find(guess[i]);
if (pos == std::string::npos)
{
	// Do nothing means not isogram
}
else
{
	{
		if (pos != i)
		{
			std::cout << "Not Isogram " << guess[i] << std::endl;
			return EWordStatus::NOT_ISOGRAM;
		}
	}

}
*/
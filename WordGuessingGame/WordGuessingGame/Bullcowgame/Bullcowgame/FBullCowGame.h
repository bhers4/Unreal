#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EWordStatus
{
	INVALID,
	OK,
	NOT_ISOGRAM,
	TOO_SHORT,
	TOO_LONG,
	Not_Lowercase
};

class FBullCowGame
{
public:
	FBullCowGame(); // Constructor
	int32 GetMaxTries() const;
	int32 GetCurrentTries() const;
	bool isGameWon() const;
	int32 GetHiddenWordLength() const;

	void Reset();
	EWordStatus CheckGuessValid(std::string);
	FBullCowCount SubmitGuess(FString guess);
	void SummarizeGame(bool);

private:
	// see constructor for initialization
	int32 MyCurrentTries;
	int32 MyMaxTries;
	FString HiddenWord;
	bool bgamewon;

	bool IsIsogram(FString) const;
};
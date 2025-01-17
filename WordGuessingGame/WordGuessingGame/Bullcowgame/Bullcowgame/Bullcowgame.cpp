// Bullcowgame.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include "pch.h"
#include <iostream>
#include <string>
#include "FBullCowGame.h"
#pragma once


// To make syntax equivalent to Unreal Engine Coding Standards
using FText = std::string;
using int32 = int;

/* Namespace */

/* Function Prototypes */
void print_intro();
void PlayGame();
FText Getguess();
bool Asktoplayagain();
FBullCowGame BCGame; // New game
void printsummary();

int main()
{
	PlayGame();
	return 0;
}

void PlayGame()
{
	// Variable Declaration
	int32 i = 0;
	FText get_guess = "";
	bool playagain = true;
	FBullCowCount bullsandcows;

	BCGame.Reset();
	// Game
	do
	{
		print_intro();
		// TODO change to while loop
		while(!BCGame.isGameWon() && BCGame.GetCurrentTries()<=BCGame.GetMaxTries())
		{
			get_guess = Getguess(); // TODO check for valid guesses
			// Submit Valid guess and receive counts
			bullsandcows = BCGame.SubmitGuess(get_guess);
			std::cout << "Bulls= " << bullsandcows.Bulls << std::endl;
			std::cout << "Cows = " << bullsandcows.Cows << std::endl;
			
		}
		printsummary();
		playagain = Asktoplayagain();
		BCGame.SummarizeGame(playagain);
		BCGame.Reset();
	} while (playagain);
	// Get x number of guesses
	
}

// Prints Intro Message
void print_intro()
{
	std::cout << "Welcome to Bulls and Cows, A fun word game" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of" << std::endl;
	return;
}

// Gets Guess and Returns it as a string -> Also prints
FText Getguess()
{
	EWordStatus guess_validity = EWordStatus::INVALID;
	FText Guess = "";
	do
	{
		int32 currenttry = BCGame.GetCurrentTries();
		std::cout << "Try " << currenttry << "/" << BCGame.GetMaxTries() << " Enter Guess: ";
		
		std::getline(std::cin, Guess);


		guess_validity = BCGame.CheckGuessValid(Guess);
		switch (guess_validity)
		{
		case (EWordStatus::OK):
			return Guess;
		case (EWordStatus::NOT_ISOGRAM):
			std::cout << "Not an Isogram" << std::endl;
			break;
		case (EWordStatus::Not_Lowercase):
			std::cout << "Please Enter Lowercase only" << std::endl;
			break;
		case (EWordStatus::TOO_LONG):
			std::cout << "Too long of a words, Enter " << BCGame.GetHiddenWordLength() << " Letter Word" << std::endl;
			break;
		case EWordStatus::TOO_SHORT:
			std::cout << "Too Short, Enter " << BCGame.GetHiddenWordLength() << " Letter Word" << std::endl;
			break;
		default:
			return Guess;
		}
	} while (guess_validity != EWordStatus::OK);
	return Guess;
}

bool Asktoplayagain()
{
	FText Response = "";
	std::cout << "Do you want to play again(y/n): ";
	std::getline(std::cin, Response);
	return (Response[0] == 'y' || Response[0] == 'Y');
}

void printsummary()
{
	if (BCGame.isGameWon())
	{
		std::cout << "YOU WON" << std::endl;
	}
	else
	{
		std::cout << "YOU LOST" << std::endl;
	}
}

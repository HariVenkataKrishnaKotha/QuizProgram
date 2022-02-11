#pragma once
//Include the libraries and Definitions required for the program
#include <iostream>
#include <fstream>
#include <vector>
#define NOMINMAX //Had to define to avoid the program to check the Min/Max from Windows.h
#include <Windows.h>
#include <String>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

//Global Variable included in the program
int Number_of_Que;
int Test_Que;
string File_path;
ifstream file1;
int cnt = 0;
int answer = 0;
int correct = 0;
int original = 0;
int vect_size = 0;
int option_no = 0;
string line;
vector<int> vect;
bool check = false;
float perc;

/// <summary>
/// Checks the number of Questions available in the Question File and verifies the user given input,
/// Restricts the invalid inputs from the user
/// </summary>
/// <param name="Que_No"></param>
/// <returns>Integer value of number of Questions to be asked in the quiz</returns>
int Check_Que(int Que_No);


/// <summary>
/// The method is responsible to display the quiz question and the options available for the user
/// Records the input given by the user and validates if it's right or wrong!
/// Records the number of correct answers till the time
/// </summary>
/// <param name="file"></param>
/// <param name="line"></param>
/// <param name="answer"></param>
/// <param name="original"></param>
/// <param name="correct"></param>
/// <param name="check"></param>
/// <returns>Integer value for the number of correct answers till time</returns>
int Start_the_quiz(istream& file, string line, int answer, int original, int correct, bool check);


/// <summary>
/// Take the input from the user and validates the question file and the number of questions to be asked!
/// </summary>
/// <returns>A boolean value deciding whether to proceed or if there's an issue to be reported to the user</returns>
bool Quiz_param();


/// <summary>
/// The method is reponsible to identify the question phrase and trigger Start_the_quiz to display the question and options
/// The question to be asked is selected based on the vector that's been shuffled for randomness
/// </summary>
/// <param name="file"></param>
void Proceed_Quiz(istream& file);


/// <summary>
/// The methos is responsible to display the stats for the user. 
/// Such as the total number of questions attempted, the number of correct answers
/// The total percentage of the correct answers
/// The total elapsed time for the quiz
/// </summary>
void results();


/// <summary>
/// Responsible to shuffle the vector that has line numbers for the questions in the file
/// Swaps the index for the elements for the required randomness
/// </summary>
/// <param name="file"></param>
void shuff(ifstream& file);

/// <summary>
/// The main methos is the intial driving method that triggers the remaining methods
/// </summary>
int main();

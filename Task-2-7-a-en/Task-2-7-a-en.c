// Task-2-7-a-en.c : This file contains the 'main' function. 
// Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int main(int argc, char* args[])
{
	char a[80]; // string for the current code
	char b[80]; // string for the target code
	int total_moves = 0; // Move counter
	// Reading input data
	printf("Enter the current code: ");
	fgets(a, 80, stdin); // Input the current code
	printf("Enter the target code: ");
	fgets(b, 80, stdin); // Input the target code
	int n_len1 = strlen(a); // Calculate the length of the first string
	int n_len2 = strlen(b); // Calculate the length of the second string
	// Check if the lengths of the current and target codes match
	// If the length of the current code does not equal the length of the target code,
	// or if either code is not four digits long, the program terminates.
	if ((n_len1 != 4) || (n_len2 != 4) || (n_len1 != n_len2))
	{
		printf("The combination for the code lock must be 4 digits long.\r\n");
		printf("The current code and the target code must be of the same length.\r\n");
		// Pause output until the "Enter" key is pressed
		getc(stdin);
		exit(0);
	}
	// Calculate the minimum number of moves
	for (int i = 0; i < n_len1; i++)
	{
		int x = a[i]; // Extract the digit from the current code
		int y = b[i]; // Extract the digit from the target code
		int diff1 = abs(x - y); // Difference between digits (forward rotation)
		int diff2 = 10 - abs(x - y); // Difference between digits (reverse rotation)
		// The minimum number of moves is the shortest distance between each digit
		// of the current code and the target code on the safe dial.
		// The total number of moves is the final answer.
		total_moves += min(diff1, diff2);
	}
	// Display information on the screen
	printf("Current code: %s\r\n", a);
	printf("Target code: %s\r\n", b);
	printf("Minimum number of moves: %d\r\n", total_moves);
	// Pause output until the "Enter" key is pressed
	getc(stdin);
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item 
//		to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

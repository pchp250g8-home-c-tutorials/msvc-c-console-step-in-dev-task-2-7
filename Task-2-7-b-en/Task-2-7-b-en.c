// Task-2-7-b-en.c : This file contains the 'main' function. Program execution begins and ends there.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <alg.h>

int main(int argc, char* args[])
{
    int total_moves = 0; // Move counter
    int a, a1; // Current code value
    int b, b1; // Target code value
    int m = 0; // Number of digits in the current code
    int n = 0; // Number of digits in the target code
    // Reading input data
    // Input data: target code and current code
    // Entered as four-digit numbers
    printf("Enter the current code: ");
    scanf("%d", &a);
    printf("Enter the target code: ");
    scanf("%d", &b);
    n = 0; // Number of digits in the current code
    a1 = a;
    b1 = b;
    // Number of digits in the current code
    while (a1 > 0)
    {
        m += 1; // Calculate the number of digits in the value. 
        a1 /= 10; // Divide the value by 10.
    }
    // Number of digits in the target code
    while (b1 > 0)
    {
        n += 1; // Calculate the number of digits in the value. 
        b1 /= 10; // Divide the value by 10.
    }
    // Check if the lengths of the current and target codes match
    // If the lengths are not equal, or if either code is not four digits long,
    // the program terminates.
    if ((m != 4) || (n != 4) || (m != n))
    {
        printf("The combination for the combination lock must be 4 digits long.");
        printf("The current and target codes must be of the same length.");
        // Pause the output until the "Enter" key is pressed
        getchar();
        getc(stdin);
        return 0;
    }
    a1 = a;
    b1 = b;
    // Iterate through the digits of the current and target codes
    while ((a1 > 0) && (b1 > 0))
    {
        int d1 = a1 % 10; // Digit from the current code
        int d2 = b1 % 10; // Digit from the target code
        int diff1 = abs(d1 - d2); // Difference between digits (direct rotation)
        int diff2 = 10 - abs(d1 - d2); // Difference between digits (reverse rotation)
        // The minimum number of moves is the smallest distance between each corresponding
        // digit of the target code and the current code of the safe lock.
        total_moves += min(diff1, diff2);
        a1 /= 10; // Move to the next digit of the current code
        b1 /= 10; // Move to the next digit of the target code
    }
    // Display information on the screen
    printf("Current code: %d\r\n", a);
    printf("Target code: %d\r\n", b);
    printf("Minimum number of moves: %d\r\n", total_moves);
    // Pause the output until the "Enter" key is pressed
    getchar();
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
//      to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
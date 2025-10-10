/*
 * Filename: count_words.c
 * Author: odinHQ
 * Date: 2025-10-10
 * Description:
 *   This program reads a sequence of characters one by one from the user.
 *   Words are separated by spaces or commas. Input ends with a dot '.'.
 *   It counts the number of words that start and end with the same letter.
 * Example:
 *   Input: g o g, b o b, a a .
 *   Output: 3
 */

#include <stdio.h>

int main(void)
{
    char c;             // current character
    char first = 0;     // first letter of the current word
    char last = 0;      // last letter of the current word
    int count = 0;      // number of words that start and end with the same letter
    int in_word = 0;    // flag indicating whether we are inside a word

    printf("Enter characters one by one. Words are separated by spaces or commas.\n");
    printf("End input with a dot '.'\n");

    while (1)
    {
        scanf_s("%c", &c, 1); // read one character

        if (c == '.')  // dot = end of input
        {
            if (in_word) // if there was a word before the dot
            {
                if (first == last)
                    count++;
            }
            break;
        }

        if (c == ' ' || c == ',') // end of a word
        {
            if (in_word)
            {
                if (first == last)
                    count++;
                in_word = 0; // exit current word
            }
        }
        else
        {
            if (!in_word) // start of a new word
            {
                first = c;
                in_word = 1;
            }
            last = c; // update the last letter of the word
        }
    }

    printf("\nNumber of words that start and end with the same letter: %d\n", count);

    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *word1 = argv[1];
    char *word2 = argv[2];
    
    int len1 = strlen(word1);
    int len2 = strlen(word2); 
   
    int numOfLetters[126] = {0}; // initialize an array containing only zeros (256 for the number of ascii characters)
    
    if (len1 !=len2) {
        printf("Not an anagram \n"); // Check if the two words have the same number of letters
        return 1;
    }
    
    for (int i = 0 ; i < len1 ; i++){ // Increment the array at the index of each letter of the first word, ie if the first letter is 'a', increment at numOfLetters[97].
        int letter1 = (int ) word1[i];
        if (letter1>=65 && letter1<=90){ // for the program to be case insensitive
            letter1 += 32 ;
        }
        numOfLetters[letter1]++;
    }

    for (int i = 0 ; i < len2 ; i++){ // decrement the array for the second word.
        int letter2 = (int) word2[i];
        if (letter2>=65 && letter2<=90){
            letter2 += 32;
        }
        numOfLetters[letter2]--;        
    }

    for (int i=0;i<126;i++){ // Check if the array contains anything other than zeros, if so, the words are not anagrams
        if (numOfLetters[i] != 0){
            printf("Not an anagram \n");
            return 1 ;
        }
    } 
    printf("Anagrams\n");
    return 0;
}

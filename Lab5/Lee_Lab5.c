//
//  Lee_Lab5.c
//  
//
//  Created by Jihye Lee on 2/14/24.
//

#include "Lee_Lab5.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


// defined the number of lower, upper, and spaces = 0
int lower = 0;
int upper = 0;
int space = 0;

// Input string in an array form
char input[] = "My String is Being Stored on My Process Memory's Stack\n";


// Counts the number of lower-case letters in the gvien string
int lower_case(char string[]){
    
    
    for (int index = 0; index < strlen(string);index++){
        if (islower(string[index])) {
            lower++;
        }
    }
    return lower;
}

// Coutns the number of upper-case letters in the given string
int upper_case(char string[]){
    
    for (int index = 0; index < strlen(string);index++){
        if (isupper(string[index])) {
            upper++;
        }
    }
    return upper;
    
}

// Counts the number of spaces in the given string
int spaces(char string[]){
    
    for (int index = 0; index < strlen(string);index++){
        if (string[index] == ' ') {
            space++;
        }
    }
    return space;
    
}

// Count how many tiems does the letter appears in the string
bool counter (char letter) {
    int count =0;
    for (int i=0;i<strlen(input);i++){
        if (input[i] == letter)
            count ++;
    }
    if (count == 1){
        return true;
    } else{
        return false;
    }
}

// Return the unique letter
int unique_letter(char string[]){
    
    for (int index = 1; index < strlen(string);index++){
        if (counter(string[index])){
            return string[index];
        }
    }
    return '\0';
}

int main(){
    printf("%s",input);
    printf("Total Lowercases letters are: %d \n", lower_case(input));
    printf("Total Uppercases letters are: %d \n", upper_case(input));
    printf("Total spaces are: %d \n", spaces(input));
    printf("The first non-recurring letter is: %c", unique_letter(input));
    
}

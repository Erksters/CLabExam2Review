#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
/*
 * This program:
 * 1- Stores some city names in an dynamic array.
 * 2- The names are stored in memory allocated dynamically for the exact number of bytes (strlen) required by the city name
 * 3- It can print the city names in three different formats, depending on the user's selection
 * 4- Once the user selects the option, the function should be called dynamically
 * 5- See menu below for restrictions for each function
 */

void printAsIs(char ** array, int numberOfCities);
void printToUpper(char ** array, int numberOfCities);
void printReverse(char ** array, int numberOfCities);

int main() {

    typedef void (*printCitiesFun)(char ** array, int numberOfCities);
    printCitiesFun printFun;

    const int NUMOFCITIES = 3;
    char ** cities = (char*)malloc(sizeof(char)*NUMOFCITIES);
    char cityName[50];

    for(int i = 0; i < 3; i++){
        printf("Enter city %d name: ", i);
        scanf("%s", cityName); getchar();
        cities[i] = malloc(sizeof(char) * strlen(cityName));
        strcpy(cities[i], cityName);

    }

    printf("\n");

    printf("Select a format to print Cities\n");
    printf("1- As Is\n"); // As the user typed it
    printf("2- All Caps\n"); // (i) Use toupper to convert each character at the time (ii) do NOT use strlen()
    printf("3- Reverse Print\n"); // (i)  You can use strlen()

    printf("What format to print?\n");

    char selection = getchar();

    switch (selection){
        case '1':
            printFun = printAsIs;
            break;
        case '2':
            printFun = printToUpper;
            break;
        case '3':
            printFun = printReverse;
            break;
        default:
            printf("Not an Option");

    }

    (*printFun)(cities, NUMOFCITIES);









    return 0;
}

/// This method will take in a double pointer and print of the character arrays "as is"
/// \param array
/// \param numberOfCities
void printAsIs(char ** array, int numberOfCities){
    for(int j = 0; j< numberOfCities; j++){
        printf("%s\n", *array++);
    }
}

/// This method will take in a double pointer and print off the characters as its "Capitalized counterpart".
/// \param array
/// \param numberOfCities
void printToUpper(char ** array, int numberOfCities){
    for(int j = 0; j< numberOfCities; j++){
        for(int k = 0; k<strlen(array[j]); k++){
            char temp = array[j][k];
            printf("%c", toupper(temp));
        }
        printf("\n");
    }
}

/// This method will take in a double pointer and print off the characters from back to front A.K.A. in reverse. For Reverse order, change the outer for loop instead.
/// \param array
/// \param numberOfCities
void printReverse(char ** array, int numberOfCities){
    for(int j = 0; j< numberOfCities; j++){
        for(int k = (int)strlen(array[j]) ; k>-1; k--){
            char temp = array[j][k];
            printf("%c", temp);
        }
        printf("\n");
    }
}
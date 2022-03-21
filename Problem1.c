/*
 * ECE-330 HW4 Problem #1
 * Author: Bree Latimer
 * Date: 3/20/2022
 * 
 * This program takes in a user input 'n' Where n is the number of integers to populate the array.
 * The array will then be populated by n number of random integers and the program will output 
 * two numbers: The sum of all even numbers, and the sum of all odd numbers.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printUsage();

int main(int argc, char *argv[]){
  //Giving our random number generator a seed
  srand(time( NULL ));

  //Expected path to enter
  if(argc == 2){
    int evenSum = 0;
    int oddSum = 0;

    int size = atoi(argv[1]); //Read user input and put it into a variable as an integer
    int numArray[size];

    //Populate the array with random numbers
    for(int i = 0; i < size; i++){
      numArray[i] = rand() % 100;
      printf("%d\n", numArray[i]);
    }

    //Go through array and add to respective counters
    for(int i = 0; i < size; i++){
      //Check if odd
      if(numArray[i] % 2 != 0){
        oddSum += numArray[i];
      } else {
        evenSum += numArray[i];
      }
    }

    printf("Odd sum: %d\nEven sum: %d\n", oddSum, evenSum);

  }else if(argc != 2){
    printUsage();
  }
  return 0;
}

void printUsage(){
  printf("Usage:\n./problem1 <number of integers to populate the array>\n");
}

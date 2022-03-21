/**
 * ECE-330 HW4 Problem #2
 * Author: Bree Latimer
 * Date: 3/20/2022
 * 
 * I tried ¯\_(ツ)_/¯
 * Segfaults will not leave me alone.
 * 
 * This program has 2 predetermined sets of size 10.
 * We then print the results of the following set operations.
 * A Union B
 * A Intersection B
 * and finally,
 * A-B and B-A. (This will be done by calculating the intersection of the two and subtracting it from their corresponding set)
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printArray();
int * set_union();
// int * set_intersection();
// int * set_difference();


const int ARRAY_SIZE = 10;

int main(int argc, char *argv[]){
    //Giving our random number generator a seed
    srand(time( NULL ));

    int array_a[] = {6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int array_b[] = {11, 12, 13, 14, 15, 16, 17, 18, 19};

    int unionSet = *set_union(array_a, array_b);
    int unionSetSize = sizeof(unionSet / sizeof(int));

    printf("A union B is:\n");
    printArray(unionSet, unionSetSize);

    // //Call A Intersection B and print
    // printf("A intersection B is:\n");
    // printArray(setIntersection(array_a, array_b, ARRAY_SIZE), ARRAY_SIZE);

    // //Call A - B and B - A and print
    // print("A - B is:\n");
    // printArray(setMinus(array_a, array_b, ARRAY_SIZE), ARRAY_SIZE);

    // print("B - A is:\n");
    // printArray(setMinus(array_b, array_a, ARRAY_SIZE), ARRAY_SIZE);

}

int * set_union(int array_a[], int array_b[]){
    int setSize = 0;
    
    int tempSet[20]; //initialize to the max value

    for(int i = 0; i < ARRAY_SIZE; i++){
        tempSet[i] = array_a[i];
        setSize++;
    }

    for(int i = 0; i < ARRAY_SIZE; i++){
        int contains = 0;
        for(int j = 0; j < setSize; j++){
            if(array_b[i] == tempSet[j]){
                contains = 1;
            }
        }

        if(contains == 0){
            tempSet[setSize] = array_b[i];
            setSize++;
        }
    }

    int retVal[setSize];
    for(int i = 0; i < setSize; i++){
        retVal[i] = tempSet[i];
    }

    return &retVal;
}

void printArray(int inputArray[], int size){
    printf("{");
    for(int i = 0; i < size; i++){
        if(i != size-1){
            printf("%d, ", inputArray[i]);
        } else {
            printf("%d", inputArray[i]);
        }
    }
    printf("}\n");
}
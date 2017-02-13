#include <stdio.h>
#include <stdlib.h>

// function prototype
void fuzzyOn();
void bubbleSort();

// main
int main(){
    fuzzyOn();
    return 0;
}

// function of fuzzy execution
void fuzzyOn(){
    bubbleSort();
}

// function of bubble sort
void bubbleSort(){
    // variables
    int num[] = {64, 97, 87, 77, 54, 66, 81, 79, 88, 73}; // initialize value
    int i, j, temp; // bubble sort variables
    int highNum;
    int numLength = sizeof(num) / sizeof(num[0]);

    // before bubble sort
    printf("initialize value : ");
    for(i = 0; i < numLength; i++){
        printf("%d ",num[i]);
    }
    printf("\n");

    // highest value
    highNum = num[0];
    for(i = 0; i < numLength; i++){
        if(num[i] > highNum){
            highNum = num[i];
        }
    }

    // bubble sort
    for (i = 0; i < numLength; i++) {
        for (j = 0; j < numLength - i; j++) {
            if (num[j] > num[j+1]) {
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }

    // before bubble sort
    printf("after bubble sort : ");
    for(i = 0; i < numLength; i++){
        printf("%d ",num[i]);
    }
    printf("\n");
}

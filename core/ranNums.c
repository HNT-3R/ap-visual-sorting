#include "core.h"

//generiert eine zufällige Ganzzahl unter dem gegebenen Limit
int generateRandomNumber(int max) { 
    return (rand() % max + 1);
}

//mischt ein Integer-Array
void shuffleNums(int *p_nums, int maxIndex) {
    for (int i = 0; i < maxIndex; i++) {
        int temp = p_nums[i];
        int randI = generateRandomNumber(maxIndex - 1);

        p_nums[i] = p_nums[randI];
        p_nums[randI] = temp;
    }
}

//füllt ein Array mit vollkommen unterschiedlichen Werten
//Resultat ist aufsteigend sortiert
void setAllDisctinctSortedAsc(int *p_nums, int max) {
    //alldistinct machen
    for (int i = 0; i < max; i++) {
        p_nums[i] = i;
    }
}

//füllt ein Array mit vollkommen unterschiedlichen Zahlen
//Zahlen können mehrfach vorkommen und sind unsortiert
void setRanNumsUnsorted(int *p_nums, int max) {
    for (int i = 0; i < max; i++) {
        p_nums[i] = generateRandomNumber(max);
    }
}

//ordnet ein Array rüchwärts an
void setNumsBackwards(int *p_nums, int max) {
    for (int i = 0; i < max/2; i++) {
        int temp = p_nums[i];
        p_nums[i] = p_nums[(max-1) - i];
        p_nums[(max-1) - i] = temp; 
    }
}

//sortiert ein Array mit Selectionsort
//benötigt für non-distinct Arrays
void setSorted(int *p_nums, int max) {
    List* list;
    int n;
    int minIdx;

    n = max;
    for(int i = 0; i < n - 1; i++) {
        minIdx = i;

        for(int j = i + 1; j < n; j++) {
            if(p_nums[j] < p_nums[minIdx]) {
                minIdx = j;
            }
        }
        int tmp = p_nums[i];
        p_nums[i] = p_nums[minIdx];
        p_nums[minIdx] = tmp;
    }
}
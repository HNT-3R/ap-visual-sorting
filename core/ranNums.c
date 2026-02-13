#include "core.h"


int myRanNum(int max) { 
    return (rand() % max + 1);
}

void shuffleNums(int *p_nums, int maxIndex) {
    for (int i = 0; i < maxIndex; i++) {
        int temp = p_nums[i];
        int randI = myRanNum(maxIndex - 1);

        p_nums[i] = p_nums[randI];
        p_nums[randI] = temp;
    }
}

//alle zahen unterschiedlich
void setAllDisctinctSortedAsc(int *p_nums, int max) {
    //alldistinct machen
    for (int i = 0; i < max; i++) {
        p_nums[i] = i;
    }
}

//alle zahlen random, können auch gleiche mehrmals vorkommen
void setRanNumsUnsorted(int *p_nums, int max) {
    for (int i = 0; i < max; i++) {
        p_nums[i] = myRanNum(max);
    }
}

void setOrderedNums(int *p_nums, int max) {
    for (int i = 0; i < max; i++) {
        p_nums[i] = i;
    }
}

void setReverseOrderedNums(int *p_nums, int max) {
    for (int i = 0; i < max; i++) {
        p_nums[i] = max - i;
    }
}

void setNumsBackwards(int *p_nums, int max) {
    for (int i = 0; i < max/2; i++) {
        int temp = p_nums[i];
        p_nums[i] = p_nums[(max-1) - i];
        p_nums[(max-1) - i] = temp; 
    }
}

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
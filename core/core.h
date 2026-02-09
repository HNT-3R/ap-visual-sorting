
#ifndef CORE_H
#define CORE_H

#include <stdlib.h>

typedef struct {
    int dynLength;
    int absLength;
    int *nums;
    int index;
    bool isFinished;
} List;

#include "../ui/ui.h"

typedef struct {
    int algoNum; //wie viele algorithmen zu sortieren

    int maxArrNum; //wie viele elemente in liste, und wie groß ist größtes element
    bool allDistinct; //alle unterschiedlich in unsortierter liste, oder egal
    
} SortStruct;



void simpelSort(List* list);

void setAllDisctinctRanNums(int *p_nums, int max);
void setRanNums(int *p_nums, int max);


#endif
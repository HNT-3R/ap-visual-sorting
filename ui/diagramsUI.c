#include "ui.h"



void drawDiagramsUI(float w, float h, AppState* state) {
    int tiles = 0;
    for (int i = 0; i < state->algoInfoNum; i++) {
        if (state->algoInfos[i].isSelected) tiles++;
    }
    int tileAr[tiles];
    int counter = 0;
    for (int i = 0; i < state->algoInfoNum; i++) {
        if (state->algoInfos[i].isSelected) {
            tileAr[counter] = i;
            counter++;
        }
    }
    float widthDiv = 1;
    float heightDiv = 1;

    while (widthDiv * heightDiv < tiles) {
        if (widthDiv <= heightDiv) widthDiv++;
        else heightDiv++;
    }
    //printf("%d: %d, %d tiling\n", tiles, widthDiv, heightDiv);


    for (float i = 0; i < widthDiv; i++) {
        for (float j = 0; j < heightDiv; j++) {
            if (counter > 0) {
                float recW = w / widthDiv;
                float recH = h / heightDiv;
                Rectangle rec = {(recW * i) + 1, (recH * j) + 1, recW - 2, recH - 2};
                //drawOutline(rec, 1, PINK);
                createDiagram(rec, state->algos[tileAr[counter-1]].list);
                DrawText((state->algoInfos[tileAr[counter-1]].name), rec.x, rec.y, (w * h * 0.000022f), LIME);
                counter--;
            }
            
        }
    }
    /*
    Rectangle dia = {0, 0, w, h};
    int finishedCounter;
    for (int i = 0; i < 1; i++) { 
        createDiagram(dia, state->algos[i].list);
        if(state->algos[i].list->isFinished) {
            finishedCounter++;
        }
    }
    if(finishedCounter >= state->algoNum) {
        state->toDraw = 2;
    }*/
}
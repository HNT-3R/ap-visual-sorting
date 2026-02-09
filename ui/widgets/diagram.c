#include "../ui.h"

int findMax(int ar[], int length) {
    int maxValue = 0;
    for(int i = 0; i < length; i++) {
        if (ar[i] > maxValue) {
            maxValue = ar[i];
        }
    }
    return maxValue;
}

void createDiagram(Rectangle box, List* list) {
    int len = list->absLength;
    if (len <= 0) return;
    
    int barWidth = box.width / len;
    int maxValue = findMax(list->nums, len);  // Maximum berechnen

    
    for(int i = 0; i < len; i++) {
        int barHeight = (list->nums[i] * box.height) / maxValue;
        
        int x = box.x + (i * barWidth);
        int y = box.y + box.height - barHeight;
        
        
        if (i == list->index) {
            DrawRectangle(x, y, barWidth, barHeight, RED);
        } else {
            DrawRectangle(x, y, barWidth, barHeight, LIGHTGRAY);
        }

        if (list->isFinished) {
            DrawRectangle(x, y, barWidth, barHeight, GRAY);
            //usleep(timeStep); //animation so aufsteigende balken noch machen
        }

    }

    drawOutline(box, 4, PINK);
}
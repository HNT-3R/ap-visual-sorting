#include <stdio.h>
#include <stdlib.h>
#include "raylib.h"


#define defaultWidth 1200
#define defaultHeight 800
#define len(arr) (sizeof(arr) / sizeof((arr)[0]))

typedef struct {
    int x;
    int y;
    int width;
    int height;
} Box;

int findMax(int ar[], int length) {
    int maxValue = 0;
    for(int i = 0; i < length; i++) {
        if (ar[i] > maxValue) {
            maxValue = ar[i];
        }
    }
    return maxValue;
}

void drawOutline(Box box, int thickness, Color c) {
    //oben
    DrawRectangle(box.x, box.y, box.width, thickness, c);

    //links
    DrawRectangle(box.x, box.y, thickness, box.height, c);
   
    //untent
    DrawRectangle(box.x, box.height-thickness, box.width, box.height, c);
    
    //rechts
    DrawRectangle(box.x + box.width - thickness, box.y, thickness, box.height, c);
}

void createDiagram(Box box, int *nums, int length) {
    if (length <= 0) return;
    
    int barWidth = box.width / length;
    int maxValue = findMax(nums, length);  // Maximum berechnen
    
    for(int i = 0; i < length; i++) {
        int barHeight = (nums[i] * box.height) / maxValue;
        
        int x = box.x + (i * barWidth);
        int y = box.y + box.height - barHeight;
        
        DrawRectangle(x, y, barWidth, barHeight, GREEN);
    }
    drawOutline(box, 4, PINK);
}

int main(void) {
    int sWidth = defaultWidth;
    int sHeight = defaultHeight;
    int num = 30;
    int *nums = calloc(num, sizeof(int));
    
    for (int i = 0; i < num; i++) {nums[i] = i;}

    SetConfigFlags(FLAG_WINDOW_MAXIMIZED | FLAG_WINDOW_RESIZABLE);
    InitWindow(sWidth, sHeight, "Diagramm Beispiel");
    SetTargetFPS(60); 

    while (!WindowShouldClose()) 
    {
        BeginDrawing();
        
        sWidth = GetScreenWidth();
        sHeight = GetScreenHeight();
        Box b = {0, 0, sWidth, sHeight};
        ClearBackground(SKYBLUE);
        createDiagram(b, nums, num);
        
        EndDrawing();
    }


    free(nums);
    CloseWindow();
    return 0;
}
#include "ui.h"
//DrawText(text, box.x+6, box.y+2, box.height-2, c);
void drawSortChooser(int w, int h) {
    DrawText("choose sorting\nalgorithm", 8, 0, w/40, FSTCOLOR);

    Rectangle rec = {0, 0, ((int) w/4), ((int) h/5*3)};
    drawOutline(rec, 4, FSTCOLOR);
}


void drawTextInput(Rectangle rec, AppState* state) {
    
    
    drawInputField(rec, state->numMaxInput, &state->letCount);
}

void drawOptChooser(int w, int h, AppState* state) {
    DrawText("choose list\nparameter", 8, (int) h/5*3, w/40, FSTCOLOR);

    Rectangle rec = {0, h/5*3 - 4, w/4, h/5*2 + 4};
    drawOutline(rec, 4, FSTCOLOR);

    DrawText("List size n:", 8, h/5*3.5f, w/40, FSTCOLOR);
    Rectangle nRec = {8, h/5*3.68f, rec.width-16, w/36};
    drawTextInput(nRec, state);
}

void drawStartButton(int w, int h, AppState* state) {
    int btnX = (int) w / 10 * 8;
    int btnY = (int) h / 20 * 18; 

    int btnWidth = (w / 6); 
    int btnHeight = (h / 14);
    
    
    Rectangle btn = {btnX, btnY, btnWidth, btnHeight};

    bool isPressed = false;
    drawButton(btn, "start", &isPressed);
    if (isPressed) {
        state->toDraw = 1;
    }
}



void drawChooseUI(int w, int h, AppState* state) {
    drawSortChooser(w, h);
    drawOptChooser(w, h, state);
    drawStartButton(w, h, state);

    
    
}




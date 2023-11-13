#include "dragAndDrop.h"

void CheckIfAnswerIsInTheSlot(bool& isinslot1, bool& isinslot2, Rectangle Option1, Rectangle Option2, Rectangle OptionSlot1, Rectangle OptionSlot2) {
    isinslot1 = CheckCollisionRecs(Option1, OptionSlot1);
    if (!isinslot1) {
        isinslot1 = CheckCollisionRecs(Option2, OptionSlot1);
    }
    isinslot2 = CheckCollisionRecs(Option1, OptionSlot2);
    if (!isinslot2) {
        isinslot2 = CheckCollisionRecs(Option2, OptionSlot2);
    }
}


void NewObjective(int resetcounter, bool& Option1inCorrectSlot, bool& Option2inCorrectSlot, Rectangle Option1, Rectangle Option2, Rectangle OptionSlot1, Rectangle OptionSlot2) {
    if (resetcounter == 0) {
        Option1inCorrectSlot = CheckCollisionRecs(Option1, OptionSlot1);
        Option2inCorrectSlot = CheckCollisionRecs(Option2, OptionSlot2);
    }
    else if (resetcounter == 1) {
        Option1inCorrectSlot = CheckCollisionRecs(Option1, OptionSlot2);
        Option2inCorrectSlot = CheckCollisionRecs(Option2, OptionSlot1);
    }
    else if (resetcounter == 2) {
        Option1inCorrectSlot = CheckCollisionRecs(Option1, OptionSlot2);
        Option2inCorrectSlot = CheckCollisionRecs(Option2, OptionSlot1);
    }
}


void DragNDropCheckAndDamage(bool& isinslot1, bool& isinslot2, bool& Option1inCorrectSlot, bool& Option2inCorrectSlot, bool& isSnapped, bool& turncheck, bool& dmgplayer, bool& dmgenemy, float* original1X, float* original1Y, float* original2X, float* original2Y, int& Health, int& EnemyHealth, int& counter, int& resetcounter) {

    if (IsMouseButtonUp(MOUSE_LEFT_BUTTON) && (isinslot1 && !Option1inCorrectSlot) && (isinslot2 && !Option2inCorrectSlot) && isSnapped) {
            *original1X = 300;
            *original1Y = 600;
            *original2X = 380;
            *original2Y = 600;
            Health -= 25;
            dmgplayer = true;
            isSnapped = false;
            turncheck = false;
        }


        if (IsMouseButtonUp(MOUSE_LEFT_BUTTON) && Option1inCorrectSlot && Option2inCorrectSlot && isSnapped) {
            *original1X = 300;
            *original1Y = 600;
            *original2X = 380;
            *original2Y = 600;
            if (counter == 0) {
                EnemyHealth -= 40;
                counter++;

            }
            else {
                EnemyHealth -= 30;
            }
            dmgenemy = true;
            isSnapped = false;
            turncheck = false;
            resetcounter += 1;
        }
    }


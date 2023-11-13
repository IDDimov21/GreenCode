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

void CheckIfAnswerIsInTheSlotHard(bool& isinslot1, bool& isinslot2, Rectangle Option1, Rectangle Option2, Rectangle Option3, Rectangle Option4, Rectangle OptionSlot1, Rectangle OptionSlot2) {
    isinslot1 = CheckCollisionRecs(Option1, OptionSlot1) || CheckCollisionRecs(Option2, OptionSlot1) || CheckCollisionRecs(Option3, OptionSlot1) || CheckCollisionRecs(Option4, OptionSlot1);
    isinslot2 = CheckCollisionRecs(Option1, OptionSlot2) || CheckCollisionRecs(Option2, OptionSlot2) || CheckCollisionRecs(Option3, OptionSlot2) || CheckCollisionRecs(Option4, OptionSlot2);
    /*if (!isinslot1) {
        isinslot1 = CheckCollisionRecs(Option1, OptionSlot2) || CheckCollisionRecs(Option2, OptionSlot2) || CheckCollisionRecs(Option3, OptionSlot2) || CheckCollisionRecs(Option4, OptionSlot2);

        if (isinslot1) {
            isinslot2 = false;
        }
    }*/
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

void NewObjectiveHard(int resetcounter, bool& Option1inCorrectSlot, bool& Option2inCorrectSlot, bool& Option3inCorrectSlot, bool& Option4inCorrectSlot,Rectangle Option1, Rectangle Option2, Rectangle Option3, Rectangle Option4,Rectangle OptionSlot1, Rectangle OptionSlot2) {
    if (resetcounter == 0) {
        Option1inCorrectSlot = CheckCollisionRecs(Option1, OptionSlot1);
        Option3inCorrectSlot = CheckCollisionRecs(Option3, OptionSlot2);
    }
    else if (resetcounter == 1) {
        Option1inCorrectSlot = CheckCollisionRecs(Option1, OptionSlot2);
        Option2inCorrectSlot = CheckCollisionRecs(Option2, OptionSlot1);
        Option3inCorrectSlot = CheckCollisionRecs(Option3, OptionSlot2);
        Option4inCorrectSlot = CheckCollisionRecs(Option4, OptionSlot1);
    }
    else if (resetcounter == 2) {
        Option1inCorrectSlot = CheckCollisionRecs(Option1, OptionSlot1) || CheckCollisionRecs(Option1, OptionSlot2);
        Option2inCorrectSlot = CheckCollisionRecs(Option2, OptionSlot1) || CheckCollisionRecs(Option2, OptionSlot2);
        Option3inCorrectSlot = CheckCollisionRecs(Option3, OptionSlot1) || CheckCollisionRecs(Option3, OptionSlot2);
        Option4inCorrectSlot = CheckCollisionRecs(Option4, OptionSlot1) || CheckCollisionRecs(Option4, OptionSlot2);
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
            if (counter == 1) {
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

void DragNDropCheckAndDamageHard(bool& isinslot1, bool& isinslot2, bool& Option1inCorrectSlot, bool& Option2inCorrectSlot,bool& Option3inCorrectSlot, bool& isSnapped, bool& turncheck, bool& dmgplayer, bool& dmgenemy, float* original1X, float* original1Y, float* original2X, float* original2Y, float* original3X, float* original3Y, float* original4X, float* original4Y, int& Health, int& EnemyHealth, int& counter, int& resetcounter) {
    if ((IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && isinslot1 && !Option1inCorrectSlot) && (isinslot2 && !Option3inCorrectSlot) && isSnapped) {
        *original1X = 300;
        *original1Y = 600;
        *original2X = 380;
        *original2Y = 600;
        *original3X = 460;
        *original3Y = 600;
        *original4X = 540;
        *original4Y = 600;
        Health -= 25;
        dmgplayer = true;
        isSnapped = false;
        turncheck = false;
    }
    if ((IsMouseButtonReleased(MOUSE_LEFT_BUTTON) && Option1inCorrectSlot && Option3inCorrectSlot && isSnapped)) {
            *original1X = 300;
            *original1Y = 600;
            *original2X = 380;
            *original2Y = 600;
            *original3X = 460;
            *original3Y = 600;
            *original4X = 540;
            *original4Y = 600;
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
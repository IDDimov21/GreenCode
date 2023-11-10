#include "gameStructures.h"
#include "raylib.h"


void DragNDrop(bool& collision, bool& isDragging, bool& isSnapped, bool& check1, Rectangle& Option, Rectangle& OptionSlot1, Rectangle& OptionSlot2) {

    if (collision) {
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && CheckCollisionPointRec(GetMousePosition(), Option)) {
            isDragging = true;
        }
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            isDragging = false;
            if (CheckCollisionRecs(Option, OptionSlot1)) {
                Option.x = OptionSlot1.x + 14;
                Option.y = OptionSlot1.y + 2;
                isSnapped = true;
                check1 = true;
            }
            if (CheckCollisionRecs(Option, OptionSlot2)) {
                Option.x = OptionSlot2.x + 14;
                Option.y = OptionSlot2.y + 2;
                isSnapped = true;
                check1 = true;
            }
        }
        if (isDragging) {
            Option.x = GetMouseX() - Option.width / 2;
            Option.y = GetMouseY() - Option.height / 2;
            isSnapped = false;
        }
    }
}
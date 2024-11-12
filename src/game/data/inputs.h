#ifndef NO_VSCODE
#include "defines.h"
#endif

// KEYMAP(...) are sdl scancodes
// change them to something different if youre
// using a different api for keyboard input

INPUT(BUTTON_MOUSE_LEFT)   MOUSEBTN(1)              CONTROLLER(A)
INPUT(BUTTON_MOUSE_RIGHT)  MOUSEBTN(3)
INPUT(BUTTON_MOUSE_MIDDLE) MOUSEBTN(2)
INPUT(BUTTON_MOVE_UP)      KEYMAP(/* W */      26)  JOYSTICK(0 UP)    CONTROLLER(D_UP)
INPUT(BUTTON_MOVE_LEFT)    KEYMAP(/* A */      4)   JOYSTICK(0 LEFT)  CONTROLLER(D_LEFT)
INPUT(BUTTON_MOVE_DOWN)    KEYMAP(/* S */      22)  JOYSTICK(0 DOWN)  CONTROLLER(D_DOWN)
INPUT(BUTTON_MOVE_RIGHT)   KEYMAP(/* D */      7)   JOYSTICK(0 RIGHT) CONTROLLER(D_RIGHT)
INPUT(BUTTON_JUMP)         KEYMAP(/* space  */ 44)  CONTROLLER(A) CONTROLLER(B)
INPUT(BUTTON_RUN)          KEYMAP(/* lshift */ 225) CONTROLLER(X) CONTROLLER(Y)
INPUT(BUTTON_PAUSE)        KEYMAP(/* escape */ 41)  CONTROLLER(PLUS)
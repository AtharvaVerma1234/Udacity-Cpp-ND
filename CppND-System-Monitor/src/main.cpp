#include "ncurses_display.h"
#include "system.h"
#include <string>
int main() {
  System system;
  NCursesDisplay::Display(system);
}
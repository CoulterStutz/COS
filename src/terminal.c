// Terminal.C
// Written to house the functions commonly used in terminal
// Written by Coulter C. Stutz


#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
#include "include/types.h"

#include "include/math.h"
#include "include/system.h"

void badge() {
    print_red("C");
    print_cyan("O");
    print_green("S ");
    print_pink(sysvrs);
    print("\n\n");
}

void badge_min(){
    print("COS ");
    print(sysvrs);
}

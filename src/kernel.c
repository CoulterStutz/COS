#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
#include "include/types.h"
#include "include/system.h"

void kmain() {
    // Clear the screen and print the welcome message
    clearScreen();
    print("COS 1.0\n");
    //delay(100000000);

    // Main loop
    while (1) {
        // Prompt for user input
        print("\nCOS> ");

        // Read user input
        string ch = readStr();

        // Process input if its length is greater than 1
        if (strlength(ch) > 1 || (strlength(ch) == 1 && ch[0] != '\n')) {

            // Clear screen command
            if (strEql(ch, "clear")) {
                clearScreen();
            }

            // Display system info command
            else if (strEql(ch, "info")) {
                print("\n\nCOS 1.0 | Written by Coulter C. Stutz ");
                print("\n   Bootloader written in 32 bit Assembly Language ");
                print("\n       Compiled with NASM ");
                print("\n   Kernel written in C ");
                print("\n       Compiled with GCC ");
                print("\n\nSome Include Libs forked from IKnowYourBrain ");
                print("\n   His Bitcoin Address:1KEJNtrJAU3VEYyiBtELKra1Tq3XM5Ligk ");
                print("\n\n\n   Buy Me Virtual Pizza! ");
                print("\n   Bitcoin: 13jStC1PWwZttLc8rhG6Xn1UeKE7rAP6hQ ");
                print("\n   ETH/BSC/MATIC: 0xa693190103733280E23055BE70C838d9b6708b9a ");
                print("\n   Monero: 49zw4GkS6MAWffKoskZxba3WXRtLJPUpwbN5ufmHL2AgKzB7YjSWBoVPivtPmn1DVxLiSwdZc7QnkcFnvXUuWdK3RV1xhZZ ");
            }

            // Exit Command
            else if (strEql(ch, "exit"))
            {
                clearScreen();
                print("Shutting Down COS");
                print_red("\n\nHalting!");
                __asm__("hlt");
            }

            // Command not recognized
            else {
                print("\nUnknown Command: ");
                print(ch);
            }

            // Print additional newline for spacing
            print("\n\n");
        } 
        // If input is too short, just print a newline
        else {
            print("\n");
        }
    }
}

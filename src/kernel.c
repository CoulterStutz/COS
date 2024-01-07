#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
#include "include/types.h"
kmain()
{
       clearScreen();
       print("Welcome to COS operating system\n");
       while (1)
       {
                print("\nCOS> ");
                
                string ch = readStr();
                
                if(strEql(ch,"clear"))
                {
                        clearScreen();
                }
                else if(strEql(ch,"info"))
                {
                        print("\n\nCOS 1.0 | Written by Coulter C. Stutz ");
                        print("\n   Bootloader written in 32 bit Assembly Language ");
                        print("\n       Compiled with NASM ");
                        print("\n   Kernel written in C ");
                        print("\n       Compiled with GCC ");
                        print("\n\nInclude Libs forked from IKnowYourBrain ");
                        print("\n   His Bitcoin Address:1KEJNtrJAU3VEYyiBtELKra1Tq3XM5Ligk ");
                        print("\n\n\n   Buy Me Virtual Pizza! ");
                        print("\n   Bitcoin: 13jStC1PWwZttLc8rhG6Xn1UeKE7rAP6hQ ");
                        print("\n   ETH/BSC/MATIC: 0xa693190103733280E23055BE70C838d9b6708b9a ");
                        print("\n   Monero: 49zw4GkS6MAWffKoskZxba3WXRtLJPUpwbN5ufmHL2AgKzB7YjSWBoVPivtPmn1DVxLiSwdZc7QnkcFnvXUuWdK3RV1xhZZ ");
                }
                else
                {
                        print("\nBad command!\n");
                        print(ch);
                }
                
                print("\n\n");        
       }
        
}

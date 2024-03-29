// string.h
// Written by IKnowYourBrain for free use with bare-metal C programming
//      Youtube: https://www.youtube.com/@iknowbrain
//      Github: https://github.com/iknowbrain
//      Bitcoin: 13jStC1PWwZttLc8rhG6Xn1UeKE7rAP6hQ

#ifndef STRING_H
#define STRING_H

#include "types.h"
uint16 strlength(string ch)
{
        uint16 i = 1;
        while(ch[i++]);  
        return --i;
}

/* Added in episode 3*/ /*This function compares two strings and returns true (1) if they are equal or false (0) if they are not equal */

uint8 strEql(string ch1,string ch2)                     
{
        uint8 result = 1;
        uint8 size = strlength(ch1);
        if(size != strlength(ch2)) result =0;
        else 
        {
        uint8 i = 0;
        for(i;i<=size;i++)
        {
                if(ch1[i] != ch2[i]) result = 0;
        }
        }
        return result;
}


#endif

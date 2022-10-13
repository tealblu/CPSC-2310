/** CPSC 2310 Lab 4

    Nibble routines

    Nibbles are 4-bit parts of a 32 bit unsigned integer variable.  
    Nibbles are numbered 0-7 from left to right.

    Charlie Hartsell
    Username: ckharts
    Lab Section 002
**/
#include "functions.h"


unsigned int nget(unsigned int val, int position) {
   unsigned int temp;

   switch(position) {
      case 0:
         temp = val & 0xF0000000;
         temp = temp >> 28;
         return temp;
      case 1:
         temp = val & 0xF000000;
         temp = temp >> 24;
         return temp;
      case 2:
         temp = val & 0xF00000;
         temp = temp >> 20;
         return temp;
      case 3:
         temp = val & 0xF0000;
         temp = temp >> 16;
         return temp;
      case 4:
         temp = val & 0xF000;
         temp = temp >> 12;
         return temp;
      case 5:
         temp = val & 0xF00;
         temp = temp >> 8;
         return temp;
      case 6:
         temp = val & 0xF0;
         temp = temp >> 4;
         return temp;
      case 7:
         temp = val & 0xF;
         // Don't shift
         return temp;
      default:
         return 0;
   }
}

unsigned int nset(unsigned int val, unsigned int nVal, int position) {
   switch(position) {
      case 0:
         val = val & 0x0FFFFFFF;
         nVal = nVal << 28;
         val = val | nVal;
         return val;
      case 1:
         val = val & 0xF0FFFFFF;
         nVal = nVal << 24;
         val = val | nVal;
         return val;
      case 2:
         val = val & 0xFF0FFFFF;
         nVal = nVal << 20;
         val = val | nVal;
         return val;
      case 3:
         val = val & 0xFFF0FFFF;
         nVal = nVal << 16;
         val = val | nVal;
         return val;
      case 4:
         val = val & 0xFFFF0FFF;
         nVal = nVal << 12;
         val = val | nVal;
         return val;
      case 5:
         val = val & 0xFFFFF0FF;
         nVal = nVal << 8;
         val = val | nVal;
         return val;
      case 6:
         val = val & 0xFFFFFF0F;
         nVal = nVal << 4;
         val = val | nVal;
         return val;
      case 7:
         val = val & 0xFFFFFFF0;
         // Don't shift
         val = val | nVal;
         return val;
      default:
            return 0;
   }
}

unsigned int nlrotate(unsigned int val) {
   unsigned int dropped;
   
   // Store the dropped bits
   dropped = val & 0xF0000000;
   dropped = dropped >> 28;

   // Left shift val by one nibble
   val = val << 4;

   // Add back in the dropped bits
   val = val | dropped;
   
   // Return the rotated value
   return val;
}

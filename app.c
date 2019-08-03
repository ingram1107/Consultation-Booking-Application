/* License: MIT License
 * Team Memeber:
 *    ingram1107
 *    laushunze
 *    limzhenbeng
 *    weegen12
 */

#include <stdio.h>

int main(void) {
    /*int dr_hidayati[][1] = {1, 2};*/
    char usr;

    do {    /* print out the lecturers' consultation hour table*/
      printf("\tLecturers' Consultation Hour\n\n");
      printf(" ---------------------------------------------\n");
      printf("| Dr. Hidayati\t|\tMon\t  |\t2-4pm |\n");
      printf("|\t\t|\tTues\t  |\t2-4pm |\n");
      printf("|---------------|-----------------|-----------|\n");
      printf("| Dr. Azlina\t|\tTues\t  |\t3-4pm |\n");
      printf("|\t\t|\tWed\t  |\t2-4pm |\n");
      printf("|\t\t|\tThur\t  |\t3-4pm |\n");
      printf(" ---------------------------------------------\n\n");
      printf("Press x then Enter to exit the program\n");
      scanf(" %c", &usr);
    } while (usr != 'x');   /* exit the program when user input 'x' */
    /*
     *  Lecturers' available consultation hour schedule
     *
     *  Dr Hidayati | Mon   | 2-4pm
     *              | Tues  | 2-4pm
     *  ---------------------------
     *  Dr Azlina   | Tues  | 3-4pm
     *              | Wed   | 2-4pm
     *              | Thur  | 3-4pm
     */
}

/* License: MIT License
 * Team Memeber:
 *    ingram1107
 *    laushunze
 *    limzhenbeng
 *    weegen12
 */

#include <stdio.h>
#include <string.h>

#define Mon	1
#define Tues	2
#define	Wed	3
#define Thurs	4
#define Fri	5
#define	Sat	6
#define Sun	0
#define MAXCHAR 100

/* creat block of struct to record student info	*/
struct student {
	char name[20];
	int stdid[10];
	char major[2];
};

/* record = struct student	*/
typedef struct student record;
record student1;

/* lecturers' available slot	*/
int dr_hidayati[][2] = {
		{Mon,	2},
		{Mon, 	3},
		{Tues, 	2},
		{Tues, 	3}
	};
int dr_azlina[][2] = {
		{Tues, 	3},
		{Wed,	2},
		{Wed,	3},
		{Thurs,	3},
	};
int *pL1 = &dr_hidayati[0][0];
int *pL2 = &dr_azlina[0][0];

void schedule(void);
void booking(void);
void command(void);
void info(void);
/*int check_available(char [])*/

int main(void) 
{
    	char usr;
	char *pUsr = &usr;

    	do {    
		schedule();
		command();
		scanf(" %c", pUsr);
		if (*pUsr == 'c') {
			booking();
			info();
			command();
			scanf(" %c", pUsr);
			if (*pUsr == 'x')
				break;
    		} else if (*pUsr == 'x') {
			printf("Exit the program.\n");
			printf("Thank for coming!");
		}
		else
			printf("Error: Unknown Command\n");
	} while (*pUsr != 'x');   /* exit the program when user input 'x' */
    	
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

/* command list	*/
void command(void)
{
	printf("Press x then Enter to exit the program\n");
	printf("Press c then Enter to book a ticket\n");
}

/* print out the lecturers' consultation hour table	*/
void schedule(void)
{
	printf("\tLecturers' Consultation Hour\n\n");
      	printf(" ---------------------------------------------\n");
      	printf("| Dr. Hidayati\t|\tMon\t  |\t2-4pm |\n");
      	printf("|\t\t|\tTues\t  |\t2-4pm |\n");
      	printf("|---------------|-----------------|-----------|\n");
      	printf("| Dr. Azlina\t|\tTues\t  |\t3-4pm |\n");
      	printf("|\t\t|\tWed\t  |\t2-4pm |\n");
      	printf("|\t\t|\tThur\t  |\t3-4pm |\n");
      	printf(" ---------------------------------------------\n\n");
}

/* allow booking	*/
void booking(void)
{
	int i, j, k;
	char cdr_hidayati[] = "Dr._Hidayati";
	char cdr_azlina[] = "Dr._Azlina";
	char s[MAXCHAR];

	printf("This is the booking session.\n");
	printf("Select a lecturer you pefer to meet (Use underscore to represent white spaces): ");
	scanf("%s", s);
	if (strcmp(s, cdr_hidayati) == 0) { /* compare the input of user to the available string*/
		printf("Monday = 0, Tuesday = 1\n");
		printf("Each block have 4 slot available\n");
		printf("Four block available\n");
		printf("Book a slot: ");
		scanf("%d %d", &i, &j);
		if (i == 0) {
			if (j == 0) {
			}
			else if (j == 1) {
			}
		}
	}
	else if (strcmp(s, cdr_azlina) == 0){
		printf("Book a slot: ");
	}
	else
		printf("Error: Unknown Lecturer\n");
	printf("Please check your ticket's information.\n");
	printf("Select slot from the schedule.");
}

/* scan user input	*/
void info(void)
{
	printf("Enter your name (Use underscore to represent white spaces): ");
	scanf("%s", student1.name);
	printf("Enter your student ID: ");
	scanf("%s", student1.stdid);
	printf("Enter your major (TE/ME/RE): ");
	scanf("%s", student1.major);
}

/* int check_available(char s[])	*/

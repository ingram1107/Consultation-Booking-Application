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
#define Sun	7
#define MAXCHAR 100
#define MAXSTD	100
#define FALSE	-1
#define	TRUE	0

/* creat block of struct to record student info	*/
int k = 0;
struct student {
	char name[20];
	int stdid[10];
	char major[2];
	char *lecturer;
	char weekday[9];
	int block;
	int slot;
};
struct student record[MAXSTD];

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
char cdr_hidayati[] = "Dr._Hidayati";
char cdr_azlina[] = "Dr._Azlina";
int *pL1_00 = &dr_hidayati[0][0];
int *pL1_01 = &dr_hidayati[0][1];
int *pL1_10 = &dr_hidayati[1][0];
int *pL1_11 = &dr_hidayati[1][1];
int *pL1_20 = &dr_hidayati[2][0];
int *pL1_21 = &dr_hidayati[2][1];
int *pL1_30 = &dr_hidayati[3][0];
int *pL1_31 = &dr_hidayati[3][1];
int *pL2_00 = &dr_azlina[0][0];
int *pL2_01 = &dr_azlina[0][1];
int *pL2_10 = &dr_azlina[1][0];
int *pL2_11 = &dr_azlina[1][1];
int *pL2_20 = &dr_azlina[2][0];
int *pL2_21 = &dr_azlina[2][1];
int *pL2_30 = &dr_azlina[3][0];
int *pL2_31 = &dr_azlina[3][1];

void schedule(void);
void booking(void);
void command(void);
void info(void);
void ticket(void);
int check_availability(int *);
int book_slot(int);
void show_slot(char *, char [], int, int);

int main(void) 
{
    	char usr;
	char *pUsr = &usr;

    	do {    
		schedule();
		command();
		scanf(" %c", pUsr);
		if (*pUsr == 'c')
			booking();
		else if (*pUsr == 'x') {
			printf("Exit the program.\n");
			printf("Thank for coming!");
			break;
		}
		else
			printf("Error: Unknown Command\n");
	} while (*pUsr != 'x')   /* exit the program when user input 'x' */
		;
    	
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
	int i;
	char s[MAXCHAR];
	int *pL1_00 = &dr_hidayati[0][0];
	int *pL1_01 = &dr_hidayati[0][1];
	int *pL1_10 = &dr_hidayati[1][0];
	int *pL1_11 = &dr_hidayati[1][0];


	printf("This is the booking session.\n");
	printf("Select a lecturer you pefer to meet (Use underscore to represent white spaces): ");
	scanf("%s", s);
	if (strcmp(s, cdr_hidayati) == 0) { /* compare the input of user to the available string*/
		printf("Monday = 1, Tuesday = 2\n");
		printf("Each block have 4 slot available\n");
		printf("Monday have 2 blocks\n");
		printf("Tuesday have 2 blocks\n");
		printf("Enter weekday and a block number below to book a slot\n");
		printf("Enter weekday: ");
		scanf("%d", &i);
		if (i == 1) {
			printf("Dr. Hidayati - Monday\n");
			printf("Block 1: 2pm - max 4 slots\n");
			printf("Block 2: 3pm - max 4 slots\n");
			printf("Enter block number: ");
			scanf("%d", &record[k].block);
			if (record[k].block == 1) {
				if (check_availability(pL1_01) == FALSE) {
					record[k].block = 0;
					booking();
				}
				else if (*pL1_00 == *pL1_10 == FALSE) {
					printf("Error: Current Weekday Full\n");
					record[k].block = 0;
					schedule();
					printf("Please select another weekday\n");
					booking();
				} else {
					*pL1_00 = *pL1_01 = FALSE;
					info();
					record[k].lecturer = cdr_hidayati;
					strcpy(record[k].weekday, "Monday");
					printf("Successful Booking!!\n");
				}
			} else if (record[k].block == 2) {
				if (check_availability(pL1_11) == FALSE) {
					record[k].block = 0;
					booking();
				}
				else if (*pL1_00 == *pL1_10 == FALSE) {
					printf("Error: Current Weekday Full\n");
					record[k].block = 0;
					schedule();
					printf("Please select another weekday\n");
					booking();
				} else {
					*pL1_10 = *pL1_11 = FALSE;
					info();
					record[k].lecturer = cdr_hidayati;
					strcpy(record[k].weekday, "Monday");
					printf("Successful Booking!!\n");
				}
			} else {
				printf("Error: Unknow Block\n");
				booking();
			}
		} else if (i == 2) {
			printf("Dr. Hidayati - Tuesday'\n");
			printf("Block 1: 2pm - max 4 slots");
			printf("Block 2: 3pm - max 4 slots");
			printf("Enter block number: ");
			scanf("%d", &record[k].block);
			if (record[k].block == 1) {
				if (check_availability(pL1_21) == FALSE) {
					record[k].block = 0;
					booking();
				}
				else if (*pL1_20 == *pL1_30 == FALSE) {
					printf("Error: Current Weekday Full\n");
					record[k].block = 0;
					schedule();
					printf("Please select another weekday\n");
					booking();
				} else {
					*pL1_20 = *pL1_21 = FALSE;
					info();
					record[k].lecturer = cdr_hidayati;
					strcpy(record[k].weekday, "Tuesday");
					printf("Successful Booking!!\n");
				}
			} else if (record[k].block == 2) {
				if (check_availability(pL1_31) == FALSE) {
					record[k].block = 0;
					booking();
				}
				else if (*pL1_20 == *pL1_30 == FALSE) {
					printf("Error: Current Weekday Full\n");
					record[k].block = 0;
					schedule();
					printf("Please select another weekday\n");
					booking();
				} else {
					*pL1_30 = *pL1_31 = FALSE;
					info();
					record[k].lecturer = cdr_hidayati;
					strcpy(record[k].weekday, "Tuesday");
					printf("Successful Booking!!\n");
				}
			} else {
				printf("Error: Unknow Block\n");
				booking();
			}
		}
	} else if (strcmp(s, cdr_azlina) == 0){
		printf("Tuesday = 2, Wednesday = 3, Thursday = 4\n");
		printf("Each block have 4 slot available\n");
		printf("Tuesday have 1 block\n");
		printf("Wednesday have 2 blocks\n");
		printf("Thursday have 1 block\n");
		printf("Enter weekday and a block number below to book a slot\n");
		printf("Enter weekday: ");
		scanf("%d", &i);
		if (i == 2) {
			printf("Dr. Azlina - Tuesday\n");
			printf("Default Block: 3pm - max 4 slots\n");
			if (check_availability(pL2_01) == FALSE)
				booking();
			else if (*pL2_00 == FALSE) {
				printf("Error: Current Weekday Full\n");
				schedule();
				printf("Please select another weekday\n");
				booking();
			} else {
				*pL2_00 = *pL2_01 = FALSE;
				info();
				record[k].lecturer = cdr_azlina;
				strcpy(record[k].weekday, "Tuesday");
				printf("Successful Booking!!\n");
			}
		} else if (i == 3) {
			printf("Dr. Azlina - Wednesday\n");
			printf("Block 1: 2pm - max 4 slots\n");
			printf("Block 2: 3pm - max 4 slots\n");
			printf("Enter block number: ");
			scanf("%d", &record[k].block);
			if (record[k].block == 1) {
				if (check_availability(pL2_11) == FALSE) {
					record[k].block = 0;
					booking();
				}
				else if (*pL2_10 == *pL2_20 == FALSE) {
					printf("Error: Current Weekday Full\n");
					record[k].block = 0;
					schedule();
					printf("Please select another weekday\n");
					booking();
				} else {
					*pL2_10 = *pL2_11 = FALSE;
					info();
					record[k].lecturer = cdr_azlina;
					strcpy(record[k].weekday, "Wednesday");
					printf("Successful Booking!!\n");
				}
			} else if (record[k].block == 2) {
				if (check_availability(pL2_21) == FALSE) {
					record[k].block = 0;
					booking();
				}
				else if (*pL2_10 == *pL2_20 == FALSE) {
					printf("Error: Current Weekday Full\n");
					record[k].block = 0;
					schedule();
					printf("Please select another weekday\n");
					booking();
				} else {
					*pL2_20 = *pL2_21 = FALSE;
					info();
					record[k].lecturer = cdr_azlina;
					strcpy(record[k].weekday, "Wednesday");
					printf("Successful Booking!!\n");
				}
			} else {
				printf("Error: Unknow Block\n");
				booking();
			}
		} else if (i == 4) {
			printf("Dr. Azlina - Thursday\n");
			printf("Default Block: 3pm - max 4 slots\n");
			if (check_availability(pL2_31) == FALSE)
				booking();
			else if (*pL2_30 == FALSE) {
				printf("Error: Current Weekday Full\n");
				schedule();
				printf("Please select another weekday\n");
				booking();
			} else {
				*pL2_30 = *pL2_31 = FALSE;
				info();
				record[k].lecturer = cdr_azlina;
				strcpy(record[k].weekday, "Thursday");
				printf("Successful Booking!!\n");
			}
		} else {
			printf("Error: Other Weekday Not Available\n");
			booking();
		}
	} else {
		printf("Error: Unknown Lecturer\n");
		booking();
	}
	printf("Please check your ticket's information.\n");
	ticket();
	k++;
}

/* scan user input	*/
void info(void)
{
	printf("Enter your name (Use underscore to represent white spaces): ");
	scanf("%s", record[k].name);
	printf("Enter your student ID: ");
	scanf("%s", record[k].stdid);
	printf("Enter your major (TE/ME/RE): ");
	scanf("%s", record[k].major);
}

void ticket(void)
{
	printf("Name\t\tStudent ID\tMajor\n");
	printf("%s\t%s\t%s\n\n", record[k].name, record[k].stdid, record[k].major);
	printf("Booked Schedule:\n");
	printf("Lecturer\tWeekday\t\n");
	printf("%s\t%s\t\n", record[k].lecturer, record[k].weekday);	
}

int check_availability(int *s)
{
	if (*s == FALSE) {
		printf("Error: Slot Full\n");
		schedule();
		printf("Please select another slot\n");
		return FALSE;
	} else
		return TRUE;
}

int book_slot(int i)
{
	int j = 0;

	j++;

	if (j > 4)
		return FALSE;
	else
		return i = j;
}

void show_slot(char *s, char t[], int i, int j)
{
	extern void booking(void);

	if (strcmp(s, cdr_hidayati) == 0) {
		if (t == "Monday") {
			if (i == 1) {
				switch (j) {
				case 1:
					printf("2:00pm - 2:15pm");
					break;
				case 2:
					printf("2:15pm - 2:30pm");
					break;
				case 3:
					printf("2:30pm - 2:45pm");
					break;
				case 4:
					printf("2:45pm - 3:00pm");
					break;
				default:
					printf("Error: Unknown Slot Time");
				}
			} else if (i == 2) {
				switch (j) {
				case 1:
					printf("3:00pm - 3:15pm");
					break;
				case 2:
					printf("3:15pm - 3:30pm");
					break;
				case 3:
					printf("3.30pm - 3.45pm");
					break;
				case 4:
					printf("3.45pm - 4:00pm");
					break;
				default:
					printf("Error: Unknown Slot Time");
				}
			}
		} else if (t == "Tuesday") {			
			if (i == 1) {
				switch (j) {
				case 1:
					printf("2:00pm - 2:15pm");
					break;
				case 2:
					printf("2:15pm - 2:30pm");
					break;
				case 3:
					printf("2:30pm - 2:45pm");
					break;
				case 4:
					printf("2:45pm - 3:00pm");
					break;
				default:
					printf("Error: Unknown Slot Time");
				}
			} else if (i == 2) {
				switch (j) {
				case 1:
					printf("3:00pm - 3:15pm");
					break;
				case 2:
					printf("3:15pm - 3:30pm");
					break;
				case 3:
					printf("3.30pm - 3.45pm");
					break;
				case 4:
					printf("3.45pm - 4:00pm");
					break;
				default:
					printf("Error: Unknown Slot Time");
				}
			}
		} else
			printf("Error: Weekday Not Available");
	} else if (strcmp(s, cdr_azlina) == 0) {
		if (t == "Tuesday") {
			switch (j) {
			case 1:
				printf("3:00pm - 3:15pm");
				break;
			case 2:
				printf("3:15pm - 3:30pm");
				break;
			case 3:
				printf("3:30pm - 3.45pm");
				break;
			case 4:
				printf("3.45pm - 4.00pm");
				break;
			default:
				printf("Error: Unknown Slot Time");
			}
		} else if (t == "Wednesday") {			
			if (i == 1) {
				switch (j) {
				case 1:
					printf("2:00pm - 2:15pm");
					break;
				case 2:
					printf("2:15pm - 2:30pm");
					break;
				case 3:
					printf("2:30pm - 2:45pm");
					break;
				case 4:
					printf("2:45pm - 3:00pm");
					break;
				default:
					printf("Error: Unknown Slot Time");
				}
			} else if (i == 2) {
				switch (j) {
				case 1:
					printf("3:00pm - 3:15pm");
					break;
				case 2:
					printf("3:15pm - 3:30pm");
					break;
				case 3:
					printf("3.30pm - 3.45pm");
					break;
				case 4:
					printf("3.45pm - 4:00pm");
					break;
				default:
					printf("Error: Unknown Slot Time");
				}
			}

		} else if (t == "Thursday") {
			switch (j) {
			case 1:
				printf("3:00pm - 3:15pm");
				break;
			case 2:
				printf("3.15pm - 3.30pm");
				break;
			case 3:
				printf("3.30pm - 3.45pm");
				break;
			case 4:
				printf("3.45pm - 4:00pm");
				break;
			default:
				printf("Error: Unknown Slot Time");
			}
		} else
			printf("Error: Weekday Not Available");
	}
}

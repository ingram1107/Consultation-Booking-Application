/* License: MIT License
 * Team Member:
 * 	ingram1107
 * 	laushunze
 * 	limzhenbang
 * 	weegen12
 */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define	NOTAVAI	0
#define FALSE	-1
#define MAX	8

struct student {
	char name[20];
	int stdid[10];
	char major[2];
	char *lecturer;
	char weekday[9];
	int slot;
	char *time;
};
struct student record[100];
int k = -1;

int dr_hidayati[][MAX] = {
	{NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI},
	{1400, 1415, 1430, 1445, 1500, 1515, 1530, 1545},
	{1400, 1415, 1430, 1445, 1500, 1515, 1530, 1545},
	{NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI},
	{NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI},
	{NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI},
	{NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI},
};

int dr_azlina[][MAX] = {
	{NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI},
	{NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI},
	{NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, 1500, 1515, 1530, 1545},
	{1400, 1415, 1430, 1445, 1500, 1515, 1530, 1545},
	{NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, 1500, 1515, 1530, 1545},
	{NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI},
	{NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI, NOTAVAI},
};

char lec1[] = "Dr. Hidayati";
char lec2[] = "Dr. Azlina";

int display_slot(void);
int book_slot(void);
void command(char *);
void stud_rec(void);
int display_ticket(void);
char *show_slot(int);
int check(int [][MAX], int);
int calc(int [][MAX], int);
int schedule(FILE *);
int clear(void);
//int store(int [][MAX], FILE *);

int main(void)
{
	char cmd;

	do 
		command(&cmd);
	while (cmd != 'x');
	
	return 0;
}

void command(char *s)
{
	printf("\n\tMain Menu\n");
	printf("b -> Book Ticket\n");
	printf("c -> Clear File's Content\n");
	printf("s -> Display Available Slot\n");
	printf("t -> Display Ticket\n");
	printf("x -> Exit Program\n\n");
	printf("Please enter a command: ");
	scanf(" %c", s);
	switch (*s) {
	case 'b':
		book_slot();
		break;
	case 'c':
		clear();
		break;
	case 's':
		display_slot();
		break;
	case 't':
		display_ticket();
		break;
	case 'x':
		printf("Exit Program\n");
		break;
	default:
		printf("Error: Unknown Command\n");
		break;
	}
}

int display_slot(void)
{
	/*FILE *fstore1 = fopen("data1.txt", "r");
	FILE *fstore2 = fopen("data2.txt", "r");

	if (fstore1 == NULL || fstore2 == NULL) {
		printf("Error: Fail to access the previous data\n");
		return 1;
	}

	int a = calc(dr_hidayati, 1);
	int b = calc(dr_hidayati, 2);
	int c = calc(dr_azlina, 2);
	int d = calc(dr_azlina, 3);
	int e = calc(dr_azlina, 4);

	fclose(fstore1);
	fclose(fstore2);
	*/

	int read = 0;
	char f;
	FILE *fptr = fopen("time table.txt", "w+");

	if (fptr == NULL) {
		printf("Error: Fail to open \'time table.txt\'");
		return 1;		
	}
	
	fprintf(fptr, "\tLecturers' Consultation Hour\n\n");
	fprintf(fptr, "Lecturer\tWeekday\t\tTime\n");
	fprintf(fptr, "Dr. Hidayati\tMonday\t\t2-4pm\n");
	fprintf(fptr, "\t\tTuesday\t\t2-4pm\n");
	fprintf(fptr, "Dr. Azlina\tTuesday\t\t3-4pm\n");
	fprintf(fptr, "\t\tWednesday\t2-4pm\n");
	fprintf(fptr, "\t\tThursday\t3-4pm\n\n");
	
	fseek(fptr, read, SEEK_SET);
	f = fgetc(fptr);
	while (f != EOF) {
		printf("%c", f);
		f = fgetc(fptr);
	}

	fclose(fptr);
	return 0;
}

int book_slot(void)
{
	char lecname[20];
	char temp, cmd;
	int i, j;
	FILE *fl1 = fopen("dr hidayati.txt", "a+");
	FILE *fl2 = fopen("dr azlina.txt", "a+");
	
	/*FILE *fstore1 = fopen("data1.txt", "w+");
	FILE *fstore2 = fopen("data2.txt", "w+");
	*/

	printf("\n\tWelcome to the booking session.\n");
	printf("All inputs are CASE SENSITIVE\n");
	printf("Please enter lecturer's name who you pefer to meet: ");
	scanf("%c", &temp);
	scanf("%[^\n]", lecname);
	printf("\n");

	if (strcmp(lecname, lec1) == 0) {
		printf("\tDr. Hidayati Session\n");
		printf("Weekday\t\tTime\n");
		printf("Monday\t\t2-4pm\n");
		printf("Tuesday\t\t2-4pm\n");
		printf("\n\tNumber Menu\n");
		printf("1 -> Select Monday\n");
		printf("2 -> Select Tuesday\n");
		printf("Please choose a weekday: ");
		scanf("%d", &i);
		printf("\n");
		if (i == 1) {
			if (check(dr_hidayati, i) == FALSE) {
				printf("Error: Not available\n");
				book_slot();
			} else {
				stud_rec();
				record[k].lecturer = lec1;
				strcpy(record[k].weekday, "Monday");
				j = check(dr_hidayati, i);
				record[k].slot = j;
				record[k].time = show_slot(record[k].slot);
				dr_hidayati[i][j] = NOTAVAI;
				schedule(fl1);
				//store(dr_hidayati, fstore1);
				printf("Successful Booking\n");
				printf("\n");
				return 0;
			}
		} else if (i == 2) {
			if (check(dr_hidayati, i) == FALSE) {
				printf("Error: Not available\n");
				book_slot();
			}
			else {
				stud_rec();
				record[k].lecturer = lec1;
				strcpy(record[k].weekday, "Tuesday");
				j = check(dr_hidayati, i);
				record[k].slot = j;
				record[k].time = show_slot(record[k].slot);
				dr_hidayati[i][j] = NOTAVAI;
				schedule(fl1);
				//store(dr_hidayati, fstore1);
				printf("Successful Booking\n");
				printf("\n");
				return 0;
			}
		} else {
			printf("Error: Not available\n");
			return 1;
		}
	}
	else if (strcmp(lecname, lec2) == 0) {
		printf("\tDr. Azlina Session\n");
		printf("Weekday\t\tTime\n");
		printf("Tuesday\t\t3-4pm\n");
		printf("Wednesday\t\t2-4pm\n");
		printf("Thursday\t\t3-4pm\n");
		printf("\n\tNumber Menu\n");
		printf("2 -> Select Tuesday\n");
		printf("3 -> Select Wednesday\n");
		printf("4 -> Select Thursday\n");
		printf("Please choose a weekday: ");
		scanf("%d", &i);
		printf("\n");
		if (i == 2) {
			if (check(dr_azlina, i) == FALSE) {
				printf("Error: Not available\n");
				book_slot();
			} else {
				stud_rec();
				record[k].lecturer = lec2;
				strcpy(record[k].weekday, "Tuesday");
				j = check(dr_azlina, i);
				record[k].slot = j;
				record[k].time = show_slot(record[k].slot);
				dr_azlina[i][j] = NOTAVAI;
				schedule(fl2);
				//store(dr_azlina, fstore2);
				printf("Successful Booking\n");
				printf("\n");
				return 0;
			}
		} else if (i == 3) {
			if (check(dr_azlina, i) == FALSE) {
				printf("Error: Not available\n");
				book_slot();
			}
			else {
				stud_rec();
				record[k].lecturer = lec2;
				strcpy(record[k].weekday, "Wednesday");
				j = check(dr_azlina, i);
				record[k].slot = j;
				record[k].time = show_slot(record[k].slot);
				dr_azlina[i][j] = NOTAVAI;
				schedule(fl2);
				//store(dr_azlina, fstore2);
				printf("Successful Booking\n");
				printf("\n");
				return 0;
			}
		} else if (i == 4) {
			if (check(dr_azlina, i) == FALSE) {
				printf("Error: Not available\n");
				book_slot();
			}
			else {
				stud_rec();
				record[k].lecturer = lec2;
				strcpy(record[k].weekday, "Thursday");
				j = check(dr_azlina, i);
				record[k].slot = j;
				record[k].time = show_slot(record[k].slot);
				dr_azlina[i][j] = NOTAVAI;
				schedule(fl2);
				//store(dr_azlina, fstore2);
				printf("Successful Booking\n");
				printf("\n");
				return 0;
			}
		} else {
			printf("Error: Not available\n");
			return 1;
		}
	} else {
		printf("Error: Unknown lecturer\n");
		return 1;
	}
}

int check(int s[][MAX], int rows)
{
	int j;

	for (j = 0; j < MAX; j++)
		if (s[rows][j] != NOTAVAI)
			return j;

	return FALSE;
}

void stud_rec(void)
{
	char temp;
	
	printf("Please enter your full name: ");
	scanf("%c", &temp);
	scanf("%[^\n]", record[k].name);
	printf("Please enter your student ID: ");
	scanf("%s", record[k].stdid);

	for (;;) {
		printf("Please enter your major (TE/ME/RE): ");
		scanf("%s", record[k].major);
		if (strcmp(record[k].major,"TE")==0||strcmp(record[k].major,"ME")==0||strcmp(record[k].major,"RE")==0)
			break;
		printf("Error: Unmatch major\n");
	}
}

int display_ticket(void)
{
	int read = 0;
	char c;
	struct student *ptr = &record[k];
	FILE *fptr = fopen("ticket.txt", "w+");

	if (fptr == NULL) {
		printf("Error: Fail to open \'ticket.txt\'\n");
		return 1;
	}

	if ((ptr->lecturer) == NULL) {
		printf("Error: Ticket doesn't exist\n");
		return 1;
	}

	fprintf(fptr, "\n\tTicket\n");
	fprintf(fptr, "Name\t\tStudent ID\tMajor\n");
	fprintf(fptr, "%s\t%s\t%s\n", ptr->name, ptr->stdid, ptr->major);
	fprintf(fptr, "-----\n");
	fprintf(fptr, "Lecturer\tWeekday\t\tTime\n");
	fprintf(fptr, "%s\t%s\t\t%s\n", ptr->lecturer, ptr->weekday, ptr->time);

	fseek(fptr, read, SEEK_SET);
	c = fgetc(fptr);
	while (c != EOF) {
		printf("%c", c);
		c = fgetc(fptr);
	}

	fclose(fptr);
	return 0;
}

char *show_slot(int slot)
{
	switch (slot) {
	case 0:
		return "1400 - 1415\n";
	case 1:
		return "1415 - 1430\n";
	case 2:
		return "1430 - 1445\n";
	case 3:
		return "1445 - 1500\n";
	case 4:
		return "1500 - 1515\n";
	case 5:
		return "1515 - 1530\n";
	case 6:
		return "1530 - 1545\n";
	case 7:
		return "1545 - 1600\n";
	}	
}

/*int calc(int s[][MAX], int row)
{
	int j, count;
	
	int *ptr1 = &s[row][0];
	int *ptr2 = &s[row][1];
	int *ptr3 = &s[row][2];
	int *ptr4 = &s[row][3];
	int *ptr5 = &s[row][4];
	int *ptr6 = &s[row][5];
	int *ptr7 = &s[row][6];
	int *ptr8 = &s[row][7];
	

	if (fptr == NULL) {
		printf("Error: Fail to access the previous data\n");
		return 1;
	}

	fseek(fptr, row+1, SEEK_SET);

	if (fscanf(fptr, "%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d", ptr1, ptr2, ptr3, ptr4, ptr5, ptr6, ptr7, ptr8) == 8) {
		for (j = 0, count = 0; j < MAX; j++) {
			if (s[row][j] == NOTAVAI)
				continue;
			count++;
		}
	}

	fclose(fptr);
	return count;
}*/

int schedule(FILE *fptr)
{
	struct student *ptr = &record[k];

	if (fptr == NULL) {
		printf("Error: Fail to open lecturer's file\n");
		return 1;
	}

	while (!feof(fptr))
		fgetc(fptr);

	fprintf(fptr , "%s\t%s\t%s\t%s\t%s", ptr->stdid, ptr->name, ptr->major, ptr->weekday, ptr->time);

	fclose(fptr);
	return 0;
}

/*int store(int s[][MAX], FILE *fptr)
{
	int i, j;

	if (fptr == NULL) {
		printf("Error: Fail to access the previous data\n");
		return 1;
	}

	for (i = 0; i < 7; i++) {
		for (j = 0; j < MAX; j++)
			fprintf(fptr, "%d\t", s[i][j]);
		fprintf(fptr, "\n");
	}
	
	fclose(fptr);
	return 0;
}*/

int clear(void)
{
	char temp, opt;
	char file[20];

	printf("\n\tClear Option\n");
	printf("1. dr hidayati.txt\n");
	printf("2. dr azlina.txt\n");
	printf("Please enter the file's full name you want to clear: ");
	scanf("%c", &temp);
	scanf("%[^\n]", file);
	printf("Do you want to clear this file? (y/n)");
	scanf("%c", &temp);
	printf(" ");
	scanf("%[^\n]", &opt);

	if (opt == 'y' || opt == 'Y') {
		FILE *fptr = fopen(file, "w");
		if (fptr == NULL) {
			printf("Error: Fail to open \'%s\'\n", file);
			return 1;
		}
		fclose(fptr);
		return 0;
	} else if (opt == 'n' || opt == 'N') {
		printf("Exit from Clear Menu\n");
		return 0;
	} else {
		printf("Error: Unknown option");
		return 1;
	}
}

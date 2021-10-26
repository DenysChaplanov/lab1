#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>


struct student {
	char last_name[12];
	unsigned int number_of_group;
	unsigned int web;
	unsigned int ukr;
	unsigned int proekt;
};

//n - number of students
int n = 0;

void addElement(struct student** ptr_students);
void searchOnDebt(struct student* students);
void percentOfStudents(struct student* students);
void bestSubject(struct student* students);
void worstGroup(struct student* students);

int main() {
	int i;

	struct student* students;
	students = (struct student*)malloc(n * sizeof(struct student));

	//k - number of case, p - data in case
	int k;

	while (1) {

		printf("1 - add student\n2 - search student on debt\n3 - percentage of students\n4 - best subject\n5 - worst group\n0 - return\n");

		//scan case
		scanf("%d", &k);

		switch (k) {
		case 1: {
			system("cls");
			/* Add student */
			addElement(&students);
			break;
		}

		case 2: {
			/* Search */
			system("cls");
			searchOnDebt(students);
			break;
		}
		case 3: {
			/* Percentage of students */
			system("cls");
			percentOfStudents(students);
			break;
		}
		case 4: {
			/* Print */
			system("cls");
			bestSubject(students);
			break;
		}
		case 5: {
			/* Print */
			system("cls");
			worstGroup(students);
			break;
		}
		case 0: {
			system("cls");
			printf("Exit!\n");
			return 0;
		}
		}
	}

	return 0;
}



void addElement(struct student** ptr_students) {
	//do more size 
	n++;
	// add
	*ptr_students = (struct student*)realloc(*ptr_students, n * sizeof(struct student));

	struct student* students = *ptr_students;

	//put values

	printf("Enter student surname: \n");
	scanf("%s", students[n - 1].last_name);

	do {
		printf("Enter student group (from 1 to 4): \n");
		scanf("%u", &students[n - 1].number_of_group);
	} while ((students[n - 1].number_of_group < 1) || (students[n - 1].number_of_group > 4));

	printf("Enter student mark on web: \n");
	scanf("%u", &students[n - 1].web);

	printf("Enter student mark on ukr: \n");
	scanf("%u", &students[n - 1].ukr);

	printf("Enter student mark on proekt: \n");
	scanf("%u", &students[n - 1].proekt);
}

void searchOnDebt(struct student* students) {
	int i;
	printf("Surname   ---   Group   ---   Web   ---   Ukr   ---   Proekt\n");
	for (i = 0; i < n; i++) {
		if (students[i].web < 50 || students[i].ukr < 50 || students[i].proekt < 50) {
			printf("%s\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n", students[i].last_name, students[i].number_of_group, students[i].web, students[i].ukr, students[i].proekt);
		}
	}
}

void percentOfStudents(struct student* students) {
	int i;
	int kol4 = 0, kol5 = 0;
	int percent_4, percent_5;
	for (i = 0; i < n; i++) {
		if (students[i].web >= 70 && students[i].web <= 89 || students[i].ukr >= 70 && students[i].ukr <= 89 || students[i].proekt >= 70 && students[i].proekt <= 89) {
			kol4++;
		}
	}
	for (i = 0; i < n; i++) {
		if (students[i].web >= 90 && students[i].web <= 100 || students[i].ukr >= 90 && students[i].ukr <= 100 || students[i].proekt >= 90 && students[i].proekt <= 100) {
			kol5++;
		}
	}
	percent_4 = (kol4 * 100) / n;
	percent_5 = (kol5 * 100) / n;
	printf("Percentage of those who received 4 = %d%%\n", percent_4);
	printf("Percentage of those who received 5 = %d%%\n", percent_5);
}

void bestSubject(struct student* students) {
	int i;
	int mark_web = 0, mark_ukr = 0, mark_proekt = 0;
	for (i = 0; i < n; i++) {
		mark_web += students[i].web;
		mark_ukr += students[i].ukr;
		mark_proekt += students[i].proekt;
	}
	if (mark_web > mark_ukr && mark_web > mark_proekt)
		printf("Best subject: WEB\n");
	else if (mark_ukr > mark_web && mark_ukr > mark_proekt)
		printf("Best subject: UKR\n");
	else if (mark_proekt > mark_web && mark_proekt > mark_ukr)
		printf("Best subject: PROEKT\n");
	else
		printf("There is no ONE better\n");
}

void worstGroup(struct student* students) {
	int i;
	int mark_1 = 0, mark_2 = 0, mark_3 = 0, mark_4 = 0;
	int kol1 = 0, kol2 = 0, kol3 = 0, kol4 = 0;
	for (i = 0; i < n; i++) {
		if (students[i].number_of_group == 1) {
			mark_1 += students[i].web + students[i].ukr + students[i].proekt;
			kol1++;
		}
		else if (students[i].number_of_group == 2) {
			mark_2 += students[i].web + students[i].ukr + students[i].proekt;
			kol2++;
		}
		else if (students[i].number_of_group == 3) {
			mark_3 += students[i].web + students[i].ukr + students[i].proekt;
			kol3++;
		}
		else if (students[i].number_of_group == 4) {
			mark_4 += students[i].web + students[i].ukr + students[i].proekt;
			kol4++;
		}
	}

	if (mark_1 < mark_2 && mark_1 < mark_3 && mark_1 < mark_4)
		printf("Worst group is: FIRST\n");
	else if (mark_2 < mark_1 && mark_2 < mark_3 && mark_2 < mark_4)
		printf("Worst group is: SECOND\n");
	else if (mark_3 < mark_1 && mark_3 < mark_2 && mark_3 < mark_4)
		printf("Worst group is: THIRD\n");
	else if (mark_4 < mark_1 && mark_4 < mark_2 && mark_4 < mark_3)
		printf("Worst group is: FOURTH\n");
	else
		printf("There is no ONE worse group");
}
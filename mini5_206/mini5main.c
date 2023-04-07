#include<stdio.h>
#include<string.h>
#include "mini5.h"


int menu() {
	int selection;
	char garbage[5];

	printf("Phonebook Menu: (1)Add, (2)Delete/Clear, (3)Find, (4)List, (5)Quit > ");
	scanf("%d", &selection);
	fgets(garbage,4,stdin);

	return selection;
}

int main() {
	int choice, record;
	char name[50], birth[50], phone[50];

	loadCSV("phonebook.csv");

	do {
		choice = menu();

		switch(choice) {
			case 1:
				printf("Name: ");  fgets(name,49,stdin);  name[strlen(name)-1]   = '\0';
				printf("Birth: "); fgets(birth,12,stdin); birth[strlen(birth)-1] = '\0';
				printf("Phone: "); fgets(phone,14,stdin); phone[strlen(phone)-1] = '\0';

				addRecord(name, birth, phone);

				break;
            case 2:
                //delete & clear, Jon's job
			case 3: // Roko's job
				printf("Find name: "); fgets(name,49,stdin); name[strlen(name)-1] = '\0';
				break;

			case 4:
				record = listRecords();

				if (record != 0) printf("Phonebook.csv does not exist\n");
				break;

			case 5:
				break;

			default:
				printf("Invalid menu selection\n");
		}
	} while(choice != 5);

	if(saveCSV("phonebook.csv")) printf("The phonebook is empty");

	printf("End of phonebook program\n");

	return 0;
}


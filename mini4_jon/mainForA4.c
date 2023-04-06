#include <stdio.h>
#include <string.h>
#include "phoneForA4.c"

int menu() {
    struct PHONE_RECORD phonebook[10];
    loadCSV(phonebook);
    int choiceInt;
    printf("Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit>");
    scanf("%d", &choiceInt);

        while (choiceInt != 4) {
        switch (choiceInt) {
            case 1:
                struct PHONE_RECORD tempbook;
                printf("Name: ");
                fgets(tempbook.name, 50, stdin);
                printf("Birthday: ");
                fgets(tempbook.birthday, 12, stdin);
                printf("Phone: ");
                fgets(tempbook.phone, 15, stdin);
                addRecord(phonebook, tempbook);
                break;

            case 2:
                char findName[50];
                fgets(findName, 50, stdin);
                findRecord(phonebook, findName);
                break;

            case 3:
                listRecord(phonebook);
                break;
            
            default:
                break;
        }

        printf("Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit>");
        scanf("%d", &choiceInt);
    }
    saveCSV(phonebook);
    printf("End of phonebook program");
    return 0;
}

int main() {
    menu();
}
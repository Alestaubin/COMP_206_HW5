#include <stdio.h>
#include <string.h>
// #include <phoneForA4.c>

int menu() {
    int size;
    printf("Size of phonebook: ");
    scanf("%d", &size);

    struct PHONE_RECORD *phonebook = (struct PHONE_RECORD*) malloc(size * sizeof(struct PHONE_RECORD));
    
    loadCSV(phonebook);
    int choiceInt;
    printf("Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit>");
    scanf("%d", &choiceInt);

        while (choice != 4) {
        switch (choiceInt) {
            case 1:
                struct PHONE_RECORD tempbook;
                printf("Name: ");
                fgets(tempbook.name, 50, stdin);
                printf("Birthday: ");
                fgets(tempbook.birthday, 12, stdin);
                printf("Phone: ");
                fgets(tempbook.phone, 15, stdin);
                addRecord(phonebook, tempbook, size);
                break;

            case 2:
                char findName[50];
                fgets(findName, 50, stdin);
                findRecord(phonebook, findName, size);
                break;

            case 3:
                listRecord(phonebook, size);
                break;
            
            default:
                break;
        }

        printf("Phonebook Menu: (1)Add, (2)Find, (3)List, (4)Quit>");
        scanf("%d", &choiceInt);
    }
    saveCSV(phonebook, size);
    free(phonebook);
    printf("End of phonebook program");
    return 0;
}

int main() {
    menu();
}
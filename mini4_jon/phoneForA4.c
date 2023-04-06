#include <stdio.h>
#include <string.h>

struct PHONE_RECORD {
    char name[50];
    char birthday[12];
    char phone[15];
} ;

int loadCSV(struct PHONE_RECORD *phonebook) {
    char array[1000];
    FILE *p = fopen("phonebook.csv", "rt");
    if (p != NULL) {
    
        fgets(array, 999, p); // Read the first line of the CSV and increment.

        int k = 0;
        while(!feof(p) && k < 10){
            fgets(array, 999, p);

            int i;
            for (i = 0; i < 50 && array[i] != ',', i++){
                phonebook[k].name[i] = array[i]; 
            }
            phonebook[k].name[i] = '\0';
            i++;

            int j;
            for (j = 0; j < 12 && array[i] != ','; i++, j++){
                phonebook[k].birthday[j] = array[i];
            }
            phonebook[k].birthday[j] = '\0';
            i++;

            for (int l = 0; l < 15 && (array[i] != '\n' && array[i] != '\r'); i++, l++) {
                phonebook[k].phone[l] = array[i];
            }
            phonebook[k].phone[l] = '\0';
            k++; // incrementing k to add a new contact.

        }
    }
    fclose(p);
    return 0;
}

int saveCSV(struct PHONE_RECORD *phonebook) {
    FILE *j = fopen("phonebook.csv", "wt"); // overwriting the file with the current phonebook.
        fprintf(j, "Name,birthdate,phone\n");
        for (int i = 0; i < 10; i++) {
            if (phonebook[i].name[0] != '\0') {
                fprintf(j, "%s,%s,%s\n", phonebook[i].name, phonebook[i].birthday, phonebook[i].phone);
            }
        }
        
        fclose(j);
        return 0;
}

int addRecord(struct PHONE_RECORD *phonebook, struct PHONE_RECORD newRecord) { // 
    int i = 0;
    int filled = 0;
    while (i < 10) {
        
        if (phonebook[i].name[0] == '\0') {
            filled = 1; // we are checking to see that we have space in the phonebook. 
            phonebook[i] = newRecord;
            
            break;
        }

        i++;
    }

    if ( filled == 1) { // there is space, so we add the inputted struct to the phonebook. 
        return 0;
    } else {
        printf("No more space in the CSV file.");
        return 1;
    }
}

int findRecord(struct PHONE_RECORD *phonebook, char nameFind[50]) {
    printf("Find name: %s\n", nameFind);
    for (int i = 0; i < 10; i++) {
        if (strcmp(phonebook[i].name, nameFind) == 0) { // record exists in the phonebook.
            printf("%-20s %-15s %-15s\n", "----NAME---------", "------BIRTH------", "-----PHONE-------");
            printf("%-20s %-15s %-15s\n", phonebook[i].name, phonebook[i].birthday, phonebook[i].phone); // printing the record.
            return 0;
        }
    }
    printf("Does not exist"); // we have not found a record matching the name inputted. 
    return 1;
}

int listRecord(struct PHONE_RECORD *phonebook) {
    if (phonebook[0].name[0] == '\0') {
        printf("Phonebook.csv does not exist");
        return 1;
    } 
    printf("%-20s %-15s %-15s\n", "----NAME---------", "------BIRTH------", "-----PHONE-------"); // setting up the proper format.
    for (int i = 0; i < 10; i++) {
        if (phonebook[i].name[0] != '\0') {
            printf("%-20s %-16s %-15s\n", phonebook[i].name, phonebook[i].birthday, phonebook[i].phone);
        }
    }
    return 0;
}


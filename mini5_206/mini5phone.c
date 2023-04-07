#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct PHONE_NODE {
 char name[50];
 char birthdate[12];
 char phone[15];
 struct PHONE_NODE *next;
}head1;


int isEmptyCSV = 1; // assume empty

int delete(); // Jon

int clear(); // Jon


int loadCSV(char *filename) {
	FILE *p = fopen(filename, "rt");
	char buffer[1000];
	int i,j;

	if (p == NULL) {
		isEmptyCSV = 1; // make true
		return 1; // error code
	}

	// otherwise, the file is open, read CSV
	
	fgets(buffer,999,p); // to read the CSV header (we discard it)

	if(fgets(buffer,999,p) == NULL){
        // the file contains a header but no contacts
        isEmptyCSV = 1;
        return 1;
    }
    isEmptyCSV = 0; 
    head1.next = NULL; 
    struct PHONE_NODE *tail;
    struct PHONE_NODE *head;	
    head = &head1;
    // parse the CSV record
	for(int k = 0 ; !feof(p) ; k++) {
        // Initialize a new node in the singly linked list.
        struct PHONE_NODE *pNode;
        if (k == 0){
            // Initialize the head node.
            pNode = head; 
            pNode->next = NULL;
        }else{
            // Allocate memory to a struct pointer that will be filled with the information on the current line of the csv file.
            pNode = malloc(sizeof(struct PHONE_NODE));
            // assign the field *next from the tail node to the current node
            tail->next = malloc(sizeof(struct PHONE_NODE));
            tail->next = pNode;
            pNode->next = NULL;
        }
        // assign tail variable to current node
        tail = pNode; 

		for(j=0,i=0;i<999&&buffer[i]!='\0'&&buffer[i]!=',';i++,j++)
			pNode->name[j]=buffer[i];

		pNode->name[j]='\0';
		i++;

		for(j=0;i<999&&buffer[i]!='\0'&&buffer[i]!=',';i++,j++)
			pNode->birthdate[j]=buffer[i];

		pNode->birthdate[j]='\0';
		i++;

		for(j=0;i<999&&buffer[i]!='\0'&&buffer[i]!='\n';i++,j++)
			pNode->phone[j]=buffer[i];

		pNode->phone[j]='\0';
        
		// Get the next record
		fgets(buffer,999,p);
	}

	fclose(p);

	return 0;
}

int saveCSV(char *filename) {
	FILE *p = fopen(filename,"wt");
	int i;

	if (p == NULL) return 1; // error code

	fprintf(p,"name,birthdate,phone\n");
    
    struct PHONE_NODE *pNode = &head1;
    if (isEmptyCSV) return 1; // Phonebook is empty
                                 
    // Loop through singly linked list of struct PHONE_NODE, printing each node's fields to the csv file.
    while(pNode != NULL){
		fprintf(p,"%s,%s,%s\n", pNode->name, pNode->birthdate, pNode->phone);
        pNode = pNode->next;
    }
	fclose(p);

	return 0;
}

int addRecord(char name[], char birth[], char phone[]) {
    // First need to get to the last node of the list
    struct PHONE_NODE *pNode;
    for (pNode = &head1 ; pNode->next != NULL ; pNode = pNode->next);
    // Allocate memory for new node 
    struct PHONE_NODE *pNewNode = malloc(sizeof(struct PHONE_NODE)); 
    pNode->next = malloc(sizeof(struct PHONE_NODE));
    pNode->next = pNewNode;
    pNewNode->next = NULL;

	strcpy(pNewNode->name, name);
	strcpy(pNewNode->birthdate, birth);
	strcpy(pNewNode->phone, phone);

	isEmptyCSV = 0;

	return 0;
}

int findRecord(char name[]); //Roko's job 

void printHeading() {
	 printf("---- NAME ---- ---- BIRTH DATE ---- ---- PHONE ----\n");
}

void printContent(char *name, char *birth, char *phone) {
	printf("%-14s %-20s %-10s\n", name, birth, phone);
}

int listRecords() {
	int i;

	if (isEmptyCSV) {
        return 1; // Double check this, not sure it works
    }

	printHeading();
    
    for (struct PHONE_NODE *pNode = &head1 ; pNode != NULL ; pNode = pNode->next){
		printContent(pNode->name, pNode->birthdate, pNode->phone);
    }

	return 0;	
}


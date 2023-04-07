#ifndef MINI5_H
#define MINI5_H

int loadCSV(char *filename);

int saveCSV(char *filename);

int addRecord(char name[], char birth[], char phone[]);

int findRecord(char name[]);

void printHeading();

void printContent(char *name, char *birth, char *phone);

int listRecords();

#endif 

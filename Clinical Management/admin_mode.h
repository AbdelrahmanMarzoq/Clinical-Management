#ifndef ADMIN_MODE_H
#define ADMIN_MODE_H

#include <stdlib.h>

#define MAX_PATIENT 50


#define ADD_PATIENT  1
#define EDIT_PATIENT 2
#define RESERVE_SLOT 3
#define CANCE_RESERVATION 4



typedef char boolean;

typedef struct {
    char Name[30];
    char gender[10];
    long long ID;
    int Slot;
    char age;
}Patient;


typedef enum
{
    notExist,
    Exist
}Existing;

Patient *sizeClinic[MAX_PATIENT];


void addNewPatient();

Existing exist_ID(long long ID, int *Pos);

int available_slot();

boolean reserve_slot(int Pos, int Type);

void cancel_Reservation(int Pos);

#endif // ADMIN_MODE_H




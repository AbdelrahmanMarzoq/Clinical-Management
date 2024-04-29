#include "user_mode.h"


void print_data(Pos)
{
    printf("Patient Name   : %s  \n",&(sizeClinic[Pos]->Name));
    printf("Patient Gender : %s  \n",&(sizeClinic[Pos]->gender));
    printf("Patient Age    : %d  \n",sizeClinic[Pos]->age);
    printf("Patient ID     : %ld \n",sizeClinic[Pos]->ID);
}

void print_time(Pos)
{
    int Type = sizeClinic[Pos]->Slot;
    if (Type == -1)
    {
        printf("No Reservation related to (%d) ", sizeClinic[Pos]->ID);
    }
    else if (Type == 1)
    {
        printf("2pm -> 2:30pm reserved to (%d)", sizeClinic[Pos]->ID);
    }
    else if (Type == 2)
    {
        printf("2:30pm -> 3pm reserved to (%d)", sizeClinic[Pos]->ID);
    }
    else if (Type == 3)
    {
        printf("3pm -> 3:30pm reserved to (%d)", sizeClinic[Pos]->ID);
    }
    else if (Type == 4)
    {
        printf("3:30pm -> 4pm reserved to (%d)", sizeClinic[Pos]->ID);
    }
    else
    {
        printf("4pm -> 4:30pm reserved to (%d)", sizeClinic[Pos]->ID);
    }
}

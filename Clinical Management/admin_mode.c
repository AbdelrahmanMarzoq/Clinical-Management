#include "admin_mode.h"


int num_Patient = 0;

boolean slot[5] = {1,1,1,1,1};

void addNewPatient()
{
    int Pos;
    Patient *NewPatient = NULL;
    NewPatient = (Patient *)malloc(sizeof(Patient));
    if (NULL == NewPatient)
    {
        printf("Failed to Add New Patient");
    }
    else
    {
        getchar();
        printf("Enter Patient Name   : ");
        gets(NewPatient->Name);
        printf("Enter Patient Gender : ");
        gets(NewPatient->gender);
        printf("Enter Patient Age    : ");
        scanf("%d",&(NewPatient->age));
        printf("Enter Patient ID     : ");
        scanf("%ld",&(NewPatient->ID));
        int ID = NewPatient->ID;
        if (exist_ID(ID, &Pos))
        {
            printf("This ID already Exist \n");
            free(NewPatient);
            NewPatient = NULL;
        }
        else
        {
            sizeClinic[num_Patient++] = NewPatient;
            NewPatient->Slot = -1;
        }

    }
}

Existing exist_ID(long long ID, int *Pos)
{
    int  currentID;
    for (int i = 0; i < num_Patient; i++)
    {
        currentID = sizeClinic[i]->ID;
        if (currentID == ID)
        {
            *Pos = i;
            return Exist;
        }
    }
    return notExist;
}

int available_slot()
{
    int sum = 0;
    printf("1 : 2pm    -> 2:30pm (%d)slot \n",slot[0]);
    printf("2 : 2:30pm -> 3pm    (%d)slot \n",slot[1]);
    printf("3 : 3pm    -> 3:30pm (%d)slot \n",slot[2]);
    printf("4 : 3:30pm -> 4pm    (%d)slot \n",slot[3]);
    printf("5 : 4pm    -> 4:30pm (%d)slot \n",slot[4]);
    for(int i = 0; i < 5; i++)
    {
        sum += slot[i];
    }
    return sum;
}

boolean reserve_slot(int Pos, int Type)
{
    if (slot[Type-1])
    {
        if(sizeClinic[Pos]->Slot == -1)
        {
            sizeClinic[Pos]->Slot = Type;
            slot[Type-1] = 0;
            return 1;
        }
        else
        {
            printf("This ID Reserve Time before \n");
            printf("----------------------------\n");
            return 1;
        }
    }
    else if (!(sizeClinic[Pos]->Slot == -1))
    {
            printf("This ID Reserve Time before \n");
            printf("----------------------------\n");
            return 1;
    }
    else
    {
        return 0;
    }
}

void cancel_Reservation(int Pos)
{
    slot[(sizeClinic[Pos]->Slot)-1] = 1;
    sizeClinic[Pos]->Slot = -1;
}

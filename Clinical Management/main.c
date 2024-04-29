#include <stdio.h>
#include <stdlib.h>
#include "admin_mode.h"
#include "user_mode.h"

const int savedPassword = 1234;
extern int num_Patient;

int main()
{
    char x;
    int password;
    char Trails = 1;
    long long ID;
    int Pos;
    int window;
    MAIN:
    printf("----------------------------\n");
    printf("\n");
    printf("1- Admin-Mode \n");
    printf("2- User-Mode  \n");
    printf("\n");

    printf("----------------------------\n");

    printf("Please Enter your Mode :  ");
    scanf("%d",&x);
    printf("\n");
    printf("----------------------------------------------------- ");
    printf("\n");

    if (x == 1)
    {
        printf("Admin-Mode\n");
        printf("----------------------------\n");
        printf("Enter The Password :  ");
        scanf("%d",&password);
        printf("----------------------------------------------------- \n");

        while(1)
        {
            if (password == savedPassword)
            {
                break;
            }
            else
            {
                if (Trails < 3)
                {
                    printf("----------------------------\n");
                    printf("Wrong Password \n");
                    printf("Enter Password :  ");
                    scanf("%d",&password);
                    Trails++;
                }
                else
                {
                    break;
                }
            }
        }
        if (Trails == 3 && password != savedPassword)
        {
            Trails = 0;
            exit(0);
        }
        printf("Welcome Admin :) \n");
        printf("----------------------------\n");
        Admin:
        printf("1- Add new patient record \n");
        printf("2- Edit patient record \n");
        printf("3- Reserve a slot with the doctor \n");
        printf("4- Cancel reservation \n");
        printf("----------------------------\n");
        char feature;
        printf("Choose Features :  ");
        scanf("%d",&feature);
        printf("----------------------------\n");
        while (1)
        {
            if (ADD_PATIENT == feature)
            {
                addNewPatient();
                printf("----------------------------\n");

                printf("1- Main Window \n");
                printf("2- Admin Window \n");
                scanf("%d",&window);
                if(window == 1) goto MAIN;
                else goto Admin;
            }
            else if (EDIT_PATIENT == feature && num_Patient)
            {
                printf("Enter Patient ID need to edit ");
                scanf("%ld",&ID);
                while(1)
                {
                    if(exist_ID(ID, &Pos))
                    {
                        getchar();
                        printf("Enter New Name   :  ");
                        gets(sizeClinic[Pos]->Name);
                        printf("Enter New Gender : ");
                        gets(sizeClinic[Pos]->gender);
                        printf("Enter New Age    : ");
                        scanf("%d",&(sizeClinic[Pos]->age));
                        printf("Enter New ID     : ");
                        scanf("%d",&(sizeClinic[Pos]->ID));
                        break;
                    }
                    else
                    {
                        printf("----------------------------\n");
                        printf("This ID doesn`t Exist \n");
                        printf("Enter Patient ID need to edit ");
                        scanf("%ld",&ID);
                    }
                }
                printf("1- Main Window \n");
                printf("2- Admin Window \n");
                scanf("%d",&window);
                if(window == 1) goto MAIN;
                else goto Admin;
            }
            else if (RESERVE_SLOT == feature && num_Patient)
            {
                int available;
                printf("Slots \n");
                available = available_slot();
                printf("available slots = %d \n",available);
                if (available)
                {
                    printf("Enter Your ID : ");
                    reverse:
                    scanf("%ld",&ID);
                    if (exist_ID(ID,&Pos))
                    {
                        int Type;
                        boolean ret;
                        Time:
                        printf("Enter Your Time : ");
                        scanf("%d",&Type);
                        ret = reserve_slot(Pos,Type);
                        if (!ret)
                        {
                            printf("Reserved Time \n");
                            goto Time;
                        }
                    }
                    else
                    {
                        printf("Enter Valid ID : ");
                        goto reverse;
                    }
                }
                printf("1- Main Window \n");
                printf("2- Admin Window \n");
                scanf("%d",&window);
                if(window == 1) goto MAIN;
                else goto Admin;

            }
            else if (CANCE_RESERVATION == feature && num_Patient)
            {
                printf("Enter ID : ");
                Cancel:
                scanf("%ld",&ID);
                if (exist_ID(ID,&Pos))
                {
                    cancel_Reservation(Pos);
                }
                else
                {
                    printf("Enter Valid ID : ");
                    goto Cancel;
                }
                printf("1- Main Window \n");
                printf("2- Admin Window \n");
                scanf("%d",&window);
                if(window == 1) goto MAIN;
                else goto Admin;
            }
            else if (!num_Patient && (feature <= 4 && feature > 0))
            {
                printf("No Client in Clinic\n");
                goto Admin;
            }
            else
            {
                getchar();
                printf("Invalid Feature \n");
                goto Admin;
            }
        }
    }
    else
    {
        printf("Welcome \n");
        USER:
        printf("----------------------------------------------------- \n");
        printf("1- View Patient ID \n");
        printf("2- View Today`s reservations \n");
        printf("----------------------------\n");

        char feature;
        printf("Choose Features : ");
        scanf("%d",&feature);
        printf("----------------------------\n");
        if (VIEW_PATIENT == feature)
        {
            printf("Enter ID : ");
            ID:
            scanf("%ld",&ID);
            if(exist_ID(ID,&Pos))
            {
                print_data(Pos);
            }
            else
            {
                printf("Enter Valid ID ");
                goto ID;
            }
            printf("1- Main Window \n");
            printf("2- User Window \n");
            scanf("%d",&window);
            if(window == 1) goto MAIN;
            else goto USER;
        }
        else if (TODAY_RESERVATION == feature)
        {
            printf("Enter ID : ");
            ID1:
            scanf("%ld",&ID);
            if(exist_ID(ID,&Pos))
            {
                print_time(Pos);
            }
            else
            {
                printf("Enter Valid ID ");
                goto ID1;
            }
            printf("1- Main Window \n");
            printf("2- User Window \n");
            scanf("%d",&window);
            if(window == 1) goto MAIN;
            else goto USER;
        }
    }
    return 0;
}

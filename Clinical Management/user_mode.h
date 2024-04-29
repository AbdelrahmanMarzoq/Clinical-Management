#ifndef USER_MODE_H
#define USER_MODE_H

#include "admin_mode.h"

#define VIEW_PATIENT 1
#define TODAY_RESERVATION 2


extern Patient *sizeClinic[MAX_PATIENT];

void print_data(Pos);

void print_time(Pos);


#endif // USER_MODE_H


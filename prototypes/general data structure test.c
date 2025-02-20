#include <stdio.h>
#include <string.h>

typedef char String20[21];

struct passenger {
    String20 firstName;
    String20 lastName;
    int priority;
    int id;
    int dropOff; // TBD how the final implementation of drop-off points will be
};

struct bus {
    int tripNumber;
    int passengers[17]; //To be determined how this will work, since there is a system that only allows one special shuttle;
    struct bus *next;
};

int main() 
{
    struct bus bus1;
    bus1.tripNumber = 111;
    // struct passenger passengers1[16]; 
    
    struct bus bus2;
    bus2.tripNumber = 122;

    struct bus bus3;
    bus2.tripNumber = 133;
    

    // int i;
    // for (i=0; i<1; i++)
    // {
    //     struct passenger newPassenger1;
    //     struct passenger newPassenger2;
    //     bus1.passengers[i] = newPassenger1;
    //     bus2.passengers[i] = newPassenger2;
    // }


    bus2.next = &bus3;


    // struct bus *nextBus = bus1.next;

    printf("Bus 1 Trip no.: %d \n", bus1.tripNumber);
    printf("Bus 2 Trip no.: %d \n", bus1.next->tripNumber);
    
    return 0;
}
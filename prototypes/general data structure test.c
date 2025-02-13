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
    struct passenger passengers[17]; // To be determined how this will work, since there is a system that only allows one special shuttle;
};

struct node {
    struct bus data;
    struct node *next;
};

int main() 
{
    struct bus bus1;
    bus1.tripNumber = 111;
    struct bus bus2;
    bus2.tripNumber = 122;
    struct bus bus3;
    bus3.tripNumber = 133;

    int i;
    for (i=0; i<16; i++)
    {
        struct passenger newPassenger1;
        struct passenger newPassenger2;
        bus1.passengers[i] = newPassenger1;
        bus2.passengers[i] = newPassenger2;
    }

    struct node root;
    root.data = bus1;
    busList.next = struct node buss;

    printf("Bus 1 Trip no.: %d \n", busList.data.tripNumber);
    printf("Bus 1 Trip no.: %d \n", busList.next.data.tripNumber);
    
    return 0;
}
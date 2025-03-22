#ifndef STRUCTURES_H
#define STRUCTURES_H

#define MAX_TRIPS 22
#define MAX_TRIPS_MANILA 10
#define MAX_TRIPS_LAGUNA 12
#define MAX_PASSENGERS 16

#define MAX_ROUTE_LENGTH 5


typedef char String20[21];

struct Passenger {
    int onboard;
    String20 firstName;
    String20 lastName;
    int priority;
    int id;
    int dropOff; // TBD how the final implementation of drop-off points will be
    int reserved; 
};

struct Bus {
    int tripNumber;
    int ETD;
    int specialBus;
    struct Passenger passengers[16]; //To be determined how this will work, since there is a system that only allows one special shuttle;
    struct Bus *next; // Functions like a singly linked list. the end of the node is determined with a -1 for the trip number
    int route[MAX_ROUTE_LENGTH]; // = [embarkation point, drop off 1, drop off 2, drop off 3]
    int nReserveCount;
};

struct Passenger createEmptyPassenger();

void setEmptyPassengers(struct Passenger *passengerList, int n);

void setEmptyPassenger(struct Passenger *passengerList, int n);

void initializeBuses(struct Bus trips[22]);

#endif 
#ifndef STRUCTURES_H
#define STRUCTURES_H

#define MAX_TRIPS 22
#define MAX_TRIPS_MANILA 10
#define MAX_TRIPS_LAGUNA 12
#define MAX_PASSENGERS 16

#define MAX_ROUTE_LENGTH 5


typedef char String20[21];
typedef char String50[51];
typedef char String100[51];

struct Passenger {
    int onboard;
    String20 firstName;
    String20 lastName;
    int priority;
    int id;
    int dropOff;
    int reserved; 
};

struct Bus {
    int tripNumber;
    int dispatchable;
    int route[MAX_ROUTE_LENGTH]; // = [embarkation point, drop off 1, drop off 2, drop off 3]
    int nReserveCount;
    struct Passenger passengers[16];
    struct Bus *next; 
    
};

struct Passenger createEmptyPassenger();

void setEmptyPassengers(struct Passenger *passengerList, int n);

void setEmptyPassenger(struct Passenger *passengerList, int n);

void initializeBuses(struct Bus trips[22]);

#endif 
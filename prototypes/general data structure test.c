#include <stdio.h>
#include <string.h>

typedef char String20[21];

struct Passenger {
    String20 firstName;
    String20 lastName;
    int priority;
    int id;
    int dropOff; // TBD how the final implementation of drop-off points will be
};

struct Bus {
    int tripNumber;
    int ETD;
    struct Passenger passengers[16]; //To be determined how this will work, since there is a system that only allows one special shuttle;
    struct Bus *next;
};

struct Passenger createEmptyPassenger() 
{
    struct Passenger emptyPassenger;
    emptyPassenger.priority = 0;
    emptyPassenger.id = 0;
    emptyPassenger.dropOff = 0;

    return emptyPassenger;
}

void createEmptyPassengers(struct Passenger *passengerList, int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        passengerList[i] = createEmptyPassenger();
    }
}

// Accepts an array of pointers to busses 
void initializeBusses(struct Bus bussesManilaToLaguna[10], struct Bus bussesLagunaToManila[12])
{
    struct Bus busInst;

    // Initialization of all busses for the Manila to Laguna Trip
    bussesManilaToLaguna[0] = busInst;
    bussesManilaToLaguna[1] = busInst;
    bussesManilaToLaguna[2] = busInst;
    bussesManilaToLaguna[3] = busInst;
    bussesManilaToLaguna[4] = busInst;
    bussesManilaToLaguna[5] = busInst;
    bussesManilaToLaguna[6] = busInst;
    bussesManilaToLaguna[7] = busInst;
    bussesManilaToLaguna[8] = busInst;
    bussesManilaToLaguna[9] = busInst;

    // Initialization of busses for the Laguna to Manila Trip
    bussesLagunaToManila[0] = busInst;
    bussesLagunaToManila[1] = busInst;
    bussesLagunaToManila[2] = busInst;
    bussesLagunaToManila[3] = busInst;
    bussesLagunaToManila[4] = busInst;
    bussesLagunaToManila[5] = busInst;
    bussesLagunaToManila[6] = busInst;
    bussesLagunaToManila[7] = busInst;
    bussesLagunaToManila[8] = busInst;
    bussesLagunaToManila[9] = busInst;
    bussesLagunaToManila[10] = busInst;
    bussesLagunaToManila[11] = busInst;

    //
    //
    //

    int i;
    int initialTripNo_A = 101;
    int initialTripNo_B = 150;

    // Setting essential properties for the Manila to Laguna trip
    for (i=0; i<10; i++)
    {
        createEmptyPassengers(bussesManilaToLaguna[i].passengers, 16);
        bussesManilaToLaguna[i].tripNumber = initialTripNo_A + i;
    }

    for (i=9; i>0; i--)
    {
        bussesManilaToLaguna[i-2].next = &bussesManilaToLaguna[i];
    }

    // Setting essential properties for the Laguna to Manila trip
    for (i=0; i<12; i++)
    {
        createEmptyPassengers(bussesLagunaToManila[i].passengers, 16);
        bussesLagunaToManila[i].tripNumber = initialTripNo_B + i;
    }

    for (i=11; i>0; i--)
    {
        bussesLagunaToManila[i-1].next = &bussesLagunaToManila[i];
    }

    /*
    
    ===========================================================================================
    ===========================================================================================
    ===========================================================================================
    ===========================================================================================
    ===========================================================================================
    
    */
    
    // Returns the root busses in each trip
}


int main() 
{

    struct Bus bussesManilaToLaguna[10];
    struct Bus bussesLagunaToManila[12];

    initializeBusses(bussesManilaToLaguna, bussesLagunaToManila);

    int i;
    struct Bus *currentBus; 
    
    // for (i=0; i<10; i++)
    // {
    //     printf("Bus Trip No: %d\n", bussesManilaToLaguna[i].tripNumber);
    // }

    // for (i=0; i<12; i++)
    // {
    //     printf("Bus Trip No: %d\n", bussesLagunaToManila[i].tripNumber);
    // }

    for (i=0; i<9; i++)
    {
        printf("Current Trip No: %d\n", bussesManilaToLaguna[i].tripNumber);
        printf("Next Trip No: %d\n", bussesManilaToLaguna[i].next->tripNumber);
        printf("=================== \n");
    }
    return 0;
}
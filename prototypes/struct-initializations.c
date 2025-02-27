#include <stdio.h>
#include <string.h>

typedef char String20[21];

struct Passenger {
    int onboard;
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

/* createEmptyPassenger: returns a Passenger with all values set to an empty value or zero.
    @return Passenger with empty or zero values   
*/ 
struct Passenger 
createEmptyPassenger() 
{
    struct Passenger emptyPassenger;
    emptyPassenger.onboard = 0;
    emptyPassenger.priority = 0;
    emptyPassenger.id = 0;
    emptyPassenger.dropOff = 0;

    return emptyPassenger;
}

/* setEmptyPassenger: Takes an array of passengers and sets them all to empty
   @param *passengerList - array of passengers 
   @param n - number of passengers to set
   @return void
*/ 
void 
setEmptyPassengers(struct Passenger *passengerList, int n)
{
    int i;
    for (i=0; i<n; i++)
    {
        passengerList[i] = createEmptyPassenger();
    }
}

/* setEmptyPassenger: Takes an array of passengers and sets passenger at index n to empty   
   @param *passengerList - array of passengers 
   @param n - index of passenger to set to empty
   @return void
*/ 
void 
setEmptyPassenger(struct Passenger *passengerList, int n)
{
    passengerList[n] = createEmptyPassenger();
}

/* initializeBuses: Takes an two arrays of Bus with size 10 and 12 respectively for Manila and Laguna trips. Initializes the values for all buses. 
                    NOTE - Contents of arrays do not matter, only size. They contents will be set by this function.
   @param busesManilaToLaguna - array of buses, size 10  
   @param busesLagunaToManila - index of buses, size 12
   @return void
*/ 
void 
initializeBuses(struct Bus busesManilaToLaguna[10], struct Bus busesLagunaToManila[12])
{
    struct Bus busInst; // Instantiation of a bus for defining all buses

    // Initialization of all buses for the Manila to Laguna Trip
    busesManilaToLaguna[0] = busInst;
    busesManilaToLaguna[1] = busInst;
    busesManilaToLaguna[2] = busInst;
    busesManilaToLaguna[3] = busInst;
    busesManilaToLaguna[4] = busInst;
    busesManilaToLaguna[5] = busInst;
    busesManilaToLaguna[6] = busInst;
    busesManilaToLaguna[7] = busInst;
    busesManilaToLaguna[8] = busInst;
    busesManilaToLaguna[9] = busInst;

    // Initialization of buses for the Laguna to Manila Trip
    busesLagunaToManila[0] = busInst;
    busesLagunaToManila[1] = busInst;
    busesLagunaToManila[2] = busInst;
    busesLagunaToManila[3] = busInst;
    busesLagunaToManila[4] = busInst;
    busesLagunaToManila[5] = busInst;
    busesLagunaToManila[6] = busInst;
    busesLagunaToManila[7] = busInst;
    busesLagunaToManila[8] = busInst;
    busesLagunaToManila[9] = busInst;
    busesLagunaToManila[10] = busInst;
    busesLagunaToManila[11] = busInst;

    int i;
    int initialTripNo_A = 101;
    int initialTripNo_B = 150;

    // Setting essential properties for the Manila to Laguna trip
    for (i=0; i<10; i++)
    {
        setEmptyPassengers(busesManilaToLaguna[i].passengers, 16);
        busesManilaToLaguna[i].tripNumber = initialTripNo_A + i;
    }

    // Setting essential properties for the Laguna to Manila trip
    for (i=0; i<12; i++)
    {
        setEmptyPassengers(busesLagunaToManila[i].passengers, 16);
        busesLagunaToManila[i].tripNumber = initialTripNo_B + i;
    }

    // Setup linking of buses for Manila to Laguna Trip
    for (i=9; i>=0; i--)
    {
        if (i > 7) // for 109 and 110 (special trip)
        {
            struct Bus newBusInst = busInst;
            busInst.tripNumber = -1;
            busesManilaToLaguna[i].next = &newBusInst;
        }
        else
        {
            busesManilaToLaguna[i].next = &busesManilaToLaguna[i+2];
        }
    }

    // Setup linking of buses for Manila to Laguna Trip
    for (i=11; i>=0; i--)
    {
        if (i > 9) // for 160 and 161 (for special trip)
        {
            struct Bus newBusInst = busInst;
            busInst.tripNumber = -1;
            busesLagunaToManila[i].next = &newBusInst;
        }
        else
        {
            busesLagunaToManila[i].next = &busesLagunaToManila[i+2];
        }
    }
    
}

/*
==================================
   Bus and Passenger Operations
==================================
*/

/* getPassengerCount: Takes a bus and returns the amount of passengers onboard
   @param bus - bus structure  
   @return int - the number of passengers onboard
*/ 
int 
getPassengerCount(struct Bus bus)
{
    int i;
    int count = 0;
    for (i=0; i<16; i++)
    {
        count += bus.passengers[i].onboard;
    }
    return count;
}

/* isTripFull: Takes a bus and returns 1 if the trip is full, 0 if not
   @param bus - bus structure  
   @return int - returns 1 if the trip is full, and 0 otherwise
*/ 
int 
isTripFull(struct Bus bus)
{
    int count = getPassengerCount(bus);
    if (count >=16) return 1;
    else return 0;
}

/*
========================
  Passenger Operations
========================
*/

void 
InputPassenger(int priority, String20 firstName, String20 lastName, int id, int dropOffPoint, int seatNumber, struct Bus *bus)
{
    if (bus->tripNumber == -1)
    {
        printf("There are no more remaining bus trips!");
        return;
    }

    if (isTripFull(*bus))
    {
        // Check for the lowst passenger
        struct Passenger *firstLowestPassenger = NULL;
        int i;
        for (i=0; i<16; i++)
        {
            if (priority > bus->passengers[i].priority && bus->passengers[i].priority > 0)
            {
                *firstLowestPassenger = bus->passengers[i];
            }
        }
        
        /*
        If high priority passenger
            (loop through each passenger, get first lowest priority passenger)
            move first lowest priority passenger to the next trip
        Else
            reject passenger
        */
    }
    else
    {
        // Assign Passenger to trip
    }

}

void movePassenger()
{

}



// int main() 
// {
//     // Sample Main Function with initialization of buses
//     struct Bus busesManilaToLaguna[10];
//     struct Bus busesLagunaToManila[12];

//     initializeBuses(busesManilaToLaguna, busesLagunaToManila);

//     int i; 
    

//     for (i=0; i<10; i++)
//     {
//         printf("Current Trip No: %d\n", busesManilaToLaguna[i].tripNumber);
//         printf("Next Trip No: %d\n", busesManilaToLaguna[i].next->tripNumber);
//         printf("=================== \n");
//     }

//     printf("\n\n");

//     for (i=0; i<12; i++)
//     {
//         printf("Current Trip No: %d\n", busesLagunaToManila[i].tripNumber);
//         printf("Next Trip No: %d\n", busesLagunaToManila[i].next->tripNumber);
//         printf("=================== \n");
//     }
//     return 0;
// }

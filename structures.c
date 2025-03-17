#include <stdio.h>
#include <string.h>

#include "structures.h"

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
initializeBuses(struct Bus trips[22])
{
    struct Bus busInst; // Instantiation of a bus for defining all buses
    // First 10 buses are for manila to laguna, last 12 are for laguna to manila

    // Initialization of all buses for the Manila to Laguna Trip
    int i;
    for (i=0; i<22; i++)
    {
        trips[i] = busInst;
    }


    int initialTripNo_A = 101;
    int initialTripNo_B = 150;

    // Setting essential properties for the Manila to Laguna trip
    for (i=0; i<10; i++)
    {
        setEmptyPassengers(trips[i].passengers, 16);
        trips[i].tripNumber = initialTripNo_A + i;
    }

    // Setting essential properties for the Laguna to Manila trip
    for (i=0; i<12; i++)
    {
        setEmptyPassengers(trips[i+10].passengers, 16);
        trips[i+10].tripNumber = initialTripNo_B + i;
    }

    // Setup linking of buses for Manila to Laguna Trip
    for (i=9; i>=0; i--)
    {
        if (i > 7) // for 109 and 110 (special trip)
        {
            struct Bus newBusInst = busInst;
            busInst.tripNumber = -1;
            trips[i].next = &newBusInst;
        }
        else
        {
            trips[i].next = &trips[i+2];
        }
    }

    // Setup linking of buses for Manila to Laguna Trip
    for (i=11; i>=0; i--)
    {
        if (i > 9) // for 160 and 161 (for special trip)
        {
            struct Bus newBusInst = busInst;
            busInst.tripNumber = -1;
            trips[i+10].next = &newBusInst;
        }
        else
        {
            trips[i+10].next = &trips[i+2+10];
        }
    } 
}
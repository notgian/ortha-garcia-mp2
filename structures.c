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
    emptyPassenger.reserved = 0;

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
    int i;
    for (i=0; i<MAX_TRIPS; i++)
    {
        struct Bus busInst;
        
        busInst.ETD = 0;
        busInst.specialBus = 0;
        busInst.next = NULL;
        busInst.tripNumber = -1;
        setEmptyPassengers(busInst.passengers, MAX_PASSENGERS);

        int i;
        for (i = 0; i < MAX_ROUTE_LENGTH; i++)
        {
            busInst.route[i] = 0;
        }

        trips[i] = busInst;
    }

    int initialTripNo_A = 101;
    int initialTripNo_B = 150;

    // Setting trip numbers and routes for the Manila to Laguna trip
    for (i=0; i<10; i++)
    {
        trips[i].tripNumber = initialTripNo_A + i;
        if (initialTripNo_A + i == 110)  
            trips[i].specialBus = 1;
        
        if (i % 2 == 0) // Odd numbered buses
        {
            trips[i].route[0] = 20050; // Embarkation Point
            trips[i].route[1] = 10010; 
            trips[i].route[2] = 10020;
            trips[i].route[3] = 10040;
        }
        else // Even numbered buses
        {
            trips[i].route[0] = 20050; // Embarkation Point
            trips[i].route[1] = 10030; 
            trips[i].route[2] = 10040;
        }
    }

    // Setting trip numbers for the Laguna to Manila trip
    for (i=0; i<12; i++)
    {
        trips[i+10].tripNumber = initialTripNo_B + i;
        if (initialTripNo_B + i == 161)
            trips[i+10].specialBus = 1;

        if (i % 2 == 0) // Even numbered buses
        {
            trips[i+10].route[0] = 10040; // Embarkation Point
            trips[i+10].route[1] = 10010; 
            trips[i+10].route[2] = 10030;
            trips[i+10].route[3] = 10040;
            trips[i+10].route[4] = 10050;
        }
        else  // Odd numbered buses
        {
            trips[i+10].route[0] = 10040; // Embarkation Point
            trips[i+10].route[1] = 20020; 
            trips[i+10].route[2] = 20030;
            trips[i+10].route[3] = 20040;
            trips[i+10].route[4] = 20050;
        }
    }

    // Link Manila buses
    for (i=8; i >=0; i--)
    {
        trips[i].next = &trips[i+1];
    }

    // Link Laguna Buses
    for (i=10; i >=0; i--)
    {
        trips[i].next = &trips[i+1];
    }
}

// void 
// initializeBuses(struct Bus trips[22])
// {
//     // Instantiation of a bus for defining all buses
//     struct Bus busInst; 
//     busInst.tripNumber = -1;
//     busInst.ETD = 0;
//     busInst.specialBus = 0;
//     busInst.next = NULL;
//     setEmptyPassengers(busInst.passengers, MAX_PASSENGERS);

//     int i;
//     for (i = 0; i < MAX_ROUTE_LENGTH; i++)
//     {
//         busInst.route[i] = 0;
//     }

//     // First 10 buses are for manila to laguna, last 12 are for laguna to manila

//     // Initializaton of all bus' initial instances  
//     for (i=0; i<22; i++)
//     {
//         trips[i] = busInst;
//     }

//     int initialTripNo_A = 101;
//     int initialTripNo_B = 150;

//     // Setting trip numbers and routes for the Manila to Laguna trip
//     for (i=0; i<10; i++)
//     {
//         trips[i].tripNumber = initialTripNo_A + i;
//         if (initialTripNo_A + i == 110)  
//             trips[i].specialBus = 1;
        
//         if (i % 2 == 0) // Odd numbered buses
//         {
//             trips[i].route[0] = 20050; // Embarkation Point
//             trips[i].route[1] = 10010; 
//             trips[i].route[2] = 10020;
//             trips[i].route[3] = 10040;
//         }
//         else // Even numbered buses
//         {
//             trips[i].route[0] = 20050; // Embarkation Point
//             trips[i].route[1] = 10030; 
//             trips[i].route[2] = 10040;
//         }
//     }

//     // Setting trip numbers for the Laguna to Manila trip
//     for (i=0; i<12; i++)
//     {
//         trips[i+10].tripNumber = initialTripNo_B + i;
//         if (initialTripNo_B + i == 161)
//             trips[i+10].specialBus = 1;

//         if (i % 2 == 0) // Even numbered buses
//         {
//             trips[i+10].route[0] = 10040; // Embarkation Point
//             trips[i+10].route[1] = 10010; 
//             trips[i+10].route[2] = 10030;
//             trips[i+10].route[3] = 10040;
//             trips[i+10].route[4] = 10050;
//         }
//         else  // Odd numbered buses
//         {
//             trips[i+10].route[0] = 10040; // Embarkation Point
//             trips[i+10].route[1] = 20020; 
//             trips[i+10].route[2] = 20030;
//             trips[i+10].route[3] = 20040;
//             trips[i+10].route[4] = 20050;
//         }
//     }


//     // Link Manila buses
//     for (i=8; i >=0; i--)
//     {
//         trips[i].next = &trips[i+1];
//     }

//     // Link Laguna Buses
//     for (i=8; i >=0; i--)
//     {
//         trips[i].next = &trips[i+1];
//     }
// }



// void 
// initializeBuses(struct Bus trips[22])
// {
//     struct Bus busInst; // Instantiation of a bus for defining all buses
//     // First 10 buses are for manila to laguna, last 12 are for laguna to manila

//     // Initialization of all buses for the Manila to Laguna Trip
//     int i;
//     for (i=0; i<22; i++)
//     {
//         trips[i] = busInst;
//     }


//     int initialTripNo_A = 101;
//     int initialTripNo_B = 150;

//     // Setting essential properties for the Manila to Laguna trip
//     for (i=0; i<10; i++)
//     {
//         setEmptyPassengers(trips[i].passengers, 16);
//         trips[i].tripNumber = initialTripNo_A + i;
//     }

//     // Setting essential properties for the Laguna to Manila trip
//     for (i=0; i<12; i++)
//     {
//         setEmptyPassengers(trips[i+10].passengers, 16);
//         trips[i+10].tripNumber = initialTripNo_B + i;
//     }

//     // Setup linking of buses for Manila to Laguna Trip
//     for (i=9; i>=0; i--)
//     {
//         if (i > 7) // for 109 and 110 (special trip)
//         {
//             struct Bus newBusInst = busInst;
//             busInst.tripNumber = -1;
//             trips[i].next = &newBusInst;
//         }
//         else
//         {
//             trips[i].next = &trips[i+2];
//         }
//     }

//     // Setup linking of buses for Manila to Laguna Trip
//     for (i=11; i>=0; i--)
//     {
//         if (i > 9) // for 160 and 161 (for special trip)
//         {
//             struct Bus newBusInst = busInst;
//             busInst.tripNumber = -1;
//             trips[i+10].next = &newBusInst;
//         }
//         else
//         {
//             trips[i+10].next = &trips[i+2+10];
//         }
//     } 
// }
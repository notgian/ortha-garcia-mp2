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

// /* initializeBuses: Takes an two arrays of Bus with size 10 and 12 respectively for Manila and Laguna trips. Initializes the values for all buses. 
//                     NOTE - Contents of arrays do not matter, only size. They contents will be set by this function.
//    @param busesManilaToLaguna - array of buses, size 10  
//    @param busesLagunaToManila - index of buses, size 12
//    @return void
// */ 
// void 
// initializeBuses(struct Bus trips[22])
// {
//     struct Bus busInst; // Instantiation of a bus for defining all buses
//     struct Bus busesManilaToLaguna[10];
//     struct Bus busesLagunaToManila[12];

//     // Initialization of all buses for the Manila to Laguna Trip
//     busesManilaToLaguna[0] = busInst;
//     busesManilaToLaguna[1] = busInst;
//     busesManilaToLaguna[2] = busInst;
//     busesManilaToLaguna[3] = busInst;
//     busesManilaToLaguna[4] = busInst;
//     busesManilaToLaguna[5] = busInst;
//     busesManilaToLaguna[6] = busInst;
//     busesManilaToLaguna[7] = busInst;
//     busesManilaToLaguna[8] = busInst;
//     busesManilaToLaguna[9] = busInst;

//     // Initialization of buses for the Laguna to Manila Trip
//     busesLagunaToManila[0] = busInst;
//     busesLagunaToManila[1] = busInst;
//     busesLagunaToManila[2] = busInst;
//     busesLagunaToManila[3] = busInst;
//     busesLagunaToManila[4] = busInst;
//     busesLagunaToManila[5] = busInst;
//     busesLagunaToManila[6] = busInst;
//     busesLagunaToManila[7] = busInst;
//     busesLagunaToManila[8] = busInst;
//     busesLagunaToManila[9] = busInst;
//     busesLagunaToManila[10] = busInst;
//     busesLagunaToManila[11] = busInst;

//     int i;
//     int initialTripNo_A = 101;
//     int initialTripNo_B = 150;

//     // Setting essential properties for the Manila to Laguna trip
//     for (i=0; i<10; i++)
//     {
//         setEmptyPassengers(busesManilaToLaguna[i].passengers, 16);
//         busesManilaToLaguna[i].tripNumber = initialTripNo_A + i;
//     }

//     // Setting essential properties for the Laguna to Manila trip
//     for (i=0; i<12; i++)
//     {
//         setEmptyPassengers(busesLagunaToManila[i].passengers, 16);
//         busesLagunaToManila[i].tripNumber = initialTripNo_B + i;
//     }

//     // Setup linking of buses for Manila to Laguna Trip
//     for (i=9; i>=0; i--)
//     {
//         if (i > 7) // for 109 and 110 (special trip)
//         {
//             struct Bus newBusInst = busInst;
//             busInst.tripNumber = -1;
//             busesManilaToLaguna[i].next = &newBusInst;
//         }
//         else
//         {
//             busesManilaToLaguna[i].next = &busesManilaToLaguna[i+2];
//         }
//     }

//     // Setup linking of buses for Manila to Laguna Trip
//     for (i=11; i>=0; i--)
//     {
//         if (i > 9) // for 160 and 161 (for special trip)
//         {
//             struct Bus newBusInst = busInst;
//             busInst.tripNumber = -1;
//             busesLagunaToManila[i].next = &newBusInst;
//         }
//         else
//         {
//             busesLagunaToManila[i].next = &busesLagunaToManila[i+2];
//         }
//     } 

//     int k;
//     for (k=0; k<10; k++)
//     {
//         trips[k] = busesManilaToLaguna[k];
//     }
//     for (k=0; k<12; k++)
//     {
//         trips[k+10] = busesLagunaToManila[k];
//     }
// }


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
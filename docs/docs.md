<title>Ortha-Garcia ARROW EXPRESS: CCPROG 2 DOCUMENTATION</title>
<h1> Ortha-Garcia ARROW EXPRESS: CCPROG 2 DOCUMENTATION </h1>

<br />

<h2>Table of Contents</h2>

<ul> 

<li> <a href="#s-structures.h">structures.h</a> </li>

<ul> 
<li> <a href="#s-constants">Constants</a></li>
<li> <a href="#s-typedefs-and-structs">Type Definitions and Structures</a></li>
<li> <a href="#s-funcs">Functions</a></li>
</ul>

</ul>

<br />
<hr />
<br />

<h1 id="s-structures.h"> structures.h </h1>

<h2 id="s-constants">Constants</h2>

<h3>MAX_TRIPS</h3>
Defines the maximum size of the trips array
    
    #DEFINE MAX_TRIPS 22

<h3>MAX_TRIPS_MANILA</h3>
Defines the amount of trips for the MANILA to LAGUNA route (including the special shuttle)
    
    #DEFINE MAX_TRIPS 10

<h3>MAX_TRIPS_LAGUNA</h3>
Defines the amount of trips for the MANILA to LAGUNA route (including the special shuttle)

    #define MAX_TRIPS_LAGUNA 12

<h3>MAX_PASSENGERS</h3>
Defines the maximum length of a passenger array
    
    #define MAX_PASSENGERS 16

<h3>MAX_ROUTE_LENGTH</h3>
Defines the maximum length for a route array

    #define MAX_ROUTE_LENGTH 5

<h2 id="s-typedefs-and-structs">Type Definitions and Structures</h2>

<h3>typedef String20</h3>
Type definition for a string with max 20 characters
    
    typedef char String20[21];

<h3>String50</h3>
Type definition for a string with max 20 characters
    
    typedef char String20[51];

<h3>String100</h3>
Type definition for a string with max 20 characters

    typedef char String20[100];

<h3>Passenger</h3>
Structure for a passenger with the following properties and values when initialized or set to empty

<ul>

<li><code>int onboard</code> defaults to <code>0</code> when initialized and is used to indicate if a passenger is onboard.</li> 

<li><code>String20 firstName</code> defaults to an empty string when initialized and is used to store a passenger's first name.</li> 

<li><code>String20 lastName</code> defaults to an empty string when initialized and is used to store a passenger's last name.</li> 

<li><code>int priority</code> defaults to <code>0</code> when initialized and is used to indicate a passenger's priority. Values range from <code>1</code> to <code>6</code>.</li> 

<li><code>int id</code> defaults to <code>0</code> when initialized and is used to indicate a passenger's id number. This number must be unique for each passenger and must be an 8-digit number.</li> 

<li><code>int dropOff</code> defaults to <code>0</code> when initialized and is used to indicate a passenger's drop-off point. Drop off points are internally represented as indicated below:</li>
<ul> 
<li> <code>10010</code> - Mamplasan Toll Exit</li>
<li> <code>10020</code> - Phase 5, San Jose Vilage</li>
<li> <code>10030</code> - Laguna Blvd. Guard House(across Paseo PHOENIX Gasoline Station)</li>
<li> <code>10040</code> - Milagros Del Rosario Building - East Canopy</li>
<br />
<li> <code>20010</code> - Petron Gasoline Station along Gil Puyat Avenue</li>
<li> <code>20020</code> - College of St. Benilde (CSB) along Taft Avenue</li>
<li> <code>20030</code> - Gate 4: Gokongwei Gate</li>
<li> <code>20040</code> - Gate 2: North Gate (HSSH)</li>
<li> <code>20050</code> - Gate 1: South Gate (LS Building Entrance)</li>

</ul> 
Codes that begin with a <code>1</code> represent drop off points that are IN laguna and those that start with a <code>2</code> represent those that are IN Manila.

<li><code>int reserve</code> defaults to <code>0</code> and indicates whether a passenger is reserved or not. When set to <code>1</code> in indicates that the passenger is reserved, and <code>o</code> if they are not reserved.</li> 

</ul>

The actual definition is as follows:

    struct Passenger {
        int onboard;
        String20 firstName;
        String20 lastName;
        int priority;
        int id;
        int dropOff;
        int reserved; 
    };

<h3>Bus</h3>
Structure for a bus with the following properties and values when initialized

<ul>

<li> <code>int tripNumber</code> defaults to <code>0</code> when initialized and represents a bus' trip number for this specific implementation of the program, the following hold true:</li>

<ul>
<li> Manila to Laguna trips: 101-110 </li>
<li> Laguna to Manila trips: 150-161 </li>
<li> Trips 110 and 161 are special trips and are handled slightly differently as specified throughout this documentaiton
</ul>
These trip numbers are also strictly integers in code, but are often displayed with "AE" preceding it (i.e. AE-101) for the actual trip number

<li> <code>int dispatchable</code> is a bool-type that defaults to <code>1</code> upon initialization, except for the special trips (110 and 161) where it initializes to <code>0</code>.</li>

<li> <code>int route[]</code> is an integer-array with a length of <code>MAX_ROUTE_LENGTH</code>. Each element is initialized to 0, then set to the correct values. The first value always represents the <em>embarkation point</em>. Embarkation points share the same internal implementation despite using functions for drop-off points. Depending on the route this will be initialized differently.</li>

<ul> 
<li><b>AE-101, AE-103, AE-105, AE-107</b></li>

<ul>
<li>Embarkation Point : <code>20050</code> </li>
<li>Drop-Off Point 1  : <code>10010</code> </li>
<li>Drop-Off Point 2  : <code>10020</code> </li>
<li>Drop-Off Point 3  : <code>10040</code> </li>
</ul>

<li><b>AE-102, AE-104, AE-106, AE-108, AE-110 (Special trip)</b></li>

<ul>
<li>Embarkation Point : <code>20050</code> </li>
<li>Drop-Off Point 1  : <code>10030</code> </li>
<li>Drop-Off Point 2  : <code>10040</code> </li>
</ul>

<li><b>AE-151, AE-153, AE-155, AE-157, AE-159, AE-161 (Special trip)</b></li>

<ul>
<li>Embarkation Point : <code>10040</code></li>
<li>Drop-Off Point 1  : <code>20010</code></li>
<li>Drop-Off Point 2  : <code>20030</code></li>
<li>Drop-Off Point 3  : <code>20040</code></li>
<li>Drop-Off Point 4  : <code>20050</code></li>
</ul>

<li><b>AE-150, AE-152, AE-154 AE-156, AE-158, AE-160</b></li>

<ul>
<li>Embarkation Point : <code>10040</code> </li>
<li>Drop-Off Point 1  : <code>20020</code> </li>
<li>Drop-Off Point 2  : <code>20030</code> </li>
<li>Drop-Off Point 3  : <code>20040</code> </li>
<li>Drop-Off Point 4  : <code>20050</code> </li>
</ul>

</ul>

<li> <code>int nReserveCount</code> default to <code>0</code> when initialized. Represents the number of passengers that have reserved on the bus.</li>
<li> <code>Passenger passengers[]</code> is an array of passengers with a length of <code>MAX_PASSENGERS</code>. Each passenger is also set to empty when initialized.</li> 
<li> <code>Bus *next</code> is initialzed to <code>NULL</code> and is set accordingly. It is a pointer to the next bus. <code>NULL</code> pointer means that there is no bus in the line of trips after the current bus. The linking starts from AE0101, which links to AE-102, then to AE-103, up to AE-109. Upon initialization, AE-110 is not linked because it is not initially dispatchable. This is similar for the other line of trips. AE-150 links to AE-151, linking to AE-152 up to AE-160. AE-161 is not linked upon initialization.</li>

</ul>

<h2 id="s-funcs">Functions</h2>

<h3>createEmptyPassenger()</h3>
Creates an empty passenger as specified in the <code>Passenger</code> section and returns this empty passenger

    struct Passenger createEmptyPassenger()
    {
        struct Passenger emptyPassenger;
        strcpy(emptyPassenger.firstName, "");
        strcpy(emptyPassenger.lastName, "");
        emptyPassenger.onboard = 0;
        emptyPassenger.priority = 0;
        emptyPassenger.id = 0;
        emptyPassenger.dropOff = 0;
        emptyPassenger.reserved = 0;

        return emptyPassenger;
    }

<h3> setEmptyPassengers(struct Passenger *passengerList, int n) </h3>

<ul>
    <li> <code>*passengerList</code> : an array of passengers</li>
    <li> <code>n</code> : length of the array of passengers/the number of passengers to set to empty.</li>
</ul>

    void setEmptyPassengers(struct Passenger *passengerList, int n)
    {
        int i;
        for (i=0; i<n; i++)
        {
            passengerList[i] = createEmptyPassenger();
        }
    }

<h3> initializeBuses(struct Bus trips[]) </h3>
<em> Pre-condition: Pre-condition: the array passed MUST have a size of 22 </em>
Initializes all of the values of the buses and the passengers in the buses. Refer to the structures above to find particular values when initialized
<ul>
    <li> <code>trips[]</code> : an array of buses. It must have a length of exactly <code>22</code> as per the pre-condition</li>
</ul>

    void initializeBuses(struct Bus trips[MAX_TRIPS]);

<h1 id="o-operations.h">operations.h</h1>

<h2 id="o-helper-funcs">Helper Functions</h2>
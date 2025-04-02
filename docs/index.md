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

<li> <a href="#o-operations.h"> operations.h </a> </li>
<ul>
    <li> <a href="#o-helper-funcs"> Helper Functions </a> </li>
    <li> <a href="#o-bus-pass-funcs"> Bus and Passenger Functions </a> </li>
    <li> <a href="#o-passenger-funcs"> Passenger Functions</a> </li>
    <li> <a href="#o-personnel-funcs"> Arrow Personnel Functions</a> </li>
</ul>
<li> <a href="#m-main-func"> main </a> </li>
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

<h3>typedef String50</h3>
Type definition for a string with max 20 characters
    
    typedef char String20[51];

<h3>typedef String100</h3>
Type definition for a string with max 20 characters

    typedef char String20[100];

<h3 id="s-struct-passenger">struct Passenger</h3>
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

<h3 id="s-struct-bus">struct Bus</h3>
Structure for a bus with the following properties and values when initialized

<ul>
    <li> <code>int tripNumber</code> defaults to <code>0</code> when initialized and represents a bus' trip number for this specific implementation of the program, the following hold true:</li>
    <ul>
    <li> Manila to Laguna trips: 101-110 </li>
    <li> Laguna to Manila trips: 150-161 </li>
    <li> Trips 110 and 161 are special trips and are handled slightly differently as specified throughout this documentaiton
    </ul>
    These trip numbers are also strictly integers in code, but are often displayed with "AE" preceding it (i.e. AE-101) for the actual trip number
</ul>

<ul>
    <li> <code>int dispatchable</code> is a bool-type that defaults to <code>1</code> upon initialization, except for the special trips (110 and 161) where it initializes to <code>0</code>.</li>
    <li> <code>int route[]</code> is an integer-array with a length of <code>MAX_ROUTE_LENGTH</code>. Each element is initialized to 0, then set to the correct values. The first value always represents the <em>embarkation point</em>. Embarkation points share the same internal implementation despite using functions for drop-off points. Depending on the route this will be initialized differently.</li>
    <li>These trip numbers are also strictly integers in code, but are often displayed with "AE" preceding it (i.e. AE-101) for the actual trip number</li>
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
<ul>

<li><code>return</code> is a <code>Passenger</code> with properties set as follows in the code block below.</li>
</ul>

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
Sets the properties of each <code>Passenger</code> in an array of passengers
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

<h3> initializeBuses(struct Bus trips[22]) </h3>
<br />
<em> Pre-condition: Pre-condition: the array passed MUST have a size of 22. </em> <br />
Initializes all of the values of the buses and the passengers in the buses. Refer to the structures above to find the values of most other properties when initialized. 
<ul>
    <li> <code>trips[]</code> : an array of buses. It must have a length of exactly <code>22</code> as per the pre-condition</li>
</ul>

    void initializeBuses(struct Bus trips[MAX_TRIPS]);

<h1 id="o-operations.h">operations.h</h1>

<h2 id="o-helper-funcs">Helper Functions</h2>


<h3> stringToInt(String20 str) </h3>
<em> Pre-condition: the string passed only contains characters that can be considered valid numbers and the numbers are not negative </em>
<ul>
    <li> <code>str</code> : a string where each character is a valid integer</li>
</ul>

    int stringToInt(String20 str)

<h2 id="o-bus-pass-funcs">Bus and Passenger Functions</h2> 

<h3>getPassengerCount(struct Bus bus)</h3>
Returns the number of passengers on a bus. Uses the <code> onboard </code> property of each passenger to determine if the passenger is on the bus.
<ul>
<li> <code>bus</code> is a bus structure</li>
<li> <code>return</code> is an integer</li>
</ul>

    getPassengerCount(struct Bus bus)

<h3>isTripFull(struct Bus bus)</h3>
Returns <code>1</code> if the trip is full (has 16 passengers) and <code>0</code> if otherwise
<ul>
<li> <code>bus</code> is a bus structure</li>
<li> <code>return</code> is an integer</li>
</ul>

    int isTripFull(struct Bus bus)

<h3>getBusFromTripNumber(struct Bus trips[], int n, int tripNumber)</h3>
<em>Pre-condition: the trips have been initialized</em> <br />
Searches through the trip array for a bus that matches the trip number passed to the function.
<ul>
<li> <code>trips[]</code> is an array of bus trips </li>
<li> <code>n</code> is the size of the trips array</li>
<li> <code>tripNumber</code> is the trip number of the bus being searched for </li>
<li> <code>return</code> is the pointer to the bus being searched for. If it cannot be found, this is <code>NULL</code> </li>
</ul>

    struct Bus* getBusFromTripNumber(struct Bus trips[], int n, int tripNumber)

<h3>displayTripList(struct Bus trips[])</h3>
<em>Pre-condition: the trips have been initialized</em> <br />
Displays the list of bus trips. Special trips are not displayed when they have not been enabled. The display is done recursively using the <code>next</code> property of each bus, only stopping once the loop has reached the end of the nodes for both bus trip lines.
<ul>
<li> <code>trips[]</code> is an array of bus trips </li>
</ul>

    void displayTripList(struct Bus trips[])

<h3>getInputTripNumber(struct Bus trips[])</h3>
<em>Pre-condition: the trips have been initialized</em> <br />
Takes user input to get a certain bus with a particular trip number and returns a pointer to the bus. This function will infinitely loop until the user inputs a valid trip number.
<ul>
<li> <code>trips[]</code> is an array of bus trips </li>
<li> <code>return</code> a pointer to the bus with the trip number that the user specified. </li>
</ul>

    struct Bus *getInputTripNumber(struct Bus trips[])

<h3>isValidTripNumber(int nTripNumber)</h3>
Determines if the integer passed through the function corresponds to any valid trip number.
<ul>
<li> <code>nTripNumber</code> is the trip number to verify</li>
<li> <code>return</code> is <code>1</code> if the trip number is valid, and <code>0</code> if it is not </li>
</ul>

    int isValidTripNumber(int nTripNumber)

<h3>printDropOffPointFromCode(int code)</h3>
<em>Pre-condition: the drop-off code is valid</em> <br />
Prints the name of a drop-off point given a particular drop-off code
<ul>
<li> <code>code</code> is the code of the drop-off point to print. Refer to the definition of the <a href="#s-struct-passenger">Passenger</a> structure above for the mapping of each code to the text printed.</li>
<ul>

</ul>
</ul>

    void printDropOffPointFromCode(int code)

<h3>getDropOffPointFromCode(int code, String50 name)</h3>
<em>Pre-condition: the drop-off code is valid</em> <br />
Sets the value of the <code>name</code> string passed to the corresponding name of the drop-off point code passed through the function. Refer to the <a href="#s-struct-passenger">Passenger</a> structure above for the mapping of each code to the value which the string will be set to.
<ul>
<li> <code>code</code> is the code of the drop-off point</li>
<li> <code>name</code> is the string to which the name of the drop-off point will be set </li>
</ul>

    void printDropOffPointFromCode(int code)

<h3>getDropOffPointFromString(String50 string)</h3>
<em>Pre-condition: the string is a valid drop-off point.</em> <br />
Returns the drop-off point given a string with the name of the drop off point. Refer to the <a href="#s-struct-passenger">Passenger</a> structure for the mapping of each string to the drop-off code.
<ul>
<li> <code>string</code> is the drop-off point in string form</li>
<li> <code>return</code> is the drop-off point code of the string passed</li>
</ul>

    int getDropOffPointFromString(String50 string)

<h3>void clearScreen()</h3>
Clears the screen with ANSI regex

    void clearScreen()
    {
        printf("\e[1;1H\e[2J");
    }

<h3>void pauseAndContinueOnReturn()</h3>
Pauses the execution of the program until the user types a character and presses enter

    void pauseAndContinueOnReturn()
    {
        printf("\nType any character and press return to continue\n");
        scanf(" \n");
        getchar();
    }

<h2 id="o-passenger-funcs">Passenger Functions</h2>

<h3>setPassenger(struct Passenger *passenger, int priority, String20 firstName, String20 lastName, int id, int dropOffPoint, int nReserve) </h3>
<em>Pre-condition: all data being passed is valid </em> <br />
This function sets the properties of the passenger based on the values passsed to the function.
<ul>
<li> <code>passenger</code> is the pointer to the passenger to set the properties of</li>
<li> <code>priority</code> is the priority value to set the passenger to</li>
<li> <code>firstName</code> is the first name valueto set the passenger to</li>
<li> <code>lastName</code> is the last name value to set the passenger to</li>
<li> <code>id</code> is the id number value to set the passenger to</li>
<li> <code>dropOffPoint</code> is the drop-off point code value to set the passenger to </li>
<li> <code>nReserve</code> is the reserve boolean value          to set the passenger to </li>
</ul>

    void setPassenger(struct Passenger *passenger, int priority, String20 firstName, String20 lastName, int id, int dropOffPoint, int nReserve) 

<h3>inputPassenger(int priority, String20 firstName, String20 lastName, int id, int dropOffPoint, int seatNumber, struct Bus *bus, int nReserve); </h3>
<em>Pre-condition: the trips array was initialized </em> <br />
This function implements the <code>setPassenger</code> function and adds the logic for adding passengers to trips, along with trip reassignment and reservation.
<ul>
<li> <code>priority</code> is the priority of the passenger to input</li>
<li> <code>firstName</code> is the first name of the passenger to input</li>
<li> <code>lastName</code> is the last name of the passenger to input </li>
<li> <code>id</code> is the id number of the passenger to input</li>
<li> <code>dropOffPoint</code> is the drop-off point of the passenger to input</li>
<li> <code>seatNumber</code> is the seat number of the passenger to input</li>
<li> <code>bus</code> is the pointer to the bus to which the passenger will be input</li>
<li> <code>nReserve</code> is the boolean value that controls whether the passenger will reserve or not </li>
</ul>
The function has a complex set of logic that can be summarized as such:
<ul>
    <li>If the bus is NULL (no trips left) </li>
    <ul>
        <li>Display no trips are left</li>
    </ul>
<li>Else if the bus is full:</li>
    <ul>
        <li>Check if a passenger can be displayed (i.e. current passenger is reserved or is a higher priority)</li>
        <li>If a passenger CAN be displaced:</li>
        <ul>
            <li>Displace the passenger and input the current one</li>
        </ul>
        <li>If a passenger WAS NOT displaced:</li>
        <ul>
            <li>If the current passenger is attempting to reserve: Fail to board the trip</li>
            <li>Else: board the current passenger to the next trip</li>
        </ul>
        <li>If a passenger WAS displaced:</li>
        <ul>
            <li>Display a specific message depending on if they are reserved or not.</li>
            <li>Attempt to board the passenger onto the same bus with a recursive function call</li>
        </ul>
    </ul>
<li>Else if the bus is NOT full:</li>
<ul> 
    <li>If seat assignment is automatic, board them onto the first free seat</li>
    <li>If the seat is specified but is empty, board them onto the seat</li>
    <li>If the seat is specified but is not empty:</li>
    <ul>
        <li>If the current passenger's priority is greater than the passenger on the seat</li>
        <ul>
            <li>Displace the passenger on the seat</li>
            <li>Input the current passenger onto the seat</li>
            <li>Recursively call the function to automatically assign the displaced passenger to the first available seat</li>
        </ul>
        <li>Else, display that there is already a higher or equal priority passenger on the seat and to try again</li>
    </ul>
</ul>
</ul>

    void inputPassenger(int priority, String20 firstName, String20 lastName, int id, int dropOffPoint, int seatNumber, struct Bus *bus, int nReserve);

<h3>searchPassengerId(struct Bus trips[], int searchId)</h3>
<em>Pre-condition: the trips array was initialized </em> <br />
Searches for a passenger with a specified id number throughout all the trips in the <code>trips[]</code> array
<ul>
<li> <code>trips[]</code> is the array of trips where the function will search for the passenger</li>
<li> <code>searchId</code> is the id to search for</li>
<li> <code>return</code> is the <code>1</code> if the passenger is found, otherwise is <code>0</code> </li>
</ul>

    int searchPassengerId(struct Bus trips[], int searchId);

<h3>encodePassengerInformation(struct Bus trips[])</h3>
<em>Pre-condition: the trips array was initialized </em> <br />
Taken in user input and validates them before calling inputPassenger. The function takes in all input required for inputting a passenger.
<ul>
<li> <code>trips[]</code> is the array of trips to encode the passenger information to</li>
</ul>

    void encodePassengerInformation(struct Bus trips[]); 

<h3>getBusFull(struct Bus trips[], int *nFullA, int *nFullB) </h3>
<em>Pre-condition: the trips array was initialized </em> <br />
Sets two integers <code>nFullA</code> and <code>nFullB</code> to the fullness of their corresponding trips. <code>nFullA</code> corresponds to the Manila-to-Laguna line of trips, while <code>nFullB</code> to the Laguna-to-Manila line of trips. The function will check if all buses in either of the trip lines is full and then set the corresponding varialbes to <code>1</code> if they are, along with linking the special trip for that line of trips.
<ul>
<li> <code>trips[]</code> is the array of bus trips</li>
<li> <code>nFullA</code> is a pointer to the variable that determines if the Manila-to-Laguna trip line is already full</li>
<li> <code>nFullB</code> is a pointer to the variable that determines if the Laguna-to-Manila trip line is already full</li>
</ul>

    void getBusFull(struct Bus trips[], int *nFullA, int *nFullB); 

<h2 id="o-personnel-funcs"> Arrow Personnel Functions </h2>

<h3>displayPassengerCount(struct Bus bus) </h3>
Shows the passenger count and a visual representation of the entire bus. 

<ul>
    <li> <code>bus</code> is the bus of which to show the passenger count of</li>
</ul>

The visual representation follows this format. Each <code>X</code> represents a space that is occupied, and each <code>O</code> represents a space that is empty.

<h4> For a bus with 13 OR LESS passengers:</h4> 

    +-----+-----+-----+
    |  X  |  X  |  X  |
    +-----+-----+-----+
    +-----+-----+-----+
    |  X  |  X  |  X  |
    +-----+-----+-----+
    +-----+-----+-----+
    |  X  |  X  |  X  |
    +-----+-----+-----+
    +-----+-----+-----+
    |  X  |  X  |  X  |
    +-----+-----+-----+
    +-----+-----+
    |  O  |  D  |
    +-----+-----+

<h4> For a bus with MORE THAN 13 passengers:</h4> 

    +-----+-----+-----+-----+
    |  X  |  X  |  X  |  X  |
    +-----+-----+-----+-----+
    +-----+-----+-----+-----+
    |  X  |  X  |  X  |  X  |
    +-----+-----+-----+-----+
    +-----+-----+-----+-----+
    |  X  |  X  |  X  |  X  |
    +-----+-----+-----+-----+
    +-----+-----+-----+-----+
    |     |  X  |  X  |  X  |
    +-----+-----+-----+-----+
    +-----+-----+
    |  0  |  D  |
    +-----+-----+


<br />

    void displayPassengerCount(struct Bus bus);

<h3>viewPassengerCount(struct Bus trips[]) </h3>
<em>Pre-condition: the trips array was initialized</em> <br />
Asks the user to input a trip number and implements the displayPassengerCount function to display the passenger count for that trip

<ul>
    <li> <code>trips[]</code> is the array of trips </li>
</ul>

    void viewPassengerCount(struct Bus trips[])

<h3>viewDropOffCount(struct Bus trips[]) </h3>
<em>Pre-condition: the trips array was initialized</em> <br />
Asks the user to input a trip number and shows the amount passengers who will be disembarking on each drop off point

<ul>
    <li> <code>trips[]</code> is the array of trips </li>
</ul>

<br />

    void viewDropOffCount(struct Bus trips[])

<h3>viewPassengerInformation(struct Bus trips[]) </h3>
<em>Pre-condition: the trips array was initialized</em> <br />
Asks the user to input a trip number and displays the information of the passengers of that trip, including their first name, last name, id number, and priority number.

<ul>
    <li> <code>trips[]</code> is the array of trips </li>
</ul>

    void viewPassengerInformation(struct Bus trips[])

<h3>searchPassenger(struct Bus trips[]) </h3>
<em>Pre-condition: </em> <br />
Asks the user to input the last name of any passenger and shows the information of the passenger(s) with the last name specified

<ul>
    <li> <code>trips[]</code> is the array of trips </li>
</ul>

    void searchPassenger(struct Bus trips[])

<h3> loadPassengerFromFile(struct Bus trips[]) </h3>
<em>Pre-condition: the information in the file must be formatted properly</em> <br />
Asks the user to input a file, loads a passenger's information from the file and attempts to input them onto one of the trips based on the information scanned from the file. The only file format supported for this operation is <code>.txt</code>
<ul>
    <li> <code>trips[]</code> is the array of trips </li>
</ul>

The information in the file must be formatted as such:

    Trip Number: <trip number>
    Embarkation Point: <embark point in string format>
    Passenger Name: <lastName>, <firstName>
    ID Number: <id number>
    Priority: <priority number>
    Drop-Off Point: <drop-off point in string format>

<br />

    void loadPassengerFromFile(struct Bus trips[])

<h3> void loadTripFromFile() </h3>
<em>Pre-condition: the information in the file must be formatted properly </em> <br />
Asks the user to input the file name of the trip file and loads it for in-program viewing. The only file format supported for this operation is <code>.txt</code> and the format is exactly the same as specified in the <code>loadPassengerFromFile</code> function


    void loadTripFromFile()

<h2 id="o-menu-funcs">Menu Functions</h2>
Each menu function returns an <code>int</code> that is used in the main function. The value they return will determine the next screen to be processed on the following iteration of the main loop.

<h3> mainMenu() </h3>
Displays the main menu of the program. The user is prompted with 3 choices:
<ol>
    <li>To open the passenger screen</li>
    <li>To open the arrow personnel screen</li>
    <li>To exit the program</li>
</ol>

The user selects the action by inputting the corresponding number to their choice. Depending on the choice, the function will output a certain <code>int</code> that will be used to process the next screen function. The screen code for the main menu is <code>100</code>.

<ul>
<li> <code>param</code> </li>
</ul>

    void mainMenu()

<h3> passengerMenu(struct Bus trips[], int *nFullA, int *nFullB) </h3>
Displays the passenger menu and prompts the user with two choices:

<ol>
    <li>To input a passenger</li>
    <li>Return to the main menu</li>
</ol>

Similarly to the main menu function, the user selects the action by inputting the corresponding number to their choice. Depending on the choice, the function will output a certain <code>int</code> that will be used to process the next screen function. The screen code for the passenger menu is <code>200</code>.

<ul>
<li> <code>trips[]</code> is the array of trips</li>
<li> <code>nFullA</code> is the pointer to the variable that determines the fullness of the Manila-to-Laguna trip line</li>
<li> <code>nFullB</code> is the pointer to the variable that determines the fullness of the Laguna-to-Manila trip line</li>
</ul>

    int passengerMenu(struct Bus trips[], int *nFullA, int *nFullB)

<h3>arrowsPersonnelMenu(struct Bus trips[], int *nFullA, int *nFullB) </h3>
Displays the passenger menu and prompts the user with seven choices:

<ol>
    <li>To view a trip's passenger count</li>
    <li>To view a trip's drop-off count</li>
    <li>To view a trip's passenger information</li>
    <li>To load a passenger from a file</li>
    <li>To search for a passenger(s)</li>
    <li>To Load a recent trip from a file</li>
    <li>Return to the main menu</li>
</ol>

Similarly to the main menu function, the user selects the action by inputting the corresponding number to their choice. Depending on the choice, the function will output a certain <code>int</code> that will be used to process the next screen function. The screen code for the arrows personnel menu is <code>300</code>.

<ul>
<li> <code>trips[]</code> is the array of trips</li>
<li> <code>nFullA</code> is the pointer to the variable that determines the fullness of the Manila-to-Laguna trip line</li>
<li> <code>nFullB</code> is the pointer to the variable that determines the fullness of the Laguna-to-Manila trip line</li>
</ul>

    int arrowsPersonnelMenu(struct Bus trips[], int *nFullA, int *nFullB)

<h2 id="m-main-func">The Main Function</h2>

The main function first initializes important variables to be used by the program such as the <code>trips</code> array and both <code>nFullA</code> and <code>nFullB</code>.

The majority of the program's function runs in a while loop, managing the screen that the user currently has open

    while (screenState > 0)
    {
        int parentMenu = screenState - screenState % 100;

        if (parentMenu == 100) // Selected menu is main menu
            screenState = mainMenu();
        
        else if (parentMenu == 200) // Selected menu is passenger
        {
            screenState = passengerMenu(trips, &nFullA, &nFullB);
        }
        else if (parentMenu == 300) // Selected Menu is arrow personnel
        {
            screenState = arrowsPersonnelMenu(trips, &nFullA, &nFullB);
        }
    }

The loop will run until the <code>mainMenu</code> function returns <code>-1</code> to terminate the loop. 

The final thing the program does is attempt to save the trip information to a file. The user is prompted to input a date in the format <code>dd-mm-yyyy</code>. The program validates that the input is correctly formatted and the date input is valid, and then saves the file with the filename <code>dd-mm-yy.txt</code> in the directory where the application was run.
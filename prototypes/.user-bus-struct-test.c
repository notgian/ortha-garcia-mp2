#include <stdio.h>
#include <string.h>

int main()
{
    typedef char String30[31];

    struct user {
        String30 firstName;
        String30 lastName;
        int age; 
        int id;
    } ;

    typedef struct user bus[16];

    bus newBus;

    struct user passenger1;

    String30 fn = "John";
    String30 ln = "Doe";

    strcpy(passenger1.firstName, fn);
    strcpy(passenger1.lastName, ln);

    passenger1.age = 18;
    passenger1.id = 12412345;

    newBus[0] = passenger1;

    printf("Bus Passenger Information:\n");
    printf("First Name: %s\n", newBus[0].firstName);
    printf("Last Name: %s\n", newBus[0].lastName);
    printf("Age: %d\n", newBus[0].age);
    printf("ID: %d\n", newBus[0].id);
}
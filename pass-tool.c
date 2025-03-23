#include <stdio.h>
#include <string.h>

#include "structures.c"
#include "operations.c"

int main()
{
    printf("WARNING!\nTHIS IS A FILE ONLY FOR TESTING AND THEREFORE I HAVE NOT INCLUDED ANY SAFEGUARDS FOR DATA VALIDATION. USE AT YOUR OWN RISK!\n\n");

    String20 firstname, lastname, filename;
    int tripNo, id, priority, embarkPoint, dropOff;

    printf("Input trip number\n");
    scanf(" %d", &tripNo);

    printf("Input Embarkation Point:\n");
    scanf(" %d", &embarkPoint);

    printf("Input First Name:\n");
    scanf(" %s", firstname);

    printf("Input Last Name:\n");
    scanf(" %s", lastname);

    printf("Input Id number:\n");
    scanf(" %d", &id);

    printf("Input priority number:\n");
    scanf(" %d", &priority);

    printf("Input drop-off point:\n");
    scanf(" %d", &dropOff);

    printf("Input a filename for the generated passenger file:\n");
    scanf(" %s", filename);

    FILE *fp;
    fp = fopen(filename, "wb");

    fwrite(&tripNo, sizeof(int), 1, fp);        
    fwrite(&embarkPoint, sizeof(int), 1, fp);
    fwrite(firstname, sizeof(String20), 1, fp);
    fwrite(lastname, sizeof(String20), 1, fp);
    fwrite(&id, sizeof(int), 1, fp);
    fwrite(&priority, sizeof(int), 1, fp);
    fwrite(&dropOff, sizeof(int), 1, fp);

    printf("Expected output information:\n");
    printf("Trip Number       : %3d\n", tripNo);
    printf("Embarkation Point : %d\n", embarkPoint);
    printf("Passenger Name    : %s, %s\n", lastname, firstname);
    printf("ID Number         : %d\n", id);
    printf("Priority          : %d\n", priority);
    printf("Drop-Off Point    : %d\n\n", dropOff);

    fclose(fp);
}
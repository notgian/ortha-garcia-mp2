// Online C compiler to run C program online
#include <stdio.h>

int scanfN(char *message)
{
    int num;
    char c = ' ';
    int n;

    // while((scanf("%d%c", &num, &c) == 0 || 2) && (c != '\n'))
    // {
    //     while(getchar() !='\n');
    // }


    do
    {
        printf("%s", message);
        n = scanf("%d%c", &num, &c);
        printf("|%d|", c==' ');
        while(getchar() !='\n');
    }
    while((n == 0 || 2) && (c != '\n'));

    return num;
}


int main() {
    int x;
    
    x = scanfN("Enter Int: \n");
    

    printf("Int input: %d", x);

    return 0;
}
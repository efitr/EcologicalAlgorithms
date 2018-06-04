/*    Immigration-Emigration Models    */

/*  Alternatives immigration-emigration models
Queuing organisms, their population's net emigration rate is independent 
    of the queue size when the queue is greater than zero.
Non-queuing organisms, their population's net emigration rate depends 
    on the population number.
*/

/* The objective  
    What are the processes that cause population numbers to rise and fall.
    Depends on one basic feature, whether it is an open or closed system.
*/

/* Characterictics of the model 
    - 
*/

/* Characteristics of the program
    - This is an open system.
    - There is no track of specific individuals only the total number.
*/

/*Libraries I depend upon for some functions  */
#include <stdlib.h>
#include <studio.h>

/*Global variables, they can be changed through the whole program  */
#define MAXTIME 100
#define PRNTTIME 10
/*  */
int main(void)
{
    /* Every variable must have it's type predefined before be used */
    int ttt, event, n;
    int seed;
    double alpha, beta; /* individual immigrates with alpha rate per unit time
                           individual emigrates from the system with rate beta per unit time*/
    /* After the type assignment,you get to give the pertaining values to each one */
    alpha = beta = 0.1;
    n = 10;

    /*  */
    seed = 1456739853;
    srand48(seed);
    printf(" time pop\n");

    for(ttt=0;ttt<MAXTIME;ttt++)
    {
        event = 0;
        if(drand48()<alpha) event = 1;
        if(drand48()<beta) event = event - 1;
        n += event;
        if(n<0) n = 0;

        if(ttt%PRNTTIME==0)
            printf(" %3d    %-4d\n", ttt, n);
    }
    return(0);
}
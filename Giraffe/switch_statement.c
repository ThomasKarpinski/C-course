#include <stdio.h>
#include <stdlib.h>

void switchStatement(){
    char grade = 'A';

    switch(grade) {
        case 'A' :
            printf("You did great! ");
            break;
        case 'B' :
            printf("You did alright! ");
            break;
        case 'C' :
            printf("You did poorly! ");
            break;
        case 'D' :
            printf("You did bad! ");
            break;
        case 'F' :
            printf("You Failed! ");
            break;
        default :
            printf("Invalid Grade");
    }
}
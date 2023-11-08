#include <stdio.h>

int main() {
    double statement_PLN;
    double statement_USD;

    statement_PLN = 87.0;
    statement_USD = 97.0;

    char operation;

    printf("W - withdraw the money");
    printf("P - Put the money into account");
    printf("C - check the statement");
    printf("V - convert from USD to PLN or vice versa");
    printf("To choose the currency write P for PLN an U for USD\n");

    printf("Choose operation");
    scanf(" %c", &operation);

    switch (operation)
    {
    case 'W':
        double amount;
        char currency_w;
        printf("Enter the amount ");
        scanf(" %fl", &amount);
        printf("Enter the currency ");
        scanf(" %s", &currency_w);
        if (amount >= 0)
        {
            if (currency_w == 'P')
            {
                if(statement_PLN >= amount){
                    statement_PLN -= amount;
                }
                else{
                    printf("You don't have enough money");
                }
                printf("%fl", statement_PLN);
            }
            else if(currency_w == 'U'){
                if(statement_USD >= amount){
                    statement_USD -= amount;
                }
                else{
                    printf("You don't have enough money");
                }
                printf("%fl", statement_USD);
            }
            else{
                printf("Invalid currency");
            }
            
        }
        else{
            printf("Invalid value");
        }
        
        break;
    case 'P':
        double amount_to_put;
        char currency_p;
        printf("Enter the amount to put ");
        scanf(" %fl", &amount_to_put);
        printf("Enter the currency ");
        scanf(" %s", &currency_p);

        if (amount_to_put >= 0)
        {
            if (currency_p == 'P')
            {
                statement_PLN += amount_to_put;
            }
            else if(currency_p == 'U'){
                statement_USD += amount_to_put;
            }
            else{
                printf("Invalid currency");
            }
            
        }
        else{
            printf("Invalid value");
        }
        
        break;
    case 'C':
        char currency_c;
        printf("Choose currency ");
        scanf(" %s", &currency_c);
        if(currency_c == 'P'){
            printf("%fl", statement_PLN);
        }
        else if(currency_c == 'U'){
            printf("%fl", statement_USD);
        }
        else {
            printf("Invalid currency");
        }
        break;
    case 'V':
        double amount_to_conv;
        char currency_v;

        printf("Enter the amount of money to convert ");
        scanf(" %fl", &amount_to_conv);
        printf("Enter the currency to convert to another ");
        scanf(" %s", &currency_v);

        if(amount_to_conv >= 0){
            if (currency_v == 'P')
            {
                amount_to_conv /= 4.14;
                statement_USD += amount_to_conv;
            }
            else if (currency_v == 'U')
            {
                amount_to_conv *=4.14;
                statement_PLN += amount_to_conv;
            }
            else{
                printf("Invalid currency");
            }
            
        }
        else{
            printf("Invalid value");
        }
        break;
    
    default:
        printf("Something has gone wrong");
        break;
    }

    return 0;
}
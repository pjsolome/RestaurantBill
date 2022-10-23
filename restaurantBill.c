#include <stdio.h>
#include <stdlib.h> 
#include <time.h> 

//Meal structure
typedef struct {
char *name;
double price;
} Meal;

int main(int argc, char *argv[]) {

    //Check for correct amount of arguments
    if(argc == 3) {

        //Declare and initialize meals
        Meal salad;
        Meal soup;
        Meal sandwich;
        Meal pizza;

        salad.name = "Salad";
        salad.price = 9.95;

        soup.name = "Soup";
        soup.price = 4.55;

        sandwich.name = "Sandwich";
        sandwich.price = 13.25;

        pizza.name = "Pizza";
        pizza.price = 22.35;

        //Randomly choose meal
        Meal toBeCalculated;
        time_t t;
        int randomNum;

        srand((unsigned) time(&t)); 
        randomNum = rand() % 4;

        if(randomNum == 0) {
            toBeCalculated = salad;
        } else if(randomNum == 1) {
            toBeCalculated = soup;
        } else if(randomNum == 2) {
            toBeCalculated = sandwich;
        } else {
            toBeCalculated = pizza;
        }

        //Display meal cost
        printf("%s: $%d\n", toBeCalculated.name, toBeCalculated.price);

        //Display tax amount
        double taxInput = strtod(argv[1], NULL);
        double taxAmount = (taxInput / 100) * toBeCalculated.price;
        printf("Tax: $%d\n", taxAmount);

        //Display tip amount
        double tipInput = strtod(argv[2], NULL);
        double tipAmount = (tipInput / 100) * toBeCalculated.price;
        printf("Tip: $%d\n", tipAmount);

        // Display total bill
        double total = toBeCalculated.price + taxAmount + tipAmount;
        printf("Total: $%d\n", total);
        
        return 0;
    } else if(argc > 3) {
        printf("Too many arguments supplied\n");
        return 1;
    } else {
        printf("Two arguments expected\n");
        return 1;
    }
}
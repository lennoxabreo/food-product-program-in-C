
// Description: Program that allows user to enter food product option and find the respective prices, HST and totals



#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <ctype.h>



#define A "Candy "

#define A_P 4.55

#define B "Flour "

#define B_P 1.5

#define C "Soup "

#define C_P 2.88

#define D "Walnuts "

#define D_P 5.25

#define E "Rice "

#define E_P 1.05

#define F "Noodles "

#define F_P 0.35

#define G "Sugar "

#define G_P 0.92

#define H "Cake "

#define H_P 1.45



#define NUM_PRODUCTS 8

#define HST 0.13



//  product structure

typedef struct

{

    char code;

    char name[10];

    double price;

    double pounds;

} prod_uct;



// product information

void initializeProducts(prod_uct products[])

{

    int i = 0;

    char *codes = "ABCDEFGHI";

    char *names[] = { A, B, C, D, E, F, G, H };

    double prices[] = { A_P, B_P, C_P, D_P, E_P, F_P, G_P, H_P };

    for (i = 0; i < NUM_PRODUCTS; i++){

        products[i].code = codes[i];

        strcpy(products[i].name, names[i]);

        products[i].price = prices[i];

        products[i].pounds = 0;}

}



// Printing the products and the calculations

void printMenu(prod_uct products[]){

    int i = 0;

    double totalPounds = 0;

    double totalSubtotal = 0;

    double average = 0;

    double hstTax = 0;



// Displaying the menu

    printf("BULK FOOD STORE PROGRAM\n");

    printf("\n");

    printf("%-7s%-15s%-10s%-10s%-8s\n", "Item", "Description", "Cost/lb", "# Pounds", "Subtotal");

    printf("\n");

    

    for (i = 0; i < NUM_PRODUCTS; i++){

        printf("%-7c", products[i].code);

        printf("%-15s", products[i].name);

        printf("%-10.2lf", products[i].price);

        printf("%-10.2lf", products[i].pounds);

        printf("$%-7.2lf", products[i].price * products[i].pounds);

        printf("\n");

        

        totalSubtotal += products[i].price * products[i].pounds;

        totalPounds += products[i].pounds;}

    

    printf("\n");

    if (totalPounds > 0){

        average = totalSubtotal / totalPounds;}

    hstTax = totalSubtotal * HST;

    printf("Total Pounds = %.2lf\tSUBTOTAL     = $%.2lf\n", totalPounds, totalSubtotal);

    printf("Avg. Cost/lb = %.2lf\tHST Amount   = $%.2lf\n", average, hstTax);

    printf("\n");

    printf("\t\t\tTotal Amount = $%.2lf\n", (totalSubtotal + hstTax));

    printf("\n");}



// Given a letter, we decide the right array index

int letterToProductIndex(char letter){

    int index = letter - 'a';

    if (index >= 0 && index < NUM_PRODUCTS){

        return index;}

    return -1;}



// Clear out the stdin after input

void clearInput(){

    int c = 0;

    while ((c = getchar()) != '\n' && c != EOF);}



// Add a new product to the order

void addProduct(prod_uct products[], int productIndex){

    double pounds = 0;

    if (productIndex == -1){

        

// Beep for invalid option

        printf("Error: Invalid option.\n");

        printf("\7");

        return;}

    

    printf("Enter number of pounds: ");

    scanf("%lf", &pounds);

    clearInput();

    if (pounds <= 0){

        

// Beep for invalid pounds

        printf("Error: Invalid pounds, make it positive.\n");

        printf("\7");

        return;}

    

    products[productIndex].pounds += pounds;

    printf("Ok: Order accepted.\n");}



// Entry point of the program

int main(){

    prod_uct products[NUM_PRODUCTS];

    char choice = ' ';



    

// Programmers Block

       printf("Name: Lennox Dabre \n");

       printf("Description: Program that allows user to enter food product option and find the respective prices, HST and totals\n");

       printf("\n");

    

    initializeProducts(products);

    while (choice != 'q'){

// Let the user decide what to do



        printMenu(products);

        printf("Your choice (R to reset, Q to quit): ");



// Evaluate the user's option

        if (scanf("%c", &choice) == 1){

            choice = tolower(choice);

            switch (choice){

                    case 'r':

// Reset

                    initializeProducts(products);

                    printf("Ok: Menu has been reset.\n");

                    break;

                case 'q':

// Quit

                    printf("Ok: Goodbye.\n");

                    printf("HIT ANY KEY TO CONTINUE ...\n");

                    break;

                default:

                    addProduct(products, letterToProductIndex(choice));}}

        else{

            printf("Error: Please enter a character.");}

        printf("\n");

        clearInput();}

    system("pause");
    return 0;}

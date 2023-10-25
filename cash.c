#include <cs50.h>
#include <stdio.h>
#include <math.h>

float get_cents(void); 
int calculate_quarters(float cents);
int calculate_dimes(float cents);
int calculate_nickels(float cents);
int calculate_pennies(float cents);


int main(void)
{   
    float cents;
    do
    {
        // Ask how many cents the customer is owed
        cents = get_float("how many cents the customer is owed = ");
    }
    while (cents < 0);
    cents = (cents * 100);
    
    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}


float get_cents(void)
{
    float cents;
    do
    {
        // Ask how many cents the customer is owed
        cents = get_float("how many cents the customer is owed = ");
    }
    while (cents < 0);
    cents = (cents * 100);
    return  cents;
    
}


int calculate_quarters(float cents)
{
    // TODO
    int quarters = (cents / 25);
    return quarters;
}

int calculate_dimes(float cents)
{
    // TODO
    int dimes = (cents / 10);
    return dimes;
}

int calculate_nickels(float cents)
{
    // TODO
    int nickels = (cents / 5);
    return nickels;
}

int calculate_pennies(float cents)
{
    // TODO
    int pennies = (cents / 1);
    pennies = round(pennies);
    return pennies;
}
#include <stdio.h>
#include <stdbool.h>

//function for convertions btwn km/M
void KmM() {
    char value;
    float calculation;
    printf("Input either K or M to specify Kilometre or Mile: ");
    scanf(" %c", &value);
    if (value == 'K') {
        printf("Input the value you would like to be converted from kilometres to miles: ");
        scanf(" %f", &calculation);
        printf(" %f kilometres is equivelant to %f miles\n", calculation, calculation/1.609);
    }
    else if (value == 'M') {
        printf("Input the value you would like to be converted from miles to kilometres: ");
        scanf(" %f", &calculation);
        printf(" %f miles is equivelant to %f kilometres\n", calculation, calculation*1.609);
    }
}

//function for convertions btwn M/F
void MF() {
    char value;
    float calculation;
    printf("Input either M or F to specify Meters or Feet: ");
    scanf(" %c", &value);
    if (value == 'M') {
        printf("Input the value you would like to be converted from Meters to Feet: ");
        scanf(" %f", &calculation);
        printf(" %f meters is equivelant to %f feet\n", calculation, calculation*3.281);
    }
    else if (value == 'F') {
        printf("Input the value you would like to be converted from Feet to Meters: ");
        scanf(" %f", &calculation);
        printf(" %f feet is equivelant to %f meters\n", calculation, calculation/3.281);
    }
}

//function for convertions btwn cm/in
void CmIn() {
    char value;
    float calculation;
    printf("Input either C or I to specify Centimeters or Inch: ");
    scanf(" %c", &value);
    if (value == 'C') {
        printf("Input the value you would like to be converted from Centimeters to Inch: ");
        scanf(" %f", &calculation);
        printf(" %f centimeters is equivelant to %f inches\n", calculation, calculation/2.54);
    }
    else if (value == 'I') {
        printf("Input the value you would like to be converted from Inch to Centimeters: ");
        scanf(" %f", &calculation);
        printf(" %f inches is equivelant to %f centimeters\n", calculation, calculation*2.54);
    }
}

//function for convertions btwn C/F
void CF() {
    char value;
    float calculation;
    printf("Input either C or F to specify Celsius or Fahrenheit: ");
    scanf(" %c", &value);
    if (value == 'C') {
        printf("Input the value you would like to be converted from Celsius to Fahrenheit: ");
        scanf(" %f", &calculation);
        printf(" %f celsius is equivelant to %f fahrenheit\n", calculation, ((calculation*9/5)+32));
    }
    else if (value == 'F') {
        printf("Input the value you would like to be converted from Fahrenheit to Celsius: ");
        scanf(" %f", &calculation);
        printf(" %f fahrenheit is equivelant to %f celsius\n", calculation, ((calculation - 32)*5/9));
    }
}

int main (void) {
    //create variables
    int choice = 0;
    bool val = true;
    while (val) {
        //prompt user message...
        printf("\nHello!, welcome to the converter:\n Enter a conversion type:\n 1. Kilometer/Mile\n 2. Meter/Feet\n 3. Centimetre/Inch\n 4. Celsius/Fahrenheit\n 5. Quit\n");
        //store ans as integer
        scanf("%d", &choice);
        // if want km/m
        if (choice == 1){
            //run and print function
            KmM();      
        } else if (choice == 2){
            MF();
        } else if (choice == 3){
            CmIn();
        } else if (choice == 4){
            CF();
        } else if (choice == 5){
            printf("You have exited the converter!\n");
            //set val to equal 0 and thus exit the while loop...
            val = false;
        } else {
            //to re-enter loop function
            printf("Invaid!, please try again.\n");
            //val = true;
        }
    }
    return 0;
}
/* This program uses a nested struct to create a contact system that is searchable where the user can input name, address and phone numbers.
 After all input has been entered, this program will display the contact's details in a summary. */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// function definitions
// gets and stores from standard input the values for Name
void getName(struct Name *fullName) {
    
    char yesNo[3] = "y";    //string comparison for whether user entered 'y' for yes
    
    printf("Please enter the contact's first name: ");
    readString(fullName->firstName, 31);
    
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    readString(yesNo, 3);
    if (strcasecmp (yesNo, "y") == 0) {     //string compare to see if user answered 'y' (yes)
        printf("Please enter the contact's middle initial(s): ");
        readString(fullName->middleInitial, 7);
        yesNo[0] = '\0';    //to reset variable yesNo
    }
    
    printf("Please enter the contact's last name: ");
    readString(fullName->lastName, 36);
}

// gets and stores from standard input the values for Address
void getAddress(struct Address *fullAddress) {
    
    char buffer[10] = {"\0"};
    
    char yesNo[3] = "y";    //string comparison for whether user entered 'y' for yes
    
    do {
        printf("Please enter the contact's street number: ");
        readString(buffer, 10);
        fullAddress->streetNumber = atoi(buffer);   //convert string to integer
    } while (fullAddress->streetNumber <= 0);	//check to make sure street number is > 0
    
    printf("Please enter the contact's street name: ");
    readString(fullAddress->street, 41);
    
    printf("Do you want to enter an appartment number? (y or n): ");
    readString(yesNo, 3);
    if( strcasecmp (yesNo, "y") == 0) {     //string compare to see if user answered 'y' (yes)
        do {
            printf("Please enter the contact's appartment number: ");
            readString(buffer, 10);
            fullAddress->apartmentNumber = atoi(buffer);
        } while (fullAddress->apartmentNumber <= 0);	//check to make sure apartment number is > 0
        yesNo[0] = '\0';    //to reset variable yesNo
    }
    
    printf("Please enter the contact's postal code: ");
    readString(fullAddress->postalCode, 9);
    
    printf("Please enter the contact's city: ");
    readString(fullAddress->city, 41);
}

// gets and stores from standard input the values for Numbers
void getNumbers(struct Numbers *allPhones) {
    
    char yesNo[3] = "y";    //string comparison for whether user entered 'y' for yes
    
    printf("Do you want to enter a cell phone number? (y or n): ");
    readString(yesNo, 3);
    if( strcasecmp (yesNo, "y") == 0) {     //string compare to see if user answered 'y' (yes)
        printf("Please enter the contact's cell phone number: ");
        readString(allPhones->cell, 21);
        yesNo[0] = '\0';    //to reset variable yesNo
    }
    
    printf("Do you want to enter a home phone number? (y or n): ");
    readString(yesNo, 3);
    if( strcasecmp (yesNo, "y") == 0) {     //string compare to see if user answered 'y' (yes)
        printf("Please enter the contact's home phone number: ");
        readString(allPhones->home, 21);
        yesNo[0] = '\0';    //to reset variable yesNo
    }
    
    printf("Do you want to enter a business phone number? (y or n): ");
    readString(yesNo, 3);
    if( strcasecmp (yesNo, "y") == 0) {     //string compare to see if user answered 'y' (yes)
        printf("Please enter the contact's business phone number: ");
        readString(allPhones->business, 21);
        yesNo[0] = '\0';    //to reset variable yesNo
    }
}

//function to remove last character \n
void readString (char *myString, int length) {  
    char buffer[255];                   //array called buffer to hold 255 characters
    fgets(buffer, 255, stdin);		//input function
    buffer [strlen(buffer)-1]= '\0';	//removes new line character by setting it to NULL
    strncpy(myString, buffer, length);	//takes what is in buffer and copy it to myString
    myString[length -1]='\0';		//makes sure that myString has NULL character at the end
}


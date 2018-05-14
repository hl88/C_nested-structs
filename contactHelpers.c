/* This implementation file contains helper functions for contact.c to help reduce redundant coding for common repetative tasks.*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "contacts.h"
#include "contactHelpers.h"

#define MAXCONTACTS 5


// clearKeyboard function clears the standard input buffer
void clearKeyboard(void)
{
    while (getchar() != '\n')   ; // empty execution code block on purpose
}

// pause function pauses execution of the application
int pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
    return 0;
}

// getInt function gets a valid integer from the keyboard and returns it
// if integer is invalid, an error message is displayed
int getInt(void)
{
    int value = 0;
    
    char NL='x';
    
    while (NL != '\n') {
        scanf("%d%c", &value, &NL);
        
        if(NL != '\n') {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
    }
    return value;
}

// getIntInRange function uses getInt function to receive a valid integer and returns it only if the value entered is within the lower-bound and upper-bound range (inclusive)
int getIntInRange(int a, int b)
{
    while (1) {
        
        int x = getInt();
        
        if (x >= a && x <= b) {
            return x;
        } else {
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", a, b);
        }
    }
    return 0;
}

// yes function prompts user for single character entry
// character entered is valid only if it is 'Y' or 'y' or 'N' or 'n'
int yes(void)
{
    char value = '\0';
    
    char NL='x';
    
    while (NL != '\n') {
        scanf("%c%c", &value, &NL);
        
        if(NL != '\n' || (value != 'Y' && value != 'y' && value != 'N' && value != 'n')) {
            clearKeyboard();
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        }
    }
    
    if (value == 'Y' || value == 'y') {
        return 1;
    } else {
        return 0;
    }
}

// menu function prints a menu option and checks the input to see if it's within range
int menu(void)
{
    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n");
    printf("\n");
    printf("Select an option:> ");
    
    while (1) {
        int y = getInt();
        if (y >= 0 && y <= 6) {
            return y;
        } else {
            printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
        }
    }
    
    return 0;
}

// ContactManagerSystem function determines if the user's entered option is available
void ContactManagerSystem(void)
{
    struct Contact contact [MAXCONTACTS] =
    { { { "Rick", {'\0'}, "Grimes" },
        { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
        { "4161112222", "4162223333", "4163334444" } },
        {
            { "Maggie", "R.", "Greene" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9051112222", "9052223333", "9053334444" } },
        {
            { "Morgan", "A.", "Jones" },
            { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" }, { "7051112222", "7052223333", "7053334444" } },
        {
            { "Sasha", {'\0'}, "Williams" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9052223333", "9052223333", "9054445555" } },
        {
            { "", {'\0'}, "" },
            { 55, "", 0, "", "" },
            { "", "", "" } },
    };
    
    
    int flag = 0;
    
    while (flag == 0) {
        
        int z = menu();
        
        if (z == 1) {
            displayContacts(contact, MAXCONTACTS);
            pause();
            printf("\n");
        } else if (z == 2) {
            printf("\n");
            addContact(contact, MAXCONTACTS);
            pause();
            printf("\n");
        } else if (z == 3 ) {
            updateContact(contact, MAXCONTACTS);
            pause();
            printf("\n");
        } else if (z == 4) {
            deleteContact(contact, MAXCONTACTS);
            pause();
            printf("\n");
        } else if (z == 5) {
            searchContacts(contact, MAXCONTACTS);
            pause();
            printf("\n");
        } else if (z == 6) {
            sortContacts(contact, MAXCONTACTS);
            printf("\n");
            printf("--- Contact sorted! ---\n");
            pause();
            printf("\n");
        } else {
            printf("\nExit the program? (Y)es/(N)o: ");
            
            if (yes()) {
                printf("\nContact Management System: terminated");
                flag = 1;
            }
            
            printf("\n");
            
        }
    }
}

// generic function to get a ten-digit phone number (ensures 10 chars entered)
void getTenDigitPhone(char telNum[11])
{
    int needInput = 1;
    
    while (needInput == 1) {
        scanf("%10s", telNum);
        clearKeyboard();
        
        // (String Length Function: validate entry of 10 characters)
        if (strlen(telNum) == 10)
            needInput = 0;
        else
            printf("Enter a 10-digit phone number: ");
    }
}


// finds a contact based on the provided cell phone number and returns the index
// if the contact is not found, the function should return -1
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{
    int i;
    
    //linear search
    for (i = 0; i < size; i++) {
        if (strcmp (cellNum, contacts[i].numbers.cell) == 0) {
            return i;
        }
    }
    return -1;
}


// displays a centered title “Contacts Listing” header that is surrounded in a border
void displayContactHeader(void)
{
    printf("\n");
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
}

// displays a line and a total contact summary
void displayContactFooter(int a)
{
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n\n", a);
}

// displays the details for a single contact
void displayContact(const struct Contact *contact)
{
    if (strcmp (contact->name.middleInitial, "") == 0) {
        printf(" %s %s\n", contact->name.firstName, contact->name.lastName);
    } else {
        printf(" %s %s %s\n", contact->name.firstName, contact->name.middleInitial, contact->name.lastName);
    }
    
    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
    
    if (contact->address.apartmentNumber <= 0){
        printf("       %d %s, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.city, contact->address.postalCode);
    } else {
        printf("       %d %s, Apt# %d, %s, %s\n", contact->address.streetNumber, contact->address.street, contact->address.apartmentNumber, contact->address.city, contact->address.postalCode);
    }
}

// displays a title header, a detail listing of each VALID contact in the array and a footer section showing the total number of contacts
void displayContacts(const struct Contact contact[], int size)
{
    displayContactHeader();
    
    int i;
    
    int count = 0;
    
    for (i = 0; i < size; i++) {
        if (strcmp (contact[i].numbers.cell, "") != 0 ) {
            displayContact(&contact[i]);
            count++;
        }
    }
    displayContactFooter(count);
}

// prompts the user to search the contact listings based on a cell phone number
void searchContacts(const struct Contact contacts[], int size)
{
    char telNum[11];
    
    printf("\nEnter the cell number for the contact: ");
    getTenDigitPhone(telNum);
    
    int index = findContactIndex(contacts, size, telNum);  //index in the array for found contact
    
    if (index == -1) {
        printf("*** Contact NOT FOUND ***");
        printf("\n");
    } else {
        printf("\n");
        displayContact(&contacts[index]);
        printf("\n");
    }
}

// determines if there is an available slot in the contact array
void addContact(struct Contact contacts[], int size)
{
    int i;
    
    for (i = 0; i < size; i++) {
        
        char *x = contacts[i].numbers.cell;
        
        if (strlen(x) == 0) {
            getContact(&contacts[i]);
            printf("--- New contact added! ---\n");
            return;
        }
    }
    printf("*** ERROR: The contact list is full! ***\n");
    
}

// prompts the user for the cell phone number of the contact to update
void updateContact(struct Contact contacts[], int size)
{
    char telNum[11];
    
    printf("\nEnter the cell number for the contact: ");
    getTenDigitPhone(telNum);
    
    int index = findContactIndex(contacts, size, telNum);  //index in the array for found contact
    
    if (index == -1) {
        printf("*** Contact NOT FOUND ***\n");
        return;
    }
    
    printf("\n");
    printf("Contact found:");
    printf("\n");
    displayContact(&contacts[index]);
    printf("\n");
    
    printf("Do you want to update the name? (y or n): ");
    
    if (yes()) {
        getName(&contacts[index].name);
    }
    
    printf("Do you want to update the address? (y or n): ");
    
    if (yes()) {
        getAddress(&contacts[index].address);
    }
    
    printf("Do you want to update the numbers? (y or n): ");
    if (yes()) {
        getNumbers(&contacts[index].numbers);
    }
    
    printf("--- Contact Updated! ---\n");
    
}

// prompts the user for the cell phone number of the contact to delete from the list
void deleteContact(struct Contact contacts[], int size)
{
    char telNum[11];
    
    printf("\nEnter the cell number for the contact: ");
    getTenDigitPhone(telNum);
    
    int index = findContactIndex(contacts, size, telNum);  //index in the array for found contact
    
    if (index == -1) {
        printf("*** Contact NOT FOUND ***\n");
        return;
    }
    
    
    printf("\n");
    printf("Contact found:");
    printf("\n");
    displayContact(&contacts[index]);
    printf("\n");
    
    printf("CONFIRM: Delete this contact? (y or n): ");
    
    if (yes()) {
        contacts[index].numbers.cell[0] = '\0';
        printf("--- Contact deleted! ---\n");
    }
    
}

// reorders the elements in the contacts array from lowest to highest based on the cell phone numbers
void sortContacts(struct Contact contacts[], int size)
{
    int i, j, m;
    struct Contact tempContact;
    size = MAXCONTACTS;
    
    for (i = 0; i < size-1; i++) {
        m = i;
        for (j = i + 1; j < size; j++)
            if (strcmp (contacts[j].numbers.cell , contacts[m].numbers.cell) < 0 ) {
                m = j;
            }
        if (m != i) {
            tempContact = contacts[i];
            contacts[i] = contacts[m];
            contacts[m] = tempContact;
        }
    }
}



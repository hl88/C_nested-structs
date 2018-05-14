/* This program uses a nested struct to create a contact system that is searchable where the user can input name, address and phone numbers.
 After all input has been entered, this program will display the contact's details in a summary.
 
 This is the header file for contacts.c */

// structure type Name declaration for first name, middle initial, and last name
struct Name {
    char firstName[31];
    char middleInitial[7];
    char lastName[36];
};

// structure type Address declaration for street number, name, apartment number, postal code, and city
struct Address {
    int streetNumber;
    char street[41];
    int apartmentNumber;
    char postalCode[8];
    char city[41];
};

// structure type Numbers declaration for all phone numbers: cell, home, business
struct Numbers {
    char cell[21];
    char home[21];
    char business[21];
};

// structure type Contact declaration for name, address and numbers
struct Contacts {
    struct Name name;
    struct Address address;
    struct Numbers numbers;
};

// function prototype to get name, address and phone numbers
void getName(struct Name *);
void getAddress(struct Address *);
void getNumbers(struct Numbers *);

// function prototype to remove last character '\n'
void readString(char *, int);

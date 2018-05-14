/* Description: This is the header file for contactHelpers.h. It modularizes general helper functions to
help reduce redundant coding for common repetative tasks. */


//------------------------------------------------------
// Function Prototypes
//------------------------------------------------------


// clearKeyboard function clears the standard input buffer
void clearKeyboard(void);

// pause function pauses execution of the application
int pause(void);

// getInt function gets a valid integer from the keyboard and returns it
// if integer is invalid, an error message is displayed
int getInt(void);

// getIntInRange function uses getInt function to receive a valid integer and returns it only if the value entered is within the lower-bound and upper-bound range (inclusive)
int getIntInRange(int, int);

// yes function prompts user for single character entry
// character entered is valid only if it is 'Y' or 'y' or 'N' or 'n'
int yes(void);

// menu function prints a menu option and checks the input to see if it's within range
int menu(void);

// ContactManagerSystem function determines if the user's entered option is available
void ContactManagerSystem(void);

// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char[11]);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact[], int, const char[]);

// displayContactHeader
// put function prototype here:
void displayContactHeader(void);

// displayContactFooter:
// put function prototype here:
void displayContactFooter(int);

// displayContact:
// put function prototype here:
void displayContact(const struct Contact*);

// displayContacts:
// put function prototype here:
void displayContacts(const struct Contact[], int);

// searchContacts:
// put function prototype here:
void searchContacts(const struct Contact[], int);

// addContact:
// put function prototype here:
void addContact(struct Contact[], int);

// updateContact:
// put function prototype here:
void updateContact(struct Contact[], int);

// deleteContact:
// put function prototype here:
void deleteContact(struct Contact[], int);

// sortContacts:
// put function prototype here:
void sortContacts(struct Contact[], int);

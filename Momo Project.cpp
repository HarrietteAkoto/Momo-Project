#include <iostream>
using namespace std;
const int MAX_ATTEMPTS = 
3;
const int DEFAULT_PIN = 
0000;
const int 
DEFAULT_BALANCE = 1000;
// Function to authenticate the user
bool authenticate(int& pin, 
int& attempts) {
 int entered_pin;
 cout << "Enter your PIN: ";
 cin >> entered_pin;
 if (entered_pin == pin) {
 attempts = 0; // Reset the number of attempts
 return true;
 } else {
 attempts++;
 if (attempts >= 
MAX_ATTEMPTS) {
 cout << "Too many incorrect attempts. Exiting..." << endl;
 exit(0);
 } else {
 cout << "Incorrect PIN. Please try again." << endl;
 return false;
 }
 }
}
// Function to reset or change the PIN
void reset_pin(int& pin) {
 int old_pin, new_pin, 
confirm_pin;
 cout << "Enter your old PIN: ";
 cin >> old_pin;
 if (old_pin == pin) {
 cout << "Enter your new PIN: ";
 cin >> new_pin;
 cout << "Confirm your new PIN: ";
 cin >> confirm_pin;
 if (new_pin == 
confirm_pin) {
 pin = new_pin; // Set the new PINcout << "Your PIN has been changed successfully."
 } else {
 cout << "PINs do not match. Please try again." << endl;
 }
 } else {
 cout << "Incorrect old PIN. Please try again." << endl;
 }
}
// Function to check the user's balance
void check_balance(int 
balance) {
 cout << "Your balance is: " 
<< balance << endl;
}
// Function to send money to another user
void send_money(int& 
balance) {
 int amount, 
recipient_number;
 cout << "Enter the amount to send: ";
 cin >> amount;
 if (amount <= 0) {
 cout << "Invalid amount. Please try again." << endl;
 return;
 }
 if (amount > balance) {
 cout << "Insufficient funds. Please try again." << endl;
 return;
 }
 cout << "Enter the recipient's phone number: ";
 cin >> recipient_number;
 // TODO: Add code to send money to the recipient balance -= amount; 
 // Deduct the amount from the user's balance
 cout << "Money sent successfully." << endl;
}
int main() {
 int pin = DEFAULT_PIN;
 int balance = 
DEFAULT_BALANCE;
 int attempts = 0;
 int choice;
 do {
 cout << "1. Authenticate" << endl;
 cout << "2. Reset/change PIN" << endl;
 cout << "3. Check balance" << endl;
 cout << "4. Send money" << endl;
 cout << "5. Exit" << endl;
 cout << "Enter your choice: ";
 cin >> choice;
 switch (choice) {
 case 1:
 authenticate(pin, 
attempts);
 break;
 case 2:
 reset_pin(pin);
 break;
 case 3:
 
check_balance(balance);
 break;
 case 4:
 
send_money(balance);
 break;
 case 5:
 cout << "Exiting..." 
<< endl;
 break;
 default:
 cout << "Invalid choice. Please try again." << endl;
 }
 } while (choice != 5);
 return 0;
}

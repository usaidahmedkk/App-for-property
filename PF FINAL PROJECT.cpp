#include <iostream>
#include <string>

using namespace std;

string storedEmail = "";
string storedPassword = "";

struct Property {
    string location, type;
    double size, price;
};

const int MAX_PROPERTIES = 100;
Property properties[MAX_PROPERTIES];
int propertyCount = 0;

void registerUser() {
    cout << "Enter email: ";
    cin >> storedEmail;
    cout << "Enter password: ";
    cin >> storedPassword;
    cout << "Registration successful!" << endl;
}

void loginUser() {
    string email, password;
    cout << "Enter email: ";
    cin >> email;
    cout << "Enter password: ";
    cin >> password;

    if (email == storedEmail && password == storedPassword)
        cout << "Login successful! Welcome, " << email << "." << endl;
    else
        cout << "Invalid email or password." << endl;
}

void addProperty() {
    if (propertyCount >= MAX_PROPERTIES) {
        cout << "Property limit reached." << endl;
        return;
    }

    cout << "Enter location: ";
    cin >> properties[propertyCount].location;
    cout << "Enter size(sq.ft): ";
    cin >> properties[propertyCount].size;
    cout << "Enter price(rs): ";
    cin >> properties[propertyCount].price;
    cout << "Enter type(house,appartment,flat): ";
    cin >> properties[propertyCount].type;

    propertyCount++;
    cout << "Property listed." << endl;
}

void displayProperties() {
    if (propertyCount == 0) {
        cout << "No properties available." << endl;
        return;
    }

    for (int i = 0; i < propertyCount; i++) {
        cout << "Property #" << (i + 1) << endl;
        cout << "Location: " << properties[i].location << endl;
        cout << "Size: " << properties[i].size << " sq ft" << endl;
        cout << "Price: " << properties[i].price<< "rs" << endl;
        cout << "Type: " << properties[i].type << endl;
    }
}


int main() {
    int choice;
    while (true) {
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. List Property" << endl;
        cout << "4. View Properties" << endl;
        cout << "5. Exit" << endl;
        cout << "Choose an option: ";
        cin >> choice;

        if (choice == 1) registerUser();
        else if (choice == 2) loginUser();
        else if (choice == 3) addProperty();
        else if (choice == 4) displayProperties();
        else if (choice == 5) break;
        else cout << "Invalid choice." << endl;
    }
    return 0;
}


#include <iostream>
#include <string>
using namespace std;

const int MAX_ROOMS = 10;

struct Room {
    int roomNumber;
    bool isBooked;
    string customerName;
};

Room rooms[MAX_ROOMS];

void initializeRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].isBooked = false;
        rooms[i].customerName = "";
    }
}

void displayAvailableRooms() {
    cout << "\nAvailable Rooms:\n";
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (!rooms[i].isBooked) {
            cout << "Room " << rooms[i].roomNumber << " is available." << endl;
        }
    }
}

void bookRoom() {
    int roomNumber;
    string customerName;

    cout << "\nEnter room number to book: ";
    cin >> roomNumber;

    if (roomNumber < 1 || roomNumber > MAX_ROOMS) {
        cout << "Invalid room number. Please try again." << endl;
        return;
    }

    if (rooms[roomNumber - 1].isBooked) {
        cout << "Room " << roomNumber << " is already booked." << endl;
    } else {
        cout << "Enter your name: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, customerName);

        rooms[roomNumber - 1].isBooked = true;
        rooms[roomNumber - 1].customerName = customerName;

        cout << "Room " << roomNumber << " has been successfully booked by " << customerName << "!" << endl;
    }
}

void viewBookings() {
    cout << "\nBooked Rooms:\n";
    bool anyBooked = false;

    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].isBooked) {
            cout << "Room " << rooms[i].roomNumber << " is booked by " << rooms[i].customerName << "." << endl;
            anyBooked = true;
        }
    }

    if (!anyBooked) {
        cout << "No rooms are currently booked." << endl;
    }
}

int main() {
    int choice;

    initializeRooms();

    do {
        cout << "\nHotel Management System\n";
        cout << "1. Display Available Rooms\n";
        cout << "2. Book a Room\n";
        cout << "3. View Bookings\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayAvailableRooms();
                break;
            case 2:
                bookRoom();
                break;
            case 3:
                viewBookings();
                break;
            case 4:
                cout << "Exiting the system. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

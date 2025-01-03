#include <iostream>
#include <string>
using namespace std;

const int MAX_ROOMS = 10;

struct Room {
    int roomNumber;
    bool isBooked;
    string customerName;
    string roomType; // New field for room type
    double rate;     // New field for room rate
};

Room rooms[MAX_ROOMS];

void initializeRooms() {
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].roomNumber = i + 1;
        rooms[i].isBooked = false;
        rooms[i].customerName = "";
        rooms[i].roomType = (i % 2 == 0) ? "Single" : "Double"; // Alternate room types
        rooms[i].rate = (i % 2 == 0) ? 50.0 : 100.0;            // Rates based on room type
    }
}
void displayAvailableRooms() {
    cout << "\nAvailable Rooms:\n";
    cout << "Room Number | Room Type | Rate\n";
    cout << "--------------------------------\n";
    for (int i = 0; i < MAX_ROOMS; i++) {
        if (!rooms[i].isBooked) {
            cout << "     " << rooms[i].roomNumber
                 << "       |  " << rooms[i].roomType
                 << "  | $" << rooms[i].rate << endl;
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

        if (customerName.empty()) {
            cout << "Name cannot be empty. Please try again." << endl;
            return;
        }

        rooms[roomNumber - 1].isBooked = true;
        rooms[roomNumber - 1].customerName = customerName;

        cout << "Room " << roomNumber << " has been successfully booked by " << customerName << "!" << endl;
    }
}
void cancelBooking() {
    int roomNumber;

    cout << "\nEnter room number to cancel booking: ";
    cin >> roomNumber;

    if (roomNumber < 1 || roomNumber > MAX_ROOMS) {
        cout << "Invalid room number. Please try again." << endl;
        return;
    }

    if (!rooms[roomNumber - 1].isBooked) {
        cout << "Room " << roomNumber << " is not booked." << endl;
    } else {
        rooms[roomNumber - 1].isBooked = false;
        rooms[roomNumber - 1].customerName = "";

        cout << "Booking for room " << roomNumber << " has been successfully canceled." << endl;
    }
}
void viewBookings() {
    cout << "\nBooked Rooms:\n";
    cout << "Room Number | Room Type | Rate | Customer Name\n";
    cout << "----------------------------------------------------\n";
    bool anyBooked = false;

    for (int i = 0; i < MAX_ROOMS; i++) {
        if (rooms[i].isBooked) {
            cout << "     " << rooms[i].roomNumber
                 << "       |  " << rooms[i].roomType
                 << "  | $" << rooms[i].rate
                 << "  | " << rooms[i].customerName << endl;
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
        cout << "3. Cancel Booking\n";
        cout << "4. View Bookings\n";
        cout << "5. Exit\n";
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
                cancelBooking();
                break;
            case 4:
                viewBookings();
                break;
            case 5:
                cout << "Exiting the system. Thank you!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}

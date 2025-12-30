#include <iostream>
#include <string>
using namespace std;

#define SIZE 5   // Maximum tickets

string queue[SIZE];
int front = -1;
int rear = -1;

void enqueue() {
    if (rear == SIZE - 1) {
        cout << "Queue is full! Cannot add more tickets.\n";
    } else {
        string ticket;
        cout << "Enter customer ticket name: ";
        cin.ignore();
        getline(cin, ticket);

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = ticket;
        cout << "Ticket added successfully.\n";
    }
}

// Process next ticket (Dequeue)
void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty! No ticket to process.\n";
    } else {
        cout << "Processing ticket: " << queue[front] << endl;
        front++;
    }
}

void display() {
    if (front == -1 || front > rear) {
        cout << "No pending tickets.\n";
    } else {
        cout << "Pending tickets:\n";
        for (int i = front; i <= rear; i++) {
            cout << "- " << queue[i] << endl;
        }
    }
}

// Check if queue is empty
void isEmpty() {
    if (front == -1 || front > rear)
        cout << "Queue is empty.\n";
    else
        cout << "Queue is not empty.\n";
}

// Check if queue is full
void isFull() {
    if (rear == SIZE - 1)
        cout << "Queue is full.\n";
    else
        cout << "Queue is not full.\n";
}

// Cancel a customer ticket
void cancelTicket() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty. No ticket to cancel.\n";
        return;
    }

    string name;
    cout << "Enter ticket name to cancel: ";
    cin.ignore();
    getline(cin, name);

    int found = -1;
    for (int i = front; i <= rear; i++) {
        if (queue[i] == name) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        cout << "Ticket not found.\n";
    } else {
        for (int i = found; i < rear; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
        cout << "Ticket cancelled successfully.\n";
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- Customer Service Ticket System ---\n";
        cout << "1. Add Ticket (Enqueue)\n";
        cout << "2. Process Ticket (Dequeue)\n";
        cout << "3. Display Tickets\n";
        cout << "4. Check if Queue is Empty\n";
        cout << "5. Check if Queue is Full\n";
        cout << "6. Cancel Ticket\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: isEmpty(); break;
            case 5: isFull(); break;
            case 6: cancelTicket(); break;
            case 7: cout << "Program exited successfully.\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}

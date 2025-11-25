#include <iostream>
using namespace std;
struct Node {
    int patientID;
    Node* next;
};

Node* head = NULL;
//it inserts node at last of all nodes.
void insertAtEnd(int id)
 {
    Node* newNode = new Node();
    newNode->patientID = id;
    newNode->next = NULL;

    if (head == NULL) 
	{
        head = newNode;
        return;
    }

    // Go to last node
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}


void emergency(int id)
 {
    Node* newNode = new Node();
    newNode->patientID = id;
    newNode->next = head;
    head = newNode;
}


void displayPatients() {
    if (head == NULL) {
        cout << "No patients in the list.\n";
        return;
    }

    Node* temp = head;
    cout << "Current Patients: ";
    while (temp != NULL) {
        cout << temp->patientID << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int choice, id;

    while (true) {
        cout << "\n Hospital Patient System \n";
        cout << "1. Insert new patient at END\n";
        cout << "2. Insert emergency patient at BEGINNING\n";
        cout << "3. Display all patients\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Patient ID: ";
            cin >> id;
            insertAtEnd(id);
        }
        else if (choice == 2) {
            cout << "Enter Patient ID: ";
            cin >> id;
            emergency(id);
        }
        else if (choice == 3) {
            displayPatients();
        }
        else if (choice == 4) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}

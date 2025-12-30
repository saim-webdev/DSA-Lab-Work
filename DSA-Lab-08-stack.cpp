#include <iostream>
#include <string>
using namespace std;

#define SIZE 5   

string books[SIZE];  
int top = -1;         // Stack top

void pushBook() {
    if (top == SIZE - 1) {
        cout << "Stack Overflow! No more space for books.\n";
    } else {
        string book;
        cout << "Enter book name: ";
        cin.ignore();
        getline(cin, book);

        top++;
        books[top] = book;
        cout << "Book added successfully.\n";
    }
}

void popBook() {
    if (top == -1) {
        cout << "Stack Underflow! No books to remove.\n";
    } else {
        cout << "Removed book: " << books[top] << endl;
        top--;
    }
}

void peekBook() {
    if (top == -1) {
        cout << "Stack is empty. No top book.\n";
    } else {
        cout << "Top book: " << books[top] << endl;
    }
}

void displayBooks() {
    if (top == -1) {
        cout << "No books in stack.\n";
    } else {
        cout << "Books in stack (Top to Bottom):\n";
        for (int i = top; i >= 0; i--) {
            cout << "- " << books[i] << endl;
        }
    }
}

void isEmpty() {
    if (top == -1)
        cout << "Stack is empty.\n";
    else
        cout << "Stack is not empty.\n";
}

int main() {
    int choice;

    do {
        cout << "\n--- Book Management System ---\n";
        cout << "1. Add Book (Push)\n";
        cout << "2. Remove Book (Pop)\n";
        cout << "3. View Top Book (Peek)\n";
        cout << "4. Display All Books\n";
        cout << "5. Check if Stack is Empty\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: pushBook(); break;
            case 2: popBook(); break;
            case 3: peekBook(); break;
            case 4: displayBooks(); break;
            case 5: isEmpty(); break;
            case 6: cout << "Program exited successfully.\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 6);

    return 0;
}

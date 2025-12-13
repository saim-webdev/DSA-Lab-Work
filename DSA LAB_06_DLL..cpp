#include <iostream>
using namespace std;

/*
   Doubly Linked List Node
*/
struct Student
{
    int id;
    string name;
    int semester;
    float gpa;

    Student *prev;
    Student *next;
};

// Head pointer (start of list)
Student *head = NULL;

/*
   Create a new student node
*/
Student* createNode()
{
    Student *temp = new Student;

    cout << "Enter Student ID: ";
    cin >> temp->id;

    cin.ignore();   // clears input buffer

    cout << "Enter Name: ";
    getline(cin, temp->name);

    cout << "Enter Semester: ";
    cin >> temp->semester;

    cout << "Enter GPA: ";
    cin >> temp->gpa;

    temp->prev = NULL;
    temp->next = NULL;

    return temp;
}

/*
   Insert at beginning
*/
void insertAtBeginning()
{
    Student *temp = createNode();

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    cout << "Record inserted at beginning.\n";
}

/*
   Insert at end
*/
void insertAtEnd()
{
    Student *temp = createNode();

    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        // ptr was temp earlier
        Student *ptr = head;

        while (ptr->next != NULL)
            ptr = ptr->next;

        ptr->next = temp;
        temp->prev = ptr;
    }
    cout << "Record inserted at end.\n";
}

/*
   Insert at specific position
*/
void insertAtPosition()
{
    int pos;
    cout << "Enter position: ";
    cin >> pos;

    if (pos <= 1)
    {
        insertAtBeginning();
        return;
    }

    Student *ptr = head;
    for (int i = 1; i < pos - 1 && ptr != NULL; i++)
        ptr = ptr->next;

    if (ptr == NULL)
    {
        cout << "Invalid position.\n";
        return;
    }

    Student *temp = createNode();

    temp->next = ptr->next;
    temp->prev = ptr;

    if (ptr->next != NULL)
        ptr->next->prev = temp;

    ptr->next = temp;

    cout << "Record inserted at position " << pos << ".\n";
}

/*
   Delete from beginning
*/
void deleteFromBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Student *ptr = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete ptr;
    cout << "Record deleted from beginning.\n";
}

/*
   Delete from end
*/
void deleteFromEnd()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Student *ptr = head;

    if (ptr->next == NULL)
    {
        head = NULL;
        delete ptr;
        cout << "Record deleted from end.\n";
        return;
    }

    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->prev->next = NULL;
    delete ptr;

    cout << "Record deleted from end.\n";
}

/*
   Delete from specific position
*/
void deleteFromPosition()
{
    int pos;
    cout << "Enter position: ";
    cin >> pos;

    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    if (pos <= 1)
    {
        deleteFromBeginning();
        return;
    }

    Student *ptr = head;
    for (int i = 1; i < pos && ptr != NULL; i++)
        ptr = ptr->next;

    if (ptr == NULL)
    {
        cout << "Invalid position.\n";
        return;
    }

    if (ptr->next != NULL)
        ptr->next->prev = ptr->prev;

    if (ptr->prev != NULL)
        ptr->prev->next = ptr->next;

    delete ptr;
    cout << "Record deleted from position " << pos << ".\n";
}

/*
   Display from start to end
*/
void displayForward()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Student *ptr = head;
    cout << "\nStudent Records (Start to End):\n";

    while (ptr != NULL)
    {
        cout << "ID: " << ptr->id
             << ", Name: " << ptr->name
             << ", Semester: " << ptr->semester
             << ", GPA: " << ptr->gpa << endl;

        ptr = ptr->next;
    }
}

/*
   Display from end to start
*/
void displayBackward()
{
    if (head == NULL)
    {
        cout << "List is empty.\n";
        return;
    }

    Student *ptr = head;

    while (ptr->next != NULL)
        ptr = ptr->next;

    cout << "\nStudent Records (End to Start):\n";

    while (ptr != NULL)
    {
        cout << "ID: " << ptr->id
             << ", Name: " << ptr->name
             << ", Semester: " << ptr->semester
             << ", GPA: " << ptr->gpa << endl;

        ptr = ptr->prev;
    }
}

/*
   Main Menu
*/
int main()
{
    int choice;

    do
    {
        cout << "\n===== Student Enrollment System =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Display Start to End\n";
        cout << "8. Display End to Start\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1: insertAtBeginning(); break;
            case 2: insertAtEnd(); break;
            case 3: insertAtPosition(); break;
            case 4: deleteFromBeginning(); break;
            case 5: deleteFromEnd(); break;
            case 6: deleteFromPosition(); break;
            case 7: displayForward(); break;
            case 8: displayBackward(); break;
            case 0: cout << "Program exited.\n"; break;
            default: cout << "Invalid choice.\n";
        }
    }
    while (choice != 0);

    return 0;
}

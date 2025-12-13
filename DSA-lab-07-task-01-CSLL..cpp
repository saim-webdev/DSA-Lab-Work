#include <iostream>
using namespace std;

// Structure for a track (node)
struct Track
{
    int id;
    string name;
    string artist;
    float duration;
    Track* next;
};

Track* head = NULL;

// Insert at beginning
void insertAtBeginning(int id, string name, string artist, float duration)
{
    Track* temp = new Track();
    temp->id = id;
    temp->name = name;
    temp->artist = artist;
    temp->duration = duration;

    if (head == NULL)
    {
        head = temp;
        temp->next = head;
    }
    else
    {
        Track* ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;

        temp->next = head;
        ptr->next = temp;
        head = temp;
    }
}

// Insert at end
void insertAtEnd(int id, string name, string artist, float duration)
{
    Track* temp = new Track();
    temp->id = id;
    temp->name = name;
    temp->artist = artist;
    temp->duration = duration;

    if (head == NULL)
    {
        head = temp;
        temp->next = head;
    }
    else
    {
        Track* ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;

        ptr->next = temp;
        temp->next = head;
    }
}

// Delete first track
void deleteFirst()
{
    if (head == NULL)
        return;

    if (head->next == head)
    {
        delete head;
        head = NULL;
    }
    else
    {
        Track* ptr = head;
        while (ptr->next != head)
            ptr = ptr->next;

        Track* temp = head;
        head = head->next;
        ptr->next = head;
        delete temp;
    }
}

// Delete track by ID
void deleteByID(int id)
{
    if (head == NULL)
        return;

    Track* curr = head;
    Track* prev = NULL;

    do
    {
        if (curr->id == id)
        {
            if (prev != NULL)
                prev->next = curr->next;
            else
                deleteFirst();

            delete curr;
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != head);
}

// Display playlist
void display()
{
    if (head == NULL)
    {
        cout << "Playlist is empty\n";
        return;
    }

    Track* temp = head;
    cout << "\n--- Playlist ---\n";
    do
    {
        cout << "ID: " << temp->id
             << " | Song: " << temp->name
             << " | Artist: " << temp->artist
             << " | Duration: " << temp->duration << " mins\n";
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    insertAtEnd(1, "Believer", "Imagine Dragons", 3.2);
    insertAtEnd(2, "Shape of You", "Ed Sheeran", 4.1);
    insertAtBeginning(3, "Faded", "Alan Walker", 3.5);

    display();

    deleteFirst();
    cout << "\nAfter deleting first track:";
    display();

    deleteByID(2);
    cout << "\nAfter deleting track with ID 2:";
    display();

    return 0;
}

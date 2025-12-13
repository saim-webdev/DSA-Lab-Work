#include <iostream>
using namespace std;

// Structure of a Track (Node)
struct Track
{
    int id;
    string title;
    string artist;
    string album;
    float duration;
    Track* next;
    Track* prev;
};

Track* head = NULL;

// Insert at beginning
void insertAtBeginning(int id, string title, string artist, string album, float duration)
{
    Track* temp = new Track();
    temp->id = id;
    temp->title = title;
    temp->artist = artist;
    temp->album = album;
    temp->duration = duration;

    if (head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        head = temp;
    }
    else
    {
        Track* ptr = head->prev;

        temp->next = head;
        temp->prev = ptr;
        ptr->next = temp;
        head->prev = temp;
        head = temp;
    }
}

// Insert at end
void insertAtEnd(int id, string title, string artist, string album, float duration)
{
    if (head == NULL)
    {
        insertAtBeginning(id, title, artist, album, duration);
        return;
    }

    Track* temp = new Track();
    temp->id = id;
    temp->title = title;
    temp->artist = artist;
    temp->album = album;
    temp->duration = duration;

    Track* ptr = head->prev;

    ptr->next = temp;
    temp->prev = ptr;
    temp->next = head;
    head->prev = temp;
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
        Track* ptr = head->prev;
        Track* temp = head;

        head = head->next;
        head->prev = ptr;
        ptr->next = head;

        delete temp;
    }
}

// Delete last track
void deleteLast()
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
        Track* temp = head->prev;
        Track* ptr = temp->prev;

        ptr->next = head;
        head->prev = ptr;

        delete temp;
    }
}

// Display forward
void displayForward()
{
    if (head == NULL)
    {
        cout << "Playlist is empty\n";
        return;
    }

    Track* temp = head;
    cout << "\n--- Playlist (Forward) ---\n";
    do
    {
        cout << "ID: " << temp->id
             << " | Title: " << temp->title
             << " | Artist: " << temp->artist
             << " | Album: " << temp->album
             << " | Duration: " << temp->duration << " mins\n";
        temp = temp->next;
    } while (temp != head);
}

// Display backward
void displayBackward()
{
    if (head == NULL)
        return;

    Track* temp = head->prev;
    cout << "\n--- Playlist (Backward) ---\n";
    do
    {
        cout << "ID: " << temp->id
             << " | Title: " << temp->title
             << " | Artist: " << temp->artist
             << " | Album: " << temp->album
             << " | Duration: " << temp->duration << " mins\n";
        temp = temp->prev;
    } while (temp != head->prev);
}

int main()
{
    insertAtEnd(1, "Believer", "Imagine Dragons", "Evolve", 3.2);
    insertAtEnd(2, "Shape of You", "Ed Sheeran", "Divide", 4.1);
    insertAtBeginning(3, "Faded", "Alan Walker", "Different World", 3.5);

    displayForward();
    displayBackward();

    deleteFirst();
    cout << "\nAfter deleting first track:";
    displayForward();

    deleteLast();
    cout << "\nAfter deleting last track:";
    displayForward();

    return 0;
}

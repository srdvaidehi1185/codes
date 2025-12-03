#include <iostream>
using namespace std;

struct Song {
    string name;
    Song* next;
    Song* prev;
};

Song* head = NULL;
Song* current = NULL;

// Add song at end
void addSong(string s) {
    Song* n = new Song;
    n->name = s;
    n->next = NULL;
    n->prev = NULL;

    if (head == NULL) {
        head = current = n;
    }
    else {
        Song* temp = head;
        while (temp->next != NULL)
            temp = temp->next;

        temp->next = n;
        n->prev = temp;
    }
    cout << "Song added.\n";
}

// Delete current song
void deleteSong() {
    if (current == NULL) {
        cout << "No song to delete.\n";
        return;
    }

    Song* temp = current;

    if (current->prev) current->prev->next = current->next;
    if (current->next) current->next->prev = current->prev;

    if (current == head) head = current->next;
    current = current->next;

    delete temp;
    cout << "Song deleted.\n";
}

// Next song
void nextSong() {
    if (current && current->next) current = current->next;
    else cout << "No next song.\n";
}

// Previous song
void prevSong() {
    if (current && current->prev) current = current->prev;
    else cout << "No previous song.\n";
}

// Display playlist
void showPlaylist() {
    if (head == NULL) {
        cout << "Playlist empty.\n";
        return;
    }
    Song* temp = head;
    cout << "Playlist:\n";
    while (temp != NULL) {
        cout << temp->name;
        if (temp == current) cout << "  <-- current";
        cout << "\n";
        temp = temp->next;
    }
}

int main() {
    int choice;
    string song;

    while (true) {
        cout << "\n1 Add\n2 Delete\n3 Next\n4 Prev\n5 Display\n6 Exit\n";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter song: ";
            cin >> song;
            addSong(song);
        }
        else if (choice == 2) deleteSong();
        else if (choice == 3) nextSong();
        else if (choice == 4) prevSong();
        else if (choice == 5) showPlaylist();
        else break;
    }
}

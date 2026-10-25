#include <iostream>
#include <string>
using namespace std;

// Node class
class Node
{
public:
    string title;
    string artist;
    Node* prev;
    Node* next;

    Node(string t, string a)
    {
        title = t;
        artist = a;
        prev = nullptr;
        next = nullptr;
    }
};

// Music Playlist Manager class
class MusicPlaylist
{
private:
    Node* head;
    Node* current;

public:
    // Constructor
    MusicPlaylist()
    {
        head = nullptr;
        current = nullptr;
    }

    // Add a song at the end
    void addSong(string title, string artist)
    {
        Node* p = new Node(title, artist);

        if (head == nullptr)
        {
            head = p;
            current = p;
        }
        else
        {
            Node* q = head;

            while (q->next != nullptr)
            {
                q = q->next;
            }

            q->next = p;
            p->prev = q;
        }

        cout << "Song added successfully!\n";
    }

    // Display playlist in forward direction
    void displayPlaylist()
    {
        Node* q = head;

        if (q == nullptr)
        {
            cout << "Playlist is empty!\n";
            return;
        }

        cout << "\nMusic Playlist:\n";

        while (q != nullptr)
        {
            cout << q->title << " - " << q->artist << endl;
            q = q->next;
        }
    }

    // Display playlist in reverse direction
    void displayReverse()
    {
        Node* q = head;

        if (q == nullptr)
        {
            cout << "Playlist is empty!\n";
            return;
        }

        while (q->next != nullptr)
        {
            q = q->next;
        }

        cout << "\nReverse Playlist:\n";

        while (q != nullptr)
        {
            cout << q->title << " - " << q->artist << endl;
            q = q->prev;
        }
    }

    // Delete a song by title
    void deleteSong(string title)
    {
        Node* q = head;

        while (q != nullptr && q->title != title)
        {
            q = q->next;
        }

        if (q == nullptr)
        {
            cout << "Song not found!\n";
            return;
        }

        if (q->prev != nullptr)
        {
            q->prev->next = q->next;
        }
        else
        {
            head = q->next;
        }

        if (q->next != nullptr)
        {
            q->next->prev = q->prev;
        }

        if (current == q)
        {
            current = q->next;

            if (current == nullptr)
            {
                current = head;
            }
        }

        delete q;

        cout << "Song deleted successfully!\n";
    }

    // Play the current song
    void playCurrent()
    {
        if (current == nullptr)
        {
            cout << "Playlist is empty!\n";
            return;
        }

        cout << "Now Playing: " << current->title
             << " - " << current->artist << endl;
    }

    // Play the next song
    void playNext()
    {
        if (current == nullptr)
        {
            cout << "Playlist is empty!\n";
            return;
        }

        if (current->next == nullptr)
        {
            cout << "Already at the last song!\n";
            return;
        }

        current = current->next;
        playCurrent();
    }

    // Play the previous song
    void playPrevious()
    {
        if (current == nullptr)
        {
            cout << "Playlist is empty!\n";
            return;
        }

        if (current->prev == nullptr)
        {
            cout << "Already at the first song!\n";
            return;
        }

        current = current->prev;
        playCurrent();
    }

    // Display the current song
    void showCurrent()
    {
        playCurrent();
    }

    // Play the complete playlist
    void playComplete()
    {
        Node* q = head;

        if (q == nullptr)
        {
            cout << "Playlist is empty!\n";
            return;
        }

        cout << "\nPlaying Complete Playlist:\n";

        while (q != nullptr)
        {
            cout << "Playing: " << q->title
                 << " - " << q->artist << endl;
            q = q->next;
        }
    }

    // Repeat the complete playlist
    void repeatAll(int repetitions)
    {
        if (head == nullptr)
        {
            cout << "Playlist is empty!\n";
            return;
        }

        if (repetitions <= 0)
        {
            cout << "Enter a positive number of repetitions.\n";
            return;
        }

        for (int i = 1; i <= repetitions; i++)
        {
            cout << "\nRepetition " << i << ":\n";
            playComplete();
        }
    }

    // Select a song by title
    void selectSong(string title)
    {
        Node* q = head;

        while (q != nullptr)
        {
            if (q->title == title)
            {
                current = q;

                cout << "Current song selected: "
                     << current->title << endl;
                return;
            }

            q = q->next;
        }

        cout << "Song not found!\n";
    }

    // Destructor: free allocated memory
    ~MusicPlaylist()
    {
        Node* q = head;

        while (q != nullptr)
        {
            Node* p = q;
            q = q->next;
            delete p;
        }

        head = nullptr;
        current = nullptr;
    }
};

// Main function
int main()
{
    MusicPlaylist playlist;

    int choice, repetitions;
    string title, artist;

    do
    {
        cout << "\n===== MUSIC PLAYLIST MANAGER =====\n";
        cout << "1. Add Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Playlist\n";
        cout << "4. Display Playlist in Reverse\n";
        cout << "5. Play Current Song\n";
        cout << "6. Play Next Song\n";
        cout << "7. Play Previous Song\n";
        cout << "8. Play Complete Playlist\n";
        cout << "9. Repeat All\n";
        cout << "10. Show Current Song\n";
        cout << "11. Select Current Song\n";
        cout << "12. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter song title: ";
            getline(cin >> ws, title);

            cout << "Enter artist name: ";
            getline(cin, artist);

            playlist.addSong(title, artist);
            break;

        case 2:
            cout << "Enter song title to delete: ";
            getline(cin >> ws, title);

            playlist.deleteSong(title);
            break;

        case 3:
            playlist.displayPlaylist();
            break;

        case 4:
            playlist.displayReverse();
            break;

        case 5:
            playlist.playCurrent();
            break;

        case 6:
            playlist.playNext();
            break;

        case 7:
            playlist.playPrevious();
            break;

        case 8:
            playlist.playComplete();
            break;

        case 9:
            cout << "Enter number of repetitions: ";
            cin >> repetitions;

            playlist.repeatAll(repetitions);
            break;

        case 10:
            playlist.showCurrent();
            break;

        case 11:
            cout << "Enter song title to select: ";
            getline(cin >> ws, title);

            playlist.selectSong(title);
            break;

        case 12:
            cout << "Exiting Music Playlist Manager.\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 12);

    return 0;
}
//output
//PS C:\Users\poona\OneDrive\Desktop\pt123> g++ musicplayer.cpp -o musicplayer.exe
//PS C:\Users\poona\OneDrive\Desktop\pt123> ./musicplayer

//===== MUSIC PLAYLIST MANAGER =====
//1. Add Song
//2. Delete Song
//3. Display Playlist
//4. Display Playlist in Reverse
//5. Play Current Song
//6. Play Next Song
//7. Play Previous Song
//8. Play Complete Playlist
//9. Repeat All
//10. Show Current Song
//11. Select Current Song
//12. Exit
//Enter your choice: 1
//Enter song title: naina
//Enter artist name: Arijit Singh
//Song added successfully!

//===== MUSIC PLAYLIST MANAGER =====
//1. Add Song
//2. Delete Song
//3. Display Playlist
//4. Display Playlist in Reverse
//5. Play Current Song
//6. Play Next Song
//7. Play Previous Song
//8. Play Complete Playlist
//9. Repeat All
//10. Show Current Song
//11. Select Current Song
//12. Exit
//Enter your choice: 2
//Enter song title to delete: naina
//Song deleted successfully!

//===== MUSIC PLAYLIST MANAGER =====
//1. Add Song
//2. Delete Song
//3. Display Playlist
//4. Display Playlist in Reverse
//5. Play Current Song
//6. Play Next Song
//7. Play Previous Song
//8. Play Complete Playlist
//9. Repeat All
//10. Show Current Song
//11. Select Current Song
//12. Exit
//Enter your choice: 3
//Playlist is empty!

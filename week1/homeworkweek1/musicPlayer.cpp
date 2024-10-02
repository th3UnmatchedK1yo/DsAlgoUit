#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

struct SongNode
{
    string name;
    SongNode *prev;
    SongNode *next;

    SongNode(string songName) : name(songName), prev(nullptr), next(nullptr) {}
};

class MusicPlayer
{
private:
    SongNode *head;
    SongNode *tail;
    SongNode *current;
    unordered_map<string, SongNode *> songMap;

public:
    MusicPlayer() : head(nullptr), tail(nullptr), current(nullptr) {}

    // Add a song to the playlist
    void addSong(const string &name)
    {
        SongNode *newSong = new SongNode(name);
        songMap[name] = newSong;

        if (!head)
        { // First song added
            head = tail = current = newSong;
            head->next = head;
            head->prev = head;
        }
        else
        { // Add to the end of the playlist
            newSong->prev = tail;
            newSong->next = head;
            tail->next = newSong;
            head->prev = newSong;
            tail = newSong;
        }
    }

    // Play the next song
    void playNext()
    {
        if (current)
        {
            current = current->next;
        }
    }

    // Play the previous song
    void playPrev()
    {
        if (current)
        {
            current = current->prev;
        }
    }

    // Remove a song from the playlist
    void removeSong(const string &name)
    {
        if (songMap.find(name) == songMap.end())
            return; // Song doesn't exist

        SongNode *songToRemove = songMap[name];

        if (songToRemove == head && songToRemove == tail)
        {
            // If there's only one song in the playlist
            head = tail = current = nullptr;
        }
        else
        {
            if (songToRemove == current)
            {
                playNext(); // Move to next song before removing the current song
            }
            // Remove the song from the linked list
            songToRemove->prev->next = songToRemove->next;
            songToRemove->next->prev = songToRemove->prev;

            if (songToRemove == head)
            {
                head = songToRemove->next;
            }
            if (songToRemove == tail)
            {
                tail = songToRemove->prev;
            }
        }

        // Delete the node and remove it from the map
        songMap.erase(name);
        delete songToRemove;
    }

    // Display the current playlist starting from the current song
    void displayPlaylist()
    {
        if (!current)
        {
            cout << endl;
            return;
        }

        SongNode *temp = current;
        do
        {
            cout << temp->name << " ";
            temp = temp->next;
        } while (temp != current);
        cout << endl;
    }
};

int main()
{
    MusicPlayer player;
    int n;
    cin >> n;
    string command, songName;

    for (int i = 0; i < n; ++i)
    {
        cin >> command;
        if (command == "ADD")
        {
            cin >> songName;
            player.addSong(songName);
        }
        else if (command == "NEXT")
        {
            player.playNext();
        }
        else if (command == "PREV")
        {
            player.playPrev();
        }
        else if (command == "REMOVE")
        {
            cin >> songName;
            player.removeSong(songName);
        }
        else if (command == "DISPLAY")
        {
            player.displayPlaylist();
        }
    }

    return 0;
}

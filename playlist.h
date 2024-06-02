#ifndef PLAYLIST_H
#define PLAYLIST_H

#define MAX_NAME_LENGTH 100

typedef struct Node {
    char artist[MAX_NAME_LENGTH];
    char song[MAX_NAME_LENGTH];
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct {
    Node* head;
    Node* current;
} CircularDoublyLinkedList;

Node* createNode(char* artist, char* song);
void initList(CircularDoublyLinkedList* list);
void append(CircularDoublyLinkedList* list, char* artist, char* song);
void displayPlaylist(CircularDoublyLinkedList* list);
void nextSong(CircularDoublyLinkedList* list);
void previousSong(CircularDoublyLinkedList* list);
void simulatePlaying();
void displayCurrentSong(CircularDoublyLinkedList* list);
void loadPlaylist(CircularDoublyLinkedList* list, const char* filename);
void insertSong(CircularDoublyLinkedList* list, const char* filename, char* artist, char* song);
void showMenu();

#endif // PLAYLIST_H

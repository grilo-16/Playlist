#include "playlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

Node* createNode(char* artist, char* song) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->artist, artist);
    strcpy(newNode->song, song);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void initList(CircularDoublyLinkedList* list) {
    list->head = NULL;
    list->current = NULL;
}

void append(CircularDoublyLinkedList* list, char* artist, char* song) {
    Node* newNode = createNode(artist, song);
    if (list->head == NULL) {
        list->head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        list->current = newNode;
    } else {
        Node* tail = list->head->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = list->head;
        list->head->prev = newNode;
    }
}

void displayPlaylist(CircularDoublyLinkedList* list) {
    if (list->head == NULL) {
        printf("🎵 A playlist está vazia. 🎵\n");
        return;
    }
    printf("\n🎵 Playlist 🎵\n");
    printf("-------------------------------\n");
    Node* temp = list->head;
    do {
        printf("🎤 Artista: %s\n", temp->artist);
        printf("🎶 Música: %s\n", temp->song);
        printf("-------------------------------\n");
        temp = temp->next;
    } while (temp != list->head);
}

void nextSong(CircularDoublyLinkedList* list) {
    if (list->current != NULL) {
        list->current = list->current->next;
    }
}

void previousSong(CircularDoublyLinkedList* list) {
    if (list->current != NULL) {
        list->current = list->current->prev;
    }
}

void simulatePlaying() {
    printf("\nTocando: ");
    fflush(stdout);
    for (int i = 0; i < 30; ++i) {
        printf("🎵");
        fflush(stdout);
        usleep(200000);
    }
    printf("\n");
}

void displayCurrentSong(CircularDoublyLinkedList* list) {
    if (list->current != NULL) {
        printf("\n🎶 Música Atual 🎶\n");
        printf("-------------------------------\n");
        printf("🎤 Artista: %s\n", list->current->artist);
        printf("🎶 Música: %s\n", list->current->song);
        printf("-------------------------------\n");
        simulatePlaying();
    } else {
        printf("🎵 A playlist está vazia. 🎵\n");
    }
}

void loadPlaylist(CircularDoublyLinkedList* list, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("⚠️ Erro ao abrir o arquivo. ⚠️\n");
        return;
    }
    char line[200];
    while (fgets(line, sizeof(line), file)) {
        char* artist = strtok(line, ";");
        char* song = strtok(NULL, "\n");
        if (artist && song) {
            append(list, artist, song);
        }
    }
    fclose(file);
}

void insertSong(CircularDoublyLinkedList* list, const char* filename, char* artist, char* song) {
    append(list, artist, song);
    FILE* file = fopen(filename, "a");
    if (file == NULL) {
        printf("⚠️ Erro ao abrir o arquivo. ⚠️\n");
        return;
    }
    fprintf(file, "%s;%s\n", artist, song);
    fclose(file);
}

void showMenu() {
    printf("\n🎵 Menu da Playlist 🎵\n");
    printf("-------------------------------\n");
    printf("1. 📜 Exibir playlist pela ordem de cadastro\n");
    printf("2. ⏭️ Avançar para próxima música\n");
    printf("3. ⏮️ Retornar à música anterior\n");
    printf("4. 🔍 Exibir música atual\n");
    printf("5. ➕ Inserir nova música\n");
    printf("6. 🚪 Sair\n");
    printf("-------------------------------\n");
    printf("Escolha uma opção: ");
}

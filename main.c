#include "playlist.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    CircularDoublyLinkedList playlist;
    initList(&playlist);
    const char* filename = "musicas.txt";

    loadPlaylist(&playlist, filename);
    
    int choice;
    char artist[MAX_NAME_LENGTH], song[MAX_NAME_LENGTH];

    while (1) {
        showMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayPlaylist(&playlist);
                break;
            case 2:
                nextSong(&playlist);
                displayCurrentSong(&playlist);
                break;
            case 3:
                previousSong(&playlist);
                displayCurrentSong(&playlist);
                break;
            case 4:
                displayCurrentSong(&playlist);
                break;
            case 5:
                printf("Digite o nome do artista: ");
                scanf(" %[^\n]%*c", artist);
                printf("Digite o nome da música: ");
                scanf(" %[^\n]%*c", song);
                insertSong(&playlist, filename, artist, song);
                break;
            case 6:
                printf("Saindo...\n");
                exit(0);
            default:
                printf("⚠️ Opção inválida. ⚠️\n");
        }
    }

    return 0;
}

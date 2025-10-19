#include <stdio.h>
#include <stdlib.h>

struct Canzone {
    char *title;
    char *author;
    int minutes;
    int seconds;
};
struct Canzone **libreria;
int n_songs = 1;
struct Canzone createSong() {
    struct Canzone canzone;
    canzone.title = "Title";
    canzone.author = "Author";
    canzone.minutes = 10;
    canzone.seconds = 20;
    return canzone;
}
int main(void) {
    libreria = (struct Canzone **) malloc(sizeof(struct Canzone)*n_songs);
    struct Canzone c = createSong();
    printf("Titolo: %s, Autore: %s, Durata: %d:%02d\n", c.title, c.author, c.minutes, c.seconds);
    libreria = realloc(libreria, sizeof(struct Canzone)*n_songs*2);

    while (1) {
        printf("Seleziona cosa fare : \n1) Aggiungi Canzone \n2)Visualizza tutte le canzoni \n3)Chiudi programma\n");
        int option = 0;
        scanf("%d", &option);
        printf("%d\n", option);
        switch (option) {
            case 1:
                createSong();
                break;
            case 2:
                printf("%d\n", option);
                break;
            case 3:
                return 0;
            default:
                printf("Valore invalido\n");
        }
    }
    return 0;
}
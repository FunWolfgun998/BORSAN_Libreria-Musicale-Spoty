#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Canzone {
    char *title;
    char *author;
    int minutes;
    int seconds;
};

void printAllSongs();
struct Canzone* createSong();

struct Canzone **libreria;
int n_songs = 1;
int song_now = 0;

int main(void) {
    libreria = malloc(sizeof(struct Canzone*) * n_songs);

    while (1) {
        printf("Seleziona cosa fare: \n1) Aggiungere Canzone \n2) Visualizzare tutte le canzoni \n3) Chiudi programma\n");
        int option = 0;
        scanf("%d", &option);
        getchar();

        switch (option) {
            case 1:
                if (song_now >= n_songs) {
                    n_songs *= 2;
                    libreria = realloc(libreria, sizeof(struct Canzone*) * n_songs);
                    printf("Realloc\n");
                }
                libreria[song_now] = createSong();
                song_now++;
                break;
            case 2:
                printAllSongs();
                break;
            case 3:
                // Free allocated memory before exiting
                for (int i = 0; i < song_now; i++) {
                    free(libreria[i]->title);
                    free(libreria[i]->author);
                    free(libreria[i]);
                }
                free(libreria);
                return 0;
            default:
                printf("Valore invalido\n");
        }
    }
}

void printAllSongs() {
    printf("\n--- LIBRERIA CANZONI (%d canzoni) ---\n", song_now);
    for (int i = 0; i < song_now; i++) {
        struct Canzone *c = libreria[i];
        printf("Canzone %d: Titolo: %sAutore: %sDurata: %d:%02d\n",
               i+1, c->title, c->author, c->minutes, c->seconds);
    }
    printf("--- FINE LIBRERIA ---\n\n");
}

struct Canzone* createSong() {
    struct Canzone *canzone = malloc(sizeof(struct Canzone));
    char title[100];
    char author[100];

    printf("\nInserisci titolo canzone: ");
    fgets(title, sizeof(title), stdin);
    canzone->title = malloc(strlen(title) + 1);
    strcpy(canzone->title, title);

    printf("\nInserisci autore canzone: ");
    fgets(author, sizeof(author), stdin);
    canzone->author = malloc(strlen(author) + 1);
    strcpy(canzone->author, author);

    printf("\nInserisci minuti canzone: ");
    scanf("%d", &canzone->minutes);
    printf("\nInserisci secondi canzone: ");
    scanf("%d", &canzone->seconds);
    getchar(); // Consume newline

    if (canzone->seconds >= 60) {
        canzone->minutes += canzone->seconds / 60;
        canzone->seconds = canzone->seconds % 60;
    }

    printf("Aggiunta canzone: Titolo: %sAutore: %sDurata: %d:%02d\n",
           canzone->title, canzone->author, canzone->minutes, canzone->seconds);
    return canzone;
}


//Capire cosa ho sbagliato
// #include <stdio.h>
// #include <stdlib.h>
//
// struct Canzone {
//     char *title;
//     char *author;
//     int minutes;
//     int seconds;
// };
//
// void printAllSongs();
// struct Canzone **libreria;
// int n_songs = 2;
// int song_now = 0;
//
// struct Canzone createSong() {
//     struct Canzone canzone;
//     char *title[100];
//     printf("\nInserisci titolo canzone: ");
//     fgets(title,sizeof(title),stdin);
//     canzone.title = title;
//     printf("\nInserisci autore canzone: ");
//     fgets(title,sizeof(title),stdin);
//     canzone.author = title;
//     printf("\nInserisci minuti canzone: ");
//     scanf("%d", &canzone.minutes);
//     printf("\nInserisci secondi canzone: ");
//     scanf("%d", &canzone.seconds);
//     if (canzone.seconds>60) {
//         canzone.minutes += canzone.seconds/60;
//         canzone.seconds = canzone.seconds%60;
//     }
//     printf("Aggiunta canzone: Titolo: %sAutore: %sDurata: %d:%02d\n", canzone.title, canzone.author, canzone.minutes, canzone.seconds);
//     return canzone;
// }
//
// int main(void) {
//     libreria = (struct Canzone **) malloc(sizeof(struct Canzone)*2);
//
//     while (1) {
//         printf("Seleziona cosa fare : \n1)Aggiungere Canzone \n2)Visualizzare tutte le canzoni \n3)Chiudi programma\n");
//         int option = 0;
//         scanf("%d", &option);
//         getchar();
//         printf("%d\n", option);
//         switch (option) {
//             case 1:
//                 struct Canzone c=createSong();
//                 *libreria[song_now++] = c;
//                 if (song_now>=n_songs) {
//                     libreria = realloc(libreria, sizeof(struct Canzone)*n_songs);
//                     n_songs *=2;
//                 }else {
//                     printf("Spazio %d\n", song_now);
//                 }
//                 break;
//             case 2:
//                 printAllSongs();
//                 break;
//             case 3:
//                 return 0;
//             default:
//                 printf("Valore invalido\n");
//         }
//     }
// }
// void printAllSongs() {
//     for (int i = 0; i < n_songs; i++) {
//         struct Canzone c = *libreria[i];
//         printf("Aggiunta canzone: Titolo: %sAutore: %sDurata: %d:%02d\n", c.title, c.author, c.minutes, c.seconds);
//     }
// }
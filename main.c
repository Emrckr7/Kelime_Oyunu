#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 20

void rastgele_kelime_sec(char *kelime, size_t uzunluk) {
    const char *kelime_listesi[] = {"elma", "muz", "portakal", "yedi", "roket", "erik", "kavun"};
    size_t kelime_sayisi = sizeof(kelime_listesi) / sizeof(kelime_listesi[0]);

    srand(time(NULL));
    const char *secili_kelime = kelime_listesi[rand() % kelime_sayisi];
    strncpy(kelime, secili_kelime, uzunluk);
}

void tahmini_degerlendir(const char *hedef_kelime, const char *tahmin, char *sonuc) {
    size_t uzunluk = strlen(hedef_kelime);
    for (size_t i = 0; i < uzunluk; ++i) {
        if (tahmin[i] == hedef_kelime[i]) {
            sonuc[i] = tahmin[i];  // Doðru harf ve doðru yerde
        } else if (strchr(hedef_kelime, tahmin[i]) != NULL) {
            sonuc[i] = '+';  // Doðru harf ama yanlýþ yerde
        } else {
            sonuc[i] = '-';  // Yanlýþ harf
        }
    }
    sonuc[uzunluk] = '\0';
}

int main() {
    char hedef_kelime[MAX_WORD_LENGTH];
    rastgele_kelime_sec(hedef_kelime, MAX_WORD_LENGTH);

    size_t uzunluk = strlen(hedef_kelime);
    char tahmin[MAX_WORD_LENGTH];
    char sonuc[MAX_WORD_LENGTH];

    printf("Wordle oyununa hosgeldiniz!\n");
    printf("%zu harfli kelimeyi tahmin etmeye calisiniz.\n", uzunluk);

    int deneme_sayisi = 0;
    const int max_deneme = 6;
    while (deneme_sayisi < max_deneme) {
        printf("Tahmininizi girin: ");
        scanf("%s", tahmin);

        if (strlen(tahmin) != uzunluk) {
            printf("Lütfen %zu harfli bir kelime giriniz.\n", uzunluk);
            continue;
        }

        tahmini_degerlendir(hedef_kelime, tahmin, sonuc);
        printf("Sonuc: %s\n", sonuc);

        if (strcmp(hedef_kelime, tahmin) == 0) {
            printf("Tebrikler! Kelimeyi dogru tahmin ettiniz!\n");
            break;
        }

        deneme_sayisi++;
        printf("Kalan deneme: %d\n", max_deneme - deneme_sayisi);
    }

    if (deneme_sayisi == max_deneme) {
        printf("Maalesef, deneme hakkinizz bitti. Kelime: %s\n", hedef_kelime);
    }

    return 0;
}


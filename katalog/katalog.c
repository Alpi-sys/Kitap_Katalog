#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>

#define MAX_KİTAP 100
#define UZUNLUK 100

char catalog[MAX_KİTAP][UZUNLUK];
int kitap_sayisi = 0;

void addBook() {
    if (kitap_sayisi>= MAX_KİTAP) {
        printf("\nKatalog dolu.\n");
        return;
    }

    printf("\nKitap basligi girin: ");
    getchar(); 
    fgets(catalog[kitap_sayisi], UZUNLUK, stdin);
    catalog[kitap_sayisi][strcspn(catalog[kitap_sayisi], "\n")] = 0; 

    kitap_sayisi++;
    printf("\nKitap eklendi\n");
}

void removeBook() {
    if (kitap_sayisi == 0) {
        printf("\nKitap yok\n");
        return;
    }

    printf("\nSilmek istediginiz kitabin numarasini girin (1-%d): ", kitap_sayisi);
    int numara;
    scanf_s("%d", &numara);

    if (numara < 1 || numara > kitap_sayisi) {
        printf("\nGecersiz numara\n");
        return;
    }

    for (int i = numara - 1; i < kitap_sayisi - 1; i++) {
        strcpy(catalog[i], catalog[i + 1]);
    }

    kitap_sayisi--;
    printf("\nKitap silindi\n");
}

void listBooks() {
    if (kitap_sayisi == 0) {
        printf("\nKitap yok\n");
        return;
    }

    printf("\nKitap Katalogu:\n");
    for (int i = 0; i < kitap_sayisi; i++) {
        printf("%d. %s\n", i + 1, catalog[i]);
    }
}

void sortBooks() {
    if (kitap_sayisi == 0) {
        printf("\nKitap yok\n");
        return;
    }

    for (int i = 0; i < kitap_sayisi - 1; i++) {
        for (int j = 0; j < kitap_sayisi - i - 1; j++) {
            if (strcmp(catalog[j], catalog[j + 1]) > 0) {
                char tut[UZUNLUK];
                strcpy(tut, catalog[j]);
                strcpy(catalog[j], catalog[j + 1]);
                strcpy(catalog[j + 1], tut);
            }
        }
    }

    printf("\nKitaplar Siralandi\n");
}

int main() {
    int secim;

    do {
        printf("1. Kitap Ekle\n");
        printf("2. Kitap Sil\n");
        printf("3. Kitaplari Listele\n");
        printf("4. Kitaplari Sirala\n");
        printf("5. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf_s("%d", &secim);

        switch (secim) {
        case 1:
            addBook();
            break;
        case 2:
            removeBook();
            break;
        case 3:
            listBooks();
            break;
        case 4:
            sortBooks();
            break;
        case 5:
            printf("\nCikis yapiliyor\n");
            break;
        default:
            printf("\nGecersiz secim\n");
        }
    } while (secim!= 5);

    return 0;
}
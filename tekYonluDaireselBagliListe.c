// Tek Yönlü Dairesel Bağlı Liste

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct node{
    int data;
    struct node * next;
};

struct node * basaEkle(struct node * head, int data){
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    if(head == NULL){
        temp->data = data;
        temp->next = temp;
        head = temp;
    }
    else{
        struct node * last = head;
        while(last->next != head){
            last = last->next;
        }
        last->next = temp;
        temp->data = data;
        temp->next = head;
        head = temp;
    }
    return head;
};

void sonaEkle(struct node * head, int data){
    if(head == NULL){
        printf("Boş bir listede sona ekleyemezsin\n");
        return;
    }
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    struct node * last = head;
    while(last->next != head){
        last = last->next;
    }
    last->next = temp;
    temp->data = data;
    temp->next = head;
}

void ortayaEkle(struct node * head, int data, int index){
    if(head == NULL){
        printf("Boş bir listede ortaya ekleyemezsiniz.\n");
        return;
    }
    struct node * temp = (struct node * ) malloc(sizeof(struct node));
    struct node * temp2 = head;
    while(temp2->data != index){
        temp2 = temp2->next;
    }
    temp->next = temp2->next;
    temp2->next = temp;
    temp->data = data;
}

void listeyiYazdir(struct node * head){
    if(head == NULL){
        printf("Boş bir listeyi yazdıramazsınız.\n");
        return;
    }
    struct node * temp = head;
    printf("Listenin elemanları:\n");
    do{
        printf("%d ", temp->data);
        temp = temp->next;
    }while(temp != head);
    printf("\n");
}

void elemanDuzenle(struct node * head, int data, int index){
    if(head == NULL){
        printf("Boş bir listeyi düzenleyemezsiniz.\n");
        return;
    }
    struct node * temp = head;
    while(temp->data != index){
        temp = temp->next;
    }
    temp->data = data;
}

struct node * elemanSil(struct node * head, int data){
    if(head == NULL){
        printf("Boş bir listeden eleman silemezsiniz.\n");
        return head;
    }
    struct node * temp = head;
    if(head->data == data){
        if(head->next == head){
            printf("Listenin tüm elemanları silinmiştir.\n");
            head = NULL;
            return head;
        }
        struct node * last = head;
        while(last->next != head){
            last = last->next;
        }
        head = head->next;
        last->next = head;
        free(temp);
    }
    else{
        while(temp->next->data != data){
            if(temp->next->next == head){
                printf("Silmek istediğiniz eleman bulunamadı.\n");
                return head;
            }
            temp = temp->next;
        }
        struct node * temp2 = temp->next;
        temp->next = temp2->next;
        free(temp2);
    }
    return head;
};

struct node * listeyiBosalt(struct node * head){
    if(head == NULL){
        printf("Liste zaten boş.\n");
        return head;
    }
    struct node * temp = head;
    do{
        head = head->next;
        free(temp);
        temp = head;
    }while(temp != head);
    return head;
}

int elemanSayisi(struct node * head){
    if (head == NULL){
        return 0;
    }
    int sayi = 0;
    struct node * temp = head;
    do{
        sayi++;
        temp = temp->next;
    }while(temp != head);
    return sayi;
}

void listeBilgisiYazdir(struct node * head){
    if(head == NULL){
        printf("Liste boştur.\n");
        return;
    }
    struct node * temp = head;
    int sayi = 1;
    do{
        printf("%d. elemanın hafıza adresi = %p\n", sayi, temp);
        printf("%d. elemanın değeri = %d\n", sayi, temp->data);
        printf("%d. elemandan sonraki düğümün hafıza adresi = %p\n", sayi, temp->next);
    }while(temp != head);

}

void listeyiTerstenYazdir(struct node * head){
    if(head == NULL){
        printf("Boş bir listeyi tersten yazdıramazsınız.\n");
        return;
    }
    if(head == head->next){
        printf("%d\n", head->data);
    }
    int sayi = 0;
    struct node * temp = head;
    do{
        sayi++;
        temp = temp->next;
    }while(temp != head);
    printf("Listenin tersten elemanları:\n");
    for(int i = (sayi-1); i >= 0; i--){
        temp = head;
        for(int j = 0; j < i; j++){
            temp = temp->next;
        }
        printf("%d ", temp->data);
    }
    printf("\n");
}

void ikiListeyiBirlestir(struct node * head, struct node * head2){
    if(head == NULL || head2 == NULL){
        printf("Boş listeleri birleştiremezsiniz.\n");
        return;
    }
    struct node * last = head;
    while(last->next != head){
        last = last->next;
    }
    last->next = head2;
    struct node * last2 = head2;
    while(last2->next  != head2){
        last2 = last2->next;
    }
    last2->next = head;
}



int main() {
    setlocale(LC_ALL, "Turkish");
    int secim, data, index;
    struct node *head = NULL;
    struct node *head2 = NULL;

    while (1) {
        printf("-----Aşağıdaki işlemlerden birini seçiniz...---\n");
        printf("1-Listenin Başına Eleman Ekleme\n");
        printf("2-Listenin Sonuna Eleman Ekleme\n");
        printf("3-Listenin Ortasına Eleman Ekleme\n");
        printf("4-Elemanları Listele\n");
        printf("5-Verilen Adresteki elemanı Düzenle\n");
        printf("6-Listenden İstenilen Elemanı Sil\n");
        printf("7-Listeyi Sil\n");
        printf("8-Listenin Eleman Sayısı\n");
        printf("9-Listenin Tüm elemanlarının Bilgilerini Yazdır\n");
        printf("10-Listeyi Tersten Yazdır.\n");
        printf("11-İki Listeyi Birleştir.\n");
        printf("12-Listeyi Kopyala\n"); //HENÜZ YAZILMADI.
        //LİSTEYİ İKİYE BÖLME FONKSİYONU HENÜZ YAZILMADI.
        printf("13-Programdan Çık\n");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Lütfen Eklemek İstediğiniz Değeri Giriniz...\n");
                scanf("%d", &data);
                head = basaEkle(head, data);
                break;
            case 2:
                printf("Lütfen Eklemek İstediğiniz Değeri Giriniz...\n");
                scanf("%d", &data);
                sonaEkle(head, data);
                break;
            case 3:
                printf("Lütfen Eklemek İstediğiniz Değeri Giriniz...\n");
                scanf("%d", &data);
                printf("Lütfen Ekleme Yapılacak Pozisyon Bilgisini Giriniz.....\n");
                scanf("%d", &index);
                ortayaEkle(head, data, index);
                break;
            case 4:
                listeyiYazdir(head);
                break;
            case 5:
                printf("Lütfen Değiştirmek İstediğiniz Yeni Değeri Giriniz...\n");
                scanf("%d", &data);
                printf("Lütfen Değeri Değiştirilmek İsteyen Pozisyon Bilgisini Giriniz.....\n");
                scanf("%d", &index);
                elemanDuzenle(head, data, index);
                break;
            case 6:
                printf("Lütfen Silmek İstediğiniz Elemanın Değerini Giriniz...\n");
                scanf("%d", &data);
                head = elemanSil(head, data);
                break;
            case 7:
                head = listeyiBosalt(head);
                break;
            case 8:
                printf("Listenin Eleman Sayısı = %d\n", elemanSayisi(head));
                break;
            case 9:
                listeBilgisiYazdir(head);
                break;
            case 10:
                listeyiTerstenYazdir(head);
                break;
            case 11:
                ikiListeyiBirlestir(head,head2);
            case 13:
                exit(0);
                break;
            default:
                printf("Yanlış seçim\n");
        }
    }

    return 0;
}


#include<stdio.h>
#include<stdlib.h>
#define MAXQUEUE 4

typedef struct{
    int count;
    int front;
    int rear;
    int item[MAXQUEUE];
} QUEUE;
QUEUE antrean;

void inisialisasi(QUEUE *Q){
    Q->count=0;
    Q->front=0;
    Q->rear=0;
}

int isEmpty(QUEUE *Q){
    int hasil=0;
    if (Q->count==0){
    hasil=1;
    }
    return hasil;
}

int isFull(QUEUE *Q){
    int hasil=0;
    if (Q->count==MAXQUEUE){
    hasil=1;
    }
    return hasil;
}

void insert(QUEUE *Q, int data){
// TODO 1 //
    if (isFull(Q)) {
        printf("Antrean penuh %d\n", data);
    } else {
        Q->item[Q->rear] = data;
        Q->rear = (Q->rear + 1) % MAXQUEUE;
        Q->count++;
    }
}

void hapus(QUEUE *Q){
// TODO 2 //
    if (isEmpty(Q)) {
        printf("Antrean kosong\n");
    } else {
        Q->front = (Q->front + 1) % MAXQUEUE;
        Q->count--;
    }
}

void printQueue(QUEUE *Q){
//TODO 3 //
    printf("Isi antrean: ");
    for (int i = 0; i < Q->count; i++) {
        int index = (Q->front + i) % MAXQUEUE;
        printf("%d ", Q->item[index]);
    }
        printf("\n");
    }

int main(){
inisialisasi(&antrean);
// Insert pasien pertama //
    printf("masukkan 108\n");
    insert(&antrean, 108);
    printQueue(&antrean);

// Insert pasien kedua //
    printf("masukkan 109\n");
    insert(&antrean, 109);
    printQueue(&antrean);

// Insert pasien ketiga //
    printf("masukan 110\n");
    insert(&antrean, 110);
    printQueue(&antrean);

// Insert pasien keempat //
    printf("masukan 111\n");
    insert(&antrean, 111);
    printQueue(&antrean);

// Hapus pasien pertama //
    printf("Menghapus 108 dari antrean\n");
    hapus(&antrean);
    printQueue(&antrean);

// Insert pasien kelima //
    printf("masukkan 112\n");
    insert(&antrean, 112);
    printQueue(&antrean);

return 0;

}
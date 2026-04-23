#include "scheduler.h"

// Kuyruðu oluþtur (Bellek Yönetimi - malloc)
PriorityQueue* create_queue(int capacity) {
    PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->data = (Request*)malloc(sizeof(Request) * capacity);
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

// RFC 9213 Parser: "u=3" stringinden 3 rakamýný çeker
int parse_rfc9213(const char *header) {
    const char *ptr = strstr(header, "u=");
    if (ptr) return ptr[2] - '0';
    return 7; // Varsayýlan düþük öncelik
}

// Min-Heap Push: Yeni isteði ekle ve yukarý taþý (Heapify Up)
void push(PriorityQueue *pq, Request req) {
    pq->data[pq->size] = req;
    int i = pq->size;
    pq->size++;

    while (i > 0 && pq->data[i].priority < pq->data[(i - 1) / 2].priority) {
        Request temp = pq->data[i];
        pq->data[i] = pq->data[(i - 1) / 2];
        pq->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// Belleði boþalt (Bellek Yönetimi - free)
void free_queue(PriorityQueue *pq) {
    free(pq->data);
    free(pq);
}

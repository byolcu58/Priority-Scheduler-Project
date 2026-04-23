#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ýstek yapýsý
typedef struct {
    int priority;    // 0-7 arasý rütbe
    char path[100];  // Gidilecek adres
} Request;

// Min-Heap yapýsý
typedef struct {
    Request *data;
    int size;
    int capacity;
} PriorityQueue;

// Kullanacaðýmýz fonksiyonlarýn isimleri
PriorityQueue* create_queue(int capacity);
void push(PriorityQueue *pq, Request req);
Request pop(PriorityQueue *pq);
int parse_rfc9213(const char *header);
void free_queue(PriorityQueue *pq);

#endif

#include "scheduler.h"

int main() {
    PriorityQueue *pq = create_queue(10);

    // RFC 9213 formatýnda gelen istekleri parse edelim
    Request r1; r1.priority = parse_rfc9213("u=5"); strcpy(r1.path, "/video-izle");
    Request r2; r2.priority = parse_rfc9213("u=0"); strcpy(r2.path, "/odeme-yap");
    Request r3; r3.priority = parse_rfc9213("u=2"); strcpy(r3.path, "/profil-bak");

    push(pq, r1);
    push(pq, r2);
    push(pq, r3);

    printf("API Gateway Istekleri Oncelik Sirasina Gore Islenseydi:\n");
    // En ustteki (en oncelikli) istegi gosterir
    printf("En Oncelikli Yol: %s (Priority: %d)\n", pq->data[0].path, pq->data[0].priority);

    free_queue(pq);
    system("pause");
    return 0;
}

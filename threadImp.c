#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define BSIZE 16
#define NTHREADS 4 

typedef struct {
    unsigned char *buffer;
    int length;
} Buffer;

void *doClear(void *vargp)
{
    Buffer *piece = (Buffer *) vargp;
    printf("Working on %p\n" ,piece);
    for (int i = 0; i < piece->length; i++)
    {
        *(piece->buffer) = '*';
        piece->buffer ++;
    }
}

void clearBuffer(unsigned char *p, int length)
{
    pthread_t wt[NTHREADS];
    Buffer pieces[NTHREADS];
    for (int i = 0; i < NTHREADS; i++)
    {
        pieces[i].buffer = p + i * (length / 4);
        pieces[i].length = length / 4;
        pthread_create(&wt[i], NULL, doClear, (void *)&pieces[i]);
    }
    
    for (int i = 0; i < NTHREADS; i++)
    {
        pthread_join(wt[i], NULL);
    }
}

int main() {
    unsigned char buffer[BSIZE] = {'\0'};
    clearBuffer(buffer, BSIZE);
    for (int i = 0; i < BSIZE ; i++)
    {
        printf("%c" ,buffer[i]);
    }
    printf("\nDone!\n");
    
    
    
    return 0;
}
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <malloc/malloc.h>

void print_size(void *ptr);

void *realloc(void * ptr, size_t size)
{
    void *new;

    if (!ptr) {
        new = malloc(size);
        if (!new) {
          return NULL;
        }
    } else {
        if (malloc_size(ptr) < size) {
            new = malloc(size);
            if (!new) {
              return NULL;
            }

            memcpy(new, ptr, malloc_size(ptr));

            free(ptr);
        } else {
            new = ptr;
        }
    }

    return new;
}

int
main()
{
    char *tmp = malloc(2*sizeof(char));
    print_size(tmp);

    tmp = realloc(tmp, 18 * sizeof(char));
    print_size(tmp);

    tmp[0] = '1';
    tmp[1] = '2';
    tmp[2] = '3';
    tmp[3] = '\0';

    printf("Content: %s\n", tmp);

    tmp = realloc(tmp, 1 * sizeof(char));
    print_size(tmp);

    printf("Content: %s\n", tmp);

    tmp = realloc(tmp, 64 * sizeof(char));
    print_size(tmp);

    printf("Content: %s\n", tmp);

    free(tmp);

    return 0;
}

void
print_size(void *ptr)
{
    if (ptr) {
        printf("ptr segment size: %ld\n", malloc_size(ptr));
    } else {
        printf("ptr is NULL\n");
    }
}

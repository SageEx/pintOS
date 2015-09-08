// #include "thread.h"
// #include "thread.c"

bool priorityFunction (const struct list_elem *a,
                             const struct list_elem *b,
                             void *aux){
    struct thread * A = list_entry(a,struct thread,elem);
    struct thread * B = list_entry(b,struct thread,elem);
    return A->priority < B->priority;
}


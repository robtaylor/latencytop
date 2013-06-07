#ifndef __dlist_h__
#define __dlist_h__

#include <stdbool.h>

typedef struct dlist_s dlist_t;

struct dlist_s
{
    void    *data;
    dlist_t *prev, *next;
};

extern void dlist_free(dlist_t* list);

extern dlist_t* dlist_first(dlist_t* list);
extern dlist_t* dlist_next(dlist_t* list);

extern dlist_t* dlist_delete_link(dlist_t* list, dlist_t* link);

extern dlist_t* dlist_sort(dlist_t* list, int (*compare)(void*, void*));

extern dlist_t* dlist_append(dlist_t* list, void* data);

#endif

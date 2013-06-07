#include <stdlib.h>
#include "dlist.h"



void dlist_free(dlist_t* list)
{
    dlist_t* i = dlist_first(list);
    while (i)
    {
        dlist_t* n = i->next;
        free(i);
        i = n;
    }
}



dlist_t* dlist_first(dlist_t* list)
{
    dlist_t* i;
    for (i = list; i->prev; i = i->prev);
    return i;
}

dlist_t* dlist_next(dlist_t* list)
{
    return (list ? list->next : NULL);
}



dlist_t* dlist_delete_link(dlist_t* list, dlist_t* link)
{
    if (!link)
        return NULL;

    if (link->prev)
        link->prev->next = link->next;
    if (link->next)
        link->next->prev = link->prev;

    if (list == link)
        list = (link->prev ? link->prev : link->next);

    free(link);

    if (!list)
        return NULL;

    while (list && list->prev)
        list = list->prev;
    return list;
}



dlist_t* dlist_sort(dlist_t* list, int (*compare)(void*, void*))
{
    if (!compare)
        return list;

    bool change = true;
    do {
        change = false;
        dlist_t* i;
        for (i = dlist_first(list); i && i->next; i = dlist_next(i))
        {
            dlist_t* a = i;
            dlist_t* b = i->next;

            int c = compare(a->data, b->data);
            if (c > 0)
            {
                a->next = b->next;
                b->prev = a->prev;
                a->prev = b;
                b->next = a;
                change = true;
            }
        }
    } while (change);
    
    return dlist_first(list);
}



dlist_t* dlist_append(dlist_t* list, void* data)
{
    dlist_t* node = (dlist_t*)malloc(sizeof(dlist_t));
    if (!node) return list;

    node->data = data;
    node->next = NULL;

    dlist_t* last = list;
    while (last && last->next)
        last = last->next;

    if (list)
    {
        list->next = node;
        node->prev = list;
        
        dlist_t* first = list;
        while (first && first->prev)
            first = first->prev;
        return first;
    }

    node->prev = NULL;
    return node;
}

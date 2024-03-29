#include "libmx.h"

void mx_push_back(t_list **list, void *data) {
    t_list *node = mx_create_node(data);

    if (list == NULL
        || *list == NULL) {
        *list = node;
    }
    else {
        t_list *current = *list;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = node;
    }
}


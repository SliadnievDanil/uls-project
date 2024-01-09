#include "uls.h"

void mx_sort_by_parameters(t_list *objects_info, t_sort sort_type, bool reverse) {
    switch (sort_type) {
    case NAME:
        mx_sort_list_objects(objects_info, mx_name_cmp, reverse);
        break;

    case TIME:
        mx_sort_list_objects(objects_info, mx_time_cmp, reverse);
        break;

    case SIZE:
        mx_sort_list_objects(objects_info, mx_size_cmp, reverse);
        break;

    default:
        break;
    }
}

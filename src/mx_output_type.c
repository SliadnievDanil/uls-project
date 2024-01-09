#include "uls.h"

void mx_output_type(t_list *elements_data, t_flags *flags) {
    switch (flags->format) {
    case ONECOL_OUTPUT:
        mx_onecol_output(elements_data, flags);
        break;

    case DEFAULT_OUTPUT:
        mx_default_output(elements_data, flags);
        break;

    case ONEROW_OUTPUT:
        mx_onerow_output(elements_data, flags);
        break;

    case L_OUTPUT:
        mx_L_output(elements_data, flags);
        break;

    default:
        break;
    }
}

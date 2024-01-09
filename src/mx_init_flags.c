#include "uls.h"

t_flags *mx_init_flags(int argc, char *argv[]) {
    t_flags *flags = mx_make_flags();

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') {
            break;
        }

        for (char *str = argv[i] + 1; *str != '\0'; str++) {
            switch (*str) {
            case 'R':
                flags->is_R = true;
                break;

            case 'G':
                flags->is_G = true;
                break;

            case 'F':
                flags->is_F = true;
                flags->is_p = false;
                break;

            case 'p':
                flags->is_p = true;
                flags->is_F = false;
                break;

            case 'r':
                flags->is_rev = true;
                break;

            case 'h':
                flags->is_h = true;
                break;

            case 'e':
                flags->is_e = true;
                break;

            case 'T':
                flags->is_T = true;
                break;

            case '@':
                flags->is_at = true;
                break;

            case 'g':
                flags->is_g = true;
                break;

            case 'o':
                flags->is_o = true;
                break;

            case 'x':
                flags->is_x = true;
                break;

            case 'n':
                flags->is_n = true;
                break;

            case 'q':
                flags->is_q = true;
                break;

            case 'H':
                flags->is_H = true;
                break;

            case '1':
                flags->format = ONECOL_OUTPUT;
                break;

            case 'C':
                flags->format = DEFAULT_OUTPUT;
                break;

            case 'm':
                flags->format = ONEROW_OUTPUT;
                break;

            case 'l':
                flags->format = L_OUTPUT;
                break;

            case 'c':
                flags->time_type = STAT;
                break;

            case 'u':
                flags->time_type = ACC;
                break;

            case 'U':
                flags->time_type = CREATE;
                break;

            case 't':
                flags->sort_type = TIME;
                break;

            case 'S':
                flags->sort_type = SIZE;
                break;

            case 'f':
                flags->sort_type = NONE;
                flags->ommit = ZERO;
                break;

            case 'A':
                flags->ommit = DOTS;
                break;

            case 'a':
                flags->ommit = ZERO;
                break;

            default:
                mx_printerr("uls: illegal option -- ");
                write(2, str, 1);
                write(2, "\n", 1);
                mx_printerr("usage: uls [-@ACFGHRSTUacefghlmnopqrtux1] [file ...]\n");
                exit(1);
            }
        }
    }

    if (!isatty(1)) {
        flags->is_G = false;
    } else {
        flags->is_q = true;
    }

    if (!flags->is_H) {
        flags->is_H =
                flags->format != L_OUTPUT
                && !flags->is_G
                && !flags->is_F;
    }

    if (flags->sort_type == NONE) {
        flags->ommit = ZERO;
    }

    return flags;
}

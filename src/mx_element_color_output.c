#include "uls.h"

void mx_element_color_output(mode_t mode) {
    switch (mode & S_IFMT) {
    case S_IFBLK:
        mx_printstr("\033[34;46m");
        break;

    case S_IFCHR:
        mx_printstr("\033[34;43m");
        break;

    case S_IFDIR:
        if (mode & S_IWOTH) {
            if (mode & S_ISTXT) {
                mx_printstr("\033[30;42m");
            } else {
                mx_printstr("\033[30;43m");
            }
        } else {
            mx_printstr("\033[34m");
        }
        break;

    case S_IFIFO:
        mx_printstr("\033[33m");
        break;

    case S_IFLNK:
        mx_printstr("\033[35m");
        break;

    case S_IFSOCK:
        mx_printstr("\033[32m");
        break;

    default:
        if (mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
            if (mode & S_ISUID) {
                mx_printstr("\033[30;41m");
            } else if (mode & S_ISGID) {
                mx_printstr("\033[30;46m");
            } else {
                mx_printstr("\033[31m");
            }
        }
        break;
    }
}

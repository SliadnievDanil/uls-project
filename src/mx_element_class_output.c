#include "uls.h"

int mx_element_class_output(mode_t mode, bool is_p_only) {
    char classifier = '\0';

    switch (mode & S_IFMT) {
    case S_IFDIR:
        classifier = '/';
        break;

    case S_IFIFO:
        classifier = '|';
        break;

    case S_IFLNK:
        classifier = '@';
        break;

    case S_IFSOCK:
        classifier = '=';
        break;

    case S_IFREG:
        if (mode & (S_IXUSR | S_IXGRP | S_IXOTH)) {
            classifier = '*';
        }
        break;
    }

    if (classifier != '\0') {
        if (is_p_only
            && classifier != '/') {
            return 0;
        }

        mx_printchar(classifier);

        return 1;
    }
    return 0;
}

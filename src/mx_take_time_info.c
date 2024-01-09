#include "uls.h"

struct timespec mx_take_time_info(struct stat *stat, t_time time_type) {
    switch (time_type) {
    case MOD:
        return stat->st_mtimespec;

    case STAT:
        return stat->st_ctimespec;

    case ACC:
        return stat->st_atimespec;

    case CREATE:
        return stat->st_birthtimespec;

    default:
        break;
    }
}

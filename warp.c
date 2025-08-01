#include <stdlib.h>
#include <stdio.h>


#include "warp.h"

void perr_exit(const char *s){
    perror(s);
    exit(-1);
}

int Accept(int fd, struct socketaddr* sa, socklen_t* slenptr){
    int n;
again:
    if ((n = accept(fd, sa, slenpt)) < 0){
        if ((error == ECONNABORATED) || (errno == EINTR)){
            goto again;
        }
        else {
            perr_exit(error);
        }
    }

    return n;
}
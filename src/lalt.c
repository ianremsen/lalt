#include <stdio.h>
#include <unistd.h>
#include "mpc.h"
#include "repl.h"
#include "lval.h"

int main(int argc, char** argv) {
    if (strcmp(argv[1], "repl") == 0) {
        lalt_repl();
    } else {
        break;
    }

    return 0;
}

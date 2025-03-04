#include "cut.h"
#include "cutlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>
#include <string.h>

void usage(char *program_name);

int main(int argc, char *argv[]) {

    int rod_length;

    if (argc != 2 || !strcmp(argv[1], "-h"))
        usage(argv[0]);

    int arg_len;
    if (1 != sscanf(argv[1], "%d%n", &rod_length, &arg_len) ||
        arg_len != strlen(argv[1]) || rod_length < 1)
        usage(argv[0]);

    Cut *input_cuts         = read_cuts_into_list();
    CutList optimal_cutlist = find_optimal_cuts(input_cuts, rod_length);
    print_list(optimal_cutlist);

    free(optimal_cutlist.cuts);
    free(input_cuts);

    return 0;
}

noreturn void usage(char *program_name) {
    fprintf(stderr,
            "Usage:\n"
            "%s [-h] length\n"
            "length = integer > 0\n",
            program_name);
    exit(1);
}
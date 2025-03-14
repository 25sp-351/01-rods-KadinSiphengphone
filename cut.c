#include "cut.h"
#include <stdio.h>
#include <stdlib.h>

Cut *read_cuts_into_list() {

    Cut *cuts = malloc(sizeof(Cut) * MAX_LIST_SIZE);
    int length;
    int value;
    int xx = 0;

    while (!feof(stdin)) {
        if (fscanf(stdin, "%d, %d\n", &length, &value) != 2 || length < 1 ||
            value < 1) {
            return NULL;
        }

        cuts[xx].length         = length;
        cuts[xx].value          = value;
        cuts[xx].amount_of_cuts = 0;
        xx++;
    }

    if (xx == 0) {
        free(cuts);
        return NULL;
    }

    cuts[xx].length         = END_OF_LIST;
    cuts[xx].value          = END_OF_LIST;
    cuts[xx].amount_of_cuts = END_OF_LIST;

    return cuts;
}

int size_of_cuts(Cut *cuts) {
    int size = 0;
    while (cuts[size].length != END_OF_LIST)
        size++;
    return size;
}

Cut *create_empty_cuts(Cut *cuts) {
    Cut *empty_cuts = copy_cuts(cuts);
    if (empty_cuts)
        for (int xx = 0; xx < size_of_cuts(empty_cuts); xx++)
            empty_cuts[xx].amount_of_cuts = 0;
    return empty_cuts;
}

Cut *copy_cuts(Cut *cuts) {
    int size  = size_of_cuts(cuts);
    Cut *copy = malloc(sizeof(Cut) * (size_of_cuts(cuts) + 1));
    if (!copy)
        return NULL;
    for (int xx = 0; xx < size; xx++) {
        copy[xx].length         = cuts[xx].length;
        copy[xx].value          = cuts[xx].value;
        copy[xx].amount_of_cuts = cuts[xx].amount_of_cuts;
    }

    copy[size].length         = END_OF_LIST;
    copy[size].value          = END_OF_LIST;
    copy[size].amount_of_cuts = END_OF_LIST;
    return copy;
}

Cut *add_cut(Cut *cuts, int length) {
    int size = size_of_cuts(cuts);
    for (int xx = 0; xx < size; xx++) {
        if (cuts[xx].length == length) {
            cuts[xx].amount_of_cuts++;
            break;
        }
    }

    return cuts;
}
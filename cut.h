#ifndef CUT_H
#define CUT_H

#define MAX_LIST_SIZE 101
#define END_OF_LIST -1

typedef struct {
    int length;
    int value;
    int amount_of_cuts;
} Cut;

Cut *read_cuts_into_list();
int size_of_cuts(Cut *cuts);
Cut *copy_cuts(Cut *cuts);
Cut *create_empty_cuts(Cut *cuts);
Cut *add_cut(Cut *cuts, int length);

#endif
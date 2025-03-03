#ifndef CUTLIST_H
#define CUTLIST_H

#include "cut.h"

typedef struct
{
    Cut *cuts;
    int remainder;
    int total_value;
} CutList;

CutList new_cutlist(Cut *cuts, int rod_length, int total_value);
CutList find_optimal_cuts(Cut *cuts, int rod_length);
void print_list(CutList cutlist);

#endif
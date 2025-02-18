#ifndef CUT_LIST_H
#define CUT_LIST_H
#include "piece_values.h"
#include "vec.h"
typedef struct pg {
  PieceLengthValue pv;
  int count;
} PieceGroup;

typedef struct cl {
  Vec groups;
  PieceLength remainder;
  PieceValue total_value;
} CutList;

CutList *new_cutlist(PieceLength length);
void cutlist_print(CutList *cl);
void cutlist_free(CutList *cl);

CutList *optimal_cutlist_for(Vec value_list, PieceLength rod_length);
#endif
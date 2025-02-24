#include "cut_list.h"
#include <stdio.h>
#include <stdlib.h>

CutList *new_cutlist(PieceLength remainder) {
  CutList *cl = malloc(sizeof(CutList));
  cl->groups = new_vec(sizeof(PieceGroup));
  cl->remainder = remainder;
  cl->total_value = 0;
  return cl;
}

CutList *cutlist_copy(CutList *cl) {
  CutList *new_cl = malloc(sizeof(CutList));
  new_cl->remainder = cl->remainder;
  new_cl->total_value = cl->total_value;
  new_cl->groups = vec_copy(cl->groups);
  return new_cl;
}

void cutlist_free(CutList *cl) {

  vec_free(cl->groups);
  free(cl);
}

CutList *cutlist_add(CutList *cl, PieceLengthValue pv) {
  PieceGroup *groups = vec_items(cl->groups);

  cl->remainder -= pv.length;
  cl->total_value += pv.value;
  for (int group_ix = 0; group_ix < cl->groups->length; group_ix++) {
    if (pvs_equal(&groups[group_ix].pv, &pv)) {
      groups[group_ix].count++;
      return cl;
    }
  }
  PieceGroup g = (PieceGroup){.pv = pv, .count = 1};
  vec_add(cl->groups, &g);
  return cl;
}

CutList *choose_best_cuts(CutList *starting_cutlist, Vec pv) {
  CutList *best_option = cutlist_copy(starting_cutlist);
  PieceLengthValue *lengths_to_try = vec_items(pv);

  for (int xx = 0; xx < vec_length(pv); xx++) {
    PieceLengthValue length_to_try = lengths_to_try[xx];
    if (length_to_try.length > starting_cutlist->remainder) {
      continue;
    }
    CutList *possible_option = choose_best_cuts(
        cutlist_add(cutlist_copy(starting_cutlist), length_to_try), pv);
    if (possible_option->total_value > best_option->total_value) {
      if (best_option) {
        cutlist_free(best_option);
      }
      best_option = possible_option;
    } else {
      cutlist_free(possible_option);
    }
  }
  cutlist_free(starting_cutlist);
  return best_option;
}

CutList *optimal_cutlist_for(Vec value_list, PieceLength rod_length) {
  CutList *starting_cutlist = new_cutlist(rod_length);
  return choose_best_cuts(starting_cutlist, value_list);
}

void cutlist_print(CutList *cl) {
  printf("print:\n");
  PieceGroup *groups = vec_items(cl->groups);
  for (int xx = 0; xx < vec_length(cl->groups); xx++) {
    printf("%d @ %d = %d\n", groups[xx].count, groups[xx].pv.length,
           groups[xx].count * groups[xx].pv.value);
  }
  printf("remainder: %d\n", cl->remainder);
  printf("value: %d\n", cl->total_value);
}
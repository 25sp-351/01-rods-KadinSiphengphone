#include <stdio.h>
#include <stdlib.h>
// clang -o main -Wall -g main.c
/*
 */

const int cuts_array_size = 50;
const int optimal_cuts_array_size = 255;
int read_cuts(int cut_lenghts[], int cut_values[]);
void find_optimal_cuts(int rod_length, int cut_lengths[], int cut_values[],
                       int number_of_cuts);
int main(int argc, char *argv[]) {

  int rod_length = atoi(argv[1]);
  int cut_lengths[cuts_array_size];
  int cut_values[cuts_array_size];
  int number_of_cuts = 0;

  if (argc != 2) {
    return 1;
  }

  number_of_cuts = read_cuts(cut_lengths, cut_values);
  for (int i = 0; i < number_of_cuts; i++) {
    printf("cut length: %d, cut value: %d\n", cut_lengths[i], cut_values[i]);
  }
  return 0;
}

void find_optimal_cuts(int rod_length, int cut_lengths[], int cut_values[],
                       int number_of_cuts) {
  int possible_cuts[number_of_cuts * number_of_cuts];
  int max_cuts[number_of_cuts];
  int max_value = 0;
  int cut_length_sum = 0;

  for (int xx = 0; xx < number_of_cuts; xx++) {
    max_cuts[xx] = rod_length / cut_lengths[xx];

    for (int yy = 0; yy < max_cuts[xx]; yy++) {

      cut_length_sum += cut_lengths[yy];
      if (cut_length_sum <= rod_length) {
      }
    }
  }
}

int read_cuts(int cut_lengths[], int cut_values[]) {

  int ii = 0;
  int cut_length = 0;
  int cut_value = 0;

  printf("Enter cut lengths and values:\n");
  while (fscanf(stdin, "%d, %d", &cut_length, &cut_value) == 2) {
    cut_lengths[ii] = cut_length;
    cut_values[ii] = cut_value;
    ii++;
  }
  return ii;
}

/* Name: Arun Bhusri
 * ID: 5680607
 */
#include <stdio.h>
#include <stdlib.h>
#include "box.h"

/* Creates a new box with 'init_cap' capacity */
void createBox(Box **b, int init_cap) {
  *b = (Box *)malloc(sizeof(Box));
  (*b)->data = (int *)malloc(init_cap * sizeof(int));
  (*b)->size = 0;
  (*b)->cap = init_cap;
    // IMPLEMENT
}

/* Inserts an element into a box. If the box
 * is full, double the capacity of the box
 */
void insert(Box *b, int elem) {
  if(b->size < b->cap-1){
    b->data[b->size] = elem;
    b->size++;
  }else{
  	b->cap *= 2;
    b->data = (int *)realloc(b->data, b->cap * sizeof(int));
    b->data[b->size] = elem;
    b->size++;
  }
    // IMPLEMENT
}

/* Removes all occurances of an element from a box.
 * After removal, the elements in the box should be condensed i.e. no gap
 * between any two elements. The capacity of the box
 * remains unchanged after removal.
 */
void removeAll(Box *b, int elem) {
  int index;
  int size = b->size;
  for(int i = 0; i < size; i++){
    if(b->data[i] == elem){
      index=i;
      while(index < (b->size)-1){
        b->data[index] = b->data[index+1]; //replace old with new
        index++;
      }
      b->size--;
    }
  }
    // IMPLEMENT
}

/* Prints out elements in a box */
void printBox(Box *b) {
  int size = b->size;
  for(int i = 0; i < size; i++){
    printf("%d\n", b->data[i]);
  }
    // IMPLEMENT
}

/* Returns the mean of data in a box */
double getMean(Box *b) {
  int size = b->size;
  double mean = 0.0;
  for(int i = 0; i < size; i++){
    mean += (double)b->data[i];
  }
  return mean/size;
    // IMPLEMENT
}

void dealloc(Box **b) {
  free((*b)->data);
  free(*b);
    // IMPLEMENT
}

/*
TEST: ./box < test.in
OUTPUT:
AVG = 4.00
box1 size = 10
box2 size = 1
box1 cap = 1024
box2 cap = 4
-- b1
11
2
3
4
5
2
3
2
2
6
-- b2
2
--
-- b1 (after remove)
11
3
4
5
3
6
--
-- b2 (after remove)
--
*/
int main(int argc, char **argv)
{
    Box *b1 = NULL;
    Box *b2 = NULL;

    createBox(&b1, 1);
    createBox(&b2, 2);

    int n;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int tmp;
        scanf("%d",&tmp);
        insert(b1, tmp);
    }
    insert(b2, 2);

    printf("AVG = %0.2f\n",getMean(b1));
    printf("box1 size = %d\n",b1->size);
    printf("box2 size = %d\n",b2->size);
    printf("box1 cap = %d\n",b1->cap);
    printf("box2 cap = %d\n",b2->cap);

    printf("-- b1\n");
    printBox(b1);
    printf("-- b2\n");
    printBox(b2);
    printf("--\n");

    removeAll(b1, 2);
    printf("-- b1 (after remove)\n");
    printBox(b1);
    printf("--\n");
    removeAll(b2, 2);
    printf("-- b2 (after remove)\n");
    printBox(b2);
    printf("--\n");

    dealloc(&b1);
    dealloc(&b2);
}

/* Name: Arun Bhusri
 * ID: 5680607
 */
#include <stdio.h>
#include <stdlib.h>
#include "mergesort.h"

void merge(Entry *output, Entry *L, int nL, Entry *R, int nR){
  int i,j,k;
  i=0;
  j=0;
  k=0;
  while(k < nL + nR){
    if(j >= nR || (i < nL && L[i].data < R[j].data)){
      output[k] = L[i];
      i++;
    } else {
      output[k] = R[j];
      j++;
    }
    k++;
  }
  //   // IMPLEMENT
}

void merge_sort(Entry *entries, int n) {
  if(n > 1){
    Entry *L,*R,*temp;
    int mid=n/2;
    //Split the array entries into 2 arrays: L and R
    L = (Entry *)malloc(mid * sizeof(Entry));
  	R = (Entry *)malloc((n - mid) * sizeof(Entry));
    for(int i = 0;i<mid;i++) L[i] = entries[i];
  	for(int i = mid;i<n;i++) R[i-mid] = entries[i];

    temp = (Entry *)malloc(n * sizeof(Entry)); //Create a temp array that can hold n entries
    merge_sort(L,mid); //Call mergsort() on L
    merge_sort(R,n-mid); //Call mergesort() on R
    merge(temp,L,mid,R,n-mid); //Call merge() with temp, L and R along with the size of L and R
    for(int i=0;i<n;i++){
      entries[i] = temp[i];
    }

    free(L);
    free(R);
    free(temp);
  }
    // IMPLEMENT
}

/*
TEST: ./mergesort < test.in
OUTPUT:
1 lsdfjl
2 ghijk
3 ksdljf
5 abc
6 def
*/
int main(void) {
  int n;
  scanf("%d\n", &n);
  Entry *Input = (Entry *)malloc(n * sizeof(Entry));
  int j = 0;
  while(j < n){
    Input[j].name = (char *)calloc(n,MAX_NAME_LENGTH * sizeof(char));
    scanf("%d %s\n", &Input[j].data, Input[j].name);
    j++;
  }

  merge_sort(Input,n);
  for(int i = 0;i < n;i++){
    printf("%d %s\n", Input[i].data, Input[i].name);
  }
  for(int x=0;x<n;x++){
    free(Input[x].name);
  }
  free(Input);
  return 0;
    // IMPLEMENT
}

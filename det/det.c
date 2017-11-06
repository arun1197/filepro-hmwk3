/* Name: Arun Bhusri
 * ID: 5680607
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void detHelper(int **a, int **copy, int x, int y, int n){
	int ii = 0;
  int jj = 0;
	for(int i = 0; i < n; i++){
    // copy[i] = (int *)malloc(sizeof(int) * n);
		for(int j = 0; j < n; j++){
			if(i != x && j != y){
				copy[ii][jj] = a[i][j];
        jj++;
				if(jj == n - 1){
					jj = 0;
				  ii++;
				}
			}
		}
	}
  // for (int i = 0; i < n; i++) {
  //   free(copy[i]);
  // }
}
double compute_det(int **a, int n) {
  double ans = 0.0;
	if (n == 1) return *a[0];
	int **copy = (int **)malloc(sizeof(int *) * n);
  for (int i = 0; i < n; i++) {
    copy[i] = (int *)malloc(sizeof(int) * n);
  }
	int swapPlusMinus = 1;
	for(int i = 0; i < n; i++){
		detHelper(a, copy, 0, i, n);
		ans += a[0][i] * compute_det(copy, n - 1) * swapPlusMinus;
		swapPlusMinus = -swapPlusMinus;
	}
  for (int i = 0; i < n; i++) {
    free(copy[i]);
  }
  free(copy);
	return ans;
  // return 0.0;
}

/*
TEST: ./det < det.in
OUTPUT:
-105.00000
*/
int main(void) {
  // implement this
  int n;
  scanf("%d", &n);
  // printf("%d\n",n);
  int **a = (int **)malloc(sizeof(int *) * n);
  for(int i = 0; i < n; i++){
    a[i] = (int *)malloc(sizeof(int) * n);
    for(int j = 0; j < n; j++){
      scanf("%d", &a[i][j]);
    }
  }
  printf("%f\n",compute_det(a, n));
  for (int i = 0; i < n; i++) {
    free(a[i]);
  }
  free(a);
	return 0;
}

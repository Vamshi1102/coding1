// check if the grammar has left recv or not, if it does elim the left recv.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void main(){
    char prod[20][20], alpha[20][20], beta[20][20];
    int i, j, k, n;
    printf("enter the number of productions: ");
    scanf("%d", &n);
    printf("Enter %d productions: ", n);
    for (k=0; k<=n; k++){
        gets(prod[k]);
    }
    for (k=1; k<=n; k++){
        if (prod[k][0] == prod[k][3]){
            printf("\nEntered Production is an left recursion");
            i = 4; j=0;
            while (prod[k][i] != '/'){
                alpha[k][j++] = prod[k][i++];
            }
            alpha[k][j] = '\0';
            i = i + 1;
            j = 0;
            while(prod[k][i] != '\0'){
                beta[k][j++] = prod[k][i++];
            }
            beta[k][j] = '\0';
            printf("\nthe prodiction %d after removing the left productions is: \n", k);
            printf("\n%c->%s%c'", prod[k][0], beta[k], prod[k][0]);
            printf("\n%c'->%s%c'/$\n", prod[k][0], alpha[k], prod[k][0]);
        }
        else{
            printf("entered production is not left recursive");
        }
    }
}

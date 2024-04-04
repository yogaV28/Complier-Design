#include<stdio.h>
#include<string.h>
#include<ctype.h> // Include ctype.h for isupper()

void main() {
    char st[10][20], ft[20][20], fol[20][20];
    int n, i, j, k, l;

    printf("Enter the number of non-terminals: ");
    scanf("%d", &n);
    printf("Enter the productions in the grammar:\n");
    for (i = 0; i < n; i++)
        scanf("%s", st[i]);

    for (i = 0; i < n; i++)
        fol[i][0] = '\0';

    // Compute FIRST sets
    for (i = 0; i < n; i++) {
        j = 3;
        l = 0;
        while (st[i][j] != '\0') {
            if (!isupper(st[i][j])) {
                ft[i][l++] = st[i][j];
                ft[i][l] = '\0'; // Terminate the string
                break; // Break after encountering a terminal symbol
            } else {
                k = 0;
                while (st[i][j] != st[k][0])
                    k++;
                strcat(ft[i], ft[k]);
                if (strchr(ft[k], '@') == NULL) // If '@' (epsilon) is not in the FIRST set
                    break; // Break if epsilon is not in the FIRST set of current non-terminal
            }
            j++;
        }
    }

    // Compute FOLLOW sets
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            l = strlen(st[j]);
            for (k = 3; k < l; k++) {
                if (st[j][k] == st[i][0]) {
                    if (st[j][k + 1] != '\0') {
                        if (!isupper(st[j][k + 1])) {
                            fol[i][strlen(fol[i])] = st[j][k + 1];
                            fol[i][strlen(fol[i])] = '\0'; // Terminate the string
                        } else {
                            int x = 0;
                            while (st[j][k + 1] != st[x][0])
                                x++;
                            strcat(fol[i], ft[x]);
                        }
                    } else {
                        int x = 0;
                        while (st[j][0] != st[x][0])
                            x++;
                        strcat(fol[i], fol[x]);
                    }
                }
            }
        }
    }

    // Print FIRST and FOLLOW sets
    printf("\nFIRST:\n");
    for (i = 0; i < n; i++)
        printf("FIRST[%c] = %s\n", st[i][0], ft[i]);

    printf("\nFOLLOW:\n");
    for (i = 0; i < n; i++)
        printf("FOLLOW[%c] = %s\n", st[i][0], fol[i]);
}

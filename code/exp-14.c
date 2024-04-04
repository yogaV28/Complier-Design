#include <stdio.h>
#include <string.h>

struct op {
    char l[20];
    char r[20];
} op[10];

int main() {
    int i, j, n, lineno = 1;
    char *match;

    printf("Enter the number of statements: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Statement %d (left): ", i + 1);
        scanf("%s", op[i].l);
        printf("Statement %d (right): ", i + 1);
        scanf("%s", op[i].r);
    }

    printf("\nIntermediate Code:\n");
    for (i = 0; i < n; i++) {
        printf("Line No=%d\n", lineno++);
        printf("\t\t\t%s = %s\n", op[i].l, op[i].r);
    }

    printf("\n*** Data Flow Analysis for the Above Code ***\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            match = strstr(op[j].r, op[i].l);
            if (match != NULL) {
                printf("\n%s is live at %s\n", op[i].l, op[j].r);
            }
        }
    }

    return 0;
}

#include<stdio.h>
#include<stdlib.h>

typedef struct {
    float withdraw;
    float deposit;
} transac;

typedef struct {
    char name[50];
    transac tra;
} person;

int main() {
    int n, ans;
    
    printf("Enter the no. of persons you want to give: ");
    scanf("%d", &n);

    // Dynamically allocate memory for 'n' persons
    person *s = (person *)malloc(n * sizeof(person));
    if (s == NULL) {
        printf("Memory Allocation Failed\n");
        exit(1);
    }

    // Input for persons' records
    printf("Enter your records:\n");
    for (int i = 0; i < n; i++) {
        printf("Person [%d]\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", s[i].name);  // Corrected: Added space before %[^\n]

        printf("\nDo you want to withdraw or deposit money?\n");
        printf("1. For Withdraw\n2. For Deposit\n3. Exit\n");
        printf("Ans: ");
        scanf("%d", &ans);

        switch (ans) {
            case 1:
                printf("Withdraw money amount: Rs ");
                scanf("%f", &s[i].tra.withdraw);  // Modified: Handle first person (can modify for all)
                printf("Money Withdrawn Successfully\nYou have Rs. %.2f withdrawn from your bank\n", s[i].tra.withdraw);
                break;

            case 2:
                printf("Deposit money amount: Rs ");
                scanf("%f", &s[i].tra.deposit);  // Modified: Handle first person (can modify for all)
                printf("Money Deposited Successfully\nYou have Rs. %.2f deposited to your bank\n", s[i].tra.deposit);
                break;

            case 3:
                free(s);  // Free memory before exiting
                exit(0);

            default:
                printf("Choose a valid number\n");
                break;
        }
    }

    // free(s); // Redundant: already freed inside exit(0)
    return 0;
}

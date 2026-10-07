#include <stdio.h>

/**
 * purpose: mobile money transation system for an agent. It suports
 * deposit withdrawal, balance inquiry and a transaction summary, and
 * keeps running till the agent chooses Exit.
 * Return: 0 Always (Successful)
 */

 void clearBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        /*keeps reading until the end of the line*/
    }
 }

 int main() {
    double balance = 0.0;
    double amount;
    int choice;
    int deposits = 0;
    int withdrawals = 0;

    while (1) {

        printf("\n===== MOBILE MONEY TRANSACTION SYSTEM =====\n");
        printf("1: Deposit\n");
        printf("2: Withdraw\n");
        printf("3: Check Balance\n");
        printf("4: Transaction Summary\n");
        printf("5: Exit\n");
        printf("Enter Choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input: Please enter a number from 1 to 5.\n");
            clearBuffer();
            continue;
        }

        if (choice == 5) {
            printf("System terminated.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter deposit amount: ");

                if (scanf("%lf", &amount) != 1) {
                    printf("Invalid input: Amount must be a number.\n");
                    clearBuffer();
                    continue;
                }

                if (amount <= 0) {
                    printf("Transactioin rejected: Amount must be positive.\n");
                    continue;
                }

                balance += amount;
                deposits++;
                
                printf("Deposit Successful!\n");
                printf("Current Balance: %.2f RWF\n", balance);
                break;
            
            case 2:
                printf("Enter withdrawal amount: ");

                if (scanf("%lf", &amount) != 1) {
                    printf("Invalid input: Amount must be a number.\n");
                    clearBuffer();
                    continue;
                }

                if (amount <= 0) {
                    printf("Transaction rejected: Amount must be positive.\n");
                    continue;
                }

                if (amount > balance) {
                    printf("Transaction rejected: Insufficient balance.\n");
                    continue;
                }

                balance -= amount;
                withdrawals++;

                printf("Withdrawal Successful!\n");
                printf("Current balance: %.2f RWF\n", balance);
                break;
            
            case 3:
                printf("Current balance: %.2f RWF\n", balance);
                break;
            
            case 4:
                printf("Successful deposits: %d\n", deposits);
                printf("Successful withdrawals: %d\n", withdrawals);
                break;
            
            default:
                printf("Invalid choice: Please select 1 to 5.\n");
                break;
        }
    }

    return 0;
 }
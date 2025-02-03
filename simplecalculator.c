#include <stdio.h>

int main() {
    int choice;
    float num1, num2, result;

    printf("************************************\n");
    printf("*         SIMPLE CALCULATOR        *\n");
    printf("************************************\n");
    printf("  1. Addition (+)\n");
    printf("  2. Subtraction (-)\n");
    printf("  3. Multiplication (*)\n");
    printf("  4. Division (/)\n");
    printf("  5. Exit\n");
    printf("************************************\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    if (choice >= 1 && choice <= 4) {
        printf("Enter first number: ");
        scanf("%f", &num1);
        printf("Enter second number: ");
        scanf("%f", &num2);
    }

    switch (choice) {
        case 1:
            result = num1 + num2;
            printf("\nResult: %.2f + %.2f = %.2f\n", num1, num2, result);
            break;
        case 2:
            result = num1 - num2;
            printf("\nResult: %.2f - %.2f = %.2f\n", num1, num2, result);
            break;
        case 3:
            result = num1 * num2;
            printf("\nResult: %.2f * %.2f = %.2f\n", num1, num2, result);
            break;
        case 4:
            if (num2 != 0) {
                result = num1 / num2;
                printf("\nResult: %.2f / %.2f = %.2f\n", num1, num2, result);
            } else {
                printf("\nError: Division by zero is not allowed!\n");
            }
            break;
        case 5:
            printf("\nExiting... Thank you for using the calculator!\n");
            return 0;
        default:
            printf("\nInvalid choice! Please enter a number between 1 and 5.\n");
    }
    
    printf("************************************\n");
    return 0;
}

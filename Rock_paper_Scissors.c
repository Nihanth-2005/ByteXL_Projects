#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get the computer's choice
char getComputerChoice() {
    int n = rand() % 3;  // Generates a number between 0-2
    if (n == 0) return 's';  // Stone
    if (n == 1) return 'p';  // Paper
    return 'z';              // Scissor
}

// Function to determine the winner
int determineWinner(char userChoice, char computerChoice) {
    if (userChoice == computerChoice)
        return -1;  // Draw
    if ((userChoice == 's' && computerChoice == 'z') ||
        (userChoice == 'p' && computerChoice == 's') ||
        (userChoice == 'z' && computerChoice == 'p'))
        return 1;   // User wins
    return 0;       // Computer wins
}

int main() {
    char userChoice, computerChoice;
    int userScore = 0, computerScore = 0;
    
    srand(time(0));  // Seed for random function

    printf("\n===== Welcome to the Rock-Paper-Scissors Game! =====\n");
    printf("\nRules:\n");
    printf("\t-> 's' for Stone\n");
    printf("\t-> 'p' for Paper\n");
    printf("\t-> 'z' for Scissor\n");
    printf("\t-> 'q' to Quit the game\n");

    while (1) {
        printf("\nEnter your choice (s/p/z/q): ");
        scanf(" %c", &userChoice);  // Space before %c to ignore whitespace

        // Exit condition
        if (userChoice == 'q') {
            printf("\n===== Game Over! =====\n");
            break;
        }

        // Input validation
        if (userChoice != 's' && userChoice != 'p' && userChoice != 'z') {
            printf("Invalid input! Please enter 's', 'p', or 'z'.\n");
            continue;
        }

        computerChoice = getComputerChoice();

        printf("\nYou chose: %c\n", userChoice);
        printf("Computer chose: %c\n", computerChoice);

        int result = determineWinner(userChoice, computerChoice);

        if (result == -1) {
            printf("Result: It's a DRAW!\n");
        } else if (result == 1) {
            printf("Result: Congratulations! You WIN this round!\n");
            userScore++;
        } else {
            printf("Result: Oh no! Computer WINS this round!\n");
            computerScore++;
        }

        printf("\n----- Current Score -----\n");
        printf("You: %d | Computer: %d\n", userScore, computerScore);
    }

    printf("\n===== Final Score =====\n");
    printf("You: %d | Computer: %d\n", userScore, computerScore);

    if (userScore > computerScore) {
        printf("\n🎉 Congratulations! You WON the game! 🎉\n");
    } else if (userScore < computerScore) {
        printf("\n😢 Oh no! The computer won. Better luck next time! 😢\n");
    } else {
        printf("\n🤝 It's a tie! Well played! 🤝\n");
    }

    printf("\nThanks for playing! See you next time! 👋\n");

    return 0;
}

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

void menuRender(){
    printf("What level do you want to choose:\n");
    printf("1. Easy (10 guesses)\n");
    printf("2. Immediate (5 guesses)\n");
    printf("3. Hardcore (3 guesses)\n");
}

int randomize(){
    time_t t;
    srand((unsigned) time(&t));
    return rand();
}

void game() {

    menuRender();
    int menuChosen;
    scanf("%d", &menuChosen);
    int numberOfChoice;
    bool errHandle = false;
    switch (menuChosen)
    {
    case 1:
        numberOfChoice = 10;
        break;
    case 2:
        numberOfChoice = 5;
        break;
    case 3:
        numberOfChoice = 3;
        break;
    default:
        errHandle = true;
        break;
    }
    if (errHandle) {

        printf("Your choice is not available ! Please choose again ! \n");
        menuRender();
    }

    int answer = randomize();

    for (int i = 1; i<= numberOfChoice; i++) {
        int guess;
        printf("Take a guess! You have %d guess left", numberOfChoice - i);
        scanf("%d", &guess);

        if (guess == answer) {
            printf("Your guess is correct after %d guess!", i);
        } else if (i == numberOfChoice)
        {
            printf("You are out of guess! Better luck next time");
        }
        if (guess > answer)
        {
            printf("The answer is smaller than %d", guess);
        } else {printf("The answer is bigger than %d", guess);}
    }
}

int main(){
    game();
}

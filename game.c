#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<conio.h>

void menuRender(){
    printf("What level do you want to choose:\n");
    printf("1. Easy (10 guesses)\n");
    printf("2. Immediate (5 guesses)\n");
    printf("3. Hardcore (3 guesses)\n");
}

int levelChose() {
    bool errHandle = false;
    while (!errHandle)
    {
        int menuChosen;
        scanf("%d", &menuChosen);
        switch (menuChosen)
        {
            case 1:
                return 10;
                break;
            case 2:
                return 5;
                break;
            case 3:
                return 3;
                break;
            default:
                errHandle = true;
                break;
        }
        if (errHandle) {
            system("cls");
            printf("Your choice is not available ! Please choose again ! \n");
        }
    }
    
    
}

int randomize(){
    time_t t;
    srand((unsigned) time(&t));
    return rand() % 100 + 1;
}

void gameplay() {
    int answer = randomize();
    int numberOfChoice = levelChose();
    system("cls");
    for (int i = 0; i< numberOfChoice; i++) {
        int guess;
        printf("Take a guess! You have %d guess left \n", numberOfChoice - i);
        scanf("%d", &guess);
        system("cls");
        if (guess == answer) {
            printf("Your guess is correct after %d guess!\n", i);
            break;
        } else if (i == numberOfChoice)
        {
            printf("You are out of guess! Better luck next time\n");
        }
        if (guess > answer)
        {
            printf("The answer is smaller than %d\n", guess);
        } else {printf("The answer is bigger than %d\n", guess);}

        if(i + 1 == numberOfChoice) {
            printf("You lose !\n");
        }
    }
}

int tryAgain() {
    int result;
        printf("Wanna try again ???\n 1.Yes\n 2.No\n");
        scanf("%d", &result);
    if (result == 1) {
        printf("\nYou can try it again ?");
        return result;
    } else if (result != 2) {
        printf("\nYour are a little bit nervous so try it one more time");
        return 1;
    }
    return 2;
}

void game() {
    system("cls");
    menuRender();
    gameplay();
}


int main(){
    int i = 1;
    while (i == 1)
    {
        game();
        i = tryAgain();
        printf("\nPress any key to continue");
        getch();
    }
}
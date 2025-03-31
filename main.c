#include <stdio.h>

int main(void) {
    int isExit = 0;
    while (!isExit) {
        int numOfIntegers = 0;
        printf("\nNumber of integers (N): ");
        scanf("%d", &numOfIntegers);

        char *menuOptions[] = {
            "Random integers",
            "Increasing Sequence"
        };
        int menuOptionsSize = sizeof(menuOptions)/sizeof(menuOptions[0]);
        printf("Data Generation Method:");
        for(int i = 0; i < menuOptionsSize; i++) {
            printf("\n\t%d) %s", i+1, menuOptions[i]);
        }

        int selectedGenerationMethod = 0;
        printf("\nPlease choose a method: ");
        scanf("%d", &selectedGenerationMethod);

        switch (selectedGenerationMethod) {
            case 1:
            case 2:
            default:
                break;
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_INPUT_SIZE 100

const char* morseCode[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--..", 
    "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", 
};

// Map letters and numbers to Morse code
int getMorseCodeIndex(char c) {
    if (isalpha(c)) {
        return c - 'A'; 
    }
    if (isdigit(c)) {
        return c - '0' + 26; 
    }
    return -1; 
}

void encodeMessage(const char *message) {
    for (int i = 0; message[i] != '\0'; i++) {
        char ch = toupper(message[i]);
        
        if (ch == ' ') {
            printf("   "); 
            continue;
        }

        int index = getMorseCodeIndex(ch);

        if (index != -1) {
            printf("%s ", morseCode[index]); 
        } else {
            printf("?? "); 
        }
    }
    printf("\n");
}

void decodeMessage(const char *morseCodeStr) {
    char *morseCodeToken;
    char *str = strdup(morseCodeStr); 
    morseCodeToken = strtok(str, " "); 

    while (morseCodeToken != NULL) {
        int found = 0;
        for (int i = 0; i < 36; i++) {
            if (strcmp(morseCodeToken, morseCode[i]) == 0) {
                if (i < 26)
                    printf("%c", 'A' + i); 
                else
                    printf("%c", '0' + (i - 26)); 
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("?"); 
        }

        morseCodeToken = strtok(NULL, " "); 
    }
    printf("\n");

    free(str); 
}

int main() {
    int choice;
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf("\nMorse Code Converter\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) {
            case 1:
                printf("Enter the message to encode: ");
                fgets(input, MAX_INPUT_SIZE, stdin);
                input[strcspn(input, "\n")] = '\0';  
                printf("Encoded message: ");
                encodeMessage(input);
                break;
            case 2:
                printf("Enter the Morse code to decode (separate letters with spaces): ");
                fgets(input, MAX_INPUT_SIZE, stdin);
                input[strcspn(input, "\n")] = '\0';  
                printf("Decoded message: ");
                decodeMessage(input);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

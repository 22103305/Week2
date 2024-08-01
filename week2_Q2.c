#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LEN 50

int main() {
    char paragraph[10000];
    char words[MAX_WORDS][MAX_WORD_LEN];
    int count[MAX_WORDS] = {0};
    int word_count = 0;
    
    printf("Enter a paragraph: ");
    fgets(paragraph, sizeof(paragraph), stdin);
    
    char *token = strtok(paragraph, " ,.-\n");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < word_count; i++) {
            if (strcmp(words[i], token) == 0) {
                count[i]++;
                found = 1;
                break;
            }
        }
        if (!found && word_count < MAX_WORDS) {
            strcpy(words[word_count], token);
            count[word_count] = 1;
            word_count++;
        }
        token = strtok(NULL, " ,.-\n");
    }
    
    printf("Word frequencies:\n");
    for (int i = 0; i < word_count; i++) {
        printf("%s: %d\n", words[i], count[i]);
    }

    return 0;
}

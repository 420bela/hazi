#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "excelbeolvas.h"
#include "beolvas.h"

void readCSV(const char *filename, Questions **head) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Failed to open the file.\n");
        return;
    }

    char line[256];  // Assuming a maximum line length of 255 characters
    fgets(line, sizeof(line), file);  // Read the header row and discard it

    while (fgets(line, sizeof(line), file) != NULL) {
        // Using strtok to tokenize the line based on commas
        char *token = strtok(line, ",");
        if (!token) {
            printf("Error: Failed to parse the line.\n");
            break;
        }

        // Assuming the order of columns in the CSV file is: difficulty, question, optionA, optionB, optionC, optionD, answer, category
        int difficulty;
        char question[100], optionA[100], optionB[100], optionC[100], optionD[100], answer, category[10];

        // Parse each token and copy it to the corresponding variable
        if (sscanf(token, "%d", &difficulty) != 1) {
            printf("Error: Failed to parse difficulty.\n");
            continue;
        }

        token = strtok(NULL, ",");
        if (!token) {
            printf("Error: Failed to parse question.\n");
            continue;
        }
       strncpy(question, token, sizeof(question) - 1);  // Kisebb méretû másolás, hagyva helyet a nulltermináló karakternek
        question[sizeof(question) - 1] = '\0';

        // Repeat the above process for the other variables...
            token = strtok(NULL, ",");
            if (!token) {
                printf("Error: Failed to parse optionA.\n");
                continue;
            }
            strncpy(optionA, token, sizeof(optionA) - 1);
            optionA[sizeof(optionA) - 1] = '\0';

// Repeat these steps for optionB, optionC, optionD, answer, category...
            token = strtok(NULL, ",");
            if (!token) {
                printf("Error: Failed to parse optionB.\n");
                continue;
            }
            strncpy(optionB, token, sizeof(optionB) - 1);
            optionB[sizeof(optionB) - 1] = '\0';

            // Repeat for optionC...
            token = strtok(NULL, ",");
            if (!token) {
                printf("Error: Failed to parse optionC.\n");
                continue;
            }
            strncpy(optionC, token, sizeof(optionC) - 1);
            optionC[sizeof(optionC) - 1] = '\0';

            // Repeat for optionD...
            token = strtok(NULL, ",");
            if (!token) {
                printf("Error: Failed to parse optionD.\n");
                continue;
            }
            strncpy(optionD, token, sizeof(optionD) - 1);
            optionD[sizeof(optionD) - 1] = '\0';

            // Repeat for answer...
            token = strtok(NULL, ",");
            if (!token) {
                printf("Error: Failed to parse answer.\n");
                continue;
            }
            if (sscanf(token, " %c", &answer) != 1) {
                printf("Error: Failed to parse answer.\n");
                continue;
            }

            // Repeat for category...
            token = strtok(NULL, ",");
            if (!token) {
                printf("Error: Failed to parse category.\n");
                continue;
            }
            strncpy(category, token, sizeof(category) - 1);
            category[sizeof(category) - 1] = '\0';

        // Create a new question and append it to the list
        Questions *new_question = createQuestion(difficulty, question, optionA, optionB, optionC, optionD, answer, category);
        appendQuestion(*head, new_question);
    }

    fclose(file);
}

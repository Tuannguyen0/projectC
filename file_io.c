#include <stdio.h>
#include <stdlib.h>
#include "user.h"

void loadUsers() {
    FILE *file = fopen("data/users.txt", "r");
    if (file == NULL) {
        printf("Khong the mo file. Tao file moi.\n");
        return;
    }
    userCount = 0;
    while (fscanf(file, "%s %s %s %s %s %s %d", users[userCount].id, users[userCount].name, users[userCount].email, users[userCount].phone, users[userCount].username, users[userCount].password, &users[userCount].isLocked) != EOF) {
        userCount++;
    }
    fclose(file);
}

void saveUsers() {
    FILE *file = fopen("data/users.txt", "w");
    if (file == NULL) {
        printf("Khong the mo file de ghi.\n");
        return;
    }
    for (int i = 0; i < userCount; i++) {
        fprintf(file, "%s %s %s %s %s %s %d\n", users[i].id, users[i].name, users[i].email, users[i].phone, users[i].username, users[i].password, users[i].isLocked);
    }
    fclose(file);
}

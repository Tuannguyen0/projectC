#include <stdio.h>
#include <string.h>
#include "user.h"

void addUser() {
    if (userCount >= MAX_USERS) {
        printf("Danh sach nguoi dung da day.\n");
        return;
    }
    User newUser;
    printf("Nhap so can cuoc: ");
    scanf("%s", newUser.id);
    printf("Nhap ten: ");
    scanf("%s", newUser.name);
    printf("Nhap email: ");
    scanf("%s", newUser.email);
    printf("Nhap so dien thoai: ");
    scanf("%s", newUser.phone);
    printf("Nhap username: ");
    scanf("%s", newUser.username);

    // M?c ð?nh password là s? ði?n tho?i
    strcpy(newUser.password, newUser.phone);
    newUser.isLocked = 0; // M?c ð?nh tr?ng thái là "open"

    // Ki?m tra trùng l?p
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].id, newUser.id) == 0 || strcmp(users[i].username, newUser.username) == 0) {
            printf("So can cuoc hoac username da ton tai. Vui long nhap lai.\n");
            return;
        }
    }

    users[userCount++] = newUser;
    printf("Them nguoi dung thanh cong.\n");
}

void displayUsers() {
    printf("\n=== DANH SACH NGUOI DUNG ===\n");
    printf("+----+----------------------+----------------------+----------------+----------------+------------+\n");
    printf("| ID |         Ten          |        Email         | So dien thoai  |    Username    | Trang thai |\n");
    printf("+----+----------------------+----------------------+----------------+----------------+------------+\n");
    for (int i = 0; i < userCount; i++) {
        printf("| %-2d | %-20s | %-20s | %-14s | %-14s | %-10s |\n",
               i + 1, users[i].name, users[i].email, users[i].phone, users[i].username,
               users[i].isLocked ? "Khoa" : "Mo");
    }
    printf("+----+----------------------+----------------------+----------------+----------------+------------+\n");
}

void lockUnlockUser() {
    char id[MAX_ID_LENGTH];
    printf("Nhap so can cuoc cua nguoi dung: ");
    scanf("%s", id);
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].id, id) == 0) {
            if (users[i].isLocked) {
                printf("Nguoi dung dang bi khoa. Ban co muon mo khoa? (1: Co, 0: Khong): ");
            } else {
                printf("Nguoi dung dang mo. Ban co muon khoa? (1: Co, 0: Khong): ");
            }
            int confirm;
            scanf("%d", &confirm);
            if (confirm) {
                users[i].isLocked = !users[i].isLocked;
                printf("Thao tac thanh cong.\n");
            }
            return;
        }
    }
    printf("Khong tim thay nguoi dung.\n");
}

void viewUserDetails() {
    char id[MAX_ID_LENGTH];
    printf("Nhap so can cuoc cua nguoi dung: ");
    scanf("%s", id);
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].id, id) == 0) {
            printf("\n=== CHI TIET NGUOI DUNG ===\n");
            printf("So can cuoc: %s\n", users[i].id);
            printf("Ten: %s\n", users[i].name);
            printf("Email: %s\n", users[i].email);
            printf("So dien thoai: %s\n", users[i].phone);
            printf("Username: %s\n", users[i].username);
            printf("Trang thai: %s\n", users[i].isLocked ? "Khoa" : "Mo");
            return;
        }
    }
    printf("Khong tim thay nguoi dung.\n");
}

void sortUsersByName() {
    for (int i = 0; i < userCount - 1; i++) {
        for (int j = i + 1; j < userCount; j++) {
            if (strcmp(users[i].name, users[j].name) > 0) {
                User temp = users[i];
                users[i] = users[j];
                users[j] = temp;
            }
        }
    }
    printf("Sap xep danh sach theo ten thanh cong.\n");
}

void searchUserByName() {
    char name[MAX_NAME_LENGTH];
    printf("Nhap ten nguoi dung can tim: ");
    scanf("%s", name);
    int found = 0;
    for (int i = 0; i < userCount; i++) {
        if (strstr(users[i].name, name) != NULL) {
            if (!found) {
                printf("\n=== KET QUA TIM KIEM ===\n");
                printf("+----+----------------------+----------------------+----------------+----------------+------------+\n");
                printf("| ID |         Ten          |        Email         | So dien thoai  |    Username    | Trang thai |\n");
                printf("+----+----------------------+----------------------+----------------+----------------+------------+\n");
            }
            printf("| %-2d | %-20s | %-20s | %-14s | %-14s | %-10s |\n",
                   i + 1, users[i].name, users[i].email, users[i].phone, users[i].username,
                   users[i].isLocked ? "Khoa" : "Mo");
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay nguoi dung.\n");
    } else {
        printf("+----+----------------------+----------------------+----------------+----------------+------------+\n");
    }
}

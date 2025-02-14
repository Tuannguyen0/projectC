#ifndef USER_H
#define USER_H

#define MAX_USERS 100
#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_PHONE_LENGTH 15
#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 20
#define MAX_ID_LENGTH 15

typedef struct {
    char id[MAX_ID_LENGTH];
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    int isLocked;
} User;

extern User users[MAX_USERS];
extern int userCount;

void addUser();
void displayUsers();
void lockUnlockUser();
void viewUserDetails();
void loadUsers();
void saveUsers();

#endif

#include <stdio.h>
#include "user.h"
#include "menu.h"

int main() {
    loadUsers();
    while (1) {
        displayMenu();
        int choice;
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        handleMenuChoice(choice);
    }
    return 0;
}

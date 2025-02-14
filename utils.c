#include <stdio.h>
#include <string.h>
#include "user.h"

int validateEmail(const char *email) {
    // Ki?m tra ð?nh d?ng email ðõn gi?n
    if (strchr(email, '@') == NULL) {
        return 0;
    }
    return 1;
}

int validatePhone(const char *phone) {
    // Ki?m tra s? ði?n tho?i có 10 ch? s?
    if (strlen(phone) != 10) {
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        if (phone[i] < '0' || phone[i] > '9') {
            return 0;
        }
    }
    return 1;
}

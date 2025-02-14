void displayMenu() {
    printf("\n=== MENU QUAN LY NGUOI DUNG ===\n");
    printf("1. Them nguoi dung\n");
    printf("2. Hien thi danh sach nguoi dung\n");
    printf("3. Khoa/Mo khoa nguoi dung\n");
    printf("4. Xem chi tiet nguoi dung\n");
    printf("5. Sap xep danh sach theo ten\n");
    printf("6. Tim kiem nguoi dung theo ten\n");
    printf("0. Thoat\n");
}

void handleMenuChoice(int choice) {
    switch (choice) {
        case 1:
            addUser();
            break;
        case 2:
            displayUsers();
            break;
        case 3:
            lockUnlockUser();
            break;
        case 4:
            viewUserDetails();
            break;
        case 5:
            sortUsersByName();
            break;
        case 6:
            searchUserByName();
            break;
        case 0:
            printf("Thoat chuong trinh.\n");
            exit(0);
        default:
            printf("Lua chon khong hop le. Vui long thu lai.\n");
    }
}

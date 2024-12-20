#include <stdio.h>
#include <string.h>

#define MAX_MENU 100

typedef struct {
    int id;
    char name[50];
    float price;
} Dish;

Dish menu[MAX_MENU] = {
    {1, "Pho", 40000},
    {2, "Bun Cha", 45000},
    {3, "Com Tam", 50000},
    {4, "Banh Mi", 20000},
    {5, "Goi Cuon", 30000}
};
int menu_size = 5;

void printMenu() {
    for (int i = 0; i < menu_size; i++) {
        printf("%d. id: %d, name: %s, price: %.2f\n", i + 1, menu[i].id, menu[i].name, menu[i].price);
    }
}
void addDishAtPosition(int position, Dish newDish);
void updateDishAtPosition(int position, Dish updatedDish);

void deleteDishAtPosition(int position);

void sortDescending();

void sortAscending();

void searchByNameLinear(char *name);

int main() {
    int choice;
    do {
        printf("\nMENU\n");
        printf("1. In menu\n");
        printf("2. Them mon an tai vi tri chi dinh\n");
        printf("3. Cap nhat mon an tai vi tri chi dinh\n");
        printf("4. Xoa mon an tai vi tri chi dinh\n");
        printf("5. Sap xep cac mon an\n");
        printf("6. Tim kiem mon an theo ten\n");
        printf("7. Thoat\n");
        printf("Nhap lua chon cua ban: \n");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printMenu();
            break;
        case 2: {
            int pos;
            Dish newDish;
            printf("Nhap vi tri: ");
            scanf("%d", &pos);
            printf("Nhap id, ten, va gia: \n");
            scanf("%d %s %f", &newDish.id, newDish.name, &newDish.price);
            addDishAtPosition(pos - 1, newDish);
            break;
        }
        case 3: {
            int pos;
            Dish updatedDish;
            printf("Nhap vi tri:\n ");
            scanf("%d", &pos);
            printf("Nhap id, ten, va gia: ");
            scanf("%d %s %f", &updatedDish.id, updatedDish.name, &updatedDish.price);
            updateDishAtPosition(pos - 1, updatedDish);
            break;
        }
        case 4: {
            int pos;
            printf("Nhap vi tri: \n");
            scanf("%d", &pos);
            deleteDishAtPosition(pos - 1);
            break;
        }
        case 5: {
            int sortChoice;
            printf("a. Sap xep giam dan theo gia\n");
            printf("b. Sap xep tang dan theo gia\n");
            printf("Nhap lua chon cua ban (1 cho a, 2 cho b): ");
            scanf("%d", &sortChoice);
            if (sortChoice == 1) {
                sortDescending();
            } else if (sortChoice == 2) {
                sortAscending();
            } else {
                printf("Lua chon khong hop le!\n");
            }
            break;
        }
        case 6: {
            char name[50];
            printf("Nhap ten de tim kiem: \n");
            scanf("%s", name);
            searchByNameLinear(name);
            break;
        }
        case 7:
            printf("Thoat chuong trinh...\n");
            break;
        default:
            printf("Lua chon khong hop le!\n");
        }
    } while (choice != 7);

    return 0;
}
void addDishAtPosition(int position, Dish newDish) {
    if (position < 0 || position > menu_size || menu_size >= MAX_MENU) {
        printf("Vi tri khong hop le hoac menu da day!\n");
        return;
    }
    for (int i = menu_size; i > position; i--) {
        menu[i] = menu[i - 1];
    }
    menu[position] = newDish;
    menu_size++;
}
void updateDishAtPosition(int position, Dish updatedDish) {
    if (position < 0 || position >= menu_size) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    menu[position] = updatedDish;
}
void deleteDishAtPosition(int position) {
    if (position < 0 || position >= menu_size) {
        printf("Vi tri khong hop le!\n");
        return;
    }
    for (int i = position; i < menu_size - 1; i++) {
        menu[i] = menu[i + 1];
    }
    menu_size--;
}
void sortDescending() {
    for (int i = 0; i < menu_size - 1; i++) {
        for (int j = i + 1; j < menu_size; j++) {
            if (menu[i].price < menu[j].price) {
                Dish temp = menu[i];
                menu[i] = menu[j];
                menu[j] = temp;
            }
        }
    }
}
void sortAscending() {
    for (int i = 0; i < menu_size - 1; i++) {
        for (int j = i + 1; j < menu_size; j++) {
            if (menu[i].price > menu[j].price) {
                Dish temp = menu[i];
                menu[i] = menu[j];
                menu[j] = temp;
            }
        }
    }
}
void searchByNameLinear(char *name) {
    int found = 0;
    for (int i = 0; i < menu_size; i++) {
        if (strcmp(menu[i].name, name) == 0) {
            printf("Tim thay tai vi tri %d: id: %d, name: %s, price: %.2f\n", i + 1, menu[i].id, menu[i].name, menu[i].price);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay mon an!\n");
    }
}

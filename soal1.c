//** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2024/2025
// *   Modul               : 4
// *   Hari dan Tanggal    : Senin, 4 Mei 2026
// *   Nama (NIM)          : Hezkiel Tarutung Harianja (13224010)
// *   Nama File           : soal1_modul4.c
// *   Deskripsi           : Program Gerbong Kargo Campuran
// */

#include <stdio.h>
#include <stdlib.h>

typedef struct Gerbong {
    int nilai;
    struct Gerbong *next;
} Gerbong;

Gerbong *createGerbong(int nilai) {
    Gerbong *new = (Gerbong*)malloc(sizeof(Gerbong));
    new->nilai = nilai;
    new->next = NULL;
    return new;
}

void push_front(Gerbong **head, int nilai) {
    Gerbong *new = createGerbong(nilai);
    new->next = *head;
    *head = new;
}

void push_back(Gerbong **head, int nilai) {
    Gerbong *new = createGerbong(nilai);
    if (*head == NULL) {
        *head = new;
        return;
    }
    Gerbong *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;
}

void delete(Gerbong **head, int x) {
    Gerbong *temp = *head;
    Gerbong *past = NULL;
    if (temp != NULL && temp->nilai == x) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->nilai != x) {
        past = temp;
        temp = temp->next;
    }
    if (temp == NULL) return; 
    past->next = temp->next;
    free(temp);
}

void find(Gerbong *head, int x) {
    Gerbong *temp = head;
    int pos = 0;
    while (temp != NULL) {
        if (temp->nilai == x) {
            printf("FOUND %d\n", pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("NOT FOUND\n");
}

void printList(Gerbong *head) {
    if (head == NULL) {
        printf("LIST EMPTY\n");
        return;
    }
    printf("LIST");
    Gerbong *temp = head;
    while (temp != NULL) {
        printf(" %d", temp->nilai);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int a;
    int option;
    int val;
    Gerbong *head = NULL;
    if (scanf("%d", &a) != 1) return 0;
    for (int i = 0; i < a; i++) {
        scanf("%d %d", &option, &val);
        if (option == 1) {
            push_front(&head, val);
        } else if (option == 2) {
            push_back(&head, val);
        } else if (option == 3) {
            delete(&head, val);
        } else if (option == 4) {
            find(head, val);
        }
    }
    printList(head);
    Gerbong *now = head;
    while (now != NULL) {
        Gerbong *next = now->next;
        free(now);
        now = next;
    }
    return 0;
}

//Reference : 
//1. https://www.geeksforgeeks.org/c/structure-pointer-in-c/
//2. https://www.geeksforgeeks.org/c/c-functions/
//3. https://www.geeksforgeeks.org/c/c-pointer-to-pointer-double-pointer/
//4. https://www.geeksforgeeks.org/c/c-program-for-inserting-a-node-in-a-linked-list/
//5. https://www.geeksforgeeks.org/c/linked-list-in-c/
//6. https://www.geeksforgeeks.org/c/implement-stack-in-c/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct DoublyLinkedList {
    char* value;

    struct DoublyLinkedList* previous;
    struct DoublyLinkedList* next;
};

struct DoublyLinkedList* createList(char* value) {
    struct DoublyLinkedList* root = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));

    root->value = value;
    root->previous = NULL;
    root->next = NULL;

    return root;
}

struct DoublyLinkedList* insert(char* value, struct DoublyLinkedList* previous, struct DoublyLinkedList* next) {
    struct DoublyLinkedList* element = (struct DoublyLinkedList*)malloc(sizeof(struct DoublyLinkedList));

    previous->next = element;

    element->value = value;
    element->previous = previous;
    element->next = next;

    return element;
}

struct DoublyLinkedList* find(char* value, struct DoublyLinkedList* root) {
    while(1) {
        if(strcmp(root->value, value) == 0) {
            return root;
        } else {
            if(root->next == NULL) {
                return NULL;
            } else {
                root = root->next;
            }
        }
    }
}

void delete(struct DoublyLinkedList* root) {
    while(root->next != NULL) {
        free(root);
        root = root->next;
    }
}

void debugOutput(struct DoublyLinkedList* root) {
    while(1) {
        printf("%s", root->value);
        if(root->next == NULL) {
            return;
        } else {
            root = root->next;
        }
    }
}


int main() {
    char* rootValue = "root";
    struct DoublyLinkedList* root = createList(rootValue);

    struct DoublyLinkedList* element = insert("0", root, NULL);
    for(int i = 1; i < 6; ++i) {
        char* value = (char*)malloc(2);
	sprintf(value, "%c", i + '0');
        element = insert(value, element, NULL);
    }

    printf("%s", find("2", root)->next->value);
    delete(root);
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SIZE_ARRAY 20

struct Node {
	int id;
	char word[SIZE_ARRAY];
	struct Node *prev, *next;
};

void insertEnd(struct Node** head, int id)
{
	if (*head == NULL) {
		struct Node* p = (struct Node*)malloc(sizeof(struct Node));
		p->id = id;
		p->next = p->prev = p;
		*head = p;
	} else {
		struct Node *last = (*head)->prev;
		struct Node* p = (struct Node*)malloc(sizeof(struct Node));

		p->id = id;
		p->next = *head;
		(*head)->prev = p;
		p->prev = last;
		last->next = p;
	}
}

int main() {
	struct Node* list = NULL;

	insertEnd(&list, 0);
	insertEnd(&list, 1);
	insertEnd(&list, 2);

	return 0;
}
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define SIZE_ARRAY 20

struct Node {
	int id;
	char word[SIZE_ARRAY];
	struct Node *prev, *next;
};

void clearArray(struct Node *p);
void assignData(struct Node *p, int id, char word[]);
void insertEnd(struct Node **head, int id, char word[]);
void insertBegin(struct Node **head, int id, char word[]);
void insertAfter(struct Node **head, int id_inserted, int id_after, char word[]);
void printList(struct Node *head);
void printWord(struct Node *p);

int main() {
	struct Node* list = NULL;

	insertEnd(&list, 0, "aaa");
	insertEnd(&list, 1, "bbb");
	insertEnd(&list, 2, "ccc");
	insertBegin(&list, 4, "ddd");
	insertAfter(&list, 5, 2, "eeeeeeeee");

	printf("Doubly Circular Linked List:\n");
	printList(list);

	return 0;
}

void clearArray(struct Node *p) {
	for (int i = 0; i < SIZE_ARRAY; i++) p->word[i] = '\0';
}

void assignData(struct Node *p, int id, char word[]) {
	p->id = id;
	clearArray(p);

	for (int i = 0; i < SIZE_ARRAY; i++) {
		if (word[i] == '\0') break;
		p->word[i] = word[i];
	}
}

void insertEnd(struct Node **head, int id, char word[]) {
	if (*head == NULL) {
		struct Node *p = (struct Node*)malloc(sizeof(struct Node));
		
		assignData(p, id, word);
		p->next = p->prev = p;
		*head = p;
	} else {
		struct Node *last = (*head)->prev;
		struct Node *p = (struct Node*)malloc(sizeof(struct Node));

		assignData(p, id, word);
		p->next = *head;
		(*head)->prev = p;
		p->prev = last;
		last->next = p;
	}
}

void insertBegin(struct Node **head, int id, char word[]) {
	struct Node *last = (*head)->prev;
	struct Node *p = (struct Node*)malloc(sizeof(struct Node));
	
	assignData(p, id, word);
	p->next = *head;
	p->prev = last;
	last->next = (*head)->prev = p;
	*head = p;
}

void insertAfter(struct Node **head, int id_inserted, int id_after, char word[]) {
	struct Node *p = (struct Node*)malloc(sizeof(struct Node));
	assignData(p, id_inserted, word);

	struct Node *temp = *head;
	while (temp->id != id_after) temp = temp->next;
	
	struct Node *next = temp->next;
 
	temp->next = p;
	p->prev = temp;
	p->next = next;
	next->prev = p;
}

void printList(struct Node *head) {
	struct Node *temp = head;
	printf("%c> ", 218);

	while (temp->next != head) {
		printf("%d", temp->id);
		printWord(temp);
		printf(" <%c> ", 196);
		temp = temp->next;
	}

	printf("%d", temp->id);
	printWord(temp);
	printf(" <%c\n", 191);
	printf("%c%c%c%c", 192, 196, 196, 196);
	temp = temp->next;

	while (temp->next != head) {
		int number_len = 0;
		int number = temp->id;

		if (number == 0) number_len = 1;
		else {
			while (number > 0) {
				number /= 10;
				number_len++;
			}
		}

		for (int i = 0; i < number_len; i++) {
			printf("%c", 196);
		}

		for (int i = 0; i < SIZE_ARRAY; i++) {
			if (temp->word[i] == '\0') break;
			printf("%c", 196);
		}

		for (int i = 0; i < 10; i++) printf("%c", 196);

		temp = temp->next;
	}

	printf("%c%c", 196, 217);
}

void printWord(struct Node *p) {
	printf("(");

	for (int i = 0; i < sizeof(p->word); i++) {
		if (p->word[i] == '\0') break;
		printf("%c", p->word[i]);
	}

	printf(")");
}
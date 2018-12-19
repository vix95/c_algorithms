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
void searchNode(struct Node *head, int id, char word[]);
void removeNode(struct Node *head, int id);

int main() {
	struct Node* list = NULL;
	int pos = 0;

	insertEnd(&list, pos++, "aaa");
	insertEnd(&list, pos++, "bbb");
	insertEnd(&list, pos++, "ccc");
	insertBegin(&list, pos++, "ddd");
	insertAfter(&list, pos++, 2, "eeeeeeeee");
	searchNode(&list, pos++, "ccc");

	printf(" Doubly Circular Linked List:\n");
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
	}
	else {
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
	struct Node *p = head;
	printf(" %c> ", 218);

	while (p->next != head) {
		printf("%d", p->id);
		printWord(p);
		printf(" <%c> ", 196);
		p = p->next;
	}

	printf("%d", p->id);
	printWord(p);
	printf(" <%c\n", 191);
	printf(" %c%c%c%c", 192, 196, 196, 196);
	p = p->next;

	while (p->next != head) {
		int number_len = 0;
		int number = p->id;

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
			if (p->word[i] == '\0') break;
			printf("%c", 196);
		}

		for (int i = 0; i < 10; i++) printf("%c", 196);

		p = p->next;
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

void searchNode(struct Node *head, int id, char word[]) {
	insertEnd(head, id, word);
	
	struct Node *p = head;
	
	while (p->next != head) {
		if (p->word == p->word) {
			if (p->id == id) {
				return println("Not found\n");
			}
			else {
				return println("Founded at id: %d\n", p->id);
			}
		}

		p = p->next;
	}

	removeNode(head, id);
}

void removeNode(struct Node *head, int id) {
	struct Node *p = head;

	while (p->next != head) {
		if (p->id == id) {
			struct Node *temp = p;
			
		}

		p = p->next;
	}
}
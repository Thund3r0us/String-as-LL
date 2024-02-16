/*
COP3502 CS1 Spring 2024 Lab 4
Copyright Nicole Walsh
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char letter;
  struct node *next;
} node;

// Returns number of nodes in the linkedList.
int length(node *head) {
  if (head == NULL) {
    return 0;
  }
  node *current = head;
  int nodes = 1;
  while (current->next != NULL) {
    current = current->next;
    nodes++;
  }
  return nodes;
}

// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char *toCString(node *head) {
  node *current = head;
  int len = length(current);
  char *string = malloc(sizeof(char) * (len + 1));

  // reset current pointer to head
  current = head;

  for (int i = 0; i < len; i++) {
    string[i] = current->letter;
    current = current->next;
  }
  string[len] = '\0';
  return string;
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as follows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node **pHead, char c) {
  node *newNode = malloc(sizeof(node));
  newNode->letter = c;
  newNode->next = NULL;

  if (*pHead == NULL) {
    *pHead = newNode;
    return;
  }

  node* current = *pHead;
  while (current->next != NULL) {
    current = current->next;
  }
  current->next = newNode;
}

// deletes all nodes in the linkedList.
void deleteList(node **pHead) {
  node *current = *pHead;
  node *next;
  while (current != NULL) {
    next = current->next;
    free(current);
    current = next;
  }
  *pHead = NULL;
}


int main(void) {
  int i, strLen, numInputs;
  node *head = NULL;
  char *str;
  char c;
  FILE *inFile = fopen("input.txt", "r");

  fscanf(inFile, " %d\n", &numInputs);

  while (numInputs-- > 0) {
    fscanf(inFile, " %d\n", &strLen);
    for (i = 0; i < strLen; i++) {
      fscanf(inFile, " %c", &c);
      insertChar(&head, c);
    }

    str = toCString(head);
    printf("String is : %s\n", str);

    free(str);
    deleteList(&head);

    if (head != NULL) {
      printf("deleteList is not correct!");
      break;
    }
  }
  fclose(inFile);
}
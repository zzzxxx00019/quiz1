#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct __node {
    int value;
    struct __node *next;
} node_t;

void add_entry(node_t **head, int new_value)
{
    node_t **indirect = head;

    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = new_value;
    new_node->next = NULL;

    assert(new_node);
    while (*indirect)
        indirect = &(*indirect)->next;
    *indirect = new_node;
}

void shuffle(node_t **head) {
  if (!*head)
    return;

  int length = 0;
  node_t **tmp_head = head;

  for (; *tmp_head ; tmp_head = &(*tmp_head)->next, length += 1);

  srand(time(NULL));
  tmp_head = head ;

  while (length > 1) {
    int Roll = rand() % length + 1;
    node_t **indirect = tmp_head;

    for(; Roll!=1 ; Roll--, indirect=&(*indirect)->next) ;

    int tmp_value = (*tmp_head)->value;
    (*tmp_head)->value = (*indirect)->value;
    (*indirect)->value = tmp_value;

    tmp_head = &(*tmp_head)->next;

    length -= 1;
  }
}

void print_list(node_t *head)
{
  for (; head; head = head->next)
    printf("%d ", head->value);

  printf("\n");
}

int main()
{
    node_t *head = NULL;

    print_list(head);

    add_entry(&head, 72);
    add_entry(&head, 101);
    add_entry(&head, 108);
    add_entry(&head, 109);
    add_entry(&head, 110);
    add_entry(&head, 111);

    print_list(head);
    shuffle(&head);
    print_list(head);

    return 0;
}


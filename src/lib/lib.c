#include <stdio.h>
#include <stdlib.h>
struct Node {
  int value;
  struct Node *next;
  struct Node *prev;
};
typedef struct Node node;
typedef struct {
  int size;
  node *head;
} linked_list;
linked_list create_list() {
  linked_list return_list;
  return_list.size = 0;
  return_list.head = NULL;
  return return_list;
}
node *create_node(int value) {
  node *return_node = malloc(sizeof(node));
  return_node->value = value;
  return_node->next = NULL;
  return_node->prev = NULL;
  return return_node;
}
void prepend(linked_list *input_list, int value) {
  node *new_node = create_node(value);
  if (input_list->size == 0) {
    input_list->head = new_node;
    new_node->next = new_node;
    new_node->prev = new_node;
    input_list->size++;
  }
  node *current_head = input_list->head;
  input_list->head = new_node;
  new_node->prev = current_head->prev;
  new_node->next = current_head;
  current_head->prev->next = new_node;
  current_head->prev = new_node;
  input_list->size++;
}
void append(linked_list *input_list, int value) {
  node *new_node = create_node(value);
  if (input_list->size == 0) {
    input_list->head = new_node;
    new_node->next = new_node;
    new_node->prev = new_node;
    input_list->size++;
  }
  node *current_head = input_list->head;
  node *prev_node = current_head->prev;
  current_head->prev = new_node;
  new_node->prev = prev_node;
  prev_node->next = new_node;
  new_node->next = current_head;
  input_list->size++;
}
int remove_head(linked_list *input_list) {
  if (input_list->size == 0) {
    printf("The list is empty!\n");
    return 0;
  } else if (input_list->size == 1) {
    node *current_head = input_list->head;
    int return_value = current_head->value;
    free(current_head);
    input_list->head = NULL;
    input_list->size--;
    return return_value;
  }
  node *current_head = input_list->head;
  int return_value = current_head->value;
  input_list->head = current_head->next;
  current_head->prev->next = current_head->next->prev;
  free(current_head);
  input_list->size--;
  return return_value;
}
int get_value(linked_list *, int);
int get_index(linked_list *, int);
void insert_at_index(linked_list *, int, int);
int remove_at_index(linked_list *, int);
void delete_list(linked_list *input_list) {
  while (input_list->size > 0) {
    remove_head(input_list);
  }
}

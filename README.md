# Circular Linked List in C
Circular linked list is just the linked list where the next of tail is head. Thereby, the list doesn't have a tail.
- [x] Prepend
- [x] Append
- [x] Remove head
- [x] Get value
- [x] Get index
- [x] Insert at index
- [x] Remove at index
## Prepend
Prepend function will push the current head to the next position and be the next head. If there is no elements it will become the head of the list with next and prev
being the element itself.

__Psuedo Code__
```c
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
```
## Append
Append will add the element as the last element of the list. The next element of the new node is the head.

__Psuedo Code__
```c
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
```
## Remove head
Removes the current head of the list, the next element is new head. If the list is empty, it returns 0. If the removed element is the last element in the list, the head will
be NULL.

__Psuedo Code__
```c
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
```
## Get value
Get value function will get the value at a particular index, If the index is higher than the size of the list, it will wrap around the list. If the list is empty, returns 0.

__Psuedo Code__
```c
int get_value(linked_list *input_list, int index) {
  if (input_list->size == 0) {
    printf("The list is empty\n");
    return 0;
  }

  index %= input_list->size;
  int i = 0;
  node *current_node = input_list->head;

  for (; i < index; i++) {
    current_node = current_node->next;
  }

  return current_node->value;
}
```
## Get index
Get index function returns the index if the value is present. Returns -1 if value is not present.

__Psuedo Code__
```c
int get_index(linked_list *input_list, int value) {
  if (input_list->size == 0) {
    printf("List is empty\n");
    return -1;
  }

  node *current_node = input_list->head;

  for (int i = 0; i < input_list->size; i++) {
    if (current_node->value == value) {
      return i;
    }

    current_node = current_node->next;
  }

  return -1;
}
```
## Insert at index
Insert at index will insert the value at the index the current node will be pushed to the next position. If the index is greater than size, returns with out of bounds. If the index is
size appends the value. If the index is 0, prepends the value.

__Psuedo Code__
```c
void insert_at_index(linked_list *input_list, int index, int value) {
  if (index > input_list->size) {
    printf("Index out of bounds.\n");
    return;
  } else if (index == input_list->size) {
    append(input_list, value);
    return;
  } else if (index == 0) {
    prepend(input_list, value);
    return;
  }

  node *new_node = create_node(value);
  node *current_node = input_list->head;

  for (int i = 0; i < index; i++) {
    current_node = current_node->next;
  }

  new_node->prev = current_node->prev;
  current_node->prev->next = new_node;
  new_node->next = current_node;
  current_node->prev = new_node;
  input_list->size++;
}
```
## Remove at index
Removes the node at the index and returns the value of removed node. The prev node's next is next node of the removed node and next node's prev is prev node of the removed the node.
If the index is greater than size of the list, returns 0 with out of bounds error. If the index is 0, removes the head.

__Psuedo Code__
```c
int remove_at_index(linked_list *input_list, int index) {
  if (index >= input_list->size) {
    printf("Out of bounds error\n");
    return 0;
  } else if (index == 0) {
    return remove_head(input_list);
  }

  node *current_node = input_list->head;

  for (int i = 0; i < index; i++) {
    current_node = current_node->next;
  }

  node *prev_node = current_node->prev;
  node *next_node = current_node->next;
  int return_value = current_node->value;
  prev_node->next = next_node;
  next_node->prev = prev_node;
  free(current_node);
  input_list->size--;
  return return_value;
}
```
# Licence
This project is licenced under <mark>GNU GPL V3.0</mark> licence. Feel free to use this project.

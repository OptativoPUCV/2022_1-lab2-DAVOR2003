#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {
  List* list= (List*) malloc (sizeof(list));
  list->head=NULL;
  list->tail=NULL;
  list->current=NULL;
  return list;
}

void * firstList(List * list) {
  if(list!=NULL && list->head!=NULL){
    list->current=list->head;
    return list->head->data;
  }
  return NULL;
}

void * nextList(List * list) {
  if (list->current != NULL && list->current->next!= NULL){
    list->current=list->current->next;
    return list->current->data;
    }
  return NULL;
}

void * lastList(List * list) {
  if(list->tail != NULL && list->tail->data!=NULL){
    list->current = list->tail;
    return list->tail->data;
  }
 return NULL;
}

void * prevList(List * list) {
  if(list->current !=NULL && list->current->prev!=NULL){
    list->current = list->current->prev;
    return list->current->data;
  }
 return NULL;
}

void pushFront(List * list, void * data) {
  Node* pun=createNode(data);
  if( list->head != NULL){
    pun->next=list->head;
    list->head->prev=pun;
    list->head=pun;
  }else{
    list->head=pun;
    list->tail=pun;
  }
  
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node* pun=createNode(data);
  if(list->current != NULL && list->current->next != NULL ){
    pun->next=list->current->next;
    pun->prev=list->current;
    //list->current=pun;
    list->current->next=pun;
    list->current->next->prev=pun;
  }
  list->tail=pun;
  pun->prev=list->current;
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  if(list->current != NULL && list->current->next != NULL){
    if(list->current->prev != NULL){
      list->current->prev->next =list->current->next;
      list->current->next->prev = list->current->prev;
      return list->current->data;
      }
  }
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}
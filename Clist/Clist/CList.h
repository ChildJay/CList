//#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LIST_TYPE 1 //0:单向链表 1:双向环形链表
#if LIST_TYPE == 0
typedef enum ListStatus
{
	MYLIST_OK = 0,
	MYLIST_NOINIT,
	MYLIST_NODE_NOINIT,
}ListStatus_t;

typedef	struct ListNode
{
	void* value;
	struct ListNode* next;
}ListNode_t;

typedef	struct MyList
{
	ListNode_t* node;
	unsigned int valueSize;
	unsigned int nodeNum;
}MyList_t;
#elif LIST_TYPE == 1
typedef enum ListStatus
{
	MYLIST_OK = 0,
	MYLIST_NOINIT,
	MYLIST_NODE_NOINIT,
}ListStatus_t;

typedef	struct ListNode
{
	void* value;
	struct ListNode* before;
	struct ListNode* next;
}ListNode_t;

typedef	struct MyList
{
	ListNode_t* node;
	unsigned int valueSize;
	unsigned int nodeNum;
}MyList_t;
#endif

ListNode_t* myList_newListNode(unsigned int size);
MyList_t* myList_Init(int size);
unsigned int myList_isEmpty(MyList_t* list);
unsigned int myList_length(MyList_t* list);
ListNode_t* myList_firstNode(MyList_t* list);
void* myList_first(MyList_t* list);
ListNode_t* myList_lastNode(MyList_t* list);
void* myList_last(MyList_t* list);
unsigned int myList_size(MyList_t* list);
unsigned int myList_fontSize(MyList_t* list);
ListNode_t* myList_atNode(MyList_t* list, unsigned int index);
void* myList_at(MyList_t* list, unsigned int index);
unsigned int myList_indexOf(MyList_t* list, void* value);
unsigned int myList_lastIndexOf(MyList_t* list);
void myList_append(MyList_t* list, void* value);
void myList_insert(MyList_t* list, unsigned int index, void* value);
ListNode_t* myList_swap(MyList_t* list);
void myList_swapItemsAt(MyList_t* list, unsigned int indexA, unsigned int indexB);
void myList_removeAll(MyList_t* list);
void myList_removeAt(MyList_t* list, unsigned int index);
void myList_removeBetween(MyList_t* list, unsigned int indexBegin, unsigned int indexEnd);
void myList_removeOne(MyList_t* list, void* value);
void myList_clear(MyList_t* list);

namespace MY_CLIST { class CList; }

class CList
{
public:

};


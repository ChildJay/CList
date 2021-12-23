#include "CList.h"

using namespace MY_CLIST;

#if LIST_TYPE == 0
ListNode_t* myList_newListNode(unsigned int size)
{
	ListNode_t* dataList;
	dataList = (ListNode_t*)malloc(sizeof(ListNode_t));
	dataList->next = NULL;
	dataList->value = NULL;
	return dataList;
}

MyList_t* myList_Init(int size)
{
	MyList_t* list;
	list = (MyList_t*)malloc(sizeof(MyList_t));
	list->node = NULL;
	list->valueSize = size;
	list->nodeNum = 0;
	return list;
}

unsigned int myList_isEmpty(MyList_t* list)
{
	if (list->node == NULL || list == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned int myList_length(MyList_t* list)
{
	ListNode_t* dataList = list->node;
	int len = 0;
	if (list->node == NULL || list == NULL)
	{
		return 0;
	}
	while (dataList != NULL)
	{
		dataList = dataList->next;
		len++;
	}
	return len;
}

ListNode_t* myList_firstNode(MyList_t* list)
{
	if (list->node == NULL || list == NULL)
	{
		return NULL;
	}
	return list->node;
}

void* myList_first(MyList_t* list)
{
	if (list->node == NULL || list == NULL)
	{
		return NULL;
	}
	return list->node->value;
}

ListNode_t* myList_lastNode(MyList_t* list)
{
	ListNode_t* dataList = list->node;
	if (list->node == NULL || list == NULL)
	{
		return NULL;
	}
	while (dataList->next != NULL)
	{
		dataList = dataList->next;
	}
	return dataList;
}

void* myList_last(MyList_t* list)
{
	if (list->node == NULL || list == NULL)
	{
		return NULL;
	}
	return myList_lastNode(list)->value;
}

unsigned int myList_size(MyList_t* list)
{
	unsigned int len = myList_length(list);
	return len * list->valueSize;
}

unsigned int myList_fontSize(MyList_t* list)
{
	return list->valueSize;
}

ListNode_t* myList_atNode(MyList_t* list, unsigned int index)
{
	ListNode_t* dataList = list->node;
	if (list->node == NULL || list == NULL)
	{
		return NULL;
	}
	for (unsigned int i = 0; i < index; i++)
	{
		if (dataList->next != NULL)
		{
			dataList = dataList->next;
		}
	}
	return dataList;
}

void* myList_at(MyList_t* list, unsigned int index)
{
	ListNode_t* dataList = list->node;
	if (list->node == NULL || list == NULL)
	{
		return NULL;
	}
	for (unsigned int i = 0; i < index; i++)
	{
		if (dataList->next != NULL)
		{
			dataList = dataList->next;
		}
	}
	return dataList->value;
}

unsigned int myList_indexOf(MyList_t* list, void* value)
{
	ListNode_t* dataList = list->node;
	unsigned int index = 0;
	if (list->node == NULL || list == NULL || value == NULL)
	{
		return NULL;
	}

	while (memcmp(value, dataList->value, list->valueSize) != 0)
	{
		if (dataList->next == NULL)
		{
			index = 0;
			break;
		}
		else
		{
			dataList = dataList->next;
			index++;
		}
	}
	return index;
}

unsigned int myList_lastIndexOf(MyList_t* list)
{
	ListNode_t* dataList = list->node;
	unsigned int index = 0;
	if (list->node == NULL || list == NULL)
	{
		return NULL;
	}
	while (dataList->next != NULL)
	{
		dataList = dataList->next;
		index++;
	}
	return index;
}

void myList_append(MyList_t* list, void* value)
{
	ListNode_t* dataList;
	unsigned int* valueData;
	if (list == NULL)
	{
		return;
	}

	dataList = (ListNode_t*)malloc(sizeof(ListNode_t));
	valueData = (unsigned int*)malloc(list->valueSize);
	memcpy(valueData, (const void*)value, list->valueSize);
	dataList->value = (void*)valueData;
	dataList->next = NULL;

	if (myList_isEmpty(list))
	{
		list->node = dataList;
	}
	else
	{
		myList_lastNode(list)->next = dataList;
	}
	list->nodeNum++;
}

void myList_insert(MyList_t* list, unsigned int index, void* value)
{
	ListNode_t* dataList;
	unsigned int* valueData;
	if (list == NULL)
	{
		return;
	}
	if (index >= myList_length(list))
	{
		return;
	}

	dataList = (ListNode_t*)malloc(sizeof(ListNode_t));
	valueData = (unsigned int*)malloc(list->valueSize);
	memcpy(valueData, (const void*)value, list->valueSize);
	dataList->value = (void*)valueData;
	dataList->next = NULL;

	if (index == 0)
	{
		ListNode_t* dataListTemp = list->node;
		list->node = dataList;
		list->node->next = dataListTemp;
	}
	else
	{
		ListNode_t* dataListTemp = myList_atNode(list, index);
		myList_atNode(list, index - 1)->next = dataList;
		dataList->next = dataListTemp;
	}
	list->nodeNum++;
}

ListNode_t* myList_swap(MyList_t* list)
{
	if (list->node == NULL || list->node->next == NULL || list == NULL)
	{
		return NULL;
	}
	ListNode_t* reverseList = NULL;
	ListNode_t* current = list->node;
	while (current != NULL)
	{
		ListNode_t* temp = current;
		current = current->next;
		temp->next = reverseList;
		reverseList = temp;
	}
	list->node = reverseList;
	return reverseList;
}

void myList_swapItemsAt(MyList_t* list, unsigned int indexA, unsigned int indexB)
{

	unsigned int len = myList_length(list);
	if (indexA >= len || indexB >= len)
	{
		return;
	}
	if (indexA == indexB)
	{
		return;
	}
	else if (indexA > indexB)
	{
		unsigned int indexTemp = indexA;
		indexA = indexB;
		indexB = indexTemp;
	}
	if (indexA != 0)
	{
		if (indexB - indexA != 1)
		{
			ListNode_t* dataListA;
			ListNode_t* dataListABefore;
			ListNode_t* dataListANext;
			ListNode_t* dataListB;
			ListNode_t* dataListBBefore;
			dataListABefore = myList_atNode(list, indexA - 1);
			dataListANext = myList_atNode(list, indexA + 1);
			dataListBBefore = myList_atNode(list, indexB - 1);
			dataListA = myList_atNode(list, indexA);
			dataListB = myList_atNode(list, indexB);
			dataListABefore->next = dataListB;
			dataListBBefore->next = dataListA;
			dataListA->next = dataListB->next;
			dataListB->next = dataListANext;
		}
		else
		{
			ListNode_t* dataListA;
			ListNode_t* dataListABefore;
			ListNode_t* dataListB;
			dataListABefore = myList_atNode(list, indexA - 1);
			dataListA = myList_atNode(list, indexA);
			dataListB = myList_atNode(list, indexB);
			dataListABefore->next = dataListB;
			dataListA->next = dataListB->next;
			dataListB->next = dataListA;
		}

	}
	else
	{
		if (indexB - indexA != 1)
		{
			ListNode_t* dataListA;
			ListNode_t* dataListANext;
			ListNode_t* dataListB;
			ListNode_t* dataListBBefore;
			dataListANext = myList_atNode(list, indexA + 1);
			dataListBBefore = myList_atNode(list, indexB - 1);
			dataListA = list->node;
			dataListB = myList_atNode(list, indexB);
			dataListBBefore->next = dataListA;
			dataListA->next = dataListB->next;
			dataListB->next = dataListANext;
			list->node = dataListB;
		}
		else
		{
			ListNode_t* dataListA;
			ListNode_t* dataListB;
			dataListA = list->node;
			dataListB = myList_atNode(list, indexB);
			dataListA->next = dataListB->next;
			dataListB->next = dataListA;
			list->node = dataListB;
		}

	}


}

void myList_removeAll(MyList_t* list)
{
	ListNode_t* dataList = list->node;
	if (list->node == NULL || list == NULL)
	{
		return;
	}
	while (dataList != NULL)
	{
		ListNode_t* dataListTmp = dataList;
		dataList = dataList->next;
		free(dataListTmp->value);
		free(dataListTmp);
	}
	list->node = NULL;
	list->nodeNum = 0;
}

void myList_removeAt(MyList_t* list, unsigned int index)
{
	ListNode_t* dataList = list->node;
	unsigned int len = 0;
	if (list->node == NULL || list == NULL)
	{
		return;
	}
	len = myList_length(list);
	if (index >= len)
	{
		return;
	}
	dataList = myList_atNode(list, index);
	if (len == 1)
	{
		list->node = NULL;
	}
	else
	{
		if (index != 0)
		{
			ListNode_t* dataListTmp;
			dataListTmp = myList_atNode(list, index - 1);
			dataListTmp->next = dataListTmp->next->next;
		}
		else
		{
			list->node = list->node->next;
		}
	}

	free(dataList->value);
	free(dataList);
	list->nodeNum--;
}

void myList_removeBetween(MyList_t* list, unsigned int indexBegin, unsigned int indexEnd)
{
	ListNode_t* dataList;
	unsigned int len = myList_length(list);
	if (list->node == NULL || list == NULL)
	{
		return;
	}
	if (indexBegin > indexEnd)
	{
		unsigned int tmp = indexBegin;
		indexBegin = indexEnd;
		indexEnd = tmp;
	}
	else if (indexBegin == indexEnd)
	{
		myList_removeAt(list, indexBegin);
		return;
	}

	if (indexBegin >= len)
	{
		return;
	}
	if (indexEnd >= len)
	{
		indexEnd = len - 1;
	}
	if ((indexBegin == 0) && (indexEnd == len - 1))
	{
		myList_removeAll(list);
	}
	else
	{
		for (unsigned int i = indexBegin; i <= indexEnd; i++)
		{
			myList_removeAt(list, indexBegin);
		}
	}
	list->nodeNum -= indexEnd - indexBegin + 1;
}

void myList_removeOne(MyList_t* list, void* value)
{
	myList_removeAt(list, myList_indexOf(list, value));
	list->nodeNum--;
}

void myList_clear(MyList_t* list)
{
	myList_removeAll(list);
	list->node = NULL;
	list->valueSize = 0;
	list->nodeNum = 0;
	free(list);
}

#elif LIST_TYPE == 1

ListNode_t* myList_newListNode(unsigned int size)
{
	ListNode_t* dataList;
	dataList = (ListNode_t*)malloc(sizeof(ListNode_t));
	dataList->before = NULL;
	dataList->next = NULL;
	dataList->value = NULL;
	return dataList;
}

MyList_t* myList_Init(int size)
{
	MyList_t* list;
	list = (MyList_t*)malloc(sizeof(MyList_t));
	list->node = NULL;
	list->valueSize = size;
	list->nodeNum = 0;
	return list;
}

unsigned int myList_isEmpty(MyList_t* list)
{
	if (list->node == NULL || list == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

unsigned int myList_length(MyList_t* list)
{
	ListNode_t* dataList = list->node;
	int len = 0;
	if (list->node == NULL || list == NULL)
	{
		return 0;
	}
	do
	{
		len++;
		dataList = dataList->next;
	} while (dataList != list->node);

	return len;
}

ListNode_t* myList_firstNode(MyList_t* list)
{
	if (list->node == NULL || list == NULL)
	{
		return NULL;
	}
	return list->node;
}

void* myList_first(MyList_t* list)
{
	if (list->node == NULL || list == NULL)
	{
		return NULL;
	}
	return list->node->value;
}

ListNode_t* myList_lastNode(MyList_t* list)
{
	ListNode_t* dataList = list->node;
	if (list->node == NULL || list == NULL)
	{
		return NULL;
	}
	return dataList->before;
}

void* myList_last(MyList_t* list)
{
	ListNode_t* dataList = list->node;
	if (list->node == NULL || list == NULL)
	{
		return NULL;
	}
	return dataList->before->value;
}

unsigned int myList_size(MyList_t* list)
{
	unsigned int len = myList_length(list);
	return len * list->valueSize;
}

unsigned int myList_fontSize(MyList_t* list)
{
	return list->valueSize;
}

ListNode_t* myList_atNode(MyList_t* list, unsigned int index)
{
	ListNode_t* dataList = list->node;
	unsigned int len = 0;
	if (list->node == NULL || list == NULL)
	{
		return NULL;
	}
	len = myList_length(list);
	if (index >= len / 2)
	{
		for (unsigned int i = len; i > index; i--)
		{
			if (dataList->before != list->node)
			{
				dataList = dataList->before;
			}
		}
	}
	else
	{
		for (unsigned int i = 0; i < index; i++)
		{
			if (dataList->next != list->node)
			{
				dataList = dataList->next;
			}
		}
	}
	return dataList;
}

void* myList_at(MyList_t* list, unsigned int index)
{
	ListNode_t* dataList = list->node;
	unsigned int len = 0;
	unsigned int node = 0;
	if (list->node == NULL || list == NULL)
	{
		return NULL;
	}
	len = myList_length(list);
	if (index >= len / 2)
	{
		for (unsigned int i = len; i > index; i--)
		{
			if (dataList->before != list->node)
			{
				dataList = dataList->before;
			}
		}
	}
	else
	{
		for (unsigned int i = 0; i < index; i++)
		{
			if (dataList->next != list->node)
			{
				dataList = dataList->next;
			}
		}
	}
	return dataList->value;
}

unsigned int myList_indexOf(MyList_t* list, void* value)
{
	ListNode_t* dataList = list->node;
	unsigned int index = 0;
	if (list->node == NULL || list == NULL || value == NULL)
	{
		return NULL;
	}

	while (memcmp(value, dataList->value, list->valueSize) != 0)
	{
		if (dataList->next == list->node)
		{
			index = 0;
			break;
		}
		else
		{
			dataList = dataList->next;
			index++;
		}
	}
	return index;
}

unsigned int myList_lastIndexOf(MyList_t* list)
{
	ListNode_t* dataList = list->node;
	unsigned int index = 0;
	if (list->node == NULL || list == NULL)
	{
		return NULL;
	}
	while (dataList->next != list->node)
	{
		dataList = dataList->next;
		index++;
	}
	return index;
}

void myList_append(MyList_t* list, void* value)
{
	ListNode_t* dataList;
	unsigned int* valueData;
	if (list == NULL)
	{
		return;
	}

	dataList = (ListNode_t*)malloc(sizeof(ListNode_t));
	valueData = (unsigned int*)malloc(list->valueSize);
	memcpy(valueData, (const void*)value, list->valueSize);
	dataList->value = (void*)valueData;
	dataList->next = NULL;
	dataList->before = NULL;

	if (myList_isEmpty(list))
	{
		list->node = dataList;
		list->node->before = list->node;
		list->node->next = list->node;
	}
	else
	{
		ListNode_t* dataListLast = myList_lastNode(list);
		dataListLast->next = dataList;
		dataList->before = dataListLast;
		dataList->next = list->node;
		list->node->before = dataList;
	}
	list->nodeNum++;
}

void myList_insert(MyList_t* list, unsigned int index, void* value)
{
	ListNode_t* dataList;
	ListNode_t* dataListInsert;
	unsigned int* valueData;
	if (list == NULL)
	{
		return;
	}
	if (index >= myList_length(list))
	{
		return;
	}

	dataList = (ListNode_t*)malloc(sizeof(ListNode_t));
	valueData = (unsigned int*)malloc(list->valueSize);
	memcpy(valueData, (const void*)value, list->valueSize);
	dataList->value = (void*)valueData;
	dataList->next = NULL;
	dataList->before = NULL;

	dataListInsert = myList_atNode(list, index);
	dataListInsert->before->next = dataList;
	dataList->before = dataListInsert->before;
	dataList->next = dataListInsert;
	dataListInsert->before = dataList;

	if (index == 0)
	{
		list->node = dataList;
	}
	list->nodeNum++;
}

ListNode_t* myList_swap(MyList_t* list)
{

	unsigned int len;
	if (list->node == NULL || list == NULL || list->node->next == list->node || list->node->before == list->node)
	{
		return NULL;
	}
	len = myList_length(list);

	if (1)//修改前后指针的方式
	{
		ListNode_t* ListTemp;
		unsigned int i = 0;
		do
		{
			ListTemp = list->node->next;
			list->node->next = list->node->before;
			list->node->before = ListTemp;
			list->node = list->node->before;
			i++;
		} while (i < len);
		list->node = list->node->before;
	}
	else//修改内容指针的方式
	{
		void* ListValueTemp;
		ListNode_t* ListNextTmp;
		ListNode_t* ListBeforeTmp;
		ListNextTmp = list->node;
		ListBeforeTmp = list->node->before;
		for (unsigned int i = 0; i < len / 2; i++)
		{
			ListValueTemp = ListNextTmp->value;
			ListNextTmp->value = ListBeforeTmp->value;
			ListBeforeTmp->value = ListValueTemp;
			ListNextTmp = ListNextTmp->next;
			ListBeforeTmp = ListBeforeTmp->before;
		}
	}

	return list->node;
}

void myList_swapItemsAt(MyList_t* list, unsigned int indexA, unsigned int indexB)
{

	unsigned int len = myList_length(list);
	if (indexA >= len || indexB >= len)
	{
		return;
	}
	if (indexA == indexB)
	{
		return;
	}
	else if (indexA > indexB)
	{
		unsigned int indexTemp = indexA;
		indexA = indexB;
		indexB = indexTemp;
	}
	if (1)//修改前后指针的方式
	{
		ListNode_t* dataListA;
		ListNode_t* dataListB;
		dataListA = myList_atNode(list, indexA);
		dataListB = myList_atNode(list, indexB);
		if ((dataListA->next == dataListB && dataListB->before == dataListA))
		{
			dataListA->next = dataListB->next;
			dataListB->before = dataListA->before;
			dataListA->before->next = dataListB;
			dataListB->next->before = dataListA;
			dataListA->before = dataListB;
			dataListB->next = dataListA;
		}
		else if (dataListA->before == dataListB && dataListB->next == dataListA)
		{
			dataListB->next = dataListA->next;
			dataListA->before = dataListB->before;
			dataListB->before->next = dataListA;
			dataListA->next->before = dataListB;
			dataListB->before = dataListA;
			dataListA->next = dataListB;
		}
		else
		{
			ListNode_t* dataListABef;
			ListNode_t* dataListANext;
			dataListABef = dataListA->before;
			dataListANext = dataListA->next;

			dataListA->before->next = dataListB;
			dataListA->next->before = dataListB;

			dataListB->before->next = dataListA;
			dataListB->next->before = dataListA;

			dataListA->before = dataListB->before;
			dataListA->next = dataListB->next;

			dataListB->before = dataListABef;
			dataListB->next = dataListANext;
		}
	}
	else //修改内容指针的方式
	{
		void* ListValueTemp;
		ListNode_t* dataListA;
		ListNode_t* dataListB;
		dataListA = myList_atNode(list, indexA);
		dataListB = myList_atNode(list, indexB);
		ListValueTemp = dataListA->value;
		dataListA->value = dataListB->value;
		dataListB->value = ListValueTemp;
	}


}

void myList_removeAll(MyList_t* list)
{
	ListNode_t* dataList = list->node;
	unsigned int i = 0;
	unsigned int len = 0;
	if (list->node == NULL || list == NULL)
	{
		return;
	}
	len = myList_length(list);
	ListNode_t* ListNextTmp;
	ListNode_t* ListBeforeTmp;
	ListNode_t* dataListTmp;
	ListNextTmp = list->node;
	ListBeforeTmp = list->node->before;
	for (i = 0; i < len / 2; i++)
	{
		dataListTmp = ListNextTmp;
		ListNextTmp = ListNextTmp->next;
		free(dataListTmp->value);
		free(dataListTmp);
		dataListTmp = ListBeforeTmp;
		ListBeforeTmp = ListBeforeTmp->before;
		free(dataListTmp->value);
		free(dataListTmp);
	}
	if (len % 2 != 0)
	{
		dataListTmp = ListNextTmp;
		free(dataListTmp->value);
		free(dataListTmp);
	}
	list->node = NULL;
	list->nodeNum = 0;
}

void myList_removeAt(MyList_t* list, unsigned int index)
{
	ListNode_t* dataList = list->node;
	unsigned int len = 0;
	if (list->node == NULL || list == NULL)
	{
		return;
	}
	len = myList_length(list);
	if (index >= len)
	{
		return;
	}
	dataList = myList_atNode(list, index);
	dataList->before->next = dataList->next;
	dataList->next->before = dataList->before;
	if (len == 1)
	{
		list->node = NULL;
	}
	else
	{
		if (index == 0)
		{
			list->node = list->node->next;
		}
	}
	free(dataList->value);
	free(dataList);
	list->nodeNum--;
}

void myList_removeBetween(MyList_t* list, unsigned int indexBegin, unsigned int indexEnd)
{
	ListNode_t* dataListBegin;
	ListNode_t* dataListEnd;
	unsigned int len = myList_length(list);
	if (list->node == NULL || list == NULL)
	{
		return;
	}
	if (indexBegin > indexEnd)
	{
		unsigned int tmp = indexBegin;
		indexBegin = indexEnd;
		indexEnd = tmp;
	}
	else if (indexBegin == indexEnd)
	{
		myList_removeAt(list, indexBegin);
		return;
	}

	if (indexBegin >= len)
	{
		return;
	}
	if (indexEnd >= len)
	{
		indexEnd = len - 1;
	}
	if ((indexBegin == 0) && (indexEnd == len - 1))
	{
		myList_removeAll(list);
	}
	else
	{
		dataListBegin = myList_atNode(list, indexBegin);
		dataListEnd = myList_atNode(list, indexEnd);
		dataListBegin->before->next = dataListEnd->next;
		dataListEnd->next->before = dataListBegin->before;
		if (indexBegin == 0)
		{
			list->node = dataListEnd->next;
		}
		for (unsigned int i = indexBegin; i <= indexEnd; i++)
		{
			//myList_removeAt(list, indexBegin);
			dataListEnd = dataListBegin;
			dataListBegin = dataListBegin->next;
			free(dataListEnd->value);
			free(dataListEnd);
		}

	}
	list->nodeNum -= indexEnd - indexBegin + 1;
}

void myList_removeOne(MyList_t* list, void* value)
{
	myList_removeAt(list, myList_indexOf(list, value));
	list->nodeNum--;
}

void myList_clear(MyList_t* list)
{
	myList_removeAll(list);
	list->node = NULL;
	list->valueSize = 0;
	list->nodeNum = 0;
	free(list);
}

#endif

typedef struct
{
	int A;
	short B;
	char C;
}Data_t;

MyList_t* listNodeTest = NULL;

void fun_test(void)
{
	Data_t tmp1 = { 1111,2,3 };
	Data_t tmp2 = { 11111,22,33 };
	Data_t tmp3 = { 111111,222,100 };
	printf("\r\nsizeof(Data_t) = %d\r\n", sizeof(Data_t));
	printf("\r\n 0: tmp1:%d %d %d\r\n", tmp1.A, tmp1.B, tmp1.C);
	printf("\r\n 1: tmp2:%d %d %d\r\n", tmp2.A, tmp2.B, tmp2.C);
	printf("\r\n 2: tmp3:%d %d %d\r\n", tmp3.A, tmp3.B, tmp3.C);
	printf("\r\n ListIsEmpty = %d\r\n", myList_isEmpty(listNodeTest));
	myList_append(listNodeTest, &tmp1);
	myList_append(listNodeTest, &tmp2);
	myList_append(listNodeTest, &tmp3);
	printf("\r\n 0: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 0)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->C);
	printf("\r\n 1: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 1)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 1)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 1)->value)->C);
	printf("\r\n 2: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 2)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 2)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 2)->value)->C);
	printf("\r\n ListIsEmpty = %d\r\n", myList_isEmpty(listNodeTest));
	printf("\r\n ListLength = %d\r\n", myList_length(listNodeTest));
	printf("\r\n ListSize = %d\r\n", myList_size(listNodeTest));
	printf("\r\n ListIndexOf = %d\r\n", myList_indexOf(listNodeTest, &tmp3));
	myList_swap(listNodeTest);
	printf("\r\n myList_swap\r\n");
	printf("\r\n 0: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 0)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->C);
	printf("\r\n 1: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 1)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 1)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 1)->value)->C);
	printf("\r\n 2: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 2)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 2)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 2)->value)->C);
	myList_removeAt(listNodeTest, 1);
	myList_removeAt(listNodeTest, 0);
	printf("\r\n myList_removeAt 0 , 1\r\n");
	printf("\r\n 0: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 0)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->C);
	myList_append(listNodeTest, &tmp1);
	myList_append(listNodeTest, &tmp2);
	printf("\r\n myList_append\r\n");
	printf("\r\n 0: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 0)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->C);
	printf("\r\n 1: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 1)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 1)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 1)->value)->C);
	printf("\r\n 2: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 2)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 2)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 2)->value)->C);
	myList_removeBetween(listNodeTest, 0, 1);
	printf("\r\n myList_removeBetween 0 - 1\r\n");
	printf("\r\n 0: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 0)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->C);
	myList_insert(listNodeTest, 0, &tmp1);
	myList_insert(listNodeTest, 1, &tmp3);
	printf("\r\n myList_insert\r\n");
	printf("\r\n 0: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 0)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->C);
	printf("\r\n 1: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 1)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 1)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 1)->value)->C);
	printf("\r\n 2: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 2)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 2)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 2)->value)->C);
	myList_swapItemsAt(listNodeTest, 0, 2);
	printf("\r\n myList_swapItemsAt 0 , 2\r\n");
	printf("\r\n 0: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 0)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->C);
	printf("\r\n 1: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 1)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 1)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 1)->value)->C);
	printf("\r\n 2: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 2)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 2)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 2)->value)->C);
	myList_swapItemsAt(listNodeTest, 0, 1);
	printf("\r\n myList_swapItemsAt 0 , 1\r\n");
	printf("\r\n 0: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 0)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->C);
	printf("\r\n 1: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 1)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 1)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 1)->value)->C);
	printf("\r\n 2: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 2)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 2)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 2)->value)->C);
	myList_swapItemsAt(listNodeTest, 1, 2);
	printf("\r\n myList_swapItemsAt 1 , 2\r\n");
	printf("\r\n 0: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 0)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->C);
	printf("\r\n 1: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 1)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 1)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 1)->value)->C);
	printf("\r\n 2: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 2)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 2)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 2)->value)->C);
	printf("\r\n myList_at\r\n");
	printf("\r\n 0: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_at(listNodeTest, 0))->A, ((Data_t*)myList_at(listNodeTest, 0))->B, ((Data_t*)myList_at(listNodeTest, 0))->C);
	printf("\r\n 1: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_at(listNodeTest, 1))->A, ((Data_t*)myList_at(listNodeTest, 1))->B, ((Data_t*)myList_at(listNodeTest, 1))->C);
	printf("\r\n 2: tmpdataList->value:%d %d %d\r\n", ((Data_t*)myList_at(listNodeTest, 2))->A, ((Data_t*)myList_at(listNodeTest, 2))->B, ((Data_t*)myList_at(listNodeTest, 2))->C);
}

int main()
{
	listNodeTest = myList_Init(sizeof(Data_t));
	fun_test();


	if (!myList_isEmpty(listNodeTest))
	{
		printf("\r\n ListIsEmpty = %d\r\n", myList_isEmpty(listNodeTest));
		((Data_t*)myList_at(listNodeTest, 2))->A = 555;
		((Data_t*)myList_at(listNodeTest, 1))->B = 666;
		((Data_t*)myList_at(listNodeTest, 0))->C = 99;
		printf("\r\n 0: listNodeTest->node->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 0)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 0)->value)->C);
		printf("\r\n 1: listNodeTest->node->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 1)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 1)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 1)->value)->C);
		printf("\r\n 2: listNodeTest->node->value:%d %d %d\r\n", ((Data_t*)myList_atNode(listNodeTest, 2)->value)->A, ((Data_t*)myList_atNode(listNodeTest, 2)->value)->B, ((Data_t*)myList_atNode(listNodeTest, 2)->value)->C);
	}
	myList_removeAll(listNodeTest);
	printf("\r\n ListIsEmpty = %d\r\n", myList_isEmpty(listNodeTest));
	myList_clear(listNodeTest);
	getchar();
	return 0;
}


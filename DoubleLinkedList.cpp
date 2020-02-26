#include "DoubleLinkedList.h"
#include <iostream>

//Node implementation
//default constructor: calls custom cunstructor
Node::Node() : Node(0, 0, nullptr, nullptr)
{}

//custom constructor
Node::Node(int data, size_t index, Node* next, Node* prev)
{
	Node::data = data;
	Node::index = index;
	Node::next = next;
	Node::prev = prev;
}

//default destructor
Node::~Node()
{
	//delete* Node;
}




//DoubleLinkedList implementation
//default constructor
DoubleLinkedList::DoubleLinkedList() //: DoublelinkedList(DEFAULT_VALUES)
{
	//head+tail=2
	size = 2;
	//head: next=null, prev=null
	Node* head = new Node(0, 0, nullptr, nullptr);
	//tail: next=null, prev=head
	Node* tail = new Node(1, 1, nullptr, head);
	//head: next=tail, prev=null
	head->next = tail;
	//set list's head and tail to new nodes
	DoubleLinkedList::head = head;
	DoubleLinkedList::tail = tail;
}

//custom constructor
DoubleLinkedList::DoubleLinkedList(int* array)
{
	std::cout << "AAAAAAAA" << std::endl;
}

//default destructor
DoubleLinkedList::~DoubleLinkedList()
{
	//delete EVERYTHING!?
}

//grabs data from node at specified index
int DoubleLinkedList::ReadAt(size_t index)
{
	NavigateTo(index);
	return cursor->data;
}

//inserts at specified index
void DoubleLinkedList::InsertBefore(int data, size_t index)
{
	//create new node with desired data and index
	Node* new_node = new Node(data, index, nullptr, nullptr);
	//if desired index is head:
	if (index == 0)
	{
		new_node->next = head;
		//prev is already null

		new_node->next->prev = new_node;
		//old head's next is fine as-is

		//reassign head
		head = new_node;
	}
	else
	{
		InsertBetweenEndsBefore(index, new_node);
	}

	size++;
	AuditIndeces();
}

void DoubleLinkedList::InsertAfter(int data, size_t index)
{
	//create new node with desired data and index
	Node* new_node = new Node(data, index, nullptr, nullptr);
	//if desired index is tail:
	if (index >= size-1)
	{
		new_node->prev = tail;
		//next is already null

		new_node->prev->next = new_node;
		//old tail's prev is fine as-is

		//reassign tail
		tail = new_node;
	}
	//if desired index is head:
	else if (index == 0)
	{

		InsertBetweenEndsBefore(1, new_node);
	}
	else
	{
		InsertBetweenEndsBefore(index+1, new_node);
	}

	size++;
	AuditIndeces();
}

//removes node at specified index
void DoubleLinkedList::RemoveAt(size_t index)
{
	NavigateTo(index);
	//index is head
	if (index == 0)
	{
		cursor->next->prev = nullptr;
		//head has no prev

		head = cursor->next;

		cursor->next = nullptr;
		//head's prev is already null
	}
	//index is tail
	else if (index >= size-1)
	{
		//tail's next is already null
		cursor->prev->next = nullptr;

		tail = cursor->prev;

		//tail's next is already null
		cursor->prev = nullptr;
	}
	else
	{
		cursor->next->prev = cursor->prev;
		cursor->prev->next = cursor->next;
		cursor->next = nullptr;
		cursor->prev = nullptr;
	}
	delete cursor;
	size--;
	AuditIndeces();
}

//prints entire list
void DoubleLinkedList::Display()
{
	Display(0, size);
}

//prints specified nodes in list
void DoubleLinkedList::Display(size_t start, size_t end)
{
	cursor = head;
	for (size_t i = start; i < end-1; i++)
	{
		std::cout << cursor->data << " = ";
		cursor = cursor->next;
	}
	std::cout << cursor->data << std::endl;
}

//moves cursor to specified index
void DoubleLinkedList::NavigateTo(size_t index)
{
	cursor = head;
	for (size_t i = 0; i < index; i++)
	{
		cursor = cursor->next;
	}
}

//called by InsertBefore and InsertAfter
void DoubleLinkedList::InsertBetweenEndsBefore(size_t index, Node* new_node)
{
	NavigateTo(index);
	new_node->next = cursor;
	cursor->prev = new_node;
	NavigateTo(index - 1);
	new_node->prev = cursor;
	cursor->next = new_node;
}

//copascetisize indeces
void DoubleLinkedList::AuditIndeces()
{
	cursor = head;
	for (size_t i = 0; i < size-1; i++)
	{
		cursor->index = i;
		cursor = cursor->next;
	}
}

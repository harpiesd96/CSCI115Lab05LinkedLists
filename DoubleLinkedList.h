#pragma once

const int DEFAULT_VALUES[2] = {0, 0};

class Node
{
public:
	int data;
	size_t index;
	Node* next = nullptr;
	Node* prev = nullptr;

	Node();
	Node(int data, size_t index, Node* next, Node* prev);
	~Node();
};

class DoubleLinkedList
{
public:
	size_t size = 0;
	Node* head = nullptr;
	Node* tail = nullptr;

	DoubleLinkedList();
	DoubleLinkedList(int* array);
	~DoubleLinkedList();

	int ReadAt(size_t index);
	void InsertBefore(int data, size_t index);
	void InsertAfter(int data, size_t index);
	void RemoveAt(size_t index);
	void Display();
	void Display(size_t start, size_t end);

private:
	Node* cursor = nullptr;
	void NavigateTo(size_t index);
	void InsertBetweenEndsBefore(size_t index, Node* new_node);
	void AuditIndeces();
};
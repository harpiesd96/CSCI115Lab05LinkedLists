#include "DoubleLinkedList.h"
#include <iostream>

int main()
{
    std::cout << "Hello World!\n" << std::endl;

	DoubleLinkedList DLL;
	DLL.Display();

	std::cout << "reading 0: " << DLL.ReadAt(0) << std::endl;
	std::cout << "reading 1: " << DLL.ReadAt(1) << std::endl;

	DLL.InsertBefore(12, 0);
	DLL.Display();

	DLL.InsertBefore(11, 0);
	DLL.Display();

	DLL.InsertBefore(10, 0);
	DLL.Display();

	DLL.InsertBefore(20, DLL.size-1);
	DLL.Display();

	DLL.InsertAfter(30, DLL.size-1);
	DLL.Display();

	DLL.InsertAfter(31, 0);
	DLL.Display();

	DLL.RemoveAt(5);
	DLL.Display();

	DLL.RemoveAt(0);
	DLL.Display();

	DLL.RemoveAt(DLL.size-1);
	DLL.Display();

	std::cout << "reading 3: " << DLL.ReadAt(3) << std::endl;
	std::cout << "reading 4: " << DLL.ReadAt(4) << std::endl;

	std::cout << "size: " << DLL.size << std::endl;

	system("pause");

	return 0;
}
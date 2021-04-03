#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "BST.h"

int main() {
	Link* l1 = new Link(5);
	Link* l2 = new Link(15);
	Link* root = new Link(10, l1, l2);
	BST b(root);
	
	while (true) {
		system("cls");
		std::cout << b;
		std::cout << std::endl
			<< "0. exit" << std::endl
			<< "1. find" << std::endl
			<< "2. add" << std::endl
			<< "3. delete" << std::endl;
		int n;
		int val;
		std::string s;
		std::cin >> n;
		try {
			switch (n)
			{
			case 0:
				return 0;
			case 1:
				std::cin >> val;
				std::cout << b.search(val) << std::endl;
				_getch();
				break;
			case 2:
				std::cin >> val;
				b.add(val);
				break;
			case 3:
				std::cin >> val;
				b.del(val);
				break;
			default:
				break;
			}
		}
		catch (const char* s) {
			std::cout << s << std::endl;
			_getch();
		}
	}
}
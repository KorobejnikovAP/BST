#pragma once
#include <iostream>
#include <stack>


struct Link {
	int val;
	Link* l;
	Link* r;

	Link(int _val = 0, Link * _l = nullptr, Link * _r = nullptr) : val(_val), l(_l), r(_r) {}
};

class BST
{
	Link* root;

public:
	BST(Link* r) : root(r) {}

	bool search(int val);
	void add(int _val);
	void del(int _val);

	friend std::ostream& operator << (std::ostream& o, BST& _t);
};



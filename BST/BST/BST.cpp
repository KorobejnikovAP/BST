#include "BST.h"
#include <iomanip>

void print(std::ostream& o, Link* root, int lvl) {
	if (root == nullptr)
		return;

	for (int i = 0; i < lvl; ++i)
		o << "  ";
	o << root->val << std::endl;
	print(o, root->r,  lvl + 1);
	print(o, root->l,  lvl);
}


std::ostream& operator<<(std::ostream& o, BST& _t)
{
	print(o, _t.root, 0);
	return o;
}


//void print(std::ostream& o, Link* p, int indent)
//{
//	if (p != NULL) {
//		if (p->r) {
//			print(o, p->r, indent + 4);
//		}
//		if (indent) {
//			o << std::setw(indent) << ' ';
//		}
//		if (p->r) o << " /\n" << std::setw(indent) << ' ';
//		o << p->val << "\n ";
//		if (p->l) {
//			o << std::setw(indent) << ' ' << " \\\n";
//			print(o, p->l, indent + 4);
//		}
//	}
//}
//std::ostream& operator<<(std::ostream& o, BST& _t)
//{
//	print(o, _t.root, 0);
//	return o;
//}

bool BST::search(int _val)
{
	Link* tmp = root;
	while (tmp != nullptr) {
		if (tmp->val == _val)
			return true;
		if (_val > tmp->val)
			tmp = tmp->r;
		else tmp = tmp->l;
	}
	return false;
}

void BST::add(int _val)
{
	Link* link = new Link(_val);
	if (root == nullptr)
		root = link;
	Link* curr = root;
	while (curr) {
		if (curr->val == _val)
			return ;
		if (_val > curr->val) {
			if (curr->r == nullptr) {
				curr->r = link;
				return;
			}
			curr = curr->r;
		}
		else {
			if (curr->l == nullptr) {
				curr->l = link;
				return;
			}
			curr = curr->l;
		}
	}
}

void BST::del(int _val)
{
	Link* curr = root;
	Link* parent = nullptr;
	while (curr->val != _val) {
		parent = curr;
		if (_val > curr->val)
			curr = curr->r;
		else 	
			curr = curr->l;
	}
	
	if (!curr)
		return;
	if (curr->l == nullptr && curr->r == nullptr) {
		if (!parent) {
			delete root;
			root = nullptr;
			return;
		}
		if (parent->l == curr) {
			parent->l = nullptr;
			delete curr;
			return;
		}
		if (parent->r == curr) {
			parent->r = nullptr;
			delete curr;
			return;
		}
	}

	if (curr->l == nullptr) {
		if (!parent) {
			curr->val = curr->r->val;
			delete curr->r;
			curr->r = nullptr;
			return;
		}
		if (parent && parent->l == curr)
			parent->l = curr->r;
		if (parent && parent->r == curr)
			parent->r = curr->r;
		delete curr;
		return;
	}

	if (curr->r == nullptr) {
		if (!parent) {
			curr->val = curr->l->val;
			delete curr->l;
			curr->l = nullptr;
			return;
		}
		if (parent && parent->l == curr)
			parent->l = curr->l;
		if (parent && parent->r == curr)
			parent->r = curr->l;
		delete curr;
		return;
	}

	Link* tmp = curr->r;
	while (tmp->l) tmp = tmp->l;
	int tval = tmp->val;
	del(tval);
	curr->val = tval;
}



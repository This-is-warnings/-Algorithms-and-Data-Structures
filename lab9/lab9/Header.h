#pragma once
#include <iostream>
#include <list>
#include <string>
using namespace std;

class Heap {
	int data;
	int degree;
	Heap *child;//ребенок
	Heap *sibling;//брат или сестра
	Heap *parent;//родитель 
public:

	Heap* creat(int key) {
		Heap *temp = new Heap;
		temp->data = key;
		temp->degree = NULL;
		temp->child = temp->parent = temp->sibling = NULL;
		return temp;
	}


	list<Heap*> sort_degree(list<Heap*> l1, list<Heap*> l2) {
		list<Heap*> _new;
		list<Heap*>::iterator it = l1.begin();
		list<Heap*>::iterator ot = l2.begin();
		while (it != l1.end() && ot != l2.end()) {
			if ((*it)->degree <= (*ot)->degree) {
				_new.push_back(*it);
				it++;
			}
			else {
				_new.push_back(*ot);
				ot++;
			}
		}
		while (it != l1.end()) {
			_new.push_back(*it);
			it++;
		}
		while (ot != l2.end()) {
			_new.push_back(*ot);
			ot++;
		}
		return _new;
	}

	// слияние
	Heap* merge(Heap *b1, Heap *b2) {
		if (b1->data > b2->data) {
			Heap *temp;
			temp = b1;
			b1 = b2;
			b2 = temp;
		}
		b2->parent = b1;
		b2->sibling = b1->child;
		b1->child = b2;
		b1->degree++;
		return b1;
	}

	list<Heap*> invariant(list<Heap*> heap) {
		if (heap.size() == 1) {
			return heap;
		}
		list<Heap*> newheap;
		list<Heap*>::iterator it1, it2, it3;
		it1 = it2 = it3 = heap.begin();
		if (heap.size() == 2) {
			it2++;
			it3 = heap.end();
		}
		else {
			it2++;
			it3 = it2;
			it3++;
		}
		while (it1 != heap.end()) {
			if (it2 == heap.end()) {
				it1++;
			}
			else if ((*it1)->degree < (*it2)->degree) {
				it1++;
				it2++;
				if (it3 != heap.end())
					it3++;
			}
			else if (it3 != heap.end() && (*it1)->degree == (*it2)->degree && (*it1)->degree == (*it3)->degree) {
				it1++;
				it2++;
				it3++;
			}
			else if ((*it1)->degree == (*it2)->degree) {
				*it1 = merge(*it1, *it2);
				it2 = heap.erase(it2);
				if (it3 != heap.end()) {
					it3++;
				}
			}
		}
		return heap;
	}
	// вставка в кучу дерева
	list<Heap*> insertInHeap(list<Heap*> heap, Heap *tree) {
		list<Heap*> temp;
		temp.push_back(tree);
		temp = sort_degree(heap, temp);
		list<Heap*> _temp = invariant(temp);
		return _temp;
	}

	list<Heap*> insert(list<Heap*> _head, int key) {
		Heap *temp = creat(key);
		list<Heap*> _temp = insertInHeap(_head, temp);
		return _temp;
	}

	list<Heap*> removeMaxPriority(Heap *tree) {
		list<Heap*> heap;
		Heap *temp = tree->child;
		Heap *lo;
		while (temp) {
			lo = temp;
			temp = temp->sibling;
			lo->sibling = NULL;
			heap.push_front(lo);
		}
		return heap;
	}

	Heap* getMaxPriority(list<Heap*> heap) {
		list<Heap*>::iterator it = heap.begin();
		Heap *temp = *it;
		while (it != heap.end()) {
			if ((*it)->data < temp->data) {
				temp = *it;
			}
			it++;
		}
		return temp;
	}

	list<Heap*> deleteMaxPriority(list<Heap*> heap) {
		list<Heap*> newheap, lo;
		Heap *temp;
		temp = getMaxPriority(heap);
		list<Heap*>::iterator it;
		it = heap.begin();
		while (it != heap.end()) {
			if (*it != temp) {
				newheap.push_back(*it);
			}
			it++;
		}
		lo = removeMaxPriority(temp);
		newheap = sort_degree(newheap, lo);
		list<Heap*> _temp = invariant(newheap);
		return _temp;
	}

	void Print_Binomial_Heap(const string & probel, const Heap* top, bool childs, bool viv, int l) {
		bool ghg = false;
		while (top != 0) {
			if (top != 0) {
				if (top->child != 0 || top->sibling != 0) {
					viv = true;
				}
				else {
					viv = false;
				}
				cout << probel;
				if (childs) {
					cout << "|----:" << top->data << endl;
				}
				else {
					if (l == 1) {
						cout << "------" << top->data << endl;
						l++;
						if (top->child == 0 && top->parent == 0) {
							ghg = true;
						}
					}
				}
				if (childs) {
					Print_Binomial_Heap(probel + "|     ", top->child, true, viv, l);
				}
				else {
					Print_Binomial_Heap(probel + "      ", top->child, true, viv, l);
				}
				top = top->sibling;
			}
		}
	}
};
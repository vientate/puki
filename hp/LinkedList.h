#pragma once
#include "Node.h"
#include "hp.h"
#include <iostream>
#include <sstream>
#include <fstream>

class LinkedList
{
public:
	LinkedList() : head(nullptr) {};
	void clear();
	LinkedList* find(string field, string value);
	void add(Doctor* p);
	void LoadFromFile(string filename);
	void SaveToFile(string filename);
	int remove(string field, string value);
	bool isEmpty() { return head == nullptr; }
	void sort(string fiel, bool ascending);
	int getSize() const;
	Node* head;
private:
	Node* findById(int id);
	Node* findByExperience(int experience);
	Node* findByOffice(int office);
	Node* findByName(string name);
	Node* findByPost(string post);
	Node* findBySkill(string skill);
	Node* findBySpecialization(string specializatoin);
	void removeNode(Node* to_detele);
};


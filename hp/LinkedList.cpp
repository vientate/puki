#include "LinkedList.h"
#include "hp.h"

void LinkedList::clear()
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* temp = current;
		current = current->next;
		delete temp;
	}
	head = nullptr;
}

void LinkedList::add(Doctor* p) {
	Node* new_node = new Node(p);
	if (head == nullptr) {
		head = new_node;
		return;
	}
	Node* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}
	current->next = new_node;
}

void LinkedList::LoadFromFile(string filename) {
	ifstream infile(filename);
	if (!infile) {
		throw runtime_error("Файл с данными не найден");
	}
	clear();
	string line;
	while (getline(infile, line)) {
		stringstream ss(line);
		string id, experience, office, name, post, skill, specialization;
		getline(ss, id, ';');
		getline(ss, name, ';');
		getline(ss, skill, ';');
		getline(ss, post, ';');
		getline(ss, specialization, ';');
		getline(ss, experience, ';');
		getline(ss, office, ';');
		int Id = stoi(id);
		double Experience = stoi(experience);
		double Office = stoi(office);
		Doctor* doctor = new Doctor(Id, Office, experience, name, post, skill, specialization);
		add(doctor);
	}
	infile.close();
}


void LinkedList::SaveToFile(string filename) {
	ofstream outfile(filename);
	if (!outfile) {
		throw runtime_error("Ошибка создания файла");
	}
	Node* current = head;

	while (current != nullptr) {
		outfile << current->data->getId() << ";"
			<< current->data->getName() << ";"
			<< current->data->getSkill() << ";"
			<< current->data->getPost() << ";"
			<< current->data->getSpecialization() << ";"
			<< current->data->getExperience() << ";"
			<< current->data->getOffice() << endl;
		current = current->next;
	}
	outfile.close();
}


LinkedList* LinkedList::find(string field, string value) {
	LinkedList* result = new LinkedList();
	Node* current = head;
	while (current != nullptr)
	{
		if (field == "id" && current->data->getId() == stoi(value))
		{
			result->add(current->data);
		}
		else if (field == "name" && current->data->getName() == value)
		{
			result->add(current->data);
		}
		else if (field == "office" && current->data->getOffice() == stod(value))
		{
			result->add(current->data);
		}
		else if (field == "post" && current->data->getPost() == value)
		{
			result->add(current->data);
		}
		else if (field == "specialization" && current->data->getSpecialization() == value)
		{
			result->add(current->data);
		}
		current = current->next;
	}
	if (result->isEmpty())
	{
		delete result;
		return nullptr;
	}
	return result;
}

int LinkedList::remove(string field, string value)
{
	int counter = 0;
	Node* to_delete = nullptr;
	if (field == "id")
	{
		while ((to_delete = findById(stoi(value))) != nullptr)
		{
			removeNode(to_delete);
			counter++;
		}
		return counter;
	}
	else if (field == "name")
	{
		while ((to_delete = findByName(value)) != nullptr)
		{
			removeNode(to_delete);
			counter++;
		}
		return counter;
	}
	else if (field == "office")
	{
		while ((to_delete = findByOffice(stoi(value))) != nullptr)
		{
			removeNode(to_delete);
			counter++;
		}
		return counter;
	}
	else if (field == "post")
	{
		while ((to_delete = findByPost(value)) != nullptr)
		{
			removeNode(to_delete);
			counter++;
		}
		return counter;
	}
	else if (field == "specialization")
	{
		while ((to_delete = findBySpecialization(value)) != nullptr)
		{
			removeNode(to_delete);
			counter++;
		}
		return counter;
	}
	else {
		cout << "Неверное поле: " << field << endl;
		return counter;
	}
}

void LinkedList::removeNode(Node* to_delete)
{
	if (head == to_delete)
	{
		head = head->next;
		delete to_delete;
		return;
	}
	Node* current = head;
	while (current->next != nullptr)
	{
		if (current->next == to_delete)
		{
			current->next = current->next->next;
			delete to_delete;
			return;
		}
		current = current->next;
	}
}

Node* LinkedList::findById(int id)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data->getId() == id)
			return current;
		current = current->next;
	}
	return nullptr;
}

Node* LinkedList::findByExperience(int experience)
{
	string experience_str = to_string(experience);
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data->getExperience() == experience_str)
			return current;
		current = current->next;
	}
	return nullptr;
}

Node* LinkedList::findByOffice(int office)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data->getOffice() == office)
			return current;
		current = current->next;
	}
	return nullptr;
}

Node* LinkedList::findByName(string name)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data->getName() == name)
			return current;
		current = current->next;
	}
	return nullptr;
}

Node* LinkedList::findByPost(string post)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data->getPost() == post)
			return current;
		current = current->next;
	}
	return nullptr;
}

Node* LinkedList::findBySkill(string skill)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data->getSkill() == skill)
			return current;
		current = current->next;
	}
	return nullptr;
}

Node* LinkedList::findBySpecialization(string specializatoin)
{
	Node* current = head;
	while (current != nullptr)
	{
		if (current->data->getSpecialization() == specializatoin)
			return current;
		current = current->next;
	}
	return nullptr;
}

int LinkedList::getSize() const
{
	Node* current = head;
	int result = 0;
	while (current != nullptr)
	{
		++result;
		current = current->next;
	}
	return result;
}

void LinkedList::sort(string field, bool ascending)
{
	int size = getSize();
	for (int i = 0; i < size - 1; ++i)
	{
		Node* current = head;
		for (int j = 0; j < size - 1 - i; ++j)
		{
			Node* next = current->next;
			if ((ascending && current->data->isGreaterThen(next->data, field)) || (!ascending && current->data->isLessThen(next->data, field)))
			{
				Doctor* temp = current->data;
				current->data = next->data;
				next->data = temp;
			}
			current = next;
		}
	}
}

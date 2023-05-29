#pragma once
#include "SaveFormat.h"

class JsonFormat : public SaveFormat
{
public:
	void save(LinkedList* list, string filename) override {
		ofstream outfile(filename);
		if (!outfile) {
			cout << "Error creating file " << filename << endl;
			return;
		}
		outfile << "{" << endl;
		outfile << " \"doctors\": [" << endl;
		Node* current = list->head;
		while (current != nullptr) {
			outfile << "    {" << endl;
			outfile << "        \"id\": " << current->data->getId() << "," << endl;
			outfile << "        \"experience\": " << current->data->getExperience() << "," << endl;
			outfile << "        \"office\": " << current->data->getOffice() << "," << endl;
			outfile << "        \"name\": " << current->data->getName() << "," << endl;
			outfile << "        \"post\": \"" << current->data->getPost() << "\"," << endl;
			outfile << "        \"skill\": \"" << current->data->getSkill() << "\"," << endl;
			outfile << "        \"specialization\": \"" << current->data->getSpecialization() << "\"," << endl;
			outfile << "    }";
			current = current->next;
			if (current != nullptr) {
				outfile << ",";
			}
			outfile << endl;
		}
		outfile << "  }" << endl;
		outfile << "}" << endl;
		outfile.close();
	}
};

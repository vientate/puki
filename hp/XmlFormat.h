#pragma once
#include "SaveFormat.h"

class XmlFormat : public SaveFormat
{
public:
	void save(LinkedList* list, string filename) override {
		ofstream outfile(filename);
		if (!outfile) {
			cout << "Error creating file " << filename << endl;
			return;
		}
		outfile << "<?xml version=\"1.0\" encoding = \"UTF-8\"?>" << endl;
		outfile << "<doctors>" << endl;
		Node* current = list->head;
		while (current != nullptr) {
			outfile << "  <doctor>" << endl;
			outfile << "    <id>" << current->data->getId() << "</id>" << endl;
			outfile << "    <experience>" << current->data->getExperience() << "</experience>" << endl;
			outfile << "    <office>" << current->data->getOffice() << "</office>" << endl;
			outfile << "    <name>" << current->data->getName() << "</name>" << endl;
			outfile << "    <post>" << current->data->getPost() << "</post>" << endl;
			outfile << "    <skill>" << current->data->getSkill() << "</skill>" << endl;
			outfile << "    <specialization>" << current->data->getSpecialization() << "</specialization>" << endl;
			outfile << "  </doctor>";
			current = current->next;
			if (current != nullptr) {
				outfile << ",";
			}
			outfile << endl;
		}
		outfile << "</doctors>" << endl;
		outfile.close();
	}
};

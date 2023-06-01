#include "DoctorBase.h"
#include "LinkedList.h"
//#include "hp.h"
//#include "hp.cpp"

DoctorBase::DoctorBase()
{
	doctorList = new LinkedList();
	try
	{
		doctorList->LoadFromFile(doctorBaseFile);
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}
}
DoctorBase::~DoctorBase()
{
	try
	{
		doctorList->SaveToFile(doctorBaseFile);
	}
	catch (exception& ex)
	{
		cout << ex.what() << endl;
	}

	doctorList->clear();
	delete doctorList;
}

void DoctorBase::addDoctor() {
	int id, office, experience;
	string name, post, skill, specialization;
	cout << "������� id �����: ";
	cin >> id;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "������� ��� �����: ";
	getline(cin, name);
	cout << "������� ��������� �����: ";
	getline(cin, post);
	cout << "������� ������������� �����: ";
	getline(cin, specialization);
	cout << "������� ������������ �����: ";
	getline(cin, skill);
	cout << "������� ���� ������: ";
	cin >> experience;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "������� ������� �����: ";
	cin >> office;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	Doctor* doctorItem = new Doctor(id, office, experience, name, post, skill, specialization);
	doctorList->add(doctorItem);
}

void DoctorBase::importDoctor() {
	string filename;
	cout << "������� ���� � �����: ";
	cin >> filename;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	try {
		doctorList->LoadFromFile(filename);
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
		cin.get();
	}
}

void DoctorBase::showDoctorList()
{
	this->printResult(doctorList);
	cin.get();
}

void DoctorBase::printResult(LinkedList* doctorList)
{
	Node* current = doctorList->head;
	while (current != nullptr) {
		cout << current->data->getId() << ". " << "��������� ����� : " << current->data->getPost() << endl << "��� �����: " << current->data->getName() << endl << 
			"�������������: " << current->data->getSpecialization() << endl << "������������: " << current->data->getSkill() << endl << "����:" << current->data->getExperience() << " ���" << endl << "�������: " << current->data->getOffice() << endl << endl;;
		current = current->next;
	}
}

void DoctorBase::findDoctorById()
{
	string id;
	cout << "������� id �����: ";
	cin >> id;
	try
	{
		LinkedList* findList = doctorList->find("id", id);
		if (findList != nullptr)
		{
			printResult(findList);
			cin.get();
			cin.get();
			delete findList;
		}
		else
		{
			cout << "������ �� �������" << endl;
			cin.get();
			cin.get();
		}
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void DoctorBase::findDoctorByName()
{
	string name;
	cout << "������� ��� �����: ";
	cin >> name;
	try
	{
		LinkedList* findList = doctorList->find("name", name);
		if (findList != nullptr)
		{
			printResult(findList);
			cin.get();
			cin.get();
			delete findList;
		}
		else
		{
			cout << "������ �� �������" << endl;
			cin.get();
			cin.get();
		}
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void DoctorBase::findDoctorByOffice()
{
	string office;
	cout << "������� ������� �����: ";
	cin >> office;
	try
	{
		LinkedList* findList = doctorList->find("office", office);
		if (findList != nullptr)
		{
			printResult(findList);
			cin.get();
			cin.get();
			delete findList;
		}
		else
		{
			cout << "������ �� �������" << endl;
			cin.get();
			cin.get();
		}
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void DoctorBase::findDoctorByPost()
{
	string post;
	cout << "������� ��������� �����: ";
	cin >> post;
	try
	{
		LinkedList* findList = doctorList->find("post", post);
		if (findList != nullptr)
		{
			printResult(findList);
			getchar();
			getchar();
			delete findList;
		}
		else
		{
			cout << "������ �� �������" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void DoctorBase::findDoctorBySpecialization()
{
	string specialization;
	cout << "������� �������� ������: ";
	cin >> specialization;
	try
	{
		LinkedList* findList = doctorList->find("specialization", specialization);
		if (findList != nullptr)
		{
			printResult(findList);
			getchar();
			getchar();
			delete findList;
		}
		else
		{
			cout << "������ �� �������" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void DoctorBase::removeDoctorById()
{
	string id;
	cout << "������� id �����: ";
	cin >> id;
	try
	{
		cout << "������� " << doctorList->remove("id", id) << " �������" << endl;
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void DoctorBase::removeDoctorByName()
{
	string name;
	cout << "������� ��� �����: ";
	getline(cin, name);
	try
	{
		cout << "������� " << doctorList->remove("name", name) << " �������" << endl;
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void DoctorBase::removeDoctorByOffice()
{
	string office;
	cout << "������� ������� �����: ";
	cin >> office;
	try
	{
		cout << "������� " << doctorList->remove("office", office) << " �������" << endl;
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void DoctorBase::removeDoctorByPost()
{
	string post;
	cout << "������� ��������� �����: ";
	cin >> post;
	try
	{
		cout << "������� " << doctorList->remove("post", post) << " �������" << endl;
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void DoctorBase::removeDoctorBySpecialization()
{
	string specialization;
	cout << "������� ������������� ����� ";
	cin >> specialization;
	try
	{
		cout << "������� " << doctorList->remove("specialization", specialization) << " �������" << endl;
	}
	catch (exception& ex)
	{
		cout << "������ ������";
	}
}

void DoctorBase::sortDoctorByIdAsc()
{
	doctorList->sort("id", true);
	this->showDoctorList();
}

void DoctorBase::sortDoctorByIdDesc()
{
	doctorList->sort("id", false);
	this->showDoctorList();
}

void DoctorBase::sortDoctorByNameAsc()
{
	doctorList->sort("name", true);
	this->showDoctorList();
}

void DoctorBase::sortDoctorByNameDesc()
{
	doctorList->sort("name", false);
	this->showDoctorList();
}

void DoctorBase::sortDoctorByOfficeAsc()
{
	doctorList->sort("office", true);
	this->showDoctorList();
}

void DoctorBase::sortDoctorByOfficeDesc()
{
	doctorList->sort("office", false);
	this->showDoctorList();
}

void DoctorBase::sortDoctorByPostAsc()
{
	doctorList->sort("post", true);
	this->showDoctorList();
}

void DoctorBase::sortDoctorByPostDesc()
{
	doctorList->sort("post", false);
	this->showDoctorList();
}

void DoctorBase::sortDoctorBySpecializationAsc()
{
	doctorList->sort("specialization", true);
	this->showDoctorList();
}

void DoctorBase::sortDoctorBySpecializationDesc()
{
	doctorList->sort("specialization", false);
	this->showDoctorList();
}

void DoctorBase::sortDoctorBySkillAsc()
{
	doctorList->sort("skill", true);
	this->showDoctorList();
}

void DoctorBase::sortDoctorBySkillDesc()
{
	doctorList->sort("skill", false);
	this->showDoctorList();
}

void DoctorBase::sortDoctorByExperienceAsc()
{
	doctorList->sort("experience", true);
	this->showDoctorList();
}

void DoctorBase::sortDoctorByExperienceDesc()
{
	doctorList->sort("experience", false);
	this->showDoctorList();
}

void DoctorBase::exportDoctorListToJson()
{
	SaveFormat* format = new JsonFormat();
	format->save(doctorList, "doctors.json");
	delete format;
}
void DoctorBase::exportDoctorListToXML()
{
	SaveFormat* format = new XmlFormat();
	format->save(doctorList, "doctors.xml");
	delete format;
}
void DoctorBase::exportDoctorListToCSV()
{
	doctorList->SaveToFile("doctors.csv");
}

void DoctorBase::run() {
	SubMenu mainMenu("������� ��������", false);
	SubMenu adminMenu("����������������� ��������", true);
	SubMenu findMenu("�����", false);
	SubMenu removeMenu("��������", false);
	SubMenu userMenu("�������� ��������", false);
	SubMenu sortMenu("����������", false);
	SubMenu sortByIdMenu("���������� �� Id", false);
	SubMenu sortByNameMenu("���������� �� ���", false);
	SubMenu sortByOfficeMenu("���������� �� ��������", false);
	SubMenu sortByPostMenu("���������� �� ���������", false);
	SubMenu sortBySpecializationMenu("���������� �� �������������", false);
	SubMenu sortBySkillMenu("���������� �� ������������", false);
	SubMenu sortByExperienceMenu("���������� �� �����", false);
	SubMenu exportMenu("�������������� ������", false);

	MenuItem sortDoctorByIdAsc("�� �����������", false, [this]() {this->sortDoctorByIdAsc(); });
	MenuItem sortDoctorByIdDesc("�� ��������", false, [this]() {this->sortDoctorByIdDesc(); });
	MenuItem sortDoctorByNameAsc("�� �����������", false, [this]() {this->sortDoctorByNameAsc(); });
	MenuItem sortDoctorByNameDesc("�� ��������", false, [this]() {this->sortDoctorByNameDesc(); });
	MenuItem sortDoctorByOfficeAsc("�� �����������", false, [this]() {this->sortDoctorByOfficeAsc(); });
	MenuItem sortDoctorByOfficeDesc("�� ��������", false, [this]() {this->sortDoctorByOfficeDesc(); });
	MenuItem sortDoctorByPostAsc("�� �����������", false, [this]() {this->sortDoctorByPostAsc(); });
	MenuItem sortDoctorByPostDesc("�� ��������", false, [this]() {this->sortDoctorByPostDesc(); });
	MenuItem sortDoctorBySpecializationAsc("�� �����������", false, [this]() {this->sortDoctorBySpecializationAsc(); });
	MenuItem sortDoctorBySpecializationDesc("�� ��������", false, [this]() {this->sortDoctorBySpecializationDesc(); });
	MenuItem sortDoctorBySkillAsc("�� �����������", false, [this]() {this->sortDoctorBySkillAsc(); });
	MenuItem sortDoctorBySkillDesc("�� ��������", false, [this]() {this->sortDoctorBySkillDesc(); });
	MenuItem sortDoctorExperienceAsc("�� �����������", false, [this]() {this->sortDoctorByExperienceAsc(); });
	MenuItem sortDoctorExperienceDesc("�� ��������", false, [this]() {this->sortDoctorByExperienceDesc(); });

	MenuItem addDoctorItem("�������� ������ �����", false, [this]() {this->addDoctor(); });
	MenuItem importFromCSV("������ �� CSV", false, [this]() {this->importDoctor(); });
	MenuItem showDoctorList("���������� ������ ������", false, [this]() {this->showDoctorList(); });

	MenuItem findDoctorById("����� ����� �� id", false, [this]() {this->findDoctorById(); });
	MenuItem findDoctorByName("����� ����� �� ���", false, [this]() {this->findDoctorByName(); });
	MenuItem findDoctorByOffice("����� ����� �� ��������", false, [this]() {this->findDoctorByOffice(); });
	MenuItem findDoctorByPost("����� ����� �� ���������", false, [this]() {this->findDoctorByPost(); });
	MenuItem findDoctorBySpecialization("����� ����� �� �������������", false, [this]() {this->findDoctorBySpecialization(); });
	MenuItem removeDoctorById("������� ����� �� id", false, [this]() {this->removeDoctorById(); });
	MenuItem removeDoctorByName("������� ����� �� ���", false, [this]() {this->removeDoctorByName(); });
	MenuItem removeDoctorByOffice("������� ����� �� ��������", false, [this]() {this->removeDoctorByOffice(); });
	MenuItem removeDoctorByPost("������� ����� �� ���������", false, [this]() {this->removeDoctorByPost(); });
	MenuItem removeDoctorBySpecialization("������� ����� �� �������������", false, [this]() {this->removeDoctorBySpecialization(); });

	MenuItem exportDoctorListToCSV("�������������� � CSV", false, [this]() {this->exportDoctorListToCSV(); });
	MenuItem exportDoctorListToJson("�������������� � Json", false, [this]() {this->exportDoctorListToJson(); });
	MenuItem exportDoctorListToXML("�������������� � Xml", false, [this]() {this->exportDoctorListToXML(); });

	exportMenu.add_item(&exportDoctorListToCSV);
	exportMenu.add_item(&exportDoctorListToJson);
	exportMenu.add_item(&exportDoctorListToXML);

	sortByIdMenu.add_item(&sortDoctorByIdAsc);
	sortByIdMenu.add_item(&sortDoctorByIdDesc);
	sortByNameMenu.add_item(&sortDoctorByNameAsc);
	sortByNameMenu.add_item(&sortDoctorByNameDesc);
	sortByOfficeMenu.add_item(&sortDoctorByOfficeAsc);
	sortByOfficeMenu.add_item(&sortDoctorByOfficeDesc);
	sortByPostMenu.add_item(&sortDoctorByPostAsc);
	sortByPostMenu.add_item(&sortDoctorByPostDesc);
	sortBySpecializationMenu.add_item(&sortDoctorBySpecializationAsc);
	sortBySpecializationMenu.add_item(&sortDoctorBySpecializationDesc);
	sortBySkillMenu.add_item(&sortDoctorBySkillAsc);
	sortBySkillMenu.add_item(&sortDoctorBySkillDesc);
	sortByExperienceMenu.add_item(&sortDoctorExperienceAsc);
	sortByExperienceMenu.add_item(&sortDoctorExperienceDesc);

	sortMenu.add_item(&sortByIdMenu);
	sortMenu.add_item(&sortByNameMenu);
	sortMenu.add_item(&sortByOfficeMenu);
	sortMenu.add_item(&sortByPostMenu);
	sortMenu.add_item(&sortBySpecializationMenu);
	sortMenu.add_item(&sortBySkillMenu);
	sortMenu.add_item(&sortByExperienceMenu);
	findMenu.add_item(&findDoctorById);
	findMenu.add_item(&findDoctorByName);
	findMenu.add_item(&findDoctorByOffice);
	findMenu.add_item(&findDoctorByPost);
	findMenu.add_item(&findDoctorBySpecialization);
	removeMenu.add_item(&removeDoctorById);
	removeMenu.add_item(&removeDoctorByName);
	removeMenu.add_item(&removeDoctorByOffice);
	removeMenu.add_item(&removeDoctorByPost);
	removeMenu.add_item(&removeDoctorBySpecialization);

	adminMenu.add_item(&addDoctorItem);
	adminMenu.add_item(&importFromCSV);
	adminMenu.add_item(&findMenu);
	adminMenu.add_item(&sortMenu);
	adminMenu.add_item(&exportMenu);
	adminMenu.add_item(&removeMenu);
	adminMenu.add_item(&showDoctorList);

	userMenu.add_item(&findMenu);
	userMenu.add_item(&sortMenu);
	userMenu.add_item(&exportMenu);
	userMenu.add_item(&showDoctorList);

	mainMenu.add_item(&adminMenu);
	mainMenu.add_item(&userMenu);

	mainMenu.run();
}
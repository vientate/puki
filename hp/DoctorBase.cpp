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
	cout << "Введите id врача: ";
	cin >> id;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Введите ФИО врача: ";
	getline(cin, name);
	cout << "Введите должность врача: ";
	getline(cin, post);
	cout << "Введите специализацию врача: ";
	getline(cin, specialization);
	cout << "Введите квалификацию врача: ";
	getline(cin, skill);
	cout << "Введите стаж работы: ";
	cin >> experience;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "Введите кабинет врача: ";
	cin >> office;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	Doctor* doctorItem = new Doctor(id, office, experience, name, post, skill, specialization);
	doctorList->add(doctorItem);
}

void DoctorBase::importDoctor() {
	string filename;
	cout << "Введите путь к файлу: ";
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
		cout << current->data->getId() << ". " << "Должность врача : " << current->data->getPost() << endl << "ФИО врача: " << current->data->getName() << endl << 
			"Специальность: " << current->data->getSpecialization() << endl << "Квалификация: " << current->data->getSkill() << endl << "Стаж:" << current->data->getExperience() << " лет" << endl << "Кабинет: " << current->data->getOffice() << endl << endl;;
		current = current->next;
	}
}

void DoctorBase::findDoctorById()
{
	string id;
	cout << "Введите id врача: ";
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
			cout << "Ничего не найдено" << endl;
			cin.get();
			cin.get();
		}
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void DoctorBase::findDoctorByName()
{
	string name;
	cout << "Введите ФИО врача: ";
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
			cout << "Ничего не найдено" << endl;
			cin.get();
			cin.get();
		}
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void DoctorBase::findDoctorByOffice()
{
	string office;
	cout << "Введите кабинет врача: ";
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
			cout << "Ничего не найдено" << endl;
			cin.get();
			cin.get();
		}
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void DoctorBase::findDoctorByPost()
{
	string post;
	cout << "Введите должность врача: ";
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
			cout << "Ничего не найдено" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void DoctorBase::findDoctorBySpecialization()
{
	string specialization;
	cout << "Введите название спорта: ";
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
			cout << "Ничего не найдено" << endl;
			getchar();
			getchar();
		}
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void DoctorBase::removeDoctorById()
{
	string id;
	cout << "Введите id врача: ";
	cin >> id;
	try
	{
		cout << "Удалено " << doctorList->remove("id", id) << " записей" << endl;
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void DoctorBase::removeDoctorByName()
{
	string name;
	cout << "Введите ФИО врача: ";
	getline(cin, name);
	try
	{
		cout << "Удалено " << doctorList->remove("name", name) << " записей" << endl;
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void DoctorBase::removeDoctorByOffice()
{
	string office;
	cout << "Введите кабинет врача: ";
	cin >> office;
	try
	{
		cout << "Удалено " << doctorList->remove("office", office) << " записей" << endl;
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void DoctorBase::removeDoctorByPost()
{
	string post;
	cout << "Введите должность врача: ";
	cin >> post;
	try
	{
		cout << "Удалено " << doctorList->remove("post", post) << " записей" << endl;
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
	}
}

void DoctorBase::removeDoctorBySpecialization()
{
	string specialization;
	cout << "Введите специализацию врача ";
	cin >> specialization;
	try
	{
		cout << "Удалено " << doctorList->remove("specialization", specialization) << " записей" << endl;
	}
	catch (exception& ex)
	{
		cout << "Ошибка поиска";
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
	SubMenu mainMenu("Каталог больницы", false);
	SubMenu adminMenu("Администрирование каталога", true);
	SubMenu findMenu("Поиск", false);
	SubMenu removeMenu("Удаление", false);
	SubMenu userMenu("Просмотр каталога", false);
	SubMenu sortMenu("Сортировка", false);
	SubMenu sortByIdMenu("Сортировка по Id", false);
	SubMenu sortByNameMenu("Сортировка по ФИО", false);
	SubMenu sortByOfficeMenu("Сортировка по кабинету", false);
	SubMenu sortByPostMenu("Сортировка по должности", false);
	SubMenu sortBySpecializationMenu("Сортировка по специальности", false);
	SubMenu sortBySkillMenu("Сортировка по квалификации", false);
	SubMenu sortByExperienceMenu("Сортировка по стажу", false);
	SubMenu exportMenu("Экспортировать список", false);

	MenuItem sortDoctorByIdAsc("По возрастанию", false, [this]() {this->sortDoctorByIdAsc(); });
	MenuItem sortDoctorByIdDesc("По убыванию", false, [this]() {this->sortDoctorByIdDesc(); });
	MenuItem sortDoctorByNameAsc("По возрастанию", false, [this]() {this->sortDoctorByNameAsc(); });
	MenuItem sortDoctorByNameDesc("По убыванию", false, [this]() {this->sortDoctorByNameDesc(); });
	MenuItem sortDoctorByOfficeAsc("По возрастанию", false, [this]() {this->sortDoctorByOfficeAsc(); });
	MenuItem sortDoctorByOfficeDesc("По убыванию", false, [this]() {this->sortDoctorByOfficeDesc(); });
	MenuItem sortDoctorByPostAsc("По возрастанию", false, [this]() {this->sortDoctorByPostAsc(); });
	MenuItem sortDoctorByPostDesc("По убыванию", false, [this]() {this->sortDoctorByPostDesc(); });
	MenuItem sortDoctorBySpecializationAsc("По возрастанию", false, [this]() {this->sortDoctorBySpecializationAsc(); });
	MenuItem sortDoctorBySpecializationDesc("По убыванию", false, [this]() {this->sortDoctorBySpecializationDesc(); });
	MenuItem sortDoctorBySkillAsc("По возрастанию", false, [this]() {this->sortDoctorBySkillAsc(); });
	MenuItem sortDoctorBySkillDesc("По убыванию", false, [this]() {this->sortDoctorBySkillDesc(); });
	MenuItem sortDoctorExperienceAsc("По возрастанию", false, [this]() {this->sortDoctorByExperienceAsc(); });
	MenuItem sortDoctorExperienceDesc("По убыванию", false, [this]() {this->sortDoctorByExperienceDesc(); });

	MenuItem addDoctorItem("Добавить нового врача", false, [this]() {this->addDoctor(); });
	MenuItem importFromCSV("Импорт из CSV", false, [this]() {this->importDoctor(); });
	MenuItem showDoctorList("Посмотреть список врачей", false, [this]() {this->showDoctorList(); });

	MenuItem findDoctorById("Найти врача по id", false, [this]() {this->findDoctorById(); });
	MenuItem findDoctorByName("Найти врача по ФИО", false, [this]() {this->findDoctorByName(); });
	MenuItem findDoctorByOffice("Найти врача по кабинету", false, [this]() {this->findDoctorByOffice(); });
	MenuItem findDoctorByPost("Найти врача по должности", false, [this]() {this->findDoctorByPost(); });
	MenuItem findDoctorBySpecialization("Найти врача по специализации", false, [this]() {this->findDoctorBySpecialization(); });
	MenuItem removeDoctorById("Удалить врача по id", false, [this]() {this->removeDoctorById(); });
	MenuItem removeDoctorByName("Удалить врача по ФИО", false, [this]() {this->removeDoctorByName(); });
	MenuItem removeDoctorByOffice("Удалить врача по кабинету", false, [this]() {this->removeDoctorByOffice(); });
	MenuItem removeDoctorByPost("Удалить врача по должности", false, [this]() {this->removeDoctorByPost(); });
	MenuItem removeDoctorBySpecialization("Удалить врача по специализации", false, [this]() {this->removeDoctorBySpecialization(); });

	MenuItem exportDoctorListToCSV("Экспортировать в CSV", false, [this]() {this->exportDoctorListToCSV(); });
	MenuItem exportDoctorListToJson("Экспортировать в Json", false, [this]() {this->exportDoctorListToJson(); });
	MenuItem exportDoctorListToXML("Экспортировать в Xml", false, [this]() {this->exportDoctorListToXML(); });

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
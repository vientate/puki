#pragma once
#include "SubMenu.h"
#include "MenuItem.h"
#include "LinkedList.h"
//#include "hp.h"
#include "SaveFormat.h"
#include "JsonFormat.h"
#include "XmlFormat.h"
#include <iostream>
#include <sstream>
#include <locale>
#include <regex>
#include <limits>
#include <codecvt>

class DoctorBase
{
public:
	DoctorBase();
	void run();
	~DoctorBase();
private:
	LinkedList* doctorList;
	void addDoctor();

	void findDoctorById();
	void findDoctorByName();
	void findDoctorByOffice();
	void findDoctorByPost();
	void findDoctorBySpecialization();

	void removeDoctorById();
	void removeDoctorByName();
	void removeDoctorByOffice();
	void removeDoctorByPost();
	void removeDoctorBySpecialization();

	void sortDoctorByIdAsc();
	void sortDoctorByIdDesc();
	void sortDoctorByNameAsc();
	void sortDoctorByNameDesc();
	void sortDoctorByOfficeAsc();
	void sortDoctorByOfficeDesc();
	void sortDoctorByPostAsc();
	void sortDoctorByPostDesc();
	void sortDoctorBySpecializationAsc();
	void sortDoctorBySpecializationDesc();
	void sortDoctorBySkillAsc();
	void sortDoctorBySkillDesc();
	void sortDoctorByExperienceAsc();
	void sortDoctorByExperienceDesc();

	void exportDoctorListToJson();
	void exportDoctorListToXML();
	void exportDoctorListToCSV();

	void importDoctor();
	void printResult(LinkedList* doctorList);
	void showDoctorList();
	const string doctorBaseFile = "doctors.csv";
};
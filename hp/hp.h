#pragma once
#include <string>

using namespace std;

class Doctor
{
public:
	Doctor(int Id, int Office, string Experience, string Name, string Post, string Skill, string Specialization) : id(Id), office(Office), experience(Experience), name(Name), post(Post), skill(Skill), specialization(Specialization) {};
	int getId() const { return id; }
	int getOffice() const { return office; }
	string getExperience() const { return experience; }
	string getName() const { return name; }
	string getPost() const { return post; }
	string getSkill() const { return skill; }
	string getSpecialization() const { return specialization; };
	bool isGreaterThen(Doctor* b, string field);
	bool isLessThen(Doctor* b, string field);

private:
	int id;
	int office;
	string experience;
	string name;
	string post;
	string skill; 
	string specialization;
};

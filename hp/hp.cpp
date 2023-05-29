#pragma once
#include "hp.h"


bool Doctor::isGreaterThen(Doctor* b, string field)
{
	if (field == "id")
	{
		return this->getId() > b->getId();
	}
	else if (field == "name")
	{
		return this->getName() > b->getName();
	}
	else if (field == "office")
	{
		return this->getOffice() > b->getOffice();
	}
	else if (field == "post")
	{
		return this->getPost() > b->getPost();
	}
	else if (field == "specialization")
	{
		return this->getSpecialization() > b->getSpecialization();
	}
	else if (field == "skill")
	{
		return this->getSkill() > b->getSkill();
	}
	else if (field == "experience")
	{
		return this->getExperience() > b->getExperience();
	}
	else
	{
		return false;
	}
}

bool Doctor::isLessThen(Doctor* b, string field)
{
	if (field == "id")
	{
		return this->getId() < b->getId();
	}
	else if (field == "name")
	{
		return this->getName() < b->getName();
	}
	else if (field == "office")
	{
		return this->getOffice() < b->getOffice();
	}
	else if (field == "post")
	{
		return this->getPost() < b->getPost();
	}
	else if (field == "specialization")
	{
		return this->getSpecialization() < b->getSpecialization();
	}
	else if (field == "skill")
	{
		return this->getSkill() < b->getSkill();
	}
	else if (field == "experience")
	{
		return this->getExperience() < b->getExperience();
	}
	else
	{
		return false;
	}
}
/*
	This file is a test used to see how well Hemorrhage translate C++ into
	Atrophy
*/

#include <string>

class Person {
public:
	enum EyeColor {
		Brown,
		Hazle,
		Blue,
		Grey
	};
	enum HairColor {
		Brown,
		Black,
		Blond,
		Red
	};
private:
	std::string first_name;
	std::string last_name;
	int age;
	EyeColor eye_color;
	HairColor hair_color;

public:
	Person(void);
	Person(std::string first, std::string last, int age, EyeColor ecolor = Brown, HairColor hcolor = Brown);
	~Person(void);

	std::string GetName(void);
	std::string GetFistName(void);
	std::string GetLastName(void);

	int GetAge(void);

	EyeColor GetEyeColor(void);
	HairColor GetHairColor(void);
};

Person::Person(void) {
	/* Nothing to do */
}

Person::Person(std::string first, std::string last, int age, EyeColor ecolor, HairColor hcolor)
	: first_name(first), last_name(last), age(age), eye_color(ecolor), hair_color(hcolor) {
}

std::string Person::GetName(void) {
	return (this->first_name + " " + this->last_name);
}
std::string Person::GetFistName(void) {
	return this->first_name;
}
std::string Person::GetLastName(void) {
	return this->last_name;
}

int Person::GetAge(void) {
	return this->age;
}

EyeColor Person::GetEyeColor(void) {
	return this->eye_color;
}
HairColor Person::GetHairColor(void) {
	return this->hair_color;
}

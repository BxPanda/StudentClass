#include<iostream>
#include<string>
#pragma once

using namespace std;

class Student
{
protected:
	string Surname;
	string Name;
	string Faculty;
	unsigned int Group;
	double MiddleMark;
public:
	Student():Surname("-"),Name("-"),Faculty("-"),Group(0),MiddleMark(0){}
	Student(string s , string n , string f , unsigned int g , double m) :Surname(s), Name(n), Faculty(f), Group(g), MiddleMark(m) {}
	Student(const Student&s) :Surname(s.Surname), Name(s.Name), Faculty(s.Faculty), Group(s.Group), MiddleMark(s.MiddleMark) {}

	string GetSurname()
	{
		return Surname;
	}
	string GetName()
	{
		return Name;
	}
	string GetFaculty()
	{
		return Faculty;
	}
	unsigned int GetGroup()
	{
		return Group;
	}
	double GetMiddleMark()
	{
		return MiddleMark;
	}

	friend istream& operator>>(istream& is, Student& s)
	{
		is >> s.Surname;
		is >> s.Name;
		is >> s.Faculty;
		is >> s.Group;
		is >> s.MiddleMark;
		return is;
	}
	friend ostream& operator<<(ostream& os, Student& s)
	{
		os << s.Surname << " " << s.Name << " " << s.Faculty << " " << s.Group << " " << s.MiddleMark << endl;
		return os;
	}
	void Print()
	{
		cout << "Surname : " << Surname << endl;
		cout << "Name : " << Name << endl;
		cout << "Faculty,Group : " << Faculty << "-" << Group << endl;
		cout << "Middle mark : " << MiddleMark << endl;
		cout << "-----------------------------------------------------------------------" << endl;
	}
};


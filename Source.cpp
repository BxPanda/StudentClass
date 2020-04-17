//Completed by Khodonovich Semen 
#include<iostream>
#include<iterator>
#include<vector>
#include<fstream>
#include"Student.h"

using namespace std;

void VectorPrint(vector<Student>& v)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i].Print();
	}
}

void OnBeginning(vector<Student>&v,string faculty,unsigned int group)
{
	vector<Student>temp1;
	vector<Student>temp2;

	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i].GetFaculty() == faculty && v[i].GetGroup() == group)
		{
			temp1.push_back(v[i]);
		}
		else
		{
			temp2.push_back(v[i]);
		}
	}
	v.clear();
	copy(temp1.begin(), temp1.end(), inserter(v, v.begin()));
	copy(temp2.begin(), temp2.end(), inserter(v, v.end()));

	cout << endl << "Students of "<<faculty<<"-"<<group<<" are standing at beginning : " << endl << endl;
	VectorPrint(v);
}

void DeleteLess2(vector<Student>& v)
{
	vector<Student> temp;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i].GetMiddleMark() > 2)
		{
			temp.push_back(v[i]);
		}
	}
	v.clear();
	copy(temp.begin(), temp.end(), inserter(v, v.begin()));
	cout<< endl << "Students which have <2 middle mark deleted : " << endl << endl;
	VectorPrint(v);
}

void ABC(vector<Student>& v, string faculty, unsigned int group)
{
	vector<Student>temp;
	for (size_t i = 0; i < v.size(); i++)
	{
		if (v[i].GetFaculty() == faculty && v[i].GetGroup() == group)
		{
			temp.push_back(v[i]);
		}
	}
	v.clear();
	copy(temp.begin(), temp.end(), inserter(v, v.begin()));

	for (size_t j = 0; j < v.size()-1; j++)
	{
		for (size_t i = 0; i < v.size() - 1; i++)
		{
			if (v[i].GetSurname() > v[i + 1].GetSurname())
			{
				swap(v[i], v[i + 1]);
			}
		}
	}
	cout << endl << "Students sorted by ABC : " << endl << endl;
	VectorPrint(v);
}

int main()
{
	vector<Student>Students;
	ifstream ifs("StudentList.txt");
	copy(istream_iterator<Student>(ifs), istream_iterator<Student>(),inserter(Students, Students.end())); // Зчитуємо з файлу 
	ifs.close();
	VectorPrint(Students); // Виводимо дані на консоль які получили з текстового документу StudentList.txt

	OnBeginning(Students, "PMI", 13);
	DeleteLess2(Students);                    //Виконую операції задані в завданні 
	ABC(Students, "PMI", 13);

	return 0;
}
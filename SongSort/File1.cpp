 //Song Sorted v1.0
#pragma hdrstop
#pragma argsused

#ifdef _WIN32
#include <tchar.h>
#else
  typedef char _TCHAR;
  #define _tmain main
#endif

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <Windows.h>
using namespace std;
#include <filesystem>
namespace fs = std::filesystem;
#include <direct.h>

int _tmain(int argc, _TCHAR* argv[]) 
{
system("chcp 1251"); //���������
system("cls");       //������� ���� �������

string path;  //���� � �����
vector <string> mas; //������ ������ ������
string MainPath;  //���� � ������
cout << "Directory main path (E:/test): "; cin >> MainPath;
MainPath += '/';
cout << "Directory path search (E:/test/1): "; cin >> path;
int sizePath = path.length();  //����� ���� � �����, ��� ��������� ��� �� ����
int col; cout << "Directory col: "; cin >> col;  //���������� ���������� ����� � �����

for (int k = 0; k<10; k++) //������� ������
	{
	int i = 0;
	for (const auto & entry : fs::directory_iterator(path)) //��������� ������ ������
		{
		string str = entry.path().string();
		str.erase(0,sizePath+1);
		mas.push_back(str);
		}

	vector <string> song;  //������ ����� �����

	for (unsigned j=0;j<mas.size();j++) //��������� � �����������
		{
		string name1 = mas[j];
		song.push_back(name1);
		int pos1 = name1.find(" - ");
		string name2;
		for (unsigned i=j+1;i<mas.size();i++) //���������
			{
			name2 = mas[i];
			if (name1.substr(0,pos1+1) == name2.substr(0,pos1+1))
				{
				song.push_back(name2);
				}
			}

		if (song.size() >= col) //�������� ���������� � ����������� ����������
			{
			string Dir = MainPath + name1.substr(0,pos1);
			char dir [256];
			strcpy(dir, Dir.c_str());
			mkdir(dir);   //�������� �����
			for (unsigned i=0;i<song.size();i++)  //�����������
				{
				string DirOut = path + '/' + song[i];
				LPCTSTR dirOut = DirOut.c_str();
				string DirIn = MainPath + name1.substr(0,pos1) + '/' + song[i];
				LPCTSTR dirIn = DirIn.c_str();
				MoveFile( dirOut , dirIn );
				}
			song.clear();
			break;  //����� �� ������ � ����� �������
			}
		else song.clear();
		}
	mas.clear();
	}
system ("pause");
return 0;
}

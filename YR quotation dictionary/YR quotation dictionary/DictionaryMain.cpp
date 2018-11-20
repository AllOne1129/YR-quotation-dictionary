#include <iostream>
#include <string>
#include <windows.h>
#include "node.h"
#include "system.h"
#include "BinarySearch.h"
using namespace std;

int main()
{
	System sys;
	NODE *root;
	Initialize(&root);

	while (true)
	{
		cout << "--------------------" << endl;
		cout << "1. �ۼ��ϱ�" << endl;
		cout << "2. �����ϱ�" << endl;
		cout << "3. ��� ã��(ID)" << endl;
		cout << "4. ���� ���" << endl;
		cout << "5. ��ü ���" << endl;
		cout << "6. �˿��� ����" << endl;
		cout << "7. ������ ���" << endl;
		cout << "Q. ����" << endl;
		cout << "--------------------" << endl;
		cout << "���ϴ� ������ ��ȣ�� �Է��ϼ��� : ";

		LIMIT currentLimit = LIMIT::ALL;
		char input;
		cin >> input;
		
		switch (input)
		{
		case '1':
		{
			if (!sys.ExistPassword())
			{
				cout << "��й�ȣ�� �������ּ��� : ";
				string setPW;
				cin >> setPW;
				if (!sys.SetPassword(setPW))
				{
					cout << "������ �߻��߽��ϴ�." << endl;
					sys.SetPassword("");
					break;
				}
				else
					cout << "�ùٸ��� �����Ǿ����ϴ�." << endl;
			}

			string inputPW;
			cout << "��й�ȣ�� �Է����ּ��� : ";
			cin >> inputPW;
			if (!sys.ComparePassword(inputPW))
			{
				cout << "��й�ȣ�� ���� �ʽ��ϴ�." << endl;
				break;
			}

			Data newData;
			short wantLimit;
			cout << "����� ID�� �Է����ּ��� : ";
			cin >> newData.id;
			cout << "����� ������ �Է����ּ��� : ";
			cin.get();
			getline(cin, newData.quotation);
			cout << "���� ������ �������ּ���(1: ��ü 2: 15�� 3: 19��) : ";
			cin >> wantLimit;
			newData.SetLimit(wantLimit);

			try
			{
				Insert(&root, newData);
			}
			catch (const char *exp)
			{
				cout << exp << endl;
				break;
			}

			cout << "����� �ٸ��� ��ϵǾ����ϴ�.";
			break;
		}
		case '2':
		{
			break;
		}
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
		{
			int input;
			cin >> input;

			break;
		}
		case 'Q':
		case 'q':
		{
			cout << "�̿��� �ּż� �����մϴ�." << endl;
			return 0;
		}
		default:
			break;
		}
		Sleep(1000);
		system("cls");
	}
	return 0;
}
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "node.h"
#include "system.h"
#include "BinarySearch.h"
using namespace std;

int main()
{
	System sys;
	NODE *root;
	Initialize(&root);

	LIMIT currentLimit = LIMIT::ALL;
	int quotationNum = 0;
	while (true)
	{
		cout << "    �븶�����Ƿ�    " << endl;
		cout << "--------------------" << endl;
		cout << "1. �ۼ��ϱ�" << endl;
		cout << "2. �����ϱ�" << endl;
		cout << "3. ��� ã��(ID)" << endl;
		cout << "4. ��ü ���" << endl;
		cout << "5. �˿��� ����" << endl;
		cout << "6. ������ ���" << endl;
		cout << "Q. ����" << endl;
		cout << "--------------------" << endl;
		cout << "���ϴ� ������ ��ȣ�� �Է��ϼ��� : ";

		char input;
		cin >> input;
		
		switch (input)
		{
		case '1':
		{
			if (!sys.InputPassword())
			{
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
			quotationNum++;
			break;
		}
		case '2':
		{
			if (!sys.InputPassword())
				break;
			cout << "������ ����� ID�� �Է����ּ��� : ";
			int delID;
			cin >> delID;

			NODE *deleteNode;
			try
			{
				deleteNode = Search(root, delID);
			}
			catch (const char *exp)
			{
				cout << exp;
				break;
			}

			RemoveNode(deleteNode, &root);
			cout << "���������� �����Ǿ����ϴ�.";
			quotationNum--;
			break;
		}
		case '3':
		{
			int wantID;
			cout << "���ϴ� ����� ID�� �Է����ּ��� : ";
			cin >> wantID;
			NODE *wantNode = Search(root, wantID);
			if (currentLimit < wantNode->data.limit)
			{
				cout << "���̸� �� �԰� ������~~^^";
			}
			else
			{
				cout << wantNode->data.quotation;
			}
			break;
		}
		case '4':
		{
			if (quotationNum > 0)
				InorderTraverse(root, currentLimit);
			cout << "����Ϸ��� �ƹ� Ű�� ��������..";
			while (!_kbhit());
			break;
		}
		case '5':
		{
			system("cls");
			cout << "-----�˿��� ����-----" << endl;
			cout << "1. ��ü�̿밡" << endl;
			cout << "2. 15�� �̿밡" << endl;
			cout << "3. 19�� �̿밡" << endl;
			cout << "--------------------" << endl;
			cout << "������ �˿����� �Է����ּ��� : ";
			int input;
			cin >> input;

			currentLimit = static_cast<LIMIT>(input);
			break;
		}
		case '6':
		{
			cout << "������, ���̵�� ��ȹ : ������, �迵��" << endl;
			cout << "���� : �迵��";
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
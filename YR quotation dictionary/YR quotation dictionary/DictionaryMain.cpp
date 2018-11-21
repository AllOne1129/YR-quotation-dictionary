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
		cout << "    대마영래실록    " << endl;
		cout << "--------------------" << endl;
		cout << "1. 작성하기" << endl;
		cout << "2. 삭제하기" << endl;
		cout << "3. 어록 찾기(ID)" << endl;
		cout << "4. 전체 어록" << endl;
		cout << "5. 검열도 설정" << endl;
		cout << "6. 개발자 명단" << endl;
		cout << "Q. 종료" << endl;
		cout << "--------------------" << endl;
		cout << "원하는 동작의 번호를 입력하세요 : ";

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
			cout << "어록의 ID를 입력해주세요 : ";
			cin >> newData.id;
			cout << "어록의 내용을 입력해주세요 : ";
			cin.get();
			getline(cin, newData.quotation);
			cout << "제한 정도를 선택해주세요(1: 전체 2: 15금 3: 19금) : ";
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

			cout << "어록이 바르게 등록되었습니다.";
			quotationNum++;
			break;
		}
		case '2':
		{
			if (!sys.InputPassword())
				break;
			cout << "삭제할 어록의 ID를 입력해주세요 : ";
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
			cout << "정상적으로 삭제되었습니다.";
			quotationNum--;
			break;
		}
		case '3':
		{
			int wantID;
			cout << "원하는 어록의 ID를 입력해주세요 : ";
			cin >> wantID;
			NODE *wantNode = Search(root, wantID);
			if (currentLimit < wantNode->data.limit)
			{
				cout << "나이를 더 먹고 오세요~~^^";
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
			cout << "계속하려면 아무 키나 누르세요..";
			while (!_kbhit());
			break;
		}
		case '5':
		{
			system("cls");
			cout << "-----검열도 설정-----" << endl;
			cout << "1. 전체이용가" << endl;
			cout << "2. 15세 이용가" << endl;
			cout << "3. 19세 이용가" << endl;
			cout << "--------------------" << endl;
			cout << "설정할 검열도를 입력해주세요 : ";
			int input;
			cin >> input;

			currentLimit = static_cast<LIMIT>(input);
			break;
		}
		case '6':
		{
			cout << "개발자, 아이디어 기획 : 김태현, 김영래" << endl;
			cout << "응원 : 김영래";
			break;
		}
		case 'Q':
		case 'q':
		{
			cout << "이용해 주셔서 감사합니다." << endl;
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
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
		cout << "1. 작성하기" << endl;
		cout << "2. 삭제하기" << endl;
		cout << "3. 어록 찾기(ID)" << endl;
		cout << "4. 랜덤 어록" << endl;
		cout << "5. 전체 어록" << endl;
		cout << "6. 검열도 설정" << endl;
		cout << "7. 개발자 명단" << endl;
		cout << "Q. 종료" << endl;
		cout << "--------------------" << endl;
		cout << "원하는 동작의 번호를 입력하세요 : ";

		LIMIT currentLimit = LIMIT::ALL;
		char input;
		cin >> input;
		
		switch (input)
		{
		case '1':
		{
			if (!sys.ExistPassword())
			{
				cout << "비밀번호를 설정해주세요 : ";
				string setPW;
				cin >> setPW;
				if (!sys.SetPassword(setPW))
				{
					cout << "오류가 발생했습니다." << endl;
					sys.SetPassword("");
					break;
				}
				else
					cout << "올바르게 설정되었습니다." << endl;
			}

			string inputPW;
			cout << "비밀번호를 입력해주세요 : ";
			cin >> inputPW;
			if (!sys.ComparePassword(inputPW))
			{
				cout << "비밀번호가 맞지 않습니다." << endl;
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
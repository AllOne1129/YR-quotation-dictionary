#ifndef _SYSTEM_H_
#define _SYSTEM_H_

class System
{
private:
	string password = "";

public:
	bool ExistPassword()
	{
		if (password != "")
			return true;
		return false;
	}

	bool SetPassword(string password)
	{
		this->password = password;
		if (password == this->password)
			return true;
		return false;
	}

	bool ComparePassword(string password)
	{
		return this->password == password;
	}

	bool InputPassword()
	{
		if (!ExistPassword())
		{
			cout << "비밀번호를 설정해주세요 : ";
			string setPW;
			cin >> setPW;
			if (!SetPassword(setPW))
			{
				cout << "오류가 발생했습니다." << endl;
				SetPassword("");
				return false;
			}
			else
				cout << "올바르게 설정되었습니다." << endl;
		}

		string inputPW;
		cout << "비밀번호를 입력해주세요 : ";
		cin >> inputPW;
		if (!ComparePassword(inputPW))
		{
			cout << "비밀번호가 맞지 않습니다." << endl;
			return false;
		}

		return true;
	}
};
#endif
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
			cout << "��й�ȣ�� �������ּ��� : ";
			string setPW;
			cin >> setPW;
			if (!SetPassword(setPW))
			{
				cout << "������ �߻��߽��ϴ�." << endl;
				SetPassword("");
				return false;
			}
			else
				cout << "�ùٸ��� �����Ǿ����ϴ�." << endl;
		}

		string inputPW;
		cout << "��й�ȣ�� �Է����ּ��� : ";
		cin >> inputPW;
		if (!ComparePassword(inputPW))
		{
			cout << "��й�ȣ�� ���� �ʽ��ϴ�." << endl;
			return false;
		}

		return true;
	}
};
#endif
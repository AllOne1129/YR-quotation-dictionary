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
};
#endif
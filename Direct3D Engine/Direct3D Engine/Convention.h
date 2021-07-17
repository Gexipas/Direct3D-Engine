#pragma once

class Singleton
{
	//******************Singleton******************
public:
	static Singleton& GetInstance()
	{
		static Singleton instance;
		return instance;
	}
	Singleton(Singleton const&) = delete;
	void operator= (Singleton const&) = delete;

private:
	Singleton();
	~Singleton() {};
	//*********************************************
};
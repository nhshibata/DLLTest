#pragma once

namespace Cookie
{

	template <class T>
	class Singleton
	{
	private:

	public:
		Singleton() 
		{}
		~Singleton() 
		{}

		static T* Get()
		{
			static T instance;
			return &instance;
		}

	};

}
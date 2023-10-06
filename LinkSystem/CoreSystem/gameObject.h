#pragma once

#include "component.h"
#include <vector>
#include <string>

namespace Cookie
{

	class GameObject
	{
	private:
		std::vector<Component*> m_aComponets;
		std::string m_message;
	public:
		GameObject() {}
		GameObject(std::string str):m_message(str){}
		~GameObject() {}

		void Message()
		{
			printf("%s", m_message.c_str());
		}

		template<class T>
		void AddComponet()
		{
			T* com = new T();

			m_aComponets.push_back(com);
		}
	};


}

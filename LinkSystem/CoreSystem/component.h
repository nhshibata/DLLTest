#pragma once

namespace Cookie
{

	class GameObject;

	class Component
	{
	private:
		GameObject* m_pOwner;
	public:
		Component() : m_pOwner(nullptr)
		{};
		Component(GameObject* obj): m_pOwner(obj)
		{};
		~Component() {};

	};

}
#ifndef __COMPONENT_H__
#define __COMPONENT_H__

class Object
{
public:
	Object();
	~Object();
};

class Component
{
public:
	Component();
	Component(Object* obj);
	~Component();

};

// ↓スニペット対象
// newcomponent入寮区でスニペット
//class NewT : public Component
//{
//public:
//	Component();
//	Component(Object* obj);
//	~Component();
//
//};

void AA()
{
	int aaaa;
}

#endif // !__COMPONENT_H__


#pragma once
class Object;
struct Type
{
	const char* Name;
	int size;
	unsigned int schema;
	Object* (__stdcall* createobject)();
	Type* baseType;
	Type *next;

	Object* CreateObject();
	bool IsDervedFrom(const Type*baseType)const;
};
#define TYPEOF(classname)((Type*)&classname::type)
class Object
{
public:
	Object(){}
	virtual ~Object() {}
	virtual Type* GetType()const;
	bool IsKindOf(const Type* type)const;
	const static Type type;
};
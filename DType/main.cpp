#include"afx.h"
#include<iostream>
using namespace std;
class  Presion:public Object
{
public:
	 virtual Type* GetType()const;
	 const static Type type;
	 static Object* __stdcall Create() { return new Presion; }
};
int main() {
	/*Object *p = new Presion;
	if (p->IsKindOf(TYPEOF(Presion))) {
		Presion* pr = (Presion*)p;
		cout << "CreateOK" << endl;
		delete pr;
	}
	else
	{
		delete p;
	}*/
	Type* type = TYPEOF(Presion);
	Object* s = type->CreateObject();
	if (s!=nullptr&&s->GetType() == TYPEOF(Presion)) {
		cout << "create ok" << endl;
		delete s;
	}
	getchar();
}
const struct Type Presion::type = {"Presion",sizeof(Presion),0xffff,&Presion::Create,TYPEOF(Object),nullptr};
Type* Presion::GetType() const
{
	return TYPEOF(Presion);
}

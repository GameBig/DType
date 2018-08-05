#include "afx.h"
const struct Type Object::type = { "Object",sizeof(Object),0xffff,nullptr,nullptr,nullptr };
Type* Object::GetType() const
{
	return TYPEOF(Object);
}

bool Object::IsKindOf(const Type * type) const
{
	Type* thisType = GetType();
	return thisType->IsDervedFrom(type);
	
}

Object * Type::CreateObject()
{
	return createobject();
}

bool Type::IsDervedFrom(const Type * baseType) const
{
	const Type* TThis = this;
	while (TThis != nullptr) {
		if (TThis == baseType) {
			return true;
		}
		TThis = this->baseType;
	}
	return false;
}

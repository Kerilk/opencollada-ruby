#include "rice/Class.hpp"
#include <COLLADAFWObject.h>

#ifndef BASEOBJECT_HPP
#define BASEOBJECT_HPP

using namespace Rice;

template<typename T> inline void rb_add_Object_interface(Data_Type<T> klass)
{
	klass.define_singleton_method("id", &T::ID);
	klass.define_method("unique_id", &T::getUniqueId);
	klass.define_method("class_id", &T::getClassId);
	klass.define_method("object_id", &T::getObjectId);
	klass.define_method("file_id", &T::getFileId);
}

#endif

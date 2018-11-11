#ifndef FW_BASEOBJECT_HPP
#define FW_BASEOBJECT_HPP

#include "rice/Data_Type.hpp"
#include "rice/Class.hpp"
#include <COLLADAFWObject.h>
#include "fw.hpp"

using namespace Rice;

template<typename T> inline void rb_add_Object_interface(Data_Type<T> klass)
{
	klass.define_singleton_method("id", &T::ID);
	klass.define_method("unique_id", &T::getUniqueId);
	klass.define_method("class_id", &T::getClassId);
	klass.define_method("object_id", &T::getObjectId);
	klass.define_method("file_id", &T::getFileId);
}

template<COLLADAFW::ClassId T, typename O> inline void rb_createCFWObjectTemplateClass(Data_Type<O> &rb_cCFWObjectTemplateClass, std::string name)
{
	Data_Type<COLLADAFW::ObjectTemplate<T>> rb_cCFWObjectTemplate;
	rb_cCFWObjectTemplate = rb_cCFW.define_class<COLLADAFW::ObjectTemplate<T>>((name + "ObjectTemplate").c_str());
	rb_add_Object_interface(rb_cCFWObjectTemplate);
	rb_cCFWObjectTemplateClass = rb_cCFW.define_class<O, COLLADAFW::ObjectTemplate<T>>(name.c_str());
}

#endif

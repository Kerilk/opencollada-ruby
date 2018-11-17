#ifndef FW_ARRAYPRIMITIVETYPE_HPP
#define FW_ARRAYPRIMITIVETYPE_HPP

#include "rice/Data_Type.hpp"
#include "rice/Enum.hpp"
#include "rice/Constructor.hpp"
#include <COLLADAFWArrayPrimitiveType.h>
#include "fw.hpp"

using namespace Rice;

template<typename T> static Object rb_CFWAPT_data(Object self)
{
	Data_Object<typename COLLADAFW::ArrayPrimitiveType<T>> d(self);
	COLLADAFW::ArrayPrimitiveType<T> *arr = &(*d);
	VALUE mod;
	VALUE klass;
	VALUE ret;
	VALUE data_type = Qnil;
	T *data = arr->getData();
	if (data == NULL)
		return Qnil;
	mod = rb_const_get(rb_cObject, rb_intern("FFI"));
	klass = rb_const_get(mod, rb_intern("Pointer"));
	ret = rb_funcall(klass, rb_intern("new"), 1, ULL2NUM( sizeof(data) == 4 ? (unsigned long long int) (unsigned long int) data : (unsigned long long int) data));
	ret = rb_funcall(ret, rb_intern("slice"), 2, ULL2NUM(0), ULL2NUM(arr->getCount()*sizeof(T)));
	klass = rb_const_get(rb_cObject, rb_intern("NArray"));
	data_type = rb_CFWAPT_data_type<T>(klass);
	if (data_type == Qnil)
		return ret;
	ret = rb_funcall(klass, rb_intern("to_na"), 3, ret, data_type, ULL2NUM(arr->getCount()));
	return ret;
}

template<typename T> static Object rb_CFWAPT_set_data(Object self, Object ptr)
{
	Data_Object<typename COLLADAFW::ArrayPrimitiveType<T>> d(self);
	COLLADAFW::ArrayPrimitiveType<T> *arr = &(*d);
	VALUE arr_ptr;
	size_t count;
	VALUE klass = rb_const_get(rb_cObject, rb_intern("FFI"));
	if (rb_funcall(ptr, rb_intern("kind_of?"), 1, rb_const_get(rb_cObject, rb_intern("NArray"))) == Qtrue) {
		arr_ptr = rb_funcall(ptr, rb_intern("to_ptr"), 0);
		count = NUM2ULL(rb_funcall(ptr, rb_intern("size"), 0));
	} else if (rb_funcall(ptr, rb_intern("kind_of?"), 1, rb_const_get(klass, rb_intern("Pointer"))) == Qtrue) {
		arr_ptr = ptr;
		count = NUM2ULL(rb_funcall(arr_ptr, rb_intern("size"), 0)) / sizeof(T);
	} else {
		rb_raise(rb_eRuntimeError, "Argument must be NArray or FFI::Pointer!");
	}
	T *address = (T *)NUM2ULL(rb_funcall(arr_ptr, rb_intern("address"), 0));
	arr->setData(address, count);
	return ptr;
}

template<typename T> static Object rb_CFWAPT_append_values(Object self, Object ptr)
{
	const char *name = CFWAPT_klass_name<T>();
	Data_Object<typename COLLADAFW::ArrayPrimitiveType<T>> d(self);
	COLLADAFW::ArrayPrimitiveType<T> *arr = &(*d);
	VALUE arr_ptr;
	size_t count;
	VALUE klass = rb_const_get(rb_cObject, rb_intern("FFI"));
	VALUE klass2 = rb_const_get(rb_cObject, rb_intern("OpenCOLLADA"));
	klass2 = rb_const_get(klass2, rb_intern("FW"));
	if (rb_funcall(ptr, rb_intern("kind_of?"), 1, rb_const_get(rb_cObject, rb_intern("NArray"))) == Qtrue) {
		arr_ptr = rb_funcall(ptr, rb_intern("to_ptr"), 0);
		count = NUM2ULL(rb_funcall(ptr, rb_intern("size"), 0));
	} else if (rb_funcall(ptr, rb_intern("kind_of?"), 1, rb_const_get(klass, rb_intern("Pointer"))) == Qtrue) {
		arr_ptr = ptr;
		count = NUM2ULL(rb_funcall(arr_ptr, rb_intern("size"), 0)) / sizeof(T);
	} else if (rb_funcall(ptr, rb_intern("kind_of?"), 1, rb_const_get(klass2, rb_intern(name))) == Qtrue) {
		Data_Object<typename COLLADAFW::ArrayPrimitiveType<T>> d2(ptr);
		arr->appendValues(*d2);
		return self;
	} else {
		rb_raise(rb_eRuntimeError, "Argument must be NArray or FFI::Pointer or %s!", name);
	}
	T *address = (T *)NUM2ULL(rb_funcall(arr_ptr, rb_intern("address"), 0));
	arr->appendValues(address, count);
	return self;
}

template<typename T> inline void rb_add_ArrayPrimitiveType_interface(Data_Type<T> klass)
{
	klass.define_constructor(
		Constructor<T, int>(),
		(Arg("flags") = (int)T::FlagCombinations::DEFAULT_CONSTRUCTOR_FLAGS)
	);
	klass.define_method("clear", &T::clear);
	klass.define_method("count", &T::getCount);
	klass.define_method("count=", &T::setCount);
	klass.define_method("capacity", &T::getCapacity);
	klass.define_method("capacity=", &T::setCapacity);
	klass.define_method("alloc_memory", &T::allocMemory, (Arg("capacity"), Arg("flags") = (int)T::DEFAULT_ALLOC_FLAGS));
	klass.define_method("release_memory", &T::releaseMemory);
	klass.define_method("realloc_memory", &T::reallocMemory);
	klass.define_method("append", &T::append);
	klass.define_method("erase", &T::erase);
	klass.define_method("empty?", &T::empty);
	klass.define_method("clone_array", &T::cloneArray);
	klass.define_method("yield_owner_ship", &T::yieldOwnerShip);
}

template<typename T> static inline VALUE rb_CFWAPT_data_type(VALUE klass)
{
	return Qnil;
}

template<> inline VALUE rb_CFWAPT_data_type<int>(VALUE klass)
{
	return rb_const_get(klass, rb_intern("INT"));
}

template<> inline VALUE rb_CFWAPT_data_type<float>(VALUE klass)
{
	return rb_const_get(klass, rb_intern("SFLOAT"));
}

template<> inline VALUE rb_CFWAPT_data_type<double>(VALUE klass)
{
	return rb_const_get(klass, rb_intern("FLOAT"));
}

template<typename T> static inline const char * CFWAPT_klass_name();
template<> inline const char * CFWAPT_klass_name<unsigned int>() { return "UIntValuesArray"; }
template<> inline const char * CFWAPT_klass_name<int>() { return "IntValuesArray"; }
template<> inline const char * CFWAPT_klass_name<size_t>() { return "SizeTValuesArray"; }
template<> inline const char * CFWAPT_klass_name<unsigned long long>() { return "ULongLongArray"; }
template<> inline const char * CFWAPT_klass_name<long long>() { return "LongLongValuesArray"; }
template<> inline const char * CFWAPT_klass_name<float>() { return "FloatArray"; }
template<> inline const char * CFWAPT_klass_name<double>() { return "DoubleArray"; }
template<> inline const char * CFWAPT_klass_name<COLLADAFW::PhysicalDimension>() { return "PhysicalDimensionArray"; }

template<typename T> inline void rb_createCFWArrayPrimitiveTypeClass(Data_Type<COLLADAFW::ArrayPrimitiveType<T>> &rb_cCFWArrayPrimitiveTypeClass)
{
	const char *name = CFWAPT_klass_name<T>();
	rb_cCFWArrayPrimitiveTypeClass = rb_cCFW.define_class<COLLADAFW::ArrayPrimitiveType<T>>(name);
	rb_add_ArrayPrimitiveType_interface(rb_cCFWArrayPrimitiveTypeClass);
	rb_cCFWArrayPrimitiveTypeClass.define_method("data", &rb_CFWAPT_data<T>);
	rb_cCFWArrayPrimitiveTypeClass.define_method("data=", &rb_CFWAPT_set_data<T>);
	rb_cCFWArrayPrimitiveTypeClass.define_method("append_values", &rb_CFWAPT_append_values<T>);
	rb_cCFWArrayPrimitiveTypeClass.define_method("+", &rb_CFWAPT_append_values<T>);
	//rb_cCFWArrayPrimitiveTypeClass.define_method("[]", static_cast<T& (COLLADAFW::ArrayPrimitiveType<T>::*)(size_t)>(&COLLADAFW::ArrayPrimitiveType<T>::operator[]));
	//rb_cCFWArrayPrimitiveTypeClass.define_method("back", static_cast<T& (COLLADAFW::ArrayPrimitiveType<T>::*)()>(&COLLADAFW::ArrayPrimitiveType<T>::back));

	Enum<typename COLLADAFW::ArrayPrimitiveType<T>::Flags> rb_cCFWAPTFlags;
	rb_cCFWAPTFlags = define_enum<typename COLLADAFW::ArrayPrimitiveType<T>::Flags>("Flags", rb_cCFWArrayPrimitiveTypeClass);
	rb_cCFWAPTFlags.define_value("NO_FLAGS", COLLADAFW::ArrayPrimitiveType<T>::Flags::NO_FLAGS);
	rb_cCFWAPTFlags.define_value("RELEASE_MEMORY", COLLADAFW::ArrayPrimitiveType<T>::Flags::RELEASE_MEMORY);
	rb_cCFWAPTFlags.define_value("KEEP_OWNERSHIP_ON_ASSIGNEMNT", COLLADAFW::ArrayPrimitiveType<T>::Flags::KEEP_OWNERSHIP_ON_ASSIGNEMNT);
	Enum<typename COLLADAFW::ArrayPrimitiveType<T>::FlagCombinations> rb_cCFWAPTFlagCombinations;
	rb_cCFWAPTFlagCombinations = define_enum<typename COLLADAFW::ArrayPrimitiveType<T>::FlagCombinations>("FlagCombinations", rb_cCFWArrayPrimitiveTypeClass);
	rb_cCFWAPTFlagCombinations.define_value("DEFAULT_ALLOC_FLAGS", COLLADAFW::ArrayPrimitiveType<T>::FlagCombinations::DEFAULT_ALLOC_FLAGS);
	rb_cCFWAPTFlagCombinations.define_value("DEFAULT_CONSTRUCTOR_FLAGS", COLLADAFW::ArrayPrimitiveType<T>::FlagCombinations::DEFAULT_CONSTRUCTOR_FLAGS);
	rb_cCFWAPTFlagCombinations.define_value("OWNER", COLLADAFW::ArrayPrimitiveType<T>::FlagCombinations::OWNER);
}

#endif

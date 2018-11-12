#ifndef FW_ARRAYPRIMITIVETYPE_HPP
#define FW_ARRAYPRIMITIVETYPE_HPP

#include "rice/Data_Type.hpp"
#include "rice/Enum.hpp"
#include "rice/Constructor.hpp"
#include <COLLADAFWArrayPrimitiveType.h>
#include "fw.hpp"

using namespace Rice;

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
	klass.define_method("+", static_cast<T* (T::*)(const T&)>(&T::appendValues));
	klass.define_method("erase", &T::erase);
	klass.define_method("empty?", &T::empty);
	klass.define_method("clone_array", &T::cloneArray);
	klass.define_method("yield_owner_ship", &T::yieldOwnerShip);
}

template<typename T> inline void rb_createCFWArrayPrimitiveTypeClass(Data_Type<COLLADAFW::ArrayPrimitiveType<T>> &rb_cCFWArrayPrimitiveTypeClass, std::string name)
{
	rb_cCFWArrayPrimitiveTypeClass = rb_cCFW.define_class<COLLADAFW::ArrayPrimitiveType<T>>(name.c_str());
	rb_add_ArrayPrimitiveType_interface(rb_cCFWArrayPrimitiveTypeClass);
	rb_cCFWArrayPrimitiveTypeClass.define_method("data", static_cast<T* (COLLADAFW::ArrayPrimitiveType<T>::*)()>(&COLLADAFW::ArrayPrimitiveType<T>::getData));
	rb_cCFWArrayPrimitiveTypeClass.define_method("set_data", static_cast<void (COLLADAFW::ArrayPrimitiveType<T>::*)(T*, const size_t, const size_t)>(&COLLADAFW::ArrayPrimitiveType<T>::setData));
	rb_cCFWArrayPrimitiveTypeClass.define_method("append_values", static_cast<COLLADAFW::ArrayPrimitiveType<T>* (COLLADAFW::ArrayPrimitiveType<T>::*)(const T*, const size_t)>(&COLLADAFW::ArrayPrimitiveType<T>::appendValues));
	rb_cCFWArrayPrimitiveTypeClass.define_method("[]", static_cast<T& (COLLADAFW::ArrayPrimitiveType<T>::*)(size_t)>(&COLLADAFW::ArrayPrimitiveType<T>::operator[]));
	rb_cCFWArrayPrimitiveTypeClass.define_method("back", static_cast<T& (COLLADAFW::ArrayPrimitiveType<T>::*)()>(&COLLADAFW::ArrayPrimitiveType<T>::back));

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

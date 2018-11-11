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
}

template<typename T> inline void rb_createCFWArrayPrimitiveTypeClass(Data_Type<COLLADAFW::ArrayPrimitiveType<T>> &rb_cCFWArrayPrimitiveTypeClass, std::string name)
{
	rb_cCFWArrayPrimitiveTypeClass = rb_cCFW.define_class<COLLADAFW::ArrayPrimitiveType<T>>(name.c_str());
	rb_add_ArrayPrimitiveType_interface(rb_cCFWArrayPrimitiveTypeClass);

//	Enum<COLLADAFW::ArrayPrimitiveType<T>::Flags> rb_cCFWAPTFlags;
//	rb_cCFWAPTFlags = define_enum<COLLADAFW::ArrayPrimitiveType<T>::Flags>("Flags", rb_cCFWArrayPrimitiveTypeClass);
//	rb_cCFWAPTFlags.define_value("NO_FLAGS", COLLADAFW::ArrayPrimitiveType<T>::Flags::NO_FLAGS);
//	rb_cCFWAPTFlags.define_value("RELEASE_MEMORY", COLLADAFW::ArrayPrimitiveType<T>::Flags::RELEASE_MEMORY);
//	rb_cCFWAPTFlags.define_value("KEEP_OWNERSHIP_ON_ASSIGNEMNT", COLLADAFW::ArrayPrimitiveType<T>::Flags::KEEP_OWNERSHIP_ON_ASSIGNEMNT);
//	Enum<COLLADAFW::ArrayPrimitiveType<T>::FlagCombinations> rb_cCFWAPTFlagCombinations;
//	rb_cCFWAPTFlagCombinations define_enum<COLLADAFW::ArrayPrimitiveType<T>::FlagCombinations>("FlagCombinations", rb_cCFWArrayPrimitiveTypeClass);
//	rb_cCFWAPTFlagCombinations.define_values("DEFAULT_ALLOC_FLAGS", COLLADAFW::ArrayPrimitiveType<T>::FlagCombinations::DEFAULT_ALLOC_FLAGS);
//	rb_cCFWAPTFlagCombinations.define_values("DEFAULT_CONSTRUCTOR_FLAGS", COLLADAFW::ArrayPrimitiveType<T>::FlagCombinations::DEFAULT_CONSTRUCTOR_FLAGS);
//	rb_cCFWAPTFlagCombinations.define_values("OWNER", COLLADAFW::ArrayPrimitiveType<T>::FlagCombinations::OWNER);
}

#endif

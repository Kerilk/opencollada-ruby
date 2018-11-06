#include "rice/Enum.hpp"
#include <COLLADAFWTypes.h>

#ifndef CLASSID_HPP
#define CLASSID_HPP

using namespace Rice;

extern Rice::Enum<COLLADAFW::ClassId> rb_cCFWClassId;

template<> inline COLLADAFW::ClassId from_ruby<COLLADAFW::ClassId>(Rice::Object x)
{
	Rice::Data_Object<COLLADAFW::ClassId> d(x, rb_cCFWClassId);
	return *d;
} 

void rb_define_CFWClassId();
#endif

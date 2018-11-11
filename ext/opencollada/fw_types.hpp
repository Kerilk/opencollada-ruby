#ifndef FW_CLASSID_HPP
#define FW_CLASSID_HPP

#include "rice/Enum.hpp"
#include "rice/Data_Type.hpp"
#include <COLLADAFWTypes.h>

using namespace Rice;

extern Enum<COLLADAFW::ClassId> rb_cCFWClassId;

extern Data_Type<COLLADAFW::ArrayPrimitiveType<float>> rb_cCFWFloatArray;

void rb_define_CFWClassId();
void rb_define_CFWArrays();
#endif

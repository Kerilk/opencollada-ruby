#ifndef FW_FLOATORDOUBLEARRAY_HPP
#define FW_FLOATORDOUBLEARRAY_HPP

#include "rice/Data_Type.hpp"
#include <COLLADAFWFloatOrDoubleArray.h>
#include "fw_animatable.hpp"

using namespace Rice;

extern Data_Type<COLLADAFW::FloatOrDoubleArray> rb_cCFWFloatOrDoubleArray;

void rb_define_CFWFloatOrDouble();

#endif

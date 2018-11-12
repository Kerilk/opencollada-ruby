#ifndef FW_CLASSID_HPP
#define FW_CLASSID_HPP

#include "rice/Enum.hpp"
#include "rice/Data_Type.hpp"
#include <COLLADAFWTypes.h>

using namespace Rice;

extern Enum<COLLADAFW::ClassId> rb_cCFWClassId;
extern Enum<COLLADAFW::PhysicalDimension> rb_cFWPhysicalDimension;

extern Data_Type<COLLADAFW::ArrayPrimitiveType<unsigned int>> rb_cCFWUIntValuesArray;
extern Data_Type<COLLADAFW::ArrayPrimitiveType<int>> rb_cCFWIntValuesArray;
extern Data_Type<COLLADAFW::ArrayPrimitiveType<size_t>> rb_cCFWSizeTValuesArray;
extern Data_Type<COLLADAFW::ArrayPrimitiveType<unsigned long long>> rb_cCFWULongLongValuesArray;
extern Data_Type<COLLADAFW::ArrayPrimitiveType<long long>> rb_cCFWLongLongValuesArray;
extern Data_Type<COLLADAFW::ArrayPrimitiveType<float>> rb_cCFWFloatArray;
extern Data_Type<COLLADAFW::ArrayPrimitiveType<double>> rb_cCFWDoubleArray;
extern Data_Type<COLLADAFW::ArrayPrimitiveType<COLLADAFW::PhysicalDimension>> rb_cCFWPhysicalDimensionArray;

void rb_define_CFWTypes();
#endif

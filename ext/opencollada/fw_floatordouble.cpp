#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "rice/Enum.hpp"
#include <COLLADAFWFloatOrDoubleArray.h>
#include <COLLADAFWAnimatable.h>
#include "fw_animatable.hpp"
#include "fw_floatordouble.hpp"
#include "fw_arrayprimitivetype.hpp"
#include "fw_types.hpp"
#include "fw.hpp"
#include <iostream>

using namespace Rice;

Data_Type<COLLADAFW::FloatOrDoubleArray> rb_cCFWFloatOrDoubleArray;

static Object rb_CFWFODA_get_values(Object self) {
	Data_Object<COLLADAFW::FloatOrDoubleArray> d(self, rb_cCFWFloatOrDoubleArray);
	COLLADAFW::FloatOrDoubleArray *arr = &(*d);
	VALUE mod;
	VALUE klass;
	VALUE ret;
	if (arr->getType() == COLLADAFW::FloatOrDoubleArray::DataType::DATA_TYPE_FLOAT)
	{
		COLLADAFW::FloatArray* f_arr = arr->getFloatValues();
		if (f_arr == nullptr)
			return Qnil;
		Data_Object<COLLADAFW::FloatArray> d2(f_arr, rb_cCFWFloatArray, nullptr, nullptr);
		return d2;
	}
	if (arr->getType() == COLLADAFW::FloatOrDoubleArray::DataType::DATA_TYPE_DOUBLE)
	{
		COLLADAFW::DoubleArray* d_arr = arr->getDoubleValues();
		if (d_arr == nullptr)
			return Qnil;
		Data_Object<COLLADAFW::DoubleArray> d2(d_arr, rb_cCFWDoubleArray, nullptr, nullptr);
		return d2;
	}
	return Qnil;
}

void rb_define_CFWFloatOrDouble()
{
	rb_cCFWFloatOrDoubleArray = rb_cCFW.define_class<COLLADAFW::FloatOrDoubleArray, COLLADAFW::Animatable>("FloatOrDoubleArray");
	Enum<COLLADAFW::FloatOrDoubleArray::DataType> rb_cCFWFODDataType;
	rb_cCFWFODDataType = define_enum<COLLADAFW::FloatOrDoubleArray::DataType>("DataType", rb_cCFWFloatOrDoubleArray);
	rb_cCFWFODDataType.define_value("DATA_TYPE_FLOAT", COLLADAFW::FloatOrDoubleArray::DataType::DATA_TYPE_FLOAT);
	rb_cCFWFODDataType.define_value("DATA_TYPE_DOUBLE", COLLADAFW::FloatOrDoubleArray::DataType::DATA_TYPE_DOUBLE);
	rb_cCFWFODDataType.define_value("DATA_TYPE_UNKNOWN", COLLADAFW::FloatOrDoubleArray::DataType::DATA_TYPE_UNKNOWN);
	rb_cCFWFloatOrDoubleArray.define_constructor(Constructor<COLLADAFW::FloatOrDoubleArray, COLLADAFW::FloatOrDoubleArray::DataType>(), (Arg("type") = COLLADAFW::FloatOrDoubleArray::DataType::DATA_TYPE_UNKNOWN));

	rb_cCFWFloatOrDoubleArray.define_method("type", &COLLADAFW::FloatOrDoubleArray::getType);
	rb_cCFWFloatOrDoubleArray.define_method("type=", &COLLADAFW::FloatOrDoubleArray::setType);
	rb_cCFWFloatOrDoubleArray.define_method("values_count", &COLLADAFW::FloatOrDoubleArray::getValuesCount);
	rb_cCFWFloatOrDoubleArray.define_method("empty?", &COLLADAFW::FloatOrDoubleArray::empty);
	rb_cCFWFloatOrDoubleArray.define_method("clear", &COLLADAFW::FloatOrDoubleArray::clear);
	rb_cCFWFloatOrDoubleArray.define_method("get_values", &rb_CFWFODA_get_values);
}

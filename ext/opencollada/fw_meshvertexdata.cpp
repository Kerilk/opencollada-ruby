#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include <COLLADAFWMeshVertexData.h>
#include "fw_meshvertexdata.hpp"
#include "fw_floatordouble.hpp"
#include "fw_arrayprimitivetype.hpp"
#include "fw.hpp"

using namespace Rice;

Data_Type<COLLADAFW::MeshVertexData> rb_cCFWMeshVertexData;

template<>
Object to_ruby<COLLADAFW::MeshVertexData>(COLLADAFW::MeshVertexData const & x)
{
	return to_ruby(&x);
}

void rb_define_CFWMeshVertexData()
{
	rb_cCFWMeshVertexData = rb_cCFW.define_class<COLLADAFW::MeshVertexData, COLLADAFW::FloatOrDoubleArray>("MeshVertexData");
	rb_cCFWMeshVertexData.define_constructor(Constructor<COLLADAFW::MeshVertexData, COLLADAFW::FloatOrDoubleArray::DataType>(), (Arg("type") = COLLADAFW::FloatOrDoubleArray::DataType::DATA_TYPE_UNKNOWN));
	Data_Type<COLLADAFW::MeshVertexData::InputInfos> rb_cCFWMVDInputInfos;
	rb_cCFWMVDInputInfos = rb_cCFWMeshVertexData.define_class<COLLADAFW::MeshVertexData::InputInfos>("InputInfos");
	rb_cCFWMVDInputInfos.define_constructor(Constructor<COLLADAFW::MeshVertexData::InputInfos>());
	Data_Type<COLLADAFW::ArrayPrimitiveType<COLLADAFW::MeshVertexData::InputInfos>> rb_cCFWMVDInputInfosArray;
	rb_createCFWArrayPrimitiveTypeClass<COLLADAFW::MeshVertexData::InputInfos>(rb_cCFWMVDInputInfosArray);
	rb_cCFWMeshVertexData.define_method("num_inputs_info", &COLLADAFW::MeshVertexData::getNumInputInfos);
	rb_cCFWMeshVertexData.define_method("name", &COLLADAFW::MeshVertexData::getName);
	rb_cCFWMeshVertexData.define_method("stride", &COLLADAFW::MeshVertexData::getStride);
	rb_cCFWMeshVertexData.define_method("length", &COLLADAFW::MeshVertexData::getLength);
}

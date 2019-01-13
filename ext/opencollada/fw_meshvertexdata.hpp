#ifndef FW_MESHVERTEXDATA_HPP
#define FW_MESHVERTEXDATA_HPP

#include "rice/Data_Type.hpp"
#include <COLLADAFWMeshVertexData.h>
#include "fw_floatordouble.hpp"

using namespace Rice;

extern Data_Type<COLLADAFW::MeshVertexData> rb_cCFWMeshVertexData;

void rb_define_CFWMeshVertexData();

template<>
Object to_ruby<COLLADAFW::MeshVertexData>(COLLADAFW::MeshVertexData const & x);

#endif

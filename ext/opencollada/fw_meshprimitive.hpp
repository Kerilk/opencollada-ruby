#ifndef FW_MESHPRIMITIVE_HPP
#define FW_MESHPRIMITIVE_HPP

#include "rice/Data_Type.hpp"
#include <COLLADAFWMeshPrimitive.h>

using namespace Rice;

extern Data_Type<COLLADAFW::MeshPrimitive> rb_cCFWMeshPrimitive;

void rb_define_CFWMeshPrimitive();

#endif

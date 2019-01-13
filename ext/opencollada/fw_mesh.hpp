#ifndef FW_MESH_HPP
#define FW_MESH_HPP

#include "rice/Data_Type.hpp"
#include <COLLADAFW.h>

using namespace Rice;

extern  Data_Type<COLLADAFW::Mesh> rb_cCFWMesh;

void rb_define_CFWMesh(void);

#endif

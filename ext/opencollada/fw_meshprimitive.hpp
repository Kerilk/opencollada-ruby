#ifndef FW_MESHPRIMITIVE_HPP
#define FW_MESHPRIMITIVE_HPP

#include "rice/Data_Type.hpp"
#include <COLLADAFWMeshPrimitive.h>

using namespace Rice;

extern Data_Type<COLLADAFW::MeshPrimitive> rb_cCFWMeshPrimitive;

template<>
Object to_ruby<COLLADAFW::ArrayPrimitiveType<COLLADAFW::MeshPrimitive *>>(COLLADAFW::ArrayPrimitiveType<COLLADAFW::MeshPrimitive *> const & x);
template<>
COLLADAFW::MeshPrimitive::PrimitiveType from_ruby<COLLADAFW::MeshPrimitive::PrimitiveType>(Rice::Object x);

void rb_define_CFWMeshPrimitive();

#endif

#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include "rice/Data_Type.hpp"
#include <COLLADAFWGeometry.h>

using namespace Rice;

extern Data_Type<COLLADAFW::Geometry> rb_cCFWGeometry;

void rb_define_CFWGeometry();

#endif

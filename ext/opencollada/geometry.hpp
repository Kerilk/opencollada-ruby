#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP

#include "rice/Data_Type.hpp"
#include <COLLADAFWGeometry.h>

using namespace Rice;

extern Data_Type<COLLADAFW::Geometry> rb_cCFWGeometry;

template<> COLLADAFW::Geometry::GeometryType from_ruby<COLLADAFW::Geometry::GeometryType>(Rice::Object x);

void rb_define_CFWGeometry();

#endif

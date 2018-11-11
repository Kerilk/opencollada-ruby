#include "rice/Data_Type.hpp"
#include "rice/Enum.hpp"
#include "rice/Constructor.hpp"
#include <COLLADAFWGeometry.h>
#include "fw.hpp"
#include "fw_baseobject.hpp"
#include "fw_geometry.hpp"
#include "fw_uniqueid.hpp"


using namespace Rice;

Data_Type<COLLADAFW::Geometry> rb_cCFWGeometry;
Enum<COLLADAFW::Geometry::GeometryType> rb_cCFWGGeometryType;

template<> COLLADAFW::Geometry::GeometryType from_ruby<COLLADAFW::Geometry::GeometryType>(Rice::Object x)
{
	Rice::Data_Object<COLLADAFW::Geometry::GeometryType> d(x, rb_cCFWGGeometryType);
	return *d;
}

void rb_define_CFWGeometry() {
	rb_createCFWObjectTemplateClass<COLLADAFW::COLLADA_TYPE::GEOMETRY,COLLADAFW::Geometry>(rb_cCFWGeometry, "Geometry");
	rb_cCFWGGeometryType = define_enum<COLLADAFW::Geometry::GeometryType>("GeometryType", rb_cCFWGeometry);
	rb_cCFWGGeometryType.define_value("GEO_TYPE_MESH", COLLADAFW::Geometry::GeometryType::GEO_TYPE_MESH);
	rb_cCFWGGeometryType.define_value("GEO_TYPE_SPLINE", COLLADAFW::Geometry::GeometryType::GEO_TYPE_SPLINE);
	rb_cCFWGGeometryType.define_value("GEO_TYPE_CONVEX_MESH", COLLADAFW::Geometry::GeometryType::GEO_TYPE_CONVEX_MESH);
	rb_cCFWGGeometryType.define_value("GEO_TYPE_UNKNOWN", COLLADAFW::Geometry::GeometryType::GEO_TYPE_UNKNOWN);
	rb_cCFWGeometry.define_constructor(
		Constructor<
			COLLADAFW::Geometry,
			COLLADAFW::UniqueId,
			COLLADAFW::Geometry::GeometryType
		>()
	);
	rb_cCFWGeometry.define_method("original_id", &COLLADAFW::Geometry::getOriginalId);
	rb_cCFWGeometry.define_method("original_id=", &COLLADAFW::Geometry::setOriginalId);
	rb_cCFWGeometry.define_method("name", &COLLADAFW::Geometry::getName);
	rb_cCFWGeometry.define_method("name=", &COLLADAFW::Geometry::setName);
	rb_cCFWGeometry.define_method("type", &COLLADAFW::Geometry::getType);
	rb_cCFWGeometry.define_method("type=", &COLLADAFW::Geometry::setType);
//	rb_cCFWGeometry.define_method("clone", &COLLADAFW::Geometry::clone);
}

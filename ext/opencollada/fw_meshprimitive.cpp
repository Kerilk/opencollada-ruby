#include "rice/Data_Type.hpp"
#include "rice/Enum.hpp"
#include "rice/Constructor.hpp"
#include <COLLADAFWMeshPrimitive.h>
#include "fw.hpp"
#include "fw_objecttemplate.hpp"
#include "fw_meshprimitive.hpp"
#include "fw_arrayprimitivetype.hpp"
#include "fw_types.hpp"

using namespace Rice;

Data_Type<COLLADAFW::MeshPrimitive> rb_cCFWMeshPrimitive;
Enum<COLLADAFW::MeshPrimitive::PrimitiveType> rb_cCFWMPPrimitiveType;
Data_Type<COLLADAFW::ArrayPrimitiveType<COLLADAFW::MeshPrimitive *>> rb_cCFWMeshPrimitiveArray;

template<>
Object to_ruby<COLLADAFW::ArrayPrimitiveType<COLLADAFW::MeshPrimitive *>>(COLLADAFW::ArrayPrimitiveType<COLLADAFW::MeshPrimitive *> const & x)
{
	return to_ruby(&x);
}

template<>
COLLADAFW::MeshPrimitive::PrimitiveType from_ruby<COLLADAFW::MeshPrimitive::PrimitiveType>(Rice::Object x)
{
	Rice::Data_Object<COLLADAFW::MeshPrimitive::PrimitiveType> d(x, rb_cCFWMPPrimitiveType);
        return *d;
}

void rb_define_CFWMeshPrimitive() {
	rb_createCFWObjectTemplateClass<COLLADAFW::COLLADA_TYPE::PRIMITIVE_ELEMENT, COLLADAFW::MeshPrimitive>(rb_cCFWMeshPrimitive, "MeshPrimitive");
	rb_cCFWMPPrimitiveType = define_enum<COLLADAFW::MeshPrimitive::PrimitiveType>("PrimitiveType", rb_cCFWMeshPrimitive);
	rb_cCFWMPPrimitiveType.define_value("LINES", COLLADAFW::MeshPrimitive::PrimitiveType::LINES);
	rb_cCFWMPPrimitiveType.define_value("LINE_STRIPS", COLLADAFW::MeshPrimitive::PrimitiveType::LINE_STRIPS);
	rb_cCFWMPPrimitiveType.define_value("POLYGONS", COLLADAFW::MeshPrimitive::PrimitiveType::POLYGONS);
	rb_cCFWMPPrimitiveType.define_value("POLYLIST", COLLADAFW::MeshPrimitive::PrimitiveType::POLYLIST);
	rb_cCFWMPPrimitiveType.define_value("TRIANGLES", COLLADAFW::MeshPrimitive::PrimitiveType::TRIANGLES);
	rb_cCFWMPPrimitiveType.define_value("TRIANGLE_FANS", COLLADAFW::MeshPrimitive::PrimitiveType::TRIANGLE_FANS);
	rb_cCFWMPPrimitiveType.define_value("TRIANGLE_STRIPS", COLLADAFW::MeshPrimitive::PrimitiveType::TRIANGLE_STRIPS);
	rb_cCFWMPPrimitiveType.define_value("POINTS", COLLADAFW::MeshPrimitive::PrimitiveType::POINTS);
	rb_cCFWMPPrimitiveType.define_value("UNDEFINED_PRIMITIVE_TYPE", COLLADAFW::MeshPrimitive::PrimitiveType::UNDEFINED_PRIMITIVE_TYPE);
        rb_cCFWMeshPrimitive.define_constructor(
		Constructor<
			COLLADAFW::MeshPrimitive,
			COLLADAFW::UniqueId,
			COLLADAFW::MeshPrimitive::PrimitiveType
		>(),
		(
			Arg("unique_id"),
			Arg("primitive_type") = COLLADAFW::MeshPrimitive::PrimitiveType::UNDEFINED_PRIMITIVE_TYPE
		)
	);
        rb_createCFWArrayPrimitiveTypeClass<COLLADAFW::MeshPrimitive *>(rb_cCFWMeshPrimitiveArray);
}

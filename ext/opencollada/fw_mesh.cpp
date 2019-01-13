#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "fw.hpp"
#include "fw_uniqueid.hpp"
#include "fw_arrayprimitivetype.hpp"
#include "fw_mesh.hpp"
#include "fw_geometry.hpp"
#include "fw_meshvertexdata.hpp"
#include "fw_meshprimitive.hpp"

using namespace Rice;

Data_Type<COLLADAFW::Mesh> rb_cCFWMesh;

void rb_define_CFWMesh(void)
{
	rb_cCFWMesh = rb_cCFW.define_class<COLLADAFW::Mesh, COLLADAFW::Geometry>("Mesh");
	rb_cCFWMesh.define_constructor(
		Constructor<
			COLLADAFW::Mesh,
			COLLADAFW::UniqueId
		>()
	);
	typedef COLLADAFW::MeshVertexData& (COLLADAFW::Mesh::*get_positions)(void);
	typedef COLLADAFW::MeshVertexData& (COLLADAFW::Mesh::*get_normals)(void);
	typedef COLLADAFW::MeshVertexData& (COLLADAFW::Mesh::*get_colors)(void);
	typedef COLLADAFW::MeshVertexData& (COLLADAFW::Mesh::*get_uv_coords)(void);
	typedef COLLADAFW::MeshVertexData& (COLLADAFW::Mesh::*get_tangents)(void);
	typedef COLLADAFW::MeshVertexData& (COLLADAFW::Mesh::*get_binormals)(void);
	typedef COLLADAFW::MeshPrimitiveArray& (COLLADAFW::Mesh::*get_mesh_primitives)(void);
	rb_cCFWMesh.define_method("positions", get_positions(&COLLADAFW::Mesh::getPositions));
	rb_cCFWMesh.define_method("normals", get_normals(&COLLADAFW::Mesh::getNormals));
	rb_cCFWMesh.define_method("normals?", &COLLADAFW::Mesh::hasNormals);
	rb_cCFWMesh.define_method("colors", get_colors(&COLLADAFW::Mesh::getColors));
	rb_cCFWMesh.define_method("color_index", &COLLADAFW::Mesh::getColorIndexByName);
	rb_cCFWMesh.define_method("uv_coords", get_uv_coords(&COLLADAFW::Mesh::getUVCoords));
	rb_cCFWMesh.define_method("uv_set_index", &COLLADAFW::Mesh::getUVSetIndexByName);
	rb_cCFWMesh.define_method("tangents", get_tangents(&COLLADAFW::Mesh::getTangents));
	rb_cCFWMesh.define_method("binormals", get_binormals(&COLLADAFW::Mesh::getBinormals));
	rb_cCFWMesh.define_method("mesh_primitives", get_mesh_primitives(&COLLADAFW::Mesh::getMeshPrimitives));
	rb_cCFWMesh.define_method("mesh_primitives=", &COLLADAFW::Mesh::setMeshPrimitives);
	rb_cCFWMesh.define_method("append_primitive", &COLLADAFW::Mesh::appendPrimitive);
	rb_cCFWMesh.define_method("triangles_triangle_count", &COLLADAFW::Mesh::getTrianglesTriangleCount);
	rb_cCFWMesh.define_method("tristrips_triangle_count", &COLLADAFW::Mesh::getTristripsTriangleCount);
	rb_cCFWMesh.define_method("trifans_triangle_count", &COLLADAFW::Mesh::getTrifansTriangleCount);
	rb_cCFWMesh.define_method("polygons_polygon_count", &COLLADAFW::Mesh::getPolygonsPolygonCount);
	rb_cCFWMesh.define_method("polygons_polygon_count", &COLLADAFW::Mesh::getPolygonsPolygonCount);
	rb_cCFWMesh.define_method("primitive_count", &COLLADAFW::Mesh::getPrimitiveCount);
	rb_cCFWMesh.define_method("face_count", &COLLADAFW::Mesh::getFaceCount);
	rb_cCFWMesh.define_method("triangles_count", &COLLADAFW::Mesh::getTrianglesCount);
	rb_cCFWMesh.define_method("tristrips_count", &COLLADAFW::Mesh::getTristripsCount);
	rb_cCFWMesh.define_method("trifans_count", &COLLADAFW::Mesh::getTrifansCount);
	rb_cCFWMesh.define_method("polygons_count", &COLLADAFW::Mesh::getPolygonsCount);
	rb_cCFWMesh.define_method("mesh_primitive_count", &COLLADAFW::Mesh::getMeshPrimitiveCount);
	rb_cCFWMesh.define_method("faces_count", &COLLADAFW::Mesh::getFacesCount);
}

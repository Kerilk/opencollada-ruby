#include "rice/Module.hpp"
#include <COLLADAFW.h>
#include "opencollada_bindings.hpp"
#include "fw.hpp"
#include "fw_types.hpp"
#include "fw_uniqueid.hpp"
#include "fw_geometry.hpp"
#include "fw_animatable.hpp"
#include "fw_floatordouble.hpp"
#include "fw_meshvertexdata.hpp"
#include "fw_meshprimitive.hpp"
#include "fw_mesh.hpp"
#include "fw_iwriter.hpp"

#include "ruby_importer.hpp"

#include "saxfwl.hpp"
#include "saxfwl_loader.hpp"

using namespace Rice;

Module rb_cOpenCOLLADA;
Module rb_cCFW;
Module rb_cCSaxFWL;

extern "C"
void Init_opencollada_bindings()
{
	rb_cOpenCOLLADA = define_module("OpenCOLLADA");
	rb_cCFW = rb_cOpenCOLLADA.define_module("FW");
	rb_cCSaxFWL = rb_cOpenCOLLADA.define_module("SaxFWL");
	rb_define_CFWTypes();
	rb_define_CFWUniqueId();
	rb_define_CFWGeometry();
	rb_define_CFWAnimatable();
	rb_define_CFWFloatOrDouble();
	rb_define_CFWMeshVertexData();
	rb_define_CFWMeshPrimitive();
	rb_define_CFWMesh();
	rb_define_CFWIWriter();

	rb_define_CImporter();

	rb_define_CSaxFWLLoader();
}

#include "rice/Module.hpp"
#include <COLLADAFW.h>
#include "fw.hpp"
#include "fw_types.hpp"
#include "fw_uniqueid.hpp"
#include "fw_geometry.hpp"
#include "fw_animatable.hpp"
#include "fw_floatordouble.hpp"
#include "fw_meshvertexdata.hpp"

using namespace Rice;

Module rb_cCFW;

extern "C"
void Init_opencollada_bindings()
{
	Module rb_cOpenCOLLADA = define_module("OpenCOLLADA");
	rb_cCFW = rb_cOpenCOLLADA.define_module("FW");
	rb_define_CFWTypes();
	rb_define_CFWUniqueId();
	rb_define_CFWGeometry();
	rb_define_CFWAnimatable();
	rb_define_CFWFloatOrDouble();
	rb_define_CFWMeshVertexData();
}

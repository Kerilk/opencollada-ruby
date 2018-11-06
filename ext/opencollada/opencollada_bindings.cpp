#include "rice/Module.hpp"
#include <COLLADAFW.h>
#include "opencollada.hpp"
#include "classid.hpp"
#include "uniqueid.hpp"

using namespace Rice;

Module rb_cCFW;

extern "C"
void Init_opencollada_bindings()
{
	Module rb_cOpenCOLLADA = define_module("OpenCOLLADA");
	rb_cCFW = rb_cOpenCOLLADA.define_module("FW");
	rb_define_CFWClassId();
	rb_define_CFWUniqueId();
}

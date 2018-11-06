#include "rice/Module.hpp"
#include <COLLADAFW.h>

using namespace Rice;

extern "C"
void Init_opencollada_bindings()
{
	Module rb_cOpenCOLLADA = define_module("OpenCOLLADA");
}

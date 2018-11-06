#include "rice/Module.hpp"

using namespace Rice;

extern "C"
void Init_opencollada()
{
	Module rb_cOpenCOLLADA = define_module("OpenCOLLADA");
}

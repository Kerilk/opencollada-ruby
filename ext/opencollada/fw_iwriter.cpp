#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "fw.hpp"
#include "fw_iwriter.hpp"

using namespace Rice;

Data_Type<COLLADAFW::IWriter> rb_cCFWIWriter;

void rb_define_CFWIWriter() {
	rb_cCFWIWriter = rb_cCFW.define_class<COLLADAFW::IWriter>("IWriter");
}


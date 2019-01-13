#ifndef FW_IWRITER_HPP
#define FW_IWRITER_HPP
#include "rice/Data_Type.hpp"
#include <COLLADAFW.h>

using namespace Rice;

extern Data_Type<COLLADAFW::IWriter> rb_cCFWIWriter;

void rb_define_CFWIWriter();

#endif

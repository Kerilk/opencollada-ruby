#ifndef FW_CLASSID_HPP
#define FW_CLASSID_HPP

#include "rice/Enum.hpp"
#include <COLLADAFWTypes.h>

using namespace Rice;

extern Enum<COLLADAFW::ClassId> rb_cCFWClassId;

template<> COLLADAFW::ClassId from_ruby<COLLADAFW::ClassId>(Object x);

void rb_define_CFWClassId();
#endif

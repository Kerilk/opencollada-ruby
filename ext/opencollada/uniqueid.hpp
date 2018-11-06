#include "rice/Data_Type.hpp"
#include <COLLADAFWUniqueId.h>
#include "opencollada.hpp"
#include "classid.hpp"

#ifndef UNIQUE_ID_HPP
#define UNIQUE_ID_HPP

using namespace Rice;

extern Data_Type<COLLADAFW::UniqueId> rb_cCFWUniqueId;

void rb_define_CFWUniqueId();

#endif

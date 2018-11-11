#ifndef FW_ANIMATABLE_HPP
#define FW_ANIMATABLE_HPP

#include "rice/Data_Type.hpp"
#include <COLLADAFWAnimatable.h>

extern Data_Type<COLLADAFW::Animatable> rb_cCFWAnimatable;

void rb_define_CFWAnimatable();

#endif

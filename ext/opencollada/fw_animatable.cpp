#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include <COLLADAFWAnimatable.h>
#include "fw.hpp"
#include "fw_animatable.hpp"

using namespace Rice;

Data_Type<COLLADAFW::Animatable> rb_cCFWAnimatable;

void rb_define_CFWAnimatable()
{
	rb_cCFWAnimatable = rb_cCFW.define_class<COLLADAFW::Animatable>("Animatable");
	rb_cCFWAnimatable.define_constructor(Constructor<COLLADAFW::Animatable>());
	rb_cCFWAnimatable.define_method("animation_list", &COLLADAFW::Animatable::getAnimationList);
	rb_cCFWAnimatable.define_method("animation_list=", &COLLADAFW::Animatable::setAnimationList);
}

#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "uniqueid.hpp"

using namespace Rice;

Data_Type<COLLADAFW::UniqueId> rb_cCFWUniqueId;

void rb_define_CFWUniqueId()
{
	rb_cCFWUniqueId = rb_cCFW.define_class<COLLADAFW::UniqueId>("UniqueId");
	rb_cCFWUniqueId.define_constructor(Constructor<COLLADAFW::UniqueId>());
	rb_cCFWUniqueId.define_method("class_id", &COLLADAFW::UniqueId::getClassId);
	rb_cCFWUniqueId.define_method("object_id", &COLLADAFW::UniqueId::getObjectId);
	rb_cCFWUniqueId.define_method("file_id", &COLLADAFW::UniqueId::getFileId);
	rb_cCFWUniqueId.define_method("valid?", &COLLADAFW::UniqueId::isValid);
	rb_cCFWUniqueId.define_method("to_s", &COLLADAFW::UniqueId::toAscii);
	rb_cCFWUniqueId.define_method("from_s", &COLLADAFW::UniqueId::fromAscii);
	rb_cCFWUniqueId.define_method("<", &COLLADAFW::UniqueId::operator<);
	rb_cCFWUniqueId.define_method(">", &COLLADAFW::UniqueId::operator>);
	rb_cCFWUniqueId.define_method("==", &COLLADAFW::UniqueId::operator==);
	rb_cCFWUniqueId.define_method("!=", &COLLADAFW::UniqueId::operator!=);
}

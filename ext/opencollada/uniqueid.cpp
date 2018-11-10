#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "uniqueid.hpp"

using namespace Rice;

Data_Type<COLLADAFW::UniqueId> rb_cCFWUniqueId;

static VALUE ull2num(COLLADAFW::ObjectId const x) {
	return ULL2NUM(x);
}

template<> Rice::Object to_ruby<COLLADAFW::ObjectId>(COLLADAFW::ObjectId const & x)
{
	return Rice::protect(ull2num, x);
}

template<> COLLADAFW::ObjectId from_ruby<COLLADAFW::ObjectId>(Rice::Object x)
{
	return (COLLADAFW::ObjectId) NUM2ULL(x);
}

void rb_define_CFWUniqueId()
{
	rb_cCFWUniqueId = rb_cCFW.define_class<COLLADAFW::UniqueId>("UniqueId");
	rb_cCFWUniqueId.define_constructor(
		Constructor<
			COLLADAFW::UniqueId,
			COLLADAFW::ClassId,
			COLLADAFW::ObjectId,
			COLLADAFW::FileId
		>(),
		(
			Arg("class_id") = COLLADAFW::COLLADA_TYPE::NO_TYPE,
			Arg("object_id") = (COLLADAFW::ObjectId)0,
			Arg("file_id") = (COLLADAFW::FileId)0
		)
	);
	rb_cCFWUniqueId.define_method("class_id", &COLLADAFW::UniqueId::getClassId);
	rb_cCFWUniqueId.define_method("object_id", &COLLADAFW::UniqueId::getObjectId);
	rb_cCFWUniqueId.define_method("file_id", &COLLADAFW::UniqueId::getFileId);
	rb_cCFWUniqueId.define_method("valid?", &COLLADAFW::UniqueId::isValid);
	rb_cCFWUniqueId.define_method("to_ascii", &COLLADAFW::UniqueId::toAscii);
	rb_cCFWUniqueId.define_method("from_ascii", &COLLADAFW::UniqueId::fromAscii);
	rb_cCFWUniqueId.define_method("<", &COLLADAFW::UniqueId::operator<);
	rb_cCFWUniqueId.define_method(">", &COLLADAFW::UniqueId::operator>);
	rb_cCFWUniqueId.define_method("==", &COLLADAFW::UniqueId::operator==);
	rb_cCFWUniqueId.define_method("!=", &COLLADAFW::UniqueId::operator!=);
}

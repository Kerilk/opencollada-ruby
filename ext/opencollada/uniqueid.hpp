#include "rice/Data_Type.hpp"
#include <COLLADAFWUniqueId.h>
#include "opencollada.hpp"
#include "classid.hpp"

#ifndef UNIQUE_ID_HPP
#define UNIQUE_ID_HPP

using namespace Rice;

extern Data_Type<COLLADAFW::UniqueId> rb_cCFWUniqueId;

template<> Rice::Object to_ruby<unsigned long long>(unsigned long long const & x);
template<> unsigned long long from_ruby<unsigned long long>(Rice::Object x);

void rb_define_CFWUniqueId();

#endif

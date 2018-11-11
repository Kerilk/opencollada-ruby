#ifndef FW_UNIQUEID_HPP
#define FW_UNIQUEID_HPP

#include "rice/Data_Type.hpp"
#include <COLLADAFWUniqueId.h>
#include "fw.hpp"
#include "fw_types.hpp"

using namespace Rice;

extern Data_Type<COLLADAFW::UniqueId> rb_cCFWUniqueId;

template<> Object to_ruby<unsigned long long>(unsigned long long const & x);
template<> unsigned long long from_ruby<unsigned long long>(Object x);

void rb_define_CFWUniqueId();

#endif

#ifndef SAXFWL_LOADER_HPP
#define SAXFWL_LOADER_HPP

#include "rice/Data_Type.hpp"
#include <COLLADASaxFWLIErrorHandler.h>
#include <COLLADASaxFWLSaxParserErrorHandler.h>
#include <COLLADASaxFWLLoader.h>

using namespace Rice;

extern Data_Type<COLLADASaxFWL::Loader> rb_cCSaxFWLLoader;

void rb_define_CSaxFWLLoader();

#endif

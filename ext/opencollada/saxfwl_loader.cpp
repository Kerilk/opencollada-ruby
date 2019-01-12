#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "saxfwl.hpp"
#include "saxfwl_loader.hpp"

Data_Type<COLLADASaxFWL::Loader> rb_cCSaxFWLLoader;

void rb_define_CSaxFWLLoader()
{
	rb_cCSaxFWLLoader = rb_cCSaxFWL.define_class<COLLADASaxFWL::Loader>("Loader");
	rb_cCSaxFWLLoader.define_constructor(
		Constructor<
			COLLADASaxFWL::Loader,
			COLLADASaxFWL::IErrorHandler*
		>(),
		(
			Arg("error_handler") = (COLLADASaxFWL::IErrorHandler*)0
		)
	);
}

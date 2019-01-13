#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "ruby_importer.hpp"
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
	typedef bool (COLLADASaxFWL::Loader::*load_document_from_file)(const COLLADAFW::String&, COLLADAFW::IWriter*);
	rb_cCSaxFWLLoader.define_method(
		"load_document",
		load_document_from_file(&COLLADASaxFWL::Loader::loadDocument),
		(
			Arg("file_name"),
			Arg("loader") = new RubyImporter()
		)
	);
}

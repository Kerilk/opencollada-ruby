require 'mkmf-rice'

lib_path = '/usr/lib/opencollada'
fw_h_path = '/usr/include/opencollada/COLLADAFramework'
bu_h_path = '/usr/include/opencollada/COLLADABaseUtils'
saxfwl_h_path = '/usr/include/opencollada/COLLADASaxFrameworkLoader'
gsaxp_h_path = '/usr/include/opencollada/GeneratedSaxParser'

dir_config('OpenCOLLADABaseUtils', bu_h_path, lib_path)
dir_config('OpenCOLLADAFramework', fw_h_path, lib_path)
dir_config('OpenCOLLADASaxFrameworkLoader', saxfwl_h_path, lib_path)
dir_config('GeneratedSaxParser', gsaxp_h_path, lib_path)

$defs.push("-DHAVE_CXX11")
$LDFLAGS += " -Bstatic -lOpenCOLLADASaxFrameworkLoader -lGeneratedSaxParser -lOpenCOLLADAFramework -lOpenCOLLADABaseUtils -lMathMLSolver -lUTF -lftoa -lbuffer -lxml2 -lpcre"

create_makefile('opencollada_bindings')

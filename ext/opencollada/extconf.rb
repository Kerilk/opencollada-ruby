require 'mkmf-rice'

lib_path = '/usr/lib/opencollada'
fw_h_path = '/usr/include/opencollada/COLLADAFramework'
bu_h_path = '/usr/include/opencollada/COLLADABaseUtils'

dir_config('OpenCOLLADABaseUtils', bu_h_path, lib_path)
dir_config('OpenCOLLADAFramework', fw_h_path, lib_path)

$defs.push("-DHAVE_CXX11")
$LDFLAGS += " -Bstatic -lOpenCOLLADABaseUtils -lOpenCOLLADAFramework"

create_makefile('opencollada_bindings')

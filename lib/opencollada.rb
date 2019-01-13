require 'ffi'
require 'narray_ffi'
require 'opencollada_bindings'

class OpenCOLLADA::Importer
  def method_missing(m, *args, &block)
    if m.match("at_write_")
      puts m
      p *args
    else
      super
    end
  end
end

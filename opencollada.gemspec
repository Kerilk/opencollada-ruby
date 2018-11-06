Gem::Specification.new do |s|
  s.name = 'opencollada'
  s.version = "0.0.1"
  s.author = "Brice Videau"
  s.email = "brice.videau@imag.fr"
  s.homepage = "https://github.com/Kerilk/opencollada-ruby"
  s.summary = "Ruby OpenCOLLADA"
  s.description = "Ruby OpenCOLLADA Bindings"
  s.files = %w( opencollada.gemspec LICENSE ext/opencollada/extconf.rb lib/opencollada.rb )
  s.files += Dir['ext/opencollada/*.cpp'] + Dir['ext/opencollada/*.hpp']
  s.extensions << 'ext/opencollada/extconf.rb'
  s.has_rdoc = false
  s.license = 'BSD-2-Clause'
  s.required_ruby_version = '>= 2.2.0'
  s.add_dependency 'rice', '~> 2.1', '>=2.1.2'
end

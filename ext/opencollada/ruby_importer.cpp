#include "rice/Data_Type.hpp"
#include "rice/Constructor.hpp"
#include "ruby_importer.hpp"
#include "opencollada_bindings.hpp"
#include <ruby.h>
#include <ruby/thread.h>
#include "fw_mesh.hpp"
#include "fw_geometry.hpp"

using namespace Rice;

bool RubyImporter::writeGlobalAsset ( const COLLADAFW::FileInfo* asset )
{
	Data_Object<RubyImporter> wrappedRubyImporter(this, rb_cCImporter, nullptr, nullptr);
	wrappedRubyImporter.call("at_write_global_asset");
	return true;
}

bool RubyImporter::writeScene ( const COLLADAFW::Scene* scene )
{
	Data_Object<RubyImporter> wrappedRubyImporter(this, rb_cCImporter, nullptr, nullptr);
	wrappedRubyImporter.call("at_write_scene");
	return true;
}

bool RubyImporter::writeVisualScene ( const COLLADAFW::VisualScene* visualScene )
{
	Data_Object<RubyImporter> wrappedRubyImporter(this, rb_cCImporter, nullptr, nullptr);
	wrappedRubyImporter.call("at_write_visual_scene");
	return true;
}

bool RubyImporter::writeLibraryNodes ( const COLLADAFW::LibraryNodes* libraryNodes )
{
	Data_Object<RubyImporter> wrappedRubyImporter(this, rb_cCImporter, nullptr, nullptr);
	wrappedRubyImporter.call("at_write_library_nodes");
	return true;
 }

bool RubyImporter::writeGeometry ( const COLLADAFW::Geometry* geometry )
{
	Data_Object<RubyImporter> wrappedRubyImporter(this, rb_cCImporter, nullptr, nullptr);
	switch( geometry->getType() ) {
	case COLLADAFW::Geometry::GeometryType::GEO_TYPE_MESH:
		{
			Data_Object<COLLADAFW::Mesh> wrappedMesh((COLLADAFW::Mesh *)geometry, rb_cCFWMesh, nullptr, nullptr);
			wrappedRubyImporter.call("at_write_geometry", wrappedMesh);
		}
		break;
	case COLLADAFW::Geometry::GeometryType::GEO_TYPE_SPLINE:
	case COLLADAFW::Geometry::GeometryType::GEO_TYPE_CONVEX_MESH:
	case COLLADAFW::Geometry::GeometryType::GEO_TYPE_UNKNOWN:
		{
			Data_Object<COLLADAFW::Geometry> wrappedGeometry((COLLADAFW::Geometry*)geometry, rb_cCFWGeometry, nullptr, nullptr);
			wrappedRubyImporter.call("at_write_geometry", wrappedGeometry);
		}
		break;
	default:
		return false;
	}
	return true;
}

bool RubyImporter::writeMaterial( const COLLADAFW::Material* material )
{
	Data_Object<RubyImporter> wrappedRubyImporter(this, rb_cCImporter, nullptr, nullptr);
	wrappedRubyImporter.call("at_write_material");
	return true;
}

bool RubyImporter::writeEffect( const COLLADAFW::Effect* effect )
{
	Data_Object<RubyImporter> wrappedRubyImporter(this, rb_cCImporter, nullptr, nullptr);
	wrappedRubyImporter.call("at_write_effect");
	return true;
}

bool RubyImporter::writeCamera( const COLLADAFW::Camera* camera )
{
	Data_Object<RubyImporter> wrappedRubyImporter(this, rb_cCImporter, nullptr, nullptr);
	wrappedRubyImporter.call("at_write_camera");
	return true;
}

bool RubyImporter::writeImage( const COLLADAFW::Image* image )
{
	Data_Object<RubyImporter> wrappedRubyImporter(this, rb_cCImporter, nullptr, nullptr);
	wrappedRubyImporter.call("at_write_image");
	return true;
}

bool RubyImporter::writeLight( const COLLADAFW::Light* light )
{
	Data_Object<RubyImporter> wrappedRubyImporter(this, rb_cCImporter, nullptr, nullptr);
	wrappedRubyImporter.call("at_write_light");
	return true;
}

bool RubyImporter::writeAnimation( const COLLADAFW::Animation* animation )
{
	Data_Object<RubyImporter> wrappedRubyImporter(this, rb_cCImporter, nullptr, nullptr);
	wrappedRubyImporter.call("at_write_animation");
	return true;
}

bool RubyImporter::writeAnimationList( const COLLADAFW::AnimationList* animationList )
{
	Data_Object<RubyImporter> wrappedRubyImporter(this, rb_cCImporter, nullptr, nullptr);
	wrappedRubyImporter.call("at_write_animation_list");
	return true;
}

bool RubyImporter::writeSkinControllerData( const COLLADAFW::SkinControllerData* skinControllerData )
{
	Data_Object<RubyImporter> wrappedRubyImporter(this, rb_cCImporter, nullptr, nullptr);
	wrappedRubyImporter.call("at_write_skin_controller_data");
	return true;
}

bool RubyImporter::writeController( const COLLADAFW::Controller* controller )
{
	Data_Object<RubyImporter> wrappedRubyImporter(this, rb_cCImporter, nullptr, nullptr);
	wrappedRubyImporter.call("at_write_controller");
	return true;
}

bool RubyImporter::writeFormulas( const COLLADAFW::Formulas* formulas )
{
	Data_Object<RubyImporter> wrappedRubyImporter(this, rb_cCImporter, nullptr, nullptr);
	wrappedRubyImporter.call("at_write_formulas");
	return true;
}

bool RubyImporter::writeKinematicsScene( const COLLADAFW::KinematicsScene* kinematicsScene )
{
	Data_Object<RubyImporter> wrappedRubyImporter(this, rb_cCImporter, nullptr, nullptr);
	wrappedRubyImporter.call("at_write_kinematics_scene");
	return true;
}

Data_Type<RubyImporter> rb_cCImporter;

void rb_define_CImporter()
{
	rb_cCImporter = rb_cOpenCOLLADA.define_class<RubyImporter, COLLADAFW::IWriter>("Importer");
	rb_cCImporter.define_constructor(
		Constructor<RubyImporter>()
	);
}

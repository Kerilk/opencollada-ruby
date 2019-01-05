require 'minitest/autorun'
require 'opencollada'

class OpenCOLLADATest < Minitest::Test

  def test_uniqid
    id1 = OpenCOLLADA::FW::UniqueId::new
    assert_equal "UniqueID(0,0,0)", id1.to_ascii
    refute id1.valid?
    id2 = OpenCOLLADA::FW::UniqueId::new(OpenCOLLADA::FW::ClassId::GEOMETRY, 2, 5)
    assert id2.valid?
    assert_equal OpenCOLLADA::FW::ClassId::GEOMETRY, id2.class_id
    assert_equal 2, id2.object_id
    assert_equal 5, id2.file_id
    refute_equal id1, id2
    id1.from_ascii(id2.to_ascii)
    assert_equal id1, id2
  end

  def test_floatarray
    arr = OpenCOLLADA::FW::FloatArray::new
    assert_equal 0, arr.count
    assert_equal 0, arr.capacity
    arr.data = a = NArray::sfloat(42).random!
    assert_equal 42, arr.count
    b = arr.data
    assert_equal a, b
  end

  def test_floatordoublearray
    arr = OpenCOLLADA::FW::FloatOrDoubleArray::new
    assert_equal OpenCOLLADA::FW::FloatOrDoubleArray::DataType::DATA_TYPE_UNKNOWN, arr.type
    arr.type = OpenCOLLADA::FW::FloatOrDoubleArray::DataType::DATA_TYPE_FLOAT
    assert_equal OpenCOLLADA::FW::FloatOrDoubleArray::DataType::DATA_TYPE_FLOAT, arr.type
    assert_equal 0, arr.values_count
    farr = arr.get_values
    assert_equal OpenCOLLADA::FW::FloatArray, farr.class
    assert_equal 0, farr.count
    assert_equal 0, farr.capacity
  end

  def test_geometry
    geo = OpenCOLLADA::FW::Geometry::new(OpenCOLLADA::FW::UniqueId::new(OpenCOLLADA::FW::ClassId::GEOMETRY, 2, 5), OpenCOLLADA::FW::Geometry::GeometryType::GEO_TYPE_MESH)
    assert_equal OpenCOLLADA::FW::UniqueId::new(OpenCOLLADA::FW::ClassId::GEOMETRY, 2, 5), geo.unique_id
    assert_equal OpenCOLLADA::FW::Geometry::GeometryType::GEO_TYPE_MESH, geo.type

  end

  def test_animatable
    anim = OpenCOLLADA::FW::Animatable::new
    assert_equal OpenCOLLADA::FW::UniqueId::new, anim.animation_list
    anim.animation_list = OpenCOLLADA::FW::UniqueId::new(OpenCOLLADA::FW::ClassId::ANIMATIONLIST, 2, 5)
    assert_equal OpenCOLLADA::FW::UniqueId::new(OpenCOLLADA::FW::ClassId::ANIMATIONLIST, 2, 5), anim.animation_list
  end

  def test_meshvertexdata
    d = OpenCOLLADA::FW::MeshVertexData::new
    assert_equal 0, d.num_inputs_info
  end

  def test_meshprimitive
    p = OpenCOLLADA::FW::MeshPrimitive::new(OpenCOLLADA::FW::UniqueId::new(OpenCOLLADA::FW::ClassId::PRIMITIVE_ELEMENT, 2, 5))
  end

end

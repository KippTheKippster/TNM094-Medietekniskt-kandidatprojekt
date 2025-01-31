#include "open_cv_instance.h"
#include <godot_cpp/core/class_db.hpp>
#include <opencv2/opencv.hpp>

using namespace godot;

void OpenCVInstance::_bind_methods() {
	//ClassDB::bind_method(D_METHOD("get_input_array"), &OpenCVInstance::get_input_array);
	//ClassDB::bind_method(D_METHOD("set_input_array"), &OpenCVInstance::set_input_array);

	//ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "input_array"), "set_input_array", "get_input_array");

	ClassDB::bind_method(D_METHOD("capture_camera"), &OpenCVInstance::capture_camera);
}

OpenCVInstance::OpenCVInstance() {
	// Initialize any variables here.
	time_passed = 0.0;
	capture.open(0, cv::CAP_DSHOW);
}

OpenCVInstance::~OpenCVInstance() {
	// Add your cleanup here.
	capture.release();
	input_array.clear();
}

void OpenCVInstance::_ready() {
	cv::Mat image;
	std::cout << "image.empty(): " << image.empty() << '\n';
}

void OpenCVInstance::_process(double delta) {
	time_passed += delta;

	//Vector2 new_position = Vector2(10.0 + (10.0 * sin(time_passed * 2.0)), 10.0 + (10.0 * cos(time_passed * 1.5)));

	//set_position(new_position);
	/*
	capture >> input_matrix;
	//std::cout << input_matrix.empty() << "\n";

	input_array.clear();

	for (int i = 0; i < input_matrix.size[0]; i++)
	{
		input_array.append(Array());
		for (int j = 0; j < input_matrix.size[1]; j++)
		{
			Array array = input_array[i];
			array.append(input_matrix.at<float>(i, j));
		}
	}
	*/
}

void OpenCVInstance::capture_camera()
{
	capture >> input_matrix;
	std::cout << "Camera Captured!";
}

Array OpenCVInstance::get_input_array() const
{
	return input_array;
}

void OpenCVInstance::set_input_array()
{

}
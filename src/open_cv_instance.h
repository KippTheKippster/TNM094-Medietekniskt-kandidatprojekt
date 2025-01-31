#ifndef OPEN_CV_GODOT_H
#define OPEN_CV_GODOT_H

#include <godot_cpp/classes/sprite2d.hpp>
#include <opencv2/opencv.hpp>

namespace godot {

class OpenCVInstance : public Node {
	GDCLASS(OpenCVInstance, Node)

private:
	double time_passed;
	Array input_array;
	cv::Mat input_matrix;
	cv::VideoCapture capture;

protected:
	static void _bind_methods();

public:
	OpenCVInstance();
	~OpenCVInstance();

	void _ready() override;
	void _process(double delta) override;

	Array get_input_array() const;
	void set_input_array();
	void capture_camera();
};

}

#endif 
extends Node3D

@onready var open_cv_instance: OpenCVInstance = $OpenCVInstance

@onready var label: Label = $UiLayer/Label

var time_elapsed: float = 0.0

var open_cv_thread: Thread
var open_cv_mutex: Mutex
var exited_tree: bool = false

func _ready() -> void:
	open_cv_mutex = Mutex.new()
	open_cv_thread = Thread.new()
	open_cv_thread.start(start_capture_camera, Thread.PRIORITY_HIGH)


func start_capture_camera() -> void:
	while true:
		open_cv_mutex.lock()
		var should_exit := exited_tree
		open_cv_mutex.unlock()
		if should_exit:
			break
		
		open_cv_instance.capture_camera()
		print("Camera Captured!")

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	label.text = str(time_elapsed)
	time_elapsed += delta
	#open_cv_instance.capture_camera()


func _exit_tree() -> void:
	exited_tree = true
	open_cv_thread.wait_to_finish()

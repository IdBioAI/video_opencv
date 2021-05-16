/*#include "pch.h"
#include "init.h"
#include <iostream>

// OpenGL Extension Wrangler
#include <GL/glew.h> 
#include <GL/wglew.h> //WGLEW = Windows GL Extension Wrangler (change for different platform) 

// GLFW toolkit
#include <GLFW/glfw3.h>

// OpenGL math
#include <glm/glm.hpp>

// OpenGL textures
#include <gli/gli.hpp>

#include <GLFW/glfw3.h>

struct s_globals {
	GLFWwindow* window;
	int height;
	int width;
	double app_start_time;
};

s_globals globals;
static void error_callback(int error, const char* description);
static void finalize(int value);

init::initOpenCV::initOpenCV()
{
}

void init::initOpenCV::init_glfw()
{
	//
// GLFW init.
//

	// set error callback first
	glfwSetErrorCallback(error_callback);

	//initialize GLFW library
	int glfw_ret = glfwInit();
	if (!glfw_ret)
	{
		std::cerr << "GLFW init failed." << std::endl;
		finalize(EXIT_FAILURE);
	}

	// Shader based, modern OpenGL (3.3 and higher)
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // only new functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE); // only old functions (for old tutorials etc.)

	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	globals.window = glfwCreateWindow(800, 600, "OpenGL context", NULL, NULL);
	if (!globals.window)
	{
		std::cerr << "GLFW window creation error." << std::endl;
		finalize(EXIT_FAILURE);
	}

	// Get some GLFW info.
	{
		int major, minor, revision;

		glfwGetVersion(&major, &minor, &revision);
		std::cout << "Running GLFW " << major << '.' << minor << '.' << revision << std::endl;
		std::cout << "Compiled against GLFW " << GLFW_VERSION_MAJOR << '.' << GLFW_VERSION_MINOR << '.' << GLFW_VERSION_REVISION << std::endl;
	}

	glfwMakeContextCurrent(globals.window);										// Set current window.
	glfwGetFramebufferSize(globals.window, &globals.width, &globals.height);	// Get window size.
	//glfwSwapInterval(0);														// Set V-Sync OFF.
	glfwSwapInterval(1);														// Set V-Sync ON.


	globals.app_start_time = glfwGetTime();										// Get start time.
}

void init::initOpenCV::init_glew()
{
	//
// Initialize all valid GL extensions with GLEW.
// Usable AFTER creating GL context!
//
	{
		GLenum glew_ret;
		glew_ret = glewInit();
		if (glew_ret != GLEW_OK)
		{
			std::cerr << "WGLEW failed with error: " << glewGetErrorString(glew_ret) << std::endl;
			finalize(EXIT_FAILURE);
		}
		else
		{
			std::cout << "GLEW successfully initialized to version: " << glewGetString(GLEW_VERSION) << std::endl;
		}

		// Platform specific. (Change to GLXEW or ELGEW if necessary.)
		glew_ret = wglewInit();
		if (glew_ret != GLEW_OK)
		{
			std::cerr << "WGLEW failed with error: " << glewGetErrorString(glew_ret) << std::endl;
			finalize(EXIT_FAILURE);
		}
		else
		{
			std::cout << "WGLEW successfully initialized platform specific functions." << std::endl;
		}
	}
}

void init::initOpenCV::gl_print_info()
{
	// Get OpenGL driver info
	{
		const char* vendor_s = (const char*)glGetString(GL_VENDOR);
		const char* renderer_s = (const char*)glGetString(GL_RENDERER);
		const char* version_s = (const char*)glGetString(GL_VERSION);
		const char* glsl_s = (const char*)glGetString(GL_SHADING_LANGUAGE_VERSION);

		std::cout << "OpenGL driver vendor: " << (vendor_s == nullptr ? "<UNKNOWN>" : vendor_s) << ", renderer: " << (renderer_s == nullptr ? "<UNKNOWN>" : renderer_s) << ", version: " << (version_s == nullptr ? "<UNKNOWN>" : version_s) << std::endl;

		GLint profile_flags;
		glGetIntegerv(GL_CONTEXT_PROFILE_MASK, &profile_flags);
		std::cout << "Current profile: ";
		if (profile_flags & GL_CONTEXT_CORE_PROFILE_BIT)
			std::cout << "CORE";
		else
			std::cout << "COMPATIBILITY";
		std::cout << std::endl;

		GLint context_flags;
		glGetIntegerv(GL_CONTEXT_FLAGS, &context_flags);
		std::cout << "Active context flags: ";
		if (context_flags & GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT)
			std::cout << "GL_CONTEXT_FLAG_FORWARD_COMPATIBLE_BIT ";
		if (context_flags & GL_CONTEXT_FLAG_DEBUG_BIT)
			std::cout << "GL_CONTEXT_FLAG_DEBUG_BIT ";
		if (context_flags & GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT)
			std::cout << "GL_CONTEXT_FLAG_ROBUST_ACCESS_BIT ";
		if (context_flags & GL_CONTEXT_FLAG_NO_ERROR_BIT)
			std::cout << "GL_CONTEXT_FLAG_NO_ERROR_BIT";
		std::cout << std::endl;

		std::cout << "Primary GLSL shading language version: " << (glsl_s == nullptr ? "<UNKNOWN>" : glsl_s) << std::endl;
	}

	//
	// GLM & GLI library
	//

	std::cout << "GLM version: " << GLM_VERSION_MAJOR << '.' << GLM_VERSION_MINOR << '.' << GLM_VERSION_PATCH << "rev" << GLM_VERSION_REVISION << std::endl;
	std::cout << "GLI version: " << GLI_VERSION_MAJOR << '.' << GLI_VERSION_MINOR << '.' << GLI_VERSION_PATCH << "rev" << GLI_VERSION_REVISION << std::endl;
}

static void finalize(int code)
{
	// ...

	// Close OpenGL window if opened and terminate GLFW  
	if (globals.window)
		glfwDestroyWindow(globals.window);
	glfwTerminate();

	// ...
}


//=====================================================================================================
static void error_callback(int error, const char* description)
{
	std::cerr << "Error: " << description << std::endl;
}*/
//=====================================================================================================
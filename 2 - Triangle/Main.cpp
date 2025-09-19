#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

int main()
{
    // Initialize GLFW
    glfwInit();

    // Tell GLFW what version of OpenGL we are using
    // We are using OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Tell GLFW we are using the CORE profile
    // This means we only have the modern functions
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create a GLFWwindow object of 800x600 pixels with a name
    GLFWwindow *window = glfwCreateWindow(800, 600, "LearnOpenGL", NULL, NULL);
    // Exercise 2 - change size of the window to w=400, h=225
    // Exercise 3 - Change name of window to "I made this!"
    // GLFWwindow *window = glfwCreateWindow(400, 225, "I made this!", NULL, NULL);
    // Check if window fails to create
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    // Add window to current context
    glfwMakeContextCurrent(window);

    // Load GLAD so it configures OpenGL
    gladLoadGL();
    // Specify the viewport of OpenGl in the Window
    // x = 0, y = 0 to x = 800, y = 600
    glViewport(0, 0, 800, 600);
    // glViewport(0, 0, 400, 225);

    // Specify the color of the background
    // glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
    // Exercise 1 - Change color to orange
    // glClearColor(1.0f, 0.55f, 0.0f, 1.0f);
    // Clean the back buffer and assign a new color to it
    // glClear(GL_COLOR_BUFFER_BIT);
    // Swap the back buffer with the front buffer
    // glfwSwapBuffers(window);

    // Hard Exercise 1
    // Flucuate between variety of colors
    float prev_time = float(glfwGetTime()); // Keep track of previous time
    float angle = 0.0f;                     // control the color

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        float time = float(glfwGetTime());
        if (time - prev_time >= 0.05f) // every 0.1 seconds it's true
        {
            angle += 0.1f;    // change angle to change color
            prev_time = time; // update previous time
        }
        // Use trig to change colors
        glClearColor(float(sin(angle)), float(cos(angle)), float(tan(angle)), 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        // Take care of all GLFW events
        glfwPollEvents();
    }

    // Delete window before ending the program
    glfwDestroyWindow(window);
    // Terminate GLFW before ending the program
    glfwTerminate();
    return 0;
}
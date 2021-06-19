#include <glad/glad.h>
#include <glad/glad.c>
//#include <glad/gl.h>
//#include <glad/gl.c>
#include <GLFW/glfw3.h>

#include <iostream>
using namespace std;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    if(!glfwInit())
    {
        cout << "Failed to Init GLFW" << endl;
        exit(EXIT_FAILURE);
        //return -1;
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    
    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT,
        "LearnOpenGL", NULL, NULL);
    if(window == NULL)
    {
        cout << "Failed to create GLFW window" << endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
        //return -1;
    }
    glfwMakeContextCurrent(window);    
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if(!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        cout << "Failed to initialize GLAD" << endl;
        return -1;
    }
    cout << "OpenGL Version: " << glGetString(GL_VERSION) << endl;

    // render loop
    // -----------
    while(!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // glfw: swap buffers and poll IO events (keys pressed/released, 
        // mouse moved etc.)
        // -------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwDestroyWindow(window);
    glfwTerminate();
    exit(EXIT_SUCCESS);
    //return 0;
}

// process all input: query GLFW whether relevant keys are 
// pressed/released this frame and react accordingly
// -----------------------------------------------------
void processInput(GLFWwindow* window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

// glfw: whenever the window size changed (by OS or user resize) 
// this callback function executes
// ------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; 
    // note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}
#include <stdio.h>
#include <stdlib.h>

//GLEW
#include <GL/glew.h>
//GLFW
#include <glfw3.h>
//GLM
#include <glm/glm.hpp>

using namespace glm;

GLFWwindow* window;

int main(){

    if(!glfwInit()){
        fprintf(stderr,"Failed to initializa GLFW\n");
        getchar();
        return -1;
    }
    
    //context
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window = glfwCreateWindow(1024, 768, "Tutorial 01", NULL, NULL);
    if(window == NULL){
        fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
        getchar();
        glfwTerminate();
        return -1;
        
    }
    
    glfwMakeContextCurrent(window);
    
    //start GLEWr
    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Failed to initialize GLEW\n");
        getchar();
        glfwTerminate();
        return -1;
    }
    
    //capture input
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
    
    //blue color
    glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
    
    do
    {
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 );
    
    glfwTerminate();
    
    return 0;
}

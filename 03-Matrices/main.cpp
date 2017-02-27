#include <stdio.h>
#include <stdlib.h>

//GLEW
#include <GL/glew.h>
//GLFW
#include <glfw3.h>
//GLM
#include <glm/glm.hpp>

#include <common/shader.hpp>

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
    
    // Initialize GLEW
    glewExperimental = true; // Needed for core profile
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
    
   	GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);
    
    //1.load shader files
    //create and compile GLSL program from the shaders
    GLuint programID = LoadShaders( "SimpleVertexShader.vertexshader",
                                   "SimpleFragmentShader.fragmentshader" );
    
    //2. define vertex
    static const GLfloat g_vertex_buffer_data[] = {
        -1.0f, -1.0f, 0.0f,
        1.0f, -1.0f, 0.0f,
        0.0f,  1.0f, 0.0f,
    };
    
    //3. create a buffer os vertex
    GLuint vertexbuffer;
    glGenBuffers(1, &vertexbuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
    
    
    do
    {
        //clear screen
        glClear(GL_COLOR_BUFFER_BIT);
        
        //use shader
        glUseProgram(programID);
        
        //4. apply buffer vertex
        // 1rst attribute buffer : vertices
        glEnableVertexAttribArray(0);
        glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
        glVertexAttribPointer(
                              0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
                              3,                  // size
                              GL_FLOAT,           // type
                              GL_FALSE,           // normalized?
                              0,                  // stride
                              (void*)0            // array buffer offset
                              );
        
        //draw triangle
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glDisableVertexAttribArray(0);
        
        //swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
        
    }
    while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(window) == 0 );
    
    //cleanup VBO
    glDeleteBuffers(1, &vertexbuffer);
    glDeleteVertexArrays(1,&VertexArrayID);
    glDeleteProgram(programID);
    
    glfwTerminate();
    
    return 0;
}

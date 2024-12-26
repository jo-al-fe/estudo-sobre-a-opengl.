#include"glad/glad.h"
#include"GLFW/glfw3.h"
#include"lib/shader.h"
#include<iostream>
int main(){
    int is,ic;
    char r[512];
    glfwInit();
    GLFWwindow* janela=glfwCreateWindow(400,400,"janela",NULL,NULL);
    glfwMakeContextCurrent(janela);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    //cordenadas do verteces
     Shader ourShader("3.3.shader.vs", "3.3.shader.fs");
    float verts[]={
        0.0f,0.5f,0.0f,  1.0f,0.0f,0.0f, //top direita
        -0.5f,-0.5f,0.0f, 1.0f,0.0f,0.0f,//direita
        0.5f,-0.5,0.0f,   1.0f,0.0f,0.0f//esqueda
    };
    
    //configura são do trianglo

    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verts), verts, GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // color attribute
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    while(!glfwWindowShouldClose(janela)){
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        ourShader.use();
        glBindVertexArray(VAO);
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(janela);
        glfwPollEvents();
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;
}
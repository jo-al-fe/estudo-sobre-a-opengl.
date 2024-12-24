#include"glad/glad.h"
#include"GLFW/glfw3.h"
#include<iostream>
const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";
int main(){
    int is,ic;
    char r[512];
    glfwInit();
    GLFWwindow* janela=glfwCreateWindow(400,400,"janela",NULL,NULL);
    glfwMakeContextCurrent(janela);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    //shader do vertece
    unsigned int vertexShader=glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &is);
    // shader da cor do vertece
    unsigned int fragmentShader=glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader ,1 ,&fragmentShaderSource,NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &ic);
    // unuficar os shaders
    unsigned int shaderProgram=glCreateProgram();
    glAttachShader(shaderProgram,vertexShader);
    glAttachShader(shaderProgram,fragmentShader);
    glLinkProgram(shaderProgram);    
    //cordenadas do verteces
    float verts[]={
        -0.5f,0.5f,0.0f,//top direita
        -0.5f,-0.5f,0.0f,//direita
        0.5f,-0.5,0.0f,//esqueda
        0.5f,0.5f,0.0f//top esqueda
    };
    unsigned int inds[]={
        0,1,2,//primeiro trianglo
        0,2,3//segundo triangloS
    };
    //configura são do trianglo
    unsigned int VBO,VAO,EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER,sizeof(verts),verts,GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(inds),inds,GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);
    //verifição
    if(!is){
        glGetShaderInfoLog(vertexShader,512,NULL,r);
        std::cout<<"erro::shade compiler"<<r<<'\n';
    }
     if(!ic){
        glGetShaderInfoLog(fragmentShader,512,NULL,r);
        std::cout<<"erro::shade compiler"<<r<<'\n';
    }
    while(!glfwWindowShouldClose(janela)){
        glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(janela);
        glfwPollEvents();
    }
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);
    glfwTerminate();
    return 0;
}
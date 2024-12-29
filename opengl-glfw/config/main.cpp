#include"glad/glad.h"
#include<GLFW/glfw3.h>
#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

//comfigurando o shader
std::string readLine(const char* caminho_arquivo){
    std::string codigoShader;
    std::ifstream arquivoShader;
    arquivoShader.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try{
        arquivoShader.open(caminho_arquivo);
        std::stringstream streamShader;
        streamShader<<arquivoShader.rdbuf();
        arquivoShader.close();
        codigoShader=streamShader.str();
    }catch(std::ifstream::failure e){
        std::cout<<"erro::leitura do arquivo"<<caminho_arquivo<<'\n';
    }
    return codigoShader;
}
int main(){
    //inicia o glfw
    glfwInit();
    GLFWwindow* janela=glfwCreateWindow(400,400,"janela",NULL,NULL);
    glfwMakeContextCurrent(janela);
    //inicia o glad
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    //caminho para vertex.glsl e fragment.glsl
    std::string codigoVertexShader=readLine("vertex.glsl");
    std::string codigoFragmentShader=readLine("fragment.glsl");
    const char* vShaderCode=codigoVertexShader.c_str();
    const char* fShaderCode=codigoFragmentShader.c_str();
    //configurando o vertexShader
    unsigned int vertexShader=glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vShaderCode, NULL);
    glCompileShader(vertexShader);
    //.. o fragmentShader
    unsigned int fragmentShader=glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fShaderCode, NULL);
    glCompileShader(fragmentShader);
    //.. o shaderProgama
    unsigned int shaderProgama=glCreateProgram();
    glAttachShader(shaderProgama, vertexShader);
    glAttachShader(shaderProgama, fragmentShader);
    glLinkProgram(shaderProgama);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    while(!glfwWindowShouldClose(janela)){
        glClearColor(0.0f,0.0f,1.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgama);
        glfwSwapBuffers(janela);
        glfwPollEvents();
    }
    glDeleteProgram(shaderProgama);
    glfwTerminate();
    return 0;
}
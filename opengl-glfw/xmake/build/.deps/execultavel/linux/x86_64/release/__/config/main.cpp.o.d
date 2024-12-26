{
    values = {
        "/usr/bin/gcc",
        {
            "-m64",
            "-DGLFW_INCLUDE_NONE",
            "-isystem",
            "/home/joao/.xmake/packages/g/glfw/3.4/4c3c72af70fd4599a3038fc662af9c28/include",
            "-isystem",
            "/usr/include/X11/dri",
            "-isystem",
            "/home/joao/.xmake/packages/g/glad/v0.1.36/f31cd39a27f14bdc8dd8413392e1ee53/include"
        }
    },
    files = {
        "../config/main.cpp"
    },
    depfiles_gcc = "main.o: ../config/main.cpp ../config/glad/glad.h  ../config/glad/khrplatform.h ../config/GLFW/glfw3.h  ../config/lib/shader.h ../config/lib/../glad/glad.h\
"
}
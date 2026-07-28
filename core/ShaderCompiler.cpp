#include "ShaderCompiler.h"

#include <mod/logger.h>

GLuint ShaderCompiler::Compile(GLenum type, const std::string& source)
{
    GLuint shader = glCreateShader(type);

    const char* src = source.c_str();
    glShaderSource(shader, 1, &src, nullptr);

    glCompileShader(shader);

    if(!Check(shader))
    {
        glDeleteShader(shader);
        return 0;
    }

    return shader;
}

bool ShaderCompiler::Check(GLuint shader)
{
    GLint success = 0;

    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

    if(success)
        return true;

    char log[2048];

    glGetShaderInfoLog(shader, sizeof(log), nullptr, log);

    logger->Error("%s", log);

    return false;
}

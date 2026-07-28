#include "ShaderProgram.h"

#include <mod/logger.h>

ShaderProgram::ShaderProgram()
{
    mProgram = 0;
}

ShaderProgram::~ShaderProgram()
{
    Destroy();
}

bool ShaderProgram::Link(GLuint vertex, GLuint fragment)
{
    mProgram = glCreateProgram();

    glAttachShader(mProgram, vertex);
    glAttachShader(mProgram, fragment);

    glLinkProgram(mProgram);

    GLint success = GL_FALSE;
    glGetProgramiv(mProgram, GL_LINK_STATUS, &success);

    if(success == GL_FALSE)
    {
        char log[2048];
        glGetProgramInfoLog(mProgram, sizeof(log), nullptr, log);

        logger->Error("%s", log);

        glDeleteProgram(mProgram);
        mProgram = 0;

        return false;
    }

    return true;
}

void ShaderProgram::Bind() const
{
    glUseProgram(mProgram);
}

GLuint ShaderProgram::GetID() const
{
    return mProgram;
}

void ShaderProgram::Destroy()
{
    if(mProgram)
    {
        glDeleteProgram(mProgram);
        mProgram = 0;
    }
}

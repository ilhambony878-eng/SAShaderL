#pragma once

#include <GLES3/gl3.h>

class ShaderProgram
{
public:
    ShaderProgram();
    ~ShaderProgram();

    bool Link(GLuint vertex, GLuint fragment);

    void Bind() const;

    GLuint GetID() const;

    void Destroy();

private:
    GLuint mProgram;
};

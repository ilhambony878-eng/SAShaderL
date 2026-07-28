#pragma once

#include <GLES3/gl3.h>
#include <string>

class ShaderCompiler
{
public:
    static GLuint Compile(GLenum type, const std::string& source);

private:
    static bool Check(GLuint shader);
};

// zzz

#version 450

#ifdef GL_ES
precision mediump float;
#endif

layout (location = 0) out vec4 outColor;

layout (push_constant) uniform Push
{
    vec2 offset;
    vec3 color;
} push;

void main()
{
    outColor = vec4(push.color, 1.0);
}

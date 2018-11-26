#ifdef GL_ES
// Set default precision to medium
precision mediump int;
precision mediump float;
#endif

uniform mat4 mvp_matrix;

attribute vec4 a_position;
attribute vec2 face_texcoord;
attribute vec2 back_texcoord;

varying vec2 v_face_tex_coord;
varying vec2 v_back_tex_coord;


void main()
{
    gl_Position = mvp_matrix * a_position;

    v_face_tex_coord = face_texcoord;
    v_back_tex_coord = back_texcoord;
}

#ifdef GL_ES
// Set default precision to medium
precision mediump int;
precision mediump float;
#endif

uniform sampler2D face_texture;
uniform sampler2D back_texture;

varying vec2 v_face_tex_coord;
varying vec2 v_back_tex_coord;

void main()
{
    // Set fragment color from texture
    gl_FragColor = texture2D(back_texture, v_back_tex_coord);
    gl_FragColor = texture2D(face_texture, v_face_tex_coord);
}


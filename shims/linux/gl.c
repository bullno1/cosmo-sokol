#include <GL/gl.h>
#include <stddef.h>
#include <dlfcn.h>
#pragma GCC diagnostic ignored "-Warray-parameter"

static void* libgl = NULL;

static void (*proc_glAccum)(GLenum op, GLfloat value) = NULL;
static void (*proc_glActiveTexture)(GLenum texture) = NULL;
static void (*proc_glAlphaFunc)(GLenum func, GLfloat ref) = NULL;
static GLboolean (*proc_glAreTexturesResident)(GLsizei n, const GLuint * textures, GLboolean * residences) = NULL;
static void (*proc_glArrayElement)(GLint i) = NULL;
static void (*proc_glAttachShader)(GLuint program, GLuint shader) = NULL;
static void (*proc_glBegin)(GLenum mode) = NULL;
static void (*proc_glBeginConditionalRender)(GLuint id, GLenum mode) = NULL;
static void (*proc_glBeginQuery)(GLenum target, GLuint id) = NULL;
static void (*proc_glBeginQueryIndexed)(GLenum target, GLuint index, GLuint id) = NULL;
static void (*proc_glBeginTransformFeedback)(GLenum primitiveMode) = NULL;
static void (*proc_glBindAttribLocation)(GLuint program, GLuint index, const GLchar * name) = NULL;
static void (*proc_glBindBuffer)(GLenum target, GLuint buffer) = NULL;
static void (*proc_glBindBufferBase)(GLenum target, GLuint index, GLuint buffer) = NULL;
static void (*proc_glBindBufferRange)(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) = NULL;
static void (*proc_glBindFragDataLocation)(GLuint program, GLuint color, const GLchar * name) = NULL;
static void (*proc_glBindFragDataLocationIndexed)(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name) = NULL;
static void (*proc_glBindFramebuffer)(GLenum target, GLuint framebuffer) = NULL;
static void (*proc_glBindRenderbuffer)(GLenum target, GLuint renderbuffer) = NULL;
static void (*proc_glBindSampler)(GLuint unit, GLuint sampler) = NULL;
static void (*proc_glBindTexture)(GLenum target, GLuint texture) = NULL;
static void (*proc_glBindTransformFeedback)(GLenum target, GLuint id) = NULL;
static void (*proc_glBindVertexArray)(GLuint array) = NULL;
static void (*proc_glBitmap)(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap) = NULL;
static void (*proc_glBlendColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = NULL;
static void (*proc_glBlendEquation)(GLenum mode) = NULL;
static void (*proc_glBlendEquationSeparate)(GLenum modeRGB, GLenum modeAlpha) = NULL;
static void (*proc_glBlendEquationSeparatei)(GLuint buf, GLenum modeRGB, GLenum modeAlpha) = NULL;
static void (*proc_glBlendEquationi)(GLuint buf, GLenum mode) = NULL;
static void (*proc_glBlendFunc)(GLenum sfactor, GLenum dfactor) = NULL;
static void (*proc_glBlendFuncSeparate)(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) = NULL;
static void (*proc_glBlendFuncSeparatei)(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) = NULL;
static void (*proc_glBlendFunci)(GLuint buf, GLenum src, GLenum dst) = NULL;
static void (*proc_glBlitFramebuffer)(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) = NULL;
static void (*proc_glBufferData)(GLenum target, GLsizeiptr size, const void * data, GLenum usage) = NULL;
static void (*proc_glBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, const void * data) = NULL;
static void (*proc_glCallList)(GLuint list) = NULL;
static void (*proc_glCallLists)(GLsizei n, GLenum type, const void * lists) = NULL;
static GLenum (*proc_glCheckFramebufferStatus)(GLenum target) = NULL;
static void (*proc_glClampColor)(GLenum target, GLenum clamp) = NULL;
static void (*proc_glClear)(GLbitfield mask) = NULL;
static void (*proc_glClearAccum)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = NULL;
static void (*proc_glClearBufferfi)(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) = NULL;
static void (*proc_glClearBufferfv)(GLenum buffer, GLint drawbuffer, const GLfloat * value) = NULL;
static void (*proc_glClearBufferiv)(GLenum buffer, GLint drawbuffer, const GLint * value) = NULL;
static void (*proc_glClearBufferuiv)(GLenum buffer, GLint drawbuffer, const GLuint * value) = NULL;
static void (*proc_glClearColor)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = NULL;
static void (*proc_glClearDepth)(GLdouble depth) = NULL;
static void (*proc_glClearIndex)(GLfloat c) = NULL;
static void (*proc_glClearStencil)(GLint s) = NULL;
static void (*proc_glClientActiveTexture)(GLenum texture) = NULL;
static GLenum (*proc_glClientWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout) = NULL;
static void (*proc_glClipPlane)(GLenum plane, const GLdouble * equation) = NULL;
static void (*proc_glColor3b)(GLbyte red, GLbyte green, GLbyte blue) = NULL;
static void (*proc_glColor3bv)(const GLbyte * v) = NULL;
static void (*proc_glColor3d)(GLdouble red, GLdouble green, GLdouble blue) = NULL;
static void (*proc_glColor3dv)(const GLdouble * v) = NULL;
static void (*proc_glColor3f)(GLfloat red, GLfloat green, GLfloat blue) = NULL;
static void (*proc_glColor3fv)(const GLfloat * v) = NULL;
static void (*proc_glColor3i)(GLint red, GLint green, GLint blue) = NULL;
static void (*proc_glColor3iv)(const GLint * v) = NULL;
static void (*proc_glColor3s)(GLshort red, GLshort green, GLshort blue) = NULL;
static void (*proc_glColor3sv)(const GLshort * v) = NULL;
static void (*proc_glColor3ub)(GLubyte red, GLubyte green, GLubyte blue) = NULL;
static void (*proc_glColor3ubv)(const GLubyte * v) = NULL;
static void (*proc_glColor3ui)(GLuint red, GLuint green, GLuint blue) = NULL;
static void (*proc_glColor3uiv)(const GLuint * v) = NULL;
static void (*proc_glColor3us)(GLushort red, GLushort green, GLushort blue) = NULL;
static void (*proc_glColor3usv)(const GLushort * v) = NULL;
static void (*proc_glColor4b)(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) = NULL;
static void (*proc_glColor4bv)(const GLbyte * v) = NULL;
static void (*proc_glColor4d)(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) = NULL;
static void (*proc_glColor4dv)(const GLdouble * v) = NULL;
static void (*proc_glColor4f)(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) = NULL;
static void (*proc_glColor4fv)(const GLfloat * v) = NULL;
static void (*proc_glColor4i)(GLint red, GLint green, GLint blue, GLint alpha) = NULL;
static void (*proc_glColor4iv)(const GLint * v) = NULL;
static void (*proc_glColor4s)(GLshort red, GLshort green, GLshort blue, GLshort alpha) = NULL;
static void (*proc_glColor4sv)(const GLshort * v) = NULL;
static void (*proc_glColor4ub)(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) = NULL;
static void (*proc_glColor4ubv)(const GLubyte * v) = NULL;
static void (*proc_glColor4ui)(GLuint red, GLuint green, GLuint blue, GLuint alpha) = NULL;
static void (*proc_glColor4uiv)(const GLuint * v) = NULL;
static void (*proc_glColor4us)(GLushort red, GLushort green, GLushort blue, GLushort alpha) = NULL;
static void (*proc_glColor4usv)(const GLushort * v) = NULL;
static void (*proc_glColorMask)(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) = NULL;
static void (*proc_glColorMaski)(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) = NULL;
static void (*proc_glColorMaterial)(GLenum face, GLenum mode) = NULL;
static void (*proc_glColorP3ui)(GLenum type, GLuint color) = NULL;
static void (*proc_glColorP3uiv)(GLenum type, const GLuint * color) = NULL;
static void (*proc_glColorP4ui)(GLenum type, GLuint color) = NULL;
static void (*proc_glColorP4uiv)(GLenum type, const GLuint * color) = NULL;
static void (*proc_glColorPointer)(GLint size, GLenum type, GLsizei stride, const void * pointer) = NULL;
static void (*proc_glCompileShader)(GLuint shader) = NULL;
static void (*proc_glCompressedTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data) = NULL;
static void (*proc_glCompressedTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data) = NULL;
static void (*proc_glCompressedTexImage3D)(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data) = NULL;
static void (*proc_glCompressedTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data) = NULL;
static void (*proc_glCompressedTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data) = NULL;
static void (*proc_glCompressedTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data) = NULL;
static void (*proc_glCopyBufferSubData)(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) = NULL;
static void (*proc_glCopyPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) = NULL;
static void (*proc_glCopyTexImage1D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) = NULL;
static void (*proc_glCopyTexImage2D)(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) = NULL;
static void (*proc_glCopyTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) = NULL;
static void (*proc_glCopyTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
static void (*proc_glCopyTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
static GLuint (*proc_glCreateProgram)(void) = NULL;
static GLuint (*proc_glCreateShader)(GLenum type) = NULL;
static void (*proc_glCullFace)(GLenum mode) = NULL;
static void (*proc_glDeleteBuffers)(GLsizei n, const GLuint * buffers) = NULL;
static void (*proc_glDeleteFramebuffers)(GLsizei n, const GLuint * framebuffers) = NULL;
static void (*proc_glDeleteLists)(GLuint list, GLsizei range) = NULL;
static void (*proc_glDeleteProgram)(GLuint program) = NULL;
static void (*proc_glDeleteQueries)(GLsizei n, const GLuint * ids) = NULL;
static void (*proc_glDeleteRenderbuffers)(GLsizei n, const GLuint * renderbuffers) = NULL;
static void (*proc_glDeleteSamplers)(GLsizei count, const GLuint * samplers) = NULL;
static void (*proc_glDeleteShader)(GLuint shader) = NULL;
static void (*proc_glDeleteSync)(GLsync sync) = NULL;
static void (*proc_glDeleteTextures)(GLsizei n, const GLuint * textures) = NULL;
static void (*proc_glDeleteTransformFeedbacks)(GLsizei n, const GLuint * ids) = NULL;
static void (*proc_glDeleteVertexArrays)(GLsizei n, const GLuint * arrays) = NULL;
static void (*proc_glDepthFunc)(GLenum func) = NULL;
static void (*proc_glDepthMask)(GLboolean flag) = NULL;
static void (*proc_glDepthRange)(GLdouble n, GLdouble f) = NULL;
static void (*proc_glDetachShader)(GLuint program, GLuint shader) = NULL;
static void (*proc_glDisable)(GLenum cap) = NULL;
static void (*proc_glDisableClientState)(GLenum array) = NULL;
static void (*proc_glDisableVertexAttribArray)(GLuint index) = NULL;
static void (*proc_glDisablei)(GLenum target, GLuint index) = NULL;
static void (*proc_glDrawArrays)(GLenum mode, GLint first, GLsizei count) = NULL;
static void (*proc_glDrawArraysIndirect)(GLenum mode, const void * indirect) = NULL;
static void (*proc_glDrawArraysInstanced)(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) = NULL;
static void (*proc_glDrawBuffer)(GLenum buf) = NULL;
static void (*proc_glDrawBuffers)(GLsizei n, const GLenum * bufs) = NULL;
static void (*proc_glDrawElements)(GLenum mode, GLsizei count, GLenum type, const void * indices) = NULL;
static void (*proc_glDrawElementsBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex) = NULL;
static void (*proc_glDrawElementsIndirect)(GLenum mode, GLenum type, const void * indirect) = NULL;
static void (*proc_glDrawElementsInstanced)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount) = NULL;
static void (*proc_glDrawElementsInstancedBaseVertex)(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex) = NULL;
static void (*proc_glDrawPixels)(GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) = NULL;
static void (*proc_glDrawRangeElements)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices) = NULL;
static void (*proc_glDrawRangeElementsBaseVertex)(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex) = NULL;
static void (*proc_glDrawTransformFeedback)(GLenum mode, GLuint id) = NULL;
static void (*proc_glDrawTransformFeedbackStream)(GLenum mode, GLuint id, GLuint stream) = NULL;
static void (*proc_glEdgeFlag)(GLboolean flag) = NULL;
static void (*proc_glEdgeFlagPointer)(GLsizei stride, const void * pointer) = NULL;
static void (*proc_glEdgeFlagv)(const GLboolean * flag) = NULL;
static void (*proc_glEnable)(GLenum cap) = NULL;
static void (*proc_glEnableClientState)(GLenum array) = NULL;
static void (*proc_glEnableVertexAttribArray)(GLuint index) = NULL;
static void (*proc_glEnablei)(GLenum target, GLuint index) = NULL;
static void (*proc_glEnd)(void) = NULL;
static void (*proc_glEndConditionalRender)(void) = NULL;
static void (*proc_glEndList)(void) = NULL;
static void (*proc_glEndQuery)(GLenum target) = NULL;
static void (*proc_glEndQueryIndexed)(GLenum target, GLuint index) = NULL;
static void (*proc_glEndTransformFeedback)(void) = NULL;
static void (*proc_glEvalCoord1d)(GLdouble u) = NULL;
static void (*proc_glEvalCoord1dv)(const GLdouble * u) = NULL;
static void (*proc_glEvalCoord1f)(GLfloat u) = NULL;
static void (*proc_glEvalCoord1fv)(const GLfloat * u) = NULL;
static void (*proc_glEvalCoord2d)(GLdouble u, GLdouble v) = NULL;
static void (*proc_glEvalCoord2dv)(const GLdouble * u) = NULL;
static void (*proc_glEvalCoord2f)(GLfloat u, GLfloat v) = NULL;
static void (*proc_glEvalCoord2fv)(const GLfloat * u) = NULL;
static void (*proc_glEvalMesh1)(GLenum mode, GLint i1, GLint i2) = NULL;
static void (*proc_glEvalMesh2)(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) = NULL;
static void (*proc_glEvalPoint1)(GLint i) = NULL;
static void (*proc_glEvalPoint2)(GLint i, GLint j) = NULL;
static void (*proc_glFeedbackBuffer)(GLsizei size, GLenum type, GLfloat * buffer) = NULL;
static GLsync (*proc_glFenceSync)(GLenum condition, GLbitfield flags) = NULL;
static void (*proc_glFinish)(void) = NULL;
static void (*proc_glFlush)(void) = NULL;
static void (*proc_glFlushMappedBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length) = NULL;
static void (*proc_glFogCoordPointer)(GLenum type, GLsizei stride, const void * pointer) = NULL;
static void (*proc_glFogCoordd)(GLdouble coord) = NULL;
static void (*proc_glFogCoorddv)(const GLdouble * coord) = NULL;
static void (*proc_glFogCoordf)(GLfloat coord) = NULL;
static void (*proc_glFogCoordfv)(const GLfloat * coord) = NULL;
static void (*proc_glFogf)(GLenum pname, GLfloat param) = NULL;
static void (*proc_glFogfv)(GLenum pname, const GLfloat * params) = NULL;
static void (*proc_glFogi)(GLenum pname, GLint param) = NULL;
static void (*proc_glFogiv)(GLenum pname, const GLint * params) = NULL;
static void (*proc_glFramebufferRenderbuffer)(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) = NULL;
static void (*proc_glFramebufferTexture)(GLenum target, GLenum attachment, GLuint texture, GLint level) = NULL;
static void (*proc_glFramebufferTexture1D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) = NULL;
static void (*proc_glFramebufferTexture2D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) = NULL;
static void (*proc_glFramebufferTexture3D)(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) = NULL;
static void (*proc_glFramebufferTextureLayer)(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) = NULL;
static void (*proc_glFrontFace)(GLenum mode) = NULL;
static void (*proc_glFrustum)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) = NULL;
static void (*proc_glGenBuffers)(GLsizei n, GLuint * buffers) = NULL;
static void (*proc_glGenFramebuffers)(GLsizei n, GLuint * framebuffers) = NULL;
static GLuint (*proc_glGenLists)(GLsizei range) = NULL;
static void (*proc_glGenQueries)(GLsizei n, GLuint * ids) = NULL;
static void (*proc_glGenRenderbuffers)(GLsizei n, GLuint * renderbuffers) = NULL;
static void (*proc_glGenSamplers)(GLsizei count, GLuint * samplers) = NULL;
static void (*proc_glGenTextures)(GLsizei n, GLuint * textures) = NULL;
static void (*proc_glGenTransformFeedbacks)(GLsizei n, GLuint * ids) = NULL;
static void (*proc_glGenVertexArrays)(GLsizei n, GLuint * arrays) = NULL;
static void (*proc_glGenerateMipmap)(GLenum target) = NULL;
static void (*proc_glGetActiveAttrib)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) = NULL;
static void (*proc_glGetActiveSubroutineName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name) = NULL;
static void (*proc_glGetActiveSubroutineUniformName)(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name) = NULL;
static void (*proc_glGetActiveSubroutineUniformiv)(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values) = NULL;
static void (*proc_glGetActiveUniform)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) = NULL;
static void (*proc_glGetActiveUniformBlockName)(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName) = NULL;
static void (*proc_glGetActiveUniformBlockiv)(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetActiveUniformName)(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName) = NULL;
static void (*proc_glGetActiveUniformsiv)(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetAttachedShaders)(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders) = NULL;
static GLint (*proc_glGetAttribLocation)(GLuint program, const GLchar * name) = NULL;
static void (*proc_glGetBooleani_v)(GLenum target, GLuint index, GLboolean * data) = NULL;
static void (*proc_glGetBooleanv)(GLenum pname, GLboolean * data) = NULL;
static void (*proc_glGetBufferParameteri64v)(GLenum target, GLenum pname, GLint64 * params) = NULL;
static void (*proc_glGetBufferParameteriv)(GLenum target, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetBufferPointerv)(GLenum target, GLenum pname, void ** params) = NULL;
static void (*proc_glGetBufferSubData)(GLenum target, GLintptr offset, GLsizeiptr size, void * data) = NULL;
static void (*proc_glGetClipPlane)(GLenum plane, GLdouble * equation) = NULL;
static void (*proc_glGetCompressedTexImage)(GLenum target, GLint level, void * img) = NULL;
static void (*proc_glGetDoublev)(GLenum pname, GLdouble * data) = NULL;
static GLenum (*proc_glGetError)(void) = NULL;
static void (*proc_glGetFloatv)(GLenum pname, GLfloat * data) = NULL;
static GLint (*proc_glGetFragDataIndex)(GLuint program, const GLchar * name) = NULL;
static GLint (*proc_glGetFragDataLocation)(GLuint program, const GLchar * name) = NULL;
static void (*proc_glGetFramebufferAttachmentParameteriv)(GLenum target, GLenum attachment, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetInteger64i_v)(GLenum target, GLuint index, GLint64 * data) = NULL;
static void (*proc_glGetInteger64v)(GLenum pname, GLint64 * data) = NULL;
static void (*proc_glGetIntegeri_v)(GLenum target, GLuint index, GLint * data) = NULL;
static void (*proc_glGetIntegerv)(GLenum pname, GLint * data) = NULL;
static void (*proc_glGetLightfv)(GLenum light, GLenum pname, GLfloat * params) = NULL;
static void (*proc_glGetLightiv)(GLenum light, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetMapdv)(GLenum target, GLenum query, GLdouble * v) = NULL;
static void (*proc_glGetMapfv)(GLenum target, GLenum query, GLfloat * v) = NULL;
static void (*proc_glGetMapiv)(GLenum target, GLenum query, GLint * v) = NULL;
static void (*proc_glGetMaterialfv)(GLenum face, GLenum pname, GLfloat * params) = NULL;
static void (*proc_glGetMaterialiv)(GLenum face, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetMultisamplefv)(GLenum pname, GLuint index, GLfloat * val) = NULL;
static void (*proc_glGetPixelMapfv)(GLenum map, GLfloat * values) = NULL;
static void (*proc_glGetPixelMapuiv)(GLenum map, GLuint * values) = NULL;
static void (*proc_glGetPixelMapusv)(GLenum map, GLushort * values) = NULL;
static void (*proc_glGetPointerv)(GLenum pname, void ** params) = NULL;
static void (*proc_glGetPolygonStipple)(GLubyte * mask) = NULL;
static void (*proc_glGetProgramInfoLog)(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog) = NULL;
static void (*proc_glGetProgramStageiv)(GLuint program, GLenum shadertype, GLenum pname, GLint * values) = NULL;
static void (*proc_glGetProgramiv)(GLuint program, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetQueryIndexediv)(GLenum target, GLuint index, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetQueryObjecti64v)(GLuint id, GLenum pname, GLint64 * params) = NULL;
static void (*proc_glGetQueryObjectiv)(GLuint id, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetQueryObjectui64v)(GLuint id, GLenum pname, GLuint64 * params) = NULL;
static void (*proc_glGetQueryObjectuiv)(GLuint id, GLenum pname, GLuint * params) = NULL;
static void (*proc_glGetQueryiv)(GLenum target, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetRenderbufferParameteriv)(GLenum target, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetSamplerParameterIiv)(GLuint sampler, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetSamplerParameterIuiv)(GLuint sampler, GLenum pname, GLuint * params) = NULL;
static void (*proc_glGetSamplerParameterfv)(GLuint sampler, GLenum pname, GLfloat * params) = NULL;
static void (*proc_glGetSamplerParameteriv)(GLuint sampler, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetShaderInfoLog)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog) = NULL;
static void (*proc_glGetShaderSource)(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source) = NULL;
static void (*proc_glGetShaderiv)(GLuint shader, GLenum pname, GLint * params) = NULL;
static const GLubyte * (*proc_glGetString)(GLenum name) = NULL;
static const GLubyte * (*proc_glGetStringi)(GLenum name, GLuint index) = NULL;
static GLuint (*proc_glGetSubroutineIndex)(GLuint program, GLenum shadertype, const GLchar * name) = NULL;
static GLint (*proc_glGetSubroutineUniformLocation)(GLuint program, GLenum shadertype, const GLchar * name) = NULL;
static void (*proc_glGetSynciv)(GLsync sync, GLenum pname, GLsizei count, GLsizei * length, GLint * values) = NULL;
static void (*proc_glGetTexEnvfv)(GLenum target, GLenum pname, GLfloat * params) = NULL;
static void (*proc_glGetTexEnviv)(GLenum target, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetTexGendv)(GLenum coord, GLenum pname, GLdouble * params) = NULL;
static void (*proc_glGetTexGenfv)(GLenum coord, GLenum pname, GLfloat * params) = NULL;
static void (*proc_glGetTexGeniv)(GLenum coord, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetTexImage)(GLenum target, GLint level, GLenum format, GLenum type, void * pixels) = NULL;
static void (*proc_glGetTexLevelParameterfv)(GLenum target, GLint level, GLenum pname, GLfloat * params) = NULL;
static void (*proc_glGetTexLevelParameteriv)(GLenum target, GLint level, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetTexParameterIiv)(GLenum target, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetTexParameterIuiv)(GLenum target, GLenum pname, GLuint * params) = NULL;
static void (*proc_glGetTexParameterfv)(GLenum target, GLenum pname, GLfloat * params) = NULL;
static void (*proc_glGetTexParameteriv)(GLenum target, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetTransformFeedbackVarying)(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name) = NULL;
static GLuint (*proc_glGetUniformBlockIndex)(GLuint program, const GLchar * uniformBlockName) = NULL;
static void (*proc_glGetUniformIndices)(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices) = NULL;
static GLint (*proc_glGetUniformLocation)(GLuint program, const GLchar * name) = NULL;
static void (*proc_glGetUniformSubroutineuiv)(GLenum shadertype, GLint location, GLuint * params) = NULL;
static void (*proc_glGetUniformdv)(GLuint program, GLint location, GLdouble * params) = NULL;
static void (*proc_glGetUniformfv)(GLuint program, GLint location, GLfloat * params) = NULL;
static void (*proc_glGetUniformiv)(GLuint program, GLint location, GLint * params) = NULL;
static void (*proc_glGetUniformuiv)(GLuint program, GLint location, GLuint * params) = NULL;
static void (*proc_glGetVertexAttribIiv)(GLuint index, GLenum pname, GLint * params) = NULL;
static void (*proc_glGetVertexAttribIuiv)(GLuint index, GLenum pname, GLuint * params) = NULL;
static void (*proc_glGetVertexAttribPointerv)(GLuint index, GLenum pname, void ** pointer) = NULL;
static void (*proc_glGetVertexAttribdv)(GLuint index, GLenum pname, GLdouble * params) = NULL;
static void (*proc_glGetVertexAttribfv)(GLuint index, GLenum pname, GLfloat * params) = NULL;
static void (*proc_glGetVertexAttribiv)(GLuint index, GLenum pname, GLint * params) = NULL;
static void (*proc_glHint)(GLenum target, GLenum mode) = NULL;
static void (*proc_glIndexMask)(GLuint mask) = NULL;
static void (*proc_glIndexPointer)(GLenum type, GLsizei stride, const void * pointer) = NULL;
static void (*proc_glIndexd)(GLdouble c) = NULL;
static void (*proc_glIndexdv)(const GLdouble * c) = NULL;
static void (*proc_glIndexf)(GLfloat c) = NULL;
static void (*proc_glIndexfv)(const GLfloat * c) = NULL;
static void (*proc_glIndexi)(GLint c) = NULL;
static void (*proc_glIndexiv)(const GLint * c) = NULL;
static void (*proc_glIndexs)(GLshort c) = NULL;
static void (*proc_glIndexsv)(const GLshort * c) = NULL;
static void (*proc_glIndexub)(GLubyte c) = NULL;
static void (*proc_glIndexubv)(const GLubyte * c) = NULL;
static void (*proc_glInitNames)(void) = NULL;
static void (*proc_glInterleavedArrays)(GLenum format, GLsizei stride, const void * pointer) = NULL;
static GLboolean (*proc_glIsBuffer)(GLuint buffer) = NULL;
static GLboolean (*proc_glIsEnabled)(GLenum cap) = NULL;
static GLboolean (*proc_glIsEnabledi)(GLenum target, GLuint index) = NULL;
static GLboolean (*proc_glIsFramebuffer)(GLuint framebuffer) = NULL;
static GLboolean (*proc_glIsList)(GLuint list) = NULL;
static GLboolean (*proc_glIsProgram)(GLuint program) = NULL;
static GLboolean (*proc_glIsQuery)(GLuint id) = NULL;
static GLboolean (*proc_glIsRenderbuffer)(GLuint renderbuffer) = NULL;
static GLboolean (*proc_glIsSampler)(GLuint sampler) = NULL;
static GLboolean (*proc_glIsShader)(GLuint shader) = NULL;
static GLboolean (*proc_glIsSync)(GLsync sync) = NULL;
static GLboolean (*proc_glIsTexture)(GLuint texture) = NULL;
static GLboolean (*proc_glIsTransformFeedback)(GLuint id) = NULL;
static GLboolean (*proc_glIsVertexArray)(GLuint array) = NULL;
static void (*proc_glLightModelf)(GLenum pname, GLfloat param) = NULL;
static void (*proc_glLightModelfv)(GLenum pname, const GLfloat * params) = NULL;
static void (*proc_glLightModeli)(GLenum pname, GLint param) = NULL;
static void (*proc_glLightModeliv)(GLenum pname, const GLint * params) = NULL;
static void (*proc_glLightf)(GLenum light, GLenum pname, GLfloat param) = NULL;
static void (*proc_glLightfv)(GLenum light, GLenum pname, const GLfloat * params) = NULL;
static void (*proc_glLighti)(GLenum light, GLenum pname, GLint param) = NULL;
static void (*proc_glLightiv)(GLenum light, GLenum pname, const GLint * params) = NULL;
static void (*proc_glLineStipple)(GLint factor, GLushort pattern) = NULL;
static void (*proc_glLineWidth)(GLfloat width) = NULL;
static void (*proc_glLinkProgram)(GLuint program) = NULL;
static void (*proc_glListBase)(GLuint base) = NULL;
static void (*proc_glLoadIdentity)(void) = NULL;
static void (*proc_glLoadMatrixd)(const GLdouble * m) = NULL;
static void (*proc_glLoadMatrixf)(const GLfloat * m) = NULL;
static void (*proc_glLoadName)(GLuint name) = NULL;
static void (*proc_glLoadTransposeMatrixd)(const GLdouble * m) = NULL;
static void (*proc_glLoadTransposeMatrixf)(const GLfloat * m) = NULL;
static void (*proc_glLogicOp)(GLenum opcode) = NULL;
static void (*proc_glMap1d)(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points) = NULL;
static void (*proc_glMap1f)(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points) = NULL;
static void (*proc_glMap2d)(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points) = NULL;
static void (*proc_glMap2f)(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points) = NULL;
static void * (*proc_glMapBuffer)(GLenum target, GLenum access) = NULL;
static void * (*proc_glMapBufferRange)(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) = NULL;
static void (*proc_glMapGrid1d)(GLint un, GLdouble u1, GLdouble u2) = NULL;
static void (*proc_glMapGrid1f)(GLint un, GLfloat u1, GLfloat u2) = NULL;
static void (*proc_glMapGrid2d)(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) = NULL;
static void (*proc_glMapGrid2f)(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) = NULL;
static void (*proc_glMaterialf)(GLenum face, GLenum pname, GLfloat param) = NULL;
static void (*proc_glMaterialfv)(GLenum face, GLenum pname, const GLfloat * params) = NULL;
static void (*proc_glMateriali)(GLenum face, GLenum pname, GLint param) = NULL;
static void (*proc_glMaterialiv)(GLenum face, GLenum pname, const GLint * params) = NULL;
static void (*proc_glMatrixMode)(GLenum mode) = NULL;
static void (*proc_glMinSampleShading)(GLfloat value) = NULL;
static void (*proc_glMultMatrixd)(const GLdouble * m) = NULL;
static void (*proc_glMultMatrixf)(const GLfloat * m) = NULL;
static void (*proc_glMultTransposeMatrixd)(const GLdouble * m) = NULL;
static void (*proc_glMultTransposeMatrixf)(const GLfloat * m) = NULL;
static void (*proc_glMultiDrawArrays)(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount) = NULL;
static void (*proc_glMultiDrawElements)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount) = NULL;
static void (*proc_glMultiDrawElementsBaseVertex)(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex) = NULL;
static void (*proc_glMultiTexCoord1d)(GLenum target, GLdouble s) = NULL;
static void (*proc_glMultiTexCoord1dv)(GLenum target, const GLdouble * v) = NULL;
static void (*proc_glMultiTexCoord1f)(GLenum target, GLfloat s) = NULL;
static void (*proc_glMultiTexCoord1fv)(GLenum target, const GLfloat * v) = NULL;
static void (*proc_glMultiTexCoord1i)(GLenum target, GLint s) = NULL;
static void (*proc_glMultiTexCoord1iv)(GLenum target, const GLint * v) = NULL;
static void (*proc_glMultiTexCoord1s)(GLenum target, GLshort s) = NULL;
static void (*proc_glMultiTexCoord1sv)(GLenum target, const GLshort * v) = NULL;
static void (*proc_glMultiTexCoord2d)(GLenum target, GLdouble s, GLdouble t) = NULL;
static void (*proc_glMultiTexCoord2dv)(GLenum target, const GLdouble * v) = NULL;
static void (*proc_glMultiTexCoord2f)(GLenum target, GLfloat s, GLfloat t) = NULL;
static void (*proc_glMultiTexCoord2fv)(GLenum target, const GLfloat * v) = NULL;
static void (*proc_glMultiTexCoord2i)(GLenum target, GLint s, GLint t) = NULL;
static void (*proc_glMultiTexCoord2iv)(GLenum target, const GLint * v) = NULL;
static void (*proc_glMultiTexCoord2s)(GLenum target, GLshort s, GLshort t) = NULL;
static void (*proc_glMultiTexCoord2sv)(GLenum target, const GLshort * v) = NULL;
static void (*proc_glMultiTexCoord3d)(GLenum target, GLdouble s, GLdouble t, GLdouble r) = NULL;
static void (*proc_glMultiTexCoord3dv)(GLenum target, const GLdouble * v) = NULL;
static void (*proc_glMultiTexCoord3f)(GLenum target, GLfloat s, GLfloat t, GLfloat r) = NULL;
static void (*proc_glMultiTexCoord3fv)(GLenum target, const GLfloat * v) = NULL;
static void (*proc_glMultiTexCoord3i)(GLenum target, GLint s, GLint t, GLint r) = NULL;
static void (*proc_glMultiTexCoord3iv)(GLenum target, const GLint * v) = NULL;
static void (*proc_glMultiTexCoord3s)(GLenum target, GLshort s, GLshort t, GLshort r) = NULL;
static void (*proc_glMultiTexCoord3sv)(GLenum target, const GLshort * v) = NULL;
static void (*proc_glMultiTexCoord4d)(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) = NULL;
static void (*proc_glMultiTexCoord4dv)(GLenum target, const GLdouble * v) = NULL;
static void (*proc_glMultiTexCoord4f)(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) = NULL;
static void (*proc_glMultiTexCoord4fv)(GLenum target, const GLfloat * v) = NULL;
static void (*proc_glMultiTexCoord4i)(GLenum target, GLint s, GLint t, GLint r, GLint q) = NULL;
static void (*proc_glMultiTexCoord4iv)(GLenum target, const GLint * v) = NULL;
static void (*proc_glMultiTexCoord4s)(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) = NULL;
static void (*proc_glMultiTexCoord4sv)(GLenum target, const GLshort * v) = NULL;
static void (*proc_glMultiTexCoordP1ui)(GLenum texture, GLenum type, GLuint coords) = NULL;
static void (*proc_glMultiTexCoordP1uiv)(GLenum texture, GLenum type, const GLuint * coords) = NULL;
static void (*proc_glMultiTexCoordP2ui)(GLenum texture, GLenum type, GLuint coords) = NULL;
static void (*proc_glMultiTexCoordP2uiv)(GLenum texture, GLenum type, const GLuint * coords) = NULL;
static void (*proc_glMultiTexCoordP3ui)(GLenum texture, GLenum type, GLuint coords) = NULL;
static void (*proc_glMultiTexCoordP3uiv)(GLenum texture, GLenum type, const GLuint * coords) = NULL;
static void (*proc_glMultiTexCoordP4ui)(GLenum texture, GLenum type, GLuint coords) = NULL;
static void (*proc_glMultiTexCoordP4uiv)(GLenum texture, GLenum type, const GLuint * coords) = NULL;
static void (*proc_glNewList)(GLuint list, GLenum mode) = NULL;
static void (*proc_glNormal3b)(GLbyte nx, GLbyte ny, GLbyte nz) = NULL;
static void (*proc_glNormal3bv)(const GLbyte * v) = NULL;
static void (*proc_glNormal3d)(GLdouble nx, GLdouble ny, GLdouble nz) = NULL;
static void (*proc_glNormal3dv)(const GLdouble * v) = NULL;
static void (*proc_glNormal3f)(GLfloat nx, GLfloat ny, GLfloat nz) = NULL;
static void (*proc_glNormal3fv)(const GLfloat * v) = NULL;
static void (*proc_glNormal3i)(GLint nx, GLint ny, GLint nz) = NULL;
static void (*proc_glNormal3iv)(const GLint * v) = NULL;
static void (*proc_glNormal3s)(GLshort nx, GLshort ny, GLshort nz) = NULL;
static void (*proc_glNormal3sv)(const GLshort * v) = NULL;
static void (*proc_glNormalP3ui)(GLenum type, GLuint coords) = NULL;
static void (*proc_glNormalP3uiv)(GLenum type, const GLuint * coords) = NULL;
static void (*proc_glNormalPointer)(GLenum type, GLsizei stride, const void * pointer) = NULL;
static void (*proc_glOrtho)(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) = NULL;
static void (*proc_glPassThrough)(GLfloat token) = NULL;
static void (*proc_glPatchParameterfv)(GLenum pname, const GLfloat * values) = NULL;
static void (*proc_glPatchParameteri)(GLenum pname, GLint value) = NULL;
static void (*proc_glPauseTransformFeedback)(void) = NULL;
static void (*proc_glPixelMapfv)(GLenum map, GLsizei mapsize, const GLfloat * values) = NULL;
static void (*proc_glPixelMapuiv)(GLenum map, GLsizei mapsize, const GLuint * values) = NULL;
static void (*proc_glPixelMapusv)(GLenum map, GLsizei mapsize, const GLushort * values) = NULL;
static void (*proc_glPixelStoref)(GLenum pname, GLfloat param) = NULL;
static void (*proc_glPixelStorei)(GLenum pname, GLint param) = NULL;
static void (*proc_glPixelTransferf)(GLenum pname, GLfloat param) = NULL;
static void (*proc_glPixelTransferi)(GLenum pname, GLint param) = NULL;
static void (*proc_glPixelZoom)(GLfloat xfactor, GLfloat yfactor) = NULL;
static void (*proc_glPointParameterf)(GLenum pname, GLfloat param) = NULL;
static void (*proc_glPointParameterfv)(GLenum pname, const GLfloat * params) = NULL;
static void (*proc_glPointParameteri)(GLenum pname, GLint param) = NULL;
static void (*proc_glPointParameteriv)(GLenum pname, const GLint * params) = NULL;
static void (*proc_glPointSize)(GLfloat size) = NULL;
static void (*proc_glPolygonMode)(GLenum face, GLenum mode) = NULL;
static void (*proc_glPolygonOffset)(GLfloat factor, GLfloat units) = NULL;
static void (*proc_glPolygonStipple)(const GLubyte * mask) = NULL;
static void (*proc_glPopAttrib)(void) = NULL;
static void (*proc_glPopClientAttrib)(void) = NULL;
static void (*proc_glPopMatrix)(void) = NULL;
static void (*proc_glPopName)(void) = NULL;
static void (*proc_glPrimitiveRestartIndex)(GLuint index) = NULL;
static void (*proc_glPrioritizeTextures)(GLsizei n, const GLuint * textures, const GLfloat * priorities) = NULL;
static void (*proc_glProvokingVertex)(GLenum mode) = NULL;
static void (*proc_glPushAttrib)(GLbitfield mask) = NULL;
static void (*proc_glPushClientAttrib)(GLbitfield mask) = NULL;
static void (*proc_glPushMatrix)(void) = NULL;
static void (*proc_glPushName)(GLuint name) = NULL;
static void (*proc_glQueryCounter)(GLuint id, GLenum target) = NULL;
static void (*proc_glRasterPos2d)(GLdouble x, GLdouble y) = NULL;
static void (*proc_glRasterPos2dv)(const GLdouble * v) = NULL;
static void (*proc_glRasterPos2f)(GLfloat x, GLfloat y) = NULL;
static void (*proc_glRasterPos2fv)(const GLfloat * v) = NULL;
static void (*proc_glRasterPos2i)(GLint x, GLint y) = NULL;
static void (*proc_glRasterPos2iv)(const GLint * v) = NULL;
static void (*proc_glRasterPos2s)(GLshort x, GLshort y) = NULL;
static void (*proc_glRasterPos2sv)(const GLshort * v) = NULL;
static void (*proc_glRasterPos3d)(GLdouble x, GLdouble y, GLdouble z) = NULL;
static void (*proc_glRasterPos3dv)(const GLdouble * v) = NULL;
static void (*proc_glRasterPos3f)(GLfloat x, GLfloat y, GLfloat z) = NULL;
static void (*proc_glRasterPos3fv)(const GLfloat * v) = NULL;
static void (*proc_glRasterPos3i)(GLint x, GLint y, GLint z) = NULL;
static void (*proc_glRasterPos3iv)(const GLint * v) = NULL;
static void (*proc_glRasterPos3s)(GLshort x, GLshort y, GLshort z) = NULL;
static void (*proc_glRasterPos3sv)(const GLshort * v) = NULL;
static void (*proc_glRasterPos4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
static void (*proc_glRasterPos4dv)(const GLdouble * v) = NULL;
static void (*proc_glRasterPos4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w) = NULL;
static void (*proc_glRasterPos4fv)(const GLfloat * v) = NULL;
static void (*proc_glRasterPos4i)(GLint x, GLint y, GLint z, GLint w) = NULL;
static void (*proc_glRasterPos4iv)(const GLint * v) = NULL;
static void (*proc_glRasterPos4s)(GLshort x, GLshort y, GLshort z, GLshort w) = NULL;
static void (*proc_glRasterPos4sv)(const GLshort * v) = NULL;
static void (*proc_glReadBuffer)(GLenum src) = NULL;
static void (*proc_glReadPixels)(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels) = NULL;
static void (*proc_glRectd)(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) = NULL;
static void (*proc_glRectdv)(const GLdouble * v1, const GLdouble * v2) = NULL;
static void (*proc_glRectf)(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) = NULL;
static void (*proc_glRectfv)(const GLfloat * v1, const GLfloat * v2) = NULL;
static void (*proc_glRecti)(GLint x1, GLint y1, GLint x2, GLint y2) = NULL;
static void (*proc_glRectiv)(const GLint * v1, const GLint * v2) = NULL;
static void (*proc_glRects)(GLshort x1, GLshort y1, GLshort x2, GLshort y2) = NULL;
static void (*proc_glRectsv)(const GLshort * v1, const GLshort * v2) = NULL;
static GLint (*proc_glRenderMode)(GLenum mode) = NULL;
static void (*proc_glRenderbufferStorage)(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) = NULL;
static void (*proc_glRenderbufferStorageMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) = NULL;
static void (*proc_glResumeTransformFeedback)(void) = NULL;
static void (*proc_glRotated)(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) = NULL;
static void (*proc_glRotatef)(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) = NULL;
static void (*proc_glSampleCoverage)(GLfloat value, GLboolean invert) = NULL;
static void (*proc_glSampleMaski)(GLuint maskNumber, GLbitfield mask) = NULL;
static void (*proc_glSamplerParameterIiv)(GLuint sampler, GLenum pname, const GLint * param) = NULL;
static void (*proc_glSamplerParameterIuiv)(GLuint sampler, GLenum pname, const GLuint * param) = NULL;
static void (*proc_glSamplerParameterf)(GLuint sampler, GLenum pname, GLfloat param) = NULL;
static void (*proc_glSamplerParameterfv)(GLuint sampler, GLenum pname, const GLfloat * param) = NULL;
static void (*proc_glSamplerParameteri)(GLuint sampler, GLenum pname, GLint param) = NULL;
static void (*proc_glSamplerParameteriv)(GLuint sampler, GLenum pname, const GLint * param) = NULL;
static void (*proc_glScaled)(GLdouble x, GLdouble y, GLdouble z) = NULL;
static void (*proc_glScalef)(GLfloat x, GLfloat y, GLfloat z) = NULL;
static void (*proc_glScissor)(GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
static void (*proc_glSecondaryColor3b)(GLbyte red, GLbyte green, GLbyte blue) = NULL;
static void (*proc_glSecondaryColor3bv)(const GLbyte * v) = NULL;
static void (*proc_glSecondaryColor3d)(GLdouble red, GLdouble green, GLdouble blue) = NULL;
static void (*proc_glSecondaryColor3dv)(const GLdouble * v) = NULL;
static void (*proc_glSecondaryColor3f)(GLfloat red, GLfloat green, GLfloat blue) = NULL;
static void (*proc_glSecondaryColor3fv)(const GLfloat * v) = NULL;
static void (*proc_glSecondaryColor3i)(GLint red, GLint green, GLint blue) = NULL;
static void (*proc_glSecondaryColor3iv)(const GLint * v) = NULL;
static void (*proc_glSecondaryColor3s)(GLshort red, GLshort green, GLshort blue) = NULL;
static void (*proc_glSecondaryColor3sv)(const GLshort * v) = NULL;
static void (*proc_glSecondaryColor3ub)(GLubyte red, GLubyte green, GLubyte blue) = NULL;
static void (*proc_glSecondaryColor3ubv)(const GLubyte * v) = NULL;
static void (*proc_glSecondaryColor3ui)(GLuint red, GLuint green, GLuint blue) = NULL;
static void (*proc_glSecondaryColor3uiv)(const GLuint * v) = NULL;
static void (*proc_glSecondaryColor3us)(GLushort red, GLushort green, GLushort blue) = NULL;
static void (*proc_glSecondaryColor3usv)(const GLushort * v) = NULL;
static void (*proc_glSecondaryColorP3ui)(GLenum type, GLuint color) = NULL;
static void (*proc_glSecondaryColorP3uiv)(GLenum type, const GLuint * color) = NULL;
static void (*proc_glSecondaryColorPointer)(GLint size, GLenum type, GLsizei stride, const void * pointer) = NULL;
static void (*proc_glSelectBuffer)(GLsizei size, GLuint * buffer) = NULL;
static void (*proc_glShadeModel)(GLenum mode) = NULL;
static void (*proc_glShaderSource)(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length) = NULL;
static void (*proc_glStencilFunc)(GLenum func, GLint ref, GLuint mask) = NULL;
static void (*proc_glStencilFuncSeparate)(GLenum face, GLenum func, GLint ref, GLuint mask) = NULL;
static void (*proc_glStencilMask)(GLuint mask) = NULL;
static void (*proc_glStencilMaskSeparate)(GLenum face, GLuint mask) = NULL;
static void (*proc_glStencilOp)(GLenum fail, GLenum zfail, GLenum zpass) = NULL;
static void (*proc_glStencilOpSeparate)(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) = NULL;
static void (*proc_glTexBuffer)(GLenum target, GLenum internalformat, GLuint buffer) = NULL;
static void (*proc_glTexCoord1d)(GLdouble s) = NULL;
static void (*proc_glTexCoord1dv)(const GLdouble * v) = NULL;
static void (*proc_glTexCoord1f)(GLfloat s) = NULL;
static void (*proc_glTexCoord1fv)(const GLfloat * v) = NULL;
static void (*proc_glTexCoord1i)(GLint s) = NULL;
static void (*proc_glTexCoord1iv)(const GLint * v) = NULL;
static void (*proc_glTexCoord1s)(GLshort s) = NULL;
static void (*proc_glTexCoord1sv)(const GLshort * v) = NULL;
static void (*proc_glTexCoord2d)(GLdouble s, GLdouble t) = NULL;
static void (*proc_glTexCoord2dv)(const GLdouble * v) = NULL;
static void (*proc_glTexCoord2f)(GLfloat s, GLfloat t) = NULL;
static void (*proc_glTexCoord2fv)(const GLfloat * v) = NULL;
static void (*proc_glTexCoord2i)(GLint s, GLint t) = NULL;
static void (*proc_glTexCoord2iv)(const GLint * v) = NULL;
static void (*proc_glTexCoord2s)(GLshort s, GLshort t) = NULL;
static void (*proc_glTexCoord2sv)(const GLshort * v) = NULL;
static void (*proc_glTexCoord3d)(GLdouble s, GLdouble t, GLdouble r) = NULL;
static void (*proc_glTexCoord3dv)(const GLdouble * v) = NULL;
static void (*proc_glTexCoord3f)(GLfloat s, GLfloat t, GLfloat r) = NULL;
static void (*proc_glTexCoord3fv)(const GLfloat * v) = NULL;
static void (*proc_glTexCoord3i)(GLint s, GLint t, GLint r) = NULL;
static void (*proc_glTexCoord3iv)(const GLint * v) = NULL;
static void (*proc_glTexCoord3s)(GLshort s, GLshort t, GLshort r) = NULL;
static void (*proc_glTexCoord3sv)(const GLshort * v) = NULL;
static void (*proc_glTexCoord4d)(GLdouble s, GLdouble t, GLdouble r, GLdouble q) = NULL;
static void (*proc_glTexCoord4dv)(const GLdouble * v) = NULL;
static void (*proc_glTexCoord4f)(GLfloat s, GLfloat t, GLfloat r, GLfloat q) = NULL;
static void (*proc_glTexCoord4fv)(const GLfloat * v) = NULL;
static void (*proc_glTexCoord4i)(GLint s, GLint t, GLint r, GLint q) = NULL;
static void (*proc_glTexCoord4iv)(const GLint * v) = NULL;
static void (*proc_glTexCoord4s)(GLshort s, GLshort t, GLshort r, GLshort q) = NULL;
static void (*proc_glTexCoord4sv)(const GLshort * v) = NULL;
static void (*proc_glTexCoordP1ui)(GLenum type, GLuint coords) = NULL;
static void (*proc_glTexCoordP1uiv)(GLenum type, const GLuint * coords) = NULL;
static void (*proc_glTexCoordP2ui)(GLenum type, GLuint coords) = NULL;
static void (*proc_glTexCoordP2uiv)(GLenum type, const GLuint * coords) = NULL;
static void (*proc_glTexCoordP3ui)(GLenum type, GLuint coords) = NULL;
static void (*proc_glTexCoordP3uiv)(GLenum type, const GLuint * coords) = NULL;
static void (*proc_glTexCoordP4ui)(GLenum type, GLuint coords) = NULL;
static void (*proc_glTexCoordP4uiv)(GLenum type, const GLuint * coords) = NULL;
static void (*proc_glTexCoordPointer)(GLint size, GLenum type, GLsizei stride, const void * pointer) = NULL;
static void (*proc_glTexEnvf)(GLenum target, GLenum pname, GLfloat param) = NULL;
static void (*proc_glTexEnvfv)(GLenum target, GLenum pname, const GLfloat * params) = NULL;
static void (*proc_glTexEnvi)(GLenum target, GLenum pname, GLint param) = NULL;
static void (*proc_glTexEnviv)(GLenum target, GLenum pname, const GLint * params) = NULL;
static void (*proc_glTexGend)(GLenum coord, GLenum pname, GLdouble param) = NULL;
static void (*proc_glTexGendv)(GLenum coord, GLenum pname, const GLdouble * params) = NULL;
static void (*proc_glTexGenf)(GLenum coord, GLenum pname, GLfloat param) = NULL;
static void (*proc_glTexGenfv)(GLenum coord, GLenum pname, const GLfloat * params) = NULL;
static void (*proc_glTexGeni)(GLenum coord, GLenum pname, GLint param) = NULL;
static void (*proc_glTexGeniv)(GLenum coord, GLenum pname, const GLint * params) = NULL;
static void (*proc_glTexImage1D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels) = NULL;
static void (*proc_glTexImage2D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels) = NULL;
static void (*proc_glTexImage2DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) = NULL;
static void (*proc_glTexImage3D)(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels) = NULL;
static void (*proc_glTexImage3DMultisample)(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) = NULL;
static void (*proc_glTexParameterIiv)(GLenum target, GLenum pname, const GLint * params) = NULL;
static void (*proc_glTexParameterIuiv)(GLenum target, GLenum pname, const GLuint * params) = NULL;
static void (*proc_glTexParameterf)(GLenum target, GLenum pname, GLfloat param) = NULL;
static void (*proc_glTexParameterfv)(GLenum target, GLenum pname, const GLfloat * params) = NULL;
static void (*proc_glTexParameteri)(GLenum target, GLenum pname, GLint param) = NULL;
static void (*proc_glTexParameteriv)(GLenum target, GLenum pname, const GLint * params) = NULL;
static void (*proc_glTexSubImage1D)(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels) = NULL;
static void (*proc_glTexSubImage2D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) = NULL;
static void (*proc_glTexSubImage3D)(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) = NULL;
static void (*proc_glTransformFeedbackVaryings)(GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode) = NULL;
static void (*proc_glTranslated)(GLdouble x, GLdouble y, GLdouble z) = NULL;
static void (*proc_glTranslatef)(GLfloat x, GLfloat y, GLfloat z) = NULL;
static void (*proc_glUniform1d)(GLint location, GLdouble x) = NULL;
static void (*proc_glUniform1dv)(GLint location, GLsizei count, const GLdouble * value) = NULL;
static void (*proc_glUniform1f)(GLint location, GLfloat v0) = NULL;
static void (*proc_glUniform1fv)(GLint location, GLsizei count, const GLfloat * value) = NULL;
static void (*proc_glUniform1i)(GLint location, GLint v0) = NULL;
static void (*proc_glUniform1iv)(GLint location, GLsizei count, const GLint * value) = NULL;
static void (*proc_glUniform1ui)(GLint location, GLuint v0) = NULL;
static void (*proc_glUniform1uiv)(GLint location, GLsizei count, const GLuint * value) = NULL;
static void (*proc_glUniform2d)(GLint location, GLdouble x, GLdouble y) = NULL;
static void (*proc_glUniform2dv)(GLint location, GLsizei count, const GLdouble * value) = NULL;
static void (*proc_glUniform2f)(GLint location, GLfloat v0, GLfloat v1) = NULL;
static void (*proc_glUniform2fv)(GLint location, GLsizei count, const GLfloat * value) = NULL;
static void (*proc_glUniform2i)(GLint location, GLint v0, GLint v1) = NULL;
static void (*proc_glUniform2iv)(GLint location, GLsizei count, const GLint * value) = NULL;
static void (*proc_glUniform2ui)(GLint location, GLuint v0, GLuint v1) = NULL;
static void (*proc_glUniform2uiv)(GLint location, GLsizei count, const GLuint * value) = NULL;
static void (*proc_glUniform3d)(GLint location, GLdouble x, GLdouble y, GLdouble z) = NULL;
static void (*proc_glUniform3dv)(GLint location, GLsizei count, const GLdouble * value) = NULL;
static void (*proc_glUniform3f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) = NULL;
static void (*proc_glUniform3fv)(GLint location, GLsizei count, const GLfloat * value) = NULL;
static void (*proc_glUniform3i)(GLint location, GLint v0, GLint v1, GLint v2) = NULL;
static void (*proc_glUniform3iv)(GLint location, GLsizei count, const GLint * value) = NULL;
static void (*proc_glUniform3ui)(GLint location, GLuint v0, GLuint v1, GLuint v2) = NULL;
static void (*proc_glUniform3uiv)(GLint location, GLsizei count, const GLuint * value) = NULL;
static void (*proc_glUniform4d)(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
static void (*proc_glUniform4dv)(GLint location, GLsizei count, const GLdouble * value) = NULL;
static void (*proc_glUniform4f)(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) = NULL;
static void (*proc_glUniform4fv)(GLint location, GLsizei count, const GLfloat * value) = NULL;
static void (*proc_glUniform4i)(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) = NULL;
static void (*proc_glUniform4iv)(GLint location, GLsizei count, const GLint * value) = NULL;
static void (*proc_glUniform4ui)(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) = NULL;
static void (*proc_glUniform4uiv)(GLint location, GLsizei count, const GLuint * value) = NULL;
static void (*proc_glUniformBlockBinding)(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) = NULL;
static void (*proc_glUniformMatrix2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
static void (*proc_glUniformMatrix2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
static void (*proc_glUniformMatrix2x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
static void (*proc_glUniformMatrix2x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
static void (*proc_glUniformMatrix2x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
static void (*proc_glUniformMatrix2x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
static void (*proc_glUniformMatrix3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
static void (*proc_glUniformMatrix3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
static void (*proc_glUniformMatrix3x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
static void (*proc_glUniformMatrix3x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
static void (*proc_glUniformMatrix3x4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
static void (*proc_glUniformMatrix3x4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
static void (*proc_glUniformMatrix4dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
static void (*proc_glUniformMatrix4fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
static void (*proc_glUniformMatrix4x2dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
static void (*proc_glUniformMatrix4x2fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
static void (*proc_glUniformMatrix4x3dv)(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) = NULL;
static void (*proc_glUniformMatrix4x3fv)(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) = NULL;
static void (*proc_glUniformSubroutinesuiv)(GLenum shadertype, GLsizei count, const GLuint * indices) = NULL;
static GLboolean (*proc_glUnmapBuffer)(GLenum target) = NULL;
static void (*proc_glUseProgram)(GLuint program) = NULL;
static void (*proc_glValidateProgram)(GLuint program) = NULL;
static void (*proc_glVertex2d)(GLdouble x, GLdouble y) = NULL;
static void (*proc_glVertex2dv)(const GLdouble * v) = NULL;
static void (*proc_glVertex2f)(GLfloat x, GLfloat y) = NULL;
static void (*proc_glVertex2fv)(const GLfloat * v) = NULL;
static void (*proc_glVertex2i)(GLint x, GLint y) = NULL;
static void (*proc_glVertex2iv)(const GLint * v) = NULL;
static void (*proc_glVertex2s)(GLshort x, GLshort y) = NULL;
static void (*proc_glVertex2sv)(const GLshort * v) = NULL;
static void (*proc_glVertex3d)(GLdouble x, GLdouble y, GLdouble z) = NULL;
static void (*proc_glVertex3dv)(const GLdouble * v) = NULL;
static void (*proc_glVertex3f)(GLfloat x, GLfloat y, GLfloat z) = NULL;
static void (*proc_glVertex3fv)(const GLfloat * v) = NULL;
static void (*proc_glVertex3i)(GLint x, GLint y, GLint z) = NULL;
static void (*proc_glVertex3iv)(const GLint * v) = NULL;
static void (*proc_glVertex3s)(GLshort x, GLshort y, GLshort z) = NULL;
static void (*proc_glVertex3sv)(const GLshort * v) = NULL;
static void (*proc_glVertex4d)(GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
static void (*proc_glVertex4dv)(const GLdouble * v) = NULL;
static void (*proc_glVertex4f)(GLfloat x, GLfloat y, GLfloat z, GLfloat w) = NULL;
static void (*proc_glVertex4fv)(const GLfloat * v) = NULL;
static void (*proc_glVertex4i)(GLint x, GLint y, GLint z, GLint w) = NULL;
static void (*proc_glVertex4iv)(const GLint * v) = NULL;
static void (*proc_glVertex4s)(GLshort x, GLshort y, GLshort z, GLshort w) = NULL;
static void (*proc_glVertex4sv)(const GLshort * v) = NULL;
static void (*proc_glVertexAttrib1d)(GLuint index, GLdouble x) = NULL;
static void (*proc_glVertexAttrib1dv)(GLuint index, const GLdouble * v) = NULL;
static void (*proc_glVertexAttrib1f)(GLuint index, GLfloat x) = NULL;
static void (*proc_glVertexAttrib1fv)(GLuint index, const GLfloat * v) = NULL;
static void (*proc_glVertexAttrib1s)(GLuint index, GLshort x) = NULL;
static void (*proc_glVertexAttrib1sv)(GLuint index, const GLshort * v) = NULL;
static void (*proc_glVertexAttrib2d)(GLuint index, GLdouble x, GLdouble y) = NULL;
static void (*proc_glVertexAttrib2dv)(GLuint index, const GLdouble * v) = NULL;
static void (*proc_glVertexAttrib2f)(GLuint index, GLfloat x, GLfloat y) = NULL;
static void (*proc_glVertexAttrib2fv)(GLuint index, const GLfloat * v) = NULL;
static void (*proc_glVertexAttrib2s)(GLuint index, GLshort x, GLshort y) = NULL;
static void (*proc_glVertexAttrib2sv)(GLuint index, const GLshort * v) = NULL;
static void (*proc_glVertexAttrib3d)(GLuint index, GLdouble x, GLdouble y, GLdouble z) = NULL;
static void (*proc_glVertexAttrib3dv)(GLuint index, const GLdouble * v) = NULL;
static void (*proc_glVertexAttrib3f)(GLuint index, GLfloat x, GLfloat y, GLfloat z) = NULL;
static void (*proc_glVertexAttrib3fv)(GLuint index, const GLfloat * v) = NULL;
static void (*proc_glVertexAttrib3s)(GLuint index, GLshort x, GLshort y, GLshort z) = NULL;
static void (*proc_glVertexAttrib3sv)(GLuint index, const GLshort * v) = NULL;
static void (*proc_glVertexAttrib4Nbv)(GLuint index, const GLbyte * v) = NULL;
static void (*proc_glVertexAttrib4Niv)(GLuint index, const GLint * v) = NULL;
static void (*proc_glVertexAttrib4Nsv)(GLuint index, const GLshort * v) = NULL;
static void (*proc_glVertexAttrib4Nub)(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) = NULL;
static void (*proc_glVertexAttrib4Nubv)(GLuint index, const GLubyte * v) = NULL;
static void (*proc_glVertexAttrib4Nuiv)(GLuint index, const GLuint * v) = NULL;
static void (*proc_glVertexAttrib4Nusv)(GLuint index, const GLushort * v) = NULL;
static void (*proc_glVertexAttrib4bv)(GLuint index, const GLbyte * v) = NULL;
static void (*proc_glVertexAttrib4d)(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) = NULL;
static void (*proc_glVertexAttrib4dv)(GLuint index, const GLdouble * v) = NULL;
static void (*proc_glVertexAttrib4f)(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) = NULL;
static void (*proc_glVertexAttrib4fv)(GLuint index, const GLfloat * v) = NULL;
static void (*proc_glVertexAttrib4iv)(GLuint index, const GLint * v) = NULL;
static void (*proc_glVertexAttrib4s)(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) = NULL;
static void (*proc_glVertexAttrib4sv)(GLuint index, const GLshort * v) = NULL;
static void (*proc_glVertexAttrib4ubv)(GLuint index, const GLubyte * v) = NULL;
static void (*proc_glVertexAttrib4uiv)(GLuint index, const GLuint * v) = NULL;
static void (*proc_glVertexAttrib4usv)(GLuint index, const GLushort * v) = NULL;
static void (*proc_glVertexAttribDivisor)(GLuint index, GLuint divisor) = NULL;
static void (*proc_glVertexAttribI1i)(GLuint index, GLint x) = NULL;
static void (*proc_glVertexAttribI1iv)(GLuint index, const GLint * v) = NULL;
static void (*proc_glVertexAttribI1ui)(GLuint index, GLuint x) = NULL;
static void (*proc_glVertexAttribI1uiv)(GLuint index, const GLuint * v) = NULL;
static void (*proc_glVertexAttribI2i)(GLuint index, GLint x, GLint y) = NULL;
static void (*proc_glVertexAttribI2iv)(GLuint index, const GLint * v) = NULL;
static void (*proc_glVertexAttribI2ui)(GLuint index, GLuint x, GLuint y) = NULL;
static void (*proc_glVertexAttribI2uiv)(GLuint index, const GLuint * v) = NULL;
static void (*proc_glVertexAttribI3i)(GLuint index, GLint x, GLint y, GLint z) = NULL;
static void (*proc_glVertexAttribI3iv)(GLuint index, const GLint * v) = NULL;
static void (*proc_glVertexAttribI3ui)(GLuint index, GLuint x, GLuint y, GLuint z) = NULL;
static void (*proc_glVertexAttribI3uiv)(GLuint index, const GLuint * v) = NULL;
static void (*proc_glVertexAttribI4bv)(GLuint index, const GLbyte * v) = NULL;
static void (*proc_glVertexAttribI4i)(GLuint index, GLint x, GLint y, GLint z, GLint w) = NULL;
static void (*proc_glVertexAttribI4iv)(GLuint index, const GLint * v) = NULL;
static void (*proc_glVertexAttribI4sv)(GLuint index, const GLshort * v) = NULL;
static void (*proc_glVertexAttribI4ubv)(GLuint index, const GLubyte * v) = NULL;
static void (*proc_glVertexAttribI4ui)(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) = NULL;
static void (*proc_glVertexAttribI4uiv)(GLuint index, const GLuint * v) = NULL;
static void (*proc_glVertexAttribI4usv)(GLuint index, const GLushort * v) = NULL;
static void (*proc_glVertexAttribIPointer)(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer) = NULL;
static void (*proc_glVertexAttribP1ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value) = NULL;
static void (*proc_glVertexAttribP1uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) = NULL;
static void (*proc_glVertexAttribP2ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value) = NULL;
static void (*proc_glVertexAttribP2uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) = NULL;
static void (*proc_glVertexAttribP3ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value) = NULL;
static void (*proc_glVertexAttribP3uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) = NULL;
static void (*proc_glVertexAttribP4ui)(GLuint index, GLenum type, GLboolean normalized, GLuint value) = NULL;
static void (*proc_glVertexAttribP4uiv)(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) = NULL;
static void (*proc_glVertexAttribPointer)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer) = NULL;
static void (*proc_glVertexP2ui)(GLenum type, GLuint value) = NULL;
static void (*proc_glVertexP2uiv)(GLenum type, const GLuint * value) = NULL;
static void (*proc_glVertexP3ui)(GLenum type, GLuint value) = NULL;
static void (*proc_glVertexP3uiv)(GLenum type, const GLuint * value) = NULL;
static void (*proc_glVertexP4ui)(GLenum type, GLuint value) = NULL;
static void (*proc_glVertexP4uiv)(GLenum type, const GLuint * value) = NULL;
static void (*proc_glVertexPointer)(GLint size, GLenum type, GLsizei stride, const void * pointer) = NULL;
static void (*proc_glViewport)(GLint x, GLint y, GLsizei width, GLsizei height) = NULL;
static void (*proc_glWaitSync)(GLsync sync, GLbitfield flags, GLuint64 timeout) = NULL;
static void (*proc_glWindowPos2d)(GLdouble x, GLdouble y) = NULL;
static void (*proc_glWindowPos2dv)(const GLdouble * v) = NULL;
static void (*proc_glWindowPos2f)(GLfloat x, GLfloat y) = NULL;
static void (*proc_glWindowPos2fv)(const GLfloat * v) = NULL;
static void (*proc_glWindowPos2i)(GLint x, GLint y) = NULL;
static void (*proc_glWindowPos2iv)(const GLint * v) = NULL;
static void (*proc_glWindowPos2s)(GLshort x, GLshort y) = NULL;
static void (*proc_glWindowPos2sv)(const GLshort * v) = NULL;
static void (*proc_glWindowPos3d)(GLdouble x, GLdouble y, GLdouble z) = NULL;
static void (*proc_glWindowPos3dv)(const GLdouble * v) = NULL;
static void (*proc_glWindowPos3f)(GLfloat x, GLfloat y, GLfloat z) = NULL;
static void (*proc_glWindowPos3fv)(const GLfloat * v) = NULL;
static void (*proc_glWindowPos3i)(GLint x, GLint y, GLint z) = NULL;
static void (*proc_glWindowPos3iv)(const GLint * v) = NULL;
static void (*proc_glWindowPos3s)(GLshort x, GLshort y, GLshort z) = NULL;
static void (*proc_glWindowPos3sv)(const GLshort * v) = NULL;

static void load_gl_shims(void) {
    libgl = cosmo_dlopen("libgl.so", RTLD_NOW | RTLD_GLOBAL);
    proc_glAccum = cosmo_dltramp(cosmo_dlsym(libgl, "glAccum"));
    proc_glActiveTexture = cosmo_dltramp(cosmo_dlsym(libgl, "glActiveTexture"));
    proc_glAlphaFunc = cosmo_dltramp(cosmo_dlsym(libgl, "glAlphaFunc"));
    proc_glAreTexturesResident = cosmo_dltramp(cosmo_dlsym(libgl, "glAreTexturesResident"));
    proc_glArrayElement = cosmo_dltramp(cosmo_dlsym(libgl, "glArrayElement"));
    proc_glAttachShader = cosmo_dltramp(cosmo_dlsym(libgl, "glAttachShader"));
    proc_glBegin = cosmo_dltramp(cosmo_dlsym(libgl, "glBegin"));
    proc_glBeginConditionalRender = cosmo_dltramp(cosmo_dlsym(libgl, "glBeginConditionalRender"));
    proc_glBeginQuery = cosmo_dltramp(cosmo_dlsym(libgl, "glBeginQuery"));
    proc_glBeginQueryIndexed = cosmo_dltramp(cosmo_dlsym(libgl, "glBeginQueryIndexed"));
    proc_glBeginTransformFeedback = cosmo_dltramp(cosmo_dlsym(libgl, "glBeginTransformFeedback"));
    proc_glBindAttribLocation = cosmo_dltramp(cosmo_dlsym(libgl, "glBindAttribLocation"));
    proc_glBindBuffer = cosmo_dltramp(cosmo_dlsym(libgl, "glBindBuffer"));
    proc_glBindBufferBase = cosmo_dltramp(cosmo_dlsym(libgl, "glBindBufferBase"));
    proc_glBindBufferRange = cosmo_dltramp(cosmo_dlsym(libgl, "glBindBufferRange"));
    proc_glBindFragDataLocation = cosmo_dltramp(cosmo_dlsym(libgl, "glBindFragDataLocation"));
    proc_glBindFragDataLocationIndexed = cosmo_dltramp(cosmo_dlsym(libgl, "glBindFragDataLocationIndexed"));
    proc_glBindFramebuffer = cosmo_dltramp(cosmo_dlsym(libgl, "glBindFramebuffer"));
    proc_glBindRenderbuffer = cosmo_dltramp(cosmo_dlsym(libgl, "glBindRenderbuffer"));
    proc_glBindSampler = cosmo_dltramp(cosmo_dlsym(libgl, "glBindSampler"));
    proc_glBindTexture = cosmo_dltramp(cosmo_dlsym(libgl, "glBindTexture"));
    proc_glBindTransformFeedback = cosmo_dltramp(cosmo_dlsym(libgl, "glBindTransformFeedback"));
    proc_glBindVertexArray = cosmo_dltramp(cosmo_dlsym(libgl, "glBindVertexArray"));
    proc_glBitmap = cosmo_dltramp(cosmo_dlsym(libgl, "glBitmap"));
    proc_glBlendColor = cosmo_dltramp(cosmo_dlsym(libgl, "glBlendColor"));
    proc_glBlendEquation = cosmo_dltramp(cosmo_dlsym(libgl, "glBlendEquation"));
    proc_glBlendEquationSeparate = cosmo_dltramp(cosmo_dlsym(libgl, "glBlendEquationSeparate"));
    proc_glBlendEquationSeparatei = cosmo_dltramp(cosmo_dlsym(libgl, "glBlendEquationSeparatei"));
    proc_glBlendEquationi = cosmo_dltramp(cosmo_dlsym(libgl, "glBlendEquationi"));
    proc_glBlendFunc = cosmo_dltramp(cosmo_dlsym(libgl, "glBlendFunc"));
    proc_glBlendFuncSeparate = cosmo_dltramp(cosmo_dlsym(libgl, "glBlendFuncSeparate"));
    proc_glBlendFuncSeparatei = cosmo_dltramp(cosmo_dlsym(libgl, "glBlendFuncSeparatei"));
    proc_glBlendFunci = cosmo_dltramp(cosmo_dlsym(libgl, "glBlendFunci"));
    proc_glBlitFramebuffer = cosmo_dltramp(cosmo_dlsym(libgl, "glBlitFramebuffer"));
    proc_glBufferData = cosmo_dltramp(cosmo_dlsym(libgl, "glBufferData"));
    proc_glBufferSubData = cosmo_dltramp(cosmo_dlsym(libgl, "glBufferSubData"));
    proc_glCallList = cosmo_dltramp(cosmo_dlsym(libgl, "glCallList"));
    proc_glCallLists = cosmo_dltramp(cosmo_dlsym(libgl, "glCallLists"));
    proc_glCheckFramebufferStatus = cosmo_dltramp(cosmo_dlsym(libgl, "glCheckFramebufferStatus"));
    proc_glClampColor = cosmo_dltramp(cosmo_dlsym(libgl, "glClampColor"));
    proc_glClear = cosmo_dltramp(cosmo_dlsym(libgl, "glClear"));
    proc_glClearAccum = cosmo_dltramp(cosmo_dlsym(libgl, "glClearAccum"));
    proc_glClearBufferfi = cosmo_dltramp(cosmo_dlsym(libgl, "glClearBufferfi"));
    proc_glClearBufferfv = cosmo_dltramp(cosmo_dlsym(libgl, "glClearBufferfv"));
    proc_glClearBufferiv = cosmo_dltramp(cosmo_dlsym(libgl, "glClearBufferiv"));
    proc_glClearBufferuiv = cosmo_dltramp(cosmo_dlsym(libgl, "glClearBufferuiv"));
    proc_glClearColor = cosmo_dltramp(cosmo_dlsym(libgl, "glClearColor"));
    proc_glClearDepth = cosmo_dltramp(cosmo_dlsym(libgl, "glClearDepth"));
    proc_glClearIndex = cosmo_dltramp(cosmo_dlsym(libgl, "glClearIndex"));
    proc_glClearStencil = cosmo_dltramp(cosmo_dlsym(libgl, "glClearStencil"));
    proc_glClientActiveTexture = cosmo_dltramp(cosmo_dlsym(libgl, "glClientActiveTexture"));
    proc_glClientWaitSync = cosmo_dltramp(cosmo_dlsym(libgl, "glClientWaitSync"));
    proc_glClipPlane = cosmo_dltramp(cosmo_dlsym(libgl, "glClipPlane"));
    proc_glColor3b = cosmo_dltramp(cosmo_dlsym(libgl, "glColor3b"));
    proc_glColor3bv = cosmo_dltramp(cosmo_dlsym(libgl, "glColor3bv"));
    proc_glColor3d = cosmo_dltramp(cosmo_dlsym(libgl, "glColor3d"));
    proc_glColor3dv = cosmo_dltramp(cosmo_dlsym(libgl, "glColor3dv"));
    proc_glColor3f = cosmo_dltramp(cosmo_dlsym(libgl, "glColor3f"));
    proc_glColor3fv = cosmo_dltramp(cosmo_dlsym(libgl, "glColor3fv"));
    proc_glColor3i = cosmo_dltramp(cosmo_dlsym(libgl, "glColor3i"));
    proc_glColor3iv = cosmo_dltramp(cosmo_dlsym(libgl, "glColor3iv"));
    proc_glColor3s = cosmo_dltramp(cosmo_dlsym(libgl, "glColor3s"));
    proc_glColor3sv = cosmo_dltramp(cosmo_dlsym(libgl, "glColor3sv"));
    proc_glColor3ub = cosmo_dltramp(cosmo_dlsym(libgl, "glColor3ub"));
    proc_glColor3ubv = cosmo_dltramp(cosmo_dlsym(libgl, "glColor3ubv"));
    proc_glColor3ui = cosmo_dltramp(cosmo_dlsym(libgl, "glColor3ui"));
    proc_glColor3uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glColor3uiv"));
    proc_glColor3us = cosmo_dltramp(cosmo_dlsym(libgl, "glColor3us"));
    proc_glColor3usv = cosmo_dltramp(cosmo_dlsym(libgl, "glColor3usv"));
    proc_glColor4b = cosmo_dltramp(cosmo_dlsym(libgl, "glColor4b"));
    proc_glColor4bv = cosmo_dltramp(cosmo_dlsym(libgl, "glColor4bv"));
    proc_glColor4d = cosmo_dltramp(cosmo_dlsym(libgl, "glColor4d"));
    proc_glColor4dv = cosmo_dltramp(cosmo_dlsym(libgl, "glColor4dv"));
    proc_glColor4f = cosmo_dltramp(cosmo_dlsym(libgl, "glColor4f"));
    proc_glColor4fv = cosmo_dltramp(cosmo_dlsym(libgl, "glColor4fv"));
    proc_glColor4i = cosmo_dltramp(cosmo_dlsym(libgl, "glColor4i"));
    proc_glColor4iv = cosmo_dltramp(cosmo_dlsym(libgl, "glColor4iv"));
    proc_glColor4s = cosmo_dltramp(cosmo_dlsym(libgl, "glColor4s"));
    proc_glColor4sv = cosmo_dltramp(cosmo_dlsym(libgl, "glColor4sv"));
    proc_glColor4ub = cosmo_dltramp(cosmo_dlsym(libgl, "glColor4ub"));
    proc_glColor4ubv = cosmo_dltramp(cosmo_dlsym(libgl, "glColor4ubv"));
    proc_glColor4ui = cosmo_dltramp(cosmo_dlsym(libgl, "glColor4ui"));
    proc_glColor4uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glColor4uiv"));
    proc_glColor4us = cosmo_dltramp(cosmo_dlsym(libgl, "glColor4us"));
    proc_glColor4usv = cosmo_dltramp(cosmo_dlsym(libgl, "glColor4usv"));
    proc_glColorMask = cosmo_dltramp(cosmo_dlsym(libgl, "glColorMask"));
    proc_glColorMaski = cosmo_dltramp(cosmo_dlsym(libgl, "glColorMaski"));
    proc_glColorMaterial = cosmo_dltramp(cosmo_dlsym(libgl, "glColorMaterial"));
    proc_glColorP3ui = cosmo_dltramp(cosmo_dlsym(libgl, "glColorP3ui"));
    proc_glColorP3uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glColorP3uiv"));
    proc_glColorP4ui = cosmo_dltramp(cosmo_dlsym(libgl, "glColorP4ui"));
    proc_glColorP4uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glColorP4uiv"));
    proc_glColorPointer = cosmo_dltramp(cosmo_dlsym(libgl, "glColorPointer"));
    proc_glCompileShader = cosmo_dltramp(cosmo_dlsym(libgl, "glCompileShader"));
    proc_glCompressedTexImage1D = cosmo_dltramp(cosmo_dlsym(libgl, "glCompressedTexImage1D"));
    proc_glCompressedTexImage2D = cosmo_dltramp(cosmo_dlsym(libgl, "glCompressedTexImage2D"));
    proc_glCompressedTexImage3D = cosmo_dltramp(cosmo_dlsym(libgl, "glCompressedTexImage3D"));
    proc_glCompressedTexSubImage1D = cosmo_dltramp(cosmo_dlsym(libgl, "glCompressedTexSubImage1D"));
    proc_glCompressedTexSubImage2D = cosmo_dltramp(cosmo_dlsym(libgl, "glCompressedTexSubImage2D"));
    proc_glCompressedTexSubImage3D = cosmo_dltramp(cosmo_dlsym(libgl, "glCompressedTexSubImage3D"));
    proc_glCopyBufferSubData = cosmo_dltramp(cosmo_dlsym(libgl, "glCopyBufferSubData"));
    proc_glCopyPixels = cosmo_dltramp(cosmo_dlsym(libgl, "glCopyPixels"));
    proc_glCopyTexImage1D = cosmo_dltramp(cosmo_dlsym(libgl, "glCopyTexImage1D"));
    proc_glCopyTexImage2D = cosmo_dltramp(cosmo_dlsym(libgl, "glCopyTexImage2D"));
    proc_glCopyTexSubImage1D = cosmo_dltramp(cosmo_dlsym(libgl, "glCopyTexSubImage1D"));
    proc_glCopyTexSubImage2D = cosmo_dltramp(cosmo_dlsym(libgl, "glCopyTexSubImage2D"));
    proc_glCopyTexSubImage3D = cosmo_dltramp(cosmo_dlsym(libgl, "glCopyTexSubImage3D"));
    proc_glCreateProgram = cosmo_dltramp(cosmo_dlsym(libgl, "glCreateProgram"));
    proc_glCreateShader = cosmo_dltramp(cosmo_dlsym(libgl, "glCreateShader"));
    proc_glCullFace = cosmo_dltramp(cosmo_dlsym(libgl, "glCullFace"));
    proc_glDeleteBuffers = cosmo_dltramp(cosmo_dlsym(libgl, "glDeleteBuffers"));
    proc_glDeleteFramebuffers = cosmo_dltramp(cosmo_dlsym(libgl, "glDeleteFramebuffers"));
    proc_glDeleteLists = cosmo_dltramp(cosmo_dlsym(libgl, "glDeleteLists"));
    proc_glDeleteProgram = cosmo_dltramp(cosmo_dlsym(libgl, "glDeleteProgram"));
    proc_glDeleteQueries = cosmo_dltramp(cosmo_dlsym(libgl, "glDeleteQueries"));
    proc_glDeleteRenderbuffers = cosmo_dltramp(cosmo_dlsym(libgl, "glDeleteRenderbuffers"));
    proc_glDeleteSamplers = cosmo_dltramp(cosmo_dlsym(libgl, "glDeleteSamplers"));
    proc_glDeleteShader = cosmo_dltramp(cosmo_dlsym(libgl, "glDeleteShader"));
    proc_glDeleteSync = cosmo_dltramp(cosmo_dlsym(libgl, "glDeleteSync"));
    proc_glDeleteTextures = cosmo_dltramp(cosmo_dlsym(libgl, "glDeleteTextures"));
    proc_glDeleteTransformFeedbacks = cosmo_dltramp(cosmo_dlsym(libgl, "glDeleteTransformFeedbacks"));
    proc_glDeleteVertexArrays = cosmo_dltramp(cosmo_dlsym(libgl, "glDeleteVertexArrays"));
    proc_glDepthFunc = cosmo_dltramp(cosmo_dlsym(libgl, "glDepthFunc"));
    proc_glDepthMask = cosmo_dltramp(cosmo_dlsym(libgl, "glDepthMask"));
    proc_glDepthRange = cosmo_dltramp(cosmo_dlsym(libgl, "glDepthRange"));
    proc_glDetachShader = cosmo_dltramp(cosmo_dlsym(libgl, "glDetachShader"));
    proc_glDisable = cosmo_dltramp(cosmo_dlsym(libgl, "glDisable"));
    proc_glDisableClientState = cosmo_dltramp(cosmo_dlsym(libgl, "glDisableClientState"));
    proc_glDisableVertexAttribArray = cosmo_dltramp(cosmo_dlsym(libgl, "glDisableVertexAttribArray"));
    proc_glDisablei = cosmo_dltramp(cosmo_dlsym(libgl, "glDisablei"));
    proc_glDrawArrays = cosmo_dltramp(cosmo_dlsym(libgl, "glDrawArrays"));
    proc_glDrawArraysIndirect = cosmo_dltramp(cosmo_dlsym(libgl, "glDrawArraysIndirect"));
    proc_glDrawArraysInstanced = cosmo_dltramp(cosmo_dlsym(libgl, "glDrawArraysInstanced"));
    proc_glDrawBuffer = cosmo_dltramp(cosmo_dlsym(libgl, "glDrawBuffer"));
    proc_glDrawBuffers = cosmo_dltramp(cosmo_dlsym(libgl, "glDrawBuffers"));
    proc_glDrawElements = cosmo_dltramp(cosmo_dlsym(libgl, "glDrawElements"));
    proc_glDrawElementsBaseVertex = cosmo_dltramp(cosmo_dlsym(libgl, "glDrawElementsBaseVertex"));
    proc_glDrawElementsIndirect = cosmo_dltramp(cosmo_dlsym(libgl, "glDrawElementsIndirect"));
    proc_glDrawElementsInstanced = cosmo_dltramp(cosmo_dlsym(libgl, "glDrawElementsInstanced"));
    proc_glDrawElementsInstancedBaseVertex = cosmo_dltramp(cosmo_dlsym(libgl, "glDrawElementsInstancedBaseVertex"));
    proc_glDrawPixels = cosmo_dltramp(cosmo_dlsym(libgl, "glDrawPixels"));
    proc_glDrawRangeElements = cosmo_dltramp(cosmo_dlsym(libgl, "glDrawRangeElements"));
    proc_glDrawRangeElementsBaseVertex = cosmo_dltramp(cosmo_dlsym(libgl, "glDrawRangeElementsBaseVertex"));
    proc_glDrawTransformFeedback = cosmo_dltramp(cosmo_dlsym(libgl, "glDrawTransformFeedback"));
    proc_glDrawTransformFeedbackStream = cosmo_dltramp(cosmo_dlsym(libgl, "glDrawTransformFeedbackStream"));
    proc_glEdgeFlag = cosmo_dltramp(cosmo_dlsym(libgl, "glEdgeFlag"));
    proc_glEdgeFlagPointer = cosmo_dltramp(cosmo_dlsym(libgl, "glEdgeFlagPointer"));
    proc_glEdgeFlagv = cosmo_dltramp(cosmo_dlsym(libgl, "glEdgeFlagv"));
    proc_glEnable = cosmo_dltramp(cosmo_dlsym(libgl, "glEnable"));
    proc_glEnableClientState = cosmo_dltramp(cosmo_dlsym(libgl, "glEnableClientState"));
    proc_glEnableVertexAttribArray = cosmo_dltramp(cosmo_dlsym(libgl, "glEnableVertexAttribArray"));
    proc_glEnablei = cosmo_dltramp(cosmo_dlsym(libgl, "glEnablei"));
    proc_glEnd = cosmo_dltramp(cosmo_dlsym(libgl, "glEnd"));
    proc_glEndConditionalRender = cosmo_dltramp(cosmo_dlsym(libgl, "glEndConditionalRender"));
    proc_glEndList = cosmo_dltramp(cosmo_dlsym(libgl, "glEndList"));
    proc_glEndQuery = cosmo_dltramp(cosmo_dlsym(libgl, "glEndQuery"));
    proc_glEndQueryIndexed = cosmo_dltramp(cosmo_dlsym(libgl, "glEndQueryIndexed"));
    proc_glEndTransformFeedback = cosmo_dltramp(cosmo_dlsym(libgl, "glEndTransformFeedback"));
    proc_glEvalCoord1d = cosmo_dltramp(cosmo_dlsym(libgl, "glEvalCoord1d"));
    proc_glEvalCoord1dv = cosmo_dltramp(cosmo_dlsym(libgl, "glEvalCoord1dv"));
    proc_glEvalCoord1f = cosmo_dltramp(cosmo_dlsym(libgl, "glEvalCoord1f"));
    proc_glEvalCoord1fv = cosmo_dltramp(cosmo_dlsym(libgl, "glEvalCoord1fv"));
    proc_glEvalCoord2d = cosmo_dltramp(cosmo_dlsym(libgl, "glEvalCoord2d"));
    proc_glEvalCoord2dv = cosmo_dltramp(cosmo_dlsym(libgl, "glEvalCoord2dv"));
    proc_glEvalCoord2f = cosmo_dltramp(cosmo_dlsym(libgl, "glEvalCoord2f"));
    proc_glEvalCoord2fv = cosmo_dltramp(cosmo_dlsym(libgl, "glEvalCoord2fv"));
    proc_glEvalMesh1 = cosmo_dltramp(cosmo_dlsym(libgl, "glEvalMesh1"));
    proc_glEvalMesh2 = cosmo_dltramp(cosmo_dlsym(libgl, "glEvalMesh2"));
    proc_glEvalPoint1 = cosmo_dltramp(cosmo_dlsym(libgl, "glEvalPoint1"));
    proc_glEvalPoint2 = cosmo_dltramp(cosmo_dlsym(libgl, "glEvalPoint2"));
    proc_glFeedbackBuffer = cosmo_dltramp(cosmo_dlsym(libgl, "glFeedbackBuffer"));
    proc_glFenceSync = cosmo_dltramp(cosmo_dlsym(libgl, "glFenceSync"));
    proc_glFinish = cosmo_dltramp(cosmo_dlsym(libgl, "glFinish"));
    proc_glFlush = cosmo_dltramp(cosmo_dlsym(libgl, "glFlush"));
    proc_glFlushMappedBufferRange = cosmo_dltramp(cosmo_dlsym(libgl, "glFlushMappedBufferRange"));
    proc_glFogCoordPointer = cosmo_dltramp(cosmo_dlsym(libgl, "glFogCoordPointer"));
    proc_glFogCoordd = cosmo_dltramp(cosmo_dlsym(libgl, "glFogCoordd"));
    proc_glFogCoorddv = cosmo_dltramp(cosmo_dlsym(libgl, "glFogCoorddv"));
    proc_glFogCoordf = cosmo_dltramp(cosmo_dlsym(libgl, "glFogCoordf"));
    proc_glFogCoordfv = cosmo_dltramp(cosmo_dlsym(libgl, "glFogCoordfv"));
    proc_glFogf = cosmo_dltramp(cosmo_dlsym(libgl, "glFogf"));
    proc_glFogfv = cosmo_dltramp(cosmo_dlsym(libgl, "glFogfv"));
    proc_glFogi = cosmo_dltramp(cosmo_dlsym(libgl, "glFogi"));
    proc_glFogiv = cosmo_dltramp(cosmo_dlsym(libgl, "glFogiv"));
    proc_glFramebufferRenderbuffer = cosmo_dltramp(cosmo_dlsym(libgl, "glFramebufferRenderbuffer"));
    proc_glFramebufferTexture = cosmo_dltramp(cosmo_dlsym(libgl, "glFramebufferTexture"));
    proc_glFramebufferTexture1D = cosmo_dltramp(cosmo_dlsym(libgl, "glFramebufferTexture1D"));
    proc_glFramebufferTexture2D = cosmo_dltramp(cosmo_dlsym(libgl, "glFramebufferTexture2D"));
    proc_glFramebufferTexture3D = cosmo_dltramp(cosmo_dlsym(libgl, "glFramebufferTexture3D"));
    proc_glFramebufferTextureLayer = cosmo_dltramp(cosmo_dlsym(libgl, "glFramebufferTextureLayer"));
    proc_glFrontFace = cosmo_dltramp(cosmo_dlsym(libgl, "glFrontFace"));
    proc_glFrustum = cosmo_dltramp(cosmo_dlsym(libgl, "glFrustum"));
    proc_glGenBuffers = cosmo_dltramp(cosmo_dlsym(libgl, "glGenBuffers"));
    proc_glGenFramebuffers = cosmo_dltramp(cosmo_dlsym(libgl, "glGenFramebuffers"));
    proc_glGenLists = cosmo_dltramp(cosmo_dlsym(libgl, "glGenLists"));
    proc_glGenQueries = cosmo_dltramp(cosmo_dlsym(libgl, "glGenQueries"));
    proc_glGenRenderbuffers = cosmo_dltramp(cosmo_dlsym(libgl, "glGenRenderbuffers"));
    proc_glGenSamplers = cosmo_dltramp(cosmo_dlsym(libgl, "glGenSamplers"));
    proc_glGenTextures = cosmo_dltramp(cosmo_dlsym(libgl, "glGenTextures"));
    proc_glGenTransformFeedbacks = cosmo_dltramp(cosmo_dlsym(libgl, "glGenTransformFeedbacks"));
    proc_glGenVertexArrays = cosmo_dltramp(cosmo_dlsym(libgl, "glGenVertexArrays"));
    proc_glGenerateMipmap = cosmo_dltramp(cosmo_dlsym(libgl, "glGenerateMipmap"));
    proc_glGetActiveAttrib = cosmo_dltramp(cosmo_dlsym(libgl, "glGetActiveAttrib"));
    proc_glGetActiveSubroutineName = cosmo_dltramp(cosmo_dlsym(libgl, "glGetActiveSubroutineName"));
    proc_glGetActiveSubroutineUniformName = cosmo_dltramp(cosmo_dlsym(libgl, "glGetActiveSubroutineUniformName"));
    proc_glGetActiveSubroutineUniformiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetActiveSubroutineUniformiv"));
    proc_glGetActiveUniform = cosmo_dltramp(cosmo_dlsym(libgl, "glGetActiveUniform"));
    proc_glGetActiveUniformBlockName = cosmo_dltramp(cosmo_dlsym(libgl, "glGetActiveUniformBlockName"));
    proc_glGetActiveUniformBlockiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetActiveUniformBlockiv"));
    proc_glGetActiveUniformName = cosmo_dltramp(cosmo_dlsym(libgl, "glGetActiveUniformName"));
    proc_glGetActiveUniformsiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetActiveUniformsiv"));
    proc_glGetAttachedShaders = cosmo_dltramp(cosmo_dlsym(libgl, "glGetAttachedShaders"));
    proc_glGetAttribLocation = cosmo_dltramp(cosmo_dlsym(libgl, "glGetAttribLocation"));
    proc_glGetBooleani_v = cosmo_dltramp(cosmo_dlsym(libgl, "glGetBooleani_v"));
    proc_glGetBooleanv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetBooleanv"));
    proc_glGetBufferParameteri64v = cosmo_dltramp(cosmo_dlsym(libgl, "glGetBufferParameteri64v"));
    proc_glGetBufferParameteriv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetBufferParameteriv"));
    proc_glGetBufferPointerv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetBufferPointerv"));
    proc_glGetBufferSubData = cosmo_dltramp(cosmo_dlsym(libgl, "glGetBufferSubData"));
    proc_glGetClipPlane = cosmo_dltramp(cosmo_dlsym(libgl, "glGetClipPlane"));
    proc_glGetCompressedTexImage = cosmo_dltramp(cosmo_dlsym(libgl, "glGetCompressedTexImage"));
    proc_glGetDoublev = cosmo_dltramp(cosmo_dlsym(libgl, "glGetDoublev"));
    proc_glGetError = cosmo_dltramp(cosmo_dlsym(libgl, "glGetError"));
    proc_glGetFloatv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetFloatv"));
    proc_glGetFragDataIndex = cosmo_dltramp(cosmo_dlsym(libgl, "glGetFragDataIndex"));
    proc_glGetFragDataLocation = cosmo_dltramp(cosmo_dlsym(libgl, "glGetFragDataLocation"));
    proc_glGetFramebufferAttachmentParameteriv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetFramebufferAttachmentParameteriv"));
    proc_glGetInteger64i_v = cosmo_dltramp(cosmo_dlsym(libgl, "glGetInteger64i_v"));
    proc_glGetInteger64v = cosmo_dltramp(cosmo_dlsym(libgl, "glGetInteger64v"));
    proc_glGetIntegeri_v = cosmo_dltramp(cosmo_dlsym(libgl, "glGetIntegeri_v"));
    proc_glGetIntegerv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetIntegerv"));
    proc_glGetLightfv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetLightfv"));
    proc_glGetLightiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetLightiv"));
    proc_glGetMapdv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetMapdv"));
    proc_glGetMapfv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetMapfv"));
    proc_glGetMapiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetMapiv"));
    proc_glGetMaterialfv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetMaterialfv"));
    proc_glGetMaterialiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetMaterialiv"));
    proc_glGetMultisamplefv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetMultisamplefv"));
    proc_glGetPixelMapfv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetPixelMapfv"));
    proc_glGetPixelMapuiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetPixelMapuiv"));
    proc_glGetPixelMapusv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetPixelMapusv"));
    proc_glGetPointerv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetPointerv"));
    proc_glGetPolygonStipple = cosmo_dltramp(cosmo_dlsym(libgl, "glGetPolygonStipple"));
    proc_glGetProgramInfoLog = cosmo_dltramp(cosmo_dlsym(libgl, "glGetProgramInfoLog"));
    proc_glGetProgramStageiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetProgramStageiv"));
    proc_glGetProgramiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetProgramiv"));
    proc_glGetQueryIndexediv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetQueryIndexediv"));
    proc_glGetQueryObjecti64v = cosmo_dltramp(cosmo_dlsym(libgl, "glGetQueryObjecti64v"));
    proc_glGetQueryObjectiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetQueryObjectiv"));
    proc_glGetQueryObjectui64v = cosmo_dltramp(cosmo_dlsym(libgl, "glGetQueryObjectui64v"));
    proc_glGetQueryObjectuiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetQueryObjectuiv"));
    proc_glGetQueryiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetQueryiv"));
    proc_glGetRenderbufferParameteriv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetRenderbufferParameteriv"));
    proc_glGetSamplerParameterIiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetSamplerParameterIiv"));
    proc_glGetSamplerParameterIuiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetSamplerParameterIuiv"));
    proc_glGetSamplerParameterfv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetSamplerParameterfv"));
    proc_glGetSamplerParameteriv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetSamplerParameteriv"));
    proc_glGetShaderInfoLog = cosmo_dltramp(cosmo_dlsym(libgl, "glGetShaderInfoLog"));
    proc_glGetShaderSource = cosmo_dltramp(cosmo_dlsym(libgl, "glGetShaderSource"));
    proc_glGetShaderiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetShaderiv"));
    proc_glGetString = cosmo_dltramp(cosmo_dlsym(libgl, "glGetString"));
    proc_glGetStringi = cosmo_dltramp(cosmo_dlsym(libgl, "glGetStringi"));
    proc_glGetSubroutineIndex = cosmo_dltramp(cosmo_dlsym(libgl, "glGetSubroutineIndex"));
    proc_glGetSubroutineUniformLocation = cosmo_dltramp(cosmo_dlsym(libgl, "glGetSubroutineUniformLocation"));
    proc_glGetSynciv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetSynciv"));
    proc_glGetTexEnvfv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetTexEnvfv"));
    proc_glGetTexEnviv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetTexEnviv"));
    proc_glGetTexGendv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetTexGendv"));
    proc_glGetTexGenfv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetTexGenfv"));
    proc_glGetTexGeniv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetTexGeniv"));
    proc_glGetTexImage = cosmo_dltramp(cosmo_dlsym(libgl, "glGetTexImage"));
    proc_glGetTexLevelParameterfv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetTexLevelParameterfv"));
    proc_glGetTexLevelParameteriv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetTexLevelParameteriv"));
    proc_glGetTexParameterIiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetTexParameterIiv"));
    proc_glGetTexParameterIuiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetTexParameterIuiv"));
    proc_glGetTexParameterfv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetTexParameterfv"));
    proc_glGetTexParameteriv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetTexParameteriv"));
    proc_glGetTransformFeedbackVarying = cosmo_dltramp(cosmo_dlsym(libgl, "glGetTransformFeedbackVarying"));
    proc_glGetUniformBlockIndex = cosmo_dltramp(cosmo_dlsym(libgl, "glGetUniformBlockIndex"));
    proc_glGetUniformIndices = cosmo_dltramp(cosmo_dlsym(libgl, "glGetUniformIndices"));
    proc_glGetUniformLocation = cosmo_dltramp(cosmo_dlsym(libgl, "glGetUniformLocation"));
    proc_glGetUniformSubroutineuiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetUniformSubroutineuiv"));
    proc_glGetUniformdv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetUniformdv"));
    proc_glGetUniformfv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetUniformfv"));
    proc_glGetUniformiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetUniformiv"));
    proc_glGetUniformuiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetUniformuiv"));
    proc_glGetVertexAttribIiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetVertexAttribIiv"));
    proc_glGetVertexAttribIuiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetVertexAttribIuiv"));
    proc_glGetVertexAttribPointerv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetVertexAttribPointerv"));
    proc_glGetVertexAttribdv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetVertexAttribdv"));
    proc_glGetVertexAttribfv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetVertexAttribfv"));
    proc_glGetVertexAttribiv = cosmo_dltramp(cosmo_dlsym(libgl, "glGetVertexAttribiv"));
    proc_glHint = cosmo_dltramp(cosmo_dlsym(libgl, "glHint"));
    proc_glIndexMask = cosmo_dltramp(cosmo_dlsym(libgl, "glIndexMask"));
    proc_glIndexPointer = cosmo_dltramp(cosmo_dlsym(libgl, "glIndexPointer"));
    proc_glIndexd = cosmo_dltramp(cosmo_dlsym(libgl, "glIndexd"));
    proc_glIndexdv = cosmo_dltramp(cosmo_dlsym(libgl, "glIndexdv"));
    proc_glIndexf = cosmo_dltramp(cosmo_dlsym(libgl, "glIndexf"));
    proc_glIndexfv = cosmo_dltramp(cosmo_dlsym(libgl, "glIndexfv"));
    proc_glIndexi = cosmo_dltramp(cosmo_dlsym(libgl, "glIndexi"));
    proc_glIndexiv = cosmo_dltramp(cosmo_dlsym(libgl, "glIndexiv"));
    proc_glIndexs = cosmo_dltramp(cosmo_dlsym(libgl, "glIndexs"));
    proc_glIndexsv = cosmo_dltramp(cosmo_dlsym(libgl, "glIndexsv"));
    proc_glIndexub = cosmo_dltramp(cosmo_dlsym(libgl, "glIndexub"));
    proc_glIndexubv = cosmo_dltramp(cosmo_dlsym(libgl, "glIndexubv"));
    proc_glInitNames = cosmo_dltramp(cosmo_dlsym(libgl, "glInitNames"));
    proc_glInterleavedArrays = cosmo_dltramp(cosmo_dlsym(libgl, "glInterleavedArrays"));
    proc_glIsBuffer = cosmo_dltramp(cosmo_dlsym(libgl, "glIsBuffer"));
    proc_glIsEnabled = cosmo_dltramp(cosmo_dlsym(libgl, "glIsEnabled"));
    proc_glIsEnabledi = cosmo_dltramp(cosmo_dlsym(libgl, "glIsEnabledi"));
    proc_glIsFramebuffer = cosmo_dltramp(cosmo_dlsym(libgl, "glIsFramebuffer"));
    proc_glIsList = cosmo_dltramp(cosmo_dlsym(libgl, "glIsList"));
    proc_glIsProgram = cosmo_dltramp(cosmo_dlsym(libgl, "glIsProgram"));
    proc_glIsQuery = cosmo_dltramp(cosmo_dlsym(libgl, "glIsQuery"));
    proc_glIsRenderbuffer = cosmo_dltramp(cosmo_dlsym(libgl, "glIsRenderbuffer"));
    proc_glIsSampler = cosmo_dltramp(cosmo_dlsym(libgl, "glIsSampler"));
    proc_glIsShader = cosmo_dltramp(cosmo_dlsym(libgl, "glIsShader"));
    proc_glIsSync = cosmo_dltramp(cosmo_dlsym(libgl, "glIsSync"));
    proc_glIsTexture = cosmo_dltramp(cosmo_dlsym(libgl, "glIsTexture"));
    proc_glIsTransformFeedback = cosmo_dltramp(cosmo_dlsym(libgl, "glIsTransformFeedback"));
    proc_glIsVertexArray = cosmo_dltramp(cosmo_dlsym(libgl, "glIsVertexArray"));
    proc_glLightModelf = cosmo_dltramp(cosmo_dlsym(libgl, "glLightModelf"));
    proc_glLightModelfv = cosmo_dltramp(cosmo_dlsym(libgl, "glLightModelfv"));
    proc_glLightModeli = cosmo_dltramp(cosmo_dlsym(libgl, "glLightModeli"));
    proc_glLightModeliv = cosmo_dltramp(cosmo_dlsym(libgl, "glLightModeliv"));
    proc_glLightf = cosmo_dltramp(cosmo_dlsym(libgl, "glLightf"));
    proc_glLightfv = cosmo_dltramp(cosmo_dlsym(libgl, "glLightfv"));
    proc_glLighti = cosmo_dltramp(cosmo_dlsym(libgl, "glLighti"));
    proc_glLightiv = cosmo_dltramp(cosmo_dlsym(libgl, "glLightiv"));
    proc_glLineStipple = cosmo_dltramp(cosmo_dlsym(libgl, "glLineStipple"));
    proc_glLineWidth = cosmo_dltramp(cosmo_dlsym(libgl, "glLineWidth"));
    proc_glLinkProgram = cosmo_dltramp(cosmo_dlsym(libgl, "glLinkProgram"));
    proc_glListBase = cosmo_dltramp(cosmo_dlsym(libgl, "glListBase"));
    proc_glLoadIdentity = cosmo_dltramp(cosmo_dlsym(libgl, "glLoadIdentity"));
    proc_glLoadMatrixd = cosmo_dltramp(cosmo_dlsym(libgl, "glLoadMatrixd"));
    proc_glLoadMatrixf = cosmo_dltramp(cosmo_dlsym(libgl, "glLoadMatrixf"));
    proc_glLoadName = cosmo_dltramp(cosmo_dlsym(libgl, "glLoadName"));
    proc_glLoadTransposeMatrixd = cosmo_dltramp(cosmo_dlsym(libgl, "glLoadTransposeMatrixd"));
    proc_glLoadTransposeMatrixf = cosmo_dltramp(cosmo_dlsym(libgl, "glLoadTransposeMatrixf"));
    proc_glLogicOp = cosmo_dltramp(cosmo_dlsym(libgl, "glLogicOp"));
    proc_glMap1d = cosmo_dltramp(cosmo_dlsym(libgl, "glMap1d"));
    proc_glMap1f = cosmo_dltramp(cosmo_dlsym(libgl, "glMap1f"));
    proc_glMap2d = cosmo_dltramp(cosmo_dlsym(libgl, "glMap2d"));
    proc_glMap2f = cosmo_dltramp(cosmo_dlsym(libgl, "glMap2f"));
    proc_glMapBuffer = cosmo_dltramp(cosmo_dlsym(libgl, "glMapBuffer"));
    proc_glMapBufferRange = cosmo_dltramp(cosmo_dlsym(libgl, "glMapBufferRange"));
    proc_glMapGrid1d = cosmo_dltramp(cosmo_dlsym(libgl, "glMapGrid1d"));
    proc_glMapGrid1f = cosmo_dltramp(cosmo_dlsym(libgl, "glMapGrid1f"));
    proc_glMapGrid2d = cosmo_dltramp(cosmo_dlsym(libgl, "glMapGrid2d"));
    proc_glMapGrid2f = cosmo_dltramp(cosmo_dlsym(libgl, "glMapGrid2f"));
    proc_glMaterialf = cosmo_dltramp(cosmo_dlsym(libgl, "glMaterialf"));
    proc_glMaterialfv = cosmo_dltramp(cosmo_dlsym(libgl, "glMaterialfv"));
    proc_glMateriali = cosmo_dltramp(cosmo_dlsym(libgl, "glMateriali"));
    proc_glMaterialiv = cosmo_dltramp(cosmo_dlsym(libgl, "glMaterialiv"));
    proc_glMatrixMode = cosmo_dltramp(cosmo_dlsym(libgl, "glMatrixMode"));
    proc_glMinSampleShading = cosmo_dltramp(cosmo_dlsym(libgl, "glMinSampleShading"));
    proc_glMultMatrixd = cosmo_dltramp(cosmo_dlsym(libgl, "glMultMatrixd"));
    proc_glMultMatrixf = cosmo_dltramp(cosmo_dlsym(libgl, "glMultMatrixf"));
    proc_glMultTransposeMatrixd = cosmo_dltramp(cosmo_dlsym(libgl, "glMultTransposeMatrixd"));
    proc_glMultTransposeMatrixf = cosmo_dltramp(cosmo_dlsym(libgl, "glMultTransposeMatrixf"));
    proc_glMultiDrawArrays = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiDrawArrays"));
    proc_glMultiDrawElements = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiDrawElements"));
    proc_glMultiDrawElementsBaseVertex = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiDrawElementsBaseVertex"));
    proc_glMultiTexCoord1d = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord1d"));
    proc_glMultiTexCoord1dv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord1dv"));
    proc_glMultiTexCoord1f = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord1f"));
    proc_glMultiTexCoord1fv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord1fv"));
    proc_glMultiTexCoord1i = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord1i"));
    proc_glMultiTexCoord1iv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord1iv"));
    proc_glMultiTexCoord1s = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord1s"));
    proc_glMultiTexCoord1sv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord1sv"));
    proc_glMultiTexCoord2d = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord2d"));
    proc_glMultiTexCoord2dv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord2dv"));
    proc_glMultiTexCoord2f = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord2f"));
    proc_glMultiTexCoord2fv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord2fv"));
    proc_glMultiTexCoord2i = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord2i"));
    proc_glMultiTexCoord2iv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord2iv"));
    proc_glMultiTexCoord2s = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord2s"));
    proc_glMultiTexCoord2sv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord2sv"));
    proc_glMultiTexCoord3d = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord3d"));
    proc_glMultiTexCoord3dv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord3dv"));
    proc_glMultiTexCoord3f = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord3f"));
    proc_glMultiTexCoord3fv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord3fv"));
    proc_glMultiTexCoord3i = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord3i"));
    proc_glMultiTexCoord3iv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord3iv"));
    proc_glMultiTexCoord3s = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord3s"));
    proc_glMultiTexCoord3sv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord3sv"));
    proc_glMultiTexCoord4d = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord4d"));
    proc_glMultiTexCoord4dv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord4dv"));
    proc_glMultiTexCoord4f = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord4f"));
    proc_glMultiTexCoord4fv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord4fv"));
    proc_glMultiTexCoord4i = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord4i"));
    proc_glMultiTexCoord4iv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord4iv"));
    proc_glMultiTexCoord4s = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord4s"));
    proc_glMultiTexCoord4sv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoord4sv"));
    proc_glMultiTexCoordP1ui = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoordP1ui"));
    proc_glMultiTexCoordP1uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoordP1uiv"));
    proc_glMultiTexCoordP2ui = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoordP2ui"));
    proc_glMultiTexCoordP2uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoordP2uiv"));
    proc_glMultiTexCoordP3ui = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoordP3ui"));
    proc_glMultiTexCoordP3uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoordP3uiv"));
    proc_glMultiTexCoordP4ui = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoordP4ui"));
    proc_glMultiTexCoordP4uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glMultiTexCoordP4uiv"));
    proc_glNewList = cosmo_dltramp(cosmo_dlsym(libgl, "glNewList"));
    proc_glNormal3b = cosmo_dltramp(cosmo_dlsym(libgl, "glNormal3b"));
    proc_glNormal3bv = cosmo_dltramp(cosmo_dlsym(libgl, "glNormal3bv"));
    proc_glNormal3d = cosmo_dltramp(cosmo_dlsym(libgl, "glNormal3d"));
    proc_glNormal3dv = cosmo_dltramp(cosmo_dlsym(libgl, "glNormal3dv"));
    proc_glNormal3f = cosmo_dltramp(cosmo_dlsym(libgl, "glNormal3f"));
    proc_glNormal3fv = cosmo_dltramp(cosmo_dlsym(libgl, "glNormal3fv"));
    proc_glNormal3i = cosmo_dltramp(cosmo_dlsym(libgl, "glNormal3i"));
    proc_glNormal3iv = cosmo_dltramp(cosmo_dlsym(libgl, "glNormal3iv"));
    proc_glNormal3s = cosmo_dltramp(cosmo_dlsym(libgl, "glNormal3s"));
    proc_glNormal3sv = cosmo_dltramp(cosmo_dlsym(libgl, "glNormal3sv"));
    proc_glNormalP3ui = cosmo_dltramp(cosmo_dlsym(libgl, "glNormalP3ui"));
    proc_glNormalP3uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glNormalP3uiv"));
    proc_glNormalPointer = cosmo_dltramp(cosmo_dlsym(libgl, "glNormalPointer"));
    proc_glOrtho = cosmo_dltramp(cosmo_dlsym(libgl, "glOrtho"));
    proc_glPassThrough = cosmo_dltramp(cosmo_dlsym(libgl, "glPassThrough"));
    proc_glPatchParameterfv = cosmo_dltramp(cosmo_dlsym(libgl, "glPatchParameterfv"));
    proc_glPatchParameteri = cosmo_dltramp(cosmo_dlsym(libgl, "glPatchParameteri"));
    proc_glPauseTransformFeedback = cosmo_dltramp(cosmo_dlsym(libgl, "glPauseTransformFeedback"));
    proc_glPixelMapfv = cosmo_dltramp(cosmo_dlsym(libgl, "glPixelMapfv"));
    proc_glPixelMapuiv = cosmo_dltramp(cosmo_dlsym(libgl, "glPixelMapuiv"));
    proc_glPixelMapusv = cosmo_dltramp(cosmo_dlsym(libgl, "glPixelMapusv"));
    proc_glPixelStoref = cosmo_dltramp(cosmo_dlsym(libgl, "glPixelStoref"));
    proc_glPixelStorei = cosmo_dltramp(cosmo_dlsym(libgl, "glPixelStorei"));
    proc_glPixelTransferf = cosmo_dltramp(cosmo_dlsym(libgl, "glPixelTransferf"));
    proc_glPixelTransferi = cosmo_dltramp(cosmo_dlsym(libgl, "glPixelTransferi"));
    proc_glPixelZoom = cosmo_dltramp(cosmo_dlsym(libgl, "glPixelZoom"));
    proc_glPointParameterf = cosmo_dltramp(cosmo_dlsym(libgl, "glPointParameterf"));
    proc_glPointParameterfv = cosmo_dltramp(cosmo_dlsym(libgl, "glPointParameterfv"));
    proc_glPointParameteri = cosmo_dltramp(cosmo_dlsym(libgl, "glPointParameteri"));
    proc_glPointParameteriv = cosmo_dltramp(cosmo_dlsym(libgl, "glPointParameteriv"));
    proc_glPointSize = cosmo_dltramp(cosmo_dlsym(libgl, "glPointSize"));
    proc_glPolygonMode = cosmo_dltramp(cosmo_dlsym(libgl, "glPolygonMode"));
    proc_glPolygonOffset = cosmo_dltramp(cosmo_dlsym(libgl, "glPolygonOffset"));
    proc_glPolygonStipple = cosmo_dltramp(cosmo_dlsym(libgl, "glPolygonStipple"));
    proc_glPopAttrib = cosmo_dltramp(cosmo_dlsym(libgl, "glPopAttrib"));
    proc_glPopClientAttrib = cosmo_dltramp(cosmo_dlsym(libgl, "glPopClientAttrib"));
    proc_glPopMatrix = cosmo_dltramp(cosmo_dlsym(libgl, "glPopMatrix"));
    proc_glPopName = cosmo_dltramp(cosmo_dlsym(libgl, "glPopName"));
    proc_glPrimitiveRestartIndex = cosmo_dltramp(cosmo_dlsym(libgl, "glPrimitiveRestartIndex"));
    proc_glPrioritizeTextures = cosmo_dltramp(cosmo_dlsym(libgl, "glPrioritizeTextures"));
    proc_glProvokingVertex = cosmo_dltramp(cosmo_dlsym(libgl, "glProvokingVertex"));
    proc_glPushAttrib = cosmo_dltramp(cosmo_dlsym(libgl, "glPushAttrib"));
    proc_glPushClientAttrib = cosmo_dltramp(cosmo_dlsym(libgl, "glPushClientAttrib"));
    proc_glPushMatrix = cosmo_dltramp(cosmo_dlsym(libgl, "glPushMatrix"));
    proc_glPushName = cosmo_dltramp(cosmo_dlsym(libgl, "glPushName"));
    proc_glQueryCounter = cosmo_dltramp(cosmo_dlsym(libgl, "glQueryCounter"));
    proc_glRasterPos2d = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos2d"));
    proc_glRasterPos2dv = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos2dv"));
    proc_glRasterPos2f = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos2f"));
    proc_glRasterPos2fv = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos2fv"));
    proc_glRasterPos2i = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos2i"));
    proc_glRasterPos2iv = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos2iv"));
    proc_glRasterPos2s = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos2s"));
    proc_glRasterPos2sv = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos2sv"));
    proc_glRasterPos3d = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos3d"));
    proc_glRasterPos3dv = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos3dv"));
    proc_glRasterPos3f = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos3f"));
    proc_glRasterPos3fv = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos3fv"));
    proc_glRasterPos3i = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos3i"));
    proc_glRasterPos3iv = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos3iv"));
    proc_glRasterPos3s = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos3s"));
    proc_glRasterPos3sv = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos3sv"));
    proc_glRasterPos4d = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos4d"));
    proc_glRasterPos4dv = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos4dv"));
    proc_glRasterPos4f = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos4f"));
    proc_glRasterPos4fv = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos4fv"));
    proc_glRasterPos4i = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos4i"));
    proc_glRasterPos4iv = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos4iv"));
    proc_glRasterPos4s = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos4s"));
    proc_glRasterPos4sv = cosmo_dltramp(cosmo_dlsym(libgl, "glRasterPos4sv"));
    proc_glReadBuffer = cosmo_dltramp(cosmo_dlsym(libgl, "glReadBuffer"));
    proc_glReadPixels = cosmo_dltramp(cosmo_dlsym(libgl, "glReadPixels"));
    proc_glRectd = cosmo_dltramp(cosmo_dlsym(libgl, "glRectd"));
    proc_glRectdv = cosmo_dltramp(cosmo_dlsym(libgl, "glRectdv"));
    proc_glRectf = cosmo_dltramp(cosmo_dlsym(libgl, "glRectf"));
    proc_glRectfv = cosmo_dltramp(cosmo_dlsym(libgl, "glRectfv"));
    proc_glRecti = cosmo_dltramp(cosmo_dlsym(libgl, "glRecti"));
    proc_glRectiv = cosmo_dltramp(cosmo_dlsym(libgl, "glRectiv"));
    proc_glRects = cosmo_dltramp(cosmo_dlsym(libgl, "glRects"));
    proc_glRectsv = cosmo_dltramp(cosmo_dlsym(libgl, "glRectsv"));
    proc_glRenderMode = cosmo_dltramp(cosmo_dlsym(libgl, "glRenderMode"));
    proc_glRenderbufferStorage = cosmo_dltramp(cosmo_dlsym(libgl, "glRenderbufferStorage"));
    proc_glRenderbufferStorageMultisample = cosmo_dltramp(cosmo_dlsym(libgl, "glRenderbufferStorageMultisample"));
    proc_glResumeTransformFeedback = cosmo_dltramp(cosmo_dlsym(libgl, "glResumeTransformFeedback"));
    proc_glRotated = cosmo_dltramp(cosmo_dlsym(libgl, "glRotated"));
    proc_glRotatef = cosmo_dltramp(cosmo_dlsym(libgl, "glRotatef"));
    proc_glSampleCoverage = cosmo_dltramp(cosmo_dlsym(libgl, "glSampleCoverage"));
    proc_glSampleMaski = cosmo_dltramp(cosmo_dlsym(libgl, "glSampleMaski"));
    proc_glSamplerParameterIiv = cosmo_dltramp(cosmo_dlsym(libgl, "glSamplerParameterIiv"));
    proc_glSamplerParameterIuiv = cosmo_dltramp(cosmo_dlsym(libgl, "glSamplerParameterIuiv"));
    proc_glSamplerParameterf = cosmo_dltramp(cosmo_dlsym(libgl, "glSamplerParameterf"));
    proc_glSamplerParameterfv = cosmo_dltramp(cosmo_dlsym(libgl, "glSamplerParameterfv"));
    proc_glSamplerParameteri = cosmo_dltramp(cosmo_dlsym(libgl, "glSamplerParameteri"));
    proc_glSamplerParameteriv = cosmo_dltramp(cosmo_dlsym(libgl, "glSamplerParameteriv"));
    proc_glScaled = cosmo_dltramp(cosmo_dlsym(libgl, "glScaled"));
    proc_glScalef = cosmo_dltramp(cosmo_dlsym(libgl, "glScalef"));
    proc_glScissor = cosmo_dltramp(cosmo_dlsym(libgl, "glScissor"));
    proc_glSecondaryColor3b = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColor3b"));
    proc_glSecondaryColor3bv = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColor3bv"));
    proc_glSecondaryColor3d = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColor3d"));
    proc_glSecondaryColor3dv = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColor3dv"));
    proc_glSecondaryColor3f = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColor3f"));
    proc_glSecondaryColor3fv = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColor3fv"));
    proc_glSecondaryColor3i = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColor3i"));
    proc_glSecondaryColor3iv = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColor3iv"));
    proc_glSecondaryColor3s = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColor3s"));
    proc_glSecondaryColor3sv = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColor3sv"));
    proc_glSecondaryColor3ub = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColor3ub"));
    proc_glSecondaryColor3ubv = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColor3ubv"));
    proc_glSecondaryColor3ui = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColor3ui"));
    proc_glSecondaryColor3uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColor3uiv"));
    proc_glSecondaryColor3us = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColor3us"));
    proc_glSecondaryColor3usv = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColor3usv"));
    proc_glSecondaryColorP3ui = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColorP3ui"));
    proc_glSecondaryColorP3uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColorP3uiv"));
    proc_glSecondaryColorPointer = cosmo_dltramp(cosmo_dlsym(libgl, "glSecondaryColorPointer"));
    proc_glSelectBuffer = cosmo_dltramp(cosmo_dlsym(libgl, "glSelectBuffer"));
    proc_glShadeModel = cosmo_dltramp(cosmo_dlsym(libgl, "glShadeModel"));
    proc_glShaderSource = cosmo_dltramp(cosmo_dlsym(libgl, "glShaderSource"));
    proc_glStencilFunc = cosmo_dltramp(cosmo_dlsym(libgl, "glStencilFunc"));
    proc_glStencilFuncSeparate = cosmo_dltramp(cosmo_dlsym(libgl, "glStencilFuncSeparate"));
    proc_glStencilMask = cosmo_dltramp(cosmo_dlsym(libgl, "glStencilMask"));
    proc_glStencilMaskSeparate = cosmo_dltramp(cosmo_dlsym(libgl, "glStencilMaskSeparate"));
    proc_glStencilOp = cosmo_dltramp(cosmo_dlsym(libgl, "glStencilOp"));
    proc_glStencilOpSeparate = cosmo_dltramp(cosmo_dlsym(libgl, "glStencilOpSeparate"));
    proc_glTexBuffer = cosmo_dltramp(cosmo_dlsym(libgl, "glTexBuffer"));
    proc_glTexCoord1d = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord1d"));
    proc_glTexCoord1dv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord1dv"));
    proc_glTexCoord1f = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord1f"));
    proc_glTexCoord1fv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord1fv"));
    proc_glTexCoord1i = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord1i"));
    proc_glTexCoord1iv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord1iv"));
    proc_glTexCoord1s = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord1s"));
    proc_glTexCoord1sv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord1sv"));
    proc_glTexCoord2d = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord2d"));
    proc_glTexCoord2dv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord2dv"));
    proc_glTexCoord2f = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord2f"));
    proc_glTexCoord2fv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord2fv"));
    proc_glTexCoord2i = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord2i"));
    proc_glTexCoord2iv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord2iv"));
    proc_glTexCoord2s = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord2s"));
    proc_glTexCoord2sv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord2sv"));
    proc_glTexCoord3d = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord3d"));
    proc_glTexCoord3dv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord3dv"));
    proc_glTexCoord3f = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord3f"));
    proc_glTexCoord3fv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord3fv"));
    proc_glTexCoord3i = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord3i"));
    proc_glTexCoord3iv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord3iv"));
    proc_glTexCoord3s = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord3s"));
    proc_glTexCoord3sv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord3sv"));
    proc_glTexCoord4d = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord4d"));
    proc_glTexCoord4dv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord4dv"));
    proc_glTexCoord4f = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord4f"));
    proc_glTexCoord4fv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord4fv"));
    proc_glTexCoord4i = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord4i"));
    proc_glTexCoord4iv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord4iv"));
    proc_glTexCoord4s = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord4s"));
    proc_glTexCoord4sv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoord4sv"));
    proc_glTexCoordP1ui = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoordP1ui"));
    proc_glTexCoordP1uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoordP1uiv"));
    proc_glTexCoordP2ui = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoordP2ui"));
    proc_glTexCoordP2uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoordP2uiv"));
    proc_glTexCoordP3ui = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoordP3ui"));
    proc_glTexCoordP3uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoordP3uiv"));
    proc_glTexCoordP4ui = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoordP4ui"));
    proc_glTexCoordP4uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoordP4uiv"));
    proc_glTexCoordPointer = cosmo_dltramp(cosmo_dlsym(libgl, "glTexCoordPointer"));
    proc_glTexEnvf = cosmo_dltramp(cosmo_dlsym(libgl, "glTexEnvf"));
    proc_glTexEnvfv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexEnvfv"));
    proc_glTexEnvi = cosmo_dltramp(cosmo_dlsym(libgl, "glTexEnvi"));
    proc_glTexEnviv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexEnviv"));
    proc_glTexGend = cosmo_dltramp(cosmo_dlsym(libgl, "glTexGend"));
    proc_glTexGendv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexGendv"));
    proc_glTexGenf = cosmo_dltramp(cosmo_dlsym(libgl, "glTexGenf"));
    proc_glTexGenfv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexGenfv"));
    proc_glTexGeni = cosmo_dltramp(cosmo_dlsym(libgl, "glTexGeni"));
    proc_glTexGeniv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexGeniv"));
    proc_glTexImage1D = cosmo_dltramp(cosmo_dlsym(libgl, "glTexImage1D"));
    proc_glTexImage2D = cosmo_dltramp(cosmo_dlsym(libgl, "glTexImage2D"));
    proc_glTexImage2DMultisample = cosmo_dltramp(cosmo_dlsym(libgl, "glTexImage2DMultisample"));
    proc_glTexImage3D = cosmo_dltramp(cosmo_dlsym(libgl, "glTexImage3D"));
    proc_glTexImage3DMultisample = cosmo_dltramp(cosmo_dlsym(libgl, "glTexImage3DMultisample"));
    proc_glTexParameterIiv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexParameterIiv"));
    proc_glTexParameterIuiv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexParameterIuiv"));
    proc_glTexParameterf = cosmo_dltramp(cosmo_dlsym(libgl, "glTexParameterf"));
    proc_glTexParameterfv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexParameterfv"));
    proc_glTexParameteri = cosmo_dltramp(cosmo_dlsym(libgl, "glTexParameteri"));
    proc_glTexParameteriv = cosmo_dltramp(cosmo_dlsym(libgl, "glTexParameteriv"));
    proc_glTexSubImage1D = cosmo_dltramp(cosmo_dlsym(libgl, "glTexSubImage1D"));
    proc_glTexSubImage2D = cosmo_dltramp(cosmo_dlsym(libgl, "glTexSubImage2D"));
    proc_glTexSubImage3D = cosmo_dltramp(cosmo_dlsym(libgl, "glTexSubImage3D"));
    proc_glTransformFeedbackVaryings = cosmo_dltramp(cosmo_dlsym(libgl, "glTransformFeedbackVaryings"));
    proc_glTranslated = cosmo_dltramp(cosmo_dlsym(libgl, "glTranslated"));
    proc_glTranslatef = cosmo_dltramp(cosmo_dlsym(libgl, "glTranslatef"));
    proc_glUniform1d = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform1d"));
    proc_glUniform1dv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform1dv"));
    proc_glUniform1f = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform1f"));
    proc_glUniform1fv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform1fv"));
    proc_glUniform1i = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform1i"));
    proc_glUniform1iv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform1iv"));
    proc_glUniform1ui = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform1ui"));
    proc_glUniform1uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform1uiv"));
    proc_glUniform2d = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform2d"));
    proc_glUniform2dv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform2dv"));
    proc_glUniform2f = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform2f"));
    proc_glUniform2fv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform2fv"));
    proc_glUniform2i = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform2i"));
    proc_glUniform2iv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform2iv"));
    proc_glUniform2ui = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform2ui"));
    proc_glUniform2uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform2uiv"));
    proc_glUniform3d = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform3d"));
    proc_glUniform3dv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform3dv"));
    proc_glUniform3f = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform3f"));
    proc_glUniform3fv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform3fv"));
    proc_glUniform3i = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform3i"));
    proc_glUniform3iv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform3iv"));
    proc_glUniform3ui = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform3ui"));
    proc_glUniform3uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform3uiv"));
    proc_glUniform4d = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform4d"));
    proc_glUniform4dv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform4dv"));
    proc_glUniform4f = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform4f"));
    proc_glUniform4fv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform4fv"));
    proc_glUniform4i = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform4i"));
    proc_glUniform4iv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform4iv"));
    proc_glUniform4ui = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform4ui"));
    proc_glUniform4uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniform4uiv"));
    proc_glUniformBlockBinding = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformBlockBinding"));
    proc_glUniformMatrix2dv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformMatrix2dv"));
    proc_glUniformMatrix2fv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformMatrix2fv"));
    proc_glUniformMatrix2x3dv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformMatrix2x3dv"));
    proc_glUniformMatrix2x3fv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformMatrix2x3fv"));
    proc_glUniformMatrix2x4dv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformMatrix2x4dv"));
    proc_glUniformMatrix2x4fv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformMatrix2x4fv"));
    proc_glUniformMatrix3dv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformMatrix3dv"));
    proc_glUniformMatrix3fv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformMatrix3fv"));
    proc_glUniformMatrix3x2dv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformMatrix3x2dv"));
    proc_glUniformMatrix3x2fv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformMatrix3x2fv"));
    proc_glUniformMatrix3x4dv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformMatrix3x4dv"));
    proc_glUniformMatrix3x4fv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformMatrix3x4fv"));
    proc_glUniformMatrix4dv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformMatrix4dv"));
    proc_glUniformMatrix4fv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformMatrix4fv"));
    proc_glUniformMatrix4x2dv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformMatrix4x2dv"));
    proc_glUniformMatrix4x2fv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformMatrix4x2fv"));
    proc_glUniformMatrix4x3dv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformMatrix4x3dv"));
    proc_glUniformMatrix4x3fv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformMatrix4x3fv"));
    proc_glUniformSubroutinesuiv = cosmo_dltramp(cosmo_dlsym(libgl, "glUniformSubroutinesuiv"));
    proc_glUnmapBuffer = cosmo_dltramp(cosmo_dlsym(libgl, "glUnmapBuffer"));
    proc_glUseProgram = cosmo_dltramp(cosmo_dlsym(libgl, "glUseProgram"));
    proc_glValidateProgram = cosmo_dltramp(cosmo_dlsym(libgl, "glValidateProgram"));
    proc_glVertex2d = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex2d"));
    proc_glVertex2dv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex2dv"));
    proc_glVertex2f = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex2f"));
    proc_glVertex2fv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex2fv"));
    proc_glVertex2i = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex2i"));
    proc_glVertex2iv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex2iv"));
    proc_glVertex2s = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex2s"));
    proc_glVertex2sv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex2sv"));
    proc_glVertex3d = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex3d"));
    proc_glVertex3dv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex3dv"));
    proc_glVertex3f = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex3f"));
    proc_glVertex3fv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex3fv"));
    proc_glVertex3i = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex3i"));
    proc_glVertex3iv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex3iv"));
    proc_glVertex3s = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex3s"));
    proc_glVertex3sv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex3sv"));
    proc_glVertex4d = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex4d"));
    proc_glVertex4dv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex4dv"));
    proc_glVertex4f = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex4f"));
    proc_glVertex4fv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex4fv"));
    proc_glVertex4i = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex4i"));
    proc_glVertex4iv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex4iv"));
    proc_glVertex4s = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex4s"));
    proc_glVertex4sv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertex4sv"));
    proc_glVertexAttrib1d = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib1d"));
    proc_glVertexAttrib1dv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib1dv"));
    proc_glVertexAttrib1f = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib1f"));
    proc_glVertexAttrib1fv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib1fv"));
    proc_glVertexAttrib1s = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib1s"));
    proc_glVertexAttrib1sv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib1sv"));
    proc_glVertexAttrib2d = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib2d"));
    proc_glVertexAttrib2dv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib2dv"));
    proc_glVertexAttrib2f = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib2f"));
    proc_glVertexAttrib2fv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib2fv"));
    proc_glVertexAttrib2s = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib2s"));
    proc_glVertexAttrib2sv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib2sv"));
    proc_glVertexAttrib3d = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib3d"));
    proc_glVertexAttrib3dv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib3dv"));
    proc_glVertexAttrib3f = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib3f"));
    proc_glVertexAttrib3fv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib3fv"));
    proc_glVertexAttrib3s = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib3s"));
    proc_glVertexAttrib3sv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib3sv"));
    proc_glVertexAttrib4Nbv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib4Nbv"));
    proc_glVertexAttrib4Niv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib4Niv"));
    proc_glVertexAttrib4Nsv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib4Nsv"));
    proc_glVertexAttrib4Nub = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib4Nub"));
    proc_glVertexAttrib4Nubv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib4Nubv"));
    proc_glVertexAttrib4Nuiv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib4Nuiv"));
    proc_glVertexAttrib4Nusv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib4Nusv"));
    proc_glVertexAttrib4bv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib4bv"));
    proc_glVertexAttrib4d = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib4d"));
    proc_glVertexAttrib4dv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib4dv"));
    proc_glVertexAttrib4f = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib4f"));
    proc_glVertexAttrib4fv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib4fv"));
    proc_glVertexAttrib4iv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib4iv"));
    proc_glVertexAttrib4s = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib4s"));
    proc_glVertexAttrib4sv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib4sv"));
    proc_glVertexAttrib4ubv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib4ubv"));
    proc_glVertexAttrib4uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib4uiv"));
    proc_glVertexAttrib4usv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttrib4usv"));
    proc_glVertexAttribDivisor = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribDivisor"));
    proc_glVertexAttribI1i = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI1i"));
    proc_glVertexAttribI1iv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI1iv"));
    proc_glVertexAttribI1ui = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI1ui"));
    proc_glVertexAttribI1uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI1uiv"));
    proc_glVertexAttribI2i = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI2i"));
    proc_glVertexAttribI2iv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI2iv"));
    proc_glVertexAttribI2ui = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI2ui"));
    proc_glVertexAttribI2uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI2uiv"));
    proc_glVertexAttribI3i = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI3i"));
    proc_glVertexAttribI3iv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI3iv"));
    proc_glVertexAttribI3ui = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI3ui"));
    proc_glVertexAttribI3uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI3uiv"));
    proc_glVertexAttribI4bv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI4bv"));
    proc_glVertexAttribI4i = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI4i"));
    proc_glVertexAttribI4iv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI4iv"));
    proc_glVertexAttribI4sv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI4sv"));
    proc_glVertexAttribI4ubv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI4ubv"));
    proc_glVertexAttribI4ui = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI4ui"));
    proc_glVertexAttribI4uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI4uiv"));
    proc_glVertexAttribI4usv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribI4usv"));
    proc_glVertexAttribIPointer = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribIPointer"));
    proc_glVertexAttribP1ui = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribP1ui"));
    proc_glVertexAttribP1uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribP1uiv"));
    proc_glVertexAttribP2ui = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribP2ui"));
    proc_glVertexAttribP2uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribP2uiv"));
    proc_glVertexAttribP3ui = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribP3ui"));
    proc_glVertexAttribP3uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribP3uiv"));
    proc_glVertexAttribP4ui = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribP4ui"));
    proc_glVertexAttribP4uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribP4uiv"));
    proc_glVertexAttribPointer = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexAttribPointer"));
    proc_glVertexP2ui = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexP2ui"));
    proc_glVertexP2uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexP2uiv"));
    proc_glVertexP3ui = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexP3ui"));
    proc_glVertexP3uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexP3uiv"));
    proc_glVertexP4ui = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexP4ui"));
    proc_glVertexP4uiv = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexP4uiv"));
    proc_glVertexPointer = cosmo_dltramp(cosmo_dlsym(libgl, "glVertexPointer"));
    proc_glViewport = cosmo_dltramp(cosmo_dlsym(libgl, "glViewport"));
    proc_glWaitSync = cosmo_dltramp(cosmo_dlsym(libgl, "glWaitSync"));
    proc_glWindowPos2d = cosmo_dltramp(cosmo_dlsym(libgl, "glWindowPos2d"));
    proc_glWindowPos2dv = cosmo_dltramp(cosmo_dlsym(libgl, "glWindowPos2dv"));
    proc_glWindowPos2f = cosmo_dltramp(cosmo_dlsym(libgl, "glWindowPos2f"));
    proc_glWindowPos2fv = cosmo_dltramp(cosmo_dlsym(libgl, "glWindowPos2fv"));
    proc_glWindowPos2i = cosmo_dltramp(cosmo_dlsym(libgl, "glWindowPos2i"));
    proc_glWindowPos2iv = cosmo_dltramp(cosmo_dlsym(libgl, "glWindowPos2iv"));
    proc_glWindowPos2s = cosmo_dltramp(cosmo_dlsym(libgl, "glWindowPos2s"));
    proc_glWindowPos2sv = cosmo_dltramp(cosmo_dlsym(libgl, "glWindowPos2sv"));
    proc_glWindowPos3d = cosmo_dltramp(cosmo_dlsym(libgl, "glWindowPos3d"));
    proc_glWindowPos3dv = cosmo_dltramp(cosmo_dlsym(libgl, "glWindowPos3dv"));
    proc_glWindowPos3f = cosmo_dltramp(cosmo_dlsym(libgl, "glWindowPos3f"));
    proc_glWindowPos3fv = cosmo_dltramp(cosmo_dlsym(libgl, "glWindowPos3fv"));
    proc_glWindowPos3i = cosmo_dltramp(cosmo_dlsym(libgl, "glWindowPos3i"));
    proc_glWindowPos3iv = cosmo_dltramp(cosmo_dlsym(libgl, "glWindowPos3iv"));
    proc_glWindowPos3s = cosmo_dltramp(cosmo_dlsym(libgl, "glWindowPos3s"));
    proc_glWindowPos3sv = cosmo_dltramp(cosmo_dlsym(libgl, "glWindowPos3sv"));
}

void glAccum(GLenum op, GLfloat value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glAccum(op, value);
}

void glActiveTexture(GLenum texture) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glActiveTexture(texture);
}

void glAlphaFunc(GLenum func, GLfloat ref) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glAlphaFunc(func, ref);
}

GLboolean glAreTexturesResident(GLsizei n, const GLuint * textures, GLboolean * residences) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glAreTexturesResident(n, textures, residences);
}

void glArrayElement(GLint i) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glArrayElement(i);
}

void glAttachShader(GLuint program, GLuint shader) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glAttachShader(program, shader);
}

void glBegin(GLenum mode) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBegin(mode);
}

void glBeginConditionalRender(GLuint id, GLenum mode) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBeginConditionalRender(id, mode);
}

void glBeginQuery(GLenum target, GLuint id) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBeginQuery(target, id);
}

void glBeginQueryIndexed(GLenum target, GLuint index, GLuint id) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBeginQueryIndexed(target, index, id);
}

void glBeginTransformFeedback(GLenum primitiveMode) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBeginTransformFeedback(primitiveMode);
}

void glBindAttribLocation(GLuint program, GLuint index, const GLchar * name) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBindAttribLocation(program, index, name);
}

void glBindBuffer(GLenum target, GLuint buffer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBindBuffer(target, buffer);
}

void glBindBufferBase(GLenum target, GLuint index, GLuint buffer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBindBufferBase(target, index, buffer);
}

void glBindBufferRange(GLenum target, GLuint index, GLuint buffer, GLintptr offset, GLsizeiptr size) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBindBufferRange(target, index, buffer, offset, size);
}

void glBindFragDataLocation(GLuint program, GLuint color, const GLchar * name) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBindFragDataLocation(program, color, name);
}

void glBindFragDataLocationIndexed(GLuint program, GLuint colorNumber, GLuint index, const GLchar * name) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBindFragDataLocationIndexed(program, colorNumber, index, name);
}

void glBindFramebuffer(GLenum target, GLuint framebuffer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBindFramebuffer(target, framebuffer);
}

void glBindRenderbuffer(GLenum target, GLuint renderbuffer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBindRenderbuffer(target, renderbuffer);
}

void glBindSampler(GLuint unit, GLuint sampler) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBindSampler(unit, sampler);
}

void glBindTexture(GLenum target, GLuint texture) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBindTexture(target, texture);
}

void glBindTransformFeedback(GLenum target, GLuint id) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBindTransformFeedback(target, id);
}

void glBindVertexArray(GLuint array) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBindVertexArray(array);
}

void glBitmap(GLsizei width, GLsizei height, GLfloat xorig, GLfloat yorig, GLfloat xmove, GLfloat ymove, const GLubyte * bitmap) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBitmap(width, height, xorig, yorig, xmove, ymove, bitmap);
}

void glBlendColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBlendColor(red, green, blue, alpha);
}

void glBlendEquation(GLenum mode) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBlendEquation(mode);
}

void glBlendEquationSeparate(GLenum modeRGB, GLenum modeAlpha) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBlendEquationSeparate(modeRGB, modeAlpha);
}

void glBlendEquationSeparatei(GLuint buf, GLenum modeRGB, GLenum modeAlpha) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBlendEquationSeparatei(buf, modeRGB, modeAlpha);
}

void glBlendEquationi(GLuint buf, GLenum mode) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBlendEquationi(buf, mode);
}

void glBlendFunc(GLenum sfactor, GLenum dfactor) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBlendFunc(sfactor, dfactor);
}

void glBlendFuncSeparate(GLenum sfactorRGB, GLenum dfactorRGB, GLenum sfactorAlpha, GLenum dfactorAlpha) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBlendFuncSeparate(sfactorRGB, dfactorRGB, sfactorAlpha, dfactorAlpha);
}

void glBlendFuncSeparatei(GLuint buf, GLenum srcRGB, GLenum dstRGB, GLenum srcAlpha, GLenum dstAlpha) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBlendFuncSeparatei(buf, srcRGB, dstRGB, srcAlpha, dstAlpha);
}

void glBlendFunci(GLuint buf, GLenum src, GLenum dst) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBlendFunci(buf, src, dst);
}

void glBlitFramebuffer(GLint srcX0, GLint srcY0, GLint srcX1, GLint srcY1, GLint dstX0, GLint dstY0, GLint dstX1, GLint dstY1, GLbitfield mask, GLenum filter) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBlitFramebuffer(srcX0, srcY0, srcX1, srcY1, dstX0, dstY0, dstX1, dstY1, mask, filter);
}

void glBufferData(GLenum target, GLsizeiptr size, const void * data, GLenum usage) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBufferData(target, size, data, usage);
}

void glBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, const void * data) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glBufferSubData(target, offset, size, data);
}

void glCallList(GLuint list) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glCallList(list);
}

void glCallLists(GLsizei n, GLenum type, const void * lists) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glCallLists(n, type, lists);
}

GLenum glCheckFramebufferStatus(GLenum target) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glCheckFramebufferStatus(target);
}

void glClampColor(GLenum target, GLenum clamp) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glClampColor(target, clamp);
}

void glClear(GLbitfield mask) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glClear(mask);
}

void glClearAccum(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glClearAccum(red, green, blue, alpha);
}

void glClearBufferfi(GLenum buffer, GLint drawbuffer, GLfloat depth, GLint stencil) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glClearBufferfi(buffer, drawbuffer, depth, stencil);
}

void glClearBufferfv(GLenum buffer, GLint drawbuffer, const GLfloat * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glClearBufferfv(buffer, drawbuffer, value);
}

void glClearBufferiv(GLenum buffer, GLint drawbuffer, const GLint * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glClearBufferiv(buffer, drawbuffer, value);
}

void glClearBufferuiv(GLenum buffer, GLint drawbuffer, const GLuint * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glClearBufferuiv(buffer, drawbuffer, value);
}

void glClearColor(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glClearColor(red, green, blue, alpha);
}

void glClearDepth(GLdouble depth) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glClearDepth(depth);
}

void glClearIndex(GLfloat c) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glClearIndex(c);
}

void glClearStencil(GLint s) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glClearStencil(s);
}

void glClientActiveTexture(GLenum texture) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glClientActiveTexture(texture);
}

GLenum glClientWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glClientWaitSync(sync, flags, timeout);
}

void glClipPlane(GLenum plane, const GLdouble * equation) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glClipPlane(plane, equation);
}

void glColor3b(GLbyte red, GLbyte green, GLbyte blue) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor3b(red, green, blue);
}

void glColor3bv(const GLbyte * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor3bv(v);
}

void glColor3d(GLdouble red, GLdouble green, GLdouble blue) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor3d(red, green, blue);
}

void glColor3dv(const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor3dv(v);
}

void glColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor3f(red, green, blue);
}

void glColor3fv(const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor3fv(v);
}

void glColor3i(GLint red, GLint green, GLint blue) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor3i(red, green, blue);
}

void glColor3iv(const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor3iv(v);
}

void glColor3s(GLshort red, GLshort green, GLshort blue) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor3s(red, green, blue);
}

void glColor3sv(const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor3sv(v);
}

void glColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor3ub(red, green, blue);
}

void glColor3ubv(const GLubyte * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor3ubv(v);
}

void glColor3ui(GLuint red, GLuint green, GLuint blue) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor3ui(red, green, blue);
}

void glColor3uiv(const GLuint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor3uiv(v);
}

void glColor3us(GLushort red, GLushort green, GLushort blue) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor3us(red, green, blue);
}

void glColor3usv(const GLushort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor3usv(v);
}

void glColor4b(GLbyte red, GLbyte green, GLbyte blue, GLbyte alpha) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor4b(red, green, blue, alpha);
}

void glColor4bv(const GLbyte * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor4bv(v);
}

void glColor4d(GLdouble red, GLdouble green, GLdouble blue, GLdouble alpha) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor4d(red, green, blue, alpha);
}

void glColor4dv(const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor4dv(v);
}

void glColor4f(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor4f(red, green, blue, alpha);
}

void glColor4fv(const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor4fv(v);
}

void glColor4i(GLint red, GLint green, GLint blue, GLint alpha) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor4i(red, green, blue, alpha);
}

void glColor4iv(const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor4iv(v);
}

void glColor4s(GLshort red, GLshort green, GLshort blue, GLshort alpha) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor4s(red, green, blue, alpha);
}

void glColor4sv(const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor4sv(v);
}

void glColor4ub(GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor4ub(red, green, blue, alpha);
}

void glColor4ubv(const GLubyte * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor4ubv(v);
}

void glColor4ui(GLuint red, GLuint green, GLuint blue, GLuint alpha) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor4ui(red, green, blue, alpha);
}

void glColor4uiv(const GLuint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor4uiv(v);
}

void glColor4us(GLushort red, GLushort green, GLushort blue, GLushort alpha) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor4us(red, green, blue, alpha);
}

void glColor4usv(const GLushort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColor4usv(v);
}

void glColorMask(GLboolean red, GLboolean green, GLboolean blue, GLboolean alpha) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColorMask(red, green, blue, alpha);
}

void glColorMaski(GLuint index, GLboolean r, GLboolean g, GLboolean b, GLboolean a) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColorMaski(index, r, g, b, a);
}

void glColorMaterial(GLenum face, GLenum mode) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColorMaterial(face, mode);
}

void glColorP3ui(GLenum type, GLuint color) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColorP3ui(type, color);
}

void glColorP3uiv(GLenum type, const GLuint * color) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColorP3uiv(type, color);
}

void glColorP4ui(GLenum type, GLuint color) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColorP4ui(type, color);
}

void glColorP4uiv(GLenum type, const GLuint * color) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColorP4uiv(type, color);
}

void glColorPointer(GLint size, GLenum type, GLsizei stride, const void * pointer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glColorPointer(size, type, stride, pointer);
}

void glCompileShader(GLuint shader) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glCompileShader(shader);
}

void glCompressedTexImage1D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLint border, GLsizei imageSize, const void * data) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glCompressedTexImage1D(target, level, internalformat, width, border, imageSize, data);
}

void glCompressedTexImage2D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLint border, GLsizei imageSize, const void * data) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glCompressedTexImage2D(target, level, internalformat, width, height, border, imageSize, data);
}

void glCompressedTexImage3D(GLenum target, GLint level, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLsizei imageSize, const void * data) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glCompressedTexImage3D(target, level, internalformat, width, height, depth, border, imageSize, data);
}

void glCompressedTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLsizei imageSize, const void * data) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glCompressedTexSubImage1D(target, level, xoffset, width, format, imageSize, data);
}

void glCompressedTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLsizei imageSize, const void * data) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glCompressedTexSubImage2D(target, level, xoffset, yoffset, width, height, format, imageSize, data);
}

void glCompressedTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLsizei imageSize, const void * data) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glCompressedTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, imageSize, data);
}

void glCopyBufferSubData(GLenum readTarget, GLenum writeTarget, GLintptr readOffset, GLintptr writeOffset, GLsizeiptr size) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glCopyBufferSubData(readTarget, writeTarget, readOffset, writeOffset, size);
}

void glCopyPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum type) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glCopyPixels(x, y, width, height, type);
}

void glCopyTexImage1D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLint border) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glCopyTexImage1D(target, level, internalformat, x, y, width, border);
}

void glCopyTexImage2D(GLenum target, GLint level, GLenum internalformat, GLint x, GLint y, GLsizei width, GLsizei height, GLint border) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glCopyTexImage2D(target, level, internalformat, x, y, width, height, border);
}

void glCopyTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLint x, GLint y, GLsizei width) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glCopyTexSubImage1D(target, level, xoffset, x, y, width);
}

void glCopyTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glCopyTexSubImage2D(target, level, xoffset, yoffset, x, y, width, height);
}

void glCopyTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLint x, GLint y, GLsizei width, GLsizei height) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glCopyTexSubImage3D(target, level, xoffset, yoffset, zoffset, x, y, width, height);
}

GLuint glCreateProgram(void) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glCreateProgram();
}

GLuint glCreateShader(GLenum type) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glCreateShader(type);
}

void glCullFace(GLenum mode) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glCullFace(mode);
}

void glDeleteBuffers(GLsizei n, const GLuint * buffers) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDeleteBuffers(n, buffers);
}

void glDeleteFramebuffers(GLsizei n, const GLuint * framebuffers) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDeleteFramebuffers(n, framebuffers);
}

void glDeleteLists(GLuint list, GLsizei range) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDeleteLists(list, range);
}

void glDeleteProgram(GLuint program) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDeleteProgram(program);
}

void glDeleteQueries(GLsizei n, const GLuint * ids) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDeleteQueries(n, ids);
}

void glDeleteRenderbuffers(GLsizei n, const GLuint * renderbuffers) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDeleteRenderbuffers(n, renderbuffers);
}

void glDeleteSamplers(GLsizei count, const GLuint * samplers) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDeleteSamplers(count, samplers);
}

void glDeleteShader(GLuint shader) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDeleteShader(shader);
}

void glDeleteSync(GLsync sync) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDeleteSync(sync);
}

void glDeleteTextures(GLsizei n, const GLuint * textures) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDeleteTextures(n, textures);
}

void glDeleteTransformFeedbacks(GLsizei n, const GLuint * ids) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDeleteTransformFeedbacks(n, ids);
}

void glDeleteVertexArrays(GLsizei n, const GLuint * arrays) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDeleteVertexArrays(n, arrays);
}

void glDepthFunc(GLenum func) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDepthFunc(func);
}

void glDepthMask(GLboolean flag) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDepthMask(flag);
}

void glDepthRange(GLdouble n, GLdouble f) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDepthRange(n, f);
}

void glDetachShader(GLuint program, GLuint shader) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDetachShader(program, shader);
}

void glDisable(GLenum cap) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDisable(cap);
}

void glDisableClientState(GLenum array) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDisableClientState(array);
}

void glDisableVertexAttribArray(GLuint index) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDisableVertexAttribArray(index);
}

void glDisablei(GLenum target, GLuint index) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDisablei(target, index);
}

void glDrawArrays(GLenum mode, GLint first, GLsizei count) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDrawArrays(mode, first, count);
}

void glDrawArraysIndirect(GLenum mode, const void * indirect) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDrawArraysIndirect(mode, indirect);
}

void glDrawArraysInstanced(GLenum mode, GLint first, GLsizei count, GLsizei instancecount) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDrawArraysInstanced(mode, first, count, instancecount);
}

void glDrawBuffer(GLenum buf) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDrawBuffer(buf);
}

void glDrawBuffers(GLsizei n, const GLenum * bufs) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDrawBuffers(n, bufs);
}

void glDrawElements(GLenum mode, GLsizei count, GLenum type, const void * indices) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDrawElements(mode, count, type, indices);
}

void glDrawElementsBaseVertex(GLenum mode, GLsizei count, GLenum type, const void * indices, GLint basevertex) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDrawElementsBaseVertex(mode, count, type, indices, basevertex);
}

void glDrawElementsIndirect(GLenum mode, GLenum type, const void * indirect) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDrawElementsIndirect(mode, type, indirect);
}

void glDrawElementsInstanced(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDrawElementsInstanced(mode, count, type, indices, instancecount);
}

void glDrawElementsInstancedBaseVertex(GLenum mode, GLsizei count, GLenum type, const void * indices, GLsizei instancecount, GLint basevertex) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDrawElementsInstancedBaseVertex(mode, count, type, indices, instancecount, basevertex);
}

void glDrawPixels(GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDrawPixels(width, height, format, type, pixels);
}

void glDrawRangeElements(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDrawRangeElements(mode, start, end, count, type, indices);
}

void glDrawRangeElementsBaseVertex(GLenum mode, GLuint start, GLuint end, GLsizei count, GLenum type, const void * indices, GLint basevertex) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDrawRangeElementsBaseVertex(mode, start, end, count, type, indices, basevertex);
}

void glDrawTransformFeedback(GLenum mode, GLuint id) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDrawTransformFeedback(mode, id);
}

void glDrawTransformFeedbackStream(GLenum mode, GLuint id, GLuint stream) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glDrawTransformFeedbackStream(mode, id, stream);
}

void glEdgeFlag(GLboolean flag) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEdgeFlag(flag);
}

void glEdgeFlagPointer(GLsizei stride, const void * pointer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEdgeFlagPointer(stride, pointer);
}

void glEdgeFlagv(const GLboolean * flag) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEdgeFlagv(flag);
}

void glEnable(GLenum cap) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEnable(cap);
}

void glEnableClientState(GLenum array) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEnableClientState(array);
}

void glEnableVertexAttribArray(GLuint index) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEnableVertexAttribArray(index);
}

void glEnablei(GLenum target, GLuint index) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEnablei(target, index);
}

void glEnd(void) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEnd();
}

void glEndConditionalRender(void) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEndConditionalRender();
}

void glEndList(void) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEndList();
}

void glEndQuery(GLenum target) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEndQuery(target);
}

void glEndQueryIndexed(GLenum target, GLuint index) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEndQueryIndexed(target, index);
}

void glEndTransformFeedback(void) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEndTransformFeedback();
}

void glEvalCoord1d(GLdouble u) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEvalCoord1d(u);
}

void glEvalCoord1dv(const GLdouble * u) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEvalCoord1dv(u);
}

void glEvalCoord1f(GLfloat u) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEvalCoord1f(u);
}

void glEvalCoord1fv(const GLfloat * u) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEvalCoord1fv(u);
}

void glEvalCoord2d(GLdouble u, GLdouble v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEvalCoord2d(u, v);
}

void glEvalCoord2dv(const GLdouble * u) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEvalCoord2dv(u);
}

void glEvalCoord2f(GLfloat u, GLfloat v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEvalCoord2f(u, v);
}

void glEvalCoord2fv(const GLfloat * u) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEvalCoord2fv(u);
}

void glEvalMesh1(GLenum mode, GLint i1, GLint i2) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEvalMesh1(mode, i1, i2);
}

void glEvalMesh2(GLenum mode, GLint i1, GLint i2, GLint j1, GLint j2) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEvalMesh2(mode, i1, i2, j1, j2);
}

void glEvalPoint1(GLint i) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEvalPoint1(i);
}

void glEvalPoint2(GLint i, GLint j) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glEvalPoint2(i, j);
}

void glFeedbackBuffer(GLsizei size, GLenum type, GLfloat * buffer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFeedbackBuffer(size, type, buffer);
}

GLsync glFenceSync(GLenum condition, GLbitfield flags) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glFenceSync(condition, flags);
}

void glFinish(void) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFinish();
}

void glFlush(void) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFlush();
}

void glFlushMappedBufferRange(GLenum target, GLintptr offset, GLsizeiptr length) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFlushMappedBufferRange(target, offset, length);
}

void glFogCoordPointer(GLenum type, GLsizei stride, const void * pointer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFogCoordPointer(type, stride, pointer);
}

void glFogCoordd(GLdouble coord) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFogCoordd(coord);
}

void glFogCoorddv(const GLdouble * coord) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFogCoorddv(coord);
}

void glFogCoordf(GLfloat coord) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFogCoordf(coord);
}

void glFogCoordfv(const GLfloat * coord) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFogCoordfv(coord);
}

void glFogf(GLenum pname, GLfloat param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFogf(pname, param);
}

void glFogfv(GLenum pname, const GLfloat * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFogfv(pname, params);
}

void glFogi(GLenum pname, GLint param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFogi(pname, param);
}

void glFogiv(GLenum pname, const GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFogiv(pname, params);
}

void glFramebufferRenderbuffer(GLenum target, GLenum attachment, GLenum renderbuffertarget, GLuint renderbuffer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFramebufferRenderbuffer(target, attachment, renderbuffertarget, renderbuffer);
}

void glFramebufferTexture(GLenum target, GLenum attachment, GLuint texture, GLint level) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFramebufferTexture(target, attachment, texture, level);
}

void glFramebufferTexture1D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFramebufferTexture1D(target, attachment, textarget, texture, level);
}

void glFramebufferTexture2D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFramebufferTexture2D(target, attachment, textarget, texture, level);
}

void glFramebufferTexture3D(GLenum target, GLenum attachment, GLenum textarget, GLuint texture, GLint level, GLint zoffset) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFramebufferTexture3D(target, attachment, textarget, texture, level, zoffset);
}

void glFramebufferTextureLayer(GLenum target, GLenum attachment, GLuint texture, GLint level, GLint layer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFramebufferTextureLayer(target, attachment, texture, level, layer);
}

void glFrontFace(GLenum mode) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFrontFace(mode);
}

void glFrustum(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glFrustum(left, right, bottom, top, zNear, zFar);
}

void glGenBuffers(GLsizei n, GLuint * buffers) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGenBuffers(n, buffers);
}

void glGenFramebuffers(GLsizei n, GLuint * framebuffers) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGenFramebuffers(n, framebuffers);
}

GLuint glGenLists(GLsizei range) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glGenLists(range);
}

void glGenQueries(GLsizei n, GLuint * ids) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGenQueries(n, ids);
}

void glGenRenderbuffers(GLsizei n, GLuint * renderbuffers) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGenRenderbuffers(n, renderbuffers);
}

void glGenSamplers(GLsizei count, GLuint * samplers) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGenSamplers(count, samplers);
}

void glGenTextures(GLsizei n, GLuint * textures) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGenTextures(n, textures);
}

void glGenTransformFeedbacks(GLsizei n, GLuint * ids) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGenTransformFeedbacks(n, ids);
}

void glGenVertexArrays(GLsizei n, GLuint * arrays) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGenVertexArrays(n, arrays);
}

void glGenerateMipmap(GLenum target) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGenerateMipmap(target);
}

void glGetActiveAttrib(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetActiveAttrib(program, index, bufSize, length, size, type, name);
}

void glGetActiveSubroutineName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetActiveSubroutineName(program, shadertype, index, bufSize, length, name);
}

void glGetActiveSubroutineUniformName(GLuint program, GLenum shadertype, GLuint index, GLsizei bufSize, GLsizei * length, GLchar * name) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetActiveSubroutineUniformName(program, shadertype, index, bufSize, length, name);
}

void glGetActiveSubroutineUniformiv(GLuint program, GLenum shadertype, GLuint index, GLenum pname, GLint * values) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetActiveSubroutineUniformiv(program, shadertype, index, pname, values);
}

void glGetActiveUniform(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLint * size, GLenum * type, GLchar * name) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetActiveUniform(program, index, bufSize, length, size, type, name);
}

void glGetActiveUniformBlockName(GLuint program, GLuint uniformBlockIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformBlockName) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetActiveUniformBlockName(program, uniformBlockIndex, bufSize, length, uniformBlockName);
}

void glGetActiveUniformBlockiv(GLuint program, GLuint uniformBlockIndex, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetActiveUniformBlockiv(program, uniformBlockIndex, pname, params);
}

void glGetActiveUniformName(GLuint program, GLuint uniformIndex, GLsizei bufSize, GLsizei * length, GLchar * uniformName) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetActiveUniformName(program, uniformIndex, bufSize, length, uniformName);
}

void glGetActiveUniformsiv(GLuint program, GLsizei uniformCount, const GLuint * uniformIndices, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetActiveUniformsiv(program, uniformCount, uniformIndices, pname, params);
}

void glGetAttachedShaders(GLuint program, GLsizei maxCount, GLsizei * count, GLuint * shaders) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetAttachedShaders(program, maxCount, count, shaders);
}

GLint glGetAttribLocation(GLuint program, const GLchar * name) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glGetAttribLocation(program, name);
}

void glGetBooleani_v(GLenum target, GLuint index, GLboolean * data) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetBooleani_v(target, index, data);
}

void glGetBooleanv(GLenum pname, GLboolean * data) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetBooleanv(pname, data);
}

void glGetBufferParameteri64v(GLenum target, GLenum pname, GLint64 * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetBufferParameteri64v(target, pname, params);
}

void glGetBufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetBufferParameteriv(target, pname, params);
}

void glGetBufferPointerv(GLenum target, GLenum pname, void ** params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetBufferPointerv(target, pname, params);
}

void glGetBufferSubData(GLenum target, GLintptr offset, GLsizeiptr size, void * data) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetBufferSubData(target, offset, size, data);
}

void glGetClipPlane(GLenum plane, GLdouble * equation) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetClipPlane(plane, equation);
}

void glGetCompressedTexImage(GLenum target, GLint level, void * img) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetCompressedTexImage(target, level, img);
}

void glGetDoublev(GLenum pname, GLdouble * data) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetDoublev(pname, data);
}

GLenum glGetError(void) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glGetError();
}

void glGetFloatv(GLenum pname, GLfloat * data) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetFloatv(pname, data);
}

GLint glGetFragDataIndex(GLuint program, const GLchar * name) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glGetFragDataIndex(program, name);
}

GLint glGetFragDataLocation(GLuint program, const GLchar * name) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glGetFragDataLocation(program, name);
}

void glGetFramebufferAttachmentParameteriv(GLenum target, GLenum attachment, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetFramebufferAttachmentParameteriv(target, attachment, pname, params);
}

void glGetInteger64i_v(GLenum target, GLuint index, GLint64 * data) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetInteger64i_v(target, index, data);
}

void glGetInteger64v(GLenum pname, GLint64 * data) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetInteger64v(pname, data);
}

void glGetIntegeri_v(GLenum target, GLuint index, GLint * data) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetIntegeri_v(target, index, data);
}

void glGetIntegerv(GLenum pname, GLint * data) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetIntegerv(pname, data);
}

void glGetLightfv(GLenum light, GLenum pname, GLfloat * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetLightfv(light, pname, params);
}

void glGetLightiv(GLenum light, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetLightiv(light, pname, params);
}

void glGetMapdv(GLenum target, GLenum query, GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetMapdv(target, query, v);
}

void glGetMapfv(GLenum target, GLenum query, GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetMapfv(target, query, v);
}

void glGetMapiv(GLenum target, GLenum query, GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetMapiv(target, query, v);
}

void glGetMaterialfv(GLenum face, GLenum pname, GLfloat * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetMaterialfv(face, pname, params);
}

void glGetMaterialiv(GLenum face, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetMaterialiv(face, pname, params);
}

void glGetMultisamplefv(GLenum pname, GLuint index, GLfloat * val) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetMultisamplefv(pname, index, val);
}

void glGetPixelMapfv(GLenum map, GLfloat * values) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetPixelMapfv(map, values);
}

void glGetPixelMapuiv(GLenum map, GLuint * values) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetPixelMapuiv(map, values);
}

void glGetPixelMapusv(GLenum map, GLushort * values) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetPixelMapusv(map, values);
}

void glGetPointerv(GLenum pname, void ** params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetPointerv(pname, params);
}

void glGetPolygonStipple(GLubyte * mask) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetPolygonStipple(mask);
}

void glGetProgramInfoLog(GLuint program, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetProgramInfoLog(program, bufSize, length, infoLog);
}

void glGetProgramStageiv(GLuint program, GLenum shadertype, GLenum pname, GLint * values) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetProgramStageiv(program, shadertype, pname, values);
}

void glGetProgramiv(GLuint program, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetProgramiv(program, pname, params);
}

void glGetQueryIndexediv(GLenum target, GLuint index, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetQueryIndexediv(target, index, pname, params);
}

void glGetQueryObjecti64v(GLuint id, GLenum pname, GLint64 * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetQueryObjecti64v(id, pname, params);
}

void glGetQueryObjectiv(GLuint id, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetQueryObjectiv(id, pname, params);
}

void glGetQueryObjectui64v(GLuint id, GLenum pname, GLuint64 * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetQueryObjectui64v(id, pname, params);
}

void glGetQueryObjectuiv(GLuint id, GLenum pname, GLuint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetQueryObjectuiv(id, pname, params);
}

void glGetQueryiv(GLenum target, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetQueryiv(target, pname, params);
}

void glGetRenderbufferParameteriv(GLenum target, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetRenderbufferParameteriv(target, pname, params);
}

void glGetSamplerParameterIiv(GLuint sampler, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetSamplerParameterIiv(sampler, pname, params);
}

void glGetSamplerParameterIuiv(GLuint sampler, GLenum pname, GLuint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetSamplerParameterIuiv(sampler, pname, params);
}

void glGetSamplerParameterfv(GLuint sampler, GLenum pname, GLfloat * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetSamplerParameterfv(sampler, pname, params);
}

void glGetSamplerParameteriv(GLuint sampler, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetSamplerParameteriv(sampler, pname, params);
}

void glGetShaderInfoLog(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * infoLog) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetShaderInfoLog(shader, bufSize, length, infoLog);
}

void glGetShaderSource(GLuint shader, GLsizei bufSize, GLsizei * length, GLchar * source) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetShaderSource(shader, bufSize, length, source);
}

void glGetShaderiv(GLuint shader, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetShaderiv(shader, pname, params);
}

const GLubyte * glGetString(GLenum name) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glGetString(name);
}

const GLubyte * glGetStringi(GLenum name, GLuint index) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glGetStringi(name, index);
}

GLuint glGetSubroutineIndex(GLuint program, GLenum shadertype, const GLchar * name) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glGetSubroutineIndex(program, shadertype, name);
}

GLint glGetSubroutineUniformLocation(GLuint program, GLenum shadertype, const GLchar * name) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glGetSubroutineUniformLocation(program, shadertype, name);
}

void glGetSynciv(GLsync sync, GLenum pname, GLsizei count, GLsizei * length, GLint * values) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetSynciv(sync, pname, count, length, values);
}

void glGetTexEnvfv(GLenum target, GLenum pname, GLfloat * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetTexEnvfv(target, pname, params);
}

void glGetTexEnviv(GLenum target, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetTexEnviv(target, pname, params);
}

void glGetTexGendv(GLenum coord, GLenum pname, GLdouble * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetTexGendv(coord, pname, params);
}

void glGetTexGenfv(GLenum coord, GLenum pname, GLfloat * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetTexGenfv(coord, pname, params);
}

void glGetTexGeniv(GLenum coord, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetTexGeniv(coord, pname, params);
}

void glGetTexImage(GLenum target, GLint level, GLenum format, GLenum type, void * pixels) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetTexImage(target, level, format, type, pixels);
}

void glGetTexLevelParameterfv(GLenum target, GLint level, GLenum pname, GLfloat * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetTexLevelParameterfv(target, level, pname, params);
}

void glGetTexLevelParameteriv(GLenum target, GLint level, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetTexLevelParameteriv(target, level, pname, params);
}

void glGetTexParameterIiv(GLenum target, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetTexParameterIiv(target, pname, params);
}

void glGetTexParameterIuiv(GLenum target, GLenum pname, GLuint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetTexParameterIuiv(target, pname, params);
}

void glGetTexParameterfv(GLenum target, GLenum pname, GLfloat * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetTexParameterfv(target, pname, params);
}

void glGetTexParameteriv(GLenum target, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetTexParameteriv(target, pname, params);
}

void glGetTransformFeedbackVarying(GLuint program, GLuint index, GLsizei bufSize, GLsizei * length, GLsizei * size, GLenum * type, GLchar * name) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetTransformFeedbackVarying(program, index, bufSize, length, size, type, name);
}

GLuint glGetUniformBlockIndex(GLuint program, const GLchar * uniformBlockName) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glGetUniformBlockIndex(program, uniformBlockName);
}

void glGetUniformIndices(GLuint program, GLsizei uniformCount, const GLchar *const* uniformNames, GLuint * uniformIndices) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetUniformIndices(program, uniformCount, uniformNames, uniformIndices);
}

GLint glGetUniformLocation(GLuint program, const GLchar * name) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glGetUniformLocation(program, name);
}

void glGetUniformSubroutineuiv(GLenum shadertype, GLint location, GLuint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetUniformSubroutineuiv(shadertype, location, params);
}

void glGetUniformdv(GLuint program, GLint location, GLdouble * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetUniformdv(program, location, params);
}

void glGetUniformfv(GLuint program, GLint location, GLfloat * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetUniformfv(program, location, params);
}

void glGetUniformiv(GLuint program, GLint location, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetUniformiv(program, location, params);
}

void glGetUniformuiv(GLuint program, GLint location, GLuint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetUniformuiv(program, location, params);
}

void glGetVertexAttribIiv(GLuint index, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetVertexAttribIiv(index, pname, params);
}

void glGetVertexAttribIuiv(GLuint index, GLenum pname, GLuint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetVertexAttribIuiv(index, pname, params);
}

void glGetVertexAttribPointerv(GLuint index, GLenum pname, void ** pointer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetVertexAttribPointerv(index, pname, pointer);
}

void glGetVertexAttribdv(GLuint index, GLenum pname, GLdouble * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetVertexAttribdv(index, pname, params);
}

void glGetVertexAttribfv(GLuint index, GLenum pname, GLfloat * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetVertexAttribfv(index, pname, params);
}

void glGetVertexAttribiv(GLuint index, GLenum pname, GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glGetVertexAttribiv(index, pname, params);
}

void glHint(GLenum target, GLenum mode) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glHint(target, mode);
}

void glIndexMask(GLuint mask) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glIndexMask(mask);
}

void glIndexPointer(GLenum type, GLsizei stride, const void * pointer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glIndexPointer(type, stride, pointer);
}

void glIndexd(GLdouble c) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glIndexd(c);
}

void glIndexdv(const GLdouble * c) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glIndexdv(c);
}

void glIndexf(GLfloat c) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glIndexf(c);
}

void glIndexfv(const GLfloat * c) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glIndexfv(c);
}

void glIndexi(GLint c) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glIndexi(c);
}

void glIndexiv(const GLint * c) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glIndexiv(c);
}

void glIndexs(GLshort c) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glIndexs(c);
}

void glIndexsv(const GLshort * c) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glIndexsv(c);
}

void glIndexub(GLubyte c) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glIndexub(c);
}

void glIndexubv(const GLubyte * c) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glIndexubv(c);
}

void glInitNames(void) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glInitNames();
}

void glInterleavedArrays(GLenum format, GLsizei stride, const void * pointer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glInterleavedArrays(format, stride, pointer);
}

GLboolean glIsBuffer(GLuint buffer) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glIsBuffer(buffer);
}

GLboolean glIsEnabled(GLenum cap) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glIsEnabled(cap);
}

GLboolean glIsEnabledi(GLenum target, GLuint index) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glIsEnabledi(target, index);
}

GLboolean glIsFramebuffer(GLuint framebuffer) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glIsFramebuffer(framebuffer);
}

GLboolean glIsList(GLuint list) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glIsList(list);
}

GLboolean glIsProgram(GLuint program) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glIsProgram(program);
}

GLboolean glIsQuery(GLuint id) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glIsQuery(id);
}

GLboolean glIsRenderbuffer(GLuint renderbuffer) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glIsRenderbuffer(renderbuffer);
}

GLboolean glIsSampler(GLuint sampler) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glIsSampler(sampler);
}

GLboolean glIsShader(GLuint shader) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glIsShader(shader);
}

GLboolean glIsSync(GLsync sync) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glIsSync(sync);
}

GLboolean glIsTexture(GLuint texture) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glIsTexture(texture);
}

GLboolean glIsTransformFeedback(GLuint id) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glIsTransformFeedback(id);
}

GLboolean glIsVertexArray(GLuint array) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glIsVertexArray(array);
}

void glLightModelf(GLenum pname, GLfloat param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glLightModelf(pname, param);
}

void glLightModelfv(GLenum pname, const GLfloat * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glLightModelfv(pname, params);
}

void glLightModeli(GLenum pname, GLint param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glLightModeli(pname, param);
}

void glLightModeliv(GLenum pname, const GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glLightModeliv(pname, params);
}

void glLightf(GLenum light, GLenum pname, GLfloat param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glLightf(light, pname, param);
}

void glLightfv(GLenum light, GLenum pname, const GLfloat * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glLightfv(light, pname, params);
}

void glLighti(GLenum light, GLenum pname, GLint param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glLighti(light, pname, param);
}

void glLightiv(GLenum light, GLenum pname, const GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glLightiv(light, pname, params);
}

void glLineStipple(GLint factor, GLushort pattern) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glLineStipple(factor, pattern);
}

void glLineWidth(GLfloat width) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glLineWidth(width);
}

void glLinkProgram(GLuint program) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glLinkProgram(program);
}

void glListBase(GLuint base) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glListBase(base);
}

void glLoadIdentity(void) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glLoadIdentity();
}

void glLoadMatrixd(const GLdouble * m) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glLoadMatrixd(m);
}

void glLoadMatrixf(const GLfloat * m) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glLoadMatrixf(m);
}

void glLoadName(GLuint name) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glLoadName(name);
}

void glLoadTransposeMatrixd(const GLdouble * m) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glLoadTransposeMatrixd(m);
}

void glLoadTransposeMatrixf(const GLfloat * m) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glLoadTransposeMatrixf(m);
}

void glLogicOp(GLenum opcode) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glLogicOp(opcode);
}

void glMap1d(GLenum target, GLdouble u1, GLdouble u2, GLint stride, GLint order, const GLdouble * points) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMap1d(target, u1, u2, stride, order, points);
}

void glMap1f(GLenum target, GLfloat u1, GLfloat u2, GLint stride, GLint order, const GLfloat * points) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMap1f(target, u1, u2, stride, order, points);
}

void glMap2d(GLenum target, GLdouble u1, GLdouble u2, GLint ustride, GLint uorder, GLdouble v1, GLdouble v2, GLint vstride, GLint vorder, const GLdouble * points) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMap2d(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

void glMap2f(GLenum target, GLfloat u1, GLfloat u2, GLint ustride, GLint uorder, GLfloat v1, GLfloat v2, GLint vstride, GLint vorder, const GLfloat * points) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMap2f(target, u1, u2, ustride, uorder, v1, v2, vstride, vorder, points);
}

void * glMapBuffer(GLenum target, GLenum access) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glMapBuffer(target, access);
}

void * glMapBufferRange(GLenum target, GLintptr offset, GLsizeiptr length, GLbitfield access) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glMapBufferRange(target, offset, length, access);
}

void glMapGrid1d(GLint un, GLdouble u1, GLdouble u2) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMapGrid1d(un, u1, u2);
}

void glMapGrid1f(GLint un, GLfloat u1, GLfloat u2) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMapGrid1f(un, u1, u2);
}

void glMapGrid2d(GLint un, GLdouble u1, GLdouble u2, GLint vn, GLdouble v1, GLdouble v2) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMapGrid2d(un, u1, u2, vn, v1, v2);
}

void glMapGrid2f(GLint un, GLfloat u1, GLfloat u2, GLint vn, GLfloat v1, GLfloat v2) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMapGrid2f(un, u1, u2, vn, v1, v2);
}

void glMaterialf(GLenum face, GLenum pname, GLfloat param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMaterialf(face, pname, param);
}

void glMaterialfv(GLenum face, GLenum pname, const GLfloat * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMaterialfv(face, pname, params);
}

void glMateriali(GLenum face, GLenum pname, GLint param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMateriali(face, pname, param);
}

void glMaterialiv(GLenum face, GLenum pname, const GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMaterialiv(face, pname, params);
}

void glMatrixMode(GLenum mode) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMatrixMode(mode);
}

void glMinSampleShading(GLfloat value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMinSampleShading(value);
}

void glMultMatrixd(const GLdouble * m) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultMatrixd(m);
}

void glMultMatrixf(const GLfloat * m) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultMatrixf(m);
}

void glMultTransposeMatrixd(const GLdouble * m) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultTransposeMatrixd(m);
}

void glMultTransposeMatrixf(const GLfloat * m) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultTransposeMatrixf(m);
}

void glMultiDrawArrays(GLenum mode, const GLint * first, const GLsizei * count, GLsizei drawcount) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiDrawArrays(mode, first, count, drawcount);
}

void glMultiDrawElements(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiDrawElements(mode, count, type, indices, drawcount);
}

void glMultiDrawElementsBaseVertex(GLenum mode, const GLsizei * count, GLenum type, const void *const* indices, GLsizei drawcount, const GLint * basevertex) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiDrawElementsBaseVertex(mode, count, type, indices, drawcount, basevertex);
}

void glMultiTexCoord1d(GLenum target, GLdouble s) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord1d(target, s);
}

void glMultiTexCoord1dv(GLenum target, const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord1dv(target, v);
}

void glMultiTexCoord1f(GLenum target, GLfloat s) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord1f(target, s);
}

void glMultiTexCoord1fv(GLenum target, const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord1fv(target, v);
}

void glMultiTexCoord1i(GLenum target, GLint s) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord1i(target, s);
}

void glMultiTexCoord1iv(GLenum target, const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord1iv(target, v);
}

void glMultiTexCoord1s(GLenum target, GLshort s) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord1s(target, s);
}

void glMultiTexCoord1sv(GLenum target, const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord1sv(target, v);
}

void glMultiTexCoord2d(GLenum target, GLdouble s, GLdouble t) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord2d(target, s, t);
}

void glMultiTexCoord2dv(GLenum target, const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord2dv(target, v);
}

void glMultiTexCoord2f(GLenum target, GLfloat s, GLfloat t) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord2f(target, s, t);
}

void glMultiTexCoord2fv(GLenum target, const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord2fv(target, v);
}

void glMultiTexCoord2i(GLenum target, GLint s, GLint t) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord2i(target, s, t);
}

void glMultiTexCoord2iv(GLenum target, const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord2iv(target, v);
}

void glMultiTexCoord2s(GLenum target, GLshort s, GLshort t) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord2s(target, s, t);
}

void glMultiTexCoord2sv(GLenum target, const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord2sv(target, v);
}

void glMultiTexCoord3d(GLenum target, GLdouble s, GLdouble t, GLdouble r) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord3d(target, s, t, r);
}

void glMultiTexCoord3dv(GLenum target, const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord3dv(target, v);
}

void glMultiTexCoord3f(GLenum target, GLfloat s, GLfloat t, GLfloat r) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord3f(target, s, t, r);
}

void glMultiTexCoord3fv(GLenum target, const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord3fv(target, v);
}

void glMultiTexCoord3i(GLenum target, GLint s, GLint t, GLint r) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord3i(target, s, t, r);
}

void glMultiTexCoord3iv(GLenum target, const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord3iv(target, v);
}

void glMultiTexCoord3s(GLenum target, GLshort s, GLshort t, GLshort r) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord3s(target, s, t, r);
}

void glMultiTexCoord3sv(GLenum target, const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord3sv(target, v);
}

void glMultiTexCoord4d(GLenum target, GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord4d(target, s, t, r, q);
}

void glMultiTexCoord4dv(GLenum target, const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord4dv(target, v);
}

void glMultiTexCoord4f(GLenum target, GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord4f(target, s, t, r, q);
}

void glMultiTexCoord4fv(GLenum target, const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord4fv(target, v);
}

void glMultiTexCoord4i(GLenum target, GLint s, GLint t, GLint r, GLint q) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord4i(target, s, t, r, q);
}

void glMultiTexCoord4iv(GLenum target, const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord4iv(target, v);
}

void glMultiTexCoord4s(GLenum target, GLshort s, GLshort t, GLshort r, GLshort q) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord4s(target, s, t, r, q);
}

void glMultiTexCoord4sv(GLenum target, const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoord4sv(target, v);
}

void glMultiTexCoordP1ui(GLenum texture, GLenum type, GLuint coords) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoordP1ui(texture, type, coords);
}

void glMultiTexCoordP1uiv(GLenum texture, GLenum type, const GLuint * coords) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoordP1uiv(texture, type, coords);
}

void glMultiTexCoordP2ui(GLenum texture, GLenum type, GLuint coords) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoordP2ui(texture, type, coords);
}

void glMultiTexCoordP2uiv(GLenum texture, GLenum type, const GLuint * coords) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoordP2uiv(texture, type, coords);
}

void glMultiTexCoordP3ui(GLenum texture, GLenum type, GLuint coords) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoordP3ui(texture, type, coords);
}

void glMultiTexCoordP3uiv(GLenum texture, GLenum type, const GLuint * coords) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoordP3uiv(texture, type, coords);
}

void glMultiTexCoordP4ui(GLenum texture, GLenum type, GLuint coords) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoordP4ui(texture, type, coords);
}

void glMultiTexCoordP4uiv(GLenum texture, GLenum type, const GLuint * coords) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glMultiTexCoordP4uiv(texture, type, coords);
}

void glNewList(GLuint list, GLenum mode) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glNewList(list, mode);
}

void glNormal3b(GLbyte nx, GLbyte ny, GLbyte nz) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glNormal3b(nx, ny, nz);
}

void glNormal3bv(const GLbyte * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glNormal3bv(v);
}

void glNormal3d(GLdouble nx, GLdouble ny, GLdouble nz) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glNormal3d(nx, ny, nz);
}

void glNormal3dv(const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glNormal3dv(v);
}

void glNormal3f(GLfloat nx, GLfloat ny, GLfloat nz) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glNormal3f(nx, ny, nz);
}

void glNormal3fv(const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glNormal3fv(v);
}

void glNormal3i(GLint nx, GLint ny, GLint nz) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glNormal3i(nx, ny, nz);
}

void glNormal3iv(const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glNormal3iv(v);
}

void glNormal3s(GLshort nx, GLshort ny, GLshort nz) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glNormal3s(nx, ny, nz);
}

void glNormal3sv(const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glNormal3sv(v);
}

void glNormalP3ui(GLenum type, GLuint coords) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glNormalP3ui(type, coords);
}

void glNormalP3uiv(GLenum type, const GLuint * coords) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glNormalP3uiv(type, coords);
}

void glNormalPointer(GLenum type, GLsizei stride, const void * pointer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glNormalPointer(type, stride, pointer);
}

void glOrtho(GLdouble left, GLdouble right, GLdouble bottom, GLdouble top, GLdouble zNear, GLdouble zFar) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glOrtho(left, right, bottom, top, zNear, zFar);
}

void glPassThrough(GLfloat token) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPassThrough(token);
}

void glPatchParameterfv(GLenum pname, const GLfloat * values) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPatchParameterfv(pname, values);
}

void glPatchParameteri(GLenum pname, GLint value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPatchParameteri(pname, value);
}

void glPauseTransformFeedback(void) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPauseTransformFeedback();
}

void glPixelMapfv(GLenum map, GLsizei mapsize, const GLfloat * values) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPixelMapfv(map, mapsize, values);
}

void glPixelMapuiv(GLenum map, GLsizei mapsize, const GLuint * values) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPixelMapuiv(map, mapsize, values);
}

void glPixelMapusv(GLenum map, GLsizei mapsize, const GLushort * values) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPixelMapusv(map, mapsize, values);
}

void glPixelStoref(GLenum pname, GLfloat param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPixelStoref(pname, param);
}

void glPixelStorei(GLenum pname, GLint param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPixelStorei(pname, param);
}

void glPixelTransferf(GLenum pname, GLfloat param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPixelTransferf(pname, param);
}

void glPixelTransferi(GLenum pname, GLint param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPixelTransferi(pname, param);
}

void glPixelZoom(GLfloat xfactor, GLfloat yfactor) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPixelZoom(xfactor, yfactor);
}

void glPointParameterf(GLenum pname, GLfloat param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPointParameterf(pname, param);
}

void glPointParameterfv(GLenum pname, const GLfloat * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPointParameterfv(pname, params);
}

void glPointParameteri(GLenum pname, GLint param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPointParameteri(pname, param);
}

void glPointParameteriv(GLenum pname, const GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPointParameteriv(pname, params);
}

void glPointSize(GLfloat size) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPointSize(size);
}

void glPolygonMode(GLenum face, GLenum mode) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPolygonMode(face, mode);
}

void glPolygonOffset(GLfloat factor, GLfloat units) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPolygonOffset(factor, units);
}

void glPolygonStipple(const GLubyte * mask) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPolygonStipple(mask);
}

void glPopAttrib(void) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPopAttrib();
}

void glPopClientAttrib(void) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPopClientAttrib();
}

void glPopMatrix(void) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPopMatrix();
}

void glPopName(void) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPopName();
}

void glPrimitiveRestartIndex(GLuint index) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPrimitiveRestartIndex(index);
}

void glPrioritizeTextures(GLsizei n, const GLuint * textures, const GLfloat * priorities) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPrioritizeTextures(n, textures, priorities);
}

void glProvokingVertex(GLenum mode) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glProvokingVertex(mode);
}

void glPushAttrib(GLbitfield mask) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPushAttrib(mask);
}

void glPushClientAttrib(GLbitfield mask) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPushClientAttrib(mask);
}

void glPushMatrix(void) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPushMatrix();
}

void glPushName(GLuint name) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glPushName(name);
}

void glQueryCounter(GLuint id, GLenum target) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glQueryCounter(id, target);
}

void glRasterPos2d(GLdouble x, GLdouble y) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos2d(x, y);
}

void glRasterPos2dv(const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos2dv(v);
}

void glRasterPos2f(GLfloat x, GLfloat y) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos2f(x, y);
}

void glRasterPos2fv(const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos2fv(v);
}

void glRasterPos2i(GLint x, GLint y) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos2i(x, y);
}

void glRasterPos2iv(const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos2iv(v);
}

void glRasterPos2s(GLshort x, GLshort y) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos2s(x, y);
}

void glRasterPos2sv(const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos2sv(v);
}

void glRasterPos3d(GLdouble x, GLdouble y, GLdouble z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos3d(x, y, z);
}

void glRasterPos3dv(const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos3dv(v);
}

void glRasterPos3f(GLfloat x, GLfloat y, GLfloat z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos3f(x, y, z);
}

void glRasterPos3fv(const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos3fv(v);
}

void glRasterPos3i(GLint x, GLint y, GLint z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos3i(x, y, z);
}

void glRasterPos3iv(const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos3iv(v);
}

void glRasterPos3s(GLshort x, GLshort y, GLshort z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos3s(x, y, z);
}

void glRasterPos3sv(const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos3sv(v);
}

void glRasterPos4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos4d(x, y, z, w);
}

void glRasterPos4dv(const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos4dv(v);
}

void glRasterPos4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos4f(x, y, z, w);
}

void glRasterPos4fv(const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos4fv(v);
}

void glRasterPos4i(GLint x, GLint y, GLint z, GLint w) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos4i(x, y, z, w);
}

void glRasterPos4iv(const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos4iv(v);
}

void glRasterPos4s(GLshort x, GLshort y, GLshort z, GLshort w) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos4s(x, y, z, w);
}

void glRasterPos4sv(const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRasterPos4sv(v);
}

void glReadBuffer(GLenum src) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glReadBuffer(src);
}

void glReadPixels(GLint x, GLint y, GLsizei width, GLsizei height, GLenum format, GLenum type, void * pixels) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glReadPixels(x, y, width, height, format, type, pixels);
}

void glRectd(GLdouble x1, GLdouble y1, GLdouble x2, GLdouble y2) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRectd(x1, y1, x2, y2);
}

void glRectdv(const GLdouble * v1, const GLdouble * v2) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRectdv(v1, v2);
}

void glRectf(GLfloat x1, GLfloat y1, GLfloat x2, GLfloat y2) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRectf(x1, y1, x2, y2);
}

void glRectfv(const GLfloat * v1, const GLfloat * v2) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRectfv(v1, v2);
}

void glRecti(GLint x1, GLint y1, GLint x2, GLint y2) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRecti(x1, y1, x2, y2);
}

void glRectiv(const GLint * v1, const GLint * v2) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRectiv(v1, v2);
}

void glRects(GLshort x1, GLshort y1, GLshort x2, GLshort y2) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRects(x1, y1, x2, y2);
}

void glRectsv(const GLshort * v1, const GLshort * v2) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRectsv(v1, v2);
}

GLint glRenderMode(GLenum mode) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glRenderMode(mode);
}

void glRenderbufferStorage(GLenum target, GLenum internalformat, GLsizei width, GLsizei height) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRenderbufferStorage(target, internalformat, width, height);
}

void glRenderbufferStorageMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRenderbufferStorageMultisample(target, samples, internalformat, width, height);
}

void glResumeTransformFeedback(void) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glResumeTransformFeedback();
}

void glRotated(GLdouble angle, GLdouble x, GLdouble y, GLdouble z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRotated(angle, x, y, z);
}

void glRotatef(GLfloat angle, GLfloat x, GLfloat y, GLfloat z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glRotatef(angle, x, y, z);
}

void glSampleCoverage(GLfloat value, GLboolean invert) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSampleCoverage(value, invert);
}

void glSampleMaski(GLuint maskNumber, GLbitfield mask) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSampleMaski(maskNumber, mask);
}

void glSamplerParameterIiv(GLuint sampler, GLenum pname, const GLint * param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSamplerParameterIiv(sampler, pname, param);
}

void glSamplerParameterIuiv(GLuint sampler, GLenum pname, const GLuint * param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSamplerParameterIuiv(sampler, pname, param);
}

void glSamplerParameterf(GLuint sampler, GLenum pname, GLfloat param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSamplerParameterf(sampler, pname, param);
}

void glSamplerParameterfv(GLuint sampler, GLenum pname, const GLfloat * param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSamplerParameterfv(sampler, pname, param);
}

void glSamplerParameteri(GLuint sampler, GLenum pname, GLint param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSamplerParameteri(sampler, pname, param);
}

void glSamplerParameteriv(GLuint sampler, GLenum pname, const GLint * param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSamplerParameteriv(sampler, pname, param);
}

void glScaled(GLdouble x, GLdouble y, GLdouble z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glScaled(x, y, z);
}

void glScalef(GLfloat x, GLfloat y, GLfloat z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glScalef(x, y, z);
}

void glScissor(GLint x, GLint y, GLsizei width, GLsizei height) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glScissor(x, y, width, height);
}

void glSecondaryColor3b(GLbyte red, GLbyte green, GLbyte blue) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColor3b(red, green, blue);
}

void glSecondaryColor3bv(const GLbyte * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColor3bv(v);
}

void glSecondaryColor3d(GLdouble red, GLdouble green, GLdouble blue) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColor3d(red, green, blue);
}

void glSecondaryColor3dv(const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColor3dv(v);
}

void glSecondaryColor3f(GLfloat red, GLfloat green, GLfloat blue) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColor3f(red, green, blue);
}

void glSecondaryColor3fv(const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColor3fv(v);
}

void glSecondaryColor3i(GLint red, GLint green, GLint blue) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColor3i(red, green, blue);
}

void glSecondaryColor3iv(const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColor3iv(v);
}

void glSecondaryColor3s(GLshort red, GLshort green, GLshort blue) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColor3s(red, green, blue);
}

void glSecondaryColor3sv(const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColor3sv(v);
}

void glSecondaryColor3ub(GLubyte red, GLubyte green, GLubyte blue) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColor3ub(red, green, blue);
}

void glSecondaryColor3ubv(const GLubyte * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColor3ubv(v);
}

void glSecondaryColor3ui(GLuint red, GLuint green, GLuint blue) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColor3ui(red, green, blue);
}

void glSecondaryColor3uiv(const GLuint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColor3uiv(v);
}

void glSecondaryColor3us(GLushort red, GLushort green, GLushort blue) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColor3us(red, green, blue);
}

void glSecondaryColor3usv(const GLushort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColor3usv(v);
}

void glSecondaryColorP3ui(GLenum type, GLuint color) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColorP3ui(type, color);
}

void glSecondaryColorP3uiv(GLenum type, const GLuint * color) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColorP3uiv(type, color);
}

void glSecondaryColorPointer(GLint size, GLenum type, GLsizei stride, const void * pointer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSecondaryColorPointer(size, type, stride, pointer);
}

void glSelectBuffer(GLsizei size, GLuint * buffer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glSelectBuffer(size, buffer);
}

void glShadeModel(GLenum mode) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glShadeModel(mode);
}

void glShaderSource(GLuint shader, GLsizei count, const GLchar *const* string, const GLint * length) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glShaderSource(shader, count, string, length);
}

void glStencilFunc(GLenum func, GLint ref, GLuint mask) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glStencilFunc(func, ref, mask);
}

void glStencilFuncSeparate(GLenum face, GLenum func, GLint ref, GLuint mask) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glStencilFuncSeparate(face, func, ref, mask);
}

void glStencilMask(GLuint mask) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glStencilMask(mask);
}

void glStencilMaskSeparate(GLenum face, GLuint mask) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glStencilMaskSeparate(face, mask);
}

void glStencilOp(GLenum fail, GLenum zfail, GLenum zpass) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glStencilOp(fail, zfail, zpass);
}

void glStencilOpSeparate(GLenum face, GLenum sfail, GLenum dpfail, GLenum dppass) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glStencilOpSeparate(face, sfail, dpfail, dppass);
}

void glTexBuffer(GLenum target, GLenum internalformat, GLuint buffer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexBuffer(target, internalformat, buffer);
}

void glTexCoord1d(GLdouble s) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord1d(s);
}

void glTexCoord1dv(const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord1dv(v);
}

void glTexCoord1f(GLfloat s) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord1f(s);
}

void glTexCoord1fv(const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord1fv(v);
}

void glTexCoord1i(GLint s) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord1i(s);
}

void glTexCoord1iv(const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord1iv(v);
}

void glTexCoord1s(GLshort s) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord1s(s);
}

void glTexCoord1sv(const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord1sv(v);
}

void glTexCoord2d(GLdouble s, GLdouble t) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord2d(s, t);
}

void glTexCoord2dv(const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord2dv(v);
}

void glTexCoord2f(GLfloat s, GLfloat t) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord2f(s, t);
}

void glTexCoord2fv(const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord2fv(v);
}

void glTexCoord2i(GLint s, GLint t) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord2i(s, t);
}

void glTexCoord2iv(const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord2iv(v);
}

void glTexCoord2s(GLshort s, GLshort t) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord2s(s, t);
}

void glTexCoord2sv(const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord2sv(v);
}

void glTexCoord3d(GLdouble s, GLdouble t, GLdouble r) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord3d(s, t, r);
}

void glTexCoord3dv(const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord3dv(v);
}

void glTexCoord3f(GLfloat s, GLfloat t, GLfloat r) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord3f(s, t, r);
}

void glTexCoord3fv(const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord3fv(v);
}

void glTexCoord3i(GLint s, GLint t, GLint r) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord3i(s, t, r);
}

void glTexCoord3iv(const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord3iv(v);
}

void glTexCoord3s(GLshort s, GLshort t, GLshort r) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord3s(s, t, r);
}

void glTexCoord3sv(const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord3sv(v);
}

void glTexCoord4d(GLdouble s, GLdouble t, GLdouble r, GLdouble q) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord4d(s, t, r, q);
}

void glTexCoord4dv(const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord4dv(v);
}

void glTexCoord4f(GLfloat s, GLfloat t, GLfloat r, GLfloat q) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord4f(s, t, r, q);
}

void glTexCoord4fv(const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord4fv(v);
}

void glTexCoord4i(GLint s, GLint t, GLint r, GLint q) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord4i(s, t, r, q);
}

void glTexCoord4iv(const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord4iv(v);
}

void glTexCoord4s(GLshort s, GLshort t, GLshort r, GLshort q) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord4s(s, t, r, q);
}

void glTexCoord4sv(const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoord4sv(v);
}

void glTexCoordP1ui(GLenum type, GLuint coords) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoordP1ui(type, coords);
}

void glTexCoordP1uiv(GLenum type, const GLuint * coords) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoordP1uiv(type, coords);
}

void glTexCoordP2ui(GLenum type, GLuint coords) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoordP2ui(type, coords);
}

void glTexCoordP2uiv(GLenum type, const GLuint * coords) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoordP2uiv(type, coords);
}

void glTexCoordP3ui(GLenum type, GLuint coords) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoordP3ui(type, coords);
}

void glTexCoordP3uiv(GLenum type, const GLuint * coords) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoordP3uiv(type, coords);
}

void glTexCoordP4ui(GLenum type, GLuint coords) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoordP4ui(type, coords);
}

void glTexCoordP4uiv(GLenum type, const GLuint * coords) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoordP4uiv(type, coords);
}

void glTexCoordPointer(GLint size, GLenum type, GLsizei stride, const void * pointer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexCoordPointer(size, type, stride, pointer);
}

void glTexEnvf(GLenum target, GLenum pname, GLfloat param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexEnvf(target, pname, param);
}

void glTexEnvfv(GLenum target, GLenum pname, const GLfloat * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexEnvfv(target, pname, params);
}

void glTexEnvi(GLenum target, GLenum pname, GLint param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexEnvi(target, pname, param);
}

void glTexEnviv(GLenum target, GLenum pname, const GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexEnviv(target, pname, params);
}

void glTexGend(GLenum coord, GLenum pname, GLdouble param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexGend(coord, pname, param);
}

void glTexGendv(GLenum coord, GLenum pname, const GLdouble * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexGendv(coord, pname, params);
}

void glTexGenf(GLenum coord, GLenum pname, GLfloat param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexGenf(coord, pname, param);
}

void glTexGenfv(GLenum coord, GLenum pname, const GLfloat * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexGenfv(coord, pname, params);
}

void glTexGeni(GLenum coord, GLenum pname, GLint param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexGeni(coord, pname, param);
}

void glTexGeniv(GLenum coord, GLenum pname, const GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexGeniv(coord, pname, params);
}

void glTexImage1D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLint border, GLenum format, GLenum type, const void * pixels) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexImage1D(target, level, internalformat, width, border, format, type, pixels);
}

void glTexImage2D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLint border, GLenum format, GLenum type, const void * pixels) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexImage2D(target, level, internalformat, width, height, border, format, type, pixels);
}

void glTexImage2DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLboolean fixedsamplelocations) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexImage2DMultisample(target, samples, internalformat, width, height, fixedsamplelocations);
}

void glTexImage3D(GLenum target, GLint level, GLint internalformat, GLsizei width, GLsizei height, GLsizei depth, GLint border, GLenum format, GLenum type, const void * pixels) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexImage3D(target, level, internalformat, width, height, depth, border, format, type, pixels);
}

void glTexImage3DMultisample(GLenum target, GLsizei samples, GLenum internalformat, GLsizei width, GLsizei height, GLsizei depth, GLboolean fixedsamplelocations) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexImage3DMultisample(target, samples, internalformat, width, height, depth, fixedsamplelocations);
}

void glTexParameterIiv(GLenum target, GLenum pname, const GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexParameterIiv(target, pname, params);
}

void glTexParameterIuiv(GLenum target, GLenum pname, const GLuint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexParameterIuiv(target, pname, params);
}

void glTexParameterf(GLenum target, GLenum pname, GLfloat param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexParameterf(target, pname, param);
}

void glTexParameterfv(GLenum target, GLenum pname, const GLfloat * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexParameterfv(target, pname, params);
}

void glTexParameteri(GLenum target, GLenum pname, GLint param) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexParameteri(target, pname, param);
}

void glTexParameteriv(GLenum target, GLenum pname, const GLint * params) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexParameteriv(target, pname, params);
}

void glTexSubImage1D(GLenum target, GLint level, GLint xoffset, GLsizei width, GLenum format, GLenum type, const void * pixels) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexSubImage1D(target, level, xoffset, width, format, type, pixels);
}

void glTexSubImage2D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLsizei width, GLsizei height, GLenum format, GLenum type, const void * pixels) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexSubImage2D(target, level, xoffset, yoffset, width, height, format, type, pixels);
}

void glTexSubImage3D(GLenum target, GLint level, GLint xoffset, GLint yoffset, GLint zoffset, GLsizei width, GLsizei height, GLsizei depth, GLenum format, GLenum type, const void * pixels) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTexSubImage3D(target, level, xoffset, yoffset, zoffset, width, height, depth, format, type, pixels);
}

void glTransformFeedbackVaryings(GLuint program, GLsizei count, const GLchar *const* varyings, GLenum bufferMode) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTransformFeedbackVaryings(program, count, varyings, bufferMode);
}

void glTranslated(GLdouble x, GLdouble y, GLdouble z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTranslated(x, y, z);
}

void glTranslatef(GLfloat x, GLfloat y, GLfloat z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glTranslatef(x, y, z);
}

void glUniform1d(GLint location, GLdouble x) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform1d(location, x);
}

void glUniform1dv(GLint location, GLsizei count, const GLdouble * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform1dv(location, count, value);
}

void glUniform1f(GLint location, GLfloat v0) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform1f(location, v0);
}

void glUniform1fv(GLint location, GLsizei count, const GLfloat * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform1fv(location, count, value);
}

void glUniform1i(GLint location, GLint v0) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform1i(location, v0);
}

void glUniform1iv(GLint location, GLsizei count, const GLint * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform1iv(location, count, value);
}

void glUniform1ui(GLint location, GLuint v0) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform1ui(location, v0);
}

void glUniform1uiv(GLint location, GLsizei count, const GLuint * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform1uiv(location, count, value);
}

void glUniform2d(GLint location, GLdouble x, GLdouble y) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform2d(location, x, y);
}

void glUniform2dv(GLint location, GLsizei count, const GLdouble * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform2dv(location, count, value);
}

void glUniform2f(GLint location, GLfloat v0, GLfloat v1) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform2f(location, v0, v1);
}

void glUniform2fv(GLint location, GLsizei count, const GLfloat * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform2fv(location, count, value);
}

void glUniform2i(GLint location, GLint v0, GLint v1) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform2i(location, v0, v1);
}

void glUniform2iv(GLint location, GLsizei count, const GLint * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform2iv(location, count, value);
}

void glUniform2ui(GLint location, GLuint v0, GLuint v1) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform2ui(location, v0, v1);
}

void glUniform2uiv(GLint location, GLsizei count, const GLuint * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform2uiv(location, count, value);
}

void glUniform3d(GLint location, GLdouble x, GLdouble y, GLdouble z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform3d(location, x, y, z);
}

void glUniform3dv(GLint location, GLsizei count, const GLdouble * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform3dv(location, count, value);
}

void glUniform3f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform3f(location, v0, v1, v2);
}

void glUniform3fv(GLint location, GLsizei count, const GLfloat * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform3fv(location, count, value);
}

void glUniform3i(GLint location, GLint v0, GLint v1, GLint v2) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform3i(location, v0, v1, v2);
}

void glUniform3iv(GLint location, GLsizei count, const GLint * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform3iv(location, count, value);
}

void glUniform3ui(GLint location, GLuint v0, GLuint v1, GLuint v2) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform3ui(location, v0, v1, v2);
}

void glUniform3uiv(GLint location, GLsizei count, const GLuint * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform3uiv(location, count, value);
}

void glUniform4d(GLint location, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform4d(location, x, y, z, w);
}

void glUniform4dv(GLint location, GLsizei count, const GLdouble * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform4dv(location, count, value);
}

void glUniform4f(GLint location, GLfloat v0, GLfloat v1, GLfloat v2, GLfloat v3) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform4f(location, v0, v1, v2, v3);
}

void glUniform4fv(GLint location, GLsizei count, const GLfloat * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform4fv(location, count, value);
}

void glUniform4i(GLint location, GLint v0, GLint v1, GLint v2, GLint v3) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform4i(location, v0, v1, v2, v3);
}

void glUniform4iv(GLint location, GLsizei count, const GLint * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform4iv(location, count, value);
}

void glUniform4ui(GLint location, GLuint v0, GLuint v1, GLuint v2, GLuint v3) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform4ui(location, v0, v1, v2, v3);
}

void glUniform4uiv(GLint location, GLsizei count, const GLuint * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniform4uiv(location, count, value);
}

void glUniformBlockBinding(GLuint program, GLuint uniformBlockIndex, GLuint uniformBlockBinding) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformBlockBinding(program, uniformBlockIndex, uniformBlockBinding);
}

void glUniformMatrix2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformMatrix2dv(location, count, transpose, value);
}

void glUniformMatrix2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformMatrix2fv(location, count, transpose, value);
}

void glUniformMatrix2x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformMatrix2x3dv(location, count, transpose, value);
}

void glUniformMatrix2x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformMatrix2x3fv(location, count, transpose, value);
}

void glUniformMatrix2x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformMatrix2x4dv(location, count, transpose, value);
}

void glUniformMatrix2x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformMatrix2x4fv(location, count, transpose, value);
}

void glUniformMatrix3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformMatrix3dv(location, count, transpose, value);
}

void glUniformMatrix3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformMatrix3fv(location, count, transpose, value);
}

void glUniformMatrix3x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformMatrix3x2dv(location, count, transpose, value);
}

void glUniformMatrix3x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformMatrix3x2fv(location, count, transpose, value);
}

void glUniformMatrix3x4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformMatrix3x4dv(location, count, transpose, value);
}

void glUniformMatrix3x4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformMatrix3x4fv(location, count, transpose, value);
}

void glUniformMatrix4dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformMatrix4dv(location, count, transpose, value);
}

void glUniformMatrix4fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformMatrix4fv(location, count, transpose, value);
}

void glUniformMatrix4x2dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformMatrix4x2dv(location, count, transpose, value);
}

void glUniformMatrix4x2fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformMatrix4x2fv(location, count, transpose, value);
}

void glUniformMatrix4x3dv(GLint location, GLsizei count, GLboolean transpose, const GLdouble * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformMatrix4x3dv(location, count, transpose, value);
}

void glUniformMatrix4x3fv(GLint location, GLsizei count, GLboolean transpose, const GLfloat * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformMatrix4x3fv(location, count, transpose, value);
}

void glUniformSubroutinesuiv(GLenum shadertype, GLsizei count, const GLuint * indices) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUniformSubroutinesuiv(shadertype, count, indices);
}

GLboolean glUnmapBuffer(GLenum target) {
    if (libgl == NULL) { load_gl_shims(); }

    return proc_glUnmapBuffer(target);
}

void glUseProgram(GLuint program) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glUseProgram(program);
}

void glValidateProgram(GLuint program) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glValidateProgram(program);
}

void glVertex2d(GLdouble x, GLdouble y) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex2d(x, y);
}

void glVertex2dv(const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex2dv(v);
}

void glVertex2f(GLfloat x, GLfloat y) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex2f(x, y);
}

void glVertex2fv(const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex2fv(v);
}

void glVertex2i(GLint x, GLint y) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex2i(x, y);
}

void glVertex2iv(const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex2iv(v);
}

void glVertex2s(GLshort x, GLshort y) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex2s(x, y);
}

void glVertex2sv(const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex2sv(v);
}

void glVertex3d(GLdouble x, GLdouble y, GLdouble z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex3d(x, y, z);
}

void glVertex3dv(const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex3dv(v);
}

void glVertex3f(GLfloat x, GLfloat y, GLfloat z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex3f(x, y, z);
}

void glVertex3fv(const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex3fv(v);
}

void glVertex3i(GLint x, GLint y, GLint z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex3i(x, y, z);
}

void glVertex3iv(const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex3iv(v);
}

void glVertex3s(GLshort x, GLshort y, GLshort z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex3s(x, y, z);
}

void glVertex3sv(const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex3sv(v);
}

void glVertex4d(GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex4d(x, y, z, w);
}

void glVertex4dv(const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex4dv(v);
}

void glVertex4f(GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex4f(x, y, z, w);
}

void glVertex4fv(const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex4fv(v);
}

void glVertex4i(GLint x, GLint y, GLint z, GLint w) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex4i(x, y, z, w);
}

void glVertex4iv(const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex4iv(v);
}

void glVertex4s(GLshort x, GLshort y, GLshort z, GLshort w) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex4s(x, y, z, w);
}

void glVertex4sv(const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertex4sv(v);
}

void glVertexAttrib1d(GLuint index, GLdouble x) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib1d(index, x);
}

void glVertexAttrib1dv(GLuint index, const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib1dv(index, v);
}

void glVertexAttrib1f(GLuint index, GLfloat x) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib1f(index, x);
}

void glVertexAttrib1fv(GLuint index, const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib1fv(index, v);
}

void glVertexAttrib1s(GLuint index, GLshort x) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib1s(index, x);
}

void glVertexAttrib1sv(GLuint index, const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib1sv(index, v);
}

void glVertexAttrib2d(GLuint index, GLdouble x, GLdouble y) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib2d(index, x, y);
}

void glVertexAttrib2dv(GLuint index, const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib2dv(index, v);
}

void glVertexAttrib2f(GLuint index, GLfloat x, GLfloat y) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib2f(index, x, y);
}

void glVertexAttrib2fv(GLuint index, const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib2fv(index, v);
}

void glVertexAttrib2s(GLuint index, GLshort x, GLshort y) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib2s(index, x, y);
}

void glVertexAttrib2sv(GLuint index, const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib2sv(index, v);
}

void glVertexAttrib3d(GLuint index, GLdouble x, GLdouble y, GLdouble z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib3d(index, x, y, z);
}

void glVertexAttrib3dv(GLuint index, const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib3dv(index, v);
}

void glVertexAttrib3f(GLuint index, GLfloat x, GLfloat y, GLfloat z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib3f(index, x, y, z);
}

void glVertexAttrib3fv(GLuint index, const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib3fv(index, v);
}

void glVertexAttrib3s(GLuint index, GLshort x, GLshort y, GLshort z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib3s(index, x, y, z);
}

void glVertexAttrib3sv(GLuint index, const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib3sv(index, v);
}

void glVertexAttrib4Nbv(GLuint index, const GLbyte * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib4Nbv(index, v);
}

void glVertexAttrib4Niv(GLuint index, const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib4Niv(index, v);
}

void glVertexAttrib4Nsv(GLuint index, const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib4Nsv(index, v);
}

void glVertexAttrib4Nub(GLuint index, GLubyte x, GLubyte y, GLubyte z, GLubyte w) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib4Nub(index, x, y, z, w);
}

void glVertexAttrib4Nubv(GLuint index, const GLubyte * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib4Nubv(index, v);
}

void glVertexAttrib4Nuiv(GLuint index, const GLuint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib4Nuiv(index, v);
}

void glVertexAttrib4Nusv(GLuint index, const GLushort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib4Nusv(index, v);
}

void glVertexAttrib4bv(GLuint index, const GLbyte * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib4bv(index, v);
}

void glVertexAttrib4d(GLuint index, GLdouble x, GLdouble y, GLdouble z, GLdouble w) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib4d(index, x, y, z, w);
}

void glVertexAttrib4dv(GLuint index, const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib4dv(index, v);
}

void glVertexAttrib4f(GLuint index, GLfloat x, GLfloat y, GLfloat z, GLfloat w) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib4f(index, x, y, z, w);
}

void glVertexAttrib4fv(GLuint index, const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib4fv(index, v);
}

void glVertexAttrib4iv(GLuint index, const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib4iv(index, v);
}

void glVertexAttrib4s(GLuint index, GLshort x, GLshort y, GLshort z, GLshort w) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib4s(index, x, y, z, w);
}

void glVertexAttrib4sv(GLuint index, const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib4sv(index, v);
}

void glVertexAttrib4ubv(GLuint index, const GLubyte * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib4ubv(index, v);
}

void glVertexAttrib4uiv(GLuint index, const GLuint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib4uiv(index, v);
}

void glVertexAttrib4usv(GLuint index, const GLushort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttrib4usv(index, v);
}

void glVertexAttribDivisor(GLuint index, GLuint divisor) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribDivisor(index, divisor);
}

void glVertexAttribI1i(GLuint index, GLint x) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI1i(index, x);
}

void glVertexAttribI1iv(GLuint index, const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI1iv(index, v);
}

void glVertexAttribI1ui(GLuint index, GLuint x) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI1ui(index, x);
}

void glVertexAttribI1uiv(GLuint index, const GLuint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI1uiv(index, v);
}

void glVertexAttribI2i(GLuint index, GLint x, GLint y) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI2i(index, x, y);
}

void glVertexAttribI2iv(GLuint index, const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI2iv(index, v);
}

void glVertexAttribI2ui(GLuint index, GLuint x, GLuint y) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI2ui(index, x, y);
}

void glVertexAttribI2uiv(GLuint index, const GLuint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI2uiv(index, v);
}

void glVertexAttribI3i(GLuint index, GLint x, GLint y, GLint z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI3i(index, x, y, z);
}

void glVertexAttribI3iv(GLuint index, const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI3iv(index, v);
}

void glVertexAttribI3ui(GLuint index, GLuint x, GLuint y, GLuint z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI3ui(index, x, y, z);
}

void glVertexAttribI3uiv(GLuint index, const GLuint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI3uiv(index, v);
}

void glVertexAttribI4bv(GLuint index, const GLbyte * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI4bv(index, v);
}

void glVertexAttribI4i(GLuint index, GLint x, GLint y, GLint z, GLint w) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI4i(index, x, y, z, w);
}

void glVertexAttribI4iv(GLuint index, const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI4iv(index, v);
}

void glVertexAttribI4sv(GLuint index, const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI4sv(index, v);
}

void glVertexAttribI4ubv(GLuint index, const GLubyte * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI4ubv(index, v);
}

void glVertexAttribI4ui(GLuint index, GLuint x, GLuint y, GLuint z, GLuint w) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI4ui(index, x, y, z, w);
}

void glVertexAttribI4uiv(GLuint index, const GLuint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI4uiv(index, v);
}

void glVertexAttribI4usv(GLuint index, const GLushort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribI4usv(index, v);
}

void glVertexAttribIPointer(GLuint index, GLint size, GLenum type, GLsizei stride, const void * pointer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribIPointer(index, size, type, stride, pointer);
}

void glVertexAttribP1ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribP1ui(index, type, normalized, value);
}

void glVertexAttribP1uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribP1uiv(index, type, normalized, value);
}

void glVertexAttribP2ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribP2ui(index, type, normalized, value);
}

void glVertexAttribP2uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribP2uiv(index, type, normalized, value);
}

void glVertexAttribP3ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribP3ui(index, type, normalized, value);
}

void glVertexAttribP3uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribP3uiv(index, type, normalized, value);
}

void glVertexAttribP4ui(GLuint index, GLenum type, GLboolean normalized, GLuint value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribP4ui(index, type, normalized, value);
}

void glVertexAttribP4uiv(GLuint index, GLenum type, GLboolean normalized, const GLuint * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribP4uiv(index, type, normalized, value);
}

void glVertexAttribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}

void glVertexP2ui(GLenum type, GLuint value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexP2ui(type, value);
}

void glVertexP2uiv(GLenum type, const GLuint * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexP2uiv(type, value);
}

void glVertexP3ui(GLenum type, GLuint value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexP3ui(type, value);
}

void glVertexP3uiv(GLenum type, const GLuint * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexP3uiv(type, value);
}

void glVertexP4ui(GLenum type, GLuint value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexP4ui(type, value);
}

void glVertexP4uiv(GLenum type, const GLuint * value) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexP4uiv(type, value);
}

void glVertexPointer(GLint size, GLenum type, GLsizei stride, const void * pointer) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glVertexPointer(size, type, stride, pointer);
}

void glViewport(GLint x, GLint y, GLsizei width, GLsizei height) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glViewport(x, y, width, height);
}

void glWaitSync(GLsync sync, GLbitfield flags, GLuint64 timeout) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glWaitSync(sync, flags, timeout);
}

void glWindowPos2d(GLdouble x, GLdouble y) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glWindowPos2d(x, y);
}

void glWindowPos2dv(const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glWindowPos2dv(v);
}

void glWindowPos2f(GLfloat x, GLfloat y) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glWindowPos2f(x, y);
}

void glWindowPos2fv(const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glWindowPos2fv(v);
}

void glWindowPos2i(GLint x, GLint y) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glWindowPos2i(x, y);
}

void glWindowPos2iv(const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glWindowPos2iv(v);
}

void glWindowPos2s(GLshort x, GLshort y) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glWindowPos2s(x, y);
}

void glWindowPos2sv(const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glWindowPos2sv(v);
}

void glWindowPos3d(GLdouble x, GLdouble y, GLdouble z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glWindowPos3d(x, y, z);
}

void glWindowPos3dv(const GLdouble * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glWindowPos3dv(v);
}

void glWindowPos3f(GLfloat x, GLfloat y, GLfloat z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glWindowPos3f(x, y, z);
}

void glWindowPos3fv(const GLfloat * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glWindowPos3fv(v);
}

void glWindowPos3i(GLint x, GLint y, GLint z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glWindowPos3i(x, y, z);
}

void glWindowPos3iv(const GLint * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glWindowPos3iv(v);
}

void glWindowPos3s(GLshort x, GLshort y, GLshort z) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glWindowPos3s(x, y, z);
}

void glWindowPos3sv(const GLshort * v) {
    if (libgl == NULL) { load_gl_shims(); }

    proc_glWindowPos3sv(v);
}

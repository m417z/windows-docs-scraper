# glDrawBuffer function

The **glDrawBuffer** function specifies which color buffers are to be drawn into.

## Parameters

*mode*

Specifies up to four color buffers to be drawn into with the following acceptable symbolic constants.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**GL\_NONE**

| No color buffers are written.<br> |
|

**GL\_FRONT\_LEFT**

| Only the front-left color buffer is written.<br> |
|

**GL\_FRONT\_RIGHT**

| Only the front-right color buffer is written.<br> |
|

**GL\_BACK\_LEFT**

| Only the back-left color buffer is written.<br> |
|

**GL\_BACK\_RIGHT**

| Only the back-right color buffer is written.<br> |
|

**GL\_FRONT**

| Only the front-left and front-right color buffers are written. If there is no front-right color buffer, only the front left-color buffer is written.<br> |
|

**GL\_BACK**

| Only the back-left and back-right color buffers are written. If there is no back-right color buffer, only the back-left color buffer is written.<br> |
|

**GL\_LEFT**

| Only the front-left and back-left color buffers are written. If there is no back-left color buffer, only the front-left color buffer is written.<br> |
|

**GL\_RIGHT**

| Only the front-right and back-right color buffers are written. If there is no back-right color buffer, only the front-right color buffer is written.<br> |
|

**GL\_FRONT\_AND\_BACK**

| All the front and back color buffers (front-left, front-right, back-left, back-right) are written. If there are no back color buffers, only the front-left and front-right color buffers are written. If there are no right color buffers, only the front-left and back-left color buffers are written. If there are no right or back color buffers, only the front-left color buffer is written.<br> |
|

**GL\_AUXi**

| Only the auxiliary color buffer *i* is written; *i* is between 0 and GL\_AUX\_BUFFERS - 1. (GL\_AUX\_BUFFERS is not the upper limit; use [**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) to query the number of available auxiliary buffers.)<br> |

The default value is GL\_FRONT for single-buffered contexts, and GL\_BACK for double-buffered contexts.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *mode* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | None of the buffers indicated by *mode* existed.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

When colors are written to the framebuffer, they are written into the color buffers specified by **glDrawBuffer**.

If more than one color buffer is selected for drawing, then blending or logical operations are computed and applied independently for each color buffer and can produce different results in each buffer.

Monoscopic contexts include only left buffers, and stereoscopic contexts include both left and right buffers. Likewise, single-buffered contexts include only front buffers, and double-buffered contexts include both front and back buffers. The context is selected at OpenGL initialization.

It is always the case that GL\_AUX *i* = GL\_AUX0 + *i*.

The following functions retrieve information related to the **glDrawBuffer** function:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_DRAW\_BUFFER

**glGet** with argument GL\_AUX\_BUFFERS

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

## See also

[**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)

[**glBlendFunc**](https://learn.microsoft.com/windows/win32/opengl/glblendfunc)

[**glColorMask**](https://learn.microsoft.com/windows/win32/opengl/glcolormask)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glIndexMask**](https://learn.microsoft.com/windows/win32/opengl/glindexmask)

[**glLogicOp**](https://learn.microsoft.com/windows/win32/opengl/gllogicop)

[**glReadBuffer**](https://learn.microsoft.com/windows/win32/opengl/glreadbuffer)


# glMultMatrixd function

The **glMultMatrixd** and [**glMultMatrixf**](https://learn.microsoft.com/windows/win32/opengl/glmultmatrixf) functions multiply the current matrix by an arbitrary matrix.

## Parameters

*m*

A pointer to a 4x4 matrix stored in column-major order as 16 consecutive values.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glMultMatrix** function multiplies the current matrix by the one specified in *m*. That is, if M is the current matrix and T is the matrix passed to **glMultMatrix**, then M is replaced with M T.

The current matrix is the projection matrix, modelview matrix, or texture matrix, determined by the current matrix mode (see [**glMatrixMode**](https://learn.microsoft.com/windows/win32/opengl/glmatrixmode)).

The *m* parameter points to a 4x4 matrix of single-precision or double-precision floating-point values stored in column-major order. That is, the matrix is stored as shown in the following image.

![![Diagram showing the 4x4 matrix that the m parameter points to.]](https://learn.microsoft.com/windows/win32/opengl/images/multi01.png)

The following functions retrieve information related to **glMultMatrix**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_MATRIX\_MODE

**glGet** with argument GL\_MODELVIEW\_MATRIX

**glGet** with argument GL\_PROJECTION\_MATRIX

**glGet** with argument GL\_TEXTURE\_MATRIX

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

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glLoadIdentity**](https://learn.microsoft.com/windows/win32/opengl/glloadidentity)

[**glLoadMatrix**](https://learn.microsoft.com/windows/win32/opengl/glloadmatrix)

[**glMatrixMode**](https://learn.microsoft.com/windows/win32/opengl/glmatrixmode)

[**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix)


# glMatrixMode function

The **glMatrixMode** function specifies which matrix is the current matrix.

## Parameters

*mode*

The matrix stack that is the target for subsequent matrix operations. The *mode* parameter can assume one of three values.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------|
|

**GL\_MODELVIEW**

| Applies subsequent matrix operations to the modelview matrix stack.<br> |
|

**GL\_PROJECTION**

| Applies subsequent matrix operations to the projection matrix stack.<br> |
|

**GL\_TEXTURE**

| Applies subsequent matrix operations to the texture matrix stack.<br> |

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *mode* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glMatrixMode** function sets the current matrix mode.

The following function retrieves information related to **glMatrixMode**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_MATRIX\_MODE

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

[**glLoadMatrix**](https://learn.microsoft.com/windows/win32/opengl/glloadmatrix)

[**glPushMatrix**](https://learn.microsoft.com/windows/win32/opengl/glpushmatrix)


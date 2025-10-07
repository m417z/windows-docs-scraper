# glGetClipPlane function

The **glGetClipPlane** function returns the coefficients of the specified clipping plane.

## Parameters

*plane*

A clipping plane. The number of clipping planes depends on the implementation, but at least six clipping planes are supported. They are identified by symbolic names of the form GL\_CLIP\_PLANE *i* where 0 = *i* < GL\_MAX\_CLIP\_PLANES.

*equation*

Returns four double-precision values that are the coefficients of the plane equation of *plane* in eye coordinates.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *plane* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glGetClipPlane** function returns in *equation* the four coefficients of the plane equation for *plane*.

It is always the case that GL\_CLIP\_PLANE*i* = GL\_CLIP\_PLANE0 + *i*.

If an error is generated, no change is made to the contents of *equation*.

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

[**glClipPlane**](https://learn.microsoft.com/windows/win32/opengl/glclipplane)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)


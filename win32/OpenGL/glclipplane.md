# glClipPlane function

The **glClipPlane** function specifies a plane against which all geometry is clipped.

## Parameters

*plane*

The clipping plane that is being positioned. Symbolic names of the form GL\_CLIP\_PLANE*i*, where *i* is an integer between 0 and GL\_MAX\_CLIP\_PLANES - 1, are accepted.

*equation*

The address of an array of four double-precision floating-point values. These values are interpreted as a plane equation.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *plane* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

Geometry is always clipped against the boundaries of a six-plane frustum in *x*, *y*, and *z*. The **glClipPlane** function allows the specification of additional planes, not necessarily perpendicular to the *x-*axis, *y-*axis, or *z*-axis, against which all geometry is clipped. Up to GL\_MAX\_CLIP\_PLANES planes can be specified, where GL\_MAX\_CLIP\_PLANES is at least six in all implementations. Because the resulting clipping region is the intersection of the defined half-spaces, it is always convex.

The **glClipPlane** function specifies a half-space using a four-component plane equation. When you call **glClipPlane**,*equation* is transformed by the inverse of the modelview matrix and stored in the resulting eye coordinates. Subsequent changes to the modelview matrix have no effect on the stored plane-equation components. If the dot product of the eye coordinates of a vertex with the stored plane equation components is positive or zero, the vertex is in with respect to that clipping plane. Otherwise, it is out.

Use the [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and [**glDisable**](https://learn.microsoft.com/windows/win32/opengl/gldisable) functions to enable and disable clipping planes. Call clipping planes with the argument GL\_CLIP\_PLANE*i*, where *i* is the plane number.

By default, all clipping planes are defined as (0,0,0,0) in eye coordinates and are disabled.

It is always the case that GL\_CLIP\_PLANE*i* = GL\_CLIP\_PLANE0 + *i*.

The following functions retrieve information related to **glClipPlane**:

[**glGetClipPlane**](https://learn.microsoft.com/windows/win32/opengl/glgetclipplane)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_CLIP\_PLANE *i*

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

[**glDisable**](https://learn.microsoft.com/windows/win32/opengl/gldisable)

[**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGetClipPlane**](https://learn.microsoft.com/windows/win32/opengl/glgetclipplane)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)


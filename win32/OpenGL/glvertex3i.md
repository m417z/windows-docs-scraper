# glVertex3i function

Specifies a vertex.

## Parameters

*x*

Specifies the x-coordinate of a vertex.

*y*

Specifies the y-coordinate of a vertex.

*z*

Specifies the z-coordinate of a vertex.

## Return value

This function does not return a value.

## Remarks

The glVertex function commands are used within [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)/[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend) pairs to specify point, line, and polygon vertices. The current color, normal, and texture coordinates are associated with the vertex when glVertex is called. When only *x* and *y* are specified, *z* defaults to 0.0 and *w* defaults to 1.0. When *x*, *y*, and *z* are specified, *w* defaults to 1.0. Invoking glVertex outside of a **glBegin**/**glEnd** pair results in undefined behavior.

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

[**glCallList**](https://learn.microsoft.com/windows/win32/opengl/glcalllist)

[**glColor**](https://learn.microsoft.com/windows/win32/opengl/glcolor-functions)

[**glEdgeFlag**](https://learn.microsoft.com/windows/win32/opengl/gledgeflag-functions)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glEvalCoord**](https://learn.microsoft.com/windows/win32/opengl/glevalcoord-functions)

[**glIndex**](https://learn.microsoft.com/windows/win32/opengl/glindex-functions)

[**glMaterial**](https://learn.microsoft.com/windows/win32/opengl/glmaterial-functions)

[**glNormal**](https://learn.microsoft.com/windows/win32/opengl/glnormal-functions)

[**glRect**](https://learn.microsoft.com/windows/win32/opengl/glrect-functions)

[**glTexCoord**](https://learn.microsoft.com/windows/win32/opengl/gltexcoord-functions)


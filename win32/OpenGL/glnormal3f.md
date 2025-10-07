# glNormal3f function

Sets the current normal vector.

## Parameters

*nx*

Specifies the x-coordinate for the new current normal vector.

*ny*

Specifies the y-coordinate for the new current normal vector.

*nz*

Specifies the z-coordinate for the new current normal vector.

## Return value

This function does not return a value.

## Remarks

The current normal is set to the given coordinates whenever you call the **glNormal3f** function.

Byte, short, or integer arguments are converted to floating-point format with a linear mapping that maps the most positive representable integer value to 1.0, and the most negative representable integer value to -1.0.

Normals specified by using **glNormal3f** need not have unit length. If normalization is enabled, then normals specified with **glNormal3f** are normalized after transformation. You can control normalization by using [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and [**glDisable**](https://learn.microsoft.com/windows/win32/opengl/gldisable) with the argument GL\_NORMALIZE. By default, normalization is disabled. You can update the current normal at any time. In particular, you can call **glNormal3f** between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend). The following functions retrieve information related to **glNormal3f**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_CURRENT\_NORMAL

[**glIsEnable**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_NORMALIZE

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

[**glColor**](https://learn.microsoft.com/windows/win32/opengl/glcolor-functions)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glIndex**](https://learn.microsoft.com/windows/win32/opengl/glindex-functions)

[**glTexCoord**](https://learn.microsoft.com/windows/win32/opengl/gltexcoord-functions)

[**glVertex**](https://learn.microsoft.com/windows/win32/opengl/glvertex-functions)


# glPolygonOffset function

The **glPolygonOffset** function sets the scale and units OpenGL uses to calculate depth values.

## Parameters

*factor*

Specifies a scale factor that is used to create a variable depth offset for each polygon. The initial value is zero.

*units*

Specifies a value that is multiplied by an implementation-specific value to create a constant depth offset. The initial value is 0.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

When GL\_POLYGON\_OFFSET is enabled, each fragment's depth value will be offset after it is interpolated from the depth values of the appropriate vertices. The value of the offset is *factor* \* ?z + r \**units*, where ?z is a measurement of the change in depth relative to the screen area of the polygon, and r is the smallest value that is guaranteed to produce a resolvable offset for a given implementation. The offset is added before the depth test is performed and before the value is written into the depth buffer.

The **glPolygonOffset** function is useful for rendering hidden-line images, for applying decals to surfaces, and for rendering solids with highlighted edges.

The **glPolygonOffset** function has no effect on depth coordinates placed in the feedback buffer. It also has no effect on selection.

The following functions retrieve information related to **glPolygonOffset**:

- [**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_POLYGON\_OFFSET\_FACTOR
- [**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_POLYGON\_OFFSET\_UNITS
- [**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_POLYGON\_OFFSET\_FILL
- [**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_POLYGON\_OFFSET\_LINE
- [**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_POLYGON\_OFFSET\_POINT

> [!Note]
> The **glPolygonOffset** function is only available in OpenGl version 1.1 or greater.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

## See also

[**glDepthFunc**](https://learn.microsoft.com/windows/win32/opengl/gldepthfunc)

[**glDisable**](https://learn.microsoft.com/windows/win32/opengl/gldisable)

[**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

[**glLineWidth**](https://learn.microsoft.com/windows/win32/opengl/gllinewidth)

[**glStencilOp**](https://learn.microsoft.com/windows/win32/opengl/glstencilop)

[**glTexEnv**](https://learn.microsoft.com/windows/win32/opengl/gltexenv-functions)


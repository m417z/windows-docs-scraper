# glCullFace function

The **glCullFace** function specifies whether front-facing or back-facing facets can be culled.

## Parameters

*mode*

Specifies whether front-facing or back-facing facets are candidates for culling. The symbolic constants GL\_FRONT, GL\_BACK, and GL\_FRONT\_AND\_BACK are accepted. The default value is GL\_BACK.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *mode* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glCullFace** function specifies whether front-facing or back-facing facets are culled (as specified by *mode*) when facet culling is enabled. You enable and disable facet culling using [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and [**glDisable**](https://learn.microsoft.com/windows/win32/opengl/gldisable) with the argument GL\_CULL\_FACE. Facets include triangles, quadrilaterals, polygons, and rectangles.

The [**glFrontFace**](https://learn.microsoft.com/windows/win32/opengl/glfrontface) function specifies which of the clockwise and counterclockwise facets are front-facing and back-facing.

If *mode* is GL\_FRONT\_AND\_BACK, no facets are drawn, but other primitives, such as points and lines, are drawn.

The following functions retrieve information related to **glCullFace**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_CULL\_FACE\_MODE

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_CULL\_FACE

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

[**glFrontFace**](https://learn.microsoft.com/windows/win32/opengl/glfrontface)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)


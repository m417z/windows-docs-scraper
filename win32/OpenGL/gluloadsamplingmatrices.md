# gluLoadSamplingMatrices function

The **gluLoadSamplingMatrices** function loads Non-Uniform Rational B-Spline ([NURBS](https://learn.microsoft.com/windows/win32/opengl/using-nurbs-curves-and-surfaces)) sampling and culling matrices.

## Parameters

*nobj*

The NURBS object (created with [**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)).

*modelMatrix*

A modelview matrix (as from a [**glGetFloatv**](https://learn.microsoft.com/windows/win32/opengl/glgetfloatv) call).

*projMatrix*

A projection matrix (as from a **glGetFloatv** call).

*viewport*

A viewport (as from a [**glGetIntegerv**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) call).

## Return value

This function does not return a value.

## Remarks

The **gluLoadSamplingMatrices** function uses *modelMatrix*, *projMatrix*, and *viewport* to recompute the sampling and culling matrices stored in *nobj*. The sampling matrix determines how finely a NURBS curve or surface must be tessellated to satisfy the sampling tolerance (as determined by the GLU\_SAMPLING\_TOLERANCE property). The culling matrix is used in deciding if a NURBS curve or surface should be culled before rendering (when the GLU\_CULLING property is turned on).

The **gluLoadSamplingMatrices** function is necessary only if the GLU\_AUTO\_LOAD\_MATRIX property is turned off (see [**gluNurbsProperty**](https://learn.microsoft.com/windows/win32/opengl/glunurbsproperty)). Although it can be convenient to leave the GLU\_AUTO\_LOAD\_MATRIX property turned on, doing so necessitates a round trip to the OpenGL server to get the current values of the modelview matrix, projection matrix, and viewport.)

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**glGetFloatv**](https://learn.microsoft.com/windows/win32/opengl/glgetfloatv)

[**glGetIntegerv**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**gluGetNurbsProperty**](https://learn.microsoft.com/windows/win32/opengl/glugetnurbsproperty)

[**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)


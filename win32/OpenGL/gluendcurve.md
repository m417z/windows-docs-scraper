# gluEndCurve function

The [**gluBeginCurve**](https://learn.microsoft.com/windows/win32/opengl/glubegincurve) and **gluEndCurve** functions delimit a Non-Uniform Rational B-Spline ([NURBS](https://learn.microsoft.com/windows/win32/opengl/using-nurbs-curves-and-surfaces)) curve definition.

## Parameters

*nobj*

The NURBS object (created with [**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)).

## Return value

This function does not return a value.

## Remarks

Use [**gluBeginCurve**](https://learn.microsoft.com/windows/win32/opengl/glubegincurve) to mark the beginning of a NURBS curve definition. After calling **gluBeginCurve**, make one or more calls to [**gluNurbsCurve**](https://learn.microsoft.com/windows/win32/opengl/glunurbscurve) to define the attributes of the curve. Exactly one of the calls to **gluNurbsCurve** must have a curve type of GL\_MAP1\_VERTEX\_3 or GL\_MAP1\_VERTEX\_4. To mark the end of the NURBS curve definition, call **gluEndCurve**.

OpenGL evaluators are used to render the NURBS curve as a series of line segments. Evaluator state is preserved during rendering with [**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib) (GL\_EVAL\_BIT ) and [**glPopAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopattrib). For information on exactly what state these calls preserve, see **glPushAttrib**.

## Examples

The following functions render a textured NURBS curve with normals; texture coordinates and normals are also specified as NURBS curves:

``` syntax
gluBeginCurve(nobj);
gluNurbsCurve(nobj, . . ., GL_MAP1_TEXTURE_COORD_2);
gluNurbsCurve(nobj, . . ., GL_MAP1_NORMAL);
gluNurbsCurve(nobj, . . ., GL_MAP1_VERTEX_4);
gluEndCurve(nobj);
```

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib)

[**gluBeginSurface**](https://learn.microsoft.com/windows/win32/opengl/glubeginsurface)

[**gluBeginTrim**](https://learn.microsoft.com/windows/win32/opengl/glubegintrim)

[**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)

[**gluNurbsCurve**](https://learn.microsoft.com/windows/win32/opengl/glunurbscurve)


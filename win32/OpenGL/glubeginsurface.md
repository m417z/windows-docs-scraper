# gluBeginSurface function

The **gluBeginSurface** and [**gluEndSurface**](https://learn.microsoft.com/windows/win32/opengl/gluendsurface) functions delimit a Non-Uniform Rational B-Spline ([NURBS](https://learn.microsoft.com/windows/win32/opengl/using-nurbs-curves-and-surfaces)) surface definition.

## Parameters

*nobj*

The NURBS object (created with [**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)).

## Return value

This function does not return a value.

## Remarks

The **gluBeginSurface** and **gluEndSurface** functions mark the beginning and end of NURBS surface definitions, which are defined with calls to **gluNurbsSurface**.

1. Call **gluBeginSurface** to mark the beginning of a NURBS surface definition.
2. Make one or more calls to **gluNurbsSurface** to define the attributes of the surface.

 Exactly one of these calls to **gluNurbsSurface** must have a surface type of GL\_MAP2\_VERTEX\_3 or GL\_MAP2\_VERTEX\_4.

3. To mark the end of the NURBS surface definition, call **gluEndSurface**.

The [**gluBeginTrim**](https://learn.microsoft.com/windows/win32/opengl/glubegintrim), [**gluPwlCurve**](https://learn.microsoft.com/windows/win32/opengl/glupwlcurve), [**gluNurbsCurve**](https://learn.microsoft.com/windows/win32/opengl/glunurbscurve), and [**gluEndTrim**](https://learn.microsoft.com/windows/win32/opengl/gluendtrim) functions support trimming of NURBS surfaces.

Use OpenGL evaluators to render the NURBS surface as a set of polygons. Preserve the evaluator state during rendering with [**glPushAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpushattrib)(GL\_EVAL\_BIT) and [**glPopAttrib**](https://learn.microsoft.com/windows/win32/opengl/glpopattrib).

## Examples

The following functions render a textured NURBS surface with normals; the texture coordinates and normals are also described as NURBS surfaces:

``` syntax
gluBeginSurface(nobj);
    gluNurbsSurface(nobj, . . ., GL_MAP2_TEXTURE_COORD_2);
    gluNurbsSurface(nobj, . . ., GL_MAP2_NORMAL);
    gluNurbsSurface(nobj, . . ., GL_MAP2_VERTEX_4);
gluEndSurface(nobj);
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

[**gluBeginCurve**](https://learn.microsoft.com/windows/win32/opengl/glubegincurve)

[**gluBeginTrim**](https://learn.microsoft.com/windows/win32/opengl/glubegintrim)

[**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)

[**gluNurbsCurve**](https://learn.microsoft.com/windows/win32/opengl/glunurbscurve)

[**gluNurbsSurface**](https://learn.microsoft.com/windows/win32/opengl/glunurbssurface)

[**gluPwlCurve**](https://learn.microsoft.com/windows/win32/opengl/glupwlcurve)


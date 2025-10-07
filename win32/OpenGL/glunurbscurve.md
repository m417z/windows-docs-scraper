# gluNurbsCurve function

The **gluNurbsCurve** function defines the shape of a Non-Uniform Rational B-Spline ([NURBS](https://learn.microsoft.com/windows/win32/opengl/using-nurbs-curves-and-surfaces)) curve.

## Parameters

*nobj*

The NURBS object (created with [**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)).

*nknots*

The number of knots in *knot*. The *nknots* parameter equals the number of control points plus the order.

*knot*

An array of *nknots* nondecreasing knot values.

*stride*

The offset (as a number of single-precision floating-point values) between successive curve control points.

*ctlarray*

A pointer to an array of control points. The coordinates must agree with *type*.

*order*

The order of the NURBS curve. The *order* parameter equals degree + 1; hence a cubic curve has an order of 4.

*type*

The type of the curve. If this curve is defined within a [**gluBeginCurve**](https://learn.microsoft.com/windows/win32/opengl/glubegincurve)/[**gluEndCurve**](https://learn.microsoft.com/windows/win32/opengl/gluendcurve) pair, then the type can be any of the valid one-dimensional evaluator types (such as GL\_MAP1\_VERTEX\_3 or GL\_MAP1\_COLOR\_4). Between a [**gluBeginTrim**](https://learn.microsoft.com/windows/win32/opengl/glubegintrim)/[**gluEndTrim**](https://learn.microsoft.com/windows/win32/opengl/gluendtrim) pair, the only valid types are GLU\_MAP1\_TRIM\_2 and GLU\_MAP1\_TRIM\_3.

## Return value

This function does not return a value.

## Remarks

When **gluNurbsCurve** appears between a **gluBeginCurve**/**gluEndCurve** pair, it describes a curve to be rendered. You associate positional, texture, and color coordinates by presenting each as a separate **gluNurbsCurve** between a **gluBeginCurve**/**gluEndCurve** pair. Do not make more than one call to **gluNurbsCurve** for color, position, and texture data within a single **gluBeginCurve**/**gluEndCurve** pair. Make exactly one call to describe the position of the curve (a *type* of GL\_MAP1\_VERTEX\_3 or GL\_MAP1\_VERTEX\_4).

When **gluNurbsCurve** appears between a [**gluBeginTrim**](https://learn.microsoft.com/windows/win32/opengl/glubegintrim)/[**gluEndTrim**](https://learn.microsoft.com/windows/win32/opengl/gluendtrim) pair, it describes a trimming curve on a NURBS surface. If *type* is GLU\_MAP1\_TRIM\_2, it describes a curve in two-dimensional (*u* and *v*) parameter space. If it is GLU\_MAP1\_TRIM\_3, it describes a curve in two-dimensional homogeneous (*u*, *v*, and *w*) parameter space. For more discussion about trimming curves, see **gluBeginTrim**.

## Examples

The following functions render a textured NURBS curve with normals:

``` syntax
gluBeginCurve(nobj);
    gluNurbsCurve(nobj, ..., GL_MAP1_TEXTURE_COORD_2);
    gluNurbsCurve(nobj, ..., GL_MAP1_NORMAL);
    gluNurbsCurve(nobj, ..., GL_MAP1_VERTEX_4);
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

[**gluBeginCurve**](https://learn.microsoft.com/windows/win32/opengl/glubegincurve)

[**gluBeginTrim**](https://learn.microsoft.com/windows/win32/opengl/glubegintrim)

[**gluEndCurve**](https://learn.microsoft.com/windows/win32/opengl/gluendcurve)

[**gluEndTrim**](https://learn.microsoft.com/windows/win32/opengl/gluendtrim)

[**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)

[**gluPwlCurve**](https://learn.microsoft.com/windows/win32/opengl/glupwlcurve)


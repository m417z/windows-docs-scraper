# gluNurbsSurface function

The **gluNurbsSurface** function defines the shape of a Non-Uniform Rational B-Spline ([NURBS](https://learn.microsoft.com/windows/win32/opengl/using-nurbs-curves-and-surfaces)) surface.

## Parameters

*nobj*

The NURBS object (created with [**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)).

*sknot\_count*

The number of knots in the parametric *u* direction.

*sknot*

An array of *sknot\_count* nondecreasing knot values in the parametric *u* direction.

*tknot\_count*

The number of knots in the parametric *v* direction.

*tknot*

An array of *tknot\_count* nondecreasing knot values in the parametric *v* direction.

*s\_stride*

The offset (as a number of single precisionfloating-point values) between successive control points in the parametric *u* direction in *ctlarray*.

*t\_stride*

The offset (in single precisionfloating-point values) between successive control points in the parametric *v* direction in *ctlarray*.

*ctlarray*

An array containing control points for the NURBS surface. The offsets between successive control points in the parametric *u* and *v* directions are given by *s\_stride* and *t\_stride*.

*sorder*

The order of the NURBS surface in the parametric *u* direction. The order is one more than the degree, hence a surface that is cubic in *u* has a *u* order of 4.

*torder*

The order of the NURBS surface in the parametric *v* direction. The order is one more than the degree, hence a surface that is cubic in *v* has a *v* order of 4.

*type*

The type of the surface. The *type* parameter can be any of the valid two-dimensional evaluator types (such as GL\_MAP2\_VERTEX\_3 or GL\_MAP2\_COLOR\_4).

## Return value

This function does not return a value.

## Remarks

Use **gluNurbsSurface** within a NURBS surface definition to describe the shape of a NURBS surface (before any trimming). To mark the beginning of a NURBS surface definition, use the [**gluBeginSurface**](https://learn.microsoft.com/windows/win32/opengl/glubeginsurface) function. To mark the end of a NURBS surface definition, use the [**gluEndSurface**](https://learn.microsoft.com/windows/win32/opengl/gluendsurface) function. Call **gluNurbsSurface** within a NURBS surface definition only.

You associate positional, texture, and color coordinates with a surface by presenting each as a separate **gluNurbsSurface** between a **gluBeginSurface**/**gluEndSurface** pair. Within a single **gluBeginSurface**/**gluEndSurface** pair, you can make only one call to **gluNurbsSurface** for color, position, and texture data. Make exactly one call to describe the position of the surface (a *type* of GL\_MAP2\_VERTEX\_3 or GL\_MAP2\_VERTEX\_4).

You can trim a NURBS surface by using the [**gluNurbsCurve**](https://learn.microsoft.com/windows/win32/opengl/glunurbscurve) and [**gluPwlCurve**](https://learn.microsoft.com/windows/win32/opengl/glupwlcurve) functions between calls to [**gluBeginTrim**](https://learn.microsoft.com/windows/win32/opengl/glubegintrim) and [**gluEndTrim**](https://learn.microsoft.com/windows/win32/opengl/gluendtrim).

A **gluNurbsSurface** with *sknot\_count* knots in the *u* direction and *tknot\_count* knots in the *v* direction with orders *sorder* and *torder* must have (*sknot\_count* -*sorder*) multipied by (*tknot\_count* -*torder*) control points.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**gluBeginSurface**](https://learn.microsoft.com/windows/win32/opengl/glubeginsurface)

[**gluBeginTrim**](https://learn.microsoft.com/windows/win32/opengl/glubegintrim)

[**gluEndSurface**](https://learn.microsoft.com/windows/win32/opengl/gluendsurface)

[**gluEndTrim**](https://learn.microsoft.com/windows/win32/opengl/gluendtrim)

[**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)

[**gluNurbsCurve**](https://learn.microsoft.com/windows/win32/opengl/glunurbscurve)

[**gluPwlCurve**](https://learn.microsoft.com/windows/win32/opengl/glupwlcurve)


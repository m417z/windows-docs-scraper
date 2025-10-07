# gluPwlCurve function

The **gluPwlCurve** function describes a piecewise linear Non-Uniform Rational B-Spline ([NURBS](https://learn.microsoft.com/windows/win32/opengl/using-nurbs-curves-and-surfaces)) trimming curve.

## Parameters

*nobj*

The NURBS object (created with [**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)).

*count*

The number of points on the curve.

*array*

An array containing the curve points.

*stride*

The offset (a number of single-precision floating-point values) between points on the curve.

*type*

The type of curve. Must be either GLU\_MAP1\_TRIM\_2 or GLU\_MAP1\_TRIM\_3.

## Return value

This function does not return a value.

## Remarks

The **gluPwlCurve** function describes a piecewise linear trimming curve for a NURBS surface. A piecewise linear curve consists of a list of coordinates of points in the parameter space for the NURBS surface to be trimmed. These points are connected with line segments to form a curve. If the curve is an approximation to a real curve, the points should be close enough that the resulting path appears curved at the resolution used in the application.

If *type* is GLU\_MAP1\_TRIM\_2, it describes a curve in two-dimensional (*u* and *v*) parameter space. If it is GLU\_MAP1\_TRIM\_3, then it describes a curve in two-dimensional homogeneous (*u*, *v*, and *w*) parameter space. For more information about trimming curves, see [**gluBeginTrim**](https://learn.microsoft.com/windows/win32/opengl/glubegintrim).

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


# gluEndTrim function

The [**gluBeginTrim**](https://learn.microsoft.com/windows/win32/opengl/glubegintrim) and **gluEndTrim** functions delimit a Non-Uniform Rational B-Spline ([NURBS](https://learn.microsoft.com/windows/win32/opengl/using-nurbs-curves-and-surfaces)) trimming loop definition.

## Parameters

*nobj*

The NURBS object (created with [**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)).

## Return value

This function does not return a value.

## Remarks

Use [**gluBeginTrim**](https://learn.microsoft.com/windows/win32/opengl/glubegintrim) to mark the beginning of a trimming loop, and **gluEndTrim** to mark the end of a trimming loop. A trimming loop is a set of oriented curve segments (forming a closed curve) that define boundaries of a NURBS surface. You include these trimming loops in the definition of a NURBS surface, between calls to [**gluBeginSurface**](https://learn.microsoft.com/windows/win32/opengl/glubeginsurface) and [**gluEndSurface**](https://learn.microsoft.com/windows/win32/opengl/gluendsurface).

The definition for a NURBS surface can contain many trimming loops. For example, if you write a definition for a NURBS surface that resembles a rectangle with a hole punched out, the definition would contain two trimming loops. One loop would define the outer edge of the rectangle; the other would define the punched-out hole. The definitions of each of these trimming loops would be bracketed by a [**gluBeginTrim**](https://learn.microsoft.com/windows/win32/opengl/glubegintrim) / **gluEndTrim** pair.

The definition of a single closed trimming loop can consist of multiple curve segments, each described as a series of line segments that form a linear curve (see [**gluPwlCurve**](https://learn.microsoft.com/windows/win32/opengl/glupwlcurve)), as a single NURBS curve (see [**gluNurbsCurve**](https://learn.microsoft.com/windows/win32/opengl/glunurbscurve)), or as a combination of both in any order. The only library calls that can appear in a trimming-loop definition (between the calls to [**gluBeginTrim**](https://learn.microsoft.com/windows/win32/opengl/glubegintrim) and **gluEndTrim**) are **gluPwlCurve** and **gluNurbsCurve**.

The displayed area of the NURBS surface is the region in the domain to the left of the trimming curve as the curve parameter increases. Thus, the retained region of the NURBS surface is inside a counterclockwise trimming loop and outside a clockwise trimming loop. For the rectangle mentioned earlier, the trimming loop for the outer edge of the rectangle runs counterclockwise, while the trimming loop for the punched-out hole runs clockwise.

If you use more than one curve to define a single trimming loop, the curve segments must form a closed loop (that is, the endpoint of each curve must be the starting point of the next curve, and the endpoint of the final curve must be the starting point of the first curve). If the endpoints of the curve are sufficiently close together but not exactly coincident, they will be forced to match. If the endpoints are not sufficiently close, an error results (see [*gluNurbsCallback*](https://learn.microsoft.com/windows/win32/opengl/glunurbs)).

If a trimming-loop definition contains multiple curves, the direction of the curves must be consistent (that is, the inside must be to the left of all of the curves). You can use nested trimming loops as long as the curve orientations alternate correctly. Trimming curves cannot be self-intersecting, nor can they intersect one another (or an error results).

If no trimming information is given for a NURBS surface, the entire surface is drawn.

## Examples

This code fragment defines a trimming loop that consists of one piecewise linear curve and two NURBS curves:

``` syntax
gluBeginTrim(nobj);
    gluPwlCurve(. . ., GLU_MAP1_TRIM_2);
    gluNurbsCurve(. . ., GLU_MAP1_TRIM_2);
    gluNurbsCurve(. . ., GLU_MAP1_TRIM_3);
gluEndTrim(nobj);
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

[**gluBeginSurface**](https://learn.microsoft.com/windows/win32/opengl/glubeginsurface)

[**gluEndSurface**](https://learn.microsoft.com/windows/win32/opengl/gluendsurface)

[**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)

[*gluNurbsCallback*](https://learn.microsoft.com/windows/win32/opengl/glunurbs)

[**gluNurbsCurve**](https://learn.microsoft.com/windows/win32/opengl/glunurbscurve)

[**gluPwlCurve**](https://learn.microsoft.com/windows/win32/opengl/glupwlcurve)


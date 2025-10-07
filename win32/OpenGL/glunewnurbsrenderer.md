# gluNewNurbsRenderer function

The **gluNewNurbsRenderer** function creates a Non-Uniform Rational B-Spline ([NURBS](https://learn.microsoft.com/windows/win32/opengl/using-nurbs-curves-and-surfaces)) object.

## Parameters

This function has no parameters.

## Remarks

The **gluNewNurbsRenderer** function creates and returns a pointer to a new NURBS object. Refer to this object when calling NURBS rendering and control functions. A return value of zero means there is not enough memory to allocate to the object.

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

[**gluBeginSurface**](https://learn.microsoft.com/windows/win32/opengl/glubeginsurface)

[**gluBeginTrim**](https://learn.microsoft.com/windows/win32/opengl/glubegintrim)

[**gluDeleteNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/gludeletenurbsrenderer)

[*gluNurbsCallback*](https://learn.microsoft.com/windows/win32/opengl/glunurbs)

[**gluNurbsProperty**](https://learn.microsoft.com/windows/win32/opengl/glunurbsproperty)


# gluDeleteNurbsRenderer function

The **gluDeleteNurbsRenderer** function destroys a Non-Uniform Rational B-Spline ([NURBS](https://learn.microsoft.com/windows/win32/opengl/using-nurbs-curves-and-surfaces)) object.

## Parameters

*nobj*

The NURBS object to be destroyed (created with **gluNewNurbsRenderer**).

## Return value

This function does not return a value.

## Remarks

The **gluDeleteNurbsRenderer** function destroys the NURBS object and frees any memory that it used. After you have called **gluDeleteNurbsRenderer**, you cannot use *nobj* again.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)


# gluGetNurbsProperty function

The **gluGetNurbsProperty** function gets a Non-Uniform Rational B-Spline ([NURBS](https://learn.microsoft.com/windows/win32/opengl/using-nurbs-curves-and-surfaces)) property.

## Parameters

*nobj*

The NURBS object (created with [**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)).

*property*

The property whose value is to be retrieved. The following values are valid: GLU\_SAMPLING\_TOLERANCE, GLU\_DISPLAY\_MODE, GLU\_CULLING, GLU\_AUTO\_LOAD\_MATRIX, GLU\_PARAMETRIC\_TOLERANCE, GLU\_SAMPLING\_METHOD, GLU\_U\_STEP, and GLU\_V\_STEP.

*value*

A pointer to the location into which the value of the named property is written.

## Return value

This function does not return a value.

## Remarks

Use **gluGetNurbsProperty** to retrieve properties stored in a NURBS object. These properties affect the way NURBS curves and surfaces are rendered. For information about NURBS properties, see [**gluNurbsProperty**](https://learn.microsoft.com/windows/win32/opengl/glunurbsproperty).

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

[**gluNurbsProperty**](https://learn.microsoft.com/windows/win32/opengl/glunurbsproperty)


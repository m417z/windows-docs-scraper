# gluNurbsCallback function

The **gluNurbsCallback** function defines a callback for a Non-Uniform Rational B-Spline ([NURBS](https://learn.microsoft.com/windows/win32/opengl/using-nurbs-curves-and-surfaces)) object.

## Parameters

*nobj*

The NURBS object (created with [**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)).

*which*

The callback being defined. The only valid value is GLU\_ERROR. The meaning of GLU\_ERROR means that the error function is called when an error is encountered. Its single argument is of type **GLenum**, and it indicates the specific error that occurred. There are 37 errors unique to NURBS, named GLU\_NURBS\_ERROR1 through GLU\_NURBS\_ERROR37. Character strings describing these errors can be retrieved with [**gluErrorString**](https://learn.microsoft.com/windows/win32/opengl/gluerrorstring).

*fn*

A pointer to the callback function.

## Return value

This function does not return a value.

## Remarks

Use **gluNurbsCallback** to define a callback to be used by a NURBS object. If the specified callback is already defined, it is replaced. If *fn* is **NULL**, then any existing callback is erased.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**gluErrorString**](https://learn.microsoft.com/windows/win32/opengl/gluerrorstring)

[**gluNewNurbsRenderer**](https://learn.microsoft.com/windows/win32/opengl/glunewnurbsrenderer)


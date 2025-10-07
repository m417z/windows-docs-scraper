# gluOrtho2D function

The **gluOrtho2D** function defines a 2-D orthographic projection matrix.

## Parameters

*left*

The coordinate for the left vertical clipping plane.

*right*

The coordinate for the right vertical clipping plane.

*bottom*

The coordinate for the bottom horizontal clipping plane.

*top*

The coordinate for the top horizontal clipping plane.

## Return value

This function does not return a value.

## Remarks

The **gluOrtho2D** function sets up a two-dimensional orthographic viewing region. This is equivalent to calling [**glOrtho**](https://learn.microsoft.com/windows/win32/opengl/glortho) with zNear = -1 and zFar = 1.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**glOrtho**](https://learn.microsoft.com/windows/win32/opengl/glortho)

[**gluPerspective**](https://learn.microsoft.com/windows/win32/opengl/gluperspective)


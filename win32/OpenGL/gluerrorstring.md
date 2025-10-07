# gluErrorString function

The **gluErrorString** function produces an error string from an OpenGL or GLU error code. The error string is ANSI only.

## Parameters

*errCode*

An OpenGL or GLU error code.

## Remarks

The **gluErrorString** function produces an error string from an OpenGL or GLU error code. The string is in an ISO Latin 1 format. For example, **gluErrorString**(GL\_OUT\_OF\_MEMORY) returns the string "out of memory".

The standard GLU error codes are GLU\_INVALID\_ENUM, GLU\_INVALID\_VALUE, and GLU\_OUT\_OF\_MEMORY. Certain other GLU functions can return specialized error codes through callbacks. For the list of OpenGL error codes, see [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror).

The **gluErrorString** function produces error strings in ANSI only. Whenever possible, use **gluErrorStringWIN**, which allows ANSI or Unicode error strings. This makes it easier to localize your program for use with another language.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror)

[*gluNurbsCallback*](https://learn.microsoft.com/windows/win32/opengl/glunurbs)

[*gluQuadricCallback*](https://learn.microsoft.com/windows/win32/opengl/gluquadric)

[*gluTessCallback*](https://learn.microsoft.com/windows/win32/opengl/glutess)


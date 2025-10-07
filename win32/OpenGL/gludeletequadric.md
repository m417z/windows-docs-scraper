# gluDeleteQuadric function

The **gluDeleteQuadric** function destroys a quadric object.

## Parameters

*state*

The quadric object to be destroyed (created with [**gluNewQuadric**](https://learn.microsoft.com/windows/win32/opengl/glunewquadric)).

## Return value

This function does not return a value.

## Remarks

The **gluDeleteQuadric** function destroys the quadric object and frees any memory that it used. After you have called **gluDeleteQuadric**, you cannot use *state* again.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**gluNewQuadric**](https://learn.microsoft.com/windows/win32/opengl/glunewquadric)


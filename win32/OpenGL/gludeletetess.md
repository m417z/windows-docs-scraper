# gluDeleteTess function

The **gluDeleteTess** function destroys a tessellation object.

## Parameters

*tess*

The tessellation object to destroy (created with [**gluNewTess**](https://learn.microsoft.com/windows/win32/opengl/glunewtess)).

## Return value

This function does not return a value.

## Remarks

The **gluDeleteTess** function destroys the indicated tessellation object and frees any memory that it used.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**gluNewTess**](https://learn.microsoft.com/windows/win32/opengl/glunewtess)

[**gluTessBeginPolygon**](https://learn.microsoft.com/windows/win32/opengl/glubeginpolygon)

[*gluTessCallback*](https://learn.microsoft.com/windows/win32/opengl/glutess)


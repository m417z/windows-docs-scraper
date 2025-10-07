# gluNewTess function

The **gluNewTess** function creates a tessellation object.

## Parameters

This function has no parameters.

## Remarks

The **gluNewTess** function creates and returns a pointer to a new tessellation object. Refer to this object when calling tessellation functions. A return value of zero means there is not enough memory to allocate to the object.

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**gluDeleteTess**](https://learn.microsoft.com/windows/win32/opengl/gludeletetess)

[**gluTessBeginPolygon**](https://learn.microsoft.com/windows/win32/opengl/glubeginpolygon)

[*gluTessCallback*](https://learn.microsoft.com/windows/win32/opengl/glutess)


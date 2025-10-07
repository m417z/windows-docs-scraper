# glIsList function

The **gllsList** function tests for display list existence.

## Parameters

*list*

A potential display list name.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **gllsList** function returns GL\_TRUE if *list* is the name of a display list and returns GL\_FALSE otherwise.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

## See also

[**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)

[**glCallList**](https://learn.microsoft.com/windows/win32/opengl/glcalllist)

[**glCallLists**](https://learn.microsoft.com/windows/win32/opengl/glcalllists)

[**glDeleteLists**](https://learn.microsoft.com/windows/win32/opengl/gldeletelists)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGenLists**](https://learn.microsoft.com/windows/win32/opengl/glgenlists)

[**glNewList**](https://learn.microsoft.com/windows/win32/opengl/glnewlist)


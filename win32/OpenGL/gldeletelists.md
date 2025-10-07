# glDeleteLists function

The **glDeleteLists** function deletes a contiguous group of display lists.

## Parameters

*list*

The integer name of the first display list to delete.

*range*

The number of display lists to delete.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_VALUE** | *range* was negative.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glDeleteLists** function causes a contiguous group of display lists to be deleted. The *list* parameter is the name of the first display list to be deleted, and *range* is the number of display lists to delete. All display lists *d* with *list* = *d* = *list* + *range* - 1 are deleted.

All storage locations allocated to the specified display lists are freed, and the names are available for reuse at a later time. Names within the range that do not have an associated display list are ignored. If *range* is zero, nothing happens.

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

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGenLists**](https://learn.microsoft.com/windows/win32/opengl/glgenlists)

[**glIsList**](https://learn.microsoft.com/windows/win32/opengl/glislist)

[**glNewList**](https://learn.microsoft.com/windows/win32/opengl/glnewlist)


# glGenLists function

The **glGenLists** function generates a contiguous set of empty display lists.

## Parameters

*range*

The number of contiguous empty display lists to be generated.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_VALUE** | *range* was negative.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glGenLists** function has one argument, *range*. It returns an integer *n* such that *range* contiguous empty display lists, named *n*, *n* + 1, . . ., *n* + (*range* - 1), are created. If *range* is zero, if there is no group of *range* contiguous names available, or if any error is generated, then no display lists are generated and zero is returned.

The following function retrieves information related to **glGenLists**:

[**glIsList**](https://learn.microsoft.com/windows/win32/opengl/glislist)

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

[**glIsList**](https://learn.microsoft.com/windows/win32/opengl/glislist)

[**glNewList**](https://learn.microsoft.com/windows/win32/opengl/glnewlist)


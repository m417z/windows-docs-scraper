# glClearStencil function

The **glClearStencil** function specifies the clear value for the stencil buffer.

## Parameters

*s*

The index used when the stencil buffer is cleared. The default value is zero.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glClearStencil** function specifies the index used by [**glClear**](https://learn.microsoft.com/windows/win32/opengl/glclear) to clear the stencil buffer. The *s* parameter is masked with 2m  - 1, where *m* is the number of bits in the stencil buffer.

The following functions retrieve information related to the **glClearStencil** function:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_STENCIL\_CLEAR\_VALUE

**glGet** with argument GL\_STENCIL\_BITS

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

[**glClear**](https://learn.microsoft.com/windows/win32/opengl/glclear)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)


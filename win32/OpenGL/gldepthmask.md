# glDepthMask function

The **glDepthMask** function enables or disables writing into the depth buffer.

## Parameters

*flag*

Specifies whether the depth buffer is enabled for writing. If *flag* is zero, depth-buffer writing is disabled. Otherwise, it is enabled. Initially, depth-buffer writing is enabled.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The following function retrieves information related to **glDepthMask**:

**glGet** with argument GL\_DEPTH\_WRITEMASK

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

[**glColorMask**](https://learn.microsoft.com/windows/win32/opengl/glcolormask)

[**glDepthFunc**](https://learn.microsoft.com/windows/win32/opengl/gldepthfunc)

[**glDepthRange**](https://learn.microsoft.com/windows/win32/opengl/gldepthrange)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glIndexMask**](https://learn.microsoft.com/windows/win32/opengl/glindexmask)

[**glStencilMask**](https://learn.microsoft.com/windows/win32/opengl/glstencilmask)


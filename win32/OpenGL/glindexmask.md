# glIndexMask function

The **glIndexMask** function controls the writing of individual bits in the color-index buffers.

## Parameters

*mask*

A bit mask to enable and disable the writing of individual bits in the color-index buffers. Initially, the mask is all ones.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glIndexMask** function controls the writing of individual bits in the color-index buffers. The least significant *n* bits of *mask*, where *1* is the number of bits in a color-index buffer, specify a mask. Wherever a one appears in the mask, the corresponding bit in the color-index buffer (or buffers) is made writable. Where a zero appears, the bit is write-protected.

This mask is used only in color-index mode, and it affects only the buffers currently selected for writing (see [**glDrawBuffer**](https://learn.microsoft.com/windows/win32/opengl/gldrawbuffer)). Initially, all bits are enabled for writing.

The following function retrieves information related to **glIndexMask**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_INDEX\_WRITEMASK

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

[**glDepthMask**](https://learn.microsoft.com/windows/win32/opengl/gldepthmask)

[**glDrawBuffer**](https://learn.microsoft.com/windows/win32/opengl/gldrawbuffer)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glIndex**](https://learn.microsoft.com/windows/win32/opengl/glindex-functions)

[**glStencilMask**](https://learn.microsoft.com/windows/win32/opengl/glstencilmask)


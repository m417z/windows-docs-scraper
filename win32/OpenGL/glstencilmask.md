# glStencilMask function

The **glStencilMask** function controls the writing of individual bits in the stencil planes.

## Parameters

*mask*

A bit mask to enable and disable writing of individual bits in the stencil planes. Initially, the mask is all ones.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glStencilMask** function controls the writing of individual bits in the stencil planes. The least significant *n* bits of *mask*, where *n* is the number of bits in the stencil buffer, specify a mask. Wherever a one appears in the mask, the corresponding bit in the stencil buffer is made writable. Where a zero appears, the bit is write-protected. Initially, all bits are enabled for writing.

The following functions retrieve information related to **glStencilMask**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_STENCIL\_WRITEMASK

glGet with argument GL\_STENCIL\_BITS

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

[**glDepthMask**](https://learn.microsoft.com/windows/win32/opengl/gldepthmask)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glIndexMask**](https://learn.microsoft.com/windows/win32/opengl/glindexmask)

[**glStencilFunc**](https://learn.microsoft.com/windows/win32/opengl/glstencilfunc)

[**glStencilOp**](https://learn.microsoft.com/windows/win32/opengl/glstencilop)


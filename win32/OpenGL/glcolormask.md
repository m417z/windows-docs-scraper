# glColorMask function

The **glColorMask** function enables and disables writing of frame-buffer color components.

## Parameters

*red*

Specify whether red can or cannot be written into the framebuffer. The default values is GL\_TRUE, indicating that the color component can be written.

*green*

Specify whether green can or cannot be written into the framebuffer. The default value is GL\_TRUE, indicating that the color component can be written.

*blue*

Specify whether blue can or cannot be written into the framebuffer. The default value is GL\_TRUE, indicating that the color component can be written.

*alpha*

Specify whether alpha can or cannot be written into the framebuffer. The default value is GL\_TRUE, indicating that the color component can be written.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glColorMask** function specifies whether the individual color components in the framebuffer can or cannot be written. If *red* is GL\_FALSE, for example, no change is made to the red component of any pixel in any of the color buffers, regardless of the drawing operation attempted.

Changes to individual bits of components cannot be controlled. Rather, changes are either enabled or disabled for entire color components.

The following functions retrieve information related to **glColorMask**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_COLOR\_WRITEMASK

**glGet** with argument GL\_RGBA\_MODE

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

[**glColor**](https://learn.microsoft.com/windows/win32/opengl/glcolor-functions)

[**glDepthMask**](https://learn.microsoft.com/windows/win32/opengl/gldepthmask)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glIndex**](https://learn.microsoft.com/windows/win32/opengl/glindex-functions)

[**glIndexMask**](https://learn.microsoft.com/windows/win32/opengl/glindexmask)

[**glStencilMask**](https://learn.microsoft.com/windows/win32/opengl/glstencilmask)


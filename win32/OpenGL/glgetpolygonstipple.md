# glGetPolygonStipple function

The **glGetPolygonStipple** function returns the polygon stipple pattern.

## Parameters

*mask*

Returns the stipple pattern.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glGetPolygonStipple** function returns a 32x32 polygon stipple pattern through the *mask* parameter. The pattern is packed into memory as if [**glReadPixels**](https://learn.microsoft.com/windows/win32/opengl/glreadpixels) with both *height* and *width* of 32, *type* of GL\_BITMAP, and *format* of GL\_COLOR\_INDEX were called, and the stipple pattern were stored in an internal 32x32 color-index buffer. Unlike **glReadPixels**, however, pixel-transfer operations (shift, offset, and pixel map) are not applied to the returned stipple image.

If an error is generated, no change is made to the contents of *mask*.

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

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions)

[**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)

[**glPolygonStipple**](https://learn.microsoft.com/windows/win32/opengl/glpolygonstipple)

[**glReadPixels**](https://learn.microsoft.com/windows/win32/opengl/glreadpixels)


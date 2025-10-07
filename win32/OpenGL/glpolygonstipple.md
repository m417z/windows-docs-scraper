# glPolygonStipple function

The **glPolygonStipple** function sets the polygon stippling pattern.

## Parameters

*mask*

A pointer to a 32x32 stipple pattern that will be unpacked from memory in the same way that [**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels) unpacks pixels.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glPolygonStipple** function sets the polygon stippling pattern. Polygon stippling, like line stippling (see [**glLineStipple**](https://learn.microsoft.com/windows/win32/opengl/gllinestipple)), masks out certain fragments produced by rasterization, creating a pattern. Stippling is independent of polygon antialiasing.

The *mask* parameter is a pointer to a 32x32 stipple pattern that is stored in memory just like the pixel data supplied to **glDrawPixels** with *height* and *width* both equal to 32, a pixel *format* of GL\_COLOR\_INDEX, and data *type* of GL\_BITMAP. That is, the stipple pattern is represented as a 32x32 array of 1-bit color indexes packed in unsigned bytes. The [**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions) function parameters, such as GL\_UNPACK\_SWAP\_BYTES and GL\_UNPACK\_LSB\_FIRST, affect the assembling of the bits into a stipple pattern. Pixel transfer operations (shift, offset, and pixel map) are not applied to the stipple image, however.

Polygon stippling is enabled and disabled with [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and **glDisable**, using argument GL\_POLYGON\_STIPPLE. If enabled, a rasterized polygon fragment with window coordinates *x*w and *y*w is sent to the next stage of OpenGL if and only if the (*x*w mod 32)th bit in the (*y*w mod 32)th row of the stipple pattern is one. When polygon stippling is disabled, it is as if the stipple pattern were all ones.

The following functions retrieve information related to **glPolygonStipple**:

[**glGetPolygonStipple**](https://learn.microsoft.com/windows/win32/opengl/glgetpolygonstipple)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_POLYGON\_STIPPLE

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

[**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glLineStipple**](https://learn.microsoft.com/windows/win32/opengl/gllinestipple)

[**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions)

[**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)


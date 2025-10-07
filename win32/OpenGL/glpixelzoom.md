# glPixelZoom function

The **glPixelZoom** function specifies the pixel zoom factors.

## Parameters

*xfactor*

The *x* zoom factor for pixel write operations.

*yfactor*

The *y* zoom factor for pixel write operations.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glPixelZoom** function specifies values for the *x* and *y* zoom factors. During the execution of [**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels) or [**glCopyPixels**](https://learn.microsoft.com/windows/win32/opengl/glcopypixels), if (*x*r ,*y*r ) is the current raster position, and a given element is in the *n*th row and *m*th column of the pixel rectangle, then pixels whose centers are in the rectangle with corners at

![Equation showing the locations where pixels are candidates for replacement.](https://learn.microsoft.com/windows/win32/opengl/images/pix05.png)

are candidates for replacement. Any pixel whose center lies on the bottom or left edge of this rectangular region is also modified.

Pixel zoom factors are not limited to positive values. Negative zoom factors reflect the resulting image about the current raster position.

The following functions retrieve information related to **glPixelZoom**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_ZOOM\_X

**glGet** with argument GL\_ZOOM\_Y

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

[**glCopyPixels**](https://learn.microsoft.com/windows/win32/opengl/glcopypixels)

[**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)


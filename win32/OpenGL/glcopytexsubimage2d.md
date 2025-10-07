# glCopyTexSubImage2D function

The **glCopyTexSubImage2D** function copies a sub-image of a two-dimensional texture image from the framebuffer.

## Parameters

*target*

The target to which the image data will be changed. Must have the value GL\_TEXTURE\_2D.

*level*

The level-of-detail number. Level 0 is the base image. Level *n* is the *n*th mipmap reduction image.

*xoffset*

The texel offset in the *x* direction within the texture array.

*yoffset*

The texel offset in the *y* direction within the texture array.

*x*

The window x-plane coordinates of the lower-left corner of the row of pixels to be copied.

*y*

The window y-plane coordinates of the lower-left corner of the row of pixels to be copied.

*width*

The width of the sub-image of the texture image. Specifying a texture sub-image with zero width has no effect.

*height*

The height of the sub-image of the texture image. Specifying a texture sub-image with zero width has no effect.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *target* was not an accepted value.<br> |
| **GL\_INVALID\_VALUE** | *level* was less than zero or greater than *log*2 (*max*), where *max* is the returned value of GL\_MAX\_TEXTURE\_SIZE.<br> |
| **GL\_INVALID\_VALUE** | *xoffset* was less than *border* or (*xoffset* + *width*)was greater than (*w* + *border*), *yoffset* was less than *border*, or (*yoffset* + *height*) was greater than (*h* + *border*), where *w* is GL\_TEXTURE\_WIDTH and *border* is GL\_TEXTURE\_BORDER. Note that *w* includes twice the *border* width.<br> |
| **GL\_INVALID\_VALUE** | *width* was less than *border* or *y* was less than *border*, where *border* is the border width of the texture array.<br> |
| **GL\_INVALID\_OPERATION** | The texture array was not defined by a previous [**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d) operation.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glCopyTexSubImage2D** function replaces a rectangular portion of a two-dimensional texture image with pixels from the current framebuffer, rather than from main memory as is the case for [**glTexSubImage2D**](https://learn.microsoft.com/windows/win32/opengl/gltexsubimage2d).

A rectangle of pixels beginning with the *x* and *y* window coordinates and with the dimensions *width* and *height* replaces the portion of the texture array with the indexes *xoffset* through *xoffset* + (*width* - 1), with the indexes *yoffset* through *yoffset* + (*width* - 1) at the mipmap level specified by *level*. The destination rectangle in the texture array cannot include any texels outside the originally specified texture array.

The **glCopyTexSubImage2D** function processes the pixels in a row in the same way as [**glCopyPixels**](https://learn.microsoft.com/windows/win32/opengl/glcopypixels), except that before the final conversion of the pixels, all pixel component values are clamped to the range \[0,1\] and converted to the texture's internal format for storage in the texture array. Pixel ordering is determined with lower *x* coordinates corresponding to lower texture coordinates. If any of the pixels within a specified row of the current framebuffer are outside the window associated with the current rendering context, then their values are undefined.

If any of the pixels within the specified rectangle of the current framebuffer are outside the read window associated with the current rendering context, then the values obtained for those pixels are undefined. No change is made to the *internalFormat*, *width*, *height*, or *border* parameter of the specified texture array or to texel values outside the specified texture sub-image.

You cannot include calls to **glCopyTexSubImage2D** in display lists.

> [!Note]
> The **glCopyTexSubImage2D** function is only available in OpenGL version 1.1 or later.

Texturing has no effect in color-index mode. The [**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions) and [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer) functions affect texture images in exactly the way they affect the way pixels are drawn using [**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels).

The following functions retrieve information related to **glCopyTexSubImage2D**:

[**glGetTexImage**](https://learn.microsoft.com/windows/win32/opengl/glgetteximage)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_TEXTURE\_2D

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

[**glCopyTexSubImage1D**](https://learn.microsoft.com/windows/win32/opengl/glcopytexsubimage1d)

[**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glFog**](https://learn.microsoft.com/windows/win32/opengl/glfog)

[**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions)

[**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)

[**glTexEnv**](https://learn.microsoft.com/windows/win32/opengl/gltexenv-functions)

[**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions)

[**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)

[**glTexSubImage2D**](https://learn.microsoft.com/windows/win32/opengl/gltexsubimage2d)

[**glTexParameter**](https://learn.microsoft.com/windows/win32/opengl/gltexparameter-functions)


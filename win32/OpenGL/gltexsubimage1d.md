# glTexSubImage1D function

The **glTexSubImage1D** function specifies a portion of an existing one-dimensional texture image. You cannot define a new texture with **glTexSubImage1D**.

## Parameters

*target*

The target texture. Must be GL\_TEXTURE\_1D.

*level*

The level-of-detail number. Level 0 is the base image. Level *n* is the *n*th mipmap reduction image.

*xoffset*

A texel offset in the *x* direction within the texture array.

*width*

The width of the texture sub-image.

*format*

The format of the pixel data. This parameter can assume one of the following symbolic values.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**GL\_COLOR\_INDEX**

| Each element is a single value, a color index. It is converted to fixed point format (with an unspecified number of 0 bits to the right of the binary point), shifted left or right, depending on the value and sign of GL\_INDEX\_SHIFT, and added to GL\_INDEX\_OFFSET (see [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)). The resulting index is converted to a set of color components using the GL\_PIXEL\_MAP\_I\_TO\_R, GL\_PIXEL\_MAP\_I\_TO\_G, GL\_PIXEL\_MAP\_I\_TO\_B, and GL\_PIXEL\_MAP\_I\_TO\_A tables, and clamped to the range \[0,1\].<br> |
|

**GL\_RED**

| Each element is a single red component. It is converted to floating point format and assembled into an RGBA element by attaching 0.0 for green and blue, and 1.0 for alpha. Each component is then multiplied by the signed scale factor GL\_c\_SCALE, added to the signed bias GL\_c\_BIAS, and clamped to the range \[0,1\] (see **glPixelTransfer**).<br> |
|

**GL\_GREEN**

| Each element is a single green component. It is converted to floating point format and assembled into an RGBA element by attaching 0.0 for red and blue, and 1.0 for alpha. Each component is then multiplied by the signed scale factor GL\_c\_SCALE, added to the signed bias GL\_c\_BIAS, and clamped to the range \[0,1\] (see [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)).<br> |
|

**GL\_BLUE**

| Each element is a single blue component. It is converted to floating point format and assembled into an RGBA element by attaching 0.0 for red and green, and 1.0 for alpha. Each component is then multiplied by the signed scale factor GL\_c\_SCALE, added to the signed bias GL\_c\_BIAS, and clamped to the range \[0,1\] (see **glPixelTransfer**).<br> |
|

**GL\_ALPHA**

| Each element is a single alpha component. It is converted to floating point format and assembled into an RGBA element by attaching 0.0 for red, green, and blue. Each component is then multiplied by the signed scale factor GL\_c\_SCALE, added to the signed bias GL\_c\_BIAS, and clamped to the range \[0,1\] (see [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)).<br> |
|

**GL\_RGB**

| Each element is an RGB triple. It is converted to floating point and assembled into an RGBA element by attaching 1.0 for alpha. Each component is then multiplied by the signed scale factor GL\_c\_SCALE, added to the signed bias GL\_c\_BIAS, and clamped to the range \[0,1\] (see **glPixelTransfer**).<br> |
|

**GL\_RGBA**

| Each element is a complete RGBA element. It is converted to floating point format. Each component is then multiplied by the signed scale factor GL\_c\_SCALE, added to the signed bias GL\_c\_BIAS, and clamped to the range \[0,1\] (see **glPixelTransfer**).<br> |
|

**GL\_LUMINANCE**

| Each element is a single luminance value. It is converted to floating point format, and then assembled into an RGBA element by replicating the luminance value three times for red, green, and blue, and attaching 1.0 for alpha. Each component is then multiplied by the signed scale factor GL\_c\_SCALE, added to the signed bias GL\_c\_BIAS, and clamped to the range \[0,1\] (see [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)).<br> |
|

**GL\_LUMINANCE\_ALPHA**

| Each element is a luminance/alpha pair. It is converted to floating point format, and then assembled into an RGBA element by replicating the luminance value three times for red, green, and blue. Each component is then multiplied by the signed scale factor GL\_c\_SCALE, added to the signed bias GL\_c\_BIAS, and clamped to the range \[0,1\] (see **glPixelTransfer**).<br> |

*type*

The data type of the pixel data. The following symbolic values are accepted: GL\_UNSIGNED\_BYTE, GL\_BYTE, GL\_BITMAP, GL\_UNSIGNED\_SHORT, GL\_SHORT, GL\_UNSIGNED\_INT, GL\_INT, and GL\_FLOAT.

*pixels*

A pointer to the image data in memory.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *target* was not GL\_TEXTURE\_1D.<br> |
| **GL\_INVALID\_ENUM** | *format* was not an accepted constant.<br> |
| **GL\_INVALID\_ENUM** | *type* was not an accepted constant.<br> |
| **GL\_INVALID\_ENUM** | *type* was GL\_BITMAP and *format* was not GL\_COLOR\_INDEX.<br> |
| **GL\_INVALID\_VALUE** | *level* was less than zero or greater than log2 *max*, where *max* was the returned value of GL\_MAX\_TEXTURE\_SIZE.<br> |
| **GL\_INVALID\_VALUE** | *xoffset* was less than *b*, or *offset* + *width* was greater than *wb*, where *w* is the GL\_TEXTURE\_WIDTH, and *b* is the width of the GL\_TEXTURE\_BORDER of the texture image being modified.<br> Note that *w* includes twice the border width.<br> |
| **GL\_INVALID\_VALUE** | *width* was less than *b*, where *b* is the border width of the texture array.<br> |
| **GL\_INVALID\_VALUE** | *border* was not zero or 1.<br> |
| **GL\_INVALID\_OPERATION** | The texure array was not defined by a previous **glTexImage1D** operation.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

One-dimensional texturing for a primitive is enabled using [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and **glDisable** with the argument GL\_TEXTURE\_1D. During texturing, part of a specified texture image is mapped into each enabled primitive. You use the **glTexSubImage1D** function to specify a contiguous sub-image of an existing one-dimensional texture image for texturing.

The texels referenced by *pixels* replace a region of the existing texture array with *x* indexes of *xoffset* and *xoffset* + (*width* 1) inclusive. This region cannot include any texels outside the range of the originally specified texture array.

Specifying a sub-image with a *width* of zero has no effect and does not generate an error.

Texturing has no effect in color-index mode.

In general, texture images can be represented by the same data formats as the pixels in a [**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels) command, except that GL\_STENCIL\_INDEX and GL\_DEPTH\_COMPONENT cannot be used. The [**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions) and [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer) modes affect texture images in exactly the way they affect **glDrawPixels**.

The following functions retrieve information related to **glTexSubImage1D**:

[**glGetTexImage**](https://learn.microsoft.com/windows/win32/opengl/glgetteximage)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_TEXTURE\_1D

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

## See also

[**glCopyTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glcopyteximage1d)

[**glCopyTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glcopyteximage2d)

[**glCopyTexSubImage1D**](https://learn.microsoft.com/windows/win32/opengl/glcopytexsubimage1d)

[**glCopyTexSubImage2D**](https://learn.microsoft.com/windows/win32/opengl/glcopytexsubimage2d)

[**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels)

[**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable)

[**glFog**](https://learn.microsoft.com/windows/win32/opengl/glfog)

[**glGetTexImage**](https://learn.microsoft.com/windows/win32/opengl/glgetteximage)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

[**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions)

[**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)

[**glTexEnv**](https://learn.microsoft.com/windows/win32/opengl/gltexenv-functions)

[**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions)

[**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d)

[**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)

[**glTexParameter**](https://learn.microsoft.com/windows/win32/opengl/gltexparameter-functions)

[**glTexSubImage2D**](https://learn.microsoft.com/windows/win32/opengl/gltexsubimage2d)


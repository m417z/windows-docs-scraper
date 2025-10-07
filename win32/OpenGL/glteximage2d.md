# glTexImage2D function

The **glTexImage2D** function specifies a two-dimensional texture image.

## Parameters

*target*

The target texture. Must be GL\_TEXTURE\_2D.

*level*

The level-of-detail number. Level 0 is the base image level. Level *n* is the *n* th mipmap reduction image.

*internalformat*

The number of color components in the texture. Must be 1, 2, 3, or 4, or one of the following symbolic constants: GL\_ALPHA, GL\_ALPHA4, GL\_ALPHA8, GL\_ALPHA12, GL\_ALPHA16, GL\_LUMINANCE, GL\_LUMINANCE4, GL\_LUMINANCE8, GL\_LUMINANCE12, GL\_LUMINANCE16, GL\_LUMINANCE\_ALPHA, GL\_LUMINANCE4\_ALPHA4, GL\_LUMINANCE6\_ALPHA2, GL\_LUMINANCE8\_ALPHA8, GL\_LUMINANCE12\_ALPHA4, GL\_LUMINANCE12\_ALPHA12, GL\_LUMINANCE16\_ALPHA16, GL\_INTENSITY, GL\_INTENSITY4, GL\_INTENSITY8, GL\_INTENSITY12, GL\_INTENSITY16, GL\_R3\_G3\_B2, GL\_RGB, GL\_RGB4, GL\_RGB5, GL\_RGB8, GL\_RGB10, GL\_RGB12, GL\_RGB16, GL\_RGBA, GL\_RGBA2, GL\_RGBA4, GL\_RGB5\_A1, GL\_RGBA8, GL\_RGB10\_A2, GL\_RGBA12, or GL\_RGBA16.

*width*

The width of the texture image. Must be 2*n* + 2(*border*) for some integer *n*.

*height*

The height of the texture image. Must be 2*m* + 2(*border*) for some integer *m*.

*border*

The width of the border. Must be either 0 or 1.

*format*

The format of the pixel data. It can assume one of nine symbolic values.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**GL\_COLOR\_INDEX**

| Each element is a single value, a color index. It is converted to fixed point (with an unspecified number of 0 bits to the right of the binary point), shifted left or right depending on the value and sign of GL\_INDEX\_SHIFT, and added to GL\_INDEX\_OFFSET (see [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)). The resulting index is converted to a set of color components using the GL\_PIXEL\_MAP\_I\_TO\_R, GL\_PIXEL\_MAP\_I\_TO\_G, GL\_PIXEL\_MAP\_I\_TO\_B, and GL\_PIXEL\_MAP\_I\_TO\_A tables, and clamped to the range \[0,1\].<br> |
|

**GL\_RED**

| Each element is a single red component. It is converted to floating point and assembled into an RGBA element by attaching 0.0 for green and blue, and 1.0 for alpha. Each component is then multiplied by the signed scale factor GL\_c\_SCALE, added to the signed bias GL\_c\_BIAS, and clamped to the range \[0,1\] (see **glPixelTransfer**).<br> |
|

**GL\_GREEN**

| Each element is a single green component. It is converted to floating point and assembled into an RGBA element by attaching 0.0 for red and blue, and 1.0 for alpha. Each component is then multiplied by the signed scale factor GL\_c\_SCALE, added to the signed bias GL\_c\_BIAS, and clamped to the range \[0,1\] (see [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)).<br> |
|

**GL\_BLUE**

| Each element is a single blue component. It is converted to floating point and assembled into an RGBA element by attaching 0.0 for red and green, and 1.0 for alpha. Each component is then multiplied by the signed scale factor GL\_c\_SCALE, added to the signed bias GL\_c\_BIAS, and clamped to the range \[0,1\] (see **glPixelTransfer**).<br> |
|

**GL\_ALPHA**

| Each element is a single red component. It is converted to floating point and assembled into an RGBA element by attaching 0.0 for red, green, and blue. Each component is then multiplied by the signed scale factor GL\_c\_SCALE, added to the signed bias GL\_c\_BIAS, and clamped to the range \[0,1\] (see [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)).<br> |
|

**GL\_RGB**

| Each element is an RGB triple. It is converted to floating point and assembled into an RGBA element by attaching 1.0 for alpha. Each component is then multiplied by the signed scale factor GL\_c\_SCALE, added to the signed bias GL\_c\_BIAS, and clamped to the range \[0,1\] (see **glPixelTransfer**).<br> |
|

**GL\_RGBA**

| Each element is a complete RGBA element. It is converted to floating point. Each component is then multiplied by the signed scale factor GL\_c\_SCALE, added to the signed bias GL\_c\_BIAS, and clamped to the range \[0,1\] (see [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)).<br> |
|

**GL\_BGR\_EXT**

| Each pixel is a group of three components in this order: blue, green, red.<br> GL\_BGR\_EXT provides a format that matches the memory layout of Windows device-independent bitmaps (DIBs). Thus your applications can use the same data with Windows function calls and OpenGL pixel function calls.<br> |
|

**GL\_BGRA\_EXT**

| Each pixel is a group of four components in this order: blue, green, red, alpha. GL\_BGRA\_EXT provides a format that matches the memory layout of Windows device-independent bitmaps (DIBs). Thus your applications can use the same data with Windows function calls and OpenGL pixel function calls.<br> |
|

**GL\_LUMINANCE**

| Each element is a single luminance value. It is converted to floating point, and then assembled into an RGBA element by replicating the luminance value three times for red, green, and blue, and attaching 1.0 for alpha. Each component is then multiplied by the signed scale factor GL\_c\_SCALE, added to the signed bias GL\_c\_BIAS, and clamped to the range \[0,1\] (see **glPixelTransfer**).<br> |
|

**GL\_LUMINANCE\_ALPHA**

| Each element is a luminance/alpha pair. It is converted to floating point, and then assembled into an RGBA element by replicating the luminance value three times for red, green, and blue. Each component is then multiplied by the signed scale factor GL\_c\_SCALE, added to the signed bias GL\_c\_BIAS, and clamped to the range \[0,1\] (see [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)).<br> |

*type*

The data type of the pixel data. The following symbolic values are accepted: GL\_UNSIGNED\_BYTE, GL\_BYTE, GL\_BITMAP, GL\_UNSIGNED\_SHORT, GL\_SHORT, GL\_UNSIGNED\_INT, GL\_INT, and GL\_FLOAT.

*pixels*

A pointer to the image data in memory.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *target* was not an GL\_TEXTURE\_2D.<br> |
| **GL\_INVALID\_ENUM** | *format* was not an accepted *format* constant. Only format constants other than GL\_STENCIL\_INDEX and GL\_DEPTH\_COMPONENT are accepted. See the parameter description of *format* for a list of possible values.<br> |
| **GL\_INVALID\_ENUM** | *type* was not a *type* constant.<br> |
| **GL\_INVALID\_ENUM** | *type* was GL\_BITMAP and *format* was not GL\_COLOR\_INDEX.<br> |
| **GL\_INVALID\_VALUE** | *level* was less than zero or greater than log2 *max*, where *max* was the returned value of GL\_MAX\_TEXTURE\_SIZE.<br> |
| **GL\_INVALID\_VALUE** | *internalformat* was not 1, 2, 3, or 4.<br> |
| **GL\_INVALID\_VALUE** | *width* or height was less than zero or greater than 2 + GL\_MAX\_TEXTURE\_SIZE, or it could not be represented as 2*n* + 2(border) for some integer value of *n*.<br> |
| **GL\_INVALID\_VALUE** | *border* was not 0 or 1.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glTexImage2D** function specifies a two-dimensional texture image. Texturing maps a portion of a specified *texture image* onto each graphical primitive for which texturing is enabled. Two-dimensional texturing is enabled and disabled using [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and **glDisable** with argument GL\_TEXTURE\_2D.

Texture images are defined with **glTexImage2D**. The arguments describe the parameters of the texture image, such as height, width, width of the border, level-of-detail number (see [**glTexParameter**](https://learn.microsoft.com/windows/win32/opengl/gltexparameter-functions)), and number of color components provided. The last three arguments describe the way the image is represented in memory. These arguments are identical to the pixel formats used for [**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels).

Data is read from *pixels* as a sequence of signed or unsigned bytes, shorts or longs, or single-precision floating-point values, depending on *type*. These values are grouped into sets of one, two, three, or four values, depending on *format*, to form elements. If *type* is GL\_BITMAP, the data is considered as a string of unsigned bytes (and *format* must be GL\_COLOR\_INDEX). Each data byte is treated as eight 1-bit elements, with bit ordering determined by GL\_UNPACK\_LSB\_FIRST (see [**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions)). Please see [**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels) for a description of the acceptable values for the *type* parameter.

A texture image can have up to four components per texture element, depending on *components*. A one-component texture image uses only the red component of the RGBA color extracted from *pixels*. A two-component image uses the R and A values. A three-component image uses the R, G, and B values. A four-component image uses all of the RGBA components.

Texturing has no effect in color-index mode.

The texture image can be represented by the same data formats as the pixels in a **glDrawPixels** command, except that GL\_STENCIL\_INDEX and GL\_DEPTH\_COMPONENT cannot be used. The [**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions) and [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer) modes affect texture images in exactly the way they affect **glDrawPixels**.

A texture image with zero height or width indicates the null texture. If the null texture is specified for level-of-detail 0, it is as if texturing were disabled.

The following functions retrieve information related to **glTexImage2D**:

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

[**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glFog**](https://learn.microsoft.com/windows/win32/opengl/glfog)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

[**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions)

[**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)

[**glTexEnv**](https://learn.microsoft.com/windows/win32/opengl/gltexenv-functions)

[**glTexGen**](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions)

[**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d)

[**glTexParameter**](https://learn.microsoft.com/windows/win32/opengl/gltexparameter-functions)


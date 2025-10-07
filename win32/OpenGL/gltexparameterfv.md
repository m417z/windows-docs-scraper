# glTexParameterfv function

Sets texture parameters.

## Parameters

*target*

The target texture, which must be either GL\_TEXTURE\_1D or GL\_TEXTURE\_2D.

*pname*

The symbolic name of a single valued texture parameter. The following symbols are accepted in *pname*.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_TEXTURE\_MIN\_FILTER** | The texture minifying function is used whenever the pixel being textured maps to an area greater than one texture element. There are six defined minifying functions. Two of them use the nearest one or nearest four texture elements to compute the texture value. The other four use mipmaps. <br> A mipmap is an ordered set of arrays representing the same image at progressively lower resolutions. If the texture has dimensions 2nx2m there are max(n, m) + 1 mipmaps. The first mipmap is the original texture, with dimensions 2nx2m. Each subsequent mipmap has dimensions 2k1x2l1 where 2kx2l are the dimensions of the previous mipmap, until either k = 0 or l = 0. At that point, subsequent mipmaps have dimension 1x2l1 or 2k1x1 until the final mipmap, which has dimension 1x1. Mipmaps are defined using [**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d) or [**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d) with the level-of-detail argument indicating the order of the mipmaps. Level 0 is the original texture; level bold max(n, m) is the final 1x1 mipmap.<br> |
| **GL\_TEXTURE\_MAG\_FILTER** | The texture magnification function is used when the pixel being textured maps to an area less than or equal to one texture element. It sets the texture magnification function to either GL\_NEAREST or GL\_LINEAR.<br> |
| **GL\_TEXTURE\_WRAP\_S** | Sets the wrap parameter for texture coordinate s to either GL\_CLAMP or GL\_REPEAT. GL\_CLAMP causes s coordinates to be clamped to the range \[0,1\] and is useful for preventing wrapping artifacts when mapping a single image onto an object. GL\_REPEAT causes the integer part of the s coordinate to be ignored; OpenGL uses only the fractional part, thereby creating a repeating pattern. Border texture elements are accessed only if wrapping is set to GL\_CLAMP. Initially, GL\_TEXTURE\_WRAP\_S is set to GL\_REPEAT.<br> |
| **GL\_TEXTURE\_WRAP\_T** | Sets the wrap parameter for texture coordinate t to either GL\_CLAMP or GL\_REPEAT. See the discussion under GL\_TEXTURE\_WRAP\_S. Initially, GL\_TEXTURE\_WRAP\_T is set to GL\_REPEAT.<br> |
| **GL\_TEXTURE\_BORDER\_COLOR** | Sets a border color. The *params* parameter contains four values that comprise the RGBA color of the texture border. Integer color components are interpreted linearly such that the most positive integer maps to 1.0, and the most negative integer maps to 1.0. The values are clamped to the range \[0,1\] when they are specified. Initially, the border color is (0, 0, 0, 0).<br> |
| **GL\_TEXTURE\_PRIORITY** | Specifies the texture residence priority of the currently bound texture. Permissible values are in the range \[0, 1\]. See [**glPrioritizeTextures**](https://learn.microsoft.com/windows/win32/opengl/glprioritizetextures) and [**glBindTexture**](https://learn.microsoft.com/windows/win32/opengl/glbindtexture) for more information.<br> |

*params*

A pointer to an array where the value or values of pname are stored. The params parameter supplies a function for minifying the texture as one of the following.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_NEAREST** | Returns the value of the texture element that is nearest (in Manhattan distance) to the center of the pixel being textured. <br> |
| **GL\_LINEAR** | Returns the weighted average of the four texture elements that are closest to the center of the pixel being textured. These can include border texture elements, depending on the values of GL\_TEXTURE\_WRAP\_S, GL\_TEXTURE\_WRAP\_T, and on the exact mapping. GL\_NEAREST is generally faster than GL\_LINEAR, but it can produce textured images with sharper edges because the transition between texture elements is not as smooth. The default value of GL\_TEXTURE\_MAG\_FILTER is GL\_LINEAR.<br> |
| **GL\_NEAREST\_MIPMAP\_NEAREST** | Chooses the mipmap that most closely matches the size of the pixel being textured and uses the GL\_NEAREST criterion (the texture element nearest to the center of the pixel) to produce a texture value. <br> |
| **GL\_LINEAR\_MIPMAP\_NEAREST** | Chooses the mipmap that most closely matches the size of the pixel being textured and uses the GL\_LINEAR criterion (a weighted average of the four texture elements that are closest to the center of the pixel) to produce a texture value. <br> |
| **GL\_NEAREST\_MIPMAP\_LINEAR** | Chooses the two mipmaps that most closely match the size of the pixel being textured and uses the GL\_NEAREST criterion (the texture element nearest to the center of the pixel) to produce a texture value from each mipmap. The final texture value is a weighted average of those two values. <br> |
| **GL\_LINEAR\_MIPMAP\_LINEAR** | Chooses the two mipmaps that most closely match the size of the pixel being textured and uses the GL\_LINEAR criterion (a weighted average of the four texture elements that are closest to the center of the pixel) to produce a texture value from each mipmap. The final texture value is a weighted average of those two values.<br> |

The *params* parameter supplies a function for magnifying the texture as one of the following.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_NEAREST** | Returns the value of the texture element that is nearest (in Manhattan distance) to the center of the pixel being textured. <br> |
| **GL\_LINEAR** | Returns the weighted average of the four texture elements that are closest to the center of the pixel being textured. These can include border texture elements, depending on the values of GL\_TEXTURE\_WRAP\_S, GL\_TEXTURE\_WRAP\_T, and on the exact mapping. GL\_NEAREST is generally faster than GL\_LINEAR, but it can produce textured images with sharper edges because the transition between texture elements is not as smooth. The default value of GL\_TEXTURE\_MAG\_FILTER is GL\_LINEAR.<br> |

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *target* or *pname* was not one of the accepted defined values, or when *param* should have had a defined constant value (based on the value of *pname*) and did not.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

Texture mapping is a technique that applies an image onto an object's surface as if the image were a decal or cellophane shrink-wrap. The image is created in texture space, with an (*s*, *t*) coordinate system. A texture is a one- or two-dimensional image and a set of parameters that determine how samples are derived from the image.

The **glTexParameter** function assigns the value or values in params to the texture parameter specified as pname. The target parameter defines the target texture, either GL\_TEXTURE\_1D or GL\_TEXTURE\_2D.

As more texture elements are sampled in the minification process, fewer aliasing artifacts will be apparent. While the GL\_NEAREST and GL\_LINEAR minification functions can be faster than the other four, they sample only one or four texture elements to determine the texture value of the pixel being rendered and can produce moire patterns or ragged transitions. The default value of GL\_TEXTURE\_MIN\_FILTER is GL\_NEAREST\_MIPMAP\_LINEAR.

Suppose that texturing is enabled (by calling [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) with argument GL\_TEXTURE\_1D or GL\_TEXTURE\_2D) and GL\_TEXTURE\_MIN\_FILTER is set to one of the functions that requires a mipmap. If either the dimensions of the texture images currently defined (with previous calls to [**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d) or [**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)) do not follow the proper sequence for mipmaps, or there are fewer texture images defined than are needed, or the set of texture images have differing numbers of texture components, then it is as if texture mapping were disabled. Linear filtering accesses the four nearest texture elements only in 2-D textures. In 1-D textures, linear filtering accesses the two nearest texture elements. The following function retrieves information related to **glTexParameterf**, **glTexParameteri**, **glTexParameterfv**, and **glTexParameteriv**:

[**glGetTexParameter**](https://learn.microsoft.com/windows/win32/opengl/glgettexparameter)

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

[**glBindTexture**](https://learn.microsoft.com/windows/win32/opengl/glbindtexture)

[**glCopyPixels**](https://learn.microsoft.com/windows/win32/opengl/glcopypixels)

[**glCopyTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glcopyteximage1d)

[**glCopyTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glcopyteximage2d)

[**glCopyTexSubImage2D**](https://learn.microsoft.com/windows/win32/opengl/glcopytexsubimage2d)

[**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGetTexParameter**](https://learn.microsoft.com/windows/win32/opengl/glgettexparameter)

[**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions)

[**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)

[**glPrioritizeTextures**](https://learn.microsoft.com/windows/win32/opengl/glprioritizetextures)

[glTexEnv](https://learn.microsoft.com/windows/win32/opengl/gltexenv-functions)

[glTexGen](https://learn.microsoft.com/windows/win32/opengl/gltexgen-functions)

[**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d)

[**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)

[**glTexSubImage1D**](https://learn.microsoft.com/windows/win32/opengl/gltexsubimage1d)

[**glTexSubImage2D**](https://learn.microsoft.com/windows/win32/opengl/gltexsubimage2d)


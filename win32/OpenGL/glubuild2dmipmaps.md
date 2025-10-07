# gluBuild2DMipmaps function

The **gluBuild2DMipmaps** function creates 2-D mipmaps.

## Parameters

*target*

The target texture. Must be GL\_TEXTURE\_2D.

*components*

The number of color components in the texture. Must be 1, 2, 3, or 4.

*width*

The width of the texture image.

*height*

The height of the texture image.

*format*

The format of the pixel data. Must be one of the following: GL\_COLOR\_INDEX, GL\_RED, GL\_GREEN, GL\_BLUE, GL\_ALPHA, GL\_RGB, GL\_RGBA, GL\_BGR\_EXT, GL\_BGRA\_EXT, GL\_LUMINANCE, or GL\_LUMINANCE\_ALPHA.

*type*

The data type for *data*. Must be one of the following: GL\_UNSIGNED\_BYTE, GL\_BYTE, GL\_BITMAP, GL\_UNSIGNED\_SHORT, GL\_SHORT, GL\_UNSIGNED\_INT, GL\_INT, or GL\_FLOAT.

*data*

A pointer to the image data in memory.

## Return value

This function does not return a value.

## Remarks

The **gluBuild2DMipmaps** function obtains the input image and generates all mipmap images (using [**gluScaleImage**](https://learn.microsoft.com/windows/win32/opengl/gluscaleimage)) so the input image can be used as a mipmapped texture image. To load each of the images, call [**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d). If the dimensions of the input image are not powers of two, then the image is scaled so that both the width and height are powers of two before the mipmaps are generated.

A return value of zero indicates success. Otherwise, a GLU error code is returned (see [**gluErrorString**](https://learn.microsoft.com/windows/win32/opengl/gluerrorstring)).

For a description of the acceptable values for the *format* parameter, see **glTexImage2D**. For a description of the acceptable values for *type*, see [**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels).

## Requirements

| Requirement | Value |
|-------------------------------------|--------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Glu.h |
| Library<br> | Glu32.lib |
| DLL<br> | Glu32.dll |

## See also

[**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels)

[**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)

[**gluBuild1DMipmaps**](https://learn.microsoft.com/windows/win32/opengl/glubuild1dmipmaps)

[**gluScaleImage**](https://learn.microsoft.com/windows/win32/opengl/gluscaleimage)


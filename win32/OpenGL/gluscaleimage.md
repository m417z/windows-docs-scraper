# gluScaleImage function

The **gluScaleImage** function scales an image to an arbitrary size.

## Parameters

*format*

The format of the pixel data. The following symbolic values are valid: GL\_COLOR\_INDEX, GL\_STENCIL\_INDEX, GL\_DEPTH\_COMPONENT, GL\_RED, GL\_GREEN, GL\_BLUE, GL\_ALPHA, GL\_RGB, GL\_RGBA, GL\_BGR\_EXT, GL\_BGRA\_EXT, GL\_LUMINANCE, and GL\_LUMINANCE\_ALPHA.

*widthin*

The width of the source image that is scaled.

*heightin*

The height of the source image that is scaled.

*typein*

The data type for *datain*. Must be one of the following: GL\_UNSIGNED\_BYTE, GL\_BYTE, GL\_BITMAP, GL\_UNSIGNED\_SHORT, GL\_SHORT, GL\_UNSIGNED\_INT, GL\_INT, or GL\_FLOAT.

*datain*

A pointer to the source image.

*widthout*

The width of the destination image.

*heightout*

The height of the destination image.

*typeout*

The data type for *dataout*. Must be one of the following: GL\_UNSIGNED\_BYTE, GL\_BYTE, GL\_BITMAP, GL\_UNSIGNED\_SHORT, GL\_SHORT, GL\_UNSIGNED\_INT, GL\_INT, or GL\_FLOAT.

*dataout*

A pointer to the destination image.

## Return value

If the function succeeds, the return value is zero.

If the function fails, the return value is a GLU error code (see [**gluErrorString**](https://learn.microsoft.com/windows/win32/opengl/gluerrorstring)).

## Remarks

The **gluScaleImage** function scales a pixel image using the appropriate pixel store modes to unpack data from the source image and pack data into the destination image.

When shrinking an image, **gluScaleImage** uses a box filter to sample the source image and create pixels for the destination image. When magnifying an image, the pixels from the source image are linearly interpolated to create the destination image.

For a description of the acceptable values for the *format*, *typein*, and *typeout* parameters, see [**glReadPixels**](https://learn.microsoft.com/windows/win32/opengl/glreadpixels).

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

[**glReadPixels**](https://learn.microsoft.com/windows/win32/opengl/glreadpixels)

[**gluBuild1DMipmaps**](https://learn.microsoft.com/windows/win32/opengl/glubuild1dmipmaps)

[**gluBuild2DMipmaps**](https://learn.microsoft.com/windows/win32/opengl/glubuild2dmipmaps)

[**gluErrorString**](https://learn.microsoft.com/windows/win32/opengl/gluerrorstring)


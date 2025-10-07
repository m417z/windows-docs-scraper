# glReadPixels function

The **glReadPixels** function reads a block of pixels from the framebuffer.

## Parameters

*x*

The window *x* coordinate of the first pixel that is read from the framebuffer. Together with the *y* coordinate, specifies the location of the lower-left corner of a rectangular block of pixels.

*y*

The window *y* coordinates of the first pixel that is read from the framebuffer. Together with the *x* coordinate, specifies the location of the lower-left corner of a rectangular block of pixels.

*width*

The width of the pixel rectangle.

*height*

The height of the pixel rectangle. *Width* and *height* parameters of value "1" correspond to a single pixel.

*format*

The format of the pixel data. The following symbolic values are accepted:

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**GL\_COLOR\_INDEX**

| Color indexes are read from the color buffer selected by [**glReadBuffer**](https://learn.microsoft.com/windows/win32/opengl/glreadbuffer). Each index is converted to fixed point, shifted left or right, depending on the value and sign of GL\_INDEX\_SHIFT, and added to GL\_INDEX\_OFFSET. If GL\_MAP\_COLOR is GL\_TRUE, indexes are replaced by their mappings in the table GL\_PIXEL\_MAP\_I\_TO\_I.<br> |
|

**GL\_STENCIL\_INDEX**

| Stencil values are read from the stencil buffer. Each index is converted to fixed point, shifted left or right, depending on the value and sign of GL\_INDEX\_SHIFT, and added to GL\_INDEX\_OFFSET. If GL\_MAP\_STENCIL is GL\_TRUE, indexes are replaced by their mappings in the table GL\_PIXEL\_MAP\_S\_TO\_S.<br> |
|

**GL\_DEPTH\_COMPONENT**

| Depth values are read from the depth buffer. Each component is converted to floating point such that the minimum depth value maps to 0.0 and the maximum value maps to 1.0. Each component is then multiplied by GL\_DEPTH\_SCALE, added to GL\_DEPTH\_BIAS, and finally clamped to the range \[0,1\].<br> |
|

**GL\_RED, GL\_GREEN, GL\_BLUE, GL\_ALPHA, GL\_RGB, GL\_RGBA, GL\_BGR\_EXT, GL\_BGRA\_EXT, GL\_LUMINANCE, GL\_LUMINANCE\_ALPHA**

| Processing differs depending on whether color buffers store color indexes or RGBA color components. If color indexes are stored, they are read from the color buffer selected by [**glReadBuffer**](https://learn.microsoft.com/windows/win32/opengl/glreadbuffer). Each index is converted to fixed point, shifted left or right, depending on the value and sign of GL\_INDEX\_SHIFT, and added to GL\_INDEX\_OFFSET. Indexes are then replaced by the red, green, blue, and alpha values obtained by indexing the GL\_PIXEL\_MAP\_I\_TO\_R, GL\_PIXEL\_MAP\_I\_TO\_G, GL\_PIXEL\_MAP\_I\_TO\_B, and GL\_PIXEL\_MAP\_I\_TO\_A tables. If RGBA color components are stored in the color buffers, they are read from the color buffer selected by **glReadBuffer**. Each color component is converted to floating point such that zero intensity maps to 0.0 and full intensity maps to 1.0. Each component is then multiplied by GL\_c\_SCALE and added to GL\_c\_BIAS, where c is GL\_RED, GL\_GREEN, GL\_BLUE, and GL\_ALPHA. Each component is clamped to the range \[0,1\]. Finally, if GL\_MAP\_COLOR is GL\_TRUE, each color component c is replaced by its mapping in the table GL\_PIXEL\_MAP\_c\_TO\_c, where c again is GL\_RED, GL\_GREEN, GL\_BLUE, and GL\_ALPHA. Each component is scaled to the size of its corresponding table before the lookup is performed. Finally, unneeded data is discarded. For example, GL\_RED discards the green, blue, and alpha components, while GL\_RGB discards only the alpha component. GL\_LUMINANCE computes a single component value as the sum of the red, green, and blue components, and GL\_LUMINANCE\_ALPHA does the same, while keeping alpha as a second value.<br> |

*type*

The data type of the pixel data. Must be one of the following values.

| Type | Index mask | Component conversion |
|---------------------|------------|----------------------|
| GL\_UNSIGNED\_BYTE | 281 | (281)*c* |
| GL\_BYTE | 271 | \[(271)*c*-1\]/2 |
| GL\_BITMAP | 1 | 1 |
| GL\_UNSIGNED\_SHORT | 2 61 | (2 61)*c* |
| GL\_SHORT | 2 51 | \[(2 51)*c*1\]/2 |
| GL\_UNSIGNED\_INT\_ | 2 1 | (2 1)*c* |
| GL\_INT | 2 1 | \[(2 1)*c*1\]/2 |
| GL\_FLOAT | none | *c* |

*pixels*

Returns the pixel data.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *format* or *type* was not an accepted value.<br> |
| **GL\_INVALID\_VALUE** | Either *width* or *height* was negative.<br> |
| **GL\_INVALID\_OPERATION** | *format* was GL\_COLOR\_INDEX, and the color buffers stored RGBA or BGRA color components.<br> |
| **GL\_INVALID\_OPERATION** | *format* was GL\_STENCIL\_INDEX, and there was no stencil buffer.<br> |
| **GL\_INVALID\_OPERATION** | *format* was GL\_DEPTH\_COMPONENT, and there was no depth buffer.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glReadPixels** function returns pixel data from the framebuffer, starting with the pixel whose lower-left corner is at location (*x*, *y*), into client memory starting at location *pixels*. Several parameters control the processing of the pixel data before it is placed into client memory. These parameters are set with three commands: [**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions), [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer), and [**glPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap). This topic describes the effects on **glReadPixels** of most, but not all of the parameters specified by these three commands.

The **glReadPixels** function returns values from each pixel with lower-left corner at (*x* + i, *y* + j) for 0 = i < *width* and 0 = j < *height*. This pixel is said to be the *i*th pixel in the *j*th row. Pixels are returned in row order from the lowest to the highest row, left to right in each row.

The shift, scale, bias, and lookup factors described above are all specified by [**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer). The lookup table contents are specified by [**glPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap).

The final step involves converting the indexes or components to the proper format, as specified by *type*. If *format* is GL\_COLOR\_INDEX or GL\_STENCIL\_INDEX and *type* is not GL\_FLOAT, each index is masked with the mask value given in the following table. If *type* is GL\_FLOAT, then each integer index is converted to single-precision floating-point format.

If *format* is GL\_RED, GL\_GREEN, GL\_BLUE, GL\_ALPHA, GL\_RGB, GL\_RGBA, GL\_BGR\_EXT, GL\_BGRA\_EXT, GL\_LUMINANCE, or GL\_LUMINANCE\_ALPHA and *type* is not GL\_FLOAT, each component is multiplied by the multiplier shown in the preceding table. If type is GL\_FLOAT, then each component is passed as is (or converted to the client's single-precision floating-point format if it is different from the one used by OpenGL).

Return values are placed in memory as follows. If *format* is GL\_COLOR\_INDEX, GL\_STENCIL\_INDEX, GL\_DEPTH\_COMPONENT, GL\_RED, GL\_GREEN, GL\_BLUE, GL\_ALPHA, or GL\_LUMINANCE, a single value is returned and the data for the *i*th pixel in the *j*th row is placed in location (*j* )*width* + *i*. GL\_RGB and GL\_BGR\_EXT return three values, GL\_RGBA and GL\_BGRA\_EXT return four values, and GL\_LUMINANCE\_ALPHA returns two values for each pixel, with all values corresponding to a single pixel occupying contiguous space in *pixels*. Storage parameters set by [**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions), such as GL\_PACK\_SWAP\_BYTES and GL\_PACK\_LSB\_FIRST, affect the way that data is written into memory. See [**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions) for a description.

Values for pixels that lie outside the window connected to the current OpenGL context are undefined.

If an error is generated, no change is made to the contents of *pixels*.

The following function retrieves information related to **glReadPixels**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_INDEX\_MODE

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

[**glPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap)

[**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions)

[**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)

[**glReadBuffer**](https://learn.microsoft.com/windows/win32/opengl/glreadbuffer)


# glAccum function

The **glAccum** function operates on the accumulation buffer.

## Parameters

*op*

The accumulation buffer operation. The accepted symbolic constants are as follows.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**GL\_ACCUM**

| Obtains R, G, B, and A values from the buffer currently selected for reading (see [**glReadBuffer**](https://learn.microsoft.com/windows/win32/opengl/glreadbuffer)). Each component value is divided by 2*n* 1, where *n* is the number of bits allocated to each color component in the currently selected buffer. The result is a floating-point value in the range \[0,1\], which is multiplied by *value* and added to the corresponding pixel component in the accumulation buffer, thereby updating the accumulation buffer.<br> |
|

**GL\_LOAD**

| Similar to GL\_ACCUM, except that the current value in the accumulation buffer is not used in the calculation of the new value. That is, the R, G, B, and A values from the currently selected buffer are divided by 2*n* 1, multiplied by *value*, and then stored in the corresponding accumulation buffer cell, overwriting the current value.<br> |
|

**GL\_ADD**

| Adds *value* to each R, G, B, and A in the accumulation buffer.<br> |
|

**GL\_MULT**

| Multiplies each R, G, B, and A in the accumulation buffer by *value* and returns the scaled component to its corresponding accumulation buffer location.<br> |
|

**GL\_RETURN**

| Transfers accumulation buffer values to the color buffer or buffers currently selected for writing. Each R, G, B, and A component is multiplied by *value*, then multiplied by 2*n* 1, clamped to the range \[0, 2*n* 1 \], and stored in the corresponding display buffer cell. The only fragment operations that are applied to this transfer are pixel ownership, scissor, dithering, and color writemasks.<br> |

*value*

A floating-point value used in the accumulation buffer operation. The *op* parameter determines how *value* is used.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *op* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | There was no accumulation buffer or the function **glAccum** was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The accumulation buffer is an extended-range color buffer. Images are not rendered into it. Rather, images rendered into one of the color buffers are added to the contents of the accumulation buffer after rendering. You can create effects such as antialiasing (of points, lines, and polygons), motion blur, and depth of field by accumulating images generated with different transformation matrices.

Each pixel in the accumulation buffer consists of red, green, blue, and alpha values. The number of bits per component in the accumulation buffer depends on the implementation. You can examine this number by calling [**glGetIntegerv**](https://learn.microsoft.com/windows/win32/opengl/glgetintegerv) four times, with the arguments GL\_ACCUM\_RED\_BITS, GL\_ACCUM\_GREEN\_BITS, GL\_ACCUM\_BLUE\_BITS, and GL\_ACCUM\_ALPHA\_BITS, respectively. Regardless of the number of bits per component, however, the range of values stored by each component is \[ 1,?1\]. The accumulation buffer pixels are mapped one-to-one with framebuffer pixels.

The **glAccum** function operates on the accumulation buffer. The first argument, *op*, is a symbolic constant that selects an accumulation buffer operation. The second argument, *value*, is a floating-point value to be used in that operation. Five operations are specified: GL\_ACCUM, GL\_LOAD, GL\_ADD, GL\_MULT, and GL\_RETURN.

All accumulation buffer operations are limited to the area of the current scissor box and are applied identically to the red, green, blue, and alpha components of each pixel. The contents of an accumulation buffer pixel component are undefined if the **glAccum** operation results in a value outside the range \[ 1,1\].

To clear the accumulation buffer, use the [**glClearAccum**](https://learn.microsoft.com/windows/win32/opengl/glclearaccum) function to specify R, G, B, and A values to set it to, and issue a [**glClear**](https://learn.microsoft.com/windows/win32/opengl/glclear) function with the accumulation buffer enabled.

Only those pixels within the current scissor box are updated by any **glAccum** operation.

The following functions retrieve information related to the **glAccum** function:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_ACCUM\_RED\_BITS

**glGet** with argument GL\_ACCUM\_GREEN\_BITS

**glGet** with argument GL\_ACCUM\_BLUE\_BITS

**glGet** with argument GL\_ACCUM\_ALPHA\_BITS

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

[**glBlendFunc**](https://learn.microsoft.com/windows/win32/opengl/glblendfunc)

[**glClear**](https://learn.microsoft.com/windows/win32/opengl/glclear)

[**glClearAccum**](https://learn.microsoft.com/windows/win32/opengl/glclearaccum)

[**glCopyPixels**](https://learn.microsoft.com/windows/win32/opengl/glcopypixels)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glLogicOp**](https://learn.microsoft.com/windows/win32/opengl/gllogicop)

[**glPixelStore**](https://learn.microsoft.com/windows/win32/opengl/glpixelstore-functions)

[**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)

[**glReadBuffer**](https://learn.microsoft.com/windows/win32/opengl/glreadbuffer)

[**glReadPixels**](https://learn.microsoft.com/windows/win32/opengl/glreadpixels)

[**glScissor**](https://learn.microsoft.com/windows/win32/opengl/glscissor)

[**glStencilOp**](https://learn.microsoft.com/windows/win32/opengl/glstencilop)


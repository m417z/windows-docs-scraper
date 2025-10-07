# glGetPixelMapusv function

The [**glGetPixelMapfv**](https://learn.microsoft.com/windows/win32/opengl/glgetpixelmapfv), [**glGetPixelMapuiv**](https://learn.microsoft.com/windows/win32/opengl/glgetpixelmapuiv), and **glGetPixelMapusv** functions return the specified pixel map.

## Parameters

*map*

The name of the pixel map to return. Accepted values are GL\_PIXEL\_MAP\_I\_TO\_I, GL\_PIXEL\_MAP\_S\_TO\_S, GL\_PIXEL\_MAP\_I\_TO\_R, GL\_PIXEL\_MAP\_I\_TO\_G, GL\_PIXEL\_MAP\_I\_TO\_B, GL\_PIXEL\_MAP\_I\_TO\_A, GL\_PIXEL\_MAP\_R\_TO\_R, GL\_PIXEL\_MAP\_G\_TO\_G, GL\_PIXEL\_MAP\_B\_TO\_B, and GL\_PIXEL\_MAP\_A\_TO\_A.

*values*

Returns the pixel map contents.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *map* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

See [**glPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap) for a description of the acceptable values for the *map* parameter. The **glGetPixelMap** function returns in *values* the contents of the pixel map specified in *map*. Use pixel maps during the execution of [**glReadPixels**](https://learn.microsoft.com/windows/win32/opengl/glreadpixels), [**glDrawPixels**](https://learn.microsoft.com/windows/win32/opengl/gldrawpixels), [**glCopyPixels**](https://learn.microsoft.com/windows/win32/opengl/glcopypixels), [**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d), and [**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d) to map color indexes, stencil indexes, color components, and depth components to other values.

Unsigned integer values, if requested, are linearly mapped from the internal fixed or floating-point representation such that 1.0 maps to the largest representable integer value, and 0.0 maps to zero. Return unsigned integer values are undefined if the map value was not in the range \[0,1\].

To determine the required size of *map*, call [**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with the appropriate symbolic constant.

If an error is generated, no change is made to the contents of *values*.

The following functions retrieve information related to **glGetPixelMap**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_PIXEL\_MAP\_I\_TO\_I\_SIZE

**glGet** with argument GL\_PIXEL\_MAP\_S\_TO\_S\_SIZE

**glGet** with argument GL\_PIXEL\_MAP\_I\_TO\_R\_SIZE

**glGet** with argument GL\_PIXEL\_MAP\_I\_TO\_G\_SIZE

**glGet** with argument GL\_PIXEL\_MAP\_I\_TO\_B\_SIZE

**glGet** with argument GL\_PIXEL\_MAP\_I\_TO\_A\_SIZE

**glGet** with argument GL\_PIXEL\_MAP\_R\_TO\_R\_SIZE

**glGet** with argument GL\_PIXEL\_MAP\_G\_TO\_G\_SIZE

**glGet** with argument GL\_PIXEL\_MAP\_B\_TO\_B\_SIZE

**glGet** with argument GL\_PIXEL\_MAP\_A\_TO\_A\_SIZE

**glGet** with argument GL\_MAX\_PIXEL\_MAP\_TABLE

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

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glPixelMap**](https://learn.microsoft.com/windows/win32/opengl/glpixelmap)

[**glPixelTransfer**](https://learn.microsoft.com/windows/win32/opengl/glpixeltransfer)

[**glReadPixels**](https://learn.microsoft.com/windows/win32/opengl/glreadpixels)

[**glTexImage1D**](https://learn.microsoft.com/windows/win32/opengl/glteximage1d)

[**glTexImage2D**](https://learn.microsoft.com/windows/win32/opengl/glteximage2d)


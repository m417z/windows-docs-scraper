# glAlphaFunc function

The **glAlphaFunc** function enables your application to set the alpha test function.

## Parameters

*func*

The alpha comparison function. The following are the accepted symbolic constants and their meanings.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------|
|

**GL\_NEVER**

| Never passes.<br> |
|

**GL\_LESS**

| Passes if the incoming alpha value is less than the reference value.<br> |
|

**GL\_EQUAL**

| Passes if the incoming alpha value is equal to the reference value.<br> |
|

**GL\_LEQUAL**

| Passes if the incoming alpha value is less than or equal to the reference value.<br> |
|

**GL\_GREATER**

| Passes if the incoming alpha value is greater than the reference value.<br> |
|

**GL\_NOTEQUAL**

| Passes if the incoming alpha value is not equal to the reference value.<br> |
|

**GL\_GEQUAL**

| Passes if the incoming alpha value is greater than or equal to the reference value.<br> |
|

**GL\_ALWAYS**

| Always passes. This is the default.<br> |

*ref*

The reference value to which incoming alpha values are compared. This value is clamped to the range 0 through 1, where 0 represents the lowest possible alpha value and 1 the highest possible value. The default reference is 0.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *func* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The alpha test discards fragments depending on the outcome of a comparison between the incoming fragments' alpha values and a constant reference value. The **glAlphaFunc** function specifies the reference and comparison function. The comparison is performed only if alpha testing is enabled. (For more information on GL\_ALPHA\_TEST, see [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable).)

The *func* and *ref* parameters specify the conditions under which the pixel is drawn. The incoming alpha value is compared to *ref* using the function specified by *func*. If the comparison passes, the incoming fragment is drawn, conditional on subsequent stencil and depth-buffer tests. If the comparison fails, no change is made to the framebuffer at that pixel location.

The **glAlphaFunc** function operates on all pixel writes, including those resulting from the scan conversion of points, lines, polygons, and bitmaps, and from pixel draw and copy operations. The **glAlphaFunc** function does not affect screen clear operations.

Alpha testing is done only in RGBA mode.

The following functions retrieve information related to the **glAlphaFunc** function:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_ALPHA\_TEST\_FUNC

**glGet** with argument GL\_ALPHA\_TEST\_REF

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_ALPHA\_TEST

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

[**glDepthFunc**](https://learn.microsoft.com/windows/win32/opengl/gldepthfunc)

[**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

[**glStencilFunc**](https://learn.microsoft.com/windows/win32/opengl/glstencilfunc)


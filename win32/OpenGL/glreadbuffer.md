# glReadBuffer function

The **glReadBuffer** function selects a color buffer source for pixels.

## Parameters

*mode*

A color buffer. Accepted values are GL\_FRONT\_LEFT, GL\_FRONT\_RIGHT, GL\_BACK\_LEFT, GL\_BACK\_RIGHT, GL\_FRONT, GL\_BACK, GL\_LEFT, GL\_RIGHT, and GL\_AUX *i*, where *i* is between 0 and GL\_AUX\_BUFFERS 1.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *mode* was not one of the twelve (or more) accepted values.<br> |
| **GL\_INVALID\_OPERATION** | *mode* specified a buffer that does not exist.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glReadBuffer** function specifies a color buffer as the source for subsequent [**glReadPixels**](https://learn.microsoft.com/windows/win32/opengl/glreadpixels) and [**glCopyPixels**](https://learn.microsoft.com/windows/win32/opengl/glcopypixels) commands. The *mode* parameter accepts one of twelve or more predefined values. (GL\_AUX0 through GL\_AUX3 are always defined.) In a fully configured system, GL\_FRONT, GL\_LEFT, and GL\_FRONT\_LEFT all name the front-left buffer, GL\_FRONT\_RIGHT and GL\_RIGHT name the front-right buffer, and GL\_BACK\_LEFT and GL\_BACK name the back-left buffer.

Nonstereo double-buffered configurations have only a front-left and a back-left buffer. Single-buffered configurations have a front-left and a front-right buffer if stereo, and only a front-left buffer if nonstereo. It is an error to specify a nonexistent buffer to **glReadBuffer**.

By default, *mode* is GL\_FRONT in single-buffered configurations, and GL\_BACK in double-buffered configurations.

The following function retrieves information related to **glReadBuffer**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_READ\_BUFFER

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

[**glDrawBuffer**](https://learn.microsoft.com/windows/win32/opengl/gldrawbuffer)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glReadPixels**](https://learn.microsoft.com/windows/win32/opengl/glreadpixels)


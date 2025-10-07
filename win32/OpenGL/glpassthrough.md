# glPassThrough function

The **glPassThrough** function places a marker in the feedback buffer.

## Parameters

*token*

A marker value to be placed in the feedback buffer. It is indicated with the following unique identifying value.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------|
|

**GL\_PASS\_THROUGH\_TOKEN**

| The order of **glPassThrough** commands with respect to the specification of graphics primitives is maintained.<br> |

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

Feedback is an OpenGL render mode selected by calling [**glRenderMode**](https://learn.microsoft.com/windows/win32/opengl/glrendermode) with GL\_FEEDBACK. When OpenGL is in feedback mode, no pixels are produced by rasterization. Instead, information about primitives that would have been rasterized is fed back to the application by OpenGL. See [**glFeedbackBuffer**](https://learn.microsoft.com/windows/win32/opengl/glfeedbackbuffer) for a description of the feedback buffer and the values in it.

The **glPassThrough** function inserts a user-defined marker in the feedback buffer when it is executed in feedback mode. The *token* parameter is returned as if it were a primitive.

The **glPassThrough** function is ignored if OpenGL is not in feedback mode.

The following function retrieves information related to **glPassThrough**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_RENDER\_MODE

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

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glFeedbackBuffer**](https://learn.microsoft.com/windows/win32/opengl/glfeedbackbuffer)

[**glRenderMode**](https://learn.microsoft.com/windows/win32/opengl/glrendermode)


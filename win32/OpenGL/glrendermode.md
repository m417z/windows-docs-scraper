# glRenderMode function

The **glRenderMode** function sets the rasterization mode.

## Parameters

*mode*

The rasterization mode. The following three values are accepted. The default value is GL\_RENDER.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
|

**GL\_RENDER**

| Render mode. Primitives are rasterized, producing pixel fragments, which are written into the framebuffer. This is the normal mode and also the default mode.<br> |
|

**GL\_SELECT**

| Selection mode. No pixel fragments are produced, and no change to the framebuffer contents is made. Instead, a record of the names of primitives that would have been drawn if the render mode was GL\_RENDER is returned in a select buffer, which must be created (see [**glSelectBuffer**](https://learn.microsoft.com/windows/win32/opengl/glselectbuffer)) before selection mode is entered.<br> |
|

**GL\_FEEDBACK**

| Feedback mode. No pixel fragments are produced, and no change to the framebuffer contents is made. Instead, the coordinates and attributes of vertices that would have been drawn had the render mode been GL\_RENDER are returned in a feedback buffer, which must be created (see [**glFeedbackBuffer**](https://learn.microsoft.com/windows/win32/opengl/glfeedbackbuffer)) before feedback mode is entered.<br> |

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *mode* was not one of three accepted values.<br> |
| **GL\_INVALID\_OPERATION** | The function was called with argument GL\_SELECT before [**glSelectBuffer**](https://learn.microsoft.com/windows/win32/opengl/glselectbuffer) was called at least once.<br> |
| **GL\_INVALID\_OPERATION** | The function was called with argument GL\_FEEDBACK before [**glBeedbackBuffer**](https://learn.microsoft.com/windows/win32/opengl/glfeedbackbuffer) was called at least once.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glRenderMode** function takes one argument, *mode*, which can assume one of three predefined values above.

The return value of the **glRenderMode** function is determined by the render mode at the time **glRenderMode** is called, rather than by *mode*. The values returned for the three render modes are as follows.

| Value | Meaning |
|--------------|-------------------------------------------------------------------------|
| GL\_RENDER | Zero. |
| GL\_SELECT | The number of hit records transferred to the select buffer. |
| GL\_FEEDBACK | The number of values (not vertices) transferred to the feedback buffer. |

Refer to [**glSelectBuffer**](https://learn.microsoft.com/windows/win32/opengl/glselectbuffer) and [**glFeedbackBuffer**](https://learn.microsoft.com/windows/win32/opengl/glfeedbackbuffer) for more details concerning selection and feedback operation.

If an error is generated, **glRenderMode** returns zero regardless of the current render mode.

The following function retrieves information related to **glRenderMode**:

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

[**glInitNames**](https://learn.microsoft.com/windows/win32/opengl/glinitnames)

[**glLoadName**](https://learn.microsoft.com/windows/win32/opengl/glloadname)

[**glPassThrough**](https://learn.microsoft.com/windows/win32/opengl/glpassthrough)

[**glPushName**](https://learn.microsoft.com/windows/win32/opengl/glpushname)

[**glSelectBuffer**](https://learn.microsoft.com/windows/win32/opengl/glselectbuffer)


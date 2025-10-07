# glScissor function

The **glScissor** function defines the scissor box.

## Parameters

*x*

The x (vertical axis) coordinate for the lower-left corner of the scissor box.

*y*

The y (horizontal axis) coordinate for the lower-left corner of the scissor box. Together, x and y specify the lower-left corner of the scissor box. Initially (0,0).

*width*

The width of the scissor box.

*height*

The height of the scissor box. When an OpenGL context is *first* attached to a window, *width* and *height* are set to the dimensions of that window.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_VALUE** | Either *width* or *height* was negative.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glScissor** function defines a rectangle, called the scissor box, in window coordinates. The first two parameters, *x* and *y*, specify the lower-left corner of the box. The *width* and *height* parameters specify the width and height of the box.

The scissor test is enabled and disabled using [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and **glDisable** with argument GL\_SCISSOR\_TEST. While the scissor test is enabled, only pixels that lie within the scissor box can be modified by drawing commands. Window coordinates have integer values at the shared corners of framebuffer pixels, so **glScissor**(0,0,1,1) allows only the lower-left pixel in the window to be modified, and **glScissor**(0,0,0,0) disallows modification to all pixels in the window.

When the scissor test is disabled, it is as though the scissor box includes the entire window.

The following functions retrieve information related to **glScissor**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_SCISSOR\_BOX

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_SCISSOR\_TEST

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

[**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

[**glViewport**](https://learn.microsoft.com/windows/win32/opengl/glviewport)


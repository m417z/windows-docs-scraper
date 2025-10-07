# glViewport function

The **glViewport** function sets the viewport.

## Parameters

*x*

The lower-left corner of the viewport rectangle, in pixels. The default is (0,0).

*y*

The lower-left corner of the viewport rectangle, in pixels. The default is (0,0).

*width*

The width of the viewport. When an OpenGL context is first attached to a window, *width* and *height* are set to the dimensions of that window.

*height*

The height of the viewport. When an OpenGL context is first attached to a window, *width* and *height* are set to the dimensions of that window.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_VALUE** | Either *width* or *height* was negative.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glViewport** function specifies the affine transformation of *x* and *y* from normalized device coordinates to window coordinates. Let (*x*nd , *y*nd ) be normalized device coordinates. The window coordinates (*x*w , *y*w ) are then computed as follows:

![Equation showing computation of the window coordinates.](https://learn.microsoft.com/windows/win32/opengl/images/view01.png)

Viewport width and height are silently clamped to a range that depends on the implementation. This range is queried by calling **glGet** with argument GL\_MAX\_VIEWPORT\_DIMS.

The following functions retrieve information related to **glViewport**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_VIEWPORT

**glGet** with argument GL\_MAX\_VIEWPORT\_DIMS

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

[**glDepthRange**](https://learn.microsoft.com/windows/win32/opengl/gldepthrange)


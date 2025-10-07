# glFlush function

The **glFlush** function forces execution of OpenGL functions in finite time.

## Parameters

This function has no parameters.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

Different OpenGL implementations buffer commands in several different locations, including network buffers and the graphics accelerator itself. The **glFlush** function empties all these buffers, causing all issued commands to be executed as quickly as they are accepted by the actual rendering engine. Though this execution may not be completed in any particular time period, it does complete in a finite amount of time.

Because any OpenGL program might be executed over a network, or on an accelerator that buffers commands, be sure to call **glFlush** in any programs requiring that all of their previously issued commands have been completed. For example, call **glFlush** before waiting for user input that depends on the generated image.

The **glFlush** function can return at any time. It does not wait until the execution of all previously issued OpenGL functions is complete.

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

[**glFinish**](https://learn.microsoft.com/windows/win32/opengl/glfinish)


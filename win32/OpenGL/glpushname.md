# glPushName function

The **glPushName** and [**glPopName**](https://learn.microsoft.com/windows/win32/opengl/glpopname) functions push and pop the name stack.

## Parameters

*name*

A name that will be pushed onto the name stack.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_STACK\_OVERFLOW** | The function was called while the current matrix stack was full.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glPushName** function causes name to be pushed onto the name stack, which is initially empty. The [**glPopName**](https://learn.microsoft.com/windows/win32/opengl/glpopname) function pops one name off the top of the stack. The name stack is used during selection mode to allow sets of rendering commands to be uniquely identified. It consists of an ordered set of unsigned integers.

The name stack is always empty while the render mode is not GL\_SELECT. Calls to **glPushName** or [**glPopName**](https://learn.microsoft.com/windows/win32/opengl/glpopname) while the render mode is not GL\_SELECT are ignored.

The following functions retrieve information related to **glPushName** and [**glPopName**](https://learn.microsoft.com/windows/win32/opengl/glpopname):

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_NAME\_STACK\_DEPTH

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_MAX\_NAME\_STACK\_DEPTH

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

[**glInitNames**](https://learn.microsoft.com/windows/win32/opengl/glinitnames)

[**glLoadName**](https://learn.microsoft.com/windows/win32/opengl/glloadname)

[**glRenderMode**](https://learn.microsoft.com/windows/win32/opengl/glrendermode)

[**glSelectBuffer**](https://learn.microsoft.com/windows/win32/opengl/glselectbuffer)


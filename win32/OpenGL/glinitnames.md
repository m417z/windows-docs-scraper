# glInitNames function

The **glInitNames** function initializes the name stack.

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

The **glInitNames** function causes the name stack to be initialized to its default empty state. The name stack is used during selection mode to allow sets of rendering commands to be uniquely identified. It consists of an ordered set of unsigned integers.

The name stack is always empty while the render mode is not GL\_SELECT. Calls to **glInitNames** while the render mode is not GL\_SELECT are ignored.

The following functions retrieve information related to **glInitNames**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_NAME\_STACK\_DEPTH

**glGet** with argument GL\_MAX\_NAME\_STACK\_DEPTH

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

[**glLoadName**](https://learn.microsoft.com/windows/win32/opengl/glloadname)

[**glPushName**](https://learn.microsoft.com/windows/win32/opengl/glpushname)

[**glRenderMode**](https://learn.microsoft.com/windows/win32/opengl/glrendermode)

[**glSelectBuffer**](https://learn.microsoft.com/windows/win32/opengl/glselectbuffer)


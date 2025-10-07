# glClearColor function

The **glClearColor** function specifies clear values for the color buffers.

## Parameters

*red*

The red value that [**glClear**](https://learn.microsoft.com/windows/win32/opengl/glclear) uses to clear the color buffers. The default value is zero.

*green*

The green value that [**glClear**](https://learn.microsoft.com/windows/win32/opengl/glclear) uses to clear the color buffers. The default value is zero.

*blue*

The blue value that [**glClear**](https://learn.microsoft.com/windows/win32/opengl/glclear) uses to clear the color buffers. The default value is zero.

*alpha*

The alpha value that [**glClear**](https://learn.microsoft.com/windows/win32/opengl/glclear) uses to clear the color buffers. The default value is zero.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glClearColor** function specifies the red, green, blue, and alpha values used by [**glClear**](https://learn.microsoft.com/windows/win32/opengl/glclear) to clear the color buffers. Values specified by **glClearColor** are clamped to the range \[0,1\].

The following functions retrieve information related to the **glClearColor** function:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_ACCUM\_CLEAR\_VALUE

**glGet** with argument GL\_COLOR\_CLEAR\_VALUE

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

[**glClear**](https://learn.microsoft.com/windows/win32/opengl/glclear)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)


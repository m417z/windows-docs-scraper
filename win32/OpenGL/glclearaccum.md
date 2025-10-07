# glClearAccum function

The **glClearAccum** function specifies the clear values for the accumulation buffer.

## Parameters

*red*

The red value used when the accumulation buffer is cleared. The default value is zero.

*green*

The green value used when the accumulation buffer is cleared. The default value is zero.

*blue*

The blue value used when the accumulation buffer is cleared. The default value is zero.

*alpha*

The alpha value used when the accumulation buffer is cleared. The default value is zero.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glClearAccum** function specifies the red, green, blue, and alpha values used by [**glClear**](https://learn.microsoft.com/windows/win32/opengl/glclear) to clear the accumulation buffer.

Values specified by **glClearAccum** are clamped to the range \[1,1\].

The following function retrieves information related to **glClearAccum**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_ACCUM\_CLEAR\_VALUE

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


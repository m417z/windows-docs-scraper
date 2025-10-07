# glIndexdv function

The **glIndexdv** function sets the current color index.

## Parameters

*c*

A pointer to a one-element array that contains the new value for the current color index.

## Return value

This function does not return a value.

## Remarks

The **glIndexdv** function updates the current (single-valued) color index. It takes one argument: the new value for the current color index.

The current index is stored as a floating-point value. Integer values are converted directly to floating-point values, with no special mapping.

Index values outside the representable range of the color-index buffer are not clamped. However, before an index is dithered (if enabled) and written to the framebuffer, it is converted to fixed-point format. Any bits in the integer portion of the resulting fixed-point value that do not correspond to bits in the framebuffer are masked out.

The current index can be updated at any time. In particular, **glIndexdv** can be called between a call to [**glBegin**](https://learn.microsoft.com/windows/desktop/OpenGL/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).

The following function retrieves information related to **glIndexdv**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_CURRENT\_INDEX

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

[**glColor**](https://learn.microsoft.com/windows/win32/opengl/glcolor-functions)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)


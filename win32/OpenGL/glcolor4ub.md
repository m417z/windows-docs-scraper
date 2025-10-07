# glColor4ub function

Sets the current color.

## Parameters

*red*

The new red value for the current color.

*green*

The new green value for the current color.

*blue*

The new blue value for the current color.

*alpha*

The new alpha value for the current color.

## Return value

This function does not return a value.

## Remarks

The GL stores both a current single-valued color index and a current four-valued RGBA color. **glcolor** sets a new four-valued RGBA color. **glcolor** has two major variants: **glcolor3** and **glcolor4**. **glcolor3** variants specify new red, green, and blue values explicitly and set the current alpha value to 1.0 (full intensity) implicitly. **glcolor4** variants specify all four color components explicitly.

**glcolor3b**, **glcolor4b**, **glcolor3s**, **glcolor4s**, **glcolor3i**, and **glcolor4i** take three or four signed byte, short, or long integers as arguments. When v is appended to the name, the color commands can take a pointer to an array of such values.

Current color values are stored in floating-point format, with unspecified mantissa and exponent sizes. Unsigned integer color components, when specified, are linearly mapped to floating-point values such that the largest representable value maps to 1.0 (full intensity), and 0 maps to 0.0 (zero intensity). Signed integer color components, when specified, are linearly mapped to floating-point values such that the most positive representable value maps to 1.0, and the most negative representable value maps to -1.0. (Note that this mapping does not convert 0 precisely to 0.0.) Floating-point values are mapped directly.

Neither floating-point nor signed integer values are clamped to the range \[0,1\] before the current color is updated. However, color components are clamped to this range before they are interpolated or written into a color buffer.

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

[**glGetBooleanv, glGetDoublev, glGetFloatv, glGetIntegerv**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glIndex**](https://learn.microsoft.com/windows/win32/opengl/glindexd)


# glLineStipple function

The **glLineStipple** function specifies the line stipple pattern.

## Parameters

*factor*

A multiplier for each bit in the line stipple pattern. If *factor* is 3, for example, each bit in the pattern will be used three times before the next bit in the pattern is used. The *factor* parameter is clamped to the range \[1, 256\] and defaults to one.

*pattern*

A 16-bit integer whose bit pattern determines which fragments of a line will be drawn when the line is rasterized. Bit zero is used first, and the default pattern is all ones.

## Return value

This function does not return a value.

## Error codes

The following error code can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glLineStipple** function specifies the line stipple pattern. Line stippling masks out certain fragments produced by rasterization; those fragments will not be drawn. The masking is achieved by using three parameters: the 16-bit line stipple pattern *pattern*, the repeat count *factor*, and an integer stipple counter *s*.

Counter *s* is reset to zero whenever [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) is called, and before each line segment of a **glBegin**(GL\_LINES)/**glEnd** sequence is generated. It is incremented after each fragment of a unit width aliased line segment is generated, or after each *i* fragments of an *i* width line segment are generated. The *i* fragments associated with count *s* are masked out if *pattern* bit (*s* / *factor*) mod 16 is zero. Otherwise these fragments are sent to the framebuffer. Bit zero of *pattern* is the least significant bit.

Antialiased lines are treated as a sequence of 1x*width* rectangles for purposes of stippling. Rectangle *s* is rasterized or not based on the fragment rule described for aliased lines; it counts rectangles rather than groups of fragments.

Line stippling is enabled or disabled using [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and **glDisable** with argument GL\_LINE\_STIPPLE. When enabled, the line stipple pattern is applied as described above. When disabled, it is as if the pattern were all ones. Initially, line stippling is disabled.

The following functions retrieve information related to **glLineStipple**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_LINE\_STIPPLE\_PATTERN

**glGet** with argument GL\_LINE\_STIPPLE\_REPEAT

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_LINE\_STIPPLE

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

[**glLineWidth**](https://learn.microsoft.com/windows/win32/opengl/gllinewidth)

[**glPolygonStipple**](https://learn.microsoft.com/windows/win32/opengl/glpolygonstipple)


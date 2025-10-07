# glClear function

The **glClear** function clears buffers to preset values.

## Parameters

*mask*

Bitwise OR operators of masks that indicate the buffers to be cleared. The four masks are as follows.

| Value | Meaning |
|-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------|
|

**GL\_COLOR\_BUFFER\_BIT**

| The buffers currently enabled for color writing.<br> |
|

**GL\_DEPTH\_BUFFER\_BIT**

| The depth buffer.<br> |
|

**GL\_ACCUM\_BUFFER\_BIT**

| The accumulation buffer.<br> |
|

**GL\_STENCIL\_BUFFER\_BIT**

| The stencil buffer.<br> |

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_VALUE** | Any bit other than the four defined bits was set in *mask*.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glClear** function sets the bitplane area of the window to values previously selected by [**glClearColor**](https://learn.microsoft.com/windows/win32/opengl/glclearcolor), [**glClearIndex**](https://learn.microsoft.com/windows/win32/opengl/glclearindex), [**glClearDepth**](https://learn.microsoft.com/windows/win32/opengl/glcleardepth), [**glClearStencil**](https://learn.microsoft.com/windows/win32/opengl/glclearstencil), and [**glClearAccum**](https://learn.microsoft.com/windows/win32/opengl/glclearaccum). You can clear multiple color buffers simultaneously by selecting more than one buffer at a time using [**glDrawBuffer**](https://learn.microsoft.com/windows/win32/opengl/gldrawbuffer).

The pixel-ownership test, the scissor test, dithering, and the buffer writemasks affect the operation of **glClear**. The scissor box bounds the cleared region. The **glClear** function ignores the alpha function, blend function, logical operation, stenciling, texture mapping, and *z*-buffering.

The **glClear** function takes a single argument (*mask*) that is the bitwise OR of several values indicating which buffer is to be cleared.

The value to which each buffer is cleared depends on the setting of the clear value for that buffer.

If a buffer is not present, a **glClear** call directed at that buffer has no effect.

The following functions retrieve information related to **glClear**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_ACCUM\_CLEAR\_VALUE

**glGet** with argument GL\_DEPTH\_CLEAR\_VALUE

**glGet** with argument GL\_INDEX\_CLEAR\_VALUE

**glGet** with argument GL\_COLOR\_CLEAR\_VALUE

**glGet** with argument GL\_STENCIL\_CLEAR\_VALUE

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

## See also

[**glClearAccum**](https://learn.microsoft.com/windows/win32/opengl/glclearaccum)

[**glClearColor**](https://learn.microsoft.com/windows/win32/opengl/glclearcolor)

[**glClearDepth**](https://learn.microsoft.com/windows/win32/opengl/glcleardepth)

[**glClearIndex**](https://learn.microsoft.com/windows/win32/opengl/glclearindex)

[**glClearStencil**](https://learn.microsoft.com/windows/win32/opengl/glclearstencil)

[**glDrawBuffer**](https://learn.microsoft.com/windows/win32/opengl/gldrawbuffer)

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv)

[**glScissor**](https://learn.microsoft.com/windows/win32/opengl/glscissor)


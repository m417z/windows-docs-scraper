# glStencilFunc function

The **glStencilFunc** function sets the function and reference value for stencil testing.

## Parameters

*func*

The test function. The following eight tokens are valid.

| Value | Meaning |
|---------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------|
| **GL\_NEVER** | Always fails.<br> |
| **GL\_LESS** | Passes if (*ref* & *mask*) < (*stencil* & *mask*).<br> |
| **GL\_LEQUAL** | Passes if (*ref* & *mask*) = (*stencil* & *mask*).<br> |
| **GL\_GREATER** | Passes if (*ref* & *mask*) > (*stencil* & *mask*).<br> |
| **GL\_GEQUAL** | Passes if (*ref* & *mask*) = (*stencil* & *mask*).<br> |
| **GL\_EQUAL** | Passes if (*ref* & *mask*) = (*stencil* & *mask*).<br> |
| **GL\_NOTEQUAL** | Passes if (*ref* & *mask*) ? (*stencil* & *mask*).<br> |
| **GL\_ALWAYS** | Always passes.<br> |

*ref*

The reference value for the stencil test. The *ref* parameter is clamped to the range \[0, 2*n* 1\], where *n* is the number of bitplanes in the stencil buffer.

*mask*

A mask that is **AND**ed with both the reference value and the stored stencil value when the test is done.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *func* was not one of the eight accepted values.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

Stenciling, like *z*-buffering, enables and disables drawing on a per-pixel basis. You draw into the stencil planes using OpenGL drawing primitives, then render geometry and images, using the stencil planes to mask out portions of the screen. Stenciling is typically used in multipass rendering algorithms to achieve special effects, such as decals, outlining, and constructive solid geometry rendering.

The stencil test conditionally eliminates a pixel based on the outcome of a comparison between the reference value and the value in the stencil buffer. The test is enabled by [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and [**glDisable**](https://learn.microsoft.com/windows/win32/opengl/gldisable) with argument GL\_STENCIL\_TEST. Actions taken based on the outcome of the stencil test are specified with [**glStencilOp**](https://learn.microsoft.com/windows/win32/opengl/glstencilop).

The *func* parameter is a symbolic constant that determines the stencil comparison function. It accepts one of the eight values shown above. The *ref* parameter is an integer reference value that is used in the stencil comparison. It is clamped to the range \[0, 2*n* 1\], where *n* is the number of bitplanes in the stencil buffer. The *mask* parameter is bitwise **AND**ed with both the reference value and the stored stencil value, with the **AND**ed values participating in the comparison.

If *stencil* represents the value stored in the corresponding stencil buffer location, the preceding list shows the effect of each comparison function that can be specified by *func*. Only if the comparison succeeds is the pixel passed through to the next stage in the rasterization process (see [**glStencilOp**](https://learn.microsoft.com/windows/win32/opengl/glstencilop)). All tests treat *stencil* values as unsigned integers in the range \[0, 2*n* 1\], where *n* is the number of bitplanes in the stencil buffer.

Initially, the stencil test is disabled. If there is no stencil buffer, no stencil modification can occur and it is as if the stencil test always passes.

The following functions retrieve information related to **glStencilFunc**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_STENCIL\_FUNC

**glGet** with argument GL\_STENCIL\_VALUE\_MASK

**glGet** with argument GL\_STENCIL\_REF

**glGet** with argument GL\_STENCIL\_BITS

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_STENCIL\_TEST

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows 2000 Professional \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows 2000 Server \[desktop apps only\]<br> |
| Header<br> | Gl.h |
| Library<br> | Opengl32.lib |
| DLL<br> | Opengl32.dll |

## See also

[**glAlphaFunc**](https://learn.microsoft.com/windows/win32/opengl/glalphafunc)

[**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin)

[**glBlendFunc**](https://learn.microsoft.com/windows/win32/opengl/glblendfunc)

[**glDepthFunc**](https://learn.microsoft.com/windows/win32/opengl/gldepthfunc)

[**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

[**glLogicOp**](https://learn.microsoft.com/windows/win32/opengl/gllogicop)

[**glStencilOp**](https://learn.microsoft.com/windows/win32/opengl/glstencilop)


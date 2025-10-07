# glStencilOp function

The **glStencilOp** function sets the stencil test actions.

## Parameters

*fail*

The action to take when the stencil test fails. The following six symbolic constants are accepted.

| Value | Meaning |
|------------------------------------------------------------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------|
|

**GL\_KEEP**

| Keeps the current value.<br> |
|

**GL\_ZERO**

| Sets the stencil buffer value to zero.<br> |
|

**GL\_REPLACE**

| Sets the stencil buffer value to *ref*, as specified by **glStencilFunc**.<br> |
|

**GL\_INCR**

| Increments the current stencil buffer value. Clamps to the maximum representable unsigned value.<br> |
|

**GL\_DECR**

| Decrements the current stencil buffer value. Clamps to zero.<br> |
|

**GL\_INVERT**

| Bitwise inverts the current stencil buffer value.<br> |

*zfail*

Stencil action when the stencil test passes, but the depth test fails. Accepts the same symbolic constants as *fail.*

*zpass*

Stencil action when both the stencil test and the depth test pass, or when the stencil test passes and either there is no depth buffer or depth testing is not enabled. Accepts the same symbolic constants as *fail*.

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *fail*, *zfail*, or *zpass* was any value other than the six defined constant values.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

Stenciling, like *z*-buffering, enables and disables drawing on a per-pixel basis. You draw into the stencil planes using OpenGL drawing primitives, then render geometry and images, using the stencil planes to mask out portions of the screen. Stenciling is typically used in multipass rendering algorithms to achieve special effects, such as decals, outlining, and constructive solid geometry rendering.

The stencil test conditionally eliminates a pixel based on the outcome of a comparison between the value in the stencil buffer and a reference value. The test is enabled with [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and [**glDisable**](https://learn.microsoft.com/windows/win32/opengl/gldisable) calls with argument GL\_STENCIL\_TEST, and controlled with [**glStencilFunc**](https://learn.microsoft.com/windows/win32/opengl/glstencilfunc).

The **glStencilOp** function takes three arguments that indicate what happens to the stored stencil value while stenciling is enabled. If the stencil test fails, no change is made to the pixel's color or depth buffers, and *fail* specifies what happens to the stencil buffer contents.

Stencil buffer values are treated as unsigned integers. When incremented and decremented, values are clamped to 0 and 2*n* 1, where *n* is the value returned by querying GL\_STENCIL\_BITS.

The other two arguments to **glStencilOp** specify stencil buffer actions should subsequent depth buffer tests succeed (*zpass*) or fail (*zfail*). (See [**glDepthFunc**](https://learn.microsoft.com/windows/win32/opengl/gldepthfunc).) They are specified using the same six symbolic constants as *fail*. Note that *zfail* is ignored when there is no depth buffer, or when the depth buffer is not enabled. In these cases, *fail* and *zpass* specify stencil action when the stencil test fails and passes, respectively.

Initially the stencil test is disabled. If there is no stencil buffer, no stencil modification can occur and it is as if the stencil tests always pass, regardless of any call to **glStencilOp**.

The following functions retrieve information related to **glStencilOp**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_STENCIL\_FAIL

**glGet** with argument GL\_STENCIL\_PASS\_DEPTH\_PASS

**glGet** with argument GL\_STENCIL\_PASS\_DEPTH\_FAIL

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

[**glStencilFunc**](https://learn.microsoft.com/windows/win32/opengl/glstencilfunc)


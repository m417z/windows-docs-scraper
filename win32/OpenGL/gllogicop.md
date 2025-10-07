# glLogicOp function

The **glLogicOp** function specifies a logical pixel operation for color index rendering.

## Parameters

*opcode*

A symbolic constant that selects a logical operation. The following symbols are accepted where s equals the value of the source bit and d is the value of the destination bit.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------|----------------------|
|

**GL\_CLEAR**

| 0<br> |
|

**GL\_SET**

| 1<br> |
|

**GL\_COPY**

| s<br> |
|

**GL\_COPY\_INVERTED**

| !s<br> |
|

**GL\_NOOP**

| d<br> |
|

**GL\_INVERT**

| !d<br> |
|

**GL\_AND**

| s & d<br> |
|

**GL\_NAND**

| !(s & d)<br> |
|

**GL\_OR**

| s \| d<br> |
|

**GL\_NOR**

| !(s \| d)<br> |
|

**GL\_XOR**

| s ^ d<br> |
|

**GL\_EQUIV**

| !(s ^ d)<br> |
|

**GL\_AND\_REVERSE**

| s & !d<br> |
|

**GL\_AND\_INVERTED**

| !s & d<br> |
|

**GL\_OR\_REVERSE**

| s \| !d<br> |
|

**GL\_OR\_INVERTED**

| !s \| d<br> |

## Return value

This function does not return a value.

## Error codes

The following error codes can be retrieved by the [**glGetError**](https://learn.microsoft.com/windows/win32/opengl/glgeterror) function.

| Name | Meaning |
|-------------------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------------------------------------------|
| **GL\_INVALID\_ENUM** | *opcode* was not an accepted value.<br> |
| **GL\_INVALID\_OPERATION** | The function was called between a call to [**glBegin**](https://learn.microsoft.com/windows/win32/opengl/glbegin) and the corresponding call to [**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend).<br> |

## Remarks

The **glLogicOp** function specifies a logical operation that, when enabled, is applied between the incoming color index and the color index at the corresponding location in the framebuffer. The logical operation is enabled or disabled with [**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable) and **glDisable** using the symbolic constant GL\_LOGIC\_OP.

The *opcode* parameter is a symbolic constant chosen from the list below. In the explanation of the logical operations, *s* represents the incoming color index and *d* represents the index in the framebuffer. Standard C-language operators are used. As these bitwise operators suggest, the logical operation is applied independently to each bit pair of the source and destination indexes.

Logical pixel operations are not applied to RGBA color buffers.

When more than one color-index buffer is enabled for drawing, logical operations are done separately for each enabled buffer, using the contents of that buffer for the destination index (see [**glDrawBuffer**](https://learn.microsoft.com/windows/win32/opengl/gldrawbuffer)).

The *opcode* parameter must be one of the 16 accepted values. Other values result in an error.

The following functions retrieve information related to **glLogicOp**:

[**glGet**](https://learn.microsoft.com/windows/win32/opengl/glgetbooleanv--glgetdoublev--glgetfloatv--glgetintegerv) with argument GL\_LOGIC\_OP\_MODE

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled) with argument GL\_LOGIC\_OP

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

[**glDrawBuffer**](https://learn.microsoft.com/windows/win32/opengl/gldrawbuffer)

[**glEnable**](https://learn.microsoft.com/windows/win32/opengl/glenable)

[**glEnd**](https://learn.microsoft.com/windows/win32/opengl/glend)

[**glIsEnabled**](https://learn.microsoft.com/windows/win32/opengl/glisenabled)

[**glStencilOp**](https://learn.microsoft.com/windows/win32/opengl/glstencilop)


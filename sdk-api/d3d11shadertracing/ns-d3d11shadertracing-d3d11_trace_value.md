# D3D11_TRACE_VALUE structure

## Description

Describes a trace value.

## Members

### `Bits`

An array of bits that make up the trace value. The [0] element is X.

**Note** This member can hold **float**, **UINT**, or **INT** data.
The elements are specified as **UINT** rather than using a union to minimize the risk of x86 SNaN->QNaN quashing during float assignment.
If the bits are displayed, they can be interpreted as **float** at the last moment.

### `ValidMask`

A combination of the following component values that are combined by using a bitwise **OR** operation.
The resulting value specifies the component trace mask.

| Flag | Description |
| --- | --- |
| D3D11_TRACE_COMPONENT_X (0x1) | The x component of the trace mask. |
| D3D11_TRACE_COMPONENT_Y (0x2) | The y component of the trace mask. |
| D3D11_TRACE_COMPONENT_Z (0x4) | The depth z component of the trace mask. |
| D3D11_TRACE_COMPONENT_W (0x8) | The depth w component of the trace mask. |

Ignore unmasked values, particularly if deltas are accumulated.

## Remarks

This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-structures)
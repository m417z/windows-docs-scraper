# D3D11_TRACE_REGISTER structure

## Description

Describes a trace register.

## Members

### `RegType`

A [D3D11_TRACE_REGISTER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d11shadertracing/ne-d3d11shadertracing-d3d11_trace_register_type)-typed value that identifies the type of register that the shader-trace object uses.

### `Index1D`

An index for one-dimensional arrays. This index is used by the following register types:

* vertex shader or pixel shader input: v[Index1D]
* temp: r[Index1D]
* output: o[Index1D]
* immediate constant buffer: icb[Index1D]
* sampler s[Index1D]
* resource r[Index1D]
* input patch constant register: vpc[Index1D]
* unordered access view: u[Index1D]
* thread group shared memory: g[Index1D]

### `Index2D`

An array of indexes for two-dimensional arrays. These indexes are used by the following register types:

* GS input: v[Index2D[0]][Index2D[1]]
* indexable temp: x[Index2D[0]][Index2D[1]]
* constant buffer: cb#[#]
* input control point register: vcp[Index2D[0]][Index2D[1]]
* output control point register: vocp[Index2D[0]][Index2D[1]]

### `OperandIndex`

The index of the operand, which starts from 0.

### `Flags`

A combination of the following flags that are combined by using a bitwise **OR** operation. The resulting value specifies more about the trace register.

| Flag | Description |
| --- | --- |
| D3D11_TRACE_REGISTER_FLAGS_RELATIVE_INDEXING (0x1) | Access to the register is part of the relative indexing of a register. |

## Remarks

The following register types do not require an index:

* input PrimitiveID
* output oDepth
* immediate32
* NULL register
* output control point ID (this is actually an input; it defines the output that the thread controls)
* input fork instance ID
* input join instance ID
* input domain point register
* cycle counter

**Note** This API requires the Windows Software Development Kit (SDK) for Windows 8.

## See also

[Shader Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-shader-structures)
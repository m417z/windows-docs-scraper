# D3D11_INPUT_ELEMENT_DESC structure

## Description

A description of a single element for the input-assembler stage.

## Members

### `SemanticName`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The HLSL semantic associated with this element in a shader input-signature. See [HLSL Semantics](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-semantics) for more info.

### `SemanticIndex`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The semantic index for the element. A semantic index modifies a semantic, with an integer index number. A semantic index is only needed in a
case where there is more than one element with the same semantic. For example, a 4x4 matrix would have four components each with the semantic
name

```
matrix
```

, however each of the four component would have different semantic indices (0, 1, 2, and 3).

### `Format`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

The data type of the element data. See [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format).

### `InputSlot`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An integer value that identifies the input-assembler (see input slot). Valid values are between 0 and 15, defined in D3D11.h.

### `AlignedByteOffset`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Optional. Offset (in bytes) from the start of the vertex. Use D3D11_APPEND_ALIGNED_ELEMENT for convenience to define the current element directly
after the previous one, including any packing if necessary.

### `InputSlotClass`

Type: **[D3D11_INPUT_CLASSIFICATION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_input_classification)**

Identifies the input data class for a single input slot (see [D3D11_INPUT_CLASSIFICATION](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_input_classification)).

### `InstanceDataStepRate`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of instances to draw using the same per-instance data before advancing in the buffer by one element. This value must be 0 for an
element that contains per-vertex data (the slot class is set to D3D11_INPUT_PER_VERTEX_DATA).

## Remarks

An input-layout object contains an array of structures, each structure defines one element being read from an input slot. Create an input-layout
object by calling [ID3D11Device::CreateInputLayout](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createinputlayout). For an example, see the "Create the Input-Layout Object" subtopic under the [Getting Started with the Input-Assembler Stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage-getting-started) topic.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-d3d11-core-structures)
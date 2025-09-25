# D3D10_INPUT_ELEMENT_DESC structure

## Description

A description of a single element for the [input-assembler stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage).

## Members

### `SemanticName`

Type: **[LPCSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The [HLSL semantic](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-semantics) associated with this element in a [shader input-signature](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-signatures).

### `SemanticIndex`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The semantic index for the element. A semantic index modifies a semantic, with an integer index number. A semantic index is only needed in a case where there is more than one element with the same semantic. For example, a 4x4 matrix would have four components each with the semantic name **matrix**, however each of the four component would have different semantic indices (0, 1, 2, and 3).

### `Format`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

The data type of the element data. See [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format).

### `InputSlot`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

An integer value that identifies the input-assembler (see [input slot](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage-getting-started)). Valid values are between 0 and 15, defined in D3D10.h.

### `AlignedByteOffset`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Optional. Offset (in bytes) between each element. Use D3D10_APPEND_ALIGNED_ELEMENT for convenience to define the current element directly after the previous one, including any packing if necessary.

### `InputSlotClass`

Type: **[D3D10_INPUT_CLASSIFICATION](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_input_classification)**

Identifies the input data class for a single input slot (see [D3D10_INPUT_CLASSIFICATION](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_input_classification)).

### `InstanceDataStepRate`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of instances to draw before stepping one unit forward in a vertex buffer filled with instance data. Can be any unsigned integer value (0 means do not step) when the slot class is D3D10_INPUT_PER_INSTANCE_DATA; must be 0 when the slot class is D3D10_INPUT_PER_VERTEX_DATA.

## Remarks

An input-layout object contains an array of structures, each structure defines one element being read from an input slot. Create an input-layout object by calling [ID3D10Device::CreateInputLayout](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createinputlayout). For an example, see [Create an input-layout object](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage-getting-started).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-d3d10-core-structures)
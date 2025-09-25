# D3D12_INPUT_ELEMENT_DESC structure

## Description

Describes a single element for the input-assembler stage of the graphics pipeline.

## Members

### `SemanticName`

The HLSL semantic associated with this element in a shader input-signature. See [HLSL Semantics](https://learn.microsoft.com/windows/win32/direct3dhlsl/dx-graphics-hlsl-semantics) for more info.

### `SemanticIndex`

The semantic index for the element. A semantic index modifies a semantic, with an integer index number. A semantic index is only needed in a
case where there is more than one element with the same semantic. For example, a 4x4 matrix would have four components each with the semantic
name **matrix**, however each of the four component would have different semantic indices (0, 1, 2, and 3).

### `Format`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value that specifies the format of the element data.

### `InputSlot`

An integer value that identifies the input-assembler. For more info, see [Input Slots](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage-getting-started). Valid values are between 0 and 15.

### `AlignedByteOffset`

Optional. Offset, in bytes, to this element from the start of the vertex. Use D3D12_APPEND_ALIGNED_ELEMENT (0xffffffff) for convenience to define the current element directly
after the previous one, including any packing if necessary.

### `InputSlotClass`

A value that identifies the input data class for a single input slot.

### `InstanceDataStepRate`

The number of instances to draw using the same per-instance data before advancing in the buffer by one element. This value must be 0 for an
element that contains per-vertex data (the slot class is set to the D3D12_INPUT_PER_VERTEX_DATA member of [D3D12_INPUT_CLASSIFICATION](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_input_classification)).

## Remarks

This structure is a member of the [D3D12_INPUT_LAYOUT_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_input_layout_desc) structure. A pipeline state object contains a input-layout structure that defines one element being read from an input slot.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)
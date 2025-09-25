# D2D1_INPUT_ELEMENT_DESC structure

## Description

A description of a single element to the vertex layout.

## Members

### `semanticName`

The [HLSL semantic](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-semantics) associated with this element in a [shader input-signature](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-signatures).

### `semanticIndex`

The semantic index for the element. A semantic index modifies a semantic, with an integer index number. A semantic index is only needed in a case where there is more than one element with the same semantic. For example, a 4x4 matrix would have four components each with the semantic name matrix; however, each of the four components would have different semantic indices (0, 1, 2, and 3).

### `format`

The data type of the element data.

### `inputSlot`

An integer value that identifies the input-assembler. Valid values are between 0 and 15.

### `alignedByteOffset`

The offset in bytes between each element.

## Remarks

This structure is a subset of [D3D11_INPUT_ELEMENT_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_input_element_desc) that omits fields required to define a vertex layout.

If the [D2D1_APPEND_ALIGNED_ELEMENT](https://learn.microsoft.com/windows/desktop/Direct2D/direct2d-constants) constant is used for **alignedByteOffset**, the elements will be packed contiguously for convenience.

## See also

[D2D1_VERTEX_USAGE](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/ne-d2d1effectauthor-d2d1_vertex_usage)

[Getting Started with the Input-Assembler Stage](https://learn.microsoft.com/windows/desktop/direct3d11/d3d10-graphics-programming-guide-input-assembler-stage-getting-started)

[ID2D1EffectContext::CreateVertexBuffer](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-createvertexbuffer)

[ID2D1EffectContext::LoadVertexShader](https://learn.microsoft.com/windows/desktop/api/d2d1effectauthor/nf-d2d1effectauthor-id2d1effectcontext-loadvertexshader)

[Semantics](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-semantics)

[Signatures](https://learn.microsoft.com/windows/desktop/direct3dhlsl/dx-graphics-hlsl-signatures)
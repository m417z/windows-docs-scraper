# D3D12_INDIRECT_ARGUMENT_DESC structure

## Description

Describes an indirect argument (an indirect parameter), for use with a command signature.

## Members

### `Type`

A single [D3D12_INDIRECT_ARGUMENT_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_indirect_argument_type) enumeration constant.

### `VertexBuffer`

### `VertexBuffer.Slot`

Specifies the slot containing the vertex buffer address.

### `Constant`

### `Constant.RootParameterIndex`

Specifies the root index of the constant.

### `Constant.DestOffsetIn32BitValues`

The offset, in 32-bit values, to set the first constant of the group.
Supports multi-value constants at a given root index.
Root constant entries must be sorted from smallest to largest DestOffsetIn32BitValues.

### `Constant.Num32BitValuesToSet`

The number of 32-bit constants that are set at the given root index.
Supports multi-value constants at a given root index.

### `ConstantBufferView`

### `ConstantBufferView.RootParameterIndex`

Specifies the root index of the CBV.

### `ShaderResourceView`

### `ShaderResourceView.RootParameterIndex`

Specifies the root index of the SRV.

### `UnorderedAccessView`

### `UnorderedAccessView.RootParameterIndex`

Specifies the root index of the UAV.

## Remarks

Use this structure with the [D3D12_COMMAND_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_command_signature_desc) structure.

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[Example Root Signatures](https://learn.microsoft.com/windows/desktop/direct3d12/example-root-signatures)
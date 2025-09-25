# D3D12DDI_INDIRECT_ARGUMENT_DESC structure

## Description

The **D3D12DDI_INDIRECT_ARGUMENT_DESC** structure describes an indirect argument (an indirect parameter), for use with a command signature.

## Members

### `Type`

A [**D3D12DDI_INDIRECT_ARGUMENT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_indirect_argument_type) enumeration value that specifies the type of indirect argument. This value determines which member of the union is used.

### `VertexBuffer`

### `VertexBuffer.Slot`

Specifies the slot containing the vertex buffer address.

### `Constant`

### `Constant.RootParameterIndex`

Specifies the root index of the constant.

### `Constant.DestOffsetIn32BitValues`

The offset, in 32-bit values, to set the first constant of the group. Supports multi-value constants at a given root index. Root constant entries must be sorted from smallest to largest **DestOffsetIn32BitValues**.

### `Constant.Num32BitValuesToSet`

The number of 32-bit constants that are set at the given root index. Supports multi-value constants at a given root index.

### `ConstantBufferView`

### `ConstantBufferView.RootParameterIndex`

Specifies the root index of the CBV.

### `ShaderResourceView`

### `ShaderResourceView.RootParameterIndex`

Specifies the root index of the SRV.

### `UnorderedAccessView`

### `UnorderedAccessView.RootParameterIndex`

Specifies the root index of the UAV.

### `IncrementingConstant`

### `IncrementingConstant.RootParameterIndex`

The index within the root signature that identifies the root constant to be updated.

### `IncrementingConstant.DestOffsetIn32BitValues`

This field specifies the offset, in terms of 32-bit values (not bytes), within the root constant's memory where the incremented value will be written. It defines the position within the root constant at which the incrementing constant will start. If the root constant is an array of multiple 32-bit values, this offset indicates which element of the array will receive the first incremented value.

## Remarks

Indirect arguments are used in conjunction with command signatures to specify the type and structure of data that the GPU will read from a buffer to execute a command, without the CPU needing to be involved in each individual draw or dispatch call.

Use this structure with the [**D3D12DDIARG_CREATE_COMMAND_SIGNATURE_0001**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_command_signature_0001) structure.

See the [Mesh Shader Specification](https://microsoft.github.io/DirectX-Specs/d3d/MeshShader.html) for more information.

## See also

[**D3D12DDI_INDIRECT_ARGUMENT_TYPE**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ne-d3d12umddi-d3d12ddi_indirect_argument_type)

[**D3D12DDIARG_CREATE_COMMAND_SIGNATURE_0001**](https://learn.microsoft.com/windows-hardware/drivers/ddi/d3d12umddi/ns-d3d12umddi-d3d12ddiarg_create_command_signature_0001)
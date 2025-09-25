# D3D12_ROOT_PARAMETER structure

## Description

Describes the slot of a root signature version 1.0.

## Members

### `ParameterType`

A [D3D12_ROOT_PARAMETER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_root_parameter_type)-typed value that specifies the type of root signature slot. This member determines which type to use in the union below.

### `DescriptorTable`

A [D3D12_ROOT_DESCRIPTOR_TABLE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor_table) structure that describes the layout of a descriptor table as a collection of descriptor ranges that appear one after the other in a descriptor heap.

### `Constants`

A [D3D12_ROOT_CONSTANTS](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_constants) structure that describes constants inline in the root signature that appear in shaders as one constant buffer.

### `Descriptor`

A [D3D12_ROOT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor) structure that describes descriptors inline in the root signature that appear in shaders.

### `ShaderVisibility`

A [D3D12_SHADER_VISIBILITY](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_shader_visibility)-typed value that specifies the shaders that can access the contents of the root signature slot.

## Remarks

A [D3D12_ROOT_SIGNATURE_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_signature_desc) can contain descriptor tables and inline constants. More capable hardware could support inline descriptors in the root signature as well. The number of bind slots in the root signature are most efficient if kept below a certain size, and can have an upper bound as well.

## See also

[CD3DX12_ROOT_PARAMETER](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-root-parameter)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[Creating a Root Signature](https://learn.microsoft.com/windows/desktop/direct3d12/creating-a-root-signature)

[D3D12_ROOT_PARAMETER1](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter1)
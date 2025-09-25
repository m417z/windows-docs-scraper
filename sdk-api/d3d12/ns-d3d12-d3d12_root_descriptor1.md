# D3D12_ROOT_DESCRIPTOR1 structure

## Description

Describes descriptors inline in the root signature version 1.1 that appear in shaders.

## Members

### `ShaderRegister`

The shader register.

### `RegisterSpace`

The register space.

### `Flags`

Specifies the [D3D12_ROOT_DESCRIPTOR_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_root_descriptor_flags) that determine the volatility of descriptors and the data they reference.

## Remarks

**D3D12_ROOT_DESCRIPTOR1** is the data type of the **Descriptor** member of [D3D12_ROOT_PARAMETER1](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter1).
Use a **D3D12_ROOT_DESCRIPTOR1** when you set **D3D12_ROOT_PARAMETER1**'s **ParameterType** field to the D3D12_ROOT_PARAMETER_TYPE_CBV, D3D12_ROOT_PARAMETER_TYPE_SRV, or D3D12_ROOT_PARAMETER_TYPE_UAV members of [D3D12_ROOT_PARAMETER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_root_parameter_type).

Refer to the helper structure [CD3DX12_ROOT_DESCRIPTOR1](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-root-descriptor1).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_ROOT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor)

[Root Signature Version 1.1](https://learn.microsoft.com/windows/desktop/direct3d12/root-signature-version-1-1)
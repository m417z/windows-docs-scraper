# D3D12_ROOT_DESCRIPTOR structure

## Description

Describes descriptors inline in the root signature version 1.0 that appear in shaders.

## Members

### `ShaderRegister`

The shader register.

### `RegisterSpace`

The register space.

## Remarks

**D3D12_ROOT_DESCRIPTOR** is the data type of the **Descriptor** member of [D3D12_ROOT_PARAMETER](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter).
Use a **D3D12_ROOT_DESCRIPTOR** when you set **D3D12_ROOT_PARAMETER**'s **ParameterType** field to the D3D12_ROOT_PARAMETER_TYPE_CBV, D3D12_ROOT_PARAMETER_TYPE_SRV, or D3D12_ROOT_PARAMETER_TYPE_UAV members of [D3D12_ROOT_PARAMETER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_root_parameter_type).

## See also

[CD3DX12_ROOT_DESCRIPTOR](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-root-descriptor)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[D3D12_ROOT_DESCRIPTOR1](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_descriptor1)

[Using descriptors directly in the root signature](https://learn.microsoft.com/windows/desktop/direct3d12/using-descriptors-directly-in-the-root-signature)
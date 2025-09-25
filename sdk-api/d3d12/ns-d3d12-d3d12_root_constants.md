# D3D12_ROOT_CONSTANTS structure

## Description

Describes constants inline in the root signature that appear in shaders as one constant buffer.

## Members

### `ShaderRegister`

The shader register.

### `RegisterSpace`

The register space.

### `Num32BitValues`

The number of constants that occupy a single shader slot (these constants appear like a single constant buffer).
All constants occupy a single root signature bind slot.

## Remarks

Refer to [Resource Binding in HLSL](https://learn.microsoft.com/windows/desktop/direct3d12/resource-binding-in-hlsl) for more information on shader registers and spaces.

**D3D12_ROOT_CONSTANTS** is the data type of the **Constants** member of [D3D12_ROOT_PARAMETER](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter).
Use a **D3D12_ROOT_CONSTANTS** when you set **D3D12_ROOT_PARAMETER**'s **SlotType** field to the D3D12_ROOT_PARAMETER_TYPE_32BIT_CONSTANTS member of [D3D12_ROOT_PARAMETER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_root_parameter_type).

## See also

[CD3DX12_ROOT_CONSTANTS](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-root-constants)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)

[Creating a Root Signature](https://learn.microsoft.com/windows/desktop/direct3d12/creating-a-root-signature)

[Using constants directly in the root signature](https://learn.microsoft.com/windows/desktop/direct3d12/using-constants-directly-in-the-root-signature)
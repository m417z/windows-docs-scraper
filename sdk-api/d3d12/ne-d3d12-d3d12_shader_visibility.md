# D3D12_SHADER_VISIBILITY enumeration

## Description

Specifies the shaders that can access the contents of a given root signature slot.

## Constants

### `D3D12_SHADER_VISIBILITY_ALL:0`

Specifies that all shader stages can access whatever is bound at the root signature slot.

### `D3D12_SHADER_VISIBILITY_VERTEX:1`

Specifies that the vertex shader stage can access whatever is bound at the root signature slot.

### `D3D12_SHADER_VISIBILITY_HULL:2`

Specifies that the hull shader stage can access whatever is bound at the root signature slot.

### `D3D12_SHADER_VISIBILITY_DOMAIN:3`

Specifies that the domain shader stage can access whatever is bound at the root signature slot.

### `D3D12_SHADER_VISIBILITY_GEOMETRY:4`

Specifies that the geometry shader stage can access whatever is bound at the root signature slot.

### `D3D12_SHADER_VISIBILITY_PIXEL:5`

Specifies that the pixel shader stage can access whatever is bound at the root signature slot.

### `D3D12_SHADER_VISIBILITY_AMPLIFICATION:6`

Specifies that the amplification shader stage can access whatever is bound at the root signature slot.

### `D3D12_SHADER_VISIBILITY_MESH:7`

Specifies that the mesh shader stage can access whatever is bound at the root signature slot.

## Remarks

This enum is used by the [D3D12_ROOT_PARAMETER](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_root_parameter) structure.

The compute queue always uses **D3D12_SHADER_VISIBILITY_ALL** because it has only one active stage. The 3D queue can choose values, but if it uses **D3D12_SHADER_VISIBILITY_ALL**, all shader stages can access whatever is bound at the root signature slot.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)
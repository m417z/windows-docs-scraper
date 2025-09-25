# D3D12_SHADER_VERSION_TYPE enumeration

## Description

Enumerates the types of shaders that Direct3D recognizes.
Used to encode the **Version** member of the [D3D12_SHADER_DESC](https://learn.microsoft.com/windows/desktop/api/d3d12shader/ns-d3d12shader-d3d12_shader_desc) structure.

## Constants

### `D3D12_SHVER_PIXEL_SHADER:0`

Pixel shader.

### `D3D12_SHVER_VERTEX_SHADER:1`

Vertex shader.

### `D3D12_SHVER_GEOMETRY_SHADER:2`

Geometry shader.

### `D3D12_SHVER_HULL_SHADER:3`

Hull shader.

### `D3D12_SHVER_DOMAIN_SHADER:4`

Domain shader.

### `D3D12_SHVER_COMPUTE_SHADER:5`

Compute shader.

### `D3D12_SHVER_RESERVED0:0xFFF0`

Indicates the end of the enumeration.

## See also

[Shader Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-shader-enums)
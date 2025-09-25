# D3D12DDI_SHADER_VISIBILITY enumeration

## Description

**D3D12DDI_SHADER_VISIBILITY** identifies the shaders that can access the contents of a given root signature slot.

## Constants

### `D3D12DDI_SHADER_VISIBILITY_ALL:0`

All shader stages can access whatever is bound at the root signature slot.

### `D3D12DDI_SHADER_VISIBILITY_VERTEX:1`

The vertex shader stage can access whatever is bound at the root signature slot.

### `D3D12DDI_SHADER_VISIBILITY_HULL:2`

The hull shader stage can access whatever is bound at the root signature slot.

### `D3D12DDI_SHADER_VISIBILITY_DOMAIN:3`

The domain shader stage can access whatever is bound at the root signature slot.

### `D3D12DDI_SHADER_VISIBILITY_GEOMETRY:4`

The geometry shader stage can access whatever is bound at the root signature slot.

### `D3D12DDI_SHADER_VISIBILITY_PIXEL:5`

The pixel shader stage can access whatever is bound at the root signature slot.

### `D3D12DDI_SHADER_VISIBILITY_AMPLIFICATION:6`

The amplification shader stage can access whatever is bound at the root signature slot.

### `D3D12DDI_SHADER_VISIBILITY_MESH:7`

The mesh shader stage can access whatever is bound at the root signature slot.

## Remarks

See the [DirectX Raytracing (DXR) functional specification](https://microsoft.github.io/DirectX-Specs/d3d/Raytracing.html) for more information.
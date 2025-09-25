# D3D10_MAP_FLAG enumeration

## Description

Specifies how the CPU should respond when Map is called on a resource being used by the GPU.

## Constants

### `D3D10_MAP_FLAG_DO_NOT_WAIT:0x100000L`

Specifies that Map should return **DXGI_ERROR_WAS_STILL_DRAWING** when the GPU blocks the CPU from accessing a resource.

## Remarks

This enumeration is used by [ID3D10Buffer::Map](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10buffer-map), [ID3D10Texture1D::Map](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10texture1d-map), [ID3D10Texture2D::Map](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10texture2d-map), and [ID3D10Texture3D::Map](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10texture3d-map).

D3D10_MAP_FLAG_DO_NOT_WAIT cannot be used with [D3D10_MAP_WRITE_DISCARD](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_map) or [D3D10_MAP_WRITE_NOOVERWRITE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_map).

For more information about potential conflicts between the GPU and CPU during resource mapping, see [Copying and Accessing Resource Data (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-mapping).

## See also

[Resource Enumerations](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-enums)
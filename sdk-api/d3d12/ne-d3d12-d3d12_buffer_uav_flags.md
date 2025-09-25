# D3D12_BUFFER_UAV_FLAGS enumeration

## Description

Identifies unordered-access view options for a buffer resource.

## Constants

### `D3D12_BUFFER_UAV_FLAG_NONE:0`

Indicates a default view.

### `D3D12_BUFFER_UAV_FLAG_RAW:0x1`

Resource contains raw, unstructured data. Requires the UAV format to be [DXGI_FORMAT_R32_TYPELESS](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format).
For more info about raw viewing of buffers, see [Raw Views of Buffers](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-resources-intro).

## Remarks

This enum is used in the [D3D12_BUFFER_UAV](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_buffer_uav) structure.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)
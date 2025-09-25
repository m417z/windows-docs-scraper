# D3D12_SUBRESOURCE_FOOTPRINT structure

## Description

Describes the format, width, height, depth, and row-pitch of the subresource into the parent resource.

## Members

### `Format`

A [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)-typed value that specifies the viewing format.

### `Width`

The width of the subresource.

### `Height`

The height of the subresource.

### `Depth`

The depth of the subresource.

### `RowPitch`

The row pitch, or width, or physical size, in bytes, of the subresource data.
This must be a multiple of D3D12_TEXTURE_DATA_PITCH_ALIGNMENT (256), and must be greater than or equal to the size of the data within a row.

## Remarks

Use this structure in the [D3D12_PLACED_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_placed_subresource_footprint) structure.

The helper structure is [CD3DX12_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-subresource-footprint).

## See also

[CD3DX12_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-subresource-footprint)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)
# D3D12_PLACED_SUBRESOURCE_FOOTPRINT structure

## Description

Describes the footprint of a placed subresource, including the offset and the D3D12_SUBRESOURCE_FOOTPRINT.

## Members

### `Offset`

The offset of the subresource within the parent resource, in bytes.
The offset between the start of the parent resource and this subresource.

### `Footprint`

The format, width, height, depth, and row-pitch of the subresource,
as a [D3D12_SUBRESOURCE_FOOTPRINT](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_subresource_footprint) structure.

## Remarks

This structure is used in the [D3D12_TEXTURE_COPY_LOCATION](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_texture_copy_location) structure,
and by [ID3D12Device::GetCopyableFootprints](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-getcopyablefootprints).

All the data referenced by the footprint structure must fit within the bounds of the parent resource. If you use [GetCopyableFootprints](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-getcopyablefootprints) to fill out the structure, the *pTotalBytes* output field indicates the required size of the resource.

This structure is also used a number of helper functions (refer to [Helper Structures and Functions for D3D12](https://learn.microsoft.com/windows/desktop/direct3d12/helper-structures-and-functions-for-d3d12)).

When copying textures, use this structure along with [D3D12_TEXTURE_COPY_LOCATION](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_texture_copy_location).

## See also

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)
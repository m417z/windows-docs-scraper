# D3D12_TILED_RESOURCE_COORDINATE structure

## Description

Describes the coordinates of a tiled resource.

## Members

### `X`

The x-coordinate of the tiled resource.

### `Y`

The y-coordinate of the tiled resource.

### `Z`

The z-coordinate of the tiled resource.

### `Subresource`

The index of the subresource for the tiled resource.

For mipmaps that use nonstandard tiling, or are packed, or both use nonstandard tiling and are packed, any subresource value that indicates any of the packed mipmaps all refer to the same tile. Additionally, the X coordinate is used to indicate a tile within the packed mip region, rather than a logical region of a single subresource. The Y and Z coordinates must be zero.

## Remarks

This structure is used by the [CopyTiles](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12graphicscommandlist-copytiles), [CopyTileMappings](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12commandqueue-copytilemappings) and [UpdateTileMappings](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12commandqueue-updatetilemappings) methods.

## See also

[CD3DX12_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-tiled-resource-coordinate)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)
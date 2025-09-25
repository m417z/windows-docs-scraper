# D3D12_SUBRESOURCE_TILING structure

## Description

Describes a tiled subresource volume.

## Members

### `WidthInTiles`

The width in tiles of the subresource.

### `HeightInTiles`

The height in tiles of the subresource.

### `DepthInTiles`

The depth in tiles of the subresource.

### `StartTileIndexInOverallResource`

The index of the tile in the overall tiled subresource to start with.

## Remarks

This structure is used by the [GetResourceTiling](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-getresourcetiling) method.

## See also

[CD3DX12_SUBRESOURCE_TILING](https://learn.microsoft.com/windows/desktop/direct3d12/cd3dx12-subresource-tiling)

[Core Structures](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-structures)
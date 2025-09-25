# D3D11_SUBRESOURCE_TILING structure

## Description

Describes a tiled subresource volume.

## Members

### `WidthInTiles`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The width in tiles of the subresource.

### `HeightInTiles`

Type: **[UINT16](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The height in tiles of the subresource.

### `DepthInTiles`

Type: **[UINT16](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The depth in tiles of the subresource.

### `StartTileIndexInOverallResource`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The index of the tile in the overall tiled subresource to start with.

[GetResourceTiling](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nf-d3d11_2-id3d11device2-getresourcetiling) sets **StartTileIndexInOverallResource** to **D3D11_PACKED_TILE** (0xffffffff) to indicate that the whole
**D3D11_SUBRESOURCE_TILING** structure is meaningless, and the info to which the *pPackedMipDesc* parameter of **GetResourceTiling** points applies. For packed tiles, the description of the packed mipmaps comes from a [D3D11_PACKED_MIP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_packed_mip_desc) structure instead.

## Remarks

Each packed mipmap is individually reported as 0 for **WidthInTiles**, **HeightInTiles** and **DepthInTiles**.

The total number of tiles in subresources is **WidthInTiles*****HeightInTiles*****DepthInTiles**.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)
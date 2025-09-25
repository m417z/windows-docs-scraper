# ID3D11Device2::GetResourceTiling

## Description

Gets info about how a tiled resource is broken into tiles.

## Parameters

### `pTiledResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

A pointer to the tiled resource to get info about.

### `pNumTilesForEntireResource` [out, optional]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a variable that receives the number of tiles needed to store the entire tiled resource.

### `pPackedMipDesc` [out, optional]

Type: **[D3D11_PACKED_MIP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_packed_mip_desc)***

A pointer to a [D3D11_PACKED_MIP_DESC](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_packed_mip_desc) structure that **GetResourceTiling** fills with info about how the tiled resource's mipmaps are packed.

### `pStandardTileShapeForNonPackedMips` [out, optional]

Type: **[D3D11_TILE_SHAPE](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_tile_shape)***

A pointer to a [D3D11_TILE_SHAPE](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_tile_shape) structure that **GetResourceTiling** fills with info about the tile shape. This is info about how pixels fit in the tiles, independent of tiled resource's dimensions,
not including packed mipmaps. If the entire tiled resource is packed, this parameter is meaningless because the tiled resource has no defined layout
for packed mipmaps.
In this situation, **GetResourceTiling** sets the members of **D3D11_TILE_SHAPE** to zeros.

### `pNumSubresourceTilings` [in, out, optional]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a variable that contains the number of tiles in the subresource. On input, this is the number of subresources to query tilings for; on output, this is the number that was actually retrieved at *pSubresourceTilingsForNonPackedMips* (clamped to what's available).

### `FirstSubresourceTilingToGet` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of the first subresource tile to get. **GetResourceTiling** ignores this parameter if the number that *pNumSubresourceTilings* points to is 0.

### `pSubresourceTilingsForNonPackedMips` [out]

Type: **[D3D11_SUBRESOURCE_TILING](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_subresource_tiling)***

A pointer to a [D3D11_SUBRESOURCE_TILING](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_subresource_tiling) structure that **GetResourceTiling** fills with info about subresource tiles.

If subresource tiles are part of packed mipmaps, **GetResourceTiling** sets the members of [D3D11_SUBRESOURCE_TILING](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_subresource_tiling) to zeros, except the **StartTileIndexInOverallResource** member, which **GetResourceTiling** sets to **D3D11_PACKED_TILE** (0xffffffff). The **D3D11_PACKED_TILE** constant indicates that the whole
**D3D11_SUBRESOURCE_TILING** structure is meaningless for this situation, and the info that the *pPackedMipDesc* parameter points to applies.

## Remarks

For more info about tiled resources, see [Tiled resources](https://learn.microsoft.com/windows/desktop/direct3d11/tiled-resources).

## See also

[ID3D11Device2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nn-d3d11_2-id3d11device2)
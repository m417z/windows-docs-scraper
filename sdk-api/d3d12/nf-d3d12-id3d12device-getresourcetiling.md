## Description

Gets info about how a tiled resource is broken into tiles.

## Parameters

### `pTiledResource` [in]

Type: **[ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource)***

Specifies a tiled [ID3D12Resource](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12resource) to get info about.

### `pNumTilesForEntireResource` [out, optional]

Type: **UINT***

A pointer to a variable that receives the number of tiles needed to store the entire tiled resource.

### `pPackedMipDesc` [out, optional]

Type: **[D3D12_PACKED_MIP_INFO](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_packed_mip_info)***

A pointer to a [D3D12_PACKED_MIP_INFO](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_packed_mip_info) structure that **GetResourceTiling** fills with info about how the tiled resource's mipmaps are packed.

### `pStandardTileShapeForNonPackedMips` [out, optional]

Type: **[D3D12_TILE_SHAPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tile_shape)***

Specifies a [D3D12_TILE_SHAPE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tile_shape) structure that **GetResourceTiling** fills with info about the tile shape. This is info about how pixels fit in the tiles, independent of tiled resource's dimensions, not including packed mipmaps. If the entire tiled resource is packed, this parameter is meaningless because the tiled resource has no defined layout for packed mipmaps. In this situation, **GetResourceTiling** sets the members of D3D12_TILE_SHAPE to zeros.

### `pNumSubresourceTilings` [in, out, optional]

Type: **UINT***

A pointer to a variable that contains the number of tiles in the subresource. On input, this is the number of subresources to query tilings for; on output, this is the number that was actually retrieved at *pSubresourceTilingsForNonPackedMips* (clamped to what's available).

### `FirstSubresourceTilingToGet` [in]

Type: **UINT**

The index of the first subresource tile to get. **GetResourceTiling** ignores this parameter if the number that *pNumSubresourceTilings* points to is 0.

### `pSubresourceTilingsForNonPackedMips` [out]

Type: **[D3D12_SUBRESOURCE_TILING](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_subresource_tiling)***

Specifies a [D3D12_SUBRESOURCE_TILING](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_subresource_tiling) structure that **GetResourceTiling** fills with info about subresource tiles. If subresource tiles are part of packed mipmaps, **GetResourceTiling** sets the members of D3D12_SUBRESOURCE_TILING to zeros, except the *StartTileIndexInOverallResource* member, which **GetResourceTiling** sets to D3D12_PACKED_TILE (0xffffffff). The D3D12_PACKED_TILE constant indicates that the whole **D3D12_SUBRESOURCE_TILING** structure is meaningless for this situation, and the info that the *pPackedMipDesc* parameter points to applies.

## Remarks

To estimate the total resource size of textures needed when calculating heap sizes and calling [CreatePlacedResource](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-createplacedresource), use [GetResourceAllocationInfo](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12device-getresourceallocationinfo(uint_uint_constd3d12_resource_desc)) instead of **GetResourceTiling**.
**GetResourceTiling** cannot be used for this.

For more information on tiled resources, refer to [Volume Tiled Resources](https://learn.microsoft.com/windows/desktop/direct3d12/volume-tiled-resources).

## See also

[ID3D12Device](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12device)

[Subresources](https://learn.microsoft.com/windows/desktop/direct3d12/subresources)
# ID3D12CommandQueue::CopyTileMappings

## Description

Copies mappings from a source reserved resource to a destination reserved resource.

## Parameters

### `pDstResource` [in]

A pointer to the destination reserved resource.

### `pDstRegionStartCoordinate` [in]

A pointer to a
[D3D12_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tiled_resource_coordinate) structure that describes the starting coordinates of the destination reserved resource.

### `pSrcResource` [in]

A pointer to the source reserved resource.

### `pSrcRegionStartCoordinate` [in]

A pointer to a [D3D12_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tiled_resource_coordinate) structure that describes the starting coordinates of the source reserved resource.

### `pRegionSize` [in]

A pointer to a [D3D12_TILE_REGION_SIZE](https://learn.microsoft.com/windows/desktop/api/d3d12/ns-d3d12-d3d12_tile_region_size) structure that describes the size of the reserved region.

### `Flags`

One member of [D3D12_TILE_MAPPING_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12/ne-d3d12-d3d12_tile_mapping_flags).

## Remarks

Use **CopyTileMappings** to copy the tile mappings from one reserved resource to another, either to duplicate a resource mapping, or to initialize a new mapping before modifying it using [UpdateTileMappings](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12commandqueue-updatetilemappings).

**CopyTileMappings** helps with tasks such as shifting mappings around within and across reserved resources, for example, scrolling tiles.
The source and destination regions can overlap; the result of the copy in this situation is as if the source was saved to a temporary location
and from there written to the destination.

The destination and the source regions must each entirely fit in their resource or behavior is undefined and the debug layer will emit an error.

## See also

[ID3D12CommandQueue](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12commandqueue)

[UpdateTileMappings](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12commandqueue-updatetilemappings)

[Volume Tiled Resources](https://learn.microsoft.com/windows/desktop/direct3d12/volume-tiled-resources)
# ID3D11DeviceContext2::CopyTileMappings

## Description

Copies mappings from a source tiled resource to a destination tiled resource.

## Parameters

### `pDestTiledResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

A pointer to the destination tiled resource.

### `pDestRegionStartCoordinate` [in]

Type: **const [D3D11_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_tiled_resource_coordinate)***

A pointer to a [D3D11_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_tiled_resource_coordinate) structure that describes the starting coordinates of the destination tiled resource.

### `pSourceTiledResource` [in]

Type: **[ID3D11Resource](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11resource)***

A pointer to the source tiled resource.

### `pSourceRegionStartCoordinate` [in]

Type: **const [D3D11_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_tiled_resource_coordinate)***

A pointer to a [D3D11_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_tiled_resource_coordinate) structure that describes the starting coordinates of the source tiled resource.

### `pTileRegionSize` [in]

Type: **const [D3D11_TILE_REGION_SIZE](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_tile_region_size)***

A pointer to a [D3D11_TILE_REGION_SIZE](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_tile_region_size) structure that describes the size of the tiled region.

### `Flags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of [D3D11_TILE_MAPPING_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ne-d3d11_2-d3d11_tile_mapping_flag) values that are combined by using a bitwise OR operation. The only valid value is **D3D11_TILE_MAPPING_NO_OVERWRITE**, which indicates that previously submitted commands to the device that may still be executing do not reference any of the tile region being updated. The device can then avoid having to flush previously submitted work to perform the tile mapping update. If the app violates this promise by updating tile mappings for locations in tiled resources that are still being referenced by outstanding commands, undefined rendering behavior results, including the potential for significant slowdowns on some architectures. This is like the "no overwrite" concept that exists elsewhere in the Direct3D API, except applied to the tile mapping data structure itself (which in hardware is a page table). The absence of the **D3D11_TILE_MAPPING_NO_OVERWRITE** value requires that tile mapping updates that **CopyTileMappings** specifies must be completed before any subsequent Direct3D command can proceed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; otherwise, returns one of the following:

* Returns **E_INVALIDARG** if various conditions such as invalid flags or passing in non Tiled Resources result in the call being dropped.
  The dest and the source regions must each entirely fit in their resource or behavior is undefined (debug layer will emit an error).
* Returns **E_OUTOFMEMORY** if the call results in the driver having to allocate space for new page table mappings but running out of memory.
  If out of memory occurs when this is called in a commandlist and the commandlist is being executed, the device will be removed. Applications can avoid this situation by only doing update calls that change existing mappings from Tiled Resources within commandlists (so drivers will not have to allocate page table memory, only change the mapping).

## Remarks

**CopyTileMappings** helps with tasks such as shifting mappings around within and across tiled resources, for example, scrolling tiles. The source and destination regions can overlap; the result of the copy in this situation is as if the source was saved to a temp location and then from there written to the destination.

For more info about tiled resources, see [Tiled resources](https://learn.microsoft.com/windows/desktop/direct3d11/tiled-resources).

## See also

[ID3D11DeviceContext2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nn-d3d11_2-id3d11devicecontext2)
# D3D11_TILE_REGION_SIZE structure

## Description

Describes the size of a tiled region.

## Members

### `NumTiles`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of tiles in the tiled region.

### `bUseBox`

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Specifies whether the runtime uses the **Width**, **Height**, and **Depth** members to define the region.

If **TRUE**, the runtime uses the **Width**, **Height**, and **Depth** members to define the region.

If **FALSE**, the runtime ignores the **Width**, **Height**, and **Depth** members and uses the **NumTiles** member to traverse tiles in the resource linearly across x, then y, then z (as applicable) and then spills over mipmaps/arrays in subresource order. For example, use this technique to map an entire resource at once.

Regardless of whether you specify **TRUE** or **FALSE** for **bUseBox**, you use a [D3D11_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_tiled_resource_coordinate) structure to specify the starting location for the region within the resource as a separate parameter outside of this structure by using x, y, and z coordinates.

When the region includes mipmaps that are packed with nonstandard tiling, **bUseBox** must be **FALSE** because tile dimensions are not standard and the app only knows a count of how many tiles are consumed by the packed area, which is per array slice. The corresponding (separate) starting location parameter uses x to offset into the flat range of tiles in this case, and y and z coordinates must each be 0.

### `Width`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The width of the tiled region, in tiles. Used for buffer and 1D, 2D, and 3D textures.

### `Height`

Type: **UINT16**

The height of the tiled region, in tiles. Used for 2D and 3D textures.

### `Depth`

Type: **UINT16**

The depth of the tiled region, in tiles. Used for 3D textures or arrays. For arrays, used for advancing in depth jumps to next slice of same mipmap size, which isn't contiguous in the subresource counting space if there are multiple mipmaps.

## See also

[D3D11_TILED_RESOURCE_COORDINATE](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ns-d3d11_2-d3d11_tiled_resource_coordinate)

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)

[Tiled resources](https://learn.microsoft.com/windows/desktop/direct3d11/tiled-resources)
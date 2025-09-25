# D3D11_TILED_RESOURCE_COORDINATE structure

## Description

Describes the coordinates of a tiled resource.

## Members

### `X`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The x position of a tiled resource. Used for buffer and 1D, 2D, and 3D textures.

### `Y`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The y position of a tiled resource. Used for 2D and 3D textures.

### `Z`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The z position of a tiled resource. Used for 3D textures.

### `Subresource`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A subresource index value into mipmaps and arrays. Used for 1D, 2D, and 3D textures.

For mipmaps that use nonstandard tiling, or are packed, or both use nonstandard tiling and are packed, any subresource value that indicates any of the packed mipmaps all refer to the same tile.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)
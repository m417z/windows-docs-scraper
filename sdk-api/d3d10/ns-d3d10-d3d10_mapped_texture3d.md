# D3D10_MAPPED_TEXTURE3D structure

## Description

Provides access to [subresource](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types) data in a [3D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types).

## Members

### `pData`

Type: **void***

Pointer to the data.

### `RowPitch`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The pitch, or width, or physical size (in bytes) of one row of an uncompressed texture. Since a block-compressed texture is encoded in 4x4 blocks, the **RowPitch** for a compressed texture is the number of bytes in a block of 4x4 texels. See [virtual size vs physical size](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-block-compression) for more information on block compression.

### `DepthPitch`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The pitch or number of bytes in all rows for a single depth.

## Remarks

This structure is used to access subresource data when calling [ID3D10Texture3D::Map](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10texture3d-map). To access data, you must cast the **pData** pointer; see [D3D10_MAPPED_TEXTURE2D](https://learn.microsoft.com/windows/desktop/api/d3d10/ns-d3d10-d3d10_mapped_texture2d) for an example.

To illustrate pitch for an uncompressed texture, assume a 3D texture with mipmap levels, as shown in the following illustration.

![Illustration of a 3D texture with mipmap levels](https://learn.microsoft.com/windows/win32/api/d3d10/images/d3d10_resource_texture3d.png)

It is easiest to consider the top-level texture only, as shown in the following illustration.

![Illustration of only the top-level texture](https://learn.microsoft.com/windows/win32/api/d3d10/images/d3d10_3d_texture_1.png)

And then visualize the top-level texture redrawn as a series of 2D textures, each one having a different depth value. This yields several texture planes, as shown in the following illustration.

![Illustration of top-level texture drawn as 2D texture planes](https://learn.microsoft.com/windows/win32/api/d3d10/images/d3d10_3d_texture_conceptual.png)

However, the actual layout of all the elements from all the texture planes looks more like the following illustration.

![Illustration of the row pitch and depth pitch in memory](https://learn.microsoft.com/windows/win32/api/d3d10/images/d3d10_3d_texture_memory.png)

Use row pitch to advance a pointer between rows within a single 2D texture plane; use depth pitch to advance a pointer between 2D texture planes.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-structures)
# D3D11_SUBRESOURCE_DATA structure

## Description

Specifies data for initializing a subresource.

## Members

### `pSysMem`

Type: **const void***

Pointer to the initialization data.

### `SysMemPitch`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The distance (in bytes) from the beginning of one line of a texture to the next line.
System-memory pitch is used only for 2D and 3D texture data as it is has no meaning for the other resource types. Specify the distance from the first pixel of one 2D slice of a 3D texture to the first pixel of the next 2D slice in that texture in the **SysMemSlicePitch** member.

### `SysMemSlicePitch`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The distance (in bytes) from the beginning of one depth level to the next.
System-memory-slice pitch is only used for 3D texture data as it has no meaning for the other resource types.

## Remarks

This structure is used in calls to create buffers ([ID3D11Device::CreateBuffer](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createbuffer)) and
textures ([ID3D11Device::CreateTexture1D](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createtexture1d), [ID3D11Device::CreateTexture2D](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createtexture2d),
and [ID3D11Device::CreateTexture3D](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createtexture3d)). If the resource you create does not require a system-memory pitch or a system-memory-slice pitch, you can use those members to pass size information, which might help you when you debug a problem with creating a resource.

A subresource is a single mipmap-level surface. You can pass an array of subresources to one of the preceding methods to create the resource. A subresource can be 1D, 2D, or 3D. How you set the members of **D3D11_SUBRESOURCE_DATA** depend on whether the subresource is 1D, 2D, or 3D.

The x, y, and d values are 0-based indices and **BytesPerPixel** depends on the pixel format. For mipmapped 3D surfaces, the number of depth slices in each level is half the number of the previous level (minimum 1) and rounded down if dividing by two results in a non-whole number.

**Note** An application must not rely on **SysMemPitch** being exactly equal to the number of texels in a line times the size of a texel.
In some cases, **SysMemPitch** will include padding to skip past additional data in a line. This could be padding for alignment or
the texture could be a subsection of a larger texture. For example, the **D3D11_SUBRESOURCE_DATA** structure could represent a 32 by 32 subsection of a 128 by 128 texture.
The value for **SysMemSlicePitch** will reflect any padding included in **SysMemPitch**.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)
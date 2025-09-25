# D3D10_SUBRESOURCE_DATA structure

## Description

Specifies data for initializing a [subresource](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types).

## Members

### `pSysMem`

Type: **const void***

Pointer to the initialization data.

### `SysMemPitch`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The distance (in bytes) from the beginning of one line of a texture to the next line.
System-memory pitch is used only for 2D and 3D texture data as it is has no meaning for the other resource types.

### `SysMemSlicePitch`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The distance (in bytes) from the beginning of one depth level to the next.
System-memory-slice pitch is only used for 3D texture data as it has no meaning for the other resource types.

## Remarks

This structure is used in calls to create buffers ([ID3D10Device::CreateBuffer](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createbuffer)) and textures ([ID3D10Device::CreateTexture1D](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createtexture1d),
[ID3D10Device::CreateTexture2D](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createtexture2d), and [ID3D10Device::CreateTexture3D](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createtexture3d)).
If the resource being created does not require a system-memory pitch or a system-memory-pitch slice, then you are free to use those members to
pass size information which may help you when debugging a problem creating a resource.

Note that an application should not rely on **SysMemPitch** being exactly equal to the number of texels in a line times the size of a texel.
In some cases **SysMemPitch** will include padding to skip past additional data in a line. This could be padding for alignment or
the texture could be a subsection of a larger texture. For example the D3D10_SUBRESOURCE_DATA structure could represent a 32 by 32 subsection of a 128 by 128 texture.
The value for **SysMemSlicePitch** will reflect any padding included in **SysMemPitch**.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-structures)
## Description

Describes a [3D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types).

## Members

## Remarks

`format`
Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**
Texture format (see [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)).

`width`
Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**
Texture width (in texels). The range is from 1 to D3D10_REQ_TEXTURE3D_U_V_OR_W_DIMENSION (2048). For more information about restrictions, see Remarks.

`height`
Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**
Texture height (in texels). The range is from 1 to D3D10_REQ_TEXTURE3D_U_V_OR_W_DIMENSION (2048). For more information about restrictions, see Remarks.

`depth`
Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**
Texture depth (in texels). The range is from 1 to D3D10_REQ_TEXTURE3D_U_V_OR_W_DIMENSION (2048).

`mipLevels`
Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**
Number of subtextures (also called mipmap levels). Use 1 for a multisampled texture; or 0 to generate a full set of subtextures.

`bindFlags`
Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**
Flags (see [D3D10_BIND_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_bind_flag)) for binding to [pipeline](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-pipeline-stages) stages. The flags can be combined by a logical OR.

`usage`
Type: **[D3D10_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_usage)**
Value that identifies how the texture is to be read from and written to. The most common value is D3D10_USAGE-DEFAULT; see [D3D10_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_usage) for all possible values.

`cpuAccessFlags`
Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**
Flags (see [D3D10_CPU_ACCESS_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_cpu_access_flag)) to specify the types of CPU access allowed. Use 0 if CPU access is not required. These flags can be combined with a logical OR.

`miscFlags`
Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**
Flags (see [D3D10_RESOURCE_MISC_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_resource_misc_flag)) that identify other, less common resource options. Use 0 if none of these flags apply. These flags can be combined with a logical OR.

This structure is used in a call to [ID3D10Device::CreateTexture3D](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createtexture3d). A helpful derived structure CD3D10_TEXTURE3D_DESC is declared in D3D10.h, to help create a texture description.

The device restricts the size of subsampled, block compressed (see [Block Compression (Direct3D 10)](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-block-compression)), and bit format resources to be multiples of sizes specific to each format.

## See also

[Resource structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-structures)
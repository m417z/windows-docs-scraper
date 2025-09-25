## Description

Describes a [1D texture](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-resources-types).

## Members

### `Width`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Texture width (in texels). The range is from 1 to D3D10_REQ_TEXTURE1D_U_DIMENSION (8192).

### `MipLevels`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of subtextures (also called mipmap levels). Use 1 for a multisampled texture; or 0 to generate a full set of subtextures.

### `ArraySize`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Number of textures in the array. The range is from 1 to D3D10_REQ_TEXTURE1D_ARRAY_AXIS_DIMENSION (512).

### `Format`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

Texture format (see [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)).

### `Usage`

Type: **[D3D10_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_usage)**

Value that identifies how the texture is to be read from and written to. The most common value is D3D10_USAGE-DEFAULT; see [D3D10_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_usage) for all possible values.

### `BindFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags (see [D3D10_BIND_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_bind_flag)) for binding to [pipeline](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-programming-guide-pipeline-stages) stages. The flags can be combined by a logical OR.

### `CPUAccessFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags (see [D3D10_CPU_ACCESS_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_cpu_access_flag)) to specify the types of CPU access allowed. Use 0 if CPU access is not required. These flags can be combined with a logical OR.

### `MiscFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags (see [D3D10_RESOURCE_MISC_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_resource_misc_flag)) that identify other, less common resource options. Use 0 if none of these flags apply. These flags can be combined with a logical OR.

## Remarks

This structure is used in a call to [ID3D10Device::CreateTexture1D](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10device-createtexture1d). A helpful derived structure CD3D10_TEXTURE1D_DESC is declared in D3D10.h, to help create a texture description.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-resource-structures)
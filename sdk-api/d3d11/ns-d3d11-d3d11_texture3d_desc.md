# D3D11_TEXTURE3D_DESC structure

## Description

Describes a 3D texture.

## Members

### `Width`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Texture width (in texels). The range is from 1 to D3D11_REQ_TEXTURE3D_U_V_OR_W_DIMENSION (2048). However, the range is actually constrained by the [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) at which you create the rendering device. For more information about restrictions, see Remarks.

### `Height`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Texture height (in texels). The range is from 1 to D3D11_REQ_TEXTURE3D_U_V_OR_W_DIMENSION (2048). However, the range is actually constrained by the [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) at which you create the rendering device. For more information about restrictions, see Remarks.

### `Depth`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Texture depth (in texels). The range is from 1 to D3D11_REQ_TEXTURE3D_U_V_OR_W_DIMENSION (2048). However, the range is actually constrained by the [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) at which you create the rendering device. For more information about restrictions, see Remarks.

### `MipLevels`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The maximum number of mipmap levels in the texture. See the remarks in [D3D11_TEX1D_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_srv). Use 1 for a multisampled texture; or 0 to generate a full set of subtextures.

### `Format`

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

Texture format (see [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)).

### `Usage`

Type: **[D3D11_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage)**

Value that identifies how the texture is to be read from and written to. The most common value is D3D11_USAGE_DEFAULT; see [D3D11_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage) for all possible values.

### `BindFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags (see [D3D11_BIND_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag)) for binding to pipeline stages. The flags can be combined by a bitwise OR.

### `CPUAccessFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags (see [D3D11_CPU_ACCESS_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_cpu_access_flag)) to specify the types of CPU access allowed. Use 0 if CPU access is not required. These flags can be combined with a bitwise OR.

### `MiscFlags`

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Flags (see [D3D11_RESOURCE_MISC_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag)) that identify other, less common resource options. Use 0 if none of these flags apply. These flags can be combined with a bitwise OR.

## Remarks

This structure is used in a call to [ID3D11Device::CreateTexture3D](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createtexture3d).

In addition to this structure, you can also use the [CD3D11_TEXTURE3D_DESC](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/jj151706(v=vs.85)) derived structure, which is defined in D3D11.h and behaves like an inherited class, to help create a texture description.

The device restricts the size of subsampled, block compressed, and bit format resources to be multiples of sizes specific to each format.

The texture size range is determined by the [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) at which you create the device and not the Microsoft Direct3D interface version. For example, if you use Microsoft Direct3D 10 hardware at feature level 10 ([D3D_FEATURE_LEVEL_10_0](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level)) and call [D3D11CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11createdevice) to create an [ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device), you must constrain the maximum texture size to D3D10_REQ_TEXTURE3D_U_V_OR_W_DIMENSION (2048) when you create your 3D texture.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)
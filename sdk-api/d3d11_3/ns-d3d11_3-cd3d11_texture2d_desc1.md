# CD3D11_TEXTURE2D_DESC1 structure

## Description

Describes a 2D texture.

## Members

### `CD3D11_TEXTURE2D_DESC1`

TBD

### `~CD3D11_TEXTURE2D_DESC1`

TBD

### `operator` const D3D11_TEXTURE2D_DESC1&

TBD

### `D3D11_TEXTURE2D_DESC1`

#### - ArraySize

Number of textures in the texture array. The range is from 1 to D3D11_REQ_TEXTURE2D_ARRAY_AXIS_DIMENSION (2048). For a texture cube-map, this value is a multiple of 6 (that is, 6 times the value in the **NumCubes** member of [D3D11_TEXCUBE_ARRAY_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_texcube_array_srv)), and the range is from 6 to 2046. The range is actually constrained by the [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) at which you create the rendering device. For more information about restrictions, see Remarks.

#### - BindFlags

Flags (see [D3D11_BIND_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_bind_flag)) for binding to pipeline stages. The flags can be combined by a bitwise OR.

#### - CPUAccessFlags

Flags (see [D3D11_CPU_ACCESS_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_cpu_access_flag)) to specify the types of CPU access allowed. Use 0 if CPU access is not required. These flags can be combined with a bitwise OR.

#### - Format

Texture format (see [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)).

#### - Height

Texture height (in texels). The range is from 1 to D3D11_REQ_TEXTURE2D_U_OR_V_DIMENSION (16384). For a texture cube-map, the range is from 1 to D3D11_REQ_TEXTURECUBE_DIMENSION (16384). However, the range is actually constrained by the [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) at which you create the rendering device. For more information about restrictions, see Remarks.

#### - MipLevels

The maximum number of mipmap levels in the texture. See the remarks in [D3D11_TEX1D_SRV](https://learn.microsoft.com/windows/desktop/api/d3d11/ns-d3d11-d3d11_tex1d_srv). Use 1 for a multisampled texture; or 0 to generate a full set of subtextures.

#### - MiscFlags

Flags (see [D3D11_RESOURCE_MISC_FLAG](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag)) that identify other, less common resource options. Use 0 if none of these flags apply. These flags can be combined by using a bitwise OR. For a texture cube-map, set the [D3D11_RESOURCE_MISC_TEXTURECUBE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_resource_misc_flag) flag. Cube-map arrays (that is, **ArraySize** > 6) require feature level [D3D_FEATURE_LEVEL_10_1](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level) or higher.

#### - SampleDesc

Structure that specifies multisampling parameters for the texture. See [DXGI_SAMPLE_DESC](https://learn.microsoft.com/windows/desktop/api/dxgicommon/ns-dxgicommon-dxgi_sample_desc).

#### - TextureLayout

A [D3D11_TEXTURE_LAYOUT](https://learn.microsoft.com/windows/desktop/api/d3d11_3/ne-d3d11_3-d3d11_texture_layout)-typed value that identifies the layout of the texture.

The TextureLayout parameter selects both the actual layout of the texture in memory and the layout visible to the application while the texture is mapped. These flags may not be requested without CPU access also requested.

It is illegal to set CPU access flags on default textures without also setting TextureLayout to a value other than D3D11_TEXTURE_LAYOUT_UNDEFINED.

D3D11_TEXTURE_LAYOUT_ROW_MAJOR may only be used to create non-multisampled, textures with a single subresource (Planar YUV textures are supported). These textures may only be used as a source and destination of copy operations, and BindFlags must be zero.

D3D11_TEXTURE_LAYOUT_64K_STANDARD_SWIZZLE may only be used to create non-multisampled, non-depth-stencil textures.

#### - Usage

Value that identifies how the texture is to be read from and written to. The most common value is D3D11_USAGE_DEFAULT; see [D3D11_USAGE](https://learn.microsoft.com/windows/desktop/api/d3d11/ne-d3d11-d3d11_usage) for all possible values.

#### - Width

Texture width (in texels). The range is from 1 to D3D11_REQ_TEXTURE2D_U_OR_V_DIMENSION (16384). For a texture cube-map, the range is from 1 to D3D11_REQ_TEXTURECUBE_DIMENSION (16384). However, the range is actually constrained by the [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) at which you create the rendering device. For more information about restrictions, see Remarks.

## Remarks

This structure is used in a call to [ID3D11Device3::CreateTexture2D1](https://learn.microsoft.com/windows/desktop/api/d3d11_3/nf-d3d11_3-id3d11device3-createtexture2d1).

In addition to this structure, you can also use the **CD3D11_TEXTURE2D_DESC1** derived structure, which is defined in D3D11_3.h and behaves like an inherited class, to help create a texture description.

The device places some size restrictions (must be multiples of a minimum size) for a subsampled, block compressed, or bit-format resource.

The texture size range is determined by the [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) at which you create the device and not the Microsoft Direct3D interface version. For example, if you use Microsoft Direct3D 10 hardware at feature level 10 ([D3D_FEATURE_LEVEL_10_0](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_feature_level)) and call [D3D11CreateDevice](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-d3d11createdevice) to create an [ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device), you must constrain the maximum texture size to D3D10_REQ_TEXTURE2D_U_OR_V_DIMENSION (8192) when you create your 2D texture.

## See also

[Resource Structures](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-resource-structures)
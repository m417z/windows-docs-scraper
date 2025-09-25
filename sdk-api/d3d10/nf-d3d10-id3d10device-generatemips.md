# ID3D10Device::GenerateMips

## Description

Generates mipmaps for the given shader resource.

## Parameters

### `pShaderResourceView` [in]

Type: **[ID3D10ShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10shaderresourceview)***

A pointer to an [ID3D10ShaderResourceView](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10shaderresourceview). The mipmaps will be generated for this shader resource.

## Remarks

GenerateMips may be called on any ID3D10ShaderResourceView in order to generate the lower mipmap levels. GenerateMips uses the largest mipmap level of the view to recursively generate the lower levels of the mip, stopping with the smallest level specified by the view. If the base resource was not created with [D3D10_BIND_RENDER_TARGET](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_bind_flag) and [D3D10_RESOURCE_MISC_GENERATE_MIPS](https://learn.microsoft.com/windows/desktop/api/d3d10/ne-d3d10-d3d10_resource_misc_flag), this call has no effect.

Video adapters that support [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.1 and higher support generating mipmaps if you use any of these formats:

```

DXGI_FORMAT_R8G8B8A8_UNORM
DXGI_FORMAT_R8G8B8A8_UNORM_SRGB
DXGI_FORMAT_B5G6R5_UNORM
DXGI_FORMAT_B8G8R8A8_UNORM
DXGI_FORMAT_B8G8R8A8_UNORM_SRGB
DXGI_FORMAT_B8G8R8X8_UNORM
DXGI_FORMAT_B8G8R8X8_UNORM_SRGB

```

Video adapters that support [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.2 and higher support generating mipmaps if you use any of these formats in addition to any of the formats for feature level 9.1:

```

DXGI_FORMAT_R16G16B16A16_FLOAT
DXGI_FORMAT_R16G16B16A16_UNORM
DXGI_FORMAT_R16G16_FLOAT
DXGI_FORMAT_R16G16_UNORM
DXGI_FORMAT_R32_FLOAT

```

Video adapters that support [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 9.3 and higher support generating mipmaps if you use any of these formats in addition to any of the formats for feature levels 9.1 and 9.2:

```

DXGI_FORMAT_R32G32B32A32_FLOAT
DXGI_FORMAT_B4G4R4A4 (optional)

```

Video adapters that support [feature level](https://learn.microsoft.com/windows/desktop/direct3d11/overviews-direct3d-11-devices-downlevel-intro) 10 and higher support generating mipmaps if you use any of these formats in addition to any of the formats for feature levels 9.1, 9.2, and 9.3:

```

DXGI_FORMAT_R32G32B32_FLOAT (optional)
DXGI_FORMAT_R16G16B16A16_SNORM
DXGI_FORMAT_R32G32_FLOAT
DXGI_FORMAT_R10G10B10A2_UNORM
DXGI_FORMAT_R11G11B10_FLOAT
DXGI_FORMAT_R8G8B8A8_SNORM
DXGI_FORMAT_R16G16_SNORM
DXGI_FORMAT_R8G8_UNORM
DXGI_FORMAT_R8G8_SNORM
DXGI_FORMAT_R16_FLOAT
DXGI_FORMAT_R16_UNORM
DXGI_FORMAT_R16_SNORM
DXGI_FORMAT_R8_UNORM
DXGI_FORMAT_R8_SNORM
DXGI_FORMAT_A8_UNORM
DXGI_FORMAT_B5G5R5A1_UNORM (optional)

```

For all other unsupported formats, this method will silently fail.

## See also

[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)
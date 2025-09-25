## Description

Defines constants that specify a cross-API sharing support tier.

The resource data formats mentioned are members of the [DXGI_FORMAT enumeration](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format).

## Constants

### `D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER_0:0`

Related to [D3D11_SHARED_RESOURCE_TIER::D3D11_SHARED_RESOURCE_TIER_1](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_shared_resource_tier).

Specifies that the most basic level of cross-API sharing is supported, including the following resource data formats.

* DXGI_FORMAT_R8G8B8A8_UNORM
* DXGI_FORMAT_R8G8B8A8_UNORM_SRGB
* DXGI_FORMAT_B8G8R8A8_UNORM
* DXGI_FORMAT_B8G8R8A8_UNORM_SRGB
* DXGI_FORMAT_B8G8R8X8_UNORM
* DXGI_FORMAT_B8G8R8X8_UNORM_SRGB
* DXGI_FORMAT_R10G10B10A2_UNORM
* DXGI_FORMAT_R16G16B16A16_FLOAT

### `D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER_1`

Related to [D3D11_SHARED_RESOURCE_TIER::D3D11_SHARED_RESOURCE_TIER_2](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_shared_resource_tier).

Specifies that cross-API sharing functionality of **D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER_0** is supported, plus the following formats.

* DXGI_FORMAT_R16G16B16A16_TYPELESS
* DXGI_FORMAT_R10G10B10A2_TYPELESS
* DXGI_FORMAT_R8G8B8A8_TYPELESS
* DXGI_FORMAT_R8G8B8X8_TYPELESS
* DXGI_FORMAT_R16G16_TYPELESS
* DXGI_FORMAT_R8G8_TYPELESS
* DXGI_FORMAT_R32_TYPELESS
* DXGI_FORMAT_R16_TYPELESS
* DXGI_FORMAT_R8_TYPELESS

This level support is built into WDDM 2.4.

Also see [Extended support for shared Texture2D resources](https://learn.microsoft.com/windows/win32/direct3d11/direct3d-11-1-features#extended-support-for-shared-texture2d-resources).

### `D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER_2`

Related to [D3D11_SHARED_RESOURCE_TIER::D3D11_SHARED_RESOURCE_TIER_3](https://learn.microsoft.com/windows/win32/api/d3d11/ne-d3d11-d3d11_shared_resource_tier).

Specifies that cross-API sharing functionality of **D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER_1** is supported, plus the following formats.

* DXGI_FORMAT_NV12 (also see [Extended NV12 texture support](https://learn.microsoft.com/windows/win32/direct3d11/direct3d-11-4-features#extended-nv12-texture-support))

### `D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER_3`

Specifies that cross-API sharing functionality of **D3D12_SHARED_RESOURCE_COMPATIBILITY_TIER_2** is supported, plus the following formats.

* DXGI_FORMAT_R11G11B10_FLOAT

## Remarks

## See also
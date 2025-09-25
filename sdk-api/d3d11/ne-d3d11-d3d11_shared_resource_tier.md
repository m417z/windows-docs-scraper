## Description

Defines constants that specify the level of support for shared resources in the current graphics driver.

## Constants

### `D3D11_SHARED_RESOURCE_TIER_0:0`

Specifies the support available when [D3D11_FEATURE_DATA_D3D11_OPTIONS::ExtendedResourceSharing](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options) is `FALSE` (only very old drivers have this value set to `FALSE`).

See [Extended support for shared Texture2D resources](https://learn.microsoft.com/windows/win32/direct3d11/direct3d-11-1-features#extended-support-for-shared-texture2d-resources).

### `D3D11_SHARED_RESOURCE_TIER_1`

Specifies the support available when [D3D11_FEATURE_DATA_D3D11_OPTIONS::ExtendedResourceSharing](https://learn.microsoft.com/windows/win32/api/d3d11/ns-d3d11-d3d11_feature_data_d3d11_options) and [D3D11_FEATURE_DATA_D3D11_OPTIONS4::ExtendedNV12SharedTextureSupported](https://learn.microsoft.com/windows/win32/api/d3d11_4/ns-d3d11_4-d3d11_feature_data_d3d11_options4) are `TRUE`.

You can share additional formats; see [Extended support for shared Texture2D resources](https://learn.microsoft.com/windows/win32/direct3d11/direct3d-11-1-features#extended-support-for-shared-texture2d-resources).

Only formats that are still shareable when **D3D11_FEATURE_DATA_D3D11_OPTIONS::ExtendedResourceSharing** == `FALSE` can be shared across APIs between Direct3D 11 and Direct3D 12.

Resource formats added by **D3D11_FEATURE_DATA_D3D11_OPTIONS::ExtendedResourceSharing** == `TRUE` can't be shared across APIs.

### `D3D11_SHARED_RESOURCE_TIER_2`

Specifies the support available when [D3D11_FEATURE_DATA_D3D11_OPTIONS4::ExtendedNV12SharedTextureSupported](https://learn.microsoft.com/windows/win32/api/d3d11_4/ns-d3d11_4-d3d11_feature_data_d3d11_options4) is `TRUE`. Also see [Extended NV12 texture support](https://learn.microsoft.com/windows/win32/direct3d11/direct3d-11-4-features#extended-nv12-texture-support).

See [Extended support for shared Texture2D resources](https://learn.microsoft.com/windows/win32/direct3d11/direct3d-11-1-features#extended-support-for-shared-texture2d-resources).

Sharing across APIs between Direct3D 11 and Direct3D 12 is possible for the **D3D11_FEATURE_DATA_D3D11_OPTIONS::ExtendedResourceSharing** == `TRUE` format list.

### `D3D11_SHARED_RESOURCE_TIER_3`

Specifies that [DXGI_FORMAT_R11G11B10_FLOAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format) supports NT handle sharing. Also see [CreateSharedHandle](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nf-dxgi1_2-idxgiresource1-createsharedhandle).

Sharing across APIs between Direct3D 11 and Direct3D 12 is possible for the **DXGI_FORMAT_R11G11B10_FLOAT** format.

## Remarks

## See also

* [Extended support for shared Texture2D resources](https://learn.microsoft.com/windows/win32/direct3d11/direct3d-11-1-features#extended-support-for-shared-texture2d-resources)
## Description

Get the number of quality levels available during multisampling.

## Parameters

### `Format` [in]

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format)**

The texture format. See [DXGI_FORMAT](https://learn.microsoft.com/windows/win32/api/dxgiformat/ne-dxgiformat-dxgi_format).

### `SampleCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)**

The number of samples during multisampling.

### `pNumQualityLevels` [out]

Type: **[UINT](https://learn.microsoft.com/windows/win32/WinProg/windows-data-types)***

Number of quality levels supported by the adapter. See **Remarks**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/win32/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

When multisampling a texture, the number of quality levels available for an adapter is dependent on the texture format used and the number of samples requested. The maximum number of quality levels is defined by **D3D11_MAX_MULTISAMPLE_SAMPLE_COUNT** in `D3D11.h`. If this method returns 0 (S_OK), and the output parameter `pNumQualityLevels` receives a positive value, then the format and sample count combination is supported for the device. When the combination is not supported, this method returns a failure **HRESULT** code (that is, a negative integer), or sets `pNumQualityLevels` output parameter to zero, or both.

Furthermore, the definition of a quality level is left to each hardware vendor to define; however no facility is provided by Direct3D to help discover this information.

Note that FEATURE_LEVEL_10_1 devices are required to support 4x MSAA for all render targets except R32G32B32A32 and R32G32B32. FEATURE_LEVEL_11_0 devices are required to support 4x MSAA for all render target formats, and 8x MSAA for all render target formats except R32G32B32A32 formats.

## See also

[ID3D11Device](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11device)
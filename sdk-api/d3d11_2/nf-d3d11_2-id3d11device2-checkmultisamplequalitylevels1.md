# ID3D11Device2::CheckMultisampleQualityLevels1

## Description

Get the number of quality levels available during multisampling.

## Parameters

### `Format` [in]

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

The texture format during multisampling.

### `SampleCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of samples during multisampling.

### `Flags` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A combination of [D3D11_CHECK_MULTISAMPLE_QUALITY_LEVELS_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ne-d3d11_2-d3d11_check_multisample_quality_levels_flag) values that are combined by using a bitwise OR operation. Currently, only [D3D11_CHECK_MULTISAMPLE_QUALITY_LEVELS_TILED_RESOURCE](https://learn.microsoft.com/windows/desktop/api/d3d11_2/ne-d3d11_2-d3d11_check_multisample_quality_levels_flag) is supported.

### `pNumQualityLevels` [out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a variable the receives the number of quality levels supported by the adapter. See Remarks.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

When you multisample a texture, the number of quality levels available for an adapter is dependent on the texture format that you use and the number of
samples that you request. The maximum number of quality levels is defined by **D3D11_MAX_MULTISAMPLE_SAMPLE_COUNT** in D3D11.h. If this method returns 0, the format
and sample count combination is not supported for the installed adapter.

Furthermore, the definition of a quality level is up to each hardware vendor to define, however no facility is provided by Direct3D to help discover
this information.

Note that FEATURE_LEVEL_10_1 devices are required to support 4x MSAA for all render targets except R32G32B32A32 and R32G32B32.
FEATURE_LEVEL_11_0 devices are required to support 4x MSAA for all render target formats, and 8x MSAA for all render target formats
except R32G32B32A32 formats.

## See also

[ID3D11Device2](https://learn.microsoft.com/windows/desktop/api/d3d11_2/nn-d3d11_2-id3d11device2)
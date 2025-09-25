# ID3D10Device::CheckMultisampleQualityLevels

## Description

Get the number of quality levels available during multisampling.

## Parameters

### `Format` [in]

Type: **[DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format)**

The texture format. See [DXGI_FORMAT](https://learn.microsoft.com/windows/desktop/api/dxgiformat/ne-dxgiformat-dxgi_format).

### `SampleCount` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The number of samples during multisampling.

### `pNumQualityLevels` [out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Number of quality levels supported by the adapter. See remarks.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

When multisampling a texture, the number of quality levels available for an adapter is dependent on the texture format used and the number of samples
requested. The maximum sample count defined by D3D10_MAX_MULTISAMPLE_SAMPLE_COUNT in d3d10.h is 32. If the returned value of
*pNumQualityLevels* is 0, the format and sample count combination is not supported for the installed adapter.

Furthermore, the definition of a quality level is up to each hardware vendor to define, however no facility is provided by Direct3D to help discover
this information.

Direct3D 10.1 devices are required to support 4x MSAA for all formats except R32G32B32A32 and R32G32B32 formats.

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)
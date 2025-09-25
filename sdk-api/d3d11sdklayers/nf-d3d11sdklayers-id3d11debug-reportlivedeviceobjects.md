# ID3D11Debug::ReportLiveDeviceObjects

## Description

Report information about a device object's lifetime.

## Parameters

### `Flags`

Type: **[D3D11_RLDO_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_rldo_flags)**

A value from the
[D3D11_RLDO_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/ne-d3d11sdklayers-d3d11_rldo_flags) enumeration.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## Remarks

**ReportLiveDeviceObjects** uses the value in *Flags* to determine the amount of information to report about a device object's lifetime.

## See also

[ID3D11Debug Interface](https://learn.microsoft.com/windows/desktop/api/d3d11sdklayers/nn-d3d11sdklayers-id3d11debug)
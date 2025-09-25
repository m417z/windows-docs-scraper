# ID3D12DebugDevice::ReportLiveDeviceObjects

## Description

Reports information about a device object's lifetime.

## Parameters

### `Flags`

Type: **[D3D12_RLDO_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_rldo_flags)**

A value from the [D3D12_RLDO_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_rldo_flags) enumeration.
This method uses the value in *Flags* to determine the amount of information to report about a device object's lifetime.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).
[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)

## See also

[ID3D12DebugDevice](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debugdevice)
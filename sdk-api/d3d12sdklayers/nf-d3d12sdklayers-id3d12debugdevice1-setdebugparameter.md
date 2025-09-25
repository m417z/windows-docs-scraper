# ID3D12DebugDevice1::SetDebugParameter

## Description

Modifies the D3D12 optional device-wide Debug Layer settings.

## Parameters

### `Type`

Type: **[D3D12_DEBUG_DEVICE_PARAMETER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_debug_device_parameter_type)**

Specifies a [D3D12_DEBUG_DEVICE_PARAMETER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_debug_device_parameter_type) value that indicates which debug parameter data to get.

### `pData` [in]

Type: **const void***

Debug parameter data to set.

### `DataSize`

Type: **UINT**

Size in bytes of the data pointed to by *pData*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## See also

[GetDebugParameter](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debugdevice1-getdebugparameter)

[ID3D12DebugDevice1](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debugdevice1)
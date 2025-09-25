# ID3D12DebugDevice1::GetDebugParameter

## Description

Gets optional device-wide Debug Layer settings.

## Parameters

### `Type`

Type: **[D3D12_DEBUG_DEVICE_PARAMETER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_debug_device_parameter_type)**

Specifies a [D3D12_DEBUG_DEVICE_PARAMETER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_debug_device_parameter_type) value that indicates which debug parameter data to set.

### `pData` [out]

Type: **void***

Points to the memory that will be filled with a copy of the debug parameter data. The interpretation of this data depends on the [D3D12_DEBUG_DEVICE_PARAMETER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_debug_device_parameter_type) given in the *Type* parameter.

### `DataSize`

Type: **UINT**

Size in bytes of the memory buffer pointed to by *pData*.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## See also

[ID3D12DebugDevice1](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debugdevice1)

[SetDebugParameter](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debugdevice1-setdebugparameter)
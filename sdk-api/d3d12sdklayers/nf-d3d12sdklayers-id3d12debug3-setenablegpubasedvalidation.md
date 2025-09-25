## Description

This method enables or disables GPU-based validation (GBV) before creating a device with the debug layer enabled.

## Parameters

### `Enable`

Type: **BOOL**

TRUE to enable GPU-based validation, otherwise FALSE.

## Remarks

GPU-based validation can be enabled/disabled only prior to creating a device. By default, GPU-based validation is disabled. To disable GPU-based validation after initially enabling it, the device must be fully released and recreated.

For more information, see [Using D3D12 Debug Layer GPU-based validation](https://learn.microsoft.com/windows/win32/direct3d12/using-d3d12-debug-layer-gpu-based-validation).

## See also

[ID3D12Debug3](https://learn.microsoft.com/windows/win32/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debug3)
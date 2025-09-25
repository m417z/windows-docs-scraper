# ID3D12Debug1::SetEnableGPUBasedValidation

## Description

This method enables or disables GPU-Based Validation (GBV) before creating a device with the debug layer enabled.

## Parameters

### `Enable`

Type: **BOOL**

TRUE to enable GPU-Based Validation, otherwise FALSE.

## Remarks

GPU-Based Validation can only be enabled/disabled prior to creating a device. By default, GPU-Based Validation is disabled. To disable GPU-Based Validation after initially enabling it the device must be fully released and recreated; disabling or enabling it after device creation will cause device removal.

For more information, see [Using D3D12 Debug Layer GPU-Based Validation](https://learn.microsoft.com/windows/desktop/direct3d12/using-d3d12-debug-layer-gpu-based-validation).

## See also

[ID3D12Debug1](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debug1)
## Description

This method configures the level of GPU-based validation that the debug device is to perform at runtime.

## Parameters

### `Flags`

Type: **[D3D12_GPU_BASED_VALIDATION_FLAGS](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/ne-d3d12sdklayers-d3d12_gpu_based_validation_flags)**

Specifies the level of GPU-based validation to perform at runtime.

## Remarks

This method overrides the default behavior of GPU-based validation so it must be called before creating the D3D12 Device. These settings can't be changed or cancelled after the device is created. If you want to change the behavior of GPU-based validation at a later time, the device must be destroyed and recreated with different parameters.

## See also

[ID3D12Debug3](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nn-d3d12sdklayers-id3d12debug3)
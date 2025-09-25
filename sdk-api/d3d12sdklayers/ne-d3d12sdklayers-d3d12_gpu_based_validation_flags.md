# D3D12_GPU_BASED_VALIDATION_FLAGS enumeration

## Description

Describes the level of GPU-based validation to perform at runtime.

## Constants

### `D3D12_GPU_BASED_VALIDATION_FLAGS_NONE:0`

Default behavior; resource states, descriptors, and descriptor tables are all validated.

### `D3D12_GPU_BASED_VALIDATION_FLAGS_DISABLE_STATE_TRACKING:0x1`

When set, GPU-based validation does not perform resource state validation which greatly reduces the performance cost of GPU-based validation. Descriptors and descriptor heaps are still validated.

## Remarks

This enumeration is used with the [ID3D12Debug2::SetGPUBasedValidationFlags](https://learn.microsoft.com/windows/desktop/api/d3d12sdklayers/nf-d3d12sdklayers-id3d12debug2-setgpubasedvalidationflags) method to configure the amount of runtime validation that will occur.

## See also

[Core Enumerations](https://learn.microsoft.com/windows/desktop/direct3d12/direct3d-12-enumerations)
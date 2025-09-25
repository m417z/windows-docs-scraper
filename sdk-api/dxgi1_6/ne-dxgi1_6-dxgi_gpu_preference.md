# DXGI_GPU_PREFERENCE enumeration

## Description

The preference of GPU for the app to run on.

## Constants

### `DXGI_GPU_PREFERENCE_UNSPECIFIED:0`

No preference of GPU.

### `DXGI_GPU_PREFERENCE_MINIMUM_POWER`

Preference for the minimum-powered GPU (such as an integrated graphics processor, or iGPU).

### `DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE`

Preference for the highest performing GPU, such as a discrete graphics processor (dGPU) or external graphics processor (xGPU).

## Remarks

This enumeration is used in the [IDXGIFactory6::EnumAdapterByGpuPreference](https://learn.microsoft.com/windows/desktop/api/dxgi1_6/nf-dxgi1_6-idxgifactory6-enumadapterbygpupreference) method.

## See also

[DXGI Enumerations](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-enums)

[xGPU UWP sample](https://github.com/Microsoft/DirectX-Graphics-Samples/tree/develop/Samples/UWP/D3D12xGPU)

[xGPU desktop sample](https://github.com/Microsoft/DirectX-Graphics-Samples/tree/develop/Samples/Desktop/D3D12xGPU)
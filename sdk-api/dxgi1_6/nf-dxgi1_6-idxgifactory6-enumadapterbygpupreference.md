## Description

Enumerates graphics adapters based on a given GPU preference.

## Parameters

### `Adapter` [in]

Type: **UINT**

The index of the adapter to enumerate. The indices are in order of the preference specified in *GpuPreference*—for example, if **DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE** is specified, then the highest-performing adapter is at index 0, the second-highest is at index 1, and so on.

### `GpuPreference` [in]

Type: **[DXGI_GPU_PREFERENCE](https://learn.microsoft.com/windows/win32/api/dxgi1_6/ne-dxgi1_6-dxgi_gpu_preference)**

The GPU preference for the app.

### `riid` [in]

Type: **REFIID**

The globally unique identifier (GUID) of the [IDXGIAdapter](https://learn.microsoft.com/windows/win32/api/dxgi1_6/nn-dxgi1_6-idxgifactory6) object referenced by the *ppvAdapter* parameter.

### `ppvAdapter` [out]

Type: **void****

The address of an [IDXGIAdapter](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgiadapter) interface pointer to the adapter.

This parameter must not be NULL.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful; an error code otherwise. For a list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/win32/direct3ddxgi/dxgi-error).

## Remarks

This method allows developers to select which GPU they think is most appropriate for each device their app creates and utilizes.

This method is similar to [IDXGIFactory1::EnumAdapters1](https://learn.microsoft.com/windows/win32/api/dxgi/nf-dxgi-idxgifactory1-enumadapters1), but it accepts a GPU preference to reorder the adapter enumeration. It returns the appropriate **IDXGIAdapter** for the given GPU preference. It is meant to be used in conjunction with the **D3D*CreateDevice** functions, which take in an **IDXGIAdapter***.

When **DXGI_GPU_PREFERENCE_UNSPECIFIED** is specified for the *GpuPreference* parameter, this method is equivalent to calling [IDXGIFactory1::EnumAdapters1](https://learn.microsoft.com/windows/win32/api/dxgi/nf-dxgi-idxgifactory1-enumadapters1).

When **DXGI_GPU_PREFERENCE_MINIMUM_POWER** is specified for the *GpuPreference* parameter, the order of preference for the adapter returned in *ppvAdapter* will be:

1. iGPUs (integrated GPUs)

2. dGPUs (discrete GPUs)

3. xGPUs (external GPUs)

When **DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE** is specified for the *GpuPreference* parameter, the order of preference for the adapter returned in *ppvAdapter* will be:

1. xGPUs

2. dGPUs

3. iGPUs

## See also

[IDXGIFactory6](https://learn.microsoft.com/windows/win32/api/dxgi1_6/nn-dxgi1_6-idxgifactory6)

[xGPU UWP sample](https://github.com/Microsoft/DirectX-Graphics-Samples/tree/develop/Samples/UWP/D3D12xGPU)

[xGPU desktop sample](https://github.com/Microsoft/DirectX-Graphics-Samples/tree/develop/Samples/Desktop/D3D12xGPU)
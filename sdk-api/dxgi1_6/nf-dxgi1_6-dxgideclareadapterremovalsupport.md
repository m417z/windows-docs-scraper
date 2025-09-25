# DXGIDeclareAdapterRemovalSupport function

## Description

Allows a process to indicate that it's resilient to any of its graphics devices being removed.

## Return value

Type: **HRESULT**

Returns **S_OK** if successful; an error code otherwise. If this function is called after device creation, it returns **DXGI_ERROR_INVALID_CALL**. If this is not the first time that this function is called, it returns **DXGI_ERROR_ALREADY_EXISTS**. For a full list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

This function is graphics API-agnostic, meaning that apps running on other APIs, such as OpenGL and Vulkan, would also apply.

This function should be called once per process and before any device creation.

## See also

[DXGI AdapterRemovalSupport test sample](https://github.com/Microsoft/DirectX-Graphics-Samples/tree/develop/Tools/DXGIAdapterRemovalSupportTest)

[DXGI Functions](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-functions)

[xGPU UWP sample](https://github.com/Microsoft/DirectX-Graphics-Samples/tree/develop/Samples/UWP/D3D12xGPU)

[xGPU desktop sample](https://github.com/Microsoft/DirectX-Graphics-Samples/tree/develop/Samples/Desktop/D3D12xGPU)
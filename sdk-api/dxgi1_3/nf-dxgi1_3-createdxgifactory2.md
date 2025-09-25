## Description

Creates a DXGI 1.3 factory that you can use to generate other DXGI objects.

In Windows 8, any DXGI factory created while DXGIDebug.dll was present on the system would load and use it. Starting in Windows 8.1, apps explicitly request that DXGIDebug.dll be loaded instead. Use **CreateDXGIFactory2** and specify the DXGI_CREATE_FACTORY_DEBUG flag to request DXGIDebug.dll; the DLL will be loaded if it is present on the system.

## Parameters

### `Flags`

Type: **UINT**

Valid values include the **DXGI_CREATE_FACTORY_DEBUG (0x01)** flag, and zero.

**Note** This flag will be set by the D3D runtime if:

* The system creates an implicit factory during device creation.
* The D3D11_CREATE_DEVICE_DEBUG flag is specified during device creation, for example using [D3D11CreateDevice](https://learn.microsoft.com/windows/win32/api/d3d11/nf-d3d11-d3d11createdevice) (or the swapchain method, or the Direct3D 10 equivalents).

### `riid`

Type: **REFIID**

The globally unique identifier (GUID) of the [IDXGIFactory2](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nn-dxgi1_2-idxgifactory2) object referenced by
the *ppFactory* parameter.

### `ppFactory` [out]

Type: **void****

Address of a pointer to an [IDXGIFactory2](https://learn.microsoft.com/windows/win32/api/dxgi1_2/nn-dxgi1_2-idxgifactory2) interface.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns S_OK if successful; an error code otherwise. For a list of error codes, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

This function accepts a flag indicating whether DXGIDebug.dll is loaded. The function otherwise behaves identically to [CreateDXGIFactory1](https://learn.microsoft.com/windows/win32/api/dxgi/nf-dxgi-createdxgifactory1).

## See also

[DXGI Functions](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-functions)
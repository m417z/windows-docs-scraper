# IDXGIAdapter::CheckInterfaceSupport

## Description

Checks whether the system supports a device interface for a graphics component.

## Parameters

### `InterfaceName` [in]

Type: **[REFGUID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/6e7d7108-c213-40bc-8294-ac13fe68fd50)**

The GUID of the interface of the device version for which support is being checked. This should usually be __uuidof(IDXGIDevice), which returns the version number of the Direct3D 9 UMD (user mode driver) binary. Since WDDM 2.3, all driver components within a driver package (D3D9, D3D11, and D3D12) have been required to share a single version number, so this is a good way to query the driver version regardless of which API is being used.

### `pUMDVersion` [out]

Type: **[LARGE_INTEGER](https://learn.microsoft.com/windows/win32/api/winnt/ns-winnt-large_integer-r1)***

The user mode driver version of *InterfaceName*. This is returned only if the interface is supported, otherwise this parameter will be **NULL**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

S_OK indicates that the interface is supported, otherwise DXGI_ERROR_UNSUPPORTED is returned (For more information, see [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error)).

## Remarks

**Note** You can use **CheckInterfaceSupport** only to check whether a Direct3D 10.x interface is supported, and only on Windows Vista SP1 and later versions of the operating system. If you try to use **CheckInterfaceSupport** to check whether a Direct3D 11.x and later version interface is supported, **CheckInterfaceSupport** returns DXGI_ERROR_UNSUPPORTED. Therefore, do not use **CheckInterfaceSupport**. Instead, to verify whether the operating system supports a particular interface, try to create the interface. For example, if you call the [ID3D11Device::CreateBlendState](https://learn.microsoft.com/windows/desktop/api/d3d11/nf-d3d11-id3d11device-createblendstate) method and it fails, the operating system does not support the [ID3D11BlendState](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11blendstate) interface.

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter)
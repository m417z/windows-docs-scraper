# IDXGIObject::GetPrivateData

## Description

Get a pointer to the object's data.

## Parameters

### `Name` [in]

Type: **[REFGUID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/6e7d7108-c213-40bc-8294-ac13fe68fd50)**

A GUID identifying the data.

### `pDataSize` [in, out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

The size of the data.

### `pData` [out]

Type: **void***

Pointer to the data.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## Remarks

If the data returned is a pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown), or one of its derivative classes, previously set by [IDXGIObject::SetPrivateDataInterface](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiobject-setprivatedatainterface), you must call [::Release()](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-release) on the pointer before the pointer is freed to decrement the reference count.

You can pass **GUID_DeviceType** in the *Name* parameter of **GetPrivateData** to retrieve the device type from the display adapter object ([IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter), [IDXGIAdapter1](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter1), [IDXGIAdapter2](https://learn.microsoft.com/windows/desktop/api/dxgi1_2/nn-dxgi1_2-idxgiadapter2)).

**To get the type of device on which the display adapter was created**

1. Call [IUnknown::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) on the [ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device) or [ID3D10Device](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device) object to retrieve the [IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice) object.
2. Call [GetParent](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiobject-getparent) on the [IDXGIDevice](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgidevice) object to retrieve the [IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter) object.
3. Call **GetPrivateData** on the [IDXGIAdapter](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiadapter) object with **GUID_DeviceType** to retrieve the type of device on which the display adapter was created. *pData* will point to a value from the driver-type enumeration (for example, a value from [D3D_DRIVER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_driver_type)).

On Windows 7 or earlier, this type is either a value from [D3D10_DRIVER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3d10misc/ne-d3d10misc-d3d10_driver_type) or [D3D_DRIVER_TYPE](https://learn.microsoft.com/windows/desktop/api/d3dcommon/ne-d3dcommon-d3d_driver_type) depending on which kind of device was created. On Windows 8, this type is always a value from **D3D_DRIVER_TYPE**. Don't use [IDXGIObject::SetPrivateData](https://learn.microsoft.com/windows/desktop/api/dxgi/nf-dxgi-idxgiobject-setprivatedata) with **GUID_DeviceType** because the behavior when doing so is undefined.

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIObject](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiobject)
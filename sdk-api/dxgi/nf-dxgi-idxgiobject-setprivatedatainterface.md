# IDXGIObject::SetPrivateDataInterface

## Description

Set an interface in the object's private data.

## Parameters

### `Name` [in]

Type: **[REFGUID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/6e7d7108-c213-40bc-8294-ac13fe68fd50)**

A GUID identifying the interface.

### `pUnknown` [in]

Type: **const [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown)-derived interface to be associated with the device object. Its reference count is incremented when set, and decremented when either the [IDXGIObject](https://learn.microsoft.com/windows/win32/api/dxgi/nn-dxgi-idxgiobject) is destroyed, or when the data is overwritten by calling [SetPrivateData](https://learn.microsoft.com/windows/win32/api/dxgi/nf-dxgi-idxgiobject-setprivatedata) or **SetPrivateDataInterface** with the same **GUID**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

Returns one of the following [DXGI_ERROR](https://learn.microsoft.com/windows/desktop/direct3ddxgi/dxgi-error).

## See also

[DXGI Interfaces](https://learn.microsoft.com/windows/desktop/direct3ddxgi/d3d10-graphics-reference-dxgi-interfaces)

[IDXGIObject](https://learn.microsoft.com/windows/desktop/api/dxgi/nn-dxgi-idxgiobject)
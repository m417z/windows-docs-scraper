# ID3D11Device::SetPrivateDataInterface

## Description

Associate an IUnknown-derived interface with this device child and associate that interface with an application-defined guid.

## Parameters

### `guid` [in]

Type: **[REFGUID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/6e7d7108-c213-40bc-8294-ac13fe68fd50)**

Guid associated with the interface.

### `pData` [in, optional]

Type: **const IUnknown***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown)-derived interface to be associated with the device object. Its reference count is incremented when set, and decremented when either the [ID3D11Device](https://learn.microsoft.com/windows/win32/api/d3d11/nn-d3d11-id3d11device) is destroyed, or when the data is overwritten by calling [SetPrivateData](https://learn.microsoft.com/windows/win32/api/d3d11/nf-d3d11-id3d11device-setprivatedata) or **SetPrivateDataInterface** with the same **GUID**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 11 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d11/d3d11-graphics-reference-returnvalues).

## See also

[ID3D11Device](https://learn.microsoft.com/windows/desktop/api/d3d11/nn-d3d11-id3d11device)
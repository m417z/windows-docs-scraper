# ID3D10Device::SetPrivateDataInterface

## Description

Associate an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown)-derived interface with this device and associate that interface with an application-defined guid.

## Parameters

### `guid` [in]

Type: **[REFGUID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/6e7d7108-c213-40bc-8294-ac13fe68fd50)**

Guid associated with the interface.

### `pData` [in]

Type: **const IUnknown***

A pointer to the [IUnknown](https://learn.microsoft.com/windows/win32/api/unknwn/nn-unknwn-iunknown)-derived interface to be associated with the device object. Its reference count is incremented when set, and decremented when either the [ID3D10Device](https://learn.microsoft.com/windows/win32/api/d3d10/nn-d3d10-id3d10device) is destroyed, or when the data is overwritten by calling [SetPrivateData](https://learn.microsoft.com/windows/win32/api/d3d10/nf-d3d10-id3d10device-setprivatedata) or **SetPrivateDataInterface** with the same **GUID**.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## See also

[ID3D10Device Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10device)
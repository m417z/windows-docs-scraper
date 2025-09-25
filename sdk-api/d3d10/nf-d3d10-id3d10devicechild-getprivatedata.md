# ID3D10DeviceChild::GetPrivateData

## Description

Get application-defined data from a device child.

## Parameters

### `guid` [in]

Type: **[REFGUID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/6e7d7108-c213-40bc-8294-ac13fe68fd50)**

Guid associated with the data.

### `pDataSize` [in, out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

Size of the data.

### `pData` [out]

Type: **void***

Pointer to the data stored with the device child. If pData is **NULL**, DataSize must also be 0, and any data previously associated with the guid will be destroyed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

If the data returned is a pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown), or one of its derivative classes, which was previously set by **SetPrivateDataInterface**, that interface will have its reference count incremented before the private data is returned.

## See also

[ID3D10DeviceChild Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10devicechild)
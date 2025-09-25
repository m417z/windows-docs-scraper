# ID3D10DeviceChild::SetPrivateData

## Description

Set application-defined data to a device child and associate that data with an application-defined guid.

## Parameters

### `guid` [in]

Type: **[REFGUID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/6e7d7108-c213-40bc-8294-ac13fe68fd50)**

Guid associated with the data.

### `DataSize` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Size of the data.

### `pData` [in]

Type: **const void***

Pointer to the data to be stored with this device child. If pData is **NULL**, DataSize must also be 0, and any data previously associated with the specified guid will be destroyed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the following [Direct3D 10 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d10/d3d10-graphics-reference-returnvalues).

## Remarks

The data stored in the device child with this method can be retrieved with [ID3D10DeviceChild::GetPrivateData](https://learn.microsoft.com/windows/desktop/api/d3d10/nf-d3d10-id3d10devicechild-getprivatedata).

## See also

[ID3D10DeviceChild Interface](https://learn.microsoft.com/windows/desktop/api/d3d10/nn-d3d10-id3d10devicechild)
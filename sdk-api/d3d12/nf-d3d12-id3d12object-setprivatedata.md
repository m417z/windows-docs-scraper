# ID3D12Object::SetPrivateData

## Description

Sets application-defined data to a device object and associates that data with an application-defined **GUID**.

## Parameters

### `guid` [in]

Type: **[REFGUID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/6e7d7108-c213-40bc-8294-ac13fe68fd50)**

The **GUID** to associate with the data.

### `DataSize` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size in bytes of the data.

### `pData` [in, optional]

Type: **const void***

A pointer to a memory block that contains the data to be stored with this device object. If *pData* is **NULL**, *DataSize* must also be 0, and any data that was previously associated with the **GUID** specified in *guid* will be destroyed.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

Rather than using the Direct3D 11 debug object naming scheme of calling **ID3D12Object::SetPrivateData** using **WKPDID_D3DDebugObjectName** with an ASCII name,
call [ID3D12Object::SetName](https://learn.microsoft.com/windows/desktop/api/d3d12/nf-d3d12-id3d12object-setname) with a UNICODE name.

## See also

[ID3D12Object](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12object)
# ID3D12Object::GetPrivateData

## Description

Gets application-defined data from a device object.

## Parameters

### `guid` [in]

Type: **[REFGUID](https://learn.microsoft.com/openspecs/windows_protocols/ms-oaut/6e7d7108-c213-40bc-8294-ac13fe68fd50)**

The **GUID** that is associated with the data.

### `pDataSize` [in, out]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)***

A pointer to a variable that on input contains the size, in bytes, of the buffer that *pData* points to, and on output contains the size, in bytes, of the amount of data that **GetPrivateData** retrieved.

### `pData` [out, optional]

Type: **void***

A pointer to a memory block that receives the data from the device object if *pDataSize* points to a value that specifies a buffer large enough to hold the data.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/win32/com/structure-of-com-error-codes)**

This method returns one of the [Direct3D 12 Return Codes](https://learn.microsoft.com/windows/desktop/direct3d12/d3d12-graphics-reference-returnvalues).

## Remarks

If the data returned is a pointer to an [IUnknown](https://learn.microsoft.com/windows/desktop/api/unknwn/nn-unknwn-iunknown), or one of its derivative classes, which was previously set by **SetPrivateDataInterface**, that interface will have its reference count incremented before the private data is returned.

## See also

[ID3D12Object](https://learn.microsoft.com/windows/desktop/api/d3d12/nn-d3d12-id3d12object)
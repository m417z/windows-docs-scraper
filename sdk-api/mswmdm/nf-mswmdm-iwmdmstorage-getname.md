# IWMDMStorage::GetName

## Description

The **GetName** method retrieves the display name of the storage.

## Parameters

### `pwszName` [out]

Pointer to a wide-character null-terminated string specifying the storage name. This is the display name of the object is the file name without path information. The caller allocates and releases this buffer.

### `nMaxChars` [in]

Integer specifying the maximum number of characters that can be copied to the name string.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## See also

[IWMDMStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage)
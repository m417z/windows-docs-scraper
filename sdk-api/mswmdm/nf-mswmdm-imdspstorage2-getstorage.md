# IMDSPStorage2::GetStorage

## Description

The **GetStorage** method makes it possible to go directly to a storage object from a storage name instead of enumerating through all storages to find it.

## Parameters

### `pszStorageName` [in]

Pointer to a **null**-terminated string containing the storage name.

### `ppStorage` [out]

Pointer to the storage object specified by *pszStorageName*, or **NULL** if no such storage was found.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The **IMDSPStorage2::GetStorage** interface extends the functionality of **IMDSPStorage**.

**IMDSPStorage2::GetStorage** does not support wildcard characters. It is not recursive, that is, it will only find storage objects in the current storage.

If this method is not implemented, it should return E_NOTIMPL. (It should not return WMDM_E_NOT_SUPPORTED or any other codes indicating that this method is not implemented). This will ensure that Windows Media Device Manager will attempt to substitute this functionality itself by enumerating all storages to find a match based on the storage name passed in as *pszStorageName*.

It is strongly recommended that a service provider implement this method to efficiently return a storage object based on name.

This method is optional. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage)

[IMDSPStorage2 Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage2)
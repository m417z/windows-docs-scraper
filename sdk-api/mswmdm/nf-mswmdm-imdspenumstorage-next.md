# IMDSPEnumStorage::Next

## Description

The **Next** method returns a pointer to the next *celt*[IMDSPStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage) interfaces.

## Parameters

### `celt` [in]

Number of storage interfaces requested.

### `ppStorage` [out]

Array of *celt*[IMDSPStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage) interface pointers allocated by the caller. Return **NULL** if no more storage media exist, or an error has occurred. If *celt* is more than 1, the caller must allocate enough memory to store *celt* number of interface pointers.

### `pceltFetched` [out]

Pointer to a **ULONG** variable that receives the count of interfaces returned.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

When there are no more storage interfaces, or when there are fewer storage interfaces than requested, the return value from **Next** is S_FALSE. When this happens, the *pceltFetched* parameter must be queried to determine how many interfaces, if any, were returned.

The storage enumerator may not reflect the effect of media insertion and removal. In such cases, the client should obtain a new enumerator object.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPEnumStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspenumstorage)

[IMDSPStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage)

[IWMDMStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorage)
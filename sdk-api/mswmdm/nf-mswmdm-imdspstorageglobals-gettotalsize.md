# IMDSPStorageGlobals::GetTotalSize

## Description

The **GetTotalSize** method retrieves the total size, in bytes, of the medium associated with this **IMDSPStorageGlobals** interface.

## Parameters

### `pdwTotalSizeLow` [out]

Pointer to a **DWORD** containing the low-order bytes of the total size of the medium.

### `pdwTotalSizeHigh` [out]

Pointer to a **DWORD** containing the high-order bytes of the total size of the medium.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorageglobals)

[IMDSPStorageGlobals::GetTotalFree](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorageglobals-gettotalfree)
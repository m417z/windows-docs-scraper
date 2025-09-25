# IMDSPStorageGlobals::GetTotalBad

## Description

The **GetTotalBad** method retrieves the total amount of unusable space on the storage medium, in bytes.

## Parameters

### `pdwBadLow` [out]

Pointer to a **DWORD** containing the low-order bytes of the unusable space.

### `pdwBadHigh` [out]

Pointer to a **DWORD** containing the high-order bytes of the unusable space.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

To determine the amount of storage space in use by the medium for file management, subtract the number of bad bytes identified by using **GetTotalBad** from the number of free bytes identified by using **GetTotalFree**.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorageglobals)
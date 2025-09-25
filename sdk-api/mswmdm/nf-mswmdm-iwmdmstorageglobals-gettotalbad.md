# IWMDMStorageGlobals::GetTotalBad

## Description

The **GetTotalBad** method retrieves the total amount of unusable space on the storage medium, in bytes.

## Parameters

### `pdwBadLow` [out]

Pointer to a **DWORD** that receives the low-order bytes of unusable space.

### `pdwBadHigh` [out]

Pointer to a **DWORD** that receives the high-order bytes of unusable space.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

To determine the amount of storage space in use by the medium for file management, subtract the number of bad bytes retrieved using **GetTotalBad** from the number of free bytes retrieved using [GetTotalFree](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorageglobals-gettotalfree).

## See also

[IWMDMStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals)

[IWMDMStorageGlobals::GetTotalFree](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorageglobals-gettotalfree)
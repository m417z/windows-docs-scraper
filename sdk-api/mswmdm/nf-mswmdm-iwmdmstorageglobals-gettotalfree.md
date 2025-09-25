# IWMDMStorageGlobals::GetTotalFree

## Description

The **GetTotalFree** method retrieves the total amount of free space on the storage medium, in bytes.

## Parameters

### `pdwFreeLow` [out]

Pointer to a **DWORD** that receives the low-order part of the free space value.

### `pdwFreeHigh` [out]

Pointer to a **DWORD** that receives the high-order part of the free space value.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

To determine the amount of storage space in use by the medium for file management, subtract the number of bad bytes retrieved using [GetTotalBad](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorageglobals-gettotalbad) from the number of free bytes retrieved using **GetTotalFree**.

## See also

[IWMDMStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals)

[IWMDMStorageGlobals::GetTotalBad](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorageglobals-gettotalbad)

[IWMDMStorageGlobals::GetTotalSize](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorageglobals-gettotalsize)
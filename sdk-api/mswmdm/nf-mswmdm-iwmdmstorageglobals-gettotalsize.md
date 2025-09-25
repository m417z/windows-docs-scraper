# IWMDMStorageGlobals::GetTotalSize

## Description

The **GetTotalSize** method retrieves the total size in bytes of the storage medium associated with the **IWMDMStorageGlobals** interface.

## Parameters

### `pdwTotalSizeLow` [out]

Pointer to a **DWORD** that receives the low-order value of the total size of the medium.

### `pdwTotalSizeHigh` [out]

Pointer to a **DWORD** that receives the high-order value of the total size of the medium.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## See also

[IWMDMStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals)

[IWMDMStorageGlobals::GetTotalFree](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-iwmdmstorageglobals-gettotalfree)
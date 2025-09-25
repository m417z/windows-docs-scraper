# IWMDMEnumStorage::Skip

## Description

The **Skip** method skips over the specified number of storages in the enumeration sequence.

## Parameters

### `celt` [in]

The number of storages to skip.

### `pceltFetched` [out]

The number of storages skipped.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

If the number of devices specified in *celt* is greater than the actual number of storage interfaces remaining in the enumeration sequence, this function will return S_FALSE. When this happens, *pceltFetched* must be queried to determine how many interfaces were actually skipped. If you skip to the end of the array of storage interfaces, a subsequent call to **Next** returns S_FALSE.

## See also

[IWMDMEnumStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumstorage)
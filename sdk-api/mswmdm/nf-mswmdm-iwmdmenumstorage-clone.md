# IWMDMEnumStorage::Clone

## Description

The **Clone** method creates another enumerator with the same enumeration state as the current enumerator.

## Parameters

### `ppEnumStorage` [out]

An [IWMDMEnumStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumstorage) interface of the cloned enumerator. The caller must release this interface when done with it.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Using this function, a client can record a particular point in the enumeration sequence and return to that point later. The new enumerator supports the same interface as the original enumerator.

## See also

[IWMDMEnumStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmenumstorage)
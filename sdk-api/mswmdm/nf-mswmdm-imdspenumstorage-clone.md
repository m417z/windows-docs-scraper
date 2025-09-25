# IMDSPEnumStorage::Clone

## Description

The **Clone** method creates another enumerator that contains the same enumeration state as the current one.

## Parameters

### `ppEnumStorage` [out]

Pointer to an [IMDSPEnumStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspenumstorage) interface.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Using this function, a client can record a particular point in the enumeration sequence, and return to that point at a later time. The new enumerator supports the same interface as the original one.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPEnumStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspenumstorage)
# IMDSPDevice::EnumStorage

## Description

The **EnumStorage** method retrieves a pointer to an **IMDSPEnumStorage** interface of an enumerator object that represents the top-level storage(s) on the device. Top-level storage for a device is the root directory of the storage medium.

## Parameters

### `ppEnumStorage` [out]

Pointer to an [IMDSPEnumStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspenumstorage) object.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPDevice Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspdevice)
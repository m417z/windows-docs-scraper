# IMDSPStorage::EnumStorage

## Description

The **EnumStorage** method accesses the **IMDSPEnumStorage** interface to enumerate the individual storage media on a device.

## Parameters

### `ppEnumStorage` [out]

Pointer to an **IMDSPEnumStorage** interface.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The **IMDSPEnumStorage** interface returned will enumerate the nested storages in the storage that **IMDSPStorage** corresponds to. Thus all the storage objects in a hierarchical structure can be retrieved recursively.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPDevice::EnumStorage](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspdevice-enumstorage)

[IMDSPEnumStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspenumstorage)

[IMDSPStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage)
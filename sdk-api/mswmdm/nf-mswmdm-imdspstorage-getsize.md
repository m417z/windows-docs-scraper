# IMDSPStorage::GetSize

## Description

The **GetSize** method retrieves the size of the storage object, in bytes.

## Parameters

### `pdwSizeLow` [out]

Pointer to a **DWORD** containing the low-order part of the storage object size.

### `pdwSizeHigh` [out]

Pointer to a **DWORD** containing the high-order part of the storage object size.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The object size is reported in bytes. The size is zero for folder objects.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage)

[IMDSPStorage::GetDate](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage-getdate)

[IMDSPStorage::GetName](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage-getname)
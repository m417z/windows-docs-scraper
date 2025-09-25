# IMDSPStorage::GetDate

## Description

The **GetDate** method retrieves the date on which the storage object (file or folder) was most recently modified.

## Parameters

### `pDateTimeUTC` [out]

Pointer to a **WMDMDATETIME** structure containing the date on which the file or folder was most recently modified.

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

The time is specified in coordinated universal time.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPStorage Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorage)

[IMDSPStorage::GetName](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage-getname)

[IMDSPStorage::GetSize](https://learn.microsoft.com/windows/desktop/api/mswmdm/nf-mswmdm-imdspstorage-getsize)

[WMDMDATETIME](https://learn.microsoft.com/windows/desktop/WMDM/wmdmdatetime)
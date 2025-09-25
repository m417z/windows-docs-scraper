# IWMDMStorageGlobals::GetCapabilities

## Description

The **GetCapabilities** method retrieves the capabilities of the root storage medium.

## Parameters

### `pdwCapabilities` [out]

Pointer to a **DWORD** containing a bitwise **OR** of zero or more of the following values.

| Capability code | Description |
| --- | --- |
| WMDM_STORAGECAP_FOLDERSINROOT | The medium supports folders in the root of storage. |
| WMDM_STORAGECAP_FILESINROOT | The medium supports files in the root of storage. |
| WMDM_STORAGECAP_FOLDERSINFOLDERS | The medium supports nested folders. |
| WMDM_STORAGECAP_FILESINFOLDERS | The medium supports files in folders. |
| WMDM_STORAGECAP_FOLDERLIMITEXISTS | There is an arbitrary count limit for the number of folders allowed per the form of folder support by the medium. |
| WMDM_STORAGECAP_FILELIMITEXISTS | There is an arbitrary count limit for the number of files allowed per the form of file support by the medium. |
| WMDM_STORAGECAP_NOT_INITIALIZABLE | The medium can not be initialized. The top-level storage can be formatted by default. |

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## See also

[IWMDMStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-iwmdmstorageglobals)
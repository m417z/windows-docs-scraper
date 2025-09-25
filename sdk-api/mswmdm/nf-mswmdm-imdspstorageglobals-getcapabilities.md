# IMDSPStorageGlobals::GetCapabilities

## Description

The **GetCapabilities** method retrieves the capabilities of the storage medium that an instance of this interface is associated with.

## Parameters

### `pdwCapabilities` [out]

Pointer to a **DWORD** containing the capabilities of the storage medium.

The following flags can be returned in the *pdwCapabilities* parameter.

| Flag | Description |
| --- | --- |
| WMDM_STORAGECAP_FOLDERSINROOT | The medium supports folders in the root of storage. |
| WMDM_STORAGECAP_FILESINROOT | The medium supports files in the root of storage. |
| WMDM_STORAGECAP_FOLDERSINFOLDERS | The medium supports folders in folders. |
| WMDM_STORAGECAP_FILESINFOLDERS | The medium supports files in folders. |
| WMDM_STORAGECAP_FOLDERLIMITEXISTS | There is an arbitrary count limit for the number of folders allowed per the form of folder support by the medium. |
| WMDM_STORAGECAP_FILELIMITEXISTS | There is an arbitrary count limit for the number of files allowed per the form of file support by the medium. |
| WMDM_STORAGECAP_NOT_INITIALIZABLE | The medium cannot be initialized. By default, the top-level storage can be initialized. |

For secured device implementations, the following flags describing the rights capabilities of the medium can also be returned.

| Flag | Description |
| --- | --- |
| WMDM_RIGHTS_PLAYBACKCOUNT | The medium supports playback count limiting for content. |
| WMDM_RIGHTS_EXPIRATIONDATE | The medium supports expiration date tracking for content. |
| WMDM_RIGHTS_FREESERIALIDS | The medium supports a free serial identifier for the file. |
| WMDM_RIGHTS_GROUPID | The medium supports a group identifier for the file. |
| WMDM_RIGHTS_NAMEDSERIALIDS | The medium supports a named serial identifier for the file. |

## Return value

The method returns an **HRESULT**. All the interface methods in Windows Media Device Manager can return any of the following classes of error codes:

* Standard COM error codes
* Windows error codes converted to HRESULT values
* Windows Media Device Manager error codes

For an extensive list of possible error codes, see [Error Codes](https://learn.microsoft.com/windows/desktop/WMDM/error-codes).

## Remarks

Attempts to perform unsupported operations on the storage medium with the **IMDSPObject** interface return an error code. The **GetCapabilities** method can be called in order to determine whether an operation can be expected to succeed under normal circumstances.

If either the WMDM_STORAGECAP_FILELIMITEXISTS flag or the WMDM_STORAGECAP_FOLDERLIMITEXISTS flag is true, there are arbitrary limits on the number of files or folders that can be created. Operations through the **IMDSPObject** interface that exceed these limits will fail.

This method must be implemented. It must not return WMDM_E_NOTSUPPORTED or E_NOTIMPL. For more information, see [Mandatory and Optional Interfaces](https://learn.microsoft.com/windows/desktop/WMDM/mandatory-and-optional-interfaces).

## See also

[IMDSPStorageGlobals Interface](https://learn.microsoft.com/windows/desktop/api/mswmdm/nn-mswmdm-imdspstorageglobals)
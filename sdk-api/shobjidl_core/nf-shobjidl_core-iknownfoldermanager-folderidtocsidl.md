# IKnownFolderManager::FolderIdToCsidl

## Description

Gets the legacy [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) value that is the equivalent of a given [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid).

## Parameters

### `rfid` [in]

Type: **REFKNOWNFOLDERID**

Reference to the [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid).

### `pnCsidl` [out]

Type: **int***

When this method returns, contains a pointer to the [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) value. This pointer is passed uninitialized.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Among other things, this value can indicate that the *rfid* parameter references a [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) that is not present on the system. Not all **KNOWNFOLDERID** values are present on all systems. Use [IKnownFolderManager::GetFolderIds](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfoldermanager-getfolderids) to retrieve the set of **KNOWNFOLDERID** values for the current system. |

## Remarks

To call this method, the caller must have at least User privileges.

## See also

[IKnownFolderManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfoldermanager)

[IKnownFolderManager::FolderIdFromCsidl](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfoldermanager-folderidfromcsidl)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))
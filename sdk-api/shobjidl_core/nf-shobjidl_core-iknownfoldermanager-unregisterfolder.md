# IKnownFolderManager::UnregisterFolder

## Description

Remove a known folder from the registry, which makes it unknown to the known folder system. This method does not remove the folder itself.

## Parameters

### `rfid` [in]

Type: **REFKNOWNFOLDERID**

**GUID** or [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) that represents the known folder.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Among other things, this value can indicate that the *rfid* parameter references a [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) that is not present on the system. Not all **KNOWNFOLDERID** values are present on all systems. Use [IKnownFolderManager::GetFolderIds](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfoldermanager-getfolderids) to retrieve the set of **KNOWNFOLDERID** values known to the current system. |

## Remarks

**Note** This method updates **HKEY_LOCAL_MACHINE** and needs to be run in the context of an administrator. Setup programs need administrator privileges to register or unregister a known folder.

## See also

[IKnownFolderManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfoldermanager)

[IKnownFolderManager::RegisterFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfoldermanager-registerfolder)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))
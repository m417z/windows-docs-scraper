# IKnownFolderManager::GetFolder

## Description

Gets an object that represents a known folder identified by its [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid). The object allows you to query certain folder properties, get the current path of the folder, redirect the folder to another location, and get the path of the folder as an [ITEMIDLIST](https://learn.microsoft.com/windows/desktop/api/shtypes/ns-shtypes-itemidlist).

## Parameters

### `rfid` [in]

Type: **REFKNOWNFOLDERID**

Reference to the [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid).

### `ppkf` [out]

Type: **[IKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfolder)****

When this method returns, contains an interface pointer to the [IKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfolder) object that represents the folder.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise, including the following:

| Return code | Description |
| --- | --- |
| **E_INVALIDARG** | Among other things, this value can indicate that the *rfid* parameter references a [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) that is not present on the system. Not all **KNOWNFOLDERID** values are present on all systems. Use [IKnownFolderManager::GetFolderIds](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfoldermanager-getfolderids) to retrieve the set of **KNOWNFOLDERID** values for the current system. |

## Remarks

To call this method, the caller must have at least User privileges.

### When to Use

Use this method when you know exactly which known folder you are looking for and want to access it directly.

## See also

[IKnownFolderManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfoldermanager)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))
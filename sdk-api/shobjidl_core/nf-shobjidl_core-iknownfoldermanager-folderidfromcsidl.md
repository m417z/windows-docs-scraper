# IKnownFolderManager::FolderIdFromCsidl

## Description

Gets the [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) that is the equivalent of a legacy [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) value.

## Parameters

### `nCsidl` [in]

Type: **int**

The [CSIDL](https://learn.microsoft.com/windows/desktop/shell/csidl) value.

### `pfid` [out]

Type: **[KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid)***

When this method returns, contains a pointer to the [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid). This pointer is passed uninitialized.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

To call this method, the caller must have at least User privileges.

## See also

[IKnownFolderManager](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfoldermanager)

[IKnownFolderManager::FolderIdToCsidl](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-iknownfoldermanager-folderidtocsidl)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))
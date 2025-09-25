# IKnownFolder::GetId

## Description

Gets the ID of the selected folder.

## Parameters

### `pkfid` [out]

Type: **[KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid)***

When this method returns, returns the [KNOWNFOLDERID](https://learn.microsoft.com/windows/desktop/shell/knownfolderid) value of the known folder. Note, **KNOWNFOLDERID** values are GUIDs.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfolder)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))
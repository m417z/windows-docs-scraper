# IKnownFolder::GetFolderType

## Description

Retrieves the folder type.

## Parameters

### `pftid` [out]

Type: **[FOLDERTYPEID](https://learn.microsoft.com/windows/desktop/shell/foldertypeid)***

When this returns, contains a pointer to a [FOLDERTYPEID](https://learn.microsoft.com/windows/desktop/shell/foldertypeid) (a GUID) that identifies the known folder type.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IKnownFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-iknownfolder)

[Known Folders Sample](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd940364(v=vs.85))
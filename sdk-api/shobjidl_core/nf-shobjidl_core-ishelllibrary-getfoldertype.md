# IShellLibrary::GetFolderType

## Description

Gets the library's folder type.

## Parameters

### `pftid` [out]

Type: **[FOLDERTYPEID](https://learn.microsoft.com/windows/desktop/shell/foldertypeid)***

The view template that is applied to a folder, usually based on its intended use and contents.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The folder type determines the default view template that is used by the folder. A view template specifies the columns and details that appear by default in the Windows Explorer view of the folder.

[FOLDERTYPEID](https://learn.microsoft.com/windows/desktop/shell/foldertypeid) values are GUID values that are defined in shlguid.h.

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[Library Description Schema](https://learn.microsoft.com/windows/desktop/shell/library-schema-entry)

[Windows Libraries](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd758096(v=vs.85))

[folderType Element (Library Schema)](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd798386(v=vs.85))
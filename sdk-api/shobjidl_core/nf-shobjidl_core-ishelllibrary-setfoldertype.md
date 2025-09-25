# IShellLibrary::SetFolderType

## Description

Sets the library's folder type.

## Parameters

### `ftid` [in]

Type: **REFFOLDERTYPEID**

The **GUID** or [FOLDERTYPEID](https://learn.microsoft.com/windows/desktop/shell/foldertypeid) that represents the view template that is applied to a folder, usually based on its intended use and contents.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The folder type determines the default view template that is used by the folder. A view template specifies the columns and details that appear by default in Windows Explorer by default view of the folder. [FOLDERTYPEID](https://learn.microsoft.com/windows/desktop/shell/foldertypeid) values are GUID values that are defined in shlguid.h.

## See also

[IShellLibrary](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishelllibrary)

[Windows Libraries](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd758096(v=vs.85))

[folderType Element (Library Schema)](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd798386(v=vs.85))
# IShellFolderViewDual::PopupItemMenu

## Description

Creates a shortcut menu for the specified item and returns the selected command string.

## Parameters

### `pfi` [in, optional]

Type: **[FolderItem](https://learn.microsoft.com/windows/win32/shell/folderitem)***

The FolderItem for which to create a shortcut menu.

### `vx` [in, optional]

Type: **VARIANT**

Optional.

### `vy` [in, optional]

Type: **VARIANT**

Optional.

### `pbs` [out]

Type: **[BSTR](https://learn.microsoft.com/previous-versions/windows/desktop/automat/bstr)***

The command string.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IShellFolderViewDual](https://learn.microsoft.com/windows/desktop/api/shldisp/nn-shldisp-ishellfolderviewdual)

[IShellFolderViewDual2](https://learn.microsoft.com/windows/desktop/api/shldisp/nn-shldisp-ishellfolderviewdual2)

[IShellFolderViewDual3](https://learn.microsoft.com/windows/desktop/api/shldisp/nn-shldisp-ishellfolderviewdual3)
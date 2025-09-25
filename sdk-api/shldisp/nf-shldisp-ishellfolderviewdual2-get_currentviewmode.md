# IShellFolderViewDual2::get_CurrentViewMode

## Description

Gets the current view mode of the current folder.

## Parameters

### `pViewMode` [out]

Type: **uint***

When this method returns, contains a pointer to an unsigned integer that represents the current view mode. For a list of possible values see [FOLDERVIEWMODE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderviewmode).

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## See also

[IShellFolderViewDual2](https://learn.microsoft.com/windows/desktop/api/shldisp/nn-shldisp-ishellfolderviewdual2)

[IShellFolderViewDual2::put_CurrentViewMode](https://learn.microsoft.com/windows/desktop/api/shldisp/nf-shldisp-ishellfolderviewdual2-put_currentviewmode)
# SFV_CREATE structure

## Description

This structure is used with the [SHCreateShellFolderView](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreateshellfolderview) function.

## Members

### `cbSize`

Type: **UINT**

The size of the **SFV_CREATE** structure, in bytes.

### `pshf`

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

The [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) interface of the folder for which to create the view.

### `psvOuter`

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

A pointer to the parent [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) interface. This parameter may be **NULL**. This parameter is used only when the view created by [SHCreateShellFolderView](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreateshellfolderview) is hosted in a common dialog box.

### `psfvcb`

Type: **[IShellFolderViewCB](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishellfolderviewcb)***

A pointer to the [IShellFolderViewCB](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishellfolderviewcb) interface that handles the view's callbacks when various events occur. This parameter may be **NULL**.

## See also

[ICommDlgBrowser](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-icommdlgbrowser)
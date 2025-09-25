# CSFV structure

## Description

Used with the [SHCreateShellFolderViewEx](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-shcreateshellfolderviewex) function.

## Members

### `cbSize`

Type: **UINT**

The size of the **CSFV** structure, in bytes.

### `pshf`

Type: **[IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder)***

A pointer to the [IShellFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellfolder) object for which to create the view.

### `psvOuter`

Type: **[IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview)***

A pointer to the parent [IShellView](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellview) interface. This parameter can be **NULL**.

### `pidl`

Type: **PCIDLIST_ABSOLUTE**

Ignored.

### `lEvents`

Type: **LONG**

### `pfnCallback`

Type: **[LPFNVIEWCALLBACK](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nc-shlobj_core-lpfnviewcallback)**

A pointer to the [LPFNVIEWCALLBACK](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nc-shlobj_core-lpfnviewcallback) function used by this folder view to handle callback messages. This parameter can be **NULL**.

### `fvm`

Type: **[FOLDERVIEWMODE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-folderviewmode)**
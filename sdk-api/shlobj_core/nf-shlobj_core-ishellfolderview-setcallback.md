# IShellFolderView::SetCallback

## Description

[**IShellFolderView::SetCallback** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

Replaces the callback object used by the view.

## Parameters

### `pNewCB` [in, optional]

Type: **[IShellFolderViewCB](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishellfolderviewcb)***

A pointer to the new [IShellFolderViewCB](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishellfolderviewcb) callback object.

### `ppOldCB` [out, optional]

Type: **[IShellFolderViewCB](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishellfolderviewcb)****

The address of an interface pointer that, when this method returns successfully, points to the original [IShellFolderViewCB](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-ishellfolderviewcb) object.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.
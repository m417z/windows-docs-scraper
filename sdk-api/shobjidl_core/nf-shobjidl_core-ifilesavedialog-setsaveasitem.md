# IFileSaveDialog::SetSaveAsItem

## Description

Sets an item to be used as the initial entry in a **Save As** dialog.

## Parameters

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

Pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that represents the item.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The name of the item is displayed in the file name edit box, and the containing folder is opened in the view. This would generally be used when the application is saving an item that already exists. For new items, use [IFileDialog::SetFileName](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-setfilename).
# IFileOpenDialog::GetResults

## Description

Gets the user's choices in a dialog that allows multiple selection.

## Parameters

### `ppenum` [out]

Type: **[IShellItemArray](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitemarray)****

The address of a pointer to an **IShellItemArray** through which the items selected in the dialog can be accessed.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method can be used whether the selection consists of a single item or multiple items.

**IFileOpenDialog::GetResults** can be called after the dialog has closed or during the handling of an IFileDialogEvents::OnFileOk event. Calling this method at any other time will fail.

[Show](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-imodalwindow-show) must return a success code for a result to be available to **IFileOpenDialog::GetResults**.
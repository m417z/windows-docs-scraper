# IFileDialog::GetFolder

## Description

Gets either the folder currently selected in the dialog, or, if the dialog is not currently displayed, the folder that is to be selected when the dialog is opened.

## Parameters

### `ppsi` [out]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)****

The address of a pointer to the interface that represents the folder.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The calling application is responsible for releasing the retrieved [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) when it is no longer needed.
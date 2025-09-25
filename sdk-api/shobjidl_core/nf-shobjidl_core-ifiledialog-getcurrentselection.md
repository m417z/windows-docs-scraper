# IFileDialog::GetCurrentSelection

## Description

Gets the user's current selection in the dialog.

## Parameters

### `ppsi` [out]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)****

The address of a pointer to the interface that represents the item currently selected in the dialog. This item can be a file or folder selected in the view window, or something that the user has entered into the dialog's edit box. The latter case may require a parsing operation (cancelable by the user) that blocks the current thread.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

The calling application is responsible for releasing the retrieved [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) when it is no longer needed.

## See also

[IFileDialog](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialog)

[IFileDialog::GetResult](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-getresult)
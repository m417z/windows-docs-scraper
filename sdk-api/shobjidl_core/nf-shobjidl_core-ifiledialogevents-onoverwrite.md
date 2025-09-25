# IFileDialogEvents::OnOverwrite

## Description

Called from the save dialog when the user chooses to overwrite a file.

## Parameters

### `pfd` [in]

Type: **[IFileDialog](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialog)***

A pointer to the interface that represents the dialog.

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the interface that represents the item that will be overwritten.

### `pResponse` [out]

Type: **[FDE_OVERWRITE_RESPONSE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-fde_overwrite_response)***

A pointer to a value from the [FDE_OVERWRITE_RESPONSE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-fde_overwrite_response) enumeration indicating the response to the potential overwrite action.

## Return value

Type: **HRESULT**

The implementer should return E_NOTIMPL if this method is not implemented; S_OK or an appropriate error code otherwise.

## Remarks

The **FOS_OVERWRITEPROMPT** flag must be set through [IFileDialog::SetOptions](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-setoptions) before this method is called.
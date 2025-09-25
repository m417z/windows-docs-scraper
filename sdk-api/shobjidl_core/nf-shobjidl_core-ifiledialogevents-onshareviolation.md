# IFileDialogEvents::OnShareViolation

## Description

Enables an application to respond to sharing violations that arise from Open or Save operations.

## Parameters

### `pfd` [in]

Type: **[IFileDialog](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialog)***

A pointer to the interface that represents the dialog.

### `psi` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to the interface that represents the item that has the sharing violation.

### `pResponse` [out]

Type: **[FDE_SHAREVIOLATION_RESPONSE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-fde_shareviolation_response)***

A pointer to a value from the [FDE_SHAREVIOLATION_RESPONSE](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/ne-shobjidl_core-fde_shareviolation_response) enumeration indicating the response to the sharing violation.

## Return value

Type: **HRESULT**

The implementer should return E_NOTIMPL if this method is not implemented; S_OK or an appropriate error code otherwise.

## Remarks

The **FOS_SHAREAWARE** flag must be set through [IFileDialog::SetOptions](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-setoptions) before this method is called.

A sharing violation could possibly arise when the application attempts to open a file, because the file could have been locked between the time that the dialog tested it and the application opened it.
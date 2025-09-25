# IFileDialog::Advise

## Description

Assigns an event handler that listens for events coming from the dialog.

## Parameters

### `pfde` [in]

Type: **[IFileDialogEvents](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialogevents)***

A pointer to an [IFileDialogEvents](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialogevents) implementation that will receive events from the dialog.

### `pdwCookie` [out]

Type: **DWORD***

A pointer to a **DWORD** that receives a value identifying this event handler. When the client is finished with the dialog, that client must call the [IFileDialog::Unadvise](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-unadvise) method with this value.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.
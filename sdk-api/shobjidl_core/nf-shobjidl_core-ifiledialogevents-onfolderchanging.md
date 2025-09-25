# IFileDialogEvents::OnFolderChanging

## Description

Called before [IFileDialogEvents::OnFolderChange](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialogevents-onfolderchange). This allows the implementer to stop navigation to a particular location.

## Parameters

### `pfd` [in]

Type: **[IFileDialog](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialog)***

A pointer to the interface that represents the dialog.

### `psiFolder` [in]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)***

A pointer to an interface that represents the folder to which the dialog is about to navigate.

## Return value

Type: **HRESULT**

Returns S_OK if successful, or an error value otherwise. A return value of S_OK or E_NOTIMPL indicates that the folder change can proceed.

## Remarks

The calling application can call [IFileDialog::SetFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-setfolder) during this callback to redirect navigation to an alternate folder. The actual navigation does not occur until **IFileDialogEvents::OnFolderChanging** has returned.

If the calling application simply prevents navigation to a particular folder, UI should be displayed with an explanation of the restriction. To obtain a parent **HWND** for the UI, obtain the [IOleWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolewindow) interface through [IFileDialog](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialog) and call [IOleWindow::GetWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolewindow-getwindow).
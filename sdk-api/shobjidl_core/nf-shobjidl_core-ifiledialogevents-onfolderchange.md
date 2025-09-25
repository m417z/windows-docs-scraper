# IFileDialogEvents::OnFolderChange

## Description

Called when the user navigates to a new folder.

## Parameters

### `pfd` [in]

Type: **[IFileDialog](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialog)***

A pointer to the interface that represents the dialog.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IFileDialogEvents::OnFolderChange** is called when the dialog is opened.

## See also

[IFileDialog::GetFolder](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-getfolder)

[IFileDialogEvents](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialogevents)

[IFileDialogEvents::OnFolderChanging](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialogevents-onfolderchanging)
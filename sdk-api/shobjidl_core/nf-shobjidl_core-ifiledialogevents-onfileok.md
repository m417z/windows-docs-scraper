# IFileDialogEvents::OnFileOk

## Description

Called just before the dialog is about to return with a result.

## Parameters

### `pfd` [in]

Type: **[IFileDialog](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialog)***

A pointer to the interface that represents the dialog.

## Return value

Type: **HRESULT**

Implementations should return **S_OK** to accept the current result in the dialog or **S_FALSE** to refuse it. In the case of **S_FALSE**, the dialog should remain open.

## Remarks

When this method is called, the [IFileDialog::GetResult](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-getresult) and [GetResults](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileopendialog-getresults) methods can be called.

The application can use this callback method to perform additional validation before the dialog closes, or to prevent the dialog from closing. If the application prevents the dialog from closing, it should display a UI to indicate a cause. To obtain a parent **HWND** for the UI, obtain the [IOleWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nn-oleidl-iolewindow) interface through [IFileDialog::QueryInterface](https://learn.microsoft.com/windows/desktop/api/unknwn/nf-unknwn-iunknown-queryinterface(q)) and call [IOleWindow::GetWindow](https://learn.microsoft.com/windows/desktop/api/oleidl/nf-oleidl-iolewindow-getwindow).

An application can also use this method to perform all of its work surrounding the opening or saving of files.
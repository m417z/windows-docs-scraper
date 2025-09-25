# IFileDialog::Close

## Description

Closes the dialog.

## Parameters

### `hr` [in]

Type: **HRESULT**

The code that will be returned by [Show](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-imodalwindow-show) to indicate that the dialog was closed before a selection was made.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

An application can call this method from a callback method or function while the dialog is open. The dialog will close and the [Show](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-imodalwindow-show) method will return with the **HRESULT** specified in *hr*.

If this method is called, there is no result available for the [IFileDialog::GetResult](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-getresult) or [GetResults](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileopendialog-getresults) methods, and they will fail if called.
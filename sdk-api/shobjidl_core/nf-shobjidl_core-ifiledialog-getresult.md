# IFileDialog::GetResult

## Description

Gets the choice that the user made in the dialog.

## Parameters

### `ppsi` [out]

Type: **[IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem)****

The address of a pointer to an [IShellItem](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ishellitem) that represents the user's choice.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

**IFileDialog::GetResult** can be called after the dialog has closed or during the handling of an [OnFileOk](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialogevents-onfileok) event. Calling this method at any other time will fail. If multiple items were chosen, this method will fail. In the case of multiple items, call [GetResults](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifileopendialog-getresults)

[Show](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-imodalwindow-show) must return a success code for a result to be available to **IFileDialog::GetResult**.

## See also

[IFileDialog](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nn-shobjidl_core-ifiledialog)

[IFileDialog::GetCurrentSelection](https://learn.microsoft.com/windows/desktop/api/shobjidl_core/nf-shobjidl_core-ifiledialog-getcurrentselection)
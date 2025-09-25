# IProgressDialog::SetCancelMsg

## Description

Sets a message to be displayed if the user cancels the operation.

## Parameters

### `pwzCancelMsg` [in]

Type: **PCWSTR**

A pointer to a null-terminated Unicode string that contains the message to be displayed.

### `pvResevered`

Type: **LPCVOID**

Reserved. Set to **NULL**.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Even though the user clicks **Cancel**, the application cannot immediately call [IProgressDialog::StopProgressDialog](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iprogressdialog-stopprogressdialog) to close the dialog box. The application must wait until the next time it calls [IProgressDialog::HasUserCancelled](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iprogressdialog-hasusercancelled) to discover that the user has canceled the operation. Since this delay might be significant, the progress dialog box provides the user with immediate feedback by clearing text lines 1 and 2 and displaying the cancel message on line 3. The message is intended to let the user know that the delay is normal and that the progress dialog box will be closed shortly. It is typically is set to something like "Please wait while ...".

## See also

[IProgressDialog](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iprogressdialog)
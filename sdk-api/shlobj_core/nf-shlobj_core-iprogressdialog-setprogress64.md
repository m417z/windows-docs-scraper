# IProgressDialog::SetProgress64

## Description

Updates the progress dialog box with the current state of the operation.

## Parameters

### `ullCompleted` [in]

Type: **ULONGLONG**

An application-defined value that indicates what proportion of the operation has been completed at the time the method was called.

### `ullTotal` [in]

Type: **ULONGLONG**

An application-defined value that specifies what value *ullCompleted* will have when the operation is complete.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

This method has exactly the same function as [IProgressDialog::SetProgress](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iprogressdialog-setprogress) but allows you to use values larger than one **DWORD** (4 GB).

## See also

[IProgressDialog](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iprogressdialog)
# IProgressDialog::SetProgress

## Description

Updates the progress dialog box with the current state of the operation.

## Parameters

### `dwCompleted` [in]

Type: **DWORD**

An application-defined value that indicates what proportion of the operation has been completed at the time the method was called.

### `dwTotal` [in]

Type: **DWORD**

An application-defined value that specifies what value *dwCompleted* will have when the operation is complete.

## Return value

Type: **HRESULT**

If this method succeeds, it returns **S_OK**. Otherwise, it returns an **HRESULT** error code.

## Remarks

Use any convenient numerical measure of the progress of the operation. To use values larger than 4 gigabytes (GB), you can instead call [IProgressDialog::SetProgress64](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nf-shlobj_core-iprogressdialog-setprogress64).

## See also

[IProgressDialog](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iprogressdialog)
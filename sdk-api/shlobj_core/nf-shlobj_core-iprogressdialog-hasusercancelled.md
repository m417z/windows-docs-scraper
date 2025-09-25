# IProgressDialog::HasUserCancelled

## Description

Checks whether the user has canceled the operation.

## Return value

Type: **BOOL**

**TRUE** if the user has canceled the operation; otherwise, **FALSE**.

## Remarks

The system does not send a message to the application when the user clicks the **Cancel** button. You must periodically use this function to poll the progress dialog box object to determine whether the operation has been canceled.

## See also

[IProgressDialog](https://learn.microsoft.com/windows/desktop/api/shlobj_core/nn-shlobj_core-iprogressdialog)
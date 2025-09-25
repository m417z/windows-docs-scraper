# GetDialogDpiChangeBehavior function

## Description

Returns the flags that might have been set on a given dialog by an earlier call to [SetDialogDpiChangeBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdialogdpichangebehavior).

 If that function was never called on the dialog, the return value will be zero.

## Parameters

### `hDlg`

The handle for the dialog to examine.

## Return value

The flags set on the given dialog. If passed an invalid handle, this function will return zero, and set its [last error](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to **ERROR_INVALID_HANDLE**.

## Remarks

It can be difficult to distinguish between a return value of **DDC_DEFAULT** and the error case, which is zero. To determine between the two, it is recommended that you call [GetLastError()](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) to check the error.

## See also

[DIALOG_DPI_CHANGE_BEHAVIORS](https://learn.microsoft.com/windows/desktop/api/winuser/ne-winuser-dialog_dpi_change_behaviors)

[SetDialogDpiChangeBehavior](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdialogdpichangebehavior)
# GetDlgCtrlID function

## Description

Retrieves the identifier of the specified control.

## Parameters

### `hWnd` [in]

Type: **HWND**

A handle to the control.

## Return value

Type: **int**

If the function succeeds, the return value is the identifier of the control.

If the function fails, the return value is zero. An invalid value for the *hwndCtl* parameter, for example, will cause the function to fail. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

**GetDlgCtrlID** accepts child window handles as well as handles of controls in dialog boxes. An application sets the identifier for a child window when it creates the window by assigning the identifier value to the *hmenu* parameter when calling the [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa) or [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa) function.

Although **GetDlgCtrlID** may return a value if *hwndCtl* is a handle to a top-level window, top-level windows cannot have identifiers and such a return value is never valid.

#### Examples

For an example, see [Initializing a Dialog Box](https://learn.microsoft.com/windows/desktop/dlgbox/using-dialog-boxes).

## See also

**Conceptual**

[CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa)

[CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa)

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[GetDlgItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdlgitem)

**Reference**
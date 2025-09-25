# GetDlgItem function

## Description

Retrieves a handle to a control in the specified dialog box.

## Parameters

### `hDlg` [in, optional]

Type: **HWND**

A handle to the dialog box that contains the control.

### `nIDDlgItem` [in]

Type: **int**

The identifier of the control to be retrieved.

## Return value

Type: **HWND**

If the function succeeds, the return value is the window handle of the specified control.

If the function fails, the return value is **NULL**, indicating an invalid dialog box handle or a nonexistent control. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

You can use the **GetDlgItem** function with any parent-child window pair, not just with dialog boxes. As long as the *hDlg* parameter specifies a parent window and the child window has a unique identifier (as specified by the *hMenu* parameter in the [CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa) or [CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa) function that created the child window), **GetDlgItem** returns a valid handle to the child window.

#### Examples

For an example, see [Initializing a Dialog Box](https://learn.microsoft.com/windows/desktop/dlgbox/using-dialog-boxes).

## See also

**Conceptual**

[CreateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowa)

[CreateWindowEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-createwindowexa)

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[GetDlgItemInt](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdlgitemint)

[GetDlgItemText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdlgitemtexta)

**Reference**
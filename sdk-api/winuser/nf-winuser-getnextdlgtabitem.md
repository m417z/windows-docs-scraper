# GetNextDlgTabItem function

## Description

Retrieves a handle to the first
control that has the [WS_TABSTOP](https://learn.microsoft.com/windows/desktop/dlgbox/dlgbox-programming-considerations)
style that precedes (or follows) the specified control.

## Parameters

### `hDlg` [in]

Type: **HWND**

A handle to the dialog box to be searched.

### `hCtl` [in, optional]

Type: **HWND**

A handle to the control to be used as the starting point for the search.
If this parameter is **NULL**, the function fails.

### `bPrevious` [in]

Type: **BOOL**

Indicates how the function is to search the dialog box. If this parameter
is **TRUE**, the function searches for the previous control
in the dialog box. If this parameter is **FALSE**, the function searches
for the next control in the dialog box.

## Return value

Type: **HWND**

If the function succeeds, the return value is the window handle
of the previous (or next) control that has the
[WS_TABSTOP](https://learn.microsoft.com/windows/desktop/dlgbox/dlgbox-programming-considerations) style set.

If the function fails, the return value is **NULL**. To get extended error
information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetNextDlgTabItem** function searches controls in the order (or reverse order) they were created in the dialog box template. The function returns the first control it locates that is visible, not disabled, and has the [WS_TABSTOP](https://learn.microsoft.com/windows/desktop/dlgbox/dlgbox-programming-considerations) style. If no such control exists, the function returns *hCtl*.

If the search for the next control with the **WS_TABSTOP** style encounters a window with the **WS_EX_CONTROLPARENT** style, the system recursively searches the window's children.

## See also

**Conceptual**

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[GetDlgItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdlgitem)

[GetNextDlgGroupItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getnextdlggroupitem)

**Reference**
# GetNextDlgGroupItem function

## Description

Retrieves a handle to the first control in a group of controls that precedes (or follows) the specified control in a dialog box.

## Parameters

### `hDlg` [in]

Type: **HWND**

A handle to the dialog box to be searched.

### `hCtl` [in, optional]

Type: **HWND**

A handle to the control to be used as the starting point for the search. If this parameter is **NULL**, the function uses the last (or first) control in the dialog box as the starting point for the search.

### `bPrevious` [in]

Type: **BOOL**

Indicates how the function is to search the group of controls in the dialog box. If this parameter is **TRUE**, the function searches for the previous control in the group. If it is **FALSE**, the function searches for the next control in the group.

## Return value

Type: **HWND**

If the function succeeds, the return value is a handle to the previous (or next) control in the group of controls.

If the function fails, the return value is **NULL**. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetNextDlgGroupItem** function searches controls in the order (or reverse order) they were created in the dialog box template. The first control in the group must have the [WS_GROUP](https://learn.microsoft.com/windows/desktop/dlgbox/dlgbox-programming-considerations) style; all other controls in the group must have been consecutively created and must not have the **WS_GROUP** style.

When searching for the previous control, the function returns the first control it locates that is visible and not disabled. If the control specified by *hCtl* has the **WS_GROUP** style, the function temporarily reverses the search to locate the first control having the **WS_GROUP** style, then resumes the search in the original direction, returning the first control it locates that is visible and not disabled, or returning *hCtl* if no such control is found.

When searching for the next control, the function returns the first control it locates that is visible, not disabled, and does not have the **WS_GROUP** style. If it encounters a control having the **WS_GROUP** style, the function reverses the search, locates the first control having the **WS_GROUP** style, and returns this control if it is visible and not disabled. Otherwise, the function resumes the search in the original direction and returns the first control it locates that is visible and not disabled, or returns *hCtl* if no such control is found.

If the search for the next control in the group encounters a window with the **WS_EX_CONTROLPARENT** style, the system recursively searches the window's children.

## See also

**Conceptual**

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[GetNextDlgTabItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getnextdlgtabitem)

**Reference**
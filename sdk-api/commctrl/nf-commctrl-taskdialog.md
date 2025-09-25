# TaskDialog function

## Description

The **TaskDialog** function creates, displays, and operates a task dialog. The task dialog contains application-defined message text and title, icons, and any combination of predefined push buttons. This function does not support the registration of a callback function to receive notifications.

## Parameters

### `hwndOwner` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the owner window of the task dialog to be created. If this parameter is **NULL**, the task dialog has no owner window.

### `hInstance` [in]

Type: **[HINSTANCE](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Handle to the module that contains the icon resource identified by the *pszIcon* member, and the string resources identified by the *pszWindowTitle* and *pszMainInstruction* members. If this parameter is **NULL**, *pszIcon* must be **NULL** or a pointer to a null-terminated, Unicode string that contains a system resource identifier, for example, TD_ERROR_ICON.

### `pszWindowTitle` [in]

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to the string to be used for the task dialog title. This parameter is a null-terminated, Unicode string that contains either text, or an integer resource identifier passed through the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. If this parameter is **NULL**, the filename of the executable program is used.

### `pszMainInstruction` [in]

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to the string to be used for the main instruction. This parameter is a null-terminated, Unicode string that contains either text, or an integer resource identifier passed through the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. This parameter can be **NULL** if no main instruction is wanted.

### `pszContent` [in]

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string used for additional text that appears below the main instruction, in a smaller font. This parameter is a null-terminated, Unicode string that contains either text, or an integer resource identifier passed through the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. Can be **NULL** if no additional text is wanted.

### `dwCommonButtons` [in]

Type: **TASKDIALOG_COMMON_BUTTON_FLAGS**

Specifies the push buttons displayed in the dialog box. This parameter may be a combination of flags from the following group.

**Note** If no buttons are specified, the dialog box will contain the **OK** button by default.

| Value | Meaning |
| --- | --- |
| **TDCBF_OK_BUTTON** | The task dialog contains the push button: **OK**. |
| **TDCBF_YES_BUTTON** | The task dialog contains the push button: **Yes**. |
| **TDCBF_NO_BUTTON** | The task dialog contains the push button: **No**. |
| **TDCBF_CANCEL_BUTTON** | The task dialog contains the push button: **Cancel**. This button must be specified for the dialog box to respond to typical cancel actions (Alt-F4 and Escape). |
| **TDCBF_RETRY_BUTTON** | The task dialog contains the push button: **Retry**. |
| **TDCBF_CLOSE_BUTTON** | The task dialog contains the push button: **Close**. |

### `pszIcon` [in]

Type: **[PCWSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Pointer to a string that identifies the icon to display in the task dialog. This parameter must be an integer resource identifier passed to the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro or one of the following predefined values. If this parameter is **NULL**, no icon will be displayed. If the *hInstance* parameter is **NULL** and one of the predefined values is not used, the **TaskDialog** function fails.

| Value | Meaning |
| --- | --- |
| **TD_ERROR_ICON** | A stop-sign icon appears in the task dialog. |
| **TD_INFORMATION_ICON** | An icon consisting of a lowercase letter i in a circle appears in the task dialog. |
| **TD_SHIELD_ICON** | A security shield icon appears in the task dialog. |
| **TD_WARNING_ICON** | An exclamation-point icon appears in the task dialog. |

### `pnButton` [out]

Type: **int***

When this function returns, contains a pointer to an integer location that receives one of the following values:

| Value | Description |
| --- | --- |
| 0 | Function call failed. Refer to return value for more information. |
| **IDCANCEL** | **Cancel** button was selected, Alt-F4 was pressed, Escape was pressed or the user clicked on the **close window** button. |
| **IDNO** | **No** button was selected. |
| **IDOK** | **OK** button was selected. |
| **IDRETRY** | **Retry** button was selected. |
| **IDYES** | **Yes** button was selected. |
| **IDCLOSE** | **Close** button was selected. |

If this value is **NULL**, no value is returned.

## Return value

Type: **[HRESULT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

This function can return one of these values.

| Return code | Description |
| --- | --- |
| **S_OK** | The operation completed successfully. |
| **E_OUTOFMEMORY** | There is insufficient memory to complete the operation. |
| **E_INVALIDARG** | One or more arguments are not valid. |
| **E_FAIL** | The operation failed. |

## Remarks

When you use a task dialog box to indicate that the system is low on memory, the strings pointed to by the *pszMainInstruction* and *pszWindowTitle* parameters should not be taken from a resource file since an attempt to load the resource may fail.

 If you create a task dialog while a dialog box is present, use a handle to the dialog box as the *hWndParent* parameter. The *hWndParent* parameter should not identify a child window, such as a control in a dialog box.

Because task dialog boxes use the correct system-defined UI elements, you should use them instead of using message boxes created with the [MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox) function. To achieve more functionality, use [TaskDialogIndirect](https://learn.microsoft.com/windows/desktop/api/commctrl/nf-commctrl-taskdialogindirect).

The following example code, to be included as part of a larger program, shows how to create a task dialog and capture input.

```

int nButtonPressed = 0;
TaskDialog(NULL, hInst,
    MAKEINTRESOURCE(IDS_APPLICATION_TITLE),
    MAKEINTRESOURCE(IDS_DOSOMETHING),
    MAKEINTRESOURCE(IDS_SOMECONTENT),
    TDCBF_OK_BUTTON | TDCBF_CANCEL_BUTTON,
    TD_WARNING_ICON,
    &nButtonPressed);

if (IDOK == nButtonPressed)
{
    // OK button pressed
}
else if (IDCANCEL == nButtonPressed)
{
    // Cancel pressed
}
```

## See also

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)
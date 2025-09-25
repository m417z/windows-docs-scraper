# MessageBoxExW function

## Description

Creates, displays, and operates a message box. The message box contains an application-defined message and title, plus any combination of predefined icons and push buttons. The buttons are in the language of the system user interface.

Currently **MessageBoxEx** and [MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox) work the same way.

## Parameters

### `hWnd` [in, optional]

Type: **HWND**

A handle to the owner window of the message box to be created. If this parameter is **NULL**, the message box has no owner window.

### `lpText` [in, optional]

Type: **LPCTSTR**

The message to be displayed.

### `lpCaption` [in, optional]

Type: **LPCTSTR**

The dialog box title. If this parameter is **NULL**, the default title **Error** is used.

### `uType` [in]

Type: **UINT**

The contents and behavior of the dialog box. For information on the supported flags, see [MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox).

### `wLanguageId` [in]

Type: **WORD**

The language for the text displayed in the message box button(s). Specifying a value of zero (0) indicates to display the button text in the default system language. If this parameter is `MAKELANGID(LANG_NEUTRAL, SUBLANG_NEUTRAL)`, the current language associated with the calling thread is used.

To specify a language other than the current language, use the [MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid) macro to create this parameter. For more information, see **MAKELANGID**.

## Return value

Type: **int**

If a message box has a **Cancel** button, the function returns the **IDCANCEL** value if either the ESC key is pressed or the **Cancel** button is selected. If the message box has no **Cancel** button, pressing ESC will no effect - unless an MB_OK button is present. If an MB_OK button is displayed and the user presses ESC, the return value will be **IDOK**.

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

If the function succeeds, the return value is one of the following menu-item values.

| Return code/value | Description |
| --- | --- |
| **IDABORT**<br><br>3 | The **Abort** button was selected. |
| **IDCANCEL**<br><br>2 | The **Cancel** button was selected. |
| **IDCONTINUE**<br><br>11 | The **Continue** button was selected. |
| **IDIGNORE**<br><br>5 | The **Ignore** button was selected. |
| **IDNO**<br><br>7 | The **No** button was selected. |
| **IDOK**<br><br>1 | The **OK** button was selected. |
| **IDRETRY**<br><br>4 | The **Retry** button was selected. |
| **IDTRYAGAIN**<br><br>10 | The **Try Again** button was selected. |
| **IDYES**<br><br>6 | The **Yes** button was selected. |

## Remarks

When you use a system-modal message box to indicate that the system is low on memory, the strings pointed to by the *lpText* and *lpCaption* parameters should not be taken from a resource file because an attempt to load the resource may fail.

If you create a message box while a dialog box is present, use a handle to the dialog box as the *hWnd* parameter. The *hWnd* parameter should not identify a child window, such as a control in a dialog box.

> [!NOTE]
> The winuser.h header defines MessageBoxEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[MAKELANGID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelangid)

[MessageBeep](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebeep)

[MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox)

[MessageBoxIndirect](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messageboxindirecta)

**Other Resources**

**Reference**

[SetForegroundWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setforegroundwindow)
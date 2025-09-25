# MessageBoxIndirectA function

## Description

Creates, displays, and operates a message box. The message box contains application-defined message text and title, any icon, and any combination of predefined push buttons.

## Parameters

### `lpmbp` [in]

Type: **const LPMSGBOXPARAMS**

A pointer to a [MSGBOXPARAMS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msgboxparamsa) structure that contains information used to display the message box.

## Return value

Type: **int**

If the function succeeds, the return value is one of the following menu-item values.

If a message box has a **Cancel** button, the function returns the **IDCANCEL** value if either the ESC key is pressed or the **Cancel** button is selected. If the message box has no **Cancel** button, pressing ESC has no effect.

If there is not enough memory to create the message box, the return value is zero.

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

When you use a system-modal message box to indicate that the system is low on memory, the strings pointed to by the **lpszText** and **lpszCaption** members of the [MSGBOXPARAMS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msgboxparamsa) structure should not be taken from a resource file, because an attempt to load the resource may fail.

If you create a message box while a dialog box is present, use a handle to the dialog box as the *hWnd* parameter. The *hWnd* parameter should not identify a child window, such as a control in a dialog box.

> [!NOTE]
> The winuser.h header defines MessageBoxIndirect as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

**Conceptual**

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[MSGBOXPARAMS](https://learn.microsoft.com/windows/desktop/api/winuser/ns-winuser-msgboxparamsa)

[MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox)

[MessageBoxEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messageboxexa)

**Reference**
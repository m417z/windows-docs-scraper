# FINDREPLACEA structure

## Description

Contains information that the [FindText](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-findtexta) and [ReplaceText](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-replacetexta) functions use to initialize the **Find** and **Replace** dialog boxes. The [FINDMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/findmsgstring) registered message uses this structure to pass the user's search or replacement input to the owner window of a **Find** or **Replace** dialog box.

## Members

### `lStructSize`

Type: **DWORD**

The length, in bytes, of the structure.

### `hwndOwner`

Type: **HWND**

A handle to the window that owns the dialog box. The window procedure of the specified window receives [FINDMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/findmsgstring) messages from the dialog box. This member can be any valid window handle, but it must not be **NULL**.

### `hInstance`

Type: **HINSTANCE**

If the **FR_ENABLETEMPLATEHANDLE** flag is set in the **Flags**, **hInstance** is a handle to a memory object containing a dialog box template. If the **FR_ENABLETEMPLATE** flag is set, **hInstance** is a handle to a module that contains a dialog box template named by the **lpTemplateName** member. If neither flag is set, this member is ignored.

### `Flags`

Type: **DWORD**

A set of bit flags that you can use to initialize the dialog box. The dialog box sets these flags when it sends the [FINDMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/findmsgstring) registered message to indicate the user's input. This member can be one or more of the following values.

| Value | Meaning |
| --- | --- |
| **FR_DIALOGTERM**<br><br>0x00000040 | If set in a [FINDMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/findmsgstring) message, indicates that the dialog box is closing. When you receive a message with this flag set, the dialog box handle returned by the [FindText](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-findtexta) or [ReplaceText](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-replacetexta) function is no longer valid. |
| **FR_DOWN**<br><br>0x00000001 | If set, the **Down** button of the direction radio buttons in a **Find** dialog box is selected indicating that you should search from the current location to the end of the document. If not set, the **Up** button is selected so you should search to the beginning of the document. You can set this flag to initialize the dialog box. If set in a [FINDMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/findmsgstring) message, indicates the user's selection. |
| **FR_ENABLEHOOK**<br><br>0x00000100 | Enables the hook function specified in the **lpfnHook** member. This flag is used only to initialize the dialog box. |
| **FR_ENABLETEMPLATE**<br><br>0x00000200 | Indicates that the **hInstance** and **lpTemplateName** members specify a dialog box template to use in place of the default template. This flag is used only to initialize the dialog box. |
| **FR_ENABLETEMPLATEHANDLE**<br><br>0x00002000 | Indicates that the **hInstance** member identifies a data block that contains a preloaded dialog box template. The system ignores the **lpTemplateName** member if this flag is specified. |
| **FR_FINDNEXT**<br><br>0x00000008 | If set in a [FINDMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/findmsgstring) message, indicates that the user clicked the **Find Next** button in a **Find** or **Replace** dialog box. The **lpstrFindWhat** member specifies the string to search for. |
| **FR_HIDEUPDOWN**<br><br>0x00004000 | If set when initializing a **Find** dialog box, hides the search direction radio buttons. |
| **FR_HIDEMATCHCASE**<br><br>0x00008000 | If set when initializing a **Find** or **Replace** dialog box, hides the **Match Case** check box. |
| **FR_HIDEWHOLEWORD**<br><br>0x00010000 | If set when initializing a **Find** or **Replace** dialog box, hides the **Match Whole Word Only** check box. |
| **FR_MATCHCASE**<br><br>0x00000004 | If set, the **Match Case** check box is selected indicating that the search should be case-sensitive. If not set, the check box is unselected so the search should be case-insensitive. You can set this flag to initialize the dialog box. If set in a [FINDMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/findmsgstring) message, indicates the user's selection. |
| **FR_NOMATCHCASE**<br><br>0x00000800 | If set when initializing a **Find** or **Replace** dialog box, disables the **Match Case** check box. |
| **FR_NOUPDOWN**<br><br>0x00000400 | If set when initializing a **Find** dialog box, disables the search direction radio buttons. |
| **FR_NOWHOLEWORD**<br><br>0x00001000 | If set when initializing a **Find** or **Replace** dialog box, disables the **Whole Word** check box. |
| **FR_REPLACE**<br><br>0x00000010 | If set in a [FINDMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/findmsgstring) message, indicates that the user clicked the **Replace** button in a **Replace** dialog box. The **lpstrFindWhat** member specifies the string to be replaced and the **lpstrReplaceWith** member specifies the replacement string. |
| **FR_REPLACEALL**<br><br>0x00000020 | If set in a [FINDMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/findmsgstring) message, indicates that the user clicked the **Replace All** button in a **Replace** dialog box. The **lpstrFindWhat** member specifies the string to be replaced and the **lpstrReplaceWith** member specifies the replacement string. |
| **FR_SHOWHELP**<br><br>0x00000080 | Causes the dialog box to display the **Help** button. The **hwndOwner** member must specify the window to receive the [HELPMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/helpmsgstring) registered messages that the dialog box sends when the user clicks the **Help** button. |
| **FR_WHOLEWORD**<br><br>0x00000002 | If set, the **Match Whole Word Only** check box is selected indicating that you should search only for whole words that match the search string. If not set, the check box is unselected so you should also search for word fragments that match the search string. You can set this flag to initialize the dialog box. If set in a [FINDMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/findmsgstring) message, indicates the user's selection. |

### `lpstrFindWhat`

Type: **LPTSTR**

The search string that the user typed in the **Find What** edit control. You must dynamically allocate the buffer or use a global or static array so it does not go out of scope before the dialog box closes. The buffer should be at least 80 characters long. If the buffer contains a string when you initialize the dialog box, the string is displayed in the **Find What** edit control. If a [FINDMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/findmsgstring) message specifies the **FR_FINDNEXT** flag, **lpstrFindWhat** contains the string to search for. The **FR_DOWN**, **FR_WHOLEWORD**, and **FR_MATCHCASE** flags indicate the direction and type of search. If a **FINDMSGSTRING** message specifies the **FR_REPLACE** or **FR_REPLACE** flags, **lpstrFindWhat** contains the string to be replaced.

### `lpstrReplaceWith`

Type: **LPTSTR**

The replacement string that the user typed in the **Replace With** edit control. You must dynamically allocate the buffer or use a global or static array so it does not go out of scope before the dialog box closes. If the buffer contains a string when you initialize the dialog box, the string is displayed in the **Replace With** edit control.

If a [FINDMSGSTRING](https://learn.microsoft.com/windows/desktop/dlgbox/findmsgstring) message specifies the **FR_REPLACE** or **FR_REPLACEALL** flags, **lpstrReplaceWith** contains the replacement string .

The [FindText](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-findtexta) function ignores this member.

### `wFindWhatLen`

Type: **WORD**

The length, in bytes, of the buffer pointed to by the **lpstrFindWhat** member.

### `wReplaceWithLen`

Type: **WORD**

The length, in bytes, of the buffer pointed to by the **lpstrReplaceWith** member.

### `lCustData`

Type: **LPARAM**

Application-defined data that the system passes to the hook procedure identified by the **lpfnHook** member. When the system sends the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message to the hook procedure, the message's *lParam* parameter is a pointer to the **FINDREPLACE** structure specified when the dialog was created. The hook procedure can use this pointer to get the **lCustData** value.

### `lpfnHook`

Type: **LPFRHOOKPROC**

A pointer to an [FRHookProc](https://learn.microsoft.com/windows/desktop/api/commdlg/nc-commdlg-lpfrhookproc) hook procedure that can process messages intended for the dialog box. This member is ignored unless the **FR_ENABLEHOOK** flag is set in the **Flags** member. If the hook procedure returns **FALSE** in response to the [WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog) message, the hook procedure must display the dialog box or else the dialog box will not be shown. To do this, first perform any other paint operations, and then call the [ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow) and [UpdateWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-updatewindow) functions.

### `lpTemplateName`

Type: **LPCTSTR**

The name of the dialog box template resource in the module identified by the **hInstance** member. This template is substituted for the standard dialog box template. For numbered dialog box resources, this can be a value returned by the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro. This member is ignored unless the **FR_ENABLETEMPLATE** flag is set in the **Flags** member.

## See also

[Common Dialog Box Library](https://learn.microsoft.com/windows/desktop/dlgbox/common-dialog-box-library)

**Conceptual**

[FRHookProc](https://learn.microsoft.com/windows/desktop/api/commdlg/nc-commdlg-lpfrhookproc)

[FindText](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-findtexta)

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)

**Reference**

[ReplaceText](https://learn.microsoft.com/windows/desktop/api/commdlg/nf-commdlg-replacetexta)

[ShowWindow](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-showwindow)

[WM_INITDIALOG](https://learn.microsoft.com/windows/desktop/dlgbox/wm-initdialog)

## Remarks

> [!NOTE]
> The commdlg.h header defines FINDREPLACE as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
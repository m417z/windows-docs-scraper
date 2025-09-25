# MSGBOXPARAMSA structure

## Description

Contains information used to display a message box. The [MessageBoxIndirect](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-messageboxindirecta) function uses this structure.

## Members

### `cbSize`

Type: **UINT**

The structure size, in bytes.

### `hwndOwner`

Type: **HWND**

A handle to the owner window. This member can be **NULL**.

### `hInstance`

Type: **HINSTANCE**

A handle to the module that contains the icon resource identified by the
**lpszIcon** member, and the string resource identified by the
**lpszText** or
**lpszCaption** member.

### `lpszText`

Type: **LPCTSTR**

A null-terminated string, or the identifier of a string resource, that contains the message to be displayed.

### `lpszCaption`

Type: **LPCTSTR**

A null-terminated string, or the identifier of a string resource, that contains the message box title. If this member is **NULL**, the default title
**Error** is used.

### `dwStyle`

Type: **DWORD**

The contents and behavior of the dialog box. This member can be a combination of flags described for the
*uType* parameter of the [MessageBoxEx](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-messageboxexa) function.

In addition, you can specify the **MB_USERICON** flag (0x00000080L) if you want the message box to display the icon specified by the
**lpszIcon** member.

### `lpszIcon`

Type: **LPCTSTR**

Identifies an icon resource. This parameter can be either a null-terminated string or an integer resource identifier passed to the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-makeintresourcea) macro.

To load one of the standard system-defined icons, set the
**hInstance** member to **NULL** and set
**lpszIcon** to one of the values listed with the [LoadIcon](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-loadicona) function.

This member is ignored if the
**dwStyle** member does not specify the **MB_USERICON** flag.

### `dwContextHelpId`

Type: **DWORD_PTR**

Identifies a help context. If a help event occurs, this value is specified in the [HELPINFO](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-helpinfo) structure that the message box sends to the owner window or callback function.

### `lpfnMsgBoxCallback`

Type: **[MSGBOXCALLBACK](https://learn.microsoft.com/windows/win32/api/winuser/nc-winuser-msgboxcallback)**

A pointer to the callback function that processes help events for the message box. The callback function has the following form:

`VOID CALLBACK MsgBoxCallback(LPHELPINFO lpHelpInfo);`

If this member is **NULL**, then the message box sends [WM_HELP](https://learn.microsoft.com/windows/win32/shell/wm-help) messages to the owner window when help events occur.

### `dwLanguageId`

Type: **DWORD**

The language in which to display the text contained in the predefined push buttons. This value must be in the form returned by the
[MAKELANGID](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-makelangid) macro.

For a list of supported language identifiers, see [Language Identifiers](https://learn.microsoft.com/windows/win32/Intl/language-identifiers). Note that each localized release of Windows typically contains resources only for a limited set of languages. Thus, for example, the U.S. version offers **LANG_ENGLISH**, the French version offers **LANG_FRENCH**, the German version offers **LANG_GERMAN**, and the Japanese version offers **LANG_JAPANESE**. Each version offers **LANG_NEUTRAL**. This limits the set of values that can be used with the
**dwLanguageId** parameter. Before specifying a language identifier, you should enumerate the locales that are installed on a system.

## See also

**Conceptual**

[Dialog Boxes](https://learn.microsoft.com/windows/win32/dlgbox/dialog-boxes)

[HELPINFO](https://learn.microsoft.com/windows/win32/api/winuser/ns-winuser-helpinfo)

[LoadIcon](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-loadicona)

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-makeintresourcea)

[MAKELANGID](https://learn.microsoft.com/windows/win32/api/winnt/nf-winnt-makelangid)

[MessageBoxEx](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-messageboxexa)

[MessageBoxIndirect](https://learn.microsoft.com/windows/win32/api/winuser/nf-winuser-messageboxindirecta)

**Other Resources**

**Reference**

[WM_HELP](https://learn.microsoft.com/windows/win32/shell/wm-help)

## Remarks

> [!NOTE]
> The winuser.h header defines **MSGBOXPARAMS** as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
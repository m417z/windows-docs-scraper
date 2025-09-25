# GetDlgItemInt function

## Description

Translates the text of a specified control in a dialog box into an integer value.

## Parameters

### `hDlg` [in]

Type: **HWND**

A handle to the dialog box that contains the control of interest.

### `nIDDlgItem` [in]

Type: **int**

The identifier of the control whose text is to be translated.

### `lpTranslated` [out, optional]

Type: **BOOL***

Indicates success or failure (**TRUE** indicates success, **FALSE** indicates failure).

If this parameter is **NULL**, the function returns no information about success or failure.

### `bSigned` [in]

Type: **BOOL**

Indicates whether the function should examine the text for a minus sign at the beginning and return a signed integer value if it finds one (**TRUE** specifies this should be done, **FALSE** that it should not).

## Return value

Type: **UINT**

If the function succeeds, the variable pointed to by *lpTranslated* is set to **TRUE**, and the return value is the translated value of the control text.

If the function fails, the variable pointed to by *lpTranslated* is set to **FALSE**, and the return value is zero. Note that, because zero is a possible translated value, a return value of zero does not by itself indicate failure.

If *lpTranslated* is **NULL**, the function returns no information about success or failure.

Note that, if the *bSigned* parameter is **TRUE** and there is a minus sign (–) at the beginning of the text, **GetDlgItemInt** translates the text into a signed integer value. Otherwise, the function creates an unsigned integer value. To obtain the proper value in this case, cast the return value to an **int** type.

To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **GetDlgItemInt** function retrieves the text of the specified control by sending the control a [WM_GETTEXT](https://learn.microsoft.com/windows/desktop/winmsg/wm-gettext) message. The function translates the retrieved text by stripping any extra spaces at the beginning of the text and then converting the decimal digits. The function stops translating when it reaches the end of the text or encounters a nonnumeric character.

The **GetDlgItemInt** function returns zero if the translated value is greater than **INT_MAX** (for signed numbers) or **UINT_MAX** (for unsigned numbers).

#### Examples

For an example, see [Creating a Modeless Dialog Box](https://learn.microsoft.com/windows/desktop/dlgbox/using-dialog-boxes).

## See also

**Conceptual**

[Dialog Boxes](https://learn.microsoft.com/windows/desktop/dlgbox/dialog-boxes)

[GetDlgCtrlID](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdlgctrlid)

[GetDlgItem](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdlgitem)

[GetDlgItemText](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-getdlgitemtexta)

**Reference**

[SetDlgItemInt](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-setdlgitemint)
# DlgDirSelectComboBoxExA function

## Description

Retrieves the current selection from a combo box filled by using the [DlgDirListComboBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dlgdirlistcomboboxa) function. The selection is interpreted as a drive letter, a file, or a directory name.

## Parameters

### `hwndDlg` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the dialog box that contains the combo box.

### `lpString` [out]

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to the buffer that receives the selected path.

### `cchOut` [in]

Type: **int**

The length, in characters, of the buffer pointed to by the *lpString* parameter.

### `idComboBox` [in]

Type: **int**

The integer identifier of the combo box control in the dialog box.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the current selection is a directory name, the return value is nonzero.

If the current selection is not a directory name, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

If the current selection specifies a directory name or drive letter, the **DlgDirSelectComboBoxEx** function removes the enclosing square brackets (and hyphens for drive letters) so the name or letter is ready to be inserted into a new path or file name. If there is no selection, the contents of the buffer pointed to by *lpString* do not change.

The **DlgDirSelectComboBoxEx** function does not allow more than one file name to be returned from a combo box.

If the string is as long or longer than the buffer, the buffer contains the truncated string with a terminating null character.

**DlgDirSelectComboBoxEx** sends [CB_GETCURSEL](https://learn.microsoft.com/windows/desktop/Controls/cb-getcursel) and [CB_GETLBTEXT](https://learn.microsoft.com/windows/desktop/Controls/cb-getlbtext) messages to the combo box.

You can use this function with all three types of combo boxes ([CBS_SIMPLE](https://learn.microsoft.com/windows/desktop/Controls/combo-box-styles), [CBS_DROPDOWN](https://learn.microsoft.com/windows/desktop/Controls/combo-box-styles), and CBS_DROPDOWNLIST).

**Security Warning:** Improper use of this function can cause problems for your application. For instance, the *nCount* parameter should be set properly for both ANSI and Unicode versions. Failure to do so could lead to a buffer overflow. You should review [Security Considerations: Microsoft Windows Controls](https://learn.microsoft.com/windows/desktop/Controls/sec-comctls) before continuing.

**Windows 95 or later**: **DlgDirSelectComboBoxExW** is supported by the Microsoft Layer for Unicode (MSLU). To use this, you must add certain files to your application, as outlined in [Microsoft Layer for Unicode on Windows Me/98/95 Systems](https://learn.microsoft.com/archive/msdn-magazine/2001/october/mslu-develop-unicode-applications-for-windows-9x-platforms-with-the-microsoft-layer-for-unicode).

> [!NOTE]
> The winuser.h header defines DlgDirSelectComboBoxEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[CB_GETCURSEL](https://learn.microsoft.com/windows/desktop/Controls/cb-getcursel)

[CB_GETLBTEXT](https://learn.microsoft.com/windows/desktop/Controls/cb-getlbtext)

[DlgDirListComboBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dlgdirlistcomboboxa)

**Reference**
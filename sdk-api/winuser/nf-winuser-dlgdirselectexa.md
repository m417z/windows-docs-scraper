# DlgDirSelectExA function

## Description

Retrieves the current selection from a single-selection list box. It assumes that the list box has been filled by the [DlgDirList](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dlgdirlista) function and that the selection is a drive letter, filename, or directory name.

## Parameters

### `hwndDlg` [in]

Type: **[HWND](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A handle to the dialog box that contains the list box.

### `lpString` [out]

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

A pointer to a buffer that receives the selected path.

### `chCount` [in]

Type: **int**

The length, in
**TCHARs**, of the buffer pointed to by
*lpString*.

### `idListBox` [in]

Type: **int**

The identifier of a list box in the dialog box.

## Return value

Type: **[BOOL](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If the current selection is a directory name, the return value is nonzero.

If the current selection is not a directory name, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

The **DlgDirSelectEx** function copies the selection to the buffer pointed to by the
*lpString* parameter. If the current selection is a directory name or drive letter, **DlgDirSelectEx** removes the enclosing square brackets (and hyphens, for drive letters), so that the name or letter is ready to be inserted into a new path. If there is no selection,
*lpString* does not change.

If the string is as long or longer than the buffer, the buffer will contain the truncated string with a terminating null character.

**DlgDirSelectEx** sends [LB_GETCURSEL](https://learn.microsoft.com/windows/desktop/Controls/lb-getcursel) and [LB_GETTEXT](https://learn.microsoft.com/windows/desktop/Controls/lb-gettext) messages to the list box. The function does not allow more than one filename to be returned from a list box. The list box must not be a multiple-selection list box. If it is, this function does not return a zero value and
*lpString* remains unchanged.

**Windows 95 or later**: **DlgDirSelectExW** is supported by the Microsoft Layer for Unicode. To use this, you must add certain files to your application, as outlined in [Microsoft Layer for Unicode on Windows Me/98/95 Systems](https://learn.microsoft.com/archive/msdn-magazine/2001/october/mslu-develop-unicode-applications-for-windows-9x-platforms-with-the-microsoft-layer-for-unicode).

#### Examples

For an example, see [Creating a Directory Listing in a Single-selection List Box](https://learn.microsoft.com/windows/desktop/Controls/using-list-boxes).

> [!NOTE]
> The winuser.h header defines DlgDirSelectEx as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[DlgDirList](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dlgdirlista)

[DlgDirListComboBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dlgdirlistcomboboxa)

[DlgDirSelectComboBoxEx](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-dlgdirselectcomboboxexa)

[LB_GETCURSEL](https://learn.microsoft.com/windows/desktop/Controls/lb-getcursel)

[LB_GETTEXT](https://learn.microsoft.com/windows/desktop/Controls/lb-gettext)

**Reference**
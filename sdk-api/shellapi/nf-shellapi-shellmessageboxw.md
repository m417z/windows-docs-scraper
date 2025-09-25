# ShellMessageBoxW function

## Description

[**ShellMessageBox** is available for use in the operating systems specified in the Requirements section. It may be altered or unavailable in subsequent versions.]

**ShellMessageBox** is a special instance of [MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox) that provides the option of using the owner window's title as the title of the message box.

## Parameters

### `hAppInst` [in]

Type: **HINSTANCE**

The handle of the module from which to load a string resource named in *pszTitle*. If *pszTitle* does not name a string resource, this parameter is ignored. This value must be valid if *pszMsg* or *pszTitle* is a resource ID.

### `hWnd` [in]

Type: **HWND**

A handle to the owner window of the message box to be created. If this variable is not **NULL**, the title of the owner window is used as the title of the message box.

### `lpcText` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string that contains either the message to be displayed or a resource ID specifying where the message is to be retrieved from.

### `lpcTitle` [in]

Type: **LPCTSTR**

A pointer to a null-terminated string that contains the dialog box title or a resource ID specifying where the title is to be retrieved. If both this parameter and *hWnd* are **NULL**, no title is displayed. If this parameter points to a loadable resource formed with the [MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea) macro, it overrides *hWnd* as the title.

### `fuStyle` [in]

Type: **UINT**

Specifies the contents and behavior of the dialog box. For possible values, see [MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox).

### `...`

A variable argument list that is combined with *pszMsg* to form the full text displayed in the message box.

## Return value

Type: **int**

An integer value indicating a button that was pressed in the message box. For specific values, see [MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox).

If the function fails, the return value is zero. To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## See also

[MAKEINTRESOURCE](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-makeintresourcea)

[MessageBox](https://learn.microsoft.com/windows/desktop/api/winuser/nf-winuser-messagebox)

## Remarks

> [!NOTE]
> The shellapi.h header defines ShellMessageBox as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
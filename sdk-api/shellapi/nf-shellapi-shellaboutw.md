# ShellAboutW function

## Description

Displays a **ShellAbout** dialog box.

## Parameters

### `hWnd` [in, optional]

Type: **HWND**

A window handle to a parent window. This parameter can be **NULL**.

### `szApp` [in]

Type: **LPCWSTR**

A pointer to a null-terminated string that contains text to be displayed in the title bar of the **ShellAbout** dialog box and on the first line of the dialog box after the text "Microsoft". If the text contains a separator (#) that divides it into two parts, the function displays the first part in the title bar and the second part on the first line after the text "Microsoft".

**Windows 2000, Windows XP, Windows Server 2003**: If the string pointed to by this parameter contains a separator (#), then the string must be writable.

**Windows Vista, Windows Server 2008**: This string cannot exceed 200 characters in length. The contents of **szApp** will no longer show after "Microsoft", unless there is a # separator, in which case the part after the # will completely replace the first line.

### `szOtherStuff` [in, optional]

Type: **LPCWSTR**

A pointer to a null-terminated string that contains text to be displayed in the dialog box after the version and copyright information. This parameter can be **NULL**.

### `hIcon` [in, optional]

Type: **HICON**

The handle of an icon that the function displays in the dialog box. This parameter can be **NULL**, in which case the function displays the Windows icon.

## Return value

Type: **int**

**TRUE** if successful; otherwise, **FALSE**.

## Remarks

Note that the **ShellAbout** function dialog box uses text and a default icon that are specific to Windows.

To see an example of a **ShellAbout** dialog box, run the `winver.exe` command.

> [!NOTE]
> The shellapi.h header defines ShellAbout as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
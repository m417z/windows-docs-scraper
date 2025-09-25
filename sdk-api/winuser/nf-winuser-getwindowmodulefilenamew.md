# GetWindowModuleFileNameW function

## Description

Retrieves the full path and file name of the module associated with the specified window handle.

## Parameters

### `hwnd` [in]

Type: **HWND**

A handle to the window whose module file name is to be retrieved.

### `pszFileName` [out]

Type: **LPTSTR**

The path and file name.

### `cchFileNameMax` [in]

Type: **UINT**

The maximum number of characters that can be copied into the *lpszFileName* buffer.

## Return value

Type: **UINT**

The return value is the total number of characters copied into the buffer.

## See also

[Windows Overview](https://learn.microsoft.com/windows/desktop/winmsg/windows)

## Remarks

> [!NOTE]
> The winuser.h header defines GetWindowModuleFileName as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
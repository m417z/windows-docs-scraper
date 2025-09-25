# GetRoleTextA function

## Description

Retrieves the localized string that describes the object's role for the specified role value.

## Parameters

### `lRole` [in]

Type: **[DWORD](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

One of the [object role](https://learn.microsoft.com/windows/desktop/WinAuto/object-roles) constants.

### `lpszRole` [out]

Type: **[LPTSTR](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

Address of a buffer that receives the role text string. If this parameter is **NULL**, the function returns the role string's length, not including the null character.

### `cchRoleMax` [in]

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

The size of the buffer that is pointed to by the *lpszRole* parameter. For ANSI strings, this value is measured in bytes; for Unicode strings, it is measured in characters.

## Return value

Type: **[UINT](https://learn.microsoft.com/windows/desktop/WinProg/windows-data-types)**

If successful, and if *lpszRole* is non-**NULL**, the return value is the number of bytes (ANSI strings) or characters (Unicode strings) copied into the buffer, not including the terminating null character. If *lpszRole* is **NULL**, the return value represents the string's length, not including the null character.

If the string resource does not exist, or if the *lpszRole* parameter is not a valid pointer, the return value is zero (0). To get extended error information, call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror).

## Remarks

> [!NOTE]
> The oleacc.h header defines GetRoleText as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).
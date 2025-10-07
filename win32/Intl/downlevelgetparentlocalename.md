# DownlevelGetParentLocaleName function

Retrieves the [locale name](https://learn.microsoft.com/windows/win32/intl/locale-names) for the parent of the supplied locale.

> [!Note]
> This function is used only by applications that run on pre-Windows Vista operating systems. Its use requires the download package. Applications that only run on Windows Vista and later should call [**GetLocaleInfo**](https://learn.microsoft.com/windows/desktop/api/Winnls/nf-winnls-getlocaleinfoa) with *LCType* set to [LOCALE\_SPARENT](https://learn.microsoft.com/windows/win32/intl/locale-sparent).

## Parameters

*Locale* \[in\]

[Locale identifier](https://learn.microsoft.com/windows/win32/intl/locale-identifiers) of the locale. You can use the [**MAKELCID**](https://learn.microsoft.com/windows/desktop/api/Winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

- [LOCALE\_INVARIANT](https://learn.microsoft.com/windows/win32/intl/locale-invariant)
- [LOCALE\_SYSTEM\_DEFAULT](https://learn.microsoft.com/windows/win32/intl/locale-system-default)
- [LOCALE\_USER\_DEFAULT](https://learn.microsoft.com/windows/win32/intl/locale-user-default)

**Windows Vista and later:** The following custom locale identifiers are also supported.

- [LOCALE\_CUSTOM\_DEFAULT](https://learn.microsoft.com/windows/win32/intl/locale-custom-constants)
- [LOCALE\_CUSTOM\_UI\_DEFAULT](https://learn.microsoft.com/windows/win32/intl/locale-custom-constants)
- [LOCALE\_CUSTOM\_UNSPECIFIED](https://learn.microsoft.com/windows/win32/intl/locale-custom-constants)

*lpName* \[out\]

Pointer to a buffer in which the function retrieves the parent locale name, or one of the following predefined values. This parameter is set to **NULL** if *cchName* is set to 0.

- [LOCALE\_NAME\_INVARIANT](https://learn.microsoft.com/windows/win32/intl/locale-name-constants)
- [LOCALE\_NAME\_SYSTEM\_DEFAULT](https://learn.microsoft.com/windows/win32/intl/locale-name-constants)
- [LOCALE\_NAME\_USER\_DEFAULT](https://learn.microsoft.com/windows/win32/intl/locale-name-constants)

*cchName* \[in\]

Size of the buffer indicated by *lpName*, in UTF-16 code points. A value of 0 for this parameter causes the function to ignore the *lpName* buffer and return the size of the buffer, in characters (null characters included), required to contain the parent locale name.

## Return value

Returns the count of UTF-16 code points in the locale name, including the terminating null character, if successful.

This function returns 0 if it does not succeed. To get extended error information, the application can call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

- ERROR\_INSUFFICIENT\_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
- ERROR\_INVALID\_PARAMETER. Any of the parameter values was invalid.

## Remarks

The required header file and DLL are part of the "Microsoft NLS Downlevel Data Mapping APIs" download, which is no longer available from the [Microsoft Download Center](https://www.microsoft.com/downloads). Use [ICU globalization APIs](https://learn.microsoft.com/dotnet/core/compatibility/globalization/5.0/icu-globalization-api) on Windows 10 May 2019 Update and later versions.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Redistributable<br> | Microsoft NLS Downlevel Data Mapping APIs onWindows XP with SP2 and later<br> |
| Header<br> | Nlsdl.h |
| DLL<br> | NlsMap.dll |

## See also

[National Language Support](https://learn.microsoft.com/windows/win32/intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/win32/intl/national-language-support-functions)

[Mapping Locale Data](https://learn.microsoft.com/windows/win32/intl/mapping-locale-data)

[**GetLocaleInfo**](https://learn.microsoft.com/windows/desktop/api/Winnls/nf-winnls-getlocaleinfoa)


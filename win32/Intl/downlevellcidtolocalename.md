# DownlevelLCIDToLocaleName function

Converts a [locale identifier](https://learn.microsoft.com/windows/win32/intl/locale-identifiers) to a [locale name](https://learn.microsoft.com/windows/win32/intl/locale-names).

> [!Note]
> This function is used only by applications that run on pre-Windows Vista operating systems. Its use requires a download package. Applications that run only on Windows Vista and later should call [**LCIDToLocaleName**](https://learn.microsoft.com/windows/desktop/api/Winnls/nf-winnls-lcidtolocalename) to retrieve a locale name.

## Parameters

*Locale* \[in\]

The locale identifier to translate. You can use the [**MAKELCID**](https://learn.microsoft.com/windows/desktop/api/Winnt/nf-winnt-makelcid) macro to create a locale identifier. This function does not support neutral locales or the following specific locale identifier values.

- [LOCALE\_SYSTEM\_DEFAULT](https://learn.microsoft.com/windows/win32/intl/locale-system-default)
- [LOCALE\_USER\_DEFAULT](https://learn.microsoft.com/windows/win32/intl/locale-user-default)
- [LOCALE\_CUSTOM\_DEFAULT](https://learn.microsoft.com/windows/win32/intl/locale-custom-constants)
- [LOCALE\_CUSTOM\_UI\_DEFAULT](https://learn.microsoft.com/windows/win32/intl/locale-custom-constants)
- [LOCALE\_CUSTOM\_UNSPECIFIED](https://learn.microsoft.com/windows/win32/intl/locale-custom-constants)

*lpName* \[out\]

Pointer to a buffer in which this function retrieves the locale name. The function retrieves **NULL** if *cchName* is set to 0.

*cchName* \[in\]

Size, in UTF-16 code points, of the locale name buffer. The application sets this parameter to 0 to return the required size of the locale name buffer.

*dwFlags* \[in\]

Flags specifying the type of name to retrieve. The default value is DOWNLEVEL\_LOCALE\_NAME.

## Return value

Returns the count of UTF-16 code points in the locale name, including the terminating null character, if successful. If the function succeeds and the value of *cchName* is 0, the return value is the required size, in characters (including null characters), for the locale name buffer.

The function returns 0 if it does not succeed. To get extended error information, the application can call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

- ERROR\_INSUFFICIENT\_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
- ERROR\_INVALID\_FLAGS. The value of *dwFlags* is not valid.
- ERROR\_INVALID\_PARAMETER. Any of the parameter values were invalid.

## Remarks

> [!Note]
> This function does not support [custom locales](https://learn.microsoft.com/windows/win32/intl/custom-locales).

The required header file and DLL are part of the "Microsoft NLS Downlevel Data Mapping APIs" download, which is no longer available from the [Microsoft Download Center](https://www.microsoft.com/downloads). Use [ICU globalization APIs](https://learn.microsoft.com/dotnet/core/compatibility/globalization/5.0/icu-globalization-api) on Windows 10 May 2019 Update and later versions.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Redistributable<br> | Microsoft NLS Downlevel Data Mapping APIs onWindows XP with SP2 and laterorWindows Vista<br> |
| Header<br> | Nlsdl.h |
| DLL<br> | NlsMap.dll |

## See also

[National Language Support](https://learn.microsoft.com/windows/win32/intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/win32/intl/national-language-support-functions)

[Mapping Locale Data](https://learn.microsoft.com/windows/win32/intl/mapping-locale-data)

[**LCIDToLocaleName**](https://learn.microsoft.com/windows/desktop/api/Winnls/nf-winnls-lcidtolocalename)


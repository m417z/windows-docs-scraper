# DownlevelLocaleNameToLCID function

Converts a [locale name](https://learn.microsoft.com/windows/win32/intl/locale-names) to a [locale identifier](https://learn.microsoft.com/windows/win32/intl/locale-identifiers) that can be used to get information from the operating system.

> [!Note]
> This function is used only by applications that run on pre-Windows Vista operating systems. Its use requires a download package. Applications that only run on Windows Vista and later should call [**LocaleNameToLCID**](https://learn.microsoft.com/windows/desktop/api/Winnls/nf-winnls-localenametolcid) to retrieve a locale identifier.

## Parameters

*lpName* \[in\]

Pointer to a null-terminated string representing a [locale name](https://learn.microsoft.com/windows/win32/intl/locale-names).

*dwFlags* \[in\]

Flags specifying the type of name. The default is DOWNLEVEL\_LOCALE\_NAME.

## Return value

Returns the locale identifier that corresponds to the locale name if successful.

The function returns 0 if it does not succeed. To get extended error information, the application can call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

- ERROR\_INVALID\_FLAGS. The values supplied for flags were not valid.
- ERROR\_INVALID\_PARAMETER. Any of the parameter values were invalid.

## Remarks

> [!Note]
> This function does not support neutral locales. The equivalent [**LocaleNameToLCID**](https://learn.microsoft.com/windows/desktop/api/Winnls/nf-winnls-localenametolcid) function supports [custom locales](https://learn.microsoft.com/windows/win32/intl/custom-locales), but only for Windows Vista and later.

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

[**LocaleNameToLCID**](https://learn.microsoft.com/windows/desktop/api/Winnls/nf-winnls-localenametolcid)


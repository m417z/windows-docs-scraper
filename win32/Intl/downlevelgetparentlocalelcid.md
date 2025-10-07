# DownlevelGetParentLocaleLCID function

Retrieves the [locale identifier](https://learn.microsoft.com/windows/win32/intl/locale-identifiers) for the parent of the supplied locale.

> [!Note]
> This function is used only by applications that run on pre-Windows Vista operating systems. Its use requires the download package. Applications that only run on Windows Vista and later should call [**GetLocaleInfo**](https://learn.microsoft.com/windows/desktop/api/Winnls/nf-winnls-getlocaleinfoa) with *LCType* set to [LOCALE\_SPARENT](https://learn.microsoft.com/windows/win32/intl/locale-sparent).

## Parameters

*Locale* \[in\]

Locale identifier of the locale for which to retrieve the parent locale identifier. You can use the [**MAKELCID**](https://learn.microsoft.com/windows/desktop/api/Winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

- [LOCALE\_INVARIANT](https://learn.microsoft.com/windows/win32/intl/locale-invariant)
- [LOCALE\_SYSTEM\_DEFAULT](https://learn.microsoft.com/windows/win32/intl/locale-system-default)
- [LOCALE\_USER\_DEFAULT](https://learn.microsoft.com/windows/win32/intl/locale-user-default)

**Windows Vista and later:** The following custom locale identifiers are also supported.

- [LOCALE\_CUSTOM\_DEFAULT](https://learn.microsoft.com/windows/win32/intl/locale-custom-constants)
- [LOCALE\_CUSTOM\_UI\_DEFAULT](https://learn.microsoft.com/windows/win32/intl/locale-custom-constants)
- [LOCALE\_CUSTOM\_UNSPECIFIED](https://learn.microsoft.com/windows/win32/intl/locale-custom-constants)

## Return value

Returns the parent locale identifier if successful, or 0 otherwise. To get extended error information, the application can call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

- ERROR\_INVALID\_PARAMETER. Any of the parameter values was invalid.

## Remarks

The required header file and DLL are part of the "Microsoft NLS Downlevel Data Mapping APIs" download, which is no longer available from the [Microsoft Download Center](https://www.microsoft.com/downloads). Use [ICU globalization APIs](https://learn.microsoft.com/dotnet/core/compatibility/globalization/5.0/icu-globalization-api) on Windows 10 May 2019 Update and later versions.

## Requirements

| Requirement | Value |
|-------------------------------------|---------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Redistributable<br> | Microsoft NLS Downlevel Data Mapping APIs onWindows XPor Windows Vista<br> |
| Header<br> | Nlsdl.h |
| DLL<br> | NlsMap.dll |

## See also

[National Language Support](https://learn.microsoft.com/windows/win32/intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/win32/intl/national-language-support-functions)

[Mapping Locale Data](https://learn.microsoft.com/windows/win32/intl/mapping-locale-data)

[**GetLocaleInfo**](https://learn.microsoft.com/windows/desktop/api/Winnls/nf-winnls-getlocaleinfoa)


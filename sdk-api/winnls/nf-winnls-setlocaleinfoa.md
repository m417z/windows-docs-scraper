# SetLocaleInfoA function

## Description

Sets an item of information in the user override portion of the current locale. This function does not set the system defaults.

**Caution** Because this function modifies values for all applications, it should only be called by the regional and language options functionality of Control Panel, or a similar utility. If making an international change to system parameters, the calling application must broadcast the [WM_SETTINGCHANGE](https://learn.microsoft.com/windows/desktop/winmsg/wm-settingchange) message to avoid causing instabilities in other applications.

## Parameters

### `Locale` [in]

For the ANSI version of the function, the [locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) of the locale with the code page used when interpreting the *lpLCData* information. For the Unicode version, this parameter is ignored.

You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

The following custom locale identifiers are also supported.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)

### `LCType` [in]

Type of locale information to set. For valid constants see "Constants Used in the LCType Parameter of GetLocaleInfo, GetLocaleInfoEx, and SetLocaleInfo" section of [Locale Information Constants](https://learn.microsoft.com/windows/desktop/Intl/locale-information-constants). The application can specify only one value per call, but it can use the binary OR operator to combine [LOCALE_USE_CP_ACP](https://learn.microsoft.com/windows/desktop/Intl/locale-use-cp-acp) with any other constant.

### `lpLCData` [in]

Pointer to a null-terminated string containing the locale information to set. The information must be in the format specific to the specified constant. The application uses a Unicode string for the Unicode version of the function, and an ANSI string for the ANSI version.

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_ACCESS_DISABLED_BY_POLICY. The group policy of the computer or the user has forbidden this operation.
* ERROR_INVALID_ACCESS. The access code was invalid.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function writes to the registry, where it sets values that are associated with a particular user instead of a particular application. These registry values affect the behavior of other applications run by the user. As a rule, an application should call this function only when the user has explicitly requested the changes. The registry settings should not be changed for the convenience of a single application.

For the *LCType* parameter, the application should set [LOCALE_USE_CP_ACP](https://learn.microsoft.com/windows/desktop/Intl/locale-use-cp-acp) to use the operating system ANSI code page instead of the locale code page for string translation.

When the ANSI version of this function is used with a Unicode-only locale identifier, the function can succeed because the operating system uses the system code page. However, characters that are undefined in the system code page appear in the string as a question mark (?).

As of Windows Vista, the [LOCALE_SDATE](https://learn.microsoft.com/windows/desktop/Intl/locale-sdate) and [LOCALE_STIME](https://learn.microsoft.com/windows/desktop/Intl/locale-stime-constants) constants are obsolete. Do not use these constants. Use [LOCALE_SSHORTDATE](https://learn.microsoft.com/windows/desktop/Intl/locale-sshortdate) and [LOCALE_STIMEFORMAT](https://learn.microsoft.com/windows/desktop/Intl/locale-stime-constants) instead. A custom locale might not have a single, uniform separator character within the date or time format: for example, a format such as "12/31, 2006" or "03:56'23" might be valid.

> [!NOTE]
> The winnls.h header defines SetLocaleInfo as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[GetLocaleInfo](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoa)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)
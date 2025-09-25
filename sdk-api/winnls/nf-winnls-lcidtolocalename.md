# LCIDToLocaleName function

## Description

Converts a [locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers) to a [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names).

**Note** For custom locales, including those created by Microsoft, your applications should prefer locale names over locale identifiers.

## Parameters

### `Locale` [in]

Locale identifier to translate. You can use the [MAKELCID](https://learn.microsoft.com/windows/desktop/api/winnt/nf-winnt-makelcid) macro to create a locale identifier or use one of the following predefined values.

* [LOCALE_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-invariant)
* [LOCALE_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-system-default)
* [LOCALE_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-user-default)

**Windows Vista:** The following custom locale identifiers are also supported.

* [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UI_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)
* [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants)

### `lpName` [out, optional]

Pointer to a buffer in which this function retrieves the locale name, or one of the following predefined values.

* [LOCALE_NAME_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)

### `cchName` [in]

Size, in characters, of the locale name buffer. The maximum possible length of a locale name, including a terminating null character, is [LOCALE_NAME_MAX_LENGTH](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants). This is the recommended size to supply for this parameter.

Alternatively, the application can set this parameter to 0. In this case, the function returns the required size for the locale name buffer.

### `dwFlags` [in]

**Before Windows 7:** Reserved; should always be 0.

**Starting with Windows 7:** Can be set to [LOCALE_ALLOW_NEUTRAL_NAMES](https://learn.microsoft.com/windows/desktop/Intl/locale-allow-neutral-names) to allow the return of a neutral name.

## Return value

Returns the count of characters, including the terminating null character, in the locale name if successful. If the function succeeds and the value of *cchName* is 0, the return value is the required size, in characters (including nulls), for the locale name buffer.

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INSUFFICIENT_BUFFER. A supplied buffer size was not large enough, or it was incorrectly set to **NULL**.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## See also

[LocaleNameToLCID](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-localenametolcid)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)
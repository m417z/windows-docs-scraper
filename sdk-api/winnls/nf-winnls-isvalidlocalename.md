# IsValidLocaleName function

## Description

Determines if the specified [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names) is valid for a locale that is installed or supported on the operating system.

**Note** An application running only on Windows Vista and later should call this function in preference to [IsValidLocale](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-isvalidlocale) to determine the validity of a [supplemental locale](https://learn.microsoft.com/windows/desktop/Intl/custom-locales).

## Parameters

### `lpLocaleName` [in]

Pointer to the locale name to validate.

## Return value

Returns a nonzero value if the locale name is valid, or returns 0 for an invalid name.

## Remarks

On Windows Vista and later, all supported locales should be installed on all operating systems.

This function can handle the name of a [custom locale](https://learn.microsoft.com/windows/desktop/Intl/custom-locales). Data is not guaranteed to be the same from computer to computer or between runs of an application. If your application must persist or transmit data, see [Using Persistent Locale Data](https://learn.microsoft.com/windows/desktop/Intl/using-persistent-locale-data).

**Beginning in Windows 8:** If your app passes language tags to this function from the [Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization) namespace, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

#### Examples

An example showing the use of this function can be found in [NLS: Name-based APIs Sample](https://learn.microsoft.com/windows/desktop/Intl/nls--name-based-apis-sample).

## See also

[GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex)

[IsValidLocale](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-isvalidlocale)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)
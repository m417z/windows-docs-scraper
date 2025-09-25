# EnumSystemLocalesEx function

## Description

Enumerates the locales that are either installed on or supported by an operating system.

**Note** The application should call this function in preference to [EnumSystemLocales](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlocalesa) if designed to run only on Windows Vista and later.

## Parameters

### `lpLocaleEnumProcEx` [in]

Pointer to an application-defined callback function. The **EnumSystemLocalesEx** function enumerates locales by making repeated calls to this callback function. For more information, see [EnumLocalesProcEx](https://learn.microsoft.com/windows/desktop/api/winnls/nc-winnls-locale_enumprocex).

### `dwFlags` [in]

Flags identifying the locales to enumerate. The flags can be used singly or combined using a binary OR. If the application specifies 0 for this parameter, the function behaves as for [LOCALE_ALL](https://learn.microsoft.com/windows/desktop/Intl/locale-all).

- [LOCALE_ALL](https://learn.microsoft.com/windows/desktop/Intl/locale-all)
- [LOCALE_ALTERNATE_SORTS](https://learn.microsoft.com/windows/desktop/Intl/locale-alternate-sorts); see Remarks
- [LOCALE_NEUTRALDATA](https://learn.microsoft.com/windows/desktop/Intl/locale-neutraldata)
- [LOCALE_SUPPLEMENTAL](https://learn.microsoft.com/windows/desktop/Intl/locale-supplemental)
- [LOCALE_WINDOWS](https://learn.microsoft.com/windows/desktop/Intl/locale-windows)
- [LOCALE_SPECIFICDATA](https://learn.microsoft.com/windows/win32/intl/locale-specificdata)

### `lParam` [in]

An application-provided parameter to be passed to the callback function. This is especially useful for multi-threaded applications.

### `lpReserved` [in, optional]

Reserved; must be **NULL**.

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_BADDB. The function could not access the data. This situation should not normally occur, and typically indicates a bad installation, a disk problem, or the like.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function enumerates locales by passing locale names, one at a time, to the application-defined callback function specified by *lpLocaleEnumProcEx*. Enumeration continues until all installed or supported names have been passed to the callback function or the callback function returns **FALSE**.

The choices for the *dwFlags* parameter are different from those for [EnumSystemLocales](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlocalesa), which must distinguish between installed and supported locales.

If *dwFlags* specifies [LOCALE_ALTERNATE_SORTS](https://learn.microsoft.com/windows/desktop/Intl/locale-alternate-sorts), the callback function is called for every locale that represents an alternate sort order. For example, Spanish (Spain) defaults to international sort order, but traditional sort order is available for an alternate sort. German (Germany) defaults to dictionary sort order, but there is an alternate phone book sort order available.

#### Examples

An example showing the use of this function can be found in [NLS: Name-based APIs Sample](https://learn.microsoft.com/windows/desktop/Intl/nls--name-based-apis-sample).

## See also

[EnumLocalesProcEx](https://learn.microsoft.com/windows/desktop/api/winnls/nc-winnls-locale_enumprocex)

[EnumSystemLocales](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlocalesa)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)
# LOCALE_ENUMPROCEX callback function

## Description

An application-defined callback function that processes enumerated locale information provided by the [EnumSystemLocalesEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlocalesex) function. The LOCALE_ENUMPROCEX type defines a pointer to this callback function. **EnumLocalesProcEx** is a placeholder for the application-defined function name.

## Parameters

### `unnamedParam1`

Pointer to a buffer containing a null-terminated [locale name](https://learn.microsoft.com/windows/win32/intl/locale-names) string.

### `unnamedParam2`

Flags defining locale information. Values for this parameter can include a binary OR of flags, but some flag combinations never occur. If the application specifies [LOCALE_WINDOWS](https://learn.microsoft.com/windows/win32/intl/locale-windows) or [LOCALE_ALTERNATE_SORTS](https://learn.microsoft.com/windows/win32/intl/locale-alternate-sorts), it can also specify [LOCALE_REPLACEMENT](https://learn.microsoft.com/windows/win32/intl/locale-replacement) so that the [EnumSystemLocalesEx](https://learn.microsoft.com/windows/win32/api/winnls/nf-winnls-enumsystemlocalesex) function can test to see if the locale is a replacement.

- [LOCALE_ALL](https://learn.microsoft.com/windows/win32/intl/locale-all)
- [LOCALE_ALTERNATE_SORTS](https://learn.microsoft.com/windows/win32/intl/locale-alternate-sorts); for more information, see [EnumSystemLocalesEx](https://learn.microsoft.com/windows/win32/api/winnls/nf-winnls-enumsystemlocalesex)
- [LOCALE_NEUTRALDATA](https://learn.microsoft.com/windows/win32/intl/locale-neutraldata)
- [LOCALE_REPLACEMENT](https://learn.microsoft.com/windows/win32/intl/locale-replacement) This constant is not a valid input to the *dwFlags* parameter of [EnumSystemLocalesEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlocalesex). To enumerate replacement locales, the application should call this function with the *Arg2* parameter specified as **LOCALE_WINDOWS** or **LOCALE_ALL**, then check for this constant in the callback function.
- [LOCALE_SUPPLEMENTAL](https://learn.microsoft.com/windows/win32/intl/locale-supplemental)
- [LOCALE_WINDOWS](https://learn.microsoft.com/windows/win32/intl/locale-windows)
- [LOCALE_NEUTRALDATA](https://learn.microsoft.com/windows/win32/intl/locale-neutraldata)
- [LOCALE_SPECIFICDATA](https://learn.microsoft.com/windows/win32/intl/locale-specificdata)

### `unnamedParam3`

An application-provided input parameter of [EnumSystemLocalesEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlocalesex). This value is especially useful for multi-threaded applications, since it can be used to pass thread-specific data to this callback function.

## Return value

Returns **TRUE** to continue enumeration or **FALSE** otherwise.

## Remarks

An **EnumLocalesProcEx** function can carry out any desired task. The application registers this function by passing its address to the [EnumSystemLocalesEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlocalesex) function.

## See also

[EnumSystemLocalesEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlocalesex)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)
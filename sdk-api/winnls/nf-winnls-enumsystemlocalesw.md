# EnumSystemLocalesW function

## Description

Enumerates the locales that are either installed on or supported by an operating system.

**Note** For interoperability reasons, the application should prefer the [EnumSystemLocalesEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlocalesex) function to **EnumSystemLocales** because Microsoft is migrating toward the use of locale names instead of locale identifiers for new locales. Any application that will be run only on Windows Vista and later should use [EnumSystemLocalesEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlocalesex).

## Parameters

### `lpLocaleEnumProc` [in]

Pointer to an application-defined callback function. For more information, see [EnumLocalesProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317822(v=vs.85)).

### `dwFlags` [in]

Flags specifying the locale identifiers to enumerate. The flags can be used singly or combined using a binary OR. If the application specifies 0 for this parameter, the function behaves as for LCID_SUPPORTED.

| Value | Meaning |
| --- | --- |
| **LCID_INSTALLED** | Enumerate only installed locale identifiers. This value cannot be used with LCID_SUPPORTED. |
| **LCID_SUPPORTED** | Enumerate all supported locale identifiers. This value cannot be used with LCID_INSTALLED. |
| **LCID_ALTERNATE_SORTS** | Enumerate only the alternate sort locale identifiers. If this value is used with either LCID_INSTALLED or LCID_SUPPORTED, the installed or supported locales are retrieved, as well as the alternate sort locale identifiers. |

## Return value

Returns a nonzero value if successful, or 0 otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_BADDB. The function could not access the data. This situation should not normally occur, and typically indicates a bad installation, a disk problem, or the like.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

The function enumerates locales by passing locale identifiers, one at a time, to the specified application-defined callback function. This continues until all of the installed or supported locale identifiers have been passed to the callback function or the callback function returns **FALSE**.

> [!NOTE]
> The winnls.h header defines EnumSystemLocales as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumLocalesProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317822(v=vs.85))

[EnumSystemLocalesEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlocalesex)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)
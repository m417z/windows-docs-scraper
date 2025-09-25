# EnumSystemLanguageGroupsW function

## Description

Enumerates the language groups that are either installed on or supported by an operating system.

**Note** For custom locales, your application should call [EnumSystemLocalesEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumsystemlocalesex) instead of **EnumSystemLanguageGroups**.

## Parameters

### `lpLanguageGroupEnumProc` [in]

Pointer to an application-defined callback function. For more information, see [EnumLanguageGroupsProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317821(v=vs.85)).

### `dwFlags` [in]

Flags specifying the language group identifiers to enumerate. This parameter can have one of the following values.

| Value | Meaning |
| --- | --- |
| **LGRPID_INSTALLED** | Enumerate only installed language group identifiers. |
| **LGRPID_SUPPORTED** | Enumerate all supported language group identifiers. |

### `lParam` [in]

Application-defined value to pass to the callback function. This parameter can be used in error checking. It can also be used to ensure thread safety in the callback function.

## Return value

Returns **TRUE** if successful or **FALSE** otherwise. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_BADDB. The function could not access the data. This situation should not normally occur, and typically indicates a bad installation, a disk problem, or the like.
* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function enumerates language groups by passing language group identifiers, one at a time, to the specified application-defined callback function. This process continues until the last language group identifier is found or the callback function returns **FALSE**.

> [!NOTE]
> The winnls.h header defines EnumSystemLanguageGroups as an alias that automatically selects the ANSI or Unicode version of this function based on the definition of the UNICODE preprocessor constant. Mixing usage of the encoding-neutral alias with code that is not encoding-neutral can lead to mismatches that result in compilation or runtime errors. For more information, see [Conventions for Function Prototypes](https://learn.microsoft.com/windows/win32/intl/conventions-for-function-prototypes).

## See also

[EnumLanguageGroupLocales](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-enumlanguagegrouplocalesa)

[EnumLanguageGroupsProc](https://learn.microsoft.com/previous-versions/windows/desktop/legacy/dd317821(v=vs.85))

[IsValidLanguageGroup](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-isvalidlanguagegroup)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)
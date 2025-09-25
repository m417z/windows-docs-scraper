# VerifyScripts function

## Description

Compares two enumerated lists of scripts.

## Parameters

### `dwFlags` [in]

Flags specifying script verification options.

| Value | Meaning |
| --- | --- |
| **VS_ALLOW_LATIN** | Allow "Latn" (Latin script) in the test list even if it is not in the locale list. |

### `lpLocaleScripts` [in]

Pointer to the locale list, the enumerated list of scripts for a given locale. This list is typically populated by calling [GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex) with *LCType* set to [LOCALE_SSCRIPTS](https://learn.microsoft.com/windows/desktop/Intl/locale-sscripts).

### `cchLocaleScripts` [in]

Size, in characters, of the string indicated by *lpLocaleScripts*. The application sets this parameter to -1 if the string is null-terminated. If this parameter is set to 0, the function fails.

### `lpTestScripts` [in]

Pointer to the test list, a second enumerated list of scripts. This list is typically populated by calling [GetStringScripts](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getstringscripts).

### `cchTestScripts` [in]

Size, in characters, of the string indicated by *lpTestScripts*. The application sets this parameter to -1 if the string is null-terminated. If this parameter is set to 0, the function fails.

## Return value

Returns **TRUE** if the test list is non-empty and all items in the list are also included in the locale list. The function still returns **TRUE** if the locale list contains more scripts than the test list, but all the test list scripts must be contained in the locale list. If VS_ALLOW_LATIN is specified in *dwFlags*, the function behaves as if "Latn;" is always in the locale list.

In all other cases, the function returns **FALSE**. This return can indicate that the test list contains an item that is not in the locale list, or it can indicate an error. To distinguish between these two cases, the application should call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return one of the following error codes:

* ERROR_INVALID_FLAGS. The values supplied for flags were not valid.
* ERROR_INVALID_PARAMETER. Any of the parameter values was invalid.
* ERROR_SUCCESS. The action completed successfully but yielded no results.

## Remarks

This function compares strings, such as "Latn;Cyrl;", that consist of a series of 4-character script names, with each script name followed by a semicolon. It also has a special case to account for the fact that the Latin script is often used in languages and locales for which it is not native.

This function is useful as part of a strategy to mitigate security issues related to [internationalized domain names (IDNs)](https://learn.microsoft.com/windows/desktop/Intl/handling-internationalized-domain-names--idns).

The following are examples of the return of this function and a subsequent call to [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror) in various scenarios. The last two examples illustrate, respectively, a case in which the test list lacks a terminating semicolon (malformed string) and a case in which the test list is empty.

| Locale string | Test string | *dwFlags* | Return value | **GetLastError** return |
| --- | --- | --- | --- | --- |
| Hani;Hira;Kana; | Hani; | * | **TRUE** | (unchanged) |
| Hani;Hira;Kana; | Hani;Latn; | 0 | **FALSE** | ERROR_SUCCESS |
| Hani;Hira;Kana; | Hani;Latn; | VS_ALLOW_LATIN | **TRUE** | (unchanged) |
| Hani;Hira;Kana; | Cyrl; | * | **FALSE** | ERROR_SUCCESS |
| Hani; | Hani;Hira;Kana; | * | FALSE | ERROR_SUCCESS |
| Hani;Hira;Kana; | Cyrl | * | **FALSE** | ERROR_INVALID_PARAMETER |
| Hani;Hira;Kana; |  | * | TRUE | (unchanged) |

* Results are the same whether VS_ALLOW_LATIN is passed in the *dwFlags* parameter or no flags are supplied.

#### Examples

[NLS: Internationalized Domain Name (IDN) Mitigation Sample](https://learn.microsoft.com/windows/desktop/Intl/nls--internationalized-domain-name--idn--mitigation-sample) demonstrates the use of this function.

## See also

[DownlevelVerifyScripts](https://learn.microsoft.com/windows/desktop/Intl/downlevelverifyscripts)

[GetLocaleInfoEx](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getlocaleinfoex)

[GetStringScripts](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-getstringscripts)

[Handling Internationalized Domain Names (IDNs)](https://learn.microsoft.com/windows/desktop/Intl/handling-internationalized-domain-names--idns)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)
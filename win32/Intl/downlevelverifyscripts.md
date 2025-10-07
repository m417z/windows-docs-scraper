# DownlevelVerifyScripts function

Compares two enumerated lists of scripts.

> [!Note]
> This function is used only by applications that run on pre-Windows Vista operating systems. Its use requires the download package. Applications that only run on Windows Vista and later should call [**VerifyScripts**](https://learn.microsoft.com/windows/desktop/api/Winnls/nf-winnls-verifyscripts).

## Parameters

*dwFlags* \[in\]

Flags specifying script verification options.

| Value | Meaning |
|-------------------------------------------------------------------------------------------------------------------------------------------------------------------|------------------------------------------------------------------------------------------------|
|

**VS\_ALLOW\_LATIN**

| Allow "Latn" (Latin script) in the test list, even if it is not in the locale list.<br> |

*lpLocaleScripts* \[in\]

Pointer to the locale list, the enumerated list of scripts for a given locale. This list is typically populated by calling [**DownlevelGetLocaleScripts**](https://learn.microsoft.com/windows/win32/intl/downlevelgetlocalescripts).

*cchLocaleScripts* \[in\]

Size, in characters, of the string indicated by *lpLocaleScripts*. The application sets this parameter to -1 if the string is null-terminated. If this parameter is set to 0, the function fails.

*lpTestScripts* \[in\]

Pointer to the test list, a second enumerated list of scripts. This list is typically populated by calling [**DownlevelGetStringScripts**](https://learn.microsoft.com/windows/win32/intl/downlevelgetstringscripts).

*cchTestScripts* \[in\]

Size, in characters, of the string indicated by *lpTestScripts*. The application sets this parameter to -1 if the string is null-terminated. If this parameter is set to 0, the function fails.

## Return value

Returns **TRUE** if the test list is non-empty and all items in the list are also included in the locale list. Otherwise, the function returns **FALSE**.

A return value of **FALSE** can indicate that the test list contains an item that is not in the locale list, or it can indicate an error. To distinguish between these two cases, the application can call [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror). If **DownlevelVerifyScripts** has successfully determined that there is an item in the test list that is not in the locale list, **GetLastError** returns ERROR\_SUCCESS. Otherwise, **GetLastError** can return one of the following error codes:

- ERROR\_INVALID\_FLAGS. The values supplied for flags were not valid.
- ERROR\_INVALID\_PARAMETER. Any of the parameter values was invalid.

## Remarks

This function compares strings, such as "Latn;Cyrl;", that consist of a series of 4-character script names, with each script name followed by a semicolon. It also has a special case to account for the fact that the Latin script is often used in languages and locales for which it is not native.

This function is useful as part of a strategy to mitigate security issues related to [internationalized domain names (IDNs)](https://learn.microsoft.com/windows/win32/intl/handling-internationalized-domain-names--idns).

The following are examples of the return of this function and a subsequent call to [**GetLastError**](https://learn.microsoft.com/windows/win32/api/errhandlingapi/nf-errhandlingapi-getlasterror) in various scenarios. The last two examples illustrate, respectively, a case in which the test list lacks a terminating semicolon (malformed string) and a case in which the test list is empty.

| "Locale" string | "Test" string | *dwFlags* | Return value | GetLastError return |
|-----------------|---------------|------------------|--------------|---------------------------|
| Hani;Hira;Kana; | Hani; | N/A | **TRUE** | N/A |
| Hani;Hira;Kana; | Hani;Latn; | 0 | **FALSE** | ERROR\_SUCCESS |
| Hani;Hira;Kana; | Hani;Latn; | VS\_ALLOW\_LATIN | **TRUE** | N/A |
| Hani;Hira;Kana; | Cyrl; | N/A | **FALSE** | ERROR\_SUCCESS |
| Hani;Hira;Kana; | Cyrl; | N/A | **FALSE** | ERROR\_INVALID\_PARAMETER |
| Hani;Hira;Kana; | | N/A | **FALSE** | ERROR\_SUCCESS |

The required header file and DLL are part of the ["Microsoft Internationalized Domain Name (IDN) Mitigation APIs"](https://archive.org/details/idndl.x86) download available from [archive.org](https://archive.org/).

## Requirements

| Requirement | Value |
|-------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows XP \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2003 \[desktop apps only\]<br> |
| Redistributable<br> | Microsoft Internationalized Domain Name (IDN) Mitigation APIs onWindows XP with SP2,Windows Server 2003 with SP1, orWindows Vista<br> |
| Header<br> | Idndl.h |
| DLL<br> | Idndl.dll |

## See also

[National Language Support](https://learn.microsoft.com/windows/win32/intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/win32/intl/national-language-support-functions)

[Handling Internationalized Domain Names (IDNs)](https://learn.microsoft.com/windows/win32/intl/handling-internationalized-domain-names--idns)

[**DownlevelGetLocaleScripts**](https://learn.microsoft.com/windows/win32/intl/downlevelgetlocalescripts)

[**DownlevelGetStringScripts**](https://learn.microsoft.com/windows/win32/intl/downlevelgetstringscripts)

[**VerifyScripts**](https://learn.microsoft.com/windows/desktop/api/Winnls/nf-winnls-verifyscripts)


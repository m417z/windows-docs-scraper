# LocaleNameToLCID function

## Description

Converts a [locale name](https://learn.microsoft.com/windows/desktop/Intl/locale-names) to a [locale identifier](https://learn.microsoft.com/windows/desktop/Intl/locale-identifiers).

## Parameters

### `lpName` [in]

Pointer to a null-terminated string representing a locale name, or one of the following predefined values.

* [LOCALE_NAME_INVARIANT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_SYSTEM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)
* [LOCALE_NAME_USER_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-name-constants)

### `dwFlags` [in]

**Prior to Windows 7:**Reserved; should always be 0.

**Beginning in Windows 7:** Can be set to [LOCALE_ALLOW_NEUTRAL_NAMES](https://learn.microsoft.com/windows/desktop/Intl/locale-allow-neutral-names) to allow the return of a neutral LCID.

## Return value

If successful, returns the locale identifier corresponding to the locale name.

If the supplied locale name corresponds to a custom locale that is the user default, this function returns [LOCALE_CUSTOM_DEFAULT](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants).

If the locale name corresponds to a custom locale that is not the user default, is a transient locale, or is a CLDR (Unicode Common Locale Data Repository) locale, the function returns [LOCALE_CUSTOM_UNSPECIFIED](https://learn.microsoft.com/windows/desktop/Intl/locale-custom-constants).

The function returns 0 if it does not succeed. To get extended error information, the application can call [GetLastError](https://learn.microsoft.com/windows/desktop/api/errhandlingapi/nf-errhandlingapi-getlasterror), which can return ERROR_INVALID_PARAMETER if any of the parameter values are invalid.

## Remarks

For custom locales, including those created by Microsoft, your applications should prefer locale names over locale identifiers. See [The deprecation of LCIDs](https://learn.microsoft.com/globalization/locale/locale-names#the-deprecation-of-lcids) for more info.

**Beginning in Windows 8:** If your app passes language tags to this function from the [Windows.Globalization](https://learn.microsoft.com/uwp/api/Windows.Globalization) namespace, it must first convert the tags by calling [ResolveLocaleName](https://learn.microsoft.com/windows/desktop/api/winnls/nf-winnls-resolvelocalename).

#### Examples

```cpp

#include "stdafx.h"
#include "windows.h"
#include "stdio.h"

int _cdecl main(
    int argc,
    char *argv[])
{
    WCHAR strNameBuffer[LOCALE_NAME_MAX_LENGTH];
    DWORD error = ERROR_SUCCESS;
    LCID  lcid;

    // Get the name for locale 0x10407 (German (German), with phonebook sort)
    if (LCIDToLocaleName(0x10407, strNameBuffer, LOCALE_NAME_MAX_LENGTH, 0) == 0)
    {
        // There was an error
        error = GetLastError();
    }
    else
    {
        // Success, display the locale name we found
        wprintf(L"Locale Name for 0x10407 is %s\n", strNameBuffer);
    }

    // Get the LCID for the locale
    lcid = LocaleNameToLCID(strNameBuffer, 0);
    if (lcid == 0)
    {
        // There was an error
        error = GetLastError();
    }
    else
    {
        // Success, print the round trip LCID
        wprintf(L"LCID for %s is 0x%x\n", strNameBuffer, lcid);
    }
}

/* This code example produces the following output:

Locale Name for 0x10407 is de-DE_phoneb
LCID for de-DE_phoneb is 0x10407

*/

```

## See also

[DownlevelLocaleNameToLCID](https://learn.microsoft.com/windows/desktop/Intl/downlevellocalenametolcid)

[NLS: Name-based APIs Sample](https://learn.microsoft.com/windows/desktop/Intl/nls--name-based-apis-sample)

[National Language Support](https://learn.microsoft.com/windows/desktop/Intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/desktop/Intl/national-language-support-functions)
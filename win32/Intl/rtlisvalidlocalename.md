# RtlIsValidLocaleName function

Determines if a locale specified by name is installed or supported on the operating system.

> [!Note]
> This function is available for use in Windows Vista only. It might be altered or unavailable in subsequent versions. Applications should use [**IsValidLocaleName**](https://learn.microsoft.com/windows/desktop/api/Winnls/nf-winnls-isvalidlocalename).

## Parameters

*LocaleName* \[in\]

[Locale name](https://learn.microsoft.com/windows/win32/intl/locale-names) to validate. This parameter can specify the name of a [custom locale](https://learn.microsoft.com/windows/win32/intl/custom-locales).

*Flags* \[in\]

Flags indicating if neutral locales are considered valid. Currently the only defined flag is [LOCALE\_ALLOW\_NEUTRAL](https://learn.microsoft.com/windows/win32/intl/locale-allow-neutral). The default value is that they are not.

## Return value

Returns a nonzero value if successful, or 0 otherwise.

## Remarks

This function is similar to [**IsValidLocaleName**](https://learn.microsoft.com/windows/desktop/api/Winnls/nf-winnls-isvalidlocalename). The only difference is that if LOCALE\_ALLOW\_NEUTRAL is set, **RtlIsValidLocaleName** returns **TRUE** for a name that corresponds to a neutral locale (such as "en"), while [**IsValidLocaleName**](https://learn.microsoft.com/windows/desktop/api/Winnls/nf-winnls-isvalidlocalename) returns **TRUE** only for a specific locale (such as "en-US"). Neutral locales are used as part of the resource loading strategy in Windows Vista and later. Only a small class of highly specialized applications use **RtlIsValidLocaleName** and set LOCALE\_ALLOW\_NEUTRAL, because neutral locales are of very limited use. None of the functions described in [Calling the "Locale Name" Functions](https://learn.microsoft.com/windows/win32/intl/calling-the--locale-name--functions) accept neutral locales as inputs.

## Requirements

| Requirement | Value |
|-------------------------------------|-----------------------------------------------------------------------------------------|
| Minimum supported client<br> | Windows Vista \[desktop apps only\]<br> |
| Minimum supported server<br> | Windows Server 2008 \[desktop apps only\]<br> |
| Header<br> | Ntrtl.h |
| Library<br> | Kernel32.lib |
| DLL<br> | Kernel32.dll |

## See also

[National Language Support](https://learn.microsoft.com/windows/win32/intl/national-language-support)

[National Language Support Functions](https://learn.microsoft.com/windows/win32/intl/national-language-support-functions)

[**IsValidLocaleName**](https://learn.microsoft.com/windows/desktop/api/Winnls/nf-winnls-isvalidlocalename)

